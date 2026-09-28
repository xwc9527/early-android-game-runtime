#!/usr/bin/env python3
"""Check warm guest execution using one trace-independent relocated artifact."""

import hashlib
import json
from pathlib import Path
import statistics
import sys


def read(path):
    return json.loads(path.read_text())


def main():
    evidence = Path(sys.argv[1])
    identity = read(evidence / "input-identity.json")
    manifest = read(evidence / "translation-manifest.json")
    source_equal = (hashlib.sha256((evidence / "input-armv7.so").read_bytes()).hexdigest() ==
                    identity["native_sha256"] == manifest["elf_sha256"])
    artifact_equal = (hashlib.sha256((evidence / "aot_blocks.c").read_bytes()).hexdigest() ==
                      manifest["generated_c_sha256"])
    samples = []
    observables = ("passed", "lines", "triangles", "bytes", "framebuffer_fnv",
                   "nonblack_pixels", "error", "actual_load_bias")
    for index in range(1, 6):
        baseline = read(evidence / f"baseline-performance-{index}-result.json")
        aot = read(evidence / f"aot-performance-{index}-result.json")
        baseline_engine = baseline["warm_guest_engine_seconds"]
        aot_engine = aot["warm_guest_engine_seconds"]
        matching = all(baseline[key] == aot[key] for key in observables)
        host_equal = ((evidence / f"baseline-performance-{index}-hosts.txt").read_bytes() ==
                      (evidence / f"aot-performance-{index}-hosts.txt").read_bytes())
        instruction_equal = (
            baseline["cold_guest_instructions"] ==
            aot["cold_guest_instructions"] + aot["aot_instructions"] - aot["warm_aot_instructions"] and
            baseline["warm_guest_instructions"] ==
            aot["warm_guest_instructions"] + aot["warm_aot_instructions"])
        samples.append({
            "index": index,
            "load_bias": aot["actual_load_bias"],
            "warm_iterations": aot["warm_iterations"],
            "observables_equal": matching,
            "host_calls_equal": host_equal,
            "instruction_accounting": instruction_equal,
            "aot_fallback_count": aot["fallback_count"],
            "baseline_warm_instructions": baseline["warm_guest_instructions"],
            "aot_warm_instructions": aot["warm_aot_instructions"],
            "aot_svc_warm_instructions": aot["warm_guest_instructions"],
            "baseline_warm_engine_seconds": baseline_engine,
            "aot_warm_engine_seconds": aot_engine,
            "aot_warm_drive_seconds": aot["warm_aot_drive_seconds"],
            "aot_warm_fallback_seconds": aot["warm_fallback_interpreter_seconds"],
            "aot_warm_svc_seconds": aot["warm_svc_interpreter_seconds"],
            "warm_speed_ratio": baseline_engine / aot_engine if aot_engine else 0,
        })
    baseline_median = statistics.median(x["baseline_warm_engine_seconds"] for x in samples)
    aot_median = statistics.median(x["aot_warm_engine_seconds"] for x in samples)
    passed = bool(source_equal and artifact_equal and manifest["relocatable"] and
                  not manifest["execution_trace_input"] and
                  all(x["warm_iterations"] == 16384 and x["observables_equal"] and
                      x["host_calls_equal"] and x["instruction_accounting"] and
                      x["aot_fallback_count"] == 0 and x["load_bias"] == 0x10000 and
                      x["baseline_warm_engine_seconds"] > 0 and
                      x["aot_warm_engine_seconds"] > 0 for x in samples))
    result = {
        "schema": "agr.offline-gloomy-warm-differential.v1",
        "tested_commit": identity["tested_commit"],
        "input_identity_valid": source_equal,
        "artifact_identity_valid": artifact_equal,
        "translation_uses_execution_trace": manifest["execution_trace_input"],
        "samples": samples,
        "baseline_warm_engine_median_seconds": baseline_median,
        "aot_warm_engine_median_seconds": aot_median,
        "warm_speed_ratio_of_medians": baseline_median / aot_median if aot_median else 0,
        "semantic_pass": passed,
    }
    (evidence / "warm-differential.json").write_text(json.dumps(result, indent=2) + "\n")
    print(json.dumps(result, indent=2))
    return 0 if passed else 1


if __name__ == "__main__":
    raise SystemExit(main())
