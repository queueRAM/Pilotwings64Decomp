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
            b'UVRM': self.scan_tag_only,
            b'PAD ': self.scan_pad,
        }

    def out_path(self) -> Path:
        return options.opts.src_path / self.dir / f"{self.name}.yaml"
    
    def scan_pad(self, rom_bytes, idx):
        idx += 4
        length, = struct.unpack(">I", rom_bytes[idx:idx+4])
        print(f"pad 0x{idx:x} 0x{length:x}")
        return None, 8 + length

    def scan_tag_only(self, rom_bytes, idx):
        tag, = struct.unpack(">4s", rom_bytes[idx:idx+4])
        return tag, 4

    def scan_form(self, rom_bytes, idx):
        ret = []
        idx += 4
        form_length, = struct.unpack(">I", rom_bytes[idx:idx+4])
        print(f"form 0x{idx:x} 0x{form_length:x}")
        idx += 4
        cur = 0
        while cur < form_length:
            tag, = struct.unpack(">4s", rom_bytes[cur+idx:cur+idx+4])
            parsed, length = self.parsers[tag](rom_bytes, cur+idx)
            ret.append((tag, length, parsed))
            cur += 4 + length
        return ret, 8 + form_length
        
    def scan(self, rom_bytes):
        self.data = []
        idx = self.rom_start
        tag, = struct.unpack(">4s", rom_bytes[idx:idx+4])
        print("scan", tag)
        while (tag in self.parsers):
            parsed, length = self.parsers[tag](rom_bytes, idx)
            self.data.append((tag, length, parsed))
            idx += 4 + length
            tag, = struct.unpack(">4s", rom_bytes[idx:idx+4])

    def split(self, rom_bytes):
        path = self.out_path()
        path.parent.mkdir(parents=True, exist_ok=True)

        if self.data and path:
            with open(path, "w", newline="\n") as f:
                f.write(yaml.dump(self.data, default_flow_style=False))
