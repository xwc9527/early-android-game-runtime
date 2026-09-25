#!/usr/bin/env python3
"""Run the same pinned cold-start first-frame probe over the five APK corpus."""

import argparse
import json
import subprocess
import sys
from pathlib import Path


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--matrix", required=True, type=Path)
    parser.add_argument("--root", default="/agr-reference", type=Path)
    parser.add_argument("--variant", choices=("CLEAN", "TRACE"), required=True)
    parser.add_argument("--arch", choices=("x86", "arm"), default="x86")
    parser.add_argument("--pair", type=Path)
    parser.add_argument("--sample-ids", nargs="+")
    parser.add_argument("--settle", type=int, default=8)
    parser.add_argument("--out", required=True, type=Path)
    args = parser.parse_args()
    matrix = json.loads(args.matrix.read_text())
    known = {sample["id"]: sample for sample in matrix["samples"]}
    selected = args.sample_ids or list(known)
    if len(set(selected)) != len(selected) or any(name not in known for name in selected):
        raise SystemExit("sample ids are not a unique subset of the locked matrix")
    if args.variant == "TRACE" and not args.pair:
        raise SystemExit("TRACE corpus requires a build-verified CLEAN/TRACE pair")
    results = []
    for sample_id in selected:
        sample = known[sample_id]
        command = [sys.executable, str(Path(__file__).with_name("probe_pair.py")),
                   "--root", str(args.root), "--apk", sample["apk"],
                   "--variant", args.variant, "--arch", args.arch,
                   "--component", sample["component"],
                   "--scenario", "cold_start", "--settle", str(args.settle)]
        if args.pair:
            command.extend(("--pair", str(args.pair)))
        outcome = subprocess.run(command, capture_output=True, text=True)
        lab_name = "aosp-r2" if args.arch == "x86" else "aosp-r2-arm"
        record = (args.root / "emulator" / lab_name / args.variant.lower() /
                  sample["package"] / "cold_start/probe.json")
        item = {"id": sample_id, "package": sample["package"],
                "returncode": outcome.returncode, "record": str(record)}
        if record.is_file():
            probe = json.loads(record.read_text())
            item.update({"status": probe["status"], "stage": probe["stage"],
                         "error": probe.get("error"),
                         "image_sha256": probe["image_sha256"],
                         "visual_status": probe.get("visual_status", "NOT_ASSESSED")})
        else:
            item.update({"status": "FAILED", "stage": "no_record",
                         "error": outcome.stderr[-1000:]})
        results.append(item)
        args.out.parent.mkdir(parents=True, exist_ok=True)
        args.out.write_text(json.dumps({"variant": args.variant, "arch": args.arch,
                                        "scenario": "cold_start",
                                        "scope": "first_frame_only", "results": results}, indent=2) + "\n")
        print(json.dumps(item), flush=True)
    if any(item["status"] != "PASS" for item in results):
        raise SystemExit(1)


if __name__ == "__main__":
    main()
