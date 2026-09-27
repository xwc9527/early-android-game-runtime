#!/usr/bin/env python3
"""Measure reusable translator capability against original guest traces."""

import argparse
from collections import Counter
import hashlib
import json
from pathlib import Path

from capstone import CS_ARCH_ARM, CS_MODE_ARM, CS_MODE_THUMB, Cs

from translate import decode, is_svc, load_trace


def source_bytes(row):
    raw = row["insn"]
    if row["len"] == 2:
        return raw.to_bytes(2, "little")
    if row["thumb"]:
        return (raw >> 16).to_bytes(2, "little") + (raw & 0xffff).to_bytes(2, "little")
    return raw.to_bytes(4, "little")


def describe(path):
    rows = load_trace(path)
    unique = {(r["pc"], r["thumb"]): r for r in rows}
    arm, thumb = Cs(CS_ARCH_ARM, CS_MODE_ARM), Cs(CS_ARCH_ARM, CS_MODE_THUMB)
    supported_dynamic = Counter()
    unsupported_dynamic = Counter()
    supported_static = Counter()
    unsupported_static = Counter()
    first_unsupported = None
    def classify(row):
        nonlocal first_unsupported
        if is_svc(row):
            return "boundary", "svc"
        try:
            return "supported", decode(row["pc"], row["insn"], row["len"], row["thumb"])[0]
        except ValueError:
            decoder = thumb if row["thumb"] else arm
            insn = next(decoder.disasm(source_bytes(row), row["pc"], count=1), None)
            mnemonic = insn.mnemonic if insn else "UNDECODED"
            if first_unsupported is None:
                first_unsupported = {"pc": f"0x{row['pc']:08x}", "thumb": row["thumb"],
                                     "length": row["len"], "instruction": f"0x{row['insn']:x}",
                                     "mnemonic": mnemonic, "operands": insn.op_str if insn else ""}
            return "unsupported", mnemonic
    boundaries = 0
    for row in rows:
        status, kind = classify(row)
        if status == "supported": supported_dynamic[kind] += 1
        elif status == "unsupported": unsupported_dynamic[kind] += 1
        else: boundaries += 1
    for row in unique.values():
        status, kind = classify(row)
        if status == "supported": supported_static[kind] += 1
        elif status == "unsupported": unsupported_static[kind] += 1
    return {"input_sha256": hashlib.sha256(path.read_bytes()).hexdigest(),
            "instruction_events": len(rows), "unique_pc_mode": len(unique),
            "thumb_events": sum(bool(r["thumb"]) for r in rows),
            "arm_events": sum(not r["thumb"] for r in rows),
            "svc_boundary_events": boundaries,
            "supported_dynamic": dict(supported_dynamic),
            "unsupported_dynamic": dict(unsupported_dynamic),
            "supported_unique_pc": dict(supported_static),
            "unsupported_unique_pc": dict(unsupported_static),
            "first_unsupported": first_unsupported}


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--gloomy", type=Path, required=True)
    parser.add_argument("--kungfoo", type=Path, required=True)
    parser.add_argument("--out", type=Path, required=True)
    args = parser.parse_args()
    gloomy, kungfoo = describe(args.gloomy), describe(args.kungfoo)
    prior = set(gloomy["supported_unique_pc"])
    current = set(kungfoo["supported_unique_pc"])
    result = {"schema_version": 1, "basis": "actual interpreter instruction traces",
              "meaning": "Current translator decoder capability; not full execution or AOT correctness",
              "gloomy": gloomy, "kungfoo": kungfoo,
              "reuse": {"gloomy_supported_op_kinds": sorted(prior),
                        "kungfoo_supported_op_kinds": sorted(current),
                        "shared_supported_op_kinds": sorted(prior & current),
                        "new_supported_op_kinds": sorted(current - prior),
                        "kungfoo_dynamic_events_in_prior_supported_kinds":
                            sum(n for kind, n in kungfoo["supported_dynamic"].items() if kind in prior),
                        "kungfoo_unique_pcs_in_prior_supported_kinds":
                            sum(n for kind, n in kungfoo["supported_unique_pc"].items() if kind in prior)}}
    args.out.write_text(json.dumps(result, indent=2) + "\n", encoding="utf-8", newline="\n")


if __name__ == "__main__":
    main()
