#!/usr/bin/env python3
"""Translate a recorded ARMv7 guest trace into a signed-code ARM64 C artifact."""

import argparse
import hashlib
import json
import struct
import time
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]


def ror32(value, bits):
    bits &= 31
    return ((value >> bits) | (value << (32 - bits))) & 0xffffffff


def sign_extend(value, bits):
    sign = 1 << (bits - 1)
    return (value ^ sign) - sign


def arm_expand_imm(insn):
    return ror32(insn & 0xff, ((insn >> 8) & 15) * 2)


def decode(pc, insn, length, thumb):
    """Return a generic operation or raise ValueError. No guest-PC special cases."""
    if thumb and length == 2:
        if insn & 0xf800 == 0x2000:
            return ("movs_imm", (insn >> 8) & 7, insn & 0xff)
        if insn & 0xff00 == 0x4600:
            rd = (insn & 7) | ((insn >> 4) & 8)
            rm = (insn >> 3) & 15
            return ("mov_reg", rd, rm)
        if insn & 0xf800 == 0x6800:
            return ("ldr_imm", insn & 7, (insn >> 3) & 7, ((insn >> 6) & 31) * 4, True, pc)
        if insn & 0xf800 == 0x9800:
            return ("ldr_imm", (insn >> 8) & 7, 13, (insn & 0xff) * 4, True, pc)
        if insn & 0xf500 == 0xb100:
            i = (insn >> 9) & 1
            imm5 = (insn >> 3) & 31
            rn = insn & 7
            nonzero = insn & 0x0800 != 0
            target = (pc + 4 + ((i << 6) | (imm5 << 1))) & 0xffffffff
            return ("cbz", rn, target, pc + 2, nonzero)
        if insn & 0xf800 == 0xe000:
            imm11 = insn & 0x7ff
            offset = sign_extend(imm11 << 1, 12)
            return ("b", (pc + 4 + offset) & 0xffffffff)
        if insn & 0xff87 == 0x4780:
            return ("blx_reg", (insn >> 3) & 15, pc + 2)
    if thumb and length == 4:
        hw0, hw1 = (insn >> 16) & 0xffff, insn & 0xffff
        if hw0 == 0xe92d:
            return ("stmdb_sp", hw1 & 0x5fff)
        if hw0 == 0xe8bd:
            mask = hw1 & 0x1fff
            if hw1 & 0x8000:
                mask |= 1 << 15
            return ("ldmia_sp", mask)
        if hw0 & 0xfff0 == 0xf8d0:
            return ("ldr_imm", (hw1 >> 12) & 15, hw0 & 15, hw1 & 0xfff, True, pc)
        if hw0 & 0xfbf0 == 0xf240:
            i = (hw0 >> 10) & 1
            imm4 = hw0 & 15
            imm3 = (hw1 >> 12) & 7
            rd = (hw1 >> 8) & 15
            imm8 = hw1 & 0xff
            immediate = (imm4 << 12) | (i << 11) | (imm3 << 8) | imm8
            return ("movw", rd, immediate)
        if hw0 & 0xf800 == 0xf000 and hw1 & 0xd000 == 0xc000:
            s = (hw0 >> 10) & 1
            imm10 = hw0 & 0x3ff
            j1 = (hw1 >> 13) & 1
            j2 = (hw1 >> 11) & 1
            imm11 = hw1 & 0x7ff
            i1 = 0 if (j1 ^ s) else 1
            i2 = 0 if (j2 ^ s) else 1
            immediate = sign_extend((s << 24) | (i1 << 23) | (i2 << 22) | (imm10 << 12) | (imm11 << 1), 25)
            target = (((pc + 4) & ~3) + immediate) & 0xffffffff
            return ("blx_imm", target, pc + 4)
    if not thumb and length == 4:
        if insn & 0x0fe00010 == 0x00800000 and (insn >> 4) & 0xff == 0:
            rn = (insn >> 16) & 15
            rd = (insn >> 12) & 15
            rm = insn & 15
            return ("add_reg", rd, rn, rm, pc)
        if insn & 0x0fe00000 == 0x02800000:
            rn = (insn >> 16) & 15
            rd = (insn >> 12) & 15
            immediate = arm_expand_imm(insn)
            return ("add_imm", rd, rn, immediate, pc)
        if insn & 0x0e500000 == 0x04000000:
            rn = (insn >> 16) & 15
            rd = (insn >> 12) & 15
            immediate = insn & 0xfff
            up = (insn >> 23) & 1
            writeback = (insn >> 21) & 1
            return ("str_wb", rd, rn, immediate, up, writeback, pc)
        if insn & 0x0c500000 == 0x04100000:
            rn = (insn >> 16) & 15
            rd = (insn >> 12) & 15
            immediate = insn & 0xfff
            up = (insn >> 23) & 1
            writeback = (insn >> 21) & 1
            return ("ldr_wb", rd, rn, immediate, up, writeback, pc)
    raise ValueError(f"unsupported encoding pc={pc:#x} thumb={thumb} len={length} insn={insn:#x}")


