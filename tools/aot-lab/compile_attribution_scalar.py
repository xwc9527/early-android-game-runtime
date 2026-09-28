#!/usr/bin/env python3
"""Compiler-style scalar lowering for the two selected real ARM regions.

Selection comes from archived execution; operations and CFG come only from ELF.
Unsupported operations fail closed. No game name or guest PC changes semantics.
"""
import argparse
import hashlib
import json
from pathlib import Path
import time

from compile_game_arm64 import discover
from compile_game_regions import direct_successors, split_after_writes
from offline_elf import Elf32Arm
from translate import is_terminal


def reg(index):
    return f"r{index}"


def flag_nz(value):
    return (f"cpsr = (cpsr & ~0xc0000000u) | (({value} >> 31) << 31) "
            f"| (({value} == 0u) << 30);")


def flag_arith(left, right, subtract, dest=None):
    lines = [f"{{ uint32_t lhs = {left}, rhs = {right};",
             f"uint32_t value = lhs {'-' if subtract else '+'} rhs;"]
    if dest is not None:
        lines.append(f"{reg(dest)} = value;")
    carry = "lhs >= rhs" if subtract else "(uint32_t)(((uint64_t)lhs + rhs) >> 32)"
    overflow = "((lhs ^ rhs) & (lhs ^ value))" if subtract else "((~(lhs ^ rhs)) & (lhs ^ value))"
    lines.append("cpsr = (cpsr & ~0xf0000000u) | ((value >> 31) << 31) "
                 f"| ((value == 0u) << 30) | (({carry}) << 29) "
                 f"| ((({overflow}) >> 31) << 28); }}")
    return " ".join(lines)


def operation(op, row):
    kind = op[0]
    if kind == "cmp_imm":
        return flag_arith(reg(op[1]), f"{op[2]}u", True)
    if kind == "cmp_reg":
        return flag_arith(reg(op[1]), reg(op[2]), True)
    if kind == "adds_imm":
        return flag_arith(reg(op[2]), f"{op[3]}u", False, op[1])
    if kind == "lsls_imm":
        rd, rm, amount = op[1:]
        return (f"{{ uint32_t value = {reg(rm)}; {reg(rd)} = value << {amount}u; "
                f"uint32_t carry = {amount}u ? ((value >> (32u - {amount}u)) & 1u) : ((cpsr >> 29) & 1u); "
                f"cpsr = (cpsr & ~0xe0000000u) | (({reg(rd)} >> 31) << 31) "
                f"| (({reg(rd)} == 0u) << 30) | (carry << 29); }}")
    if kind == "movs_imm":
        return f"{reg(op[1])} = {op[2]}u; " + flag_nz(reg(op[1]))
    if kind == "mov_reg":
        return f"{reg(op[1])} = {reg(op[2])};"
    if kind == "movw":
        return f"{reg(op[1])} = {op[2]}u & 0xffffu;"
    if kind == "ldr_imm":
        rt, rn, imm = op[1:4]
        base = f"(bias + {((row['pc'] + 4) & ~3) if row['thumb'] else row['pc'] + 8}u)" if rn == 15 else reg(rn)
        if rt == 15:
            raise ValueError("scalar probe does not support PC load")
        return (f"{{ uint32_t addr = {base} + {imm}u; if (agr_aot_fault(addr)) "
                f"{{ result = AGR_AOT_FAULT; goto L_exit; }} "
                f"memcpy(&{reg(rt)}, mem + addr, 4); }}")
    if kind == "ldr_shifted":
        rt, rn, rm, shift = op[1:5]
        if rt == 15:
            raise ValueError("scalar probe does not support PC load")
        base = reg(rn) if rn != 15 else f"(bias + {(row['pc'] + 4) & ~3}u)"
        return (f"{{ uint32_t addr = {base} + ({reg(rm)} << {shift}u); "
                f"if (agr_aot_fault(addr)) {{ result = AGR_AOT_FAULT; goto L_exit; }} "
                f"memcpy(&{reg(rt)}, mem + addr, 4); }}")
    if kind == "str_shifted":
        rt, rn, rm, shift = op[1:5]
        base = reg(rn) if rn != 15 else f"(bias + {(row['pc'] + 4) & ~3}u)"
        value = reg(rt) if rt != 15 else f"(bias + {row['pc'] + 4}u)"
        return (f"{{ uint32_t addr = {base} + ({reg(rm)} << {shift}u); "
                f"if (agr_aot_fault(addr)) {{ result = AGR_AOT_FAULT; goto L_exit; }} "
                f"memcpy(mem + addr, &{value}, 4); }}")
    if kind == "stmdb_sp":
        mask = op[1]
        regs = [i for i in range(16) if mask & (1 << i)]
        lines = [f"{{ uint32_t addr = r13 - {len(regs) * 4}u;",
                 "if (agr_aot_fault(addr)) { result = AGR_AOT_FAULT; goto L_exit; }"]
        lines += [f"memcpy(mem + addr + {index * 4}u, &r{i}, 4);" for index, i in enumerate(regs)]
        lines += [f"r13 -= {len(regs) * 4}u; }}"]
        return " ".join(lines)
    if kind == "ldmia_sp":
        mask = op[1]
        regs = [i for i in range(16) if mask & (1 << i)]
        lines = ["{ uint32_t addr = r13;"]
        for index, i in enumerate(regs):
            lines += [f"if (agr_aot_fault(addr + {index * 4}u)) "
                      "{ result = AGR_AOT_FAULT; goto L_exit; }",
                      f"uint32_t loaded_{i}; memcpy(&loaded_{i}, mem + addr + {index * 4}u, 4);"]
        lines.append(f"r13 += {len(regs) * 4}u;")
        lines += [f"r{i} = loaded_{i};" for i in regs]
        if 15 in regs:
            lines += ["cpsr = (r15 & 1u) ? (cpsr | 0x20u) : (cpsr & ~0x20u);",
                      "r15 &= ~1u;"]
        lines.append("}")
        return " ".join(lines)
    if kind == "dmb":
        return "atomic_thread_fence(memory_order_seq_cst);"
    if kind == "b":
        return f"r15 = bias + {op[1]}u;"
    if kind == "b_cond":
        return f"r15 = agr_scalar_condition(cpsr, {op[1]}u) ? bias + {op[2]}u : bias + {op[3]}u;"
    if kind == "cbz":
        rn, target, fall, nonzero = op[1:]
        test = reg(rn) if nonzero else f"!{reg(rn)}"
        return f"r15 = {test} ? bias + {target}u : bias + {fall}u;"
    if kind == "blx_reg":
        rm, nxt, pc = op[1:]
        target = reg(rm) if rm != 15 else f"(bias + {pc + (4 if row['thumb'] else 8)}u)"
        return (f"{{ uint32_t target = {target}; r14 = (bias + {nxt}u) | "
                f"{1 if row['thumb'] else 0}u; cpsr = (target & 1u) ? "
                "(cpsr | 0x20u) : (cpsr & ~0x20u); r15 = target & ~1u; }")
    raise ValueError(f"unsupported scalar operation: {op}")


