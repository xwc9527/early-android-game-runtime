#!/usr/bin/env python3
"""Select real compiled segments for CPU attribution from archived traces.

This is a test-fixture selector. It does not feed execution traces to the
offline translator or change the guest runtime's translation policy.
"""

import argparse
from collections import Counter, defaultdict
import hashlib
import json
from pathlib import Path

from compile_game_arm64 import discover
from compile_game_regions import split_after_writes
from offline_elf import Elf32Arm


MEMORY = {"ldr_imm", "ldr_shifted", "str_shifted", "stmdb_sp", "ldmia_sp"}
BRANCH = {"b", "b_cond", "cbz", "bl_imm", "blx_imm", "blx_reg", "bx_reg", "ldmia_sp"}
FLAGS = {"adds_imm", "adds_reg", "subs_imm", "subs_reg", "rsbs_imm",
         "cmp_imm", "cmp_reg", "lsls_imm", "lsls_reg", "movs_imm"}


def touched_pages(row, op):
    pc, _, _, thumb = row[:4]
    regs = row[5:21]
    kind = op[0]
    address = None
    size = 4
    if kind == "ldr_imm":
        base = regs[op[2]] if op[2] != 15 else ((pc + 4) & ~3 if thumb else pc + 8)
        address = base + op[3]
    elif kind in {"ldr_shifted", "str_shifted"}:
        base = regs[op[2]] if op[2] != 15 else (pc + 4) & ~3
        address = base + (regs[op[3]] << op[4])
    elif kind == "stmdb_sp":
        size = op[1].bit_count() * 4
        address = regs[13] - size
    elif kind == "ldmia_sp":
        size = op[1].bit_count() * 4
        address = regs[13]
    elif kind in MEMORY:
        raise ValueError(f"memory address model missing for {kind}")
    if address is None:
        return set()
    if not 0 <= address < 2**32 or not 0 < size <= 2**32 - address:
        raise ValueError(f"invalid observed memory access {address:#x}, {size}")
    return set(range(address & ~4095, (address + size - 1 & ~4095) + 1, 4096))


def select(label, elf_path, trace_path, warm_iterations):
    image = Elf32Arm(elf_path)
    blocks = split_after_writes(discover(image, allowed=None)[0])
    by_pc = {}
    for index, (start, body) in enumerate(blocks):
        for row, op in body:
            by_pc[row["pc"]] = (index // 64, start, op)
    trace = Path(trace_path).read_bytes()
    rows = [tuple(map(int, line.split())) for line in trace.splitlines()]
    bias = 65536
    region_counts = Counter(by_pc[row[0] - bias][0]
                            for row in rows if row[0] - bias in by_pc)
    hottest = region_counts.most_common(1)[0][0]
    segments = []
    index = 0
    while index < len(rows):
        entry = by_pc.get(rows[index][0] - bias)
        region = entry[0] if entry else None
        end = index + 1
        while end < len(rows):
            other = by_pc.get(rows[end][0] - bias)
            if (other[0] if other else None) != region:
                break
            end += 1
        if region == hottest:
            segments.append((index, end, tuple(row[0] - bias for row in rows[index:end])))
        index = end
    repetitions = Counter(segment[2] for segment in segments)
    if warm_iterations:
        selected = max(segments, key=lambda item: (len(item[2]), -item[0]))
    else:
        selected = max(segments, key=lambda item:
                       (len(item[2]) * repetitions[item[2]], len(item[2]), -item[0]))
    begin, end, sequence = selected
    if end >= len(rows):
        raise ValueError("selected segment has no post-state trace row")
    chosen = rows[begin:end]
    decoded = [by_pc[row[0] - bias] for row in chosen]
    pages = set()
    for row, (_, _, op) in zip(chosen, decoded):
        pages.update(touched_pages(row, op))
        pages.add(row[0] & ~4095)
    kinds = Counter(op[0] for _, _, op in decoded)
    return {
        "schema": "agr.aot-performance-real-segment.v1",
        "label": label,
        "selection": ("hottest region by compiled trace instructions; longest segment"
                      if warm_iterations else
                      "hottest region by compiled trace instructions; maximum length times identical-path count"),
        "elf_sha256": image.sha256,
        "trace_sha256": hashlib.sha256(trace).hexdigest(),
        "load_bias": bias,
        "region_id": hottest,
        "region_dynamic_compiled_instructions": region_counts[hottest],
        "trace_first_seq_zero_based": begin,
        "trace_after_seq_zero_based": end,
        "guest_pc_first": chosen[0][0],
        "guest_pc_last": chosen[-1][0],
        "guest_pc_after": rows[end][0],
        "thumb_mode": sorted({row[3] for row in chosen}),
        "guest_instructions_per_segment": len(chosen),
        "same_pc_sequence_occurrences_in_trace": repetitions[sequence],
        "warm_iterations": warm_iterations,
        "inferred_warm_executions": warm_iterations if warm_iterations else None,
        "distinct_compiled_blocks": len({start for _, start, _ in decoded}),
        "branch_instructions": sum(kinds[kind] for kind in BRANCH),
        "guest_memory_instructions": sum(kinds[kind] for kind in MEMORY),
        "flag_producing_instructions": sum(kinds[kind] for kind in FLAGS),
        "operation_counts": dict(sorted(kinds.items())),
        "runtime_boundary": "none inside; segment exits to next trace PC",
        "entry_registers": list(chosen[0][5:21]),
        "entry_cpsr": chosen[0][4],
        "post_registers": list(rows[end][5:21]),
        "post_cpsr": rows[end][4],
        "snapshot_guest_pages": sorted(pages),
        "guest_pc_sequence": list(sequence),
    }


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--kungfoo-elf", required=True)
    parser.add_argument("--kungfoo-trace", required=True)
    parser.add_argument("--gloomy-elf", required=True)
    parser.add_argument("--gloomy-trace", required=True)
    parser.add_argument("--gloomy-warm-iterations", type=int, required=True)
    parser.add_argument("--out", required=True)
    args = parser.parse_args()
    result = {"segments": [
        select("kungfoo", args.kungfoo_elf, args.kungfoo_trace, 0),
        select("gloomy", args.gloomy_elf, args.gloomy_trace, args.gloomy_warm_iterations),
    ]}
    Path(args.out).parent.mkdir(parents=True, exist_ok=True)
    Path(args.out).write_text(json.dumps(result, indent=2) + "\n")
    for segment in result["segments"]:
        print(segment["label"], segment["region_id"],
              segment["guest_instructions_per_segment"],
              segment["same_pc_sequence_occurrences_in_trace"],
              len(segment["snapshot_guest_pages"]))


if __name__ == "__main__":
    main()
