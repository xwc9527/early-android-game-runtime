#!/usr/bin/env python3
"""AGR-owned register-resident offline regions over the existing guest ABI.

The C output is a portable machine-code substrate for this architecture test;
the compiler's units are decoded IR blocks and direct intra-region edges.
"""

import argparse
import hashlib
import json
from pathlib import Path
import time

from compile_game_arm64 import discover
from offline_elf import Elf32Arm
from translate import emit_op, is_terminal


REGION_LIMIT = 64
WRITE_KINDS = {
    "stmdb_sp", "stm", "str_imm", "str_reg", "str_shifted", "str_indexed",
    "str_wb", "strb_imm", "strh_imm",
}


def split_after_writes(blocks):
    """A guest store cannot leave later instructions under a stale code guard."""
    result = []
    for _, body in blocks:
        segment = []
        for row, op in body:
            segment.append((row, op))
            if op[0] in WRITE_KINDS:
                result.append((segment[0][0]["pc"], segment))
                segment = []
        if segment:
            result.append((segment[0][0]["pc"], segment))
    unique = {}
    for pc, body in result:
        previous = unique.setdefault(pc, body)
        if previous != body:
            raise ValueError(f"ambiguous split block at {pc:#x}")
    return sorted(unique.items())


def direct_successors(body):
    row, op = body[-1]
    kind = op[0]
    if not is_terminal(op):
        return (row["pc"] + row["len"],)
    if kind == "b":
        return (op[1],)
    if kind == "cbz":
        return (op[2], op[3])
    if kind == "b_cond":
        return (op[2], op[3])
    if kind in {"bl_imm", "blx_imm"}:
        return (op[1],)
    return ()


def translated_op(op, thumb, label):
    source = emit_op(op, thumb, relocatable=True)
    early_boundary = "return AGR_AOT_BOUNDARY;" in source
    source = source.replace("return AGR_AOT_BOUNDARY;",
                            f"{{ instructions++; goto L_after_{label}; }}")
    source = source.replace("return AGR_AOT_FAULT;",
                            "{ result = AGR_AOT_FAULT; goto L_exit; }")
    source = source.replace("return rc;",
                            f"{{ if (rc == AGR_AOT_BOUNDARY) {{ instructions++; goto L_after_{label}; }} "
                            "result = rc; goto L_exit; }")
    if "return " in source:
        raise ValueError(f"unhandled operation exit: {source}")
    return source, early_boundary


def emit_region(number, blocks, image):
    starts = {pc for pc, _ in blocks}
    name = f"agr_region_{number:05d}"
    lines = [f"static int {name}(AgrAotRegs *outer) {{",
             "    if (!outer->source_elf) return AGR_AOT_MISS;",
             "    uint32_t regs[16];",
             "    memcpy(regs, outer->r, sizeof(regs));",
             "    uint32_t cpsr = *outer->cpsr;",
             "    AgrAotRegs local = {regs, &cpsr, outer->mem, outer->bias, 0, 0, 0, outer->source_elf, 0};",
             "    AgrAotRegs *s = &local;",
             "    uint32_t blocks_done = 0, instructions = 0;",
             "    int rc = 0, result = AGR_AOT_BOUNDARY;",
             "    (void)rc;",
             "    switch (outer->region_entry) {"]
    lines.extend(f"    case {index}u: goto L_{pc:08x};" for index, (pc, _) in enumerate(blocks))
    lines += ["    default: result = AGR_AOT_MISS; goto L_exit;", "    }"]
    group_guard_count = 0
    individual_guard_count = 0
    for pc, body in blocks:
        label = f"{pc:08x}"
        row0 = body[0][0]
        lines += [f"L_{label}:",
                  "    if (blocks_done >= outer->region_budget) goto L_exit;",
                  "    if (cpsr & 0x0600fc00u) goto L_exit;",
                  f"    if ((cpsr & 0x20u) != {'0x20u' if row0['thumb'] else '0u'}) "
                  "{ result = AGR_AOT_MODE_MISS; goto L_exit; }"]
        end = body[-1][0]["pc"] + body[-1][0]["len"]
        raw = image.code_at(pc, end - pc)
        if raw is None:
            raise ValueError(f"block outside executable ELF section: {pc:#x}")
        section = next(section for section in image.executable
                       if section.address <= pc and end <= section.address + section.size)
        offset = section.offset + pc - section.address
        lines.append(
            f"    if (memcmp(s->mem + s->bias + {pc}u, s->source_elf + {offset}u, {len(raw)}u)) "
            "{ result = AGR_AOT_MISS; goto L_exit; }")
        group_guard_count += 1
        for row, op in body:
            code, early_boundary = translated_op(op, row["thumb"], label)
            lines.append("    " + code)
            if not early_boundary:
                lines.append("    instructions++;")
            if is_terminal(op):
                break
        if not is_terminal(body[-1][1]):
            lines.append(f"    regs[15] = s->bias + {end}u;")
        lines += [f"L_after_{label}:", "    blocks_done++;"]
        successors = [target for target in direct_successors(body) if target in starts]
        if len(successors) == 1:
            target = successors[0]
            lines.append(f"    if (regs[15] == s->bias + {target}u) goto L_{target:08x};")
        elif len(successors) == 2:
            for target in successors:
                lines.append(f"    if (regs[15] == s->bias + {target}u) goto L_{target:08x};")
        lines.append("    goto L_exit;")
    lines += ["L_exit:",
              "    memcpy(outer->r, regs, sizeof(regs));",
              "    *outer->cpsr = cpsr;",
              "    outer->region_blocks = blocks_done;",
              "    outer->region_instructions = instructions;",
              "    return result;", "}", ""]
    return name, "\n".join(lines), group_guard_count, individual_guard_count


