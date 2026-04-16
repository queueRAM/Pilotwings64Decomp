from pathlib import Path

import crunch64
import struct
import yaml
from typing import Tuple
from splat.util import options
from splat.segtypes.segment import Segment
from splat.segtypes.linker_entry import LinkerEntry

class N64SegPw_filesys(Segment):
    def __init__(self, rom_start, rom_end, type, name, vram_start, args, yaml):
        super().__init__(
            rom_start, rom_end, type, name, vram_start, args=args, yaml=yaml
        )
        self.fs_path = "filesys"

    def parse_table(self, rom_bytes: bytes, idx: int) -> Tuple[list, int]:
        form_tag, form_length = struct.unpack(">4s L", rom_bytes[idx:idx+8])
        print(f"form 0x{idx:x} 0x{form_length:x}")
        assert form_tag == b'FORM'
        idx += 8
        fs_data_start = (((idx + form_length) + 15) // 16) * 16
        rtag, = struct.unpack(">4s", rom_bytes[idx:idx+4])
        assert rtag == b'UVRM'
        idx += 4
        table = {
            'tag': form_tag.decode("utf-8"),
            'length': form_length,
            'type': rtag.decode("utf-8"),
            'contents': []
        }
        cur = 0
        fs_data_offset = fs_data_start
        while cur < form_length:
            tag, length = struct.unpack(">4s L", rom_bytes[cur+idx:cur+idx+8])
            cur += 8
            data = rom_bytes[cur+idx:cur+idx+length]
            if tag == b'GZIP':
                tag, dlength = struct.unpack(">4s L", rom_bytes[cur+idx:cur+idx+8])
                cur += 8
                data = crunch64.mio0.decompress(rom_bytes[cur+idx:cur+idx+length])
                assert len(data) == dlength, f"Expected {len(data)} == {dlength}"
            if tag == b'PAD ':
                pass
            elif tag == b'TABL':
                for entry_tag, entry_length in struct.iter_unpack(">4s L", data):
                    table['contents'].append({
                        'tag': entry_tag.decode("utf-8"),
                        'offset': fs_data_offset,
                        'length': entry_length
                    })
                    fs_data_offset += entry_length
            cur += length
        return table

    def scan(self, rom_bytes):
        idx = self.rom_start
        self.fs_table = self.parse_table(rom_bytes, idx)

    def split(self, rom_bytes):
        path = options.opts.asset_path / self.dir / self.fs_path
        print("Make dirs", path)
        path.mkdir(parents=True, exist_ok=True)

        for form in self.fs_table['contents']:
            fname = f"{self.name}_{form['tag']}_{form['offset']:06X}.bin"
            fpath = options.opts.asset_path / self.dir / self.fs_path / fname
            with open(fpath, 'wb') as fout:
                start = form['offset']
                end = start + form['length']
                fout.write(rom_bytes[start:end])
            form['file'] = fname

        if self.fs_table and path:
            with open(path / "filetable.yaml", "w", newline="\n") as f:
                f.write(yaml.dump(self.fs_table, sort_keys=False, default_flow_style=None))
        else:
            print("ERROR:", self.fs_table, path)

    def get_linker_entries(self):
        return [
            LinkerEntry(
                self,
                [options.opts.asset_path / self.dir / "filetable.bin"],
                options.opts.asset_path / self.dir / "filetable",
                self.get_linker_section_order(),
                self.get_linker_section_linksection(),
                self.is_noload(),
            ),
            LinkerEntry(
                self,
                [options.opts.asset_path / self.dir / f"{self.name}.bin"],
                options.opts.asset_path / self.dir / f"{self.name}",
                self.get_linker_section_order(),
                self.get_linker_section_linksection(),
                self.is_noload(),
            )
        ]
