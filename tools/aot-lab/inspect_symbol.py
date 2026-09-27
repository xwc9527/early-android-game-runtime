#!/usr/bin/env python3
"""Compare a real ARMv7 ELF function's static encodings with the AOT decoder."""

import argparse
import hashlib
import json
import struct
from pathlib import Path

from capstone import CS_ARCH_ARM, CS_MODE_ARM, CS_MODE_THUMB, Cs

from translate import decode


def file_offset(elf, vaddr):
    if elf[:4] != b"\x7fELF" or elf[4] != 1 or elf[5] != 1:
        raise ValueError("expected little-endian ELF32")
    phoff = struct.unpack_from("<I", elf, 28)[0]
    phentsize, phnum = struct.unpack_from("<HH", elf, 42)
    for index in range(phnum):
        kind, offset, base, _, size, _, _, _ = struct.unpack_from(
            "<IIIIIIII", elf, phoff + index * phentsize)
        if kind == 1 and base <= vaddr < base + size:
            return offset + vaddr - base
    raise ValueError(f"address {vaddr:#x} is not in a file-backed PT_LOAD")


def inspect(path, address, size, thumb):
    elf = path.read_bytes()
    start = address & ~1 if thumb else address
    offset = file_offset(elf, start)
    decoder = Cs(CS_ARCH_ARM, CS_MODE_THUMB if thumb else CS_MODE_ARM)
    rows = []
    for item in decoder.disasm(elf[offset:offset + size], start):
        raw = int.from_bytes(item.bytes, "little")
        if thumb and len(item.bytes) == 4:
            raw = (int.from_bytes(item.bytes[:2], "little") << 16) | int.from_bytes(item.bytes[2:], "little")
        try:
            operation = decode(item.address, raw, len(item.bytes), thumb)
            supported = True
            reason = None
        except ValueError as error:
            operation = None
            supported = False
            reason = str(error)
        rows.append({"pc": f"0x{item.address:08x}", "bytes":item.bytes.hex(),
                     "mnemonic":item.mnemonic, "operands":item.op_str,
                     "aot_decoder_supported":supported,
                     "aot_operation":operation, "decoder_error":reason})
    return {"schema_version":1, "source_elf_sha256":hashlib.sha256(elf).hexdigest(),
            "symbol_address":f"0x{address:08x}", "symbol_size":size,
            "instruction_set":"Thumb" if thumb else "ARM",
            "decoded_instruction_count":len(rows),
            "supported_encoding_count":sum(row["aot_decoder_supported"] for row in rows),
            "complete_symbol_disassembly":sum(len(bytes.fromhex(row["bytes"])) for row in rows) == size,
            "rows":rows}


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--so", type=Path, required=True)
    parser.add_argument("--symbol-address", type=lambda item:int(item, 0), required=True)
    parser.add_argument("--symbol-size", type=lambda item:int(item, 0), required=True)
    parser.add_argument("--thumb", action="store_true")
    parser.add_argument("--out", type=Path, required=True)
    args = parser.parse_args()
    result = inspect(args.so, args.symbol_address, args.symbol_size, args.thumb)
    args.out.parent.mkdir(parents=True, exist_ok=True)
    args.out.write_text(json.dumps(result, indent=2) + "\n", encoding="utf-8")
    print(json.dumps({key:value for key,value in result.items() if key != "rows"}))


if __name__ == "__main__":
    main()
