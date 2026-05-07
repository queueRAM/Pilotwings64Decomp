#!/bin/env python3

import struct

class SPTH:
    """
    SPath class which stores x,y,z and heading,pitch,roll data for paths

    each of these datasets are stored as separate arrays, with each entry
    containing a time and value. the values used at runtime are then interpolated
    between the array. this means each dataset need not be of the same length.
    """

    # order of tags is important
    _spathTags = ("SCPP", "SCPH", "SCPX", "SCPY", "SCPR", "SCPZ", "SCP#")

    def __init__(self, tag="SPTH", pad_count=0, entries=None):
        self.tag = tag
        self.pad_count = pad_count
        self.entries = entries if entries is not None else {}

    @classmethod
    def from_dict(cls, d: dict):
        """Construct SPTH from dictionary"""
        return cls(d["tag"], d["pad_count"], d["entries"])

    @classmethod
    def from_bytes(cls, form: bytes):
        """Construct SPTH from raw filesystem bytes"""
        ftag, flen, stag = struct.unpack(">4s L 4s", form[:0xC])
        assert ftag == b'FORM', f"Expected 'FORM', got ${ftag}"
        assert stag == b'SPTH', f"Expected 'SPTH', got ${stag}"
        sBytes = form[8:]
        idx = 4
        pad_count = 0
        entries = {}
        while idx < flen:
            tag, length = struct.unpack(">4s L", sBytes[idx:idx+8])
            idx += 8
            tag = tag.decode()
            assert tag == "PAD " or tag in cls._spathTags, f"Unexpected tag '${tag}'"
            if tag == "PAD ":
                pad_count += 1
            elif tag in cls._spathTags:
                spIdx = idx
                count, = struct.unpack(">L", sBytes[spIdx:spIdx+4])
                spIdx += 4
                sp = [{"time": e[0], "val": e[1]} for e in struct.iter_unpack(">ff", sBytes[spIdx:spIdx+8*count])]
                spIdx += 8*count
                entries[tag] = sp
            idx += length
        return cls(stag.decode(), pad_count, entries)

    # - tag: SPTH
    # - pad_count: 1
    # - entries:
    #     - {time: 0.0, val: 0.0}
    #     - {time: 2.0, val: 4.0}
    #     - ...
    def as_dict(self) -> dict:
        """Generate dictionary suitable for creating YAML representation"""
        return {
            "tag": self.tag,
            "pad_count": self.pad_count,
            "entries": self.entries
        }

    def __bytes__(self) -> bytes:
        """Generate raw bytes suitable for regenerating filesystem data"""
        records = struct.pack(">4s", self.tag.encode())
        records += struct.pack(">4s L L", b'PAD ', 4, 0) * self.pad_count
        for tag in self._spathTags:
            scpCount = len(self.entries[tag])
            scpLength = 8 + 8 * scpCount
            records += struct.pack(">4s L L", tag.encode(), scpLength, scpCount)
            records += b''.join([struct.pack(">ff", e['time'], e['val']) for e in self.entries[tag]])
            records += b'\0' * ((8 - (len(records) % 8)) % 8)
        spth = b'FORM' + struct.pack(">L", len(records)) + records
        return spth
