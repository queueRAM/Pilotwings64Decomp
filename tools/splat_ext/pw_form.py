from pathlib import Path

import struct
import yaml
from splat.util import options
from splat.segtypes.segment import Segment

class N64SegPw_form(Segment):
    def __init__(self, rom_start, rom_end, type, name, vram_start, args, yaml):
        super().__init__(
            rom_start, rom_end, type, name, vram_start, args=args, yaml=yaml
        )
        self.data_only = True
        self.parsers = {
            b'FORM': self.scan_form,
            b'COMM': self.scan_tbd,
            b'PART': self.scan_tbd,
            b'FRMT': self.scan_tbd,
            b'LEVL': self.scan_tbd,
            b'ESND': self.scan_tbd,
            b'TOYS': self.scan_tbd,
            b'APTS': self.scan_tbd,
            b'STRG': self.scan_string,
            b'BNUS': self.scan_bnus,
            b'LPAD': self.scan_lpad,
            b'PAD ': self.scan_pad,
            b'GZIP': self.scan_gzip,
            b'3VUE': self.scan_tag_only,
            b'ADAT': self.scan_tag_only,
            b'PDAT': self.scan_tag_only,
            b'SPTH': self.scan_tag_only,
            b'UPWL': self.scan_tag_only,
            b'UPWT': self.scan_tag_only,
            b'UVAN': self.scan_tag_only,
            b'UVBT': self.scan_tag_only,
            b'UVCT': self.scan_tag_only,
            b'UVEN': self.scan_tag_only,
            b'UVFT': self.scan_tag_only,
            b'UVLT': self.scan_tag_only,
            b'UVLV': self.scan_tag_only,
            b'UVMD': self.scan_tag_only,
            b'UVRM': self.scan_tag_only,
            b'UVSQ': self.scan_tag_only,
            b'UVSX': self.scan_tag_only,
            b'UVSY': self.scan_tag_only,
            b'UVTP': self.scan_tag_only,
            b'UVTR': self.scan_tag_only,
            b'UVTX': self.scan_tag_only,
        }

    def out_path(self) -> Path:
        return options.opts.src_path / self.dir / f"{self.name}.yaml"

    def scan_pad(self, rom_bytes, idx):
        idx += 4 # skip over tag
        length, = struct.unpack(">I", rom_bytes[idx:idx+4])
        print(f"pad  0x{idx:x} 0x{length:x}")
        return {'data': rom_bytes[idx+4:idx+4+length]}, 8 + length

    def scan_tbd(self, rom_bytes, idx):
        tag, length = struct.unpack(">4sI", rom_bytes[idx:idx+8])
        print(f"tbd  {tag} 0x{idx:x} 0x{length:x}")
        return {'data': rom_bytes[idx+8:idx+8+length]}, 8 + length

    def scan_bnus(self, rom_bytes, idx):
        # Vec3f position; u32 unkC; u32 unk10; u32 unk14; u32 unk18; u32 unk1C;
        tag, length, x, y, z, uC, u10, u14, u18, u1C = struct.unpack(">4sI3f5I", rom_bytes[idx:idx+40])
        print(f"bnus {tag} 0x{idx:x} 0x{length:x} {x},{y},{z}")
        return {'pos': (x, y, z), 'unk': (uC, u10, u14, u18, u1C)}, 8 + length

    def scan_lpad(self, rom_bytes, idx):
        # Vec3f position; float heading; padding[8];
        tag, length, x, y, z, h = struct.unpack(">4sI3ff", rom_bytes[idx:idx+24])
        print(f"lpad {tag} 0x{idx:x} 0x{length:x} {x},{y},{z} {h}")
        return {'pos': (x, y, z), 'heading': h}, 8 + length

    def scan_string(self, rom_bytes, idx):
        tag, length = struct.unpack(">4sI", rom_bytes[idx:idx+8])
        text_bytes = rom_bytes[idx+8:idx+8+length]
        text = text_bytes.decode('utf-8')
        print(f"str  {tag} 0x{idx:x} 0x{length:x} {text}")
        return {'string': text}, 8 + length

    def scan_tag_only(self, rom_bytes, idx):
        tag, = struct.unpack(">4s", rom_bytes[idx:idx+4])
        print(f"tag  {tag} 0x{idx:x}")
        return tag, 4 # only tag

    def scan_form(self, rom_bytes, idx):
        ret = []
        form_length, = struct.unpack(">I", rom_bytes[idx+4:idx+8])
        print(f"form 0x{idx:x} 0x{form_length:x}")
        idx += 8
        cur = 0
        while cur < form_length:
            tag, = struct.unpack(">4s", rom_bytes[cur+idx:cur+idx+4])
            parsed, length = self.parsers[tag](rom_bytes, cur+idx)
            ret.append((tag, length, parsed))
            cur += length
        return ret, 8 + form_length # tag + length_field + length

    def scan_gzip(self, rom_bytes, idx):
        _, comp_len, tag, uncomp_len = struct.unpack(">4sL4sL", rom_bytes[idx:idx+16])
        print(f"gzip 0x{idx:x} 0x{comp_len:x} {tag} 0x{uncomp_len:x}")
        return tag, 8 + comp_len

    def scan(self, rom_bytes):
        self.data = []
        idx = self.rom_start
        tag, = struct.unpack(">4s", rom_bytes[idx:idx+4])
        print("scan", tag)
        while (tag in self.parsers):
            parsed, length = self.parsers[tag](rom_bytes, idx)
            self.data.append((tag, length, parsed))
            idx += length
            tag, = struct.unpack(">4s", rom_bytes[idx:idx+4])

    def split(self, rom_bytes):
        path = self.out_path()
        path.parent.mkdir(parents=True, exist_ok=True)

        if self.data and path:
            with open(path, "w", newline="\n") as f:
                f.write(yaml.dump(self.data, default_flow_style=False))