def is_svc(row):
    return not row["thumb"] and (row["insn"] & 0xff000000) == 0xef000000


def is_terminal(op):
    if op[0] in {"b", "cbz", "blx_reg", "blx_imm"}:
        return True
    if op[0] == "ldr_wb" and op[1] == 15:
        return True
    if op[0] == "ldmia_sp" and op[1] & (1 << 15):
        return True
    return op[0] == "ldr_imm" and op[1] == 15


def blocks_from_trace(rows):
    info = {}
    for row in rows:
        if not is_svc(row):
            info.setdefault(row["pc"], row)
    starts = []
    seen = set()

    def mark(pc):
        if pc in info and pc not in seen:
            seen.add(pc)
            starts.append(pc)

    for row in rows:
        if not is_svc(row):
            mark(row["pc"])
            break
    for index, row in enumerate(rows):
        if is_svc(row):
            if index + 1 < len(rows):
                mark(rows[index + 1]["pc"])
            continue
        op = decode(row["pc"], row["insn"], row["len"], row["thumb"])
        if not is_terminal(op):
            continue
        if index + 1 < len(rows):
            mark(rows[index + 1]["pc"])
        if op[0] == "b":
            mark(op[1])
        elif op[0] == "cbz":
            mark(op[2])
            mark(op[3])
        elif op[0] == "blx_imm":
            mark(op[1])
    built = []
    for start in starts:
        body = []
        pc = start
        while pc in info:
            row = info[pc]
            body.append(row)
            op = decode(row["pc"], row["insn"], row["len"], row["thumb"])
            if is_terminal(op):
                break
            pc = row["pc"] + row["len"]
        built.append((start, body))
    return built


def emit_op(op, thumb):
    kind = op[0]
    if kind == "movs_imm":
        return f"agr_aot_movs_imm(s, {op[1]}, {op[2]}u);"
    if kind == "mov_reg":
        return f"agr_aot_mov_reg(s, {op[1]}, {op[2]});"
    if kind == "movw":
        return f"agr_aot_movw(s, {op[1]}, {op[2]}u);"
    if kind == "ldr_imm":
        rd, rn, imm = op[1], op[2], op[3]
        pc = op[5]
        if rn == 15:
            base = f"{(pc + 4) & ~3}u" if thumb else f"{pc + 8}u"
        else:
            base = f"s->r[{rn}]"
        return f"{{ int rc = agr_aot_ldr(s, {rd}, {base} + {imm}u); if (rc) return rc; }}"
    if kind == "stmdb_sp":
        return f"if (agr_aot_stmdb_sp(s, {op[1]}u)) return AGR_AOT_FAULT;"
    if kind == "ldmia_sp":
        line = f"if ((rc = agr_aot_ldmia_sp(s, {op[1]}u))) return rc;"
        return line
    if kind == "add_reg":
        rd, rn, rm, pc = op[1:]
        base = f"{pc + 8}u" if rn == 15 else f"s->r[{rn}]"
        source = f"{pc + 8}u" if rm == 15 else f"s->r[{rm}]"
        return f"agr_aot_add_imm(s, {rd}, {base}, {source});"
    if kind == "str_wb":
        rd, rn, imm, up, writeback, pc = op[1:]
        sign = "+" if up else "-"
        base = f"({pc + 8}u)" if rn == 15 else f"s->r[{rn}]"
        value = f"({pc + 8}u)" if rd == 15 else f"s->r[{rd}]"
        lines = [f"{{ uint32_t addr = {base} {sign} {imm}u;"]
        if writeback and rn != 15:
            lines.append(f"s->r[{rn}] = addr;")
        lines.append(f"if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, {value}); }}")
        return " ".join(lines)
    if kind == "add_imm":
        rd, rn, imm, pc = op[1:]
        if rn == 15:
            return f"agr_aot_add_imm(s, {rd}, {pc + 8}u, {imm}u);"
        return f"agr_aot_add_imm(s, {rd}, s->r[{rn}], {imm}u);"
    if kind == "ldr_wb":
        rd, rn, imm, up, writeback, pc = op[1:]
        sign = "+" if up else "-"
        base = f"({pc + 8}u)" if rn == 15 else f"s->r[{rn}]"
        lines = [f"{{ uint32_t addr = {base} {sign} {imm}u;"]
        if writeback and rn != 15:
            lines.append(f"s->r[{rn}] = addr;")
        lines.append(f"if ((rc = agr_aot_ldr(s, {rd}, addr))) return rc; }}")
        return " ".join(lines)
    if kind == "b":
        return f"s->r[15] = {op[1]}u; return AGR_AOT_BOUNDARY;"
    if kind == "cbz":
        rn, target, fall, nonzero = op[1:]
        test = f"s->r[{rn}]" if nonzero else f"!s->r[{rn}]"
        return f"s->r[15] = {test} ? {target}u : {fall}u; return AGR_AOT_BOUNDARY;"
    if kind == "blx_reg":
        rm, nxt = op[1:]
        return (
            f"agr_aot_branch_reg(s, s->r[{rm}], {nxt}u, {1 if thumb else 0}); return AGR_AOT_BOUNDARY;"
        )
    if kind == "blx_imm":
        target, nxt = op[1:]
        return f"agr_aot_branch_reg(s, {target}u, {nxt}u, {1 if thumb else 0}); return AGR_AOT_BOUNDARY;"
    raise ValueError(kind)


