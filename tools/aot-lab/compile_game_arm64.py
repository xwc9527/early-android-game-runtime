#!/usr/bin/env python3
"""Conservative ELF-to-AArch64 prototype using AGR's existing guest ABI."""

import argparse
from collections import Counter
import hashlib
import json
from pathlib import Path
import time

from offline_elf import Elf32Arm
from offline_scan import scan
from translate import decode, is_svc, is_terminal


SUPPORTED = {
    "mov_reg", "movs_imm", "mov_imm", "movw", "movt", "add_imm",
    "ldr_imm", "ldr_wb", "stmdb_sp", "ldmia_sp", "b", "cbz",
    "blx_reg", "blx_imm", "bl_imm", "bx_reg",
}


def immediate(reg, value):
    value &= 0xffffffff
    return [f"movz {reg}, #{value & 0xffff}",
            f"movk {reg}, #{value >> 16}, lsl #16"] if value >> 16 else [f"movz {reg}, #{value}"]


def load_reg(index, target="w12"):
    return [f"ldr {target}, [x9, #{index * 4}]"]


def store_reg(index, source="w12"):
    return [f"str {source}, [x9, #{index * 4}]"]


def relocated(value, target="w12"):
    return immediate(target, value) + [f"add {target}, w15, {target}"]


def register_or_pc(index, pc, thumb, target="w12"):
    return relocated(pc + (4 if thumb else 8), target) if index == 15 else load_reg(index, target)


def branch_target(target_lines, link=None, thumb_link=False):
    lines = list(target_lines)
    if link is not None:
        lines += relocated(link, "w13")
        if thumb_link:
            lines.append("orr w13, w13, #1")
        lines += store_reg(14, "w13")
    lines += ["ldr w13, [x10]", "and w14, w12, #1", "lsl w14, w14, #5",
              "bic w13, w13, #0x20", "orr w13, w13, w14", "str w13, [x10]",
              "bic w12, w12, #1"] + store_reg(15) + ["b L_success"]
    return lines


def emit_op(op, pc, thumb, serial):
    kind = op[0]
    lines = []
    if kind == "mov_reg":
        return load_reg(op[2]) + store_reg(op[1])
    if kind in {"mov_imm", "movw"}:
        return immediate("w12", op[2]) + store_reg(op[1])
    if kind == "movt":
        return load_reg(op[1]) + ["and w12, w12, #0xffff"] + immediate("w13", op[2] << 16) + ["orr w12, w12, w13"] + store_reg(op[1])
    if kind == "movs_imm":
        return (immediate("w12", op[2]) + store_reg(op[1]) +
                ["cmp w12, #0", "mrs x13, nzcv", "ldr w14, [x10]",
                 "and w13, w13, #0xc0000000", "and w14, w14, #0x3fffffff",
                 "orr w14, w14, w13", "str w14, [x10]"])
    if kind == "add_imm":
        rd, rn, imm, _ = op[1:]
        lines = register_or_pc(rn, pc, thumb)
        lines += immediate("w13", imm) + ["add w12, w12, w13"] + store_reg(rd)
        return lines + (["b L_success"] if rd == 15 else [])
    if kind in {"ldr_imm", "ldr_wb"}:
        if kind == "ldr_imm":
            rd, rn, imm = op[1:4]
            lines = (relocated((pc + 4) & ~3 if thumb else pc + 8)
                     if rn == 15 else load_reg(rn))
            lines += immediate("w13", imm) + ["add w12, w12, w13"]
        else:
            rd, rn, imm, up, writeback, _ = op[1:]
            lines = register_or_pc(rn, pc, thumb)
            lines += immediate("w13", imm) + [f"{'add' if up else 'sub'} w12, w12, w13"]
            if writeback and rn != 15:
                lines += store_reg(rn)
        lines += ["cmp w12, #0x1000", "b.lo L_fault"] + immediate("w13", 0xfffffffc)
        lines += ["cmp w12, w13", "b.hi L_fault", "add x13, x11, w12, uxtw",
                  "ldr w12, [x13]"]
        if rd == 15:
            return lines + branch_target([])
        return lines + store_reg(rd)
    if kind == "stmdb_sp":
        mask = op[1]
        regs = [i for i in range(16) if mask & (1 << i)]
        lines = load_reg(13) + immediate("w13", len(regs) * 4) + ["sub w12, w12, w13",
                "cmp w12, #0x1000", "b.lo L_fault", "add x13, x11, w12, uxtw"]
        for ordinal, reg in enumerate(regs):
            lines += load_reg(reg, "w14") + [f"str w14, [x13, #{ordinal * 4}]"]
        return lines + store_reg(13)
    if kind == "ldmia_sp":
        mask = op[1]
        regs = [i for i in range(16) if mask & (1 << i)]
        lines = load_reg(13)
        for ordinal, reg in enumerate(regs):
            lines += immediate("w13", ordinal * 4) + ["add w14, w12, w13",
                     "cmp w14, #0x1000", "b.lo L_fault"] + immediate("w13", 0xfffffffc)
            lines += ["cmp w14, w13", "b.hi L_fault", "add x13, x11, w14, uxtw",
                      "ldr w14, [x13]", f"str w14, [sp, #{ordinal * 4}]"]
        lines += immediate("w13", len(regs) * 4) + ["add w12, w12, w13"] + store_reg(13)
        for ordinal, reg in enumerate(regs):
            lines += [f"ldr w12, [sp, #{ordinal * 4}]"] + store_reg(reg)
        if 15 in regs:
            return lines + load_reg(15) + branch_target([])
        return lines
    if kind == "b":
        return relocated(op[1]) + store_reg(15) + ["b L_success"]
    if kind == "cbz":
        rn, target, fall, nonzero = op[1:]
        label = f"L_taken_{serial}"
        lines = load_reg(rn) + [f"{'cbnz' if nonzero else 'cbz'} w12, {label}"]
        lines += relocated(fall) + store_reg(15) + ["b L_success", f"{label}:"]
        return lines + relocated(target) + store_reg(15) + ["b L_success"]
    if kind in {"blx_reg", "bx_reg"}:
        rm = op[1]
        return branch_target(register_or_pc(rm, pc, thumb),
                             op[2] if kind == "blx_reg" else None, thumb)
    if kind in {"bl_imm", "blx_imm"}:
        target, nxt = op[1:]
        lines = relocated(target)
        if kind == "bl_imm":
            lines.append("orr w12, w12, #1")
        return branch_target(lines, nxt, kind == "bl_imm" or thumb)
    raise ValueError(kind)


