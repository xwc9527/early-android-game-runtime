#!/usr/bin/env python3
"""Classify observed AOT misses against trace-independent ELF discovery."""

from collections import Counter
import json
from pathlib import Path
import sys

from capstone import Cs, CS_ARCH_ARM, CS_MODE_ARM, CS_MODE_THUMB

from offline_elf import Elf32Arm
from offline_scan import scan
from translate import decode


def main():
    evidence = Path(sys.argv[1])
    manifest = json.loads((evidence / "translation-manifest.json").read_text())
    image = Elf32Arm(evidence / "input-armv7.so")
    if image.sha256 != manifest["elf_sha256"]:
        raise ValueError("input ELF identity differs from generated artifact")
    rows, _, _, _ = scan(image, manifest["entry_policy"])
    sweep, _, _, _ = scan(image, "all-exidx-sweep")
    decoders = {False: Cs(CS_ARCH_ARM, CS_MODE_ARM), True: Cs(CS_ARCH_ARM, CS_MODE_THUMB)}
    counts = Counter()
    unique = {}
    total = 0
    bias = int(manifest["load_bias"])
    if manifest.get("relocatable"):
        # The formal linker result is an execution input, never a translation input.
        bias = int(sys.argv[2], 0)
    for line in (evidence / "fast-audit-fallbacks.txt").read_text().splitlines():
        reason, pc_hex, cpsr_hex = line.split()
        if reason != "lookup_miss":
            continue
        pc = int(pc_hex, 16) - bias
        thumb = bool(int(cpsr_hex, 16) & 0x20)
        row = rows.get(pc)
        if row is None:
            swept = sweep.get(pc)
            if swept is None:
                category = "indirect_mode_target_absent_from_sweep" if image.code_at(pc, 4) else "outside_elf_code"
            elif bool(swept["thumb"]) != thumb:
                category = "indirect_mode_target_wrong_sweep_mode"
            else:
                try:
                    decode(pc, swept["insn"], swept["len"], swept["thumb"])
                except ValueError:
                    category = "static_discovery_gap_sweep_unsupported"
                else:
                    category = "static_discovery_gap_sweep_decodes"
        elif bool(row["thumb"]) != thumb:
            category = "static_wrong_mode"
        else:
            try:
                decode(pc, row["insn"], row["len"], row["thumb"])
            except ValueError:
                instruction = next(decoders[thumb].disasm(image.code_at(pc, 4), pc, count=1))
                category = "unsupported_isa:" + instruction.mnemonic
            else:
                category = "decoded_but_no_fast_entry"
        counts[category] += 1
        unique.setdefault(category, set()).add((pc, thumb))
        total += 1
    result = {
        "schema": "agr.offline-aot-fallback-classification.v1",
        "input_elf_sha256": image.sha256,
        "entry_policy": manifest["entry_policy"],
        "runtime_load_bias": bias,
        "lookup_miss_events": total,
        "dynamic_counts": dict(sorted(counts.items())),
        "unique_pc_mode_counts": {key: len(value) for key, value in sorted(unique.items())},
    }
    expected = json.loads((evidence / "differential.json").read_text())["fallback_reason_counts"]["lookup_miss"]
    if total != expected:
        raise ValueError((total, expected))
    (evidence / "fallback-classification.json").write_text(json.dumps(result, indent=2) + "\n")
    print(json.dumps(result, indent=2))


if __name__ == "__main__":
    main()
