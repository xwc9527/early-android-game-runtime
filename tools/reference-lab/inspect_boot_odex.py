#!/usr/bin/env python3
"""Check paired API19 boot ODEX class flags without trusting text dexdump output."""

import argparse
import hashlib
import json
import struct
from pathlib import Path


TARGETS = ("Ljava/lang/Comparable;", "Ljava/lang/Integer;", "Ljava/lang/Number;")
PREVERIFIED_OPTIMIZED = 0x30000


def u32(data, offset):
    return struct.unpack_from("<I", data, offset)[0]


def read_uleb128(data, offset):
    value = 0
    for shift in range(0, 35, 7):
        byte = data[offset]
        offset += 1
        value |= (byte & 0x7f) << shift
        if byte < 0x80:
            return value, offset
    raise ValueError("invalid DEX uleb128")


def inspect(path):
    raw = Path(path).read_bytes()
    if raw[:8] != b"dey\n036\0":
        raise ValueError("not an API19 ODEX")
    dex_offset, dex_length = struct.unpack_from("<II", raw, 8)
    dex = raw[dex_offset:dex_offset + dex_length]
    if len(dex) != dex_length or not dex.startswith(b"dex\n"):
        raise ValueError("invalid embedded DEX")
    string_count, string_offset = struct.unpack_from("<II", dex, 56)
    type_count, type_offset = struct.unpack_from("<II", dex, 64)
    class_count, class_offset = struct.unpack_from("<II", dex, 96)
    if (string_offset + 4 * string_count > len(dex) or
            type_offset + 4 * type_count > len(dex) or
            class_offset + 32 * class_count > len(dex)):
        raise ValueError("DEX table exceeds embedded section")
    strings = []
    for i in range(string_count):
        position = u32(dex, string_offset + 4 * i)
        _, position = read_uleb128(dex, position)
        end = dex.index(b"\0", position)
        # DEX uses modified UTF-8; target descriptors are ASCII.
        strings.append(dex[position:end].decode("latin-1"))
    types = [strings[u32(dex, type_offset + 4 * i)] for i in range(type_count)]
    classes = {}
    for i in range(class_count):
        index, flags = struct.unpack_from("<II", dex, class_offset + 32 * i)
        if types[index] in TARGETS:
            classes[types[index]] = flags
    if set(classes) != set(TARGETS):
        raise ValueError("boot class missing from ODEX")
    if any(flags & PREVERIFIED_OPTIMIZED != PREVERIFIED_OPTIMIZED
           for flags in classes.values()):
        raise ValueError("boot class lacks VERIFIED or OPTIMIZED flag")
    return {"odex_sha256": hashlib.sha256(raw).hexdigest(),
            "embedded_dex_sha256": hashlib.sha256(dex).hexdigest(),
            "embedded_dex_offset": dex_offset, "embedded_dex_length": dex_length,
            "class_access_flags": dict(sorted(classes.items()))}


def paired(clean, trace):
    result = {"schema_version": 1, "baseline": "android-4.4.4_r2",
              "clean": inspect(clean), "trace": inspect(trace)}
    if result["clean"]["embedded_dex_sha256"] != result["trace"]["embedded_dex_sha256"]:
        raise ValueError("CLEAN and TRACE boot DEX differ")
    if result["clean"]["class_access_flags"] != result["trace"]["class_access_flags"]:
        raise ValueError("CLEAN and TRACE boot class flags differ")
    return result


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--clean", type=Path, required=True)
    parser.add_argument("--trace", type=Path, required=True)
    parser.add_argument("--out", type=Path, required=True)
    args = parser.parse_args()
    result = paired(args.clean, args.trace)
    args.out.parent.mkdir(parents=True, exist_ok=True)
    args.out.write_text(json.dumps(result, indent=2) + "\n", encoding="utf-8")


if __name__ == "__main__":
    main()
