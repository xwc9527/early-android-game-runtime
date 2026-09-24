#!/usr/bin/env python3
"""Compare exact build inputs; never infer physical parity from SDK alone."""

import argparse
import json
from pathlib import Path


def compare(simulator, iphoneos, physical=None):
    same_build = all(simulator.get(k) and simulator.get(k) == iphoneos.get(k)
                     for k in ("commit", "tree", "apk_sha256", "xcode_version", "xcode_build"))
    tools_exact = (simulator.get("xcode_version") == iphoneos.get("xcode_version") == "Xcode 27.0"
                   and simulator.get("sdk_version") == iphoneos.get("sdk_version") == "27.0")
    simulator_exact = (simulator.get("simulator_runtime_version") == "27.0"
                       and simulator.get("simulator_runtime_actual") ==
                       "com.apple.CoreSimulator.SimRuntime.iOS-27-0")
    physical_version = physical.get("product_version") if physical else None
    parity = ("EXACT" if physical_version == "27.0" and simulator_exact else
              "PENDING_PHYSICAL" if physical is None else "MISMATCH")
    result = {
        "schema": "agr.ios27-environment-parity.v1",
        "simulator_product_version": simulator.get("simulator_runtime_version"),
        "physical_product_version": physical_version,
        "product_version_parity": parity,
        "simulator_xcode": simulator.get("xcode_version"),
        "iphoneos_xcode": iphoneos.get("xcode_version"),
        "simulator_sdk": simulator.get("sdk_version"),
        "iphoneos_sdk": iphoneos.get("sdk_version"),
        "build_artifact_identity": "EXACT" if same_build else "MISMATCH",
        "baseline_valid": bool(same_build and tools_exact and simulator_exact),
    }
    return result


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--simulator", type=Path, required=True)
    parser.add_argument("--iphoneos", type=Path, required=True)
    parser.add_argument("--physical", type=Path)
    parser.add_argument("--output", type=Path, required=True)
    args = parser.parse_args()
    simulator = json.loads(args.simulator.read_text(encoding="utf-8"))
    iphoneos = json.loads(args.iphoneos.read_text(encoding="utf-8"))
    physical = json.loads(args.physical.read_text(encoding="utf-8")) if args.physical else None
    result = compare(simulator, iphoneos, physical)
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(json.dumps(result, indent=2) + "\n", encoding="utf-8")
    print(json.dumps(result, sort_keys=True))
    if not result["baseline_valid"] or (physical and result["product_version_parity"] != "EXACT"):
        raise SystemExit("ENVIRONMENT_BASELINE_MISMATCH")


if __name__ == "__main__":
    main()