def emit(rows, destination):
    pieces = ["#include \"agr_aot.h\"", ""]
    entries = []
    for start, body in blocks_from_trace(rows):
        name = f"aot_{start:08x}"
        lines = [f"static int {name}(AgrAotRegs *s) {{", "    int rc = 0;", "    (void)rc;"]
        ended = False
        for row in body:
            op = decode(row["pc"], row["insn"], row["len"], row["thumb"])
            lines.append("    agr_aot_count_instruction();")
            lines.append("    " + emit_op(op, row["thumb"]))
            if "return AGR_AOT_BOUNDARY" in lines[-1] or op[0] == "ldmia_sp" and (op[1] & (1 << 15)):
                ended = True
                break
        if not ended:
            nxt = body[-1]["pc"] + body[-1]["len"]
            lines.append(f"    s->r[15] = {nxt}u;")
            lines.append("    return AGR_AOT_BOUNDARY;")
        lines.append("}")
        pieces.extend(lines)
        pieces.append("")
        entries.append((start, name))
    entries.sort()
    pieces.append("const AgrAotEntry agr_aot_blocks[] = {")
    if not entries:
        pieces.append("    {0, 0}")
    else:
        for pc, name in entries:
            pieces.append(f"    {{{pc}u, {name}}},")
    pieces.append("};")
    pieces.append(f"const uint32_t agr_aot_block_count = {len(entries)}u;")
    pieces.append("")
    destination.write_text("\n".join(pieces), encoding="utf-8", newline="\n")
    return entries


def emit_partial(rows, destination, allowed_kinds):
    """Emit only already-proven generic operations, one guarded instruction per block.

    Unknown operations remain in the existing interpreter fallback. This is a
    coverage experiment, not a claim that the new workload is fully AOT-ready.
    """
    unique = {}
    ambiguous = set()
    for row in rows:
        previous = unique.setdefault(row["pc"], row)
        if (previous["insn"], previous["len"], previous["thumb"]) != (
                row["insn"], row["len"], row["thumb"]):
            ambiguous.add(row["pc"])
    pieces = ['#include "agr_aot.h"', ""]
    entries = []
    for pc, row in sorted(unique.items()):
        if pc in ambiguous:
            continue
        if is_svc(row):
            continue
        if not row["thumb"] and (row["insn"] >> 28) != 14:
            continue
        try:
            op = decode(row["pc"], row["insn"], row["len"], row["thumb"])
        except ValueError:
            continue
        if op[0] not in allowed_kinds or op[0] == "mov_reg" and op[1] == 15:
            continue
        raw, length = row["insn"], row["len"]
        name = f"aot_{pc:08x}"
        lines = [f"static int {name}(AgrAotRegs *s) {{", "    int rc = 0;", "    (void)rc;"]
        lines.append("    if (%s) return AGR_AOT_MISS;" %
                     ("!(*s->cpsr & 0x20u)" if row["thumb"] else "(*s->cpsr & 0x20u)"))
        if row["thumb"] and length == 2:
            guards = [f"agr_aot_load16(s, {pc}u) != {raw}u"]
        elif row["thumb"]:
            guards = [f"agr_aot_load16(s, {pc}u) != {raw >> 16}u",
                      f"agr_aot_load16(s, {pc + 2}u) != {raw & 0xffff}u"]
        else:
            guards = [f"agr_aot_load32(s, {pc}u) != {raw}u"]
        lines.append(f"    if ({' || '.join(guards)}) return AGR_AOT_MISS;")
        lines.append("    agr_aot_count_instruction();")
        lines.append("    " + emit_op(op, row["thumb"]))
        if not is_terminal(op):
            lines.append(f"    s->r[15] = {pc + length}u;")
            lines.append("    return AGR_AOT_BOUNDARY;")
        lines.append("}")
        pieces.extend(lines + [""])
        entries.append((pc, name))
    pieces.append("const AgrAotEntry agr_aot_blocks[] = {")
    pieces.extend(f"    {{{pc}u, {name}}}," for pc, name in entries)
    if not entries:
        pieces.append("    {0, 0},")
    pieces.extend(["};", f"const uint32_t agr_aot_block_count = {len(entries)}u;", ""])
    destination.write_text("\n".join(pieces), encoding="utf-8", newline="\n")
    return entries


