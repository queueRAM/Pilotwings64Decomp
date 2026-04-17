#!/bin/env python3

import struct

def read_table(tablePath):
    import yaml
    return yaml.safe_load(open(tablePath, 'r'))

def generate_bins(table: dict, fileDir: str, tableFile: str, filesysFile: str):
    import crunch64
    # 1. output filesystem binary and accumulate sizes
    with open(filesysFile, 'wb') as fsBin:
        offset = 0
        for form in table['contents']:
            if form['file'].endswith(".raw"):
                filePath = fileDir + "/" + form['file']
                formData = open(filePath, 'rb').read()
                formLen = len(formData) + 8
                if formLen != form['length']:
                    print(f"Warning: length mismatch {form['file']} {form['length']} != {formLen}")
                form['length'] = formLen
                offset += formLen
            elif form['file'].endswith(".yaml"):
                formData = b''
            else:
                formData = b''
            fsBin.write(formData)

    # 2. generate filetable, compress, and output file
    tableData = bytes()
    for form in table['contents']:
        tableData += struct.pack(">4s L", form['tag'].encode("utf-8"), form['length'])
    tableLen = len(tableData)
    cTableData = crunch64.mio0.compress(tableData)
    cTableLen = len(cTableData)
    uvRm = struct.pack(">4s", "UVRM".encode("utf-8"))
    for i in range(2):
        uvRm += struct.pack(">4s L L", "PAD ".encode("utf-8"), 4, 0)
    uvRm += struct.pack(">4s L", "GZIP".encode("utf-8"), cTableLen)
    uvRm += struct.pack(">4s L", "TABL".encode("utf-8"), tableLen)
    uvRm += cTableData
    uvRmLen = len(uvRm)
    with open(tableFile, 'wb') as tableBin:
        tableBin.write(struct.pack(">4s L", "FORM".encode("utf-8"), uvRmLen))
        tableBin.write(uvRm)

def main():
    import argparse
    parser = argparse.ArgumentParser()
    parser.add_argument("--table", "-t", action="store", default='./bin/filesys/filetable.yaml')
    parser.add_argument("--dir", "-d", action="store", default='./bin/filesys')
    args = parser.parse_args()
    table = read_table(args.table)
    generate_bins(table, args.dir, 'bin/filetable.bin', 'bin/filesys.bin')

if __name__ == "__main__":
    main()