def discover(image, allowed=SUPPORTED):
    rows, entry_starts, _, reasons = scan(image, "all-exidx")
    ordered = sorted(rows.values(), key=lambda row: row["pc"])
    eligible = {}
    operations = {}
    excluded = Counter()
    for row in ordered:
        pc = row["pc"]
        if is_svc(row) or not row["thumb"] and row["insn"] >> 28 != 14:
            excluded["svc_or_conditional_arm"] += 1
            continue
        try:
            op = decode(pc, row["insn"], row["len"], row["thumb"])
        except ValueError:
            excluded["unsupported_encoding"] += 1
            continue
        if ((allowed is not None and op[0] not in allowed) or
                op[0] == "mov_reg" and op[1] == 15 or
                allowed is SUPPORTED and op[0] == "add_imm" and row["thumb"] and op[2] == 15):
            excluded[f"unsupported_op:{op[0]}"] += 1
            continue
        eligible[pc] = row
        operations[pc] = op
    starts = {pc for pc, _ in entry_starts if pc in eligible}
    for index, row in enumerate(ordered):
        pc = row["pc"]
        if pc not in eligible:
            if index + 1 < len(ordered) and ordered[index + 1]["pc"] in eligible:
                starts.add(ordered[index + 1]["pc"])
            continue
        if index == 0:
            starts.add(pc)
        elif ordered[index - 1]["pc"] not in eligible:
            starts.add(pc)
        else:
            previous = ordered[index - 1]
            if (is_terminal(operations[previous["pc"]]) or
                    previous["pc"] + previous["len"] != pc or
                    previous["thumb"] != row["thumb"]):
                starts.add(pc)
        op = operations[pc]
        if is_terminal(op):
            if index + 1 < len(ordered) and ordered[index + 1]["pc"] in eligible:
                starts.add(ordered[index + 1]["pc"])
            if op[0] == "b":
                starts.add(op[1])
            elif op[0] == "b_cond":
                starts.update((op[2], op[3]))
            elif op[0] == "cbz":
                starts.update((op[2], op[3]))
            elif op[0] in {"bl_imm", "blx_imm"}:
                starts.add(op[1])
    starts.intersection_update(eligible)
    blocks = []
    for start in sorted(starts):
        body = []
        pc = start
        while pc in eligible:
            row = eligible[pc]
            op = operations[pc]
            body.append((row, op))
            if is_terminal(op):
                break
            nxt = pc + row["len"]
            if nxt in starts and nxt != start or nxt in eligible and eligible[nxt]["thumb"] != row["thumb"]:
                break
            pc = nxt
        blocks.append((start, body))
    return blocks, excluded, reasons