def load_trace(path):
    rows = []
    for line in Path(path).read_text(encoding="utf-8").splitlines():
        if not line.strip():
            continue
        fields = [int(item) for item in line.split()]
        pc, insn, length, thumb, cpsr = fields[:5]
        row = {"pc": pc, "insn": insn, "len": length, "thumb": thumb, "cpsr": cpsr}
        if len(fields) >= 21:
            row["regs"] = fields[5:21]
        rows.append(row)
    return rows


def self_test(so_path):
    from capstone import CS_ARCH_ARM, CS_MODE_ARM, CS_MODE_THUMB, Cs
    data = Path(so_path).read_bytes()
    base = 0x02800000
    thumb = Cs(CS_ARCH_ARM, CS_MODE_THUMB)
    arm = Cs(CS_ARCH_ARM, CS_MODE_ARM)
    ranges = [(0xdc4, 0xf04, True), (0xd08, 0xd44, False)]
    rows = []
    for start, end, is_thumb in ranges:
        code = data[start:end]
        decoder = thumb if is_thumb else arm
        for item in decoder.disasm(code, base + start):
            raw = int.from_bytes(item.bytes, "little") if not is_thumb or len(item.bytes) == 2 else (
                int.from_bytes(item.bytes[0:2], "little") << 16 | int.from_bytes(item.bytes[2:4], "little"))
            if not is_thumb:
                raw = int.from_bytes(item.bytes, "little")
            rows.append({"pc": item.address, "insn": raw, "len": len(item.bytes), "thumb": int(is_thumb), "cpsr": 0x20 if is_thumb else 0})
            op = decode(item.address, raw, len(item.bytes), is_thumb)
            if "#" in item.op_str and item.mnemonic in {"b", "cbz", "blx"}:
                target = int(item.op_str.split("#")[-1], 0)
                got = op[2] if op[0] == "cbz" else op[1]
                if got != target:
                    raise SystemExit(f"target mismatch {item.mnemonic} at {item.address:#x}: {got:#x} != {target:#x} raw={raw:#x}")
    out = ROOT / "Runtime" / "AotLab" / "aot_blocks.selftest.c"
    entries = emit(rows, out)
    out.unlink()
    print(f"self-test decoded {len(rows)} instructions into {len(entries)} blocks")


def main():
    started = time.perf_counter()
    parser = argparse.ArgumentParser()
    parser.add_argument("--trace")
    parser.add_argument("--out", default=str(ROOT / "Runtime" / "AotLab" / "aot_blocks.c"))
    parser.add_argument("--manifest")
    parser.add_argument("--self-test")
    parser.add_argument("--partial-baseline-trace")
    args = parser.parse_args()
    if args.self_test:
        self_test(args.self_test)
        return
    rows = load_trace(args.trace)
    allowed_kinds = None
    if args.partial_baseline_trace:
        baseline = load_trace(args.partial_baseline_trace)
        allowed_kinds = {decode(row["pc"], row["insn"], row["len"], row["thumb"])[0]
                         for row in baseline if not is_svc(row)}
        entries = emit_partial(rows, Path(args.out), allowed_kinds)
    else:
        entries = emit(rows, Path(args.out))
    manifest = {
        "trace_instructions": len(rows),
        "unique_pcs": len({row["pc"] for row in rows}),
        "thumb_instructions": sum(1 for row in rows if row["thumb"]),
        "arm_instructions": sum(1 for row in rows if not row["thumb"]),
        "vfp_instructions": 0,
        "input_trace_sha256": hashlib.sha256(Path(args.trace).read_bytes()).hexdigest(),
        "partial_baseline_trace_sha256": hashlib.sha256(Path(args.partial_baseline_trace).read_bytes()).hexdigest() if args.partial_baseline_trace else None,
        "allowed_op_kinds": sorted(allowed_kinds) if allowed_kinds is not None else None,
        "preparation_wall_seconds": time.perf_counter() - started,
        "generated_c_bytes": Path(args.out).stat().st_size,
        "blocks": [{"pc": pc, "name": name} for pc, name in entries],
    }
    if args.manifest:
        Path(args.manifest).write_text(json.dumps(manifest, indent=2) + "\n", encoding="utf-8", newline="\n")
    print(json.dumps({"blocks": len(entries), "instructions": len(rows)}))


if __name__ == "__main__":
    main()
