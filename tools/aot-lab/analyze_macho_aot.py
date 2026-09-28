#!/usr/bin/env python3
"""Disassemble final optimized AArch64 Mach-O object symbols, without source guesses."""

import argparse
from collections import Counter
import json
from pathlib import Path
import struct

from capstone import CS_ARCH_ARM64, CS_MODE_ARM, Cs
from capstone.arm64 import ARM64_OP_MEM


def mach_o_symbols(data):
    if data[:4] != b"\xcf\xfa\xed\xfe":
        raise ValueError("expected little-endian 64-bit Mach-O")
    _, _, _, _, commands, _, _, _ = struct.unpack_from("<8I", data)
    offset = 32
    text_section = None
    symbol_table = None
    for _ in range(commands):
        command, size = struct.unpack_from("<2I", data, offset)
        if size < 8:
            raise ValueError("invalid Mach-O load command")
        if command == 0x19:
            count = struct.unpack_from("<I", data, offset + 64)[0]
            for index in range(count):
                sect = offset + 72 + index * 80
                name = data[sect:sect + 16].split(b"\0", 1)[0]
                if name == b"__text":
                    address, length, file_offset = struct.unpack_from("<QQI", data, sect + 32)
                    text_section = (index + 1, address, length, file_offset)
        elif command == 0x2:
            symbol_table = struct.unpack_from("<4I", data, offset + 8)
        offset += size
    if not text_section or not symbol_table:
        raise ValueError("Mach-O text or symbol table missing")
    section_id, address, length, file_offset = text_section
    symoff, nsyms, stroff, strsize = symbol_table
    strings = data[stroff:stroff + strsize]
    symbols = []
    for index in range(nsyms):
        name_off, typ, section, desc, value = struct.unpack_from(
            "<IBBHQ", data, symoff + index * 16)
        if section != section_id or not (address <= value < address + length):
            continue
        end = strings.find(b"\0", name_off)
        if end < 0:
            continue
        name = strings[name_off:end].decode("utf-8", errors="replace")
        symbols.append((value, name))
    symbols.sort()
    ranges = {}
    for index, (value, name) in enumerate(symbols):
        end = symbols[index + 1][0] if index + 1 < len(symbols) else address + length
        if end > value:
            start_offset = file_offset + value - address
            ranges[name] = (value, data[start_offset:start_offset + end - value])
    return ranges


def classify(instruction, decoder):
    mnemonic = instruction.mnemonic
    if mnemonic.startswith(("ldr", "ldp", "ldur", "ldxr", "ldaxr")):
        category = "load"
    elif mnemonic.startswith(("str", "stp", "stur", "stxr", "stlxr")):
        category = "store"
    elif mnemonic in {"bl", "blr"}:
        category = "call"
    elif mnemonic in {"b", "br", "ret"}:
        category = "unconditional_branch"
    elif mnemonic.startswith("b.") or mnemonic in {"cbz", "cbnz", "tbz", "tbnz"}:
        category = "conditional_branch"
    else:
        category = "other"
    stack = False
    guest_array_stack = False
    cpsr_stack = False
    memory_bases = []
    for operand in instruction.operands:
        if operand.type == ARM64_OP_MEM:
            base = decoder.reg_name(operand.mem.base)
            memory_bases.append(base)
            if base in {"sp", "x29", "w29"}:
                stack = True
                if base == "sp" and 0x40 <= operand.mem.disp <= 0x7c:
                    guest_array_stack = True
                if base == "sp" and operand.mem.disp == 0x3c:
                    cpsr_stack = True
    return category, stack, guest_array_stack, cpsr_stack, memory_bases


def analyze(path, wanted):
    symbols = mach_o_symbols(Path(path).read_bytes())
    decoder = Cs(CS_ARCH_ARM64, CS_MODE_ARM)
    decoder.detail = True
    result = {}
    for query in wanted:
        matches = [name for name in symbols if name.lstrip("_") == query]
        if len(matches) != 1:
            raise ValueError(f"symbol {query}: {len(matches)} matches")
        name = matches[0]
        address, code = symbols[name]
        rows = []
        counts = Counter()
        stack_count = 0
        guest_array_count = 0
        cpsr_stack_count = 0
        for insn in decoder.disasm(code, address):
            category, stack, guest_array, cpsr_stack, bases = classify(insn, decoder)
            counts[category] += 1
            stack_count += stack
            guest_array_count += guest_array
            cpsr_stack_count += cpsr_stack
            rows.append({"address": insn.address, "mnemonic": insn.mnemonic,
                         "operands": insn.op_str, "category": category,
                         "stack_access": stack,
                         "stack_guest_array_access": guest_array,
                         "stack_cpsr_access": cpsr_stack,
                         "memory_bases": bases})
        if len(rows) * 4 != len(code):
            raise ValueError(f"incomplete disassembly of {name}")
        result[query] = {"symbol": name, "object_path": str(path),
                         "machine_code_bytes": len(code),
                         "host_instruction_count": len(rows),
                         "category_counts": dict(counts),
                         "stack_memory_accesses": stack_count,
                         "stack_guest_array_accesses": guest_array_count,
                         "stack_cpsr_accesses": cpsr_stack_count,
                         "instructions": rows}
    return result


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("object")
    parser.add_argument("--symbol", action="append", required=True)
    parser.add_argument("--out", required=True)
    args = parser.parse_args()
    result = analyze(args.object, args.symbol)
    Path(args.out).write_text(json.dumps(result, indent=2) + "\n", newline="\n")
    for name, record in result.items():
        print(name, record["host_instruction_count"],
              record["category_counts"], "stack", record["stack_memory_accesses"])


if __name__ == "__main__":
    main()