CONDITION = """static inline int agr_scalar_condition(uint32_t cpsr, uint32_t condition) {
    uint32_t n = (cpsr >> 31) & 1u, z = (cpsr >> 30) & 1u;
    uint32_t c = (cpsr >> 29) & 1u, v = (cpsr >> 28) & 1u;
    switch (condition & 15u) {
        case 0: return z; case 1: return !z; case 2: return c; case 3: return !c;
        case 4: return n; case 5: return !n; case 6: return v; case 7: return !v;
        case 8: return c && !z; case 9: return !c || z;
        case 10: return n == v; case 11: return n != v;
        case 12: return !z && n == v; case 13: return z || n != v;
        case 14: return 1; default: return 0;
    }
}
"""


def emit(blocks, entry):
    starts = {pc for pc, _ in blocks}
    if entry not in starts:
        raise ValueError("entry missing from ELF-derived CFG")
    lines = ['#include "agr_aot.h"', '', CONDITION,
             'int agr_attribution_scalar(AgrAotRegs *outer) {',
             '    uint8_t *mem = outer->mem;', '    uint32_t bias = outer->bias;',
             '    uint32_t cpsr = *outer->cpsr;',
             '    int result = AGR_AOT_BOUNDARY;']
    lines += [f'    uint32_t r{i} = outer->r[{i}];' for i in range(16)]
    lines.append(f'    goto L_{entry:08x};')
    for pc, body in blocks:
        lines.append(f'L_{pc:08x}:')
        for row, op in body:
            lines.append('    ' + operation(op, row))
            if is_terminal(op):
                break
        if not is_terminal(body[-1][1]):
            end = body[-1][0]['pc'] + body[-1][0]['len']
            lines.append(f'    r15 = bias + {end}u;')
        for target in direct_successors(body):
            if target in starts:
                lines.append(f'    if (r15 == bias + {target}u) goto L_{target:08x};')
        lines.append('    goto L_exit;')
    lines.append('L_exit:')
    lines += [f'    outer->r[{i}] = r{i};' for i in range(16)]
    lines += ['    *outer->cpsr = cpsr;', '    return result;', '}', '']
    return '\n'.join(lines)


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('--elf', required=True)
    parser.add_argument('--selection', required=True)
    parser.add_argument('--label', choices=('gloomy', 'kungfoo'), required=True)
    parser.add_argument('--out', required=True)
    parser.add_argument('--manifest', required=True)
    args = parser.parse_args()
    started = time.perf_counter()
    image = Elf32Arm(args.elf)
    spec = next(s for s in json.loads(Path(args.selection).read_text())['segments']
                if s['label'] == args.label)
    if image.sha256 != spec['elf_sha256']:
        raise ValueError('ELF differs from real trace selection')
    observed = set(spec['guest_pc_sequence'])
    blocks = split_after_writes(discover(image, allowed=None)[0])
    selected = [(pc, body) for pc, body in blocks
                if any(row['pc'] in observed for row, _ in body)]
    covered = {row['pc'] for _, body in selected for row, _ in body}
    if not observed <= covered:
        raise ValueError('real segment contains an uncompiled PC')
    entry = spec['guest_pc_first'] - spec['load_bias']
    source = emit(selected, entry)
    Path(args.out).write_text(source, newline='\n')
    manifest = {
        'schema': 'agr.aot-attribution-scalar-v1', 'label': args.label,
        'elf_sha256': image.sha256, 'selected_trace_sha256': spec['trace_sha256'],
        'entry_pc': spec['guest_pc_first'],
        'static_block_count': len(selected),
        'static_decoded_instructions': sum(len(body) for _, body in selected),
        'operation_kinds': sorted({op[0] for _, body in selected for _, op in body}),
        'guest_register_representation': '16 local scalar values',
        'runtime_dispatch': False, 'guard_count': 0,
        'generated_c_bytes': len(source.encode()),
        'generated_c_sha256': hashlib.sha256(source.encode()).hexdigest(),
        'offline_preparation_seconds': time.perf_counter() - started,
    }
    Path(args.manifest).write_text(json.dumps(manifest, indent=2) + '\n')
    print(json.dumps(manifest))


if __name__ == '__main__':
    main()