def emit_block(start, body):
    name = f"agr_game_compiled_{start:08x}"
    use_stack = any(op[0] == "ldmia_sp" for _, op in body)
    lines = [".text", ".p2align 2", f".globl _{name}", f"_{name}:"]
    if use_stack:
        lines.append("sub sp, sp, #64")
    lines += ["ldr x9, [x0]", "ldr x10, [x0, #8]", "ldr x11, [x0, #16]",
              "ldr w15, [x0, #24]", "ldr w12, [x10]", "and w12, w12, #0x20",
              f"cmp w12, #{0x20 if body[0][0]['thumb'] else 0}", "b.ne L_mode_miss"]
    for row, _ in body:
        pc = row["pc"]
        lines += relocated(pc) + ["add x13, x11, w12, uxtw"]
        raw = row["insn"]
        if row["thumb"] and row["len"] == 2:
            lines += ["ldrh w14, [x13]"] + immediate("w12", raw)
        else:
            expected = ((raw >> 16) | ((raw & 0xffff) << 16)) if row["thumb"] else raw
            lines += ["ldr w14, [x13]"] + immediate("w12", expected)
        lines += ["cmp w14, w12", "b.ne L_miss"]
    ended = False
    for serial, (row, op) in enumerate(body):
        lines += emit_op(op, row["pc"], row["thumb"], serial)
        if is_terminal(op):
            ended = True
            break
    if not ended:
        last = body[-1][0]
        lines += relocated(last["pc"] + last["len"]) + store_reg(15)
    lines += ["L_success:", "mov w0, #1", "b L_return",
              "L_fault:", "mov w0, #-1", "b L_return",
              "L_miss:", "mov w0, #3", "b L_return",
              "L_mode_miss:", "mov w0, #4", "L_return:"]
    if use_stack:
        lines.append("add sp, sp, #64")
    lines += ["ret", ""]
    # Local labels must be private to each function.
    return name, "\n".join(line.replace("L_", f"L_{start:08x}_") for line in lines)


def emit_table(blocks, image):
    entries = [(pc, f"agr_game_compiled_{pc:08x}", len(body)) for pc, body in blocks]
    pieces = ['#include "agr_aot.h"', '']
    pieces += [f"extern int {name}(AgrAotRegs *);" for _, name, _ in entries]
    pieces += ['', 'const AgrAotEntry agr_aot_debug_blocks[] = {{0, 0, 0}};',
               'const uint32_t agr_aot_debug_block_count = 0u;',
               'const AgrAotEntry agr_aot_fast_blocks[] = {']
    pieces += [f"    {{{pc}u, {name}, {length}u}}," for pc, name, length in entries]
    pieces += ['};', f'const uint32_t agr_aot_fast_block_count = {len(entries)}u;']
    size = 1
    while size < max(2, len(entries) * 2):
        size <<= 1
    hashed = [None] * size
    for entry in entries:
        index = ((entry[0] >> 1) * 2654435761) & (size - 1)
        while hashed[index] is not None:
            index = (index + 1) & (size - 1)
        hashed[index] = entry
    pieces += ['const AgrAotEntry agr_aot_fast_hash[] = {']
    pieces += [f"    {{{e[0]}u, {e[1]}, {e[2]}u}}," if e else '    {0, 0, 0},' for e in hashed]
    pieces += ['};', f'const uint32_t agr_aot_fast_hash_mask = {size - 1}u;',
               'const uint32_t agr_aot_fast_relocatable = 1u;']
    fnv = 14695981039346656037
    for byte in image.data:
        fnv = ((fnv ^ byte) * 1099511628211) & 0xffffffffffffffff
    pieces += [f'const uint64_t agr_aot_input_elf_fnv64 = {fnv}ull;',
               f'const uint32_t agr_aot_input_elf_bytes = {len(image.data)}u;', '']
    return "\n".join(pieces)


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('--elf', required=True)
    parser.add_argument('--asm', required=True)
    parser.add_argument('--table', required=True)
    parser.add_argument('--manifest', required=True)
    args = parser.parse_args()
    start_time = time.perf_counter()
    image = Elf32Arm(args.elf)
    blocks, excluded, discovery_reasons = discover(image)
    asm = []
    for start, body in blocks:
        _, source = emit_block(start, body)
        asm.append(source)
    asm_text = "\n".join(asm)
    table_text = emit_table(blocks, image)
    Path(args.asm).write_text(asm_text, encoding='utf-8', newline='\n')
    Path(args.table).write_text(table_text, encoding='utf-8', newline='\n')
    result = {
        'schema': 'agr.game-compiler-arm64-prototype.v1',
        'input_elf_sha256': image.sha256,
        'elf_sha256': image.sha256,
        'input_elf_bytes': len(image.data),
        'executable_bytes': sum(s.size for s in image.executable),
        'entry_policy': 'all-exidx',
        'execution_trace_input': False,
        'relocatable': True,
        'load_bias': 0,
        'load_bias_source': 'runtime formal linker result',
        'runtime_load_bias': True,
        'compiled_block_count': len(blocks),
        'fast_block_count': len(blocks),
        'debug_entry_count': 0,
        'static_compiled_instructions': sum(len(body) for _, body in blocks),
        'supported_op_kinds': sorted(SUPPORTED),
        'excluded_reasons': dict(sorted(excluded.items())),
        'static_discovery_reasons': dict(sorted(discovery_reasons.items())),
        'assembly_sha256': hashlib.sha256(asm_text.encode()).hexdigest(),
        'assembly_bytes': len(asm_text.encode()),
        'table_sha256': hashlib.sha256(table_text.encode()).hexdigest(),
        'generated_c_sha256': hashlib.sha256(table_text.encode()).hexdigest(),
        'table_bytes': len(table_text.encode()),
        'offline_preparation_seconds': time.perf_counter() - start_time,
    }
    Path(args.manifest).write_text(json.dumps(result, indent=2) + '\n')
    print(json.dumps(result, indent=2))


if __name__ == '__main__':
    main()
