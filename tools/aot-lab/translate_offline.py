#!/usr/bin/env python3
"""Prepare a signed AOT artifact from ELF metadata, without a guest trace."""

import argparse
import hashlib
import json
from pathlib import Path
import time

from offline_elf import Elf32Arm
from offline_scan import scan
from translate import decode, emit_partial


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--elf", required=True)
    parser.add_argument("--entry-policy", choices=("abi", "exports", "all-exidx", "all-exidx-sweep"), required=True)
    parser.add_argument("--load-bias", type=lambda value: int(value, 0), required=True)
    parser.add_argument("--out", required=True)
    parser.add_argument("--manifest", required=True)
    parser.add_argument("--no-diagnostic", action="store_true")
    args = parser.parse_args()
    started = time.perf_counter()
    image = Elf32Arm(args.elf)
    unrelocated, starts, seeds, reasons = scan(image, args.entry_policy)
    rows = []
    allowed = set()
    for item in unrelocated.values():
        row = dict(item, pc=item["pc"] + args.load_bias)
        rows.append(row)
        try:
            allowed.add(decode(row["pc"], row["insn"], row["len"], row["thumb"])[0])
        except ValueError:
            pass
    rows.sort(key=lambda item: item["pc"])
    output = Path(args.out)
    debug, fast, lengths, hash_size, max_probe = emit_partial(
        rows, output, allowed,
        extra_starts=(pc + args.load_bias for pc, _ in starts),
        emit_debug=not args.no_diagnostic, mode_guard=True)
    result = {
        "schema": "agr.offline-aot-manifest.v1",
        "elf_sha256": image.sha256,
        "elf_bytes": len(image.data),
        "executable_sections": [
            {"name": section.name, "address": section.address, "size": section.size}
            for section in image.executable],
        "entry_policy": args.entry_policy,
        "load_bias": args.load_bias,
        "load_bias_source": "caller-supplied formal linker placement; not inferred from trace",
        "translation_inputs": (["ELF32 ARM code", "dynamic symbols", "init/fini arrays"] +
                               (["EHABI exidx"] if args.entry_policy in
                                {"all-exidx", "all-exidx-sweep"} else []) +
                               ["formal linker load bias"]),
        "execution_trace_input": False,
        "fast_block_mode_guard": True,
        "seed_count": len(seeds),
        "statically_discovered_pc_modes": len(rows),
        "decoded_op_kinds": sorted(allowed),
        "unsupported_discovery_reasons": dict(sorted(reasons.items())),
        "debug_entry_count": len(debug),
        "fast_block_count": len(fast),
        "fast_blocks": [{"pc": pc, "instructions": lengths[pc]} for pc, _ in fast],
        "fast_hash_size": hash_size,
        "fast_hash_max_probe": max_probe,
        "generated_c_sha256": hashlib.sha256(output.read_bytes()).hexdigest(),
        "generated_c_bytes": output.stat().st_size,
        "preparation_wall_seconds": time.perf_counter() - started,
    }
    Path(args.manifest).write_text(json.dumps(result, indent=2) + "\n", encoding="utf-8")
    print(json.dumps({key: value for key, value in result.items() if key != "fast_blocks"}, indent=2))


if __name__ == "__main__":
    main()
