#!/usr/bin/env python3
"""Minimal class-only DEX files for the Phase 3A0 classpath contract."""

import pathlib
import struct
import sys


def uleb(value: int) -> bytes:
    out = bytearray()
    while True:
        byte = value & 0x7F
        value >>= 7
        out.append(byte | (0x80 if value else 0))
        if not value:
            return bytes(out)


def align(data: bytearray) -> None:
    while len(data) % 4:
        data.append(0)


def build(descriptors: list[str]) -> bytes:
    strings = sorted(set(descriptors) | {"Ljava/lang/Object;"})
    sidx = {text: index for index, text in enumerate(strings)}
    header_size = 0x70
    string_ids_off = header_size
    type_ids_off = string_ids_off + 4 * len(strings)
    class_defs_off = type_ids_off + 4 * len(strings)
    data_off = class_defs_off + 32 * len(descriptors)
    data = bytearray(b"\0" * data_off)
    string_offsets = []
    for text in strings:
        string_offsets.append(len(data))
        raw = text.encode("utf-8")
        data.extend(uleb(len(text)))
        data.extend(raw)
        data.append(0)
    align(data)
    for index, text in enumerate(strings):
        struct.pack_into("<I", data, string_ids_off + 4 * index, string_offsets[index])
        struct.pack_into("<I", data, type_ids_off + 4 * index, sidx[text])
    for index, descriptor in enumerate(descriptors):
        struct.pack_into(
            "<IIIIIIII",
            data,
            class_defs_off + 32 * index,
            sidx[descriptor],
            1,
            sidx["Ljava/lang/Object;"],
            0,
            0xFFFFFFFF,
            0,
            0,
            0,
        )
    file_size = len(data)
    data[0:8] = b"dex\n035\0"
    struct.pack_into("<I", data, 32, file_size)
    struct.pack_into("<I", data, 36, header_size)
    struct.pack_into("<I", data, 40, 0x12345678)
    struct.pack_into("<I", data, 56, len(strings))
    struct.pack_into("<I", data, 60, string_ids_off)
    struct.pack_into("<I", data, 64, len(strings))
    struct.pack_into("<I", data, 68, type_ids_off)
    struct.pack_into("<I", data, 96, len(descriptors))
    struct.pack_into("<I", data, 100, class_defs_off)
    struct.pack_into("<I", data, 104, file_size - data_off)
    struct.pack_into("<I", data, 108, data_off)
    return bytes(data)


def main() -> None:
    out = pathlib.Path(sys.argv[1])
    descriptors = sys.argv[2:]
    out.write_bytes(build(descriptors))


if __name__ == "__main__":
    main()
