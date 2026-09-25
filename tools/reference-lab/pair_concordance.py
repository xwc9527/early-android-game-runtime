#!/usr/bin/env python3
"""Compare measured CLEAN/TRACE runtime states without claiming semantic identity."""

import argparse
import json
from pathlib import Path


def compare(clean, trace, pair):
    if pair.get("status") != "BUILD_VERIFIED":
        raise ValueError("reference pair is not build-verified")
    if (clean.get("variant"), trace.get("variant")) != ("CLEAN", "TRACE"):
        raise ValueError("probe roles are invalid")
    if any(run.get("status") != "PASS" or run.get("pair_status") != "BUILD_VERIFIED"
           for run in (clean, trace)):
        raise ValueError("both runtime probes must pass on the verified pair")
    if clean.get("image_sha256") != pair["clean"]["image_sha256"] or \
            trace.get("image_sha256") != pair["trace"]["image_sha256"]:
        raise ValueError("probe image identity differs from verified pair")
    identity = ("apk_sha256", "scenario", "arch", "actions_sha256", "vm_config",
                "execution_mode", "jit_effective", "zygote_preload",
                "zygote_loaded_libraries", "gpu_mode", "show_window", "accel")
    if any(clean.get(key) is None or clean[key] != trace.get(key) for key in identity):
        raise ValueError("CLEAN/TRACE input or runtime configuration differs")
    clean_steps = clean.get("steps", [])
    trace_steps = trace.get("steps", [])
    if not clean_steps or len(clean_steps) != len(trace_steps):
        raise ValueError("CLEAN/TRACE scenarios have different step counts")
    mismatches = []
    for index, (left, right) in enumerate(zip(clean_steps, trace_steps)):
        for field in ("label", "resumed", "focused"):
            if left.get(field) != right.get(field):
                mismatches.append({"step": index, "field": field,
                                   "clean": left.get(field), "trace": right.get(field)})
        if left.get("process", {}).get("alive") != right.get("process", {}).get("alive"):
            mismatches.append({"step": index, "field": "process.alive"})
    return {"schema_version": 1,
            "status": "STATE_CONCORDANT" if not mismatches else "STATE_DIVERGED",
            "apk_sha256": clean["apk_sha256"], "scenario": clean["scenario"],
            "checked_fields": ["resumed", "focused", "process.alive"],
            "mismatches": mismatches,
            "semantic_equivalence_established": False,
            "pruning_authorized": False,
            "scope": "structural runtime state only; game state, timing, audio, and pixels are not equivalent by this check"}


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--clean", required=True, type=Path)
    parser.add_argument("--trace", required=True, type=Path)
    parser.add_argument("--pair", required=True, type=Path)
    parser.add_argument("--out", required=True, type=Path)
    args = parser.parse_args()
    result = compare(*(json.loads(path.read_text()) for path in
                       (args.clean, args.trace, args.pair)))
    args.out.parent.mkdir(parents=True, exist_ok=True)
    args.out.write_text(json.dumps(result, indent=2) + "\n")
    print(result["status"])
    if result["status"] != "STATE_CONCORDANT":
        raise SystemExit(1)


if __name__ == "__main__":
    main()
