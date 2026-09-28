#!/usr/bin/env python3
"""Emit a guardless real-region probe from public ELF-derived ARM operations.

The archived trace selects the comparison region and first entry; every emitted
operation and CFG successor still comes from the raw ARMv7 ELF decoder.
This test-only artifact is not a game compiler output or replacement route.
"""

import argparse
import hashlib
import json
from pathlib import Path
import time

from compile_game_arm64 import discover
from compile_game_regions import emit_region, split_after_writes
from offline_elf import Elf32Arm


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--elf", required=True)
    parser.add_argument("--selection", required=True)
    parser.add_argument("--label", choices=("gloomy", "kungfoo"), required=True)
    parser.add_argument("--out", required=True)
    parser.add_argument("--manifest", required=True)
    parser.add_argument("--guard", action="store_true")
    parser.add_argument("--account", action="store_true")
    args = parser.parse_args()
    started = time.perf_counter()
    image = Elf32Arm(args.elf)
    spec = next(x for x in json.loads(Path(args.selection).read_text())["segments"]
                if x["label"] == args.label)
    if image.sha256 != spec["elf_sha256"]:
        raise ValueError("ELF differs from selected real trace")
    sequence = spec["guest_pc_sequence"]
    observed = set(sequence)
    all_blocks = split_after_writes(discover(image, allowed=None)[0])
    selected = [(pc, body) for pc, body in all_blocks
                if any(row["pc"] in observed for row, _ in body)]
    coverage = {row["pc"] for _, body in selected for row, _ in body}
    if not observed <= coverage:
        raise ValueError("selected real execution has an uncompiled guest PC")
    entry = spec["guest_pc_first"] - spec["load_bias"]
    name, body, guards, _ = emit_region(0, selected, image, guard=args.guard,
                                        account=args.account, direct_entry=entry)
    if guards != (len(selected) if args.guard else 0):
        raise AssertionError("selected region guard count mismatch")
    source = "#include \"agr_aot.h\"\n\n" + body + (
        f"int agr_attribution_payload(AgrAotRegs *state) {{ return {name}(state); }}\n")
    Path(args.out).write_text(source, newline="\n")
    manifest = {
        "schema": "agr.aot-attribution-isolated-region.v1",
        "label": args.label,
        "elf_sha256": image.sha256,
        "selected_trace_sha256": spec["trace_sha256"],
        "selected_entry_pc": spec["guest_pc_first"],
        "selected_dynamic_instructions": len(sequence),
        "static_block_count": len(selected),
        "static_decoded_instructions": sum(len(body) for _, body in selected),
        "operation_kinds": sorted({op[0] for _, body in selected for _, op in body}),
        "guard_count": guards,
        "global_dispatch": False,
        "region_entry_search": False,
        "per_block_bookkeeping": args.account,
        "region_local_guest_state": True,
        "host_register_residency_proven": False,
        "generated_c_bytes": len(source.encode()),
        "generated_c_sha256": hashlib.sha256(source.encode()).hexdigest(),
        "offline_preparation_seconds": time.perf_counter() - started,
    }
    Path(args.manifest).write_text(json.dumps(manifest, indent=2) + "\n")
    print(json.dumps(manifest))


if __name__ == "__main__":
    main()