def emit_table(entries, image):
    pieces = ["const AgrAotEntry agr_aot_debug_blocks[] = {{0, 0, 0}};",
              "const uint32_t agr_aot_debug_block_count = 0u;",
              "const AgrAotEntry agr_aot_fast_blocks[] = {"]
    pieces += [f"    {{{pc}u, {name}, {length}u, {index % REGION_LIMIT}u}},"
               for index, (pc, name, length) in enumerate(entries)]
    pieces += ["};", f"const uint32_t agr_aot_fast_block_count = {len(entries)}u;",
               "const AgrAotEntry agr_aot_fast_hash[] = {{0, 0, 0}};",
               "const uint32_t agr_aot_fast_hash_mask = 0u;"]
    first = entries[0][0]
    slots = (entries[-1][0] - first) // 2 + 1
    pieces += [f"const uint32_t agr_aot_fast_direct_base = {first}u;",
               f"const uint32_t agr_aot_fast_direct_count = {slots}u;",
               f"const uint32_t agr_aot_fast_direct[{slots}] = {{"]
    pieces += [f"    [{(pc - first) // 2}] = {index + 1}u," for index, (pc, _, _) in enumerate(entries)]
    pieces += ["};", "const uint32_t agr_aot_fast_relocatable = 1u;"]
    fnv = 14695981039346656037
    for byte in image.data:
        fnv = ((fnv ^ byte) * 1099511628211) & 0xffffffffffffffff
    pieces += [f"const uint64_t agr_aot_input_elf_fnv64 = {fnv}ull;",
               f"const uint32_t agr_aot_input_elf_bytes = {len(image.data)}u;", ""]
    return "\n".join(pieces), slots


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--elf", required=True)
    parser.add_argument("--out", required=True)
    parser.add_argument("--manifest", required=True)
    args = parser.parse_args()
    started = time.perf_counter()
    image = Elf32Arm(args.elf)
    blocks, excluded, discovery = discover(image, allowed=None)
    blocks = split_after_writes(blocks)
    groups = [blocks[i:i + REGION_LIMIT] for i in range(0, len(blocks), REGION_LIMIT)]
    sources = ['#include "agr_aot.h"', ""]
    entries = []
    group_guards = individual_guards = direct_edges = 0
    for number, group in enumerate(groups):
        name, source, guarded, individual = emit_region(number, group, image)
        sources.append(source)
        group_guards += guarded
        individual_guards += individual
        starts = {pc for pc, _ in group}
        direct_edges += sum(bool(set(direct_successors(body)) & starts) for _, body in group)
        entries.extend((pc, name, len(body)) for pc, body in group)
    table, direct_slots = emit_table(entries, image)
    source = "\n".join(sources) + table
    Path(args.out).write_text(source, encoding="utf-8", newline="\n")
    result = {
        "schema": "agr.game-compiler-region-prototype.v1",
        "input_elf_sha256": image.sha256, "elf_sha256": image.sha256,
        "input_elf_bytes": len(image.data),
        "executable_bytes": sum(section.size for section in image.executable),
        "entry_policy": "all-exidx", "execution_trace_input": False,
        "relocatable": True, "load_bias": 0,
        "load_bias_source": "runtime formal linker result", "runtime_load_bias": True,
        "compiled_region_count": len(groups), "compiled_block_count": len(entries),
        "fast_block_count": len(entries), "debug_entry_count": 0,
        "static_compiled_instructions": sum(len(body) for _, body in blocks),
        "region_local_guest_state": True,
        "host_register_residency_proven": False,
        "direct_intra_region_edge_candidates": direct_edges,
        "block_group_guard_count": group_guards,
        "individual_instruction_guard_count": individual_guards,
        "direct_lookup_slots": direct_slots,
        "supported_op_kinds": sorted({op[0] for _, body in blocks for _, op in body}),
        "excluded_reasons": dict(sorted(excluded.items())),
        "static_discovery_reasons": dict(sorted(discovery.items())),
        "generated_c_sha256": hashlib.sha256(source.encode()).hexdigest(),
        "generated_c_bytes": len(source.encode()),
        "offline_preparation_seconds": time.perf_counter() - started,
    }
    Path(args.manifest).write_text(json.dumps(result, indent=2) + "\n")
    print(json.dumps(result, indent=2))


if __name__ == "__main__":
    main()
