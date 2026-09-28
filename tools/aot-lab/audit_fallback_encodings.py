#!/usr/bin/env python3
"""Audit untranslated instructions on the exact fast-block replay path."""

from collections import Counter
import json
from pathlib import Path
import sys

from capstone import Cs, CS_ARCH_ARM, CS_MODE_ARM, CS_MODE_THUMB
from translate import decode, is_svc


def main() -> None:
    evidence = Path(sys.argv[1])
    rows = [[int(value) for value in line.split()]
            for line in (evidence / "interpreter-trace.txt").read_text().splitlines()]
    manifest = json.loads((evidence / "translation-manifest.json").read_text())
    lengths = {item["pc"]: item["instructions"] for item in manifest["fast_blocks"]}
    decoders = {0: Cs(CS_ARCH_ARM, CS_MODE_ARM), 1: Cs(CS_ARCH_ARM, CS_MODE_THUMB)}
    encodings = Counter()
    unique_pcs = set()
    position = 0
    while position < len(rows):
        pc, instruction, length, thumb, cpsr = rows[position][:5]
        row = {"pc": pc, "insn": instruction, "len": length, "thumb": thumb, "cpsr": cpsr}
        if is_svc(row) or cpsr & 0x0600fc00:
            position += 1
            continue
        block_length = lengths.get(pc, 0)
        if block_length:
            position += block_length
            continue
        try:
            decode(pc, instruction, length, thumb)
        except ValueError:
            if thumb and length == 4:
                machine_bytes = ((instruction >> 16).to_bytes(2, "little") +
                                 (instruction & 0xffff).to_bytes(2, "little"))
            else:
                machine_bytes = instruction.to_bytes(length, "little")
            decoded = list(decoders[thumb].disasm(machine_bytes, pc))
            mnemonic = decoded[0].mnemonic if len(decoded) == 1 else "undecoded"
            encodings[(f"0x{instruction:08x}", length, thumb, mnemonic)] += 1
            unique_pcs.add((pc, thumb))
        position += 1
    result = {
        "input_trace_sha256": manifest["input_trace_sha256"],
        "dynamic_unsupported": sum(encodings.values()),
        "unique_pc_mode": len(unique_pcs),
        "mnemonic_counts": dict(sorted(Counter({
            mnemonic: sum(count for (_, _, _, name), count in encodings.items()
                          if name == mnemonic)
            for _, _, _, mnemonic in encodings
        }).items())),
        "encoding_counts": [
            {"instruction": instruction, "length": length, "thumb": thumb,
             "mnemonic": mnemonic, "dynamic_count": count}
            for (instruction, length, thumb, mnemonic), count in sorted(encodings.items())
        ],
    }
    (evidence / "fallback-encoding-audit.json").write_text(
        json.dumps(result, indent=2) + "\n", encoding="utf-8", newline="\n")
    print(json.dumps(result, indent=2))


if __name__ == "__main__":
    main()
