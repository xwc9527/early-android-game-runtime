#!/usr/bin/env python3
"""Create a valid project-owned DEX whose only application class is not Lpoc/Bridge;."""

import argparse
import hashlib
import pathlib
import struct
import zlib


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("source", type=pathlib.Path)
    parser.add_argument("output", type=pathlib.Path)
    args = parser.parse_args()

    data = bytearray(args.source.read_bytes())
    old = b"Lpoc/Bridge;"
    new = b"Lfoo/Absent;"
    if len(old) != len(new) or data.count(old) != 1:
        raise SystemExit("expected exactly one same-length Bridge descriptor")
    data[data.index(old) : data.index(old) + len(old)] = new
    data[12:32] = hashlib.sha1(data[32:]).digest()
    struct.pack_into("<I", data, 8, zlib.adler32(data[12:]) & 0xFFFFFFFF)
    if old in data or new not in data:
        raise SystemExit("descriptor rewrite failed")
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_bytes(data)


if __name__ == "__main__":
    main()
