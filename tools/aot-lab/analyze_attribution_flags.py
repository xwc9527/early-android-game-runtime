#!/usr/bin/env python3
"""Count live ARM NZCV definitions on an archived real execution segment."""
import argparse
import json
from pathlib import Path

from compile_game_arm64 import discover
from offline_elf import Elf32Arm

ALL = frozenset("NZCV")
WRITES = {
    "adds_imm": ALL, "adds_reg": ALL, "subs_imm": ALL,
    "subs_reg": ALL, "cmp_imm": ALL, "cmp_reg": ALL,
    "lsls_imm": frozenset("NZC"), "lsls_reg": frozenset("NZC"),
    "movs_imm": frozenset("NZ"),
}
CONDITION_READS = {
    0: "Z", 1: "Z", 2: "C", 3: "C", 4: "N", 5: "N",
    6: "V", 7: "V", 8: "CZ", 9: "CZ", 10: "NV", 11: "NV",
    12: "NZV", 13: "NZV", 14: "",
}


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--elf", required=True)
    parser.add_argument("--selection", required=True)
    parser.add_argument("--label", required=True)
    parser.add_argument("--out", required=True)
    args = parser.parse_args()
    image = Elf32Arm(args.elf)
    spec = next(x for x in json.loads(Path(args.selection).read_text())["segments"]
                if x["label"] == args.label)
    if image.sha256 != spec["elf_sha256"]:
        raise ValueError("ELF/trace identity mismatch")
    decoded = {row["pc"]: op for _, body in discover(image, allowed=None)[0]
               for row, op in body}
    events = []
    for pc in spec["guest_pc_sequence"]:
        op = decoded.get(pc)
        if op is None:
            raise ValueError(f"missing ELF instruction {pc:#x}")
        events.append((pc, op))
    live = set(ALL)  # final CPSR is part of the architectural oracle
    producers = []
    consumers = []
    for pc, op in reversed(events):
        kind = op[0]
        if kind in WRITES:
            writes = WRITES[kind]
            used = writes & live
            producers.append({"guest_pc": pc + spec["load_bias"], "kind": kind,
                              "writes": "".join(sorted(writes)),
                              "live_writes": "".join(sorted(used))})
            live -= writes
        if kind == "b_cond":
            reads = set(CONDITION_READS[op[1]])
            live |= reads
            consumers.append({"guest_pc": pc + spec["load_bias"],
                              "condition": op[1], "reads": "".join(sorted(reads))})
    producers.reverse()
    consumers.reverse()
    result = {
        "schema": "agr.aot-attribution-nzcv-liveness.v1",
        "label": args.label, "elf_sha256": image.sha256,
        "trace_sha256": spec["trace_sha256"],
        "guest_instructions": len(events),
        "flag_producer_events": len(producers),
        "entirely_dead_flag_producer_events": sum(not p["live_writes"] for p in producers),
        "live_flag_producer_events": sum(bool(p["live_writes"]) for p in producers),
        "condition_consumer_events": len(consumers),
        "initial_cpsr_bits_live": "".join(sorted(live)),
        "producers": producers,
        "consumers": consumers,
    }
    Path(args.out).write_text(json.dumps(result, indent=2) + "\n", newline="\n")
    print({key: value for key, value in result.items()
           if key not in {"producers", "consumers"}})


if __name__ == "__main__":
    main()
