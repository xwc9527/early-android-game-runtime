#!/usr/bin/env python3
"""Compare one KungFoo interpreter loader stage with the partial AOT run."""

import json
from pathlib import Path
import statistics
import sys


def integer_rows(path):
    return [[int(value) for value in line.split()]
            for line in path.read_text(encoding="utf-8").splitlines() if line.strip()]


def main():
    evidence = Path(sys.argv[1])
    baseline = json.loads((evidence / "baseline-stage-result.json").read_text(encoding="utf-8"))
    aot = json.loads((evidence / "aot-stage-result.json").read_text(encoding="utf-8"))
    manifest = json.loads((evidence / "translation-manifest.json").read_text(encoding="utf-8"))
    baseline_hosts = (evidence / "baseline-hosts.txt").read_text(encoding="utf-8").splitlines()
    aot_hosts = (evidence / "aot-hosts.txt").read_text(encoding="utf-8").splitlines()
    baseline_performance = [json.loads(path.read_text(encoding="utf-8")) for path in
                            sorted(evidence.glob("baseline-performance-*-stage-result.json"))]
    performance = [json.loads(path.read_text(encoding="utf-8")) for path in
                   sorted(evidence.glob("performance-*-stage-result.json"))]
    baseline_performance_hosts = [path.read_text(encoding="utf-8").splitlines() for path in
                                  sorted(evidence.glob("baseline-performance-*-hosts.txt"))]
    performance_hosts = [path.read_text(encoding="utf-8").splitlines() for path in
                         sorted(evidence.glob("performance-*-hosts.txt"))]
    trace = integer_rows(evidence / "interpreter-trace.txt")
    checkpoints = integer_rows(evidence / "aot-checkpoints.txt")

    cursor = 0
    mismatches = []
    for index, checkpoint in enumerate(checkpoints):
        pc = checkpoint[0]
        while cursor < len(trace) and trace[cursor][0] != pc:
            cursor += 1
        if cursor >= len(trace):
            mismatches.append({"checkpoint": index, "pc": pc, "reason": "pc-not-in-forward-trace"})
            break
        observed = trace[cursor]
        if len(checkpoint) < 18 or len(observed) < 21:
            mismatches.append({"checkpoint": index, "pc": pc, "reason": "truncated-row"})
            break
        if checkpoint[1] != observed[4] or checkpoint[2:17] != observed[5:20]:
            mismatches.append({"checkpoint": index, "pc": pc, "reason": "cpsr-or-r0-r14"})
            break
        cursor += 1

    equal_fields = {
        key: baseline.get(key) == aot.get(key)
        for key in ("passed", "mounted", "elf_registered", "dex_loaded",
                    "jni_onload_status", "jni_version", "native_so_bytes", "error")
    }
    baseline_seconds = float(baseline.get("seconds") or 0)
    aot_seconds = float(aot.get("seconds") or 0)
    baseline_boundary = float(baseline.get("boundary_seconds") or 0)
    aot_boundary = float(aot.get("boundary_seconds") or 0)
    baseline_guest = max(0.0, baseline_seconds - baseline_boundary)
    aot_guest = max(0.0, aot_seconds - aot_boundary)
    baseline_guest_samples = [max(0.0, float(row.get("seconds") or 0) -
                                  float(row.get("boundary_seconds") or 0))
                              for row in baseline_performance]
    performance_guest_samples = [max(0.0, float(row.get("seconds") or 0) -
                                     float(row.get("boundary_seconds") or 0))
                                 for row in performance]
    baseline_guest_median = statistics.median(baseline_guest_samples) if baseline_guest_samples else 0
    performance_guest_median = statistics.median(performance_guest_samples) if performance_guest_samples else 0
    samples_valid = (len(baseline_performance) == len(performance) == 7 and
                     all(row.get("passed") for row in baseline_performance + performance) and
                     all(hosts == baseline_hosts for hosts in baseline_performance_hosts + performance_hosts))
    result = {
        "schema_version": 1,
        "workload": "kungfoo-armv7-native-loader-stage",
        "semantic_pass": bool(all(equal_fields.values()) and baseline.get("passed") and
                              aot.get("passed") and samples_valid and baseline_hosts == aot_hosts and
                              not mismatches and checkpoints and int(aot.get("aot_instructions") or 0) > 0),
        "observable_fields_equal": equal_fields,
        "host_sequence_equal": baseline_hosts == aot_hosts,
        "performance_host_sequence_equal": samples_valid,
        "host_call_count": len(aot_hosts),
        "checkpoint_count": len(checkpoints),
        "checkpoint_mismatches": mismatches,
        "interpreter_instructions": int(baseline.get("interpreter_instructions") or 0),
        "aot_instructions": int(aot.get("aot_instructions") or 0),
        "aot_blocks": int(aot.get("aot_blocks") or 0),
        "fallback_count": int(aot.get("fallback_count") or 0),
        "miss_pc": aot.get("miss_pc"),
        "interpreter_seconds": baseline_seconds,
        "aot_correctness_seconds": aot_seconds,
        "interpreter_boundary_seconds": baseline_boundary,
        "aot_correctness_boundary_seconds": aot_boundary,
        "interpreter_guest_seconds": baseline_guest,
        "aot_correctness_guest_seconds": aot_guest,
        "performance_sample_count": len(performance),
        "interpreter_guest_seconds_samples": baseline_guest_samples,
        "aot_performance_guest_seconds_samples": performance_guest_samples,
        "interpreter_guest_seconds_median": baseline_guest_median,
        "aot_performance_guest_seconds_median": performance_guest_median,
        "interpreter_guest_seconds_range": [min(baseline_guest_samples), max(baseline_guest_samples)] if baseline_guest_samples else [],
        "aot_performance_guest_seconds_range": [min(performance_guest_samples), max(performance_guest_samples)] if performance_guest_samples else [],
        "guest_speedup_median": baseline_guest_median / performance_guest_median if performance_guest_median else 0,
        "performance_aot_instructions": sorted({int(row.get("aot_instructions") or 0) for row in performance}),
        "performance_fallback_count": sorted({int(row.get("fallback_count") or 0) for row in performance}),
        "preparation_wall_seconds": manifest.get("preparation_wall_seconds"),
        "generated_c_bytes": manifest.get("generated_c_bytes"),
        "generated_block_count": len(manifest.get("blocks") or []),
        "partial_baseline_trace_sha256": manifest.get("partial_baseline_trace_sha256"),
        "input_trace_sha256": manifest.get("input_trace_sha256"),
    }
    (evidence / "differential.json").write_text(
        json.dumps(result, indent=2) + "\n", encoding="utf-8", newline="\n")
    print(json.dumps(result, indent=2))
    return 0 if result["semantic_pass"] else 1


if __name__ == "__main__":
    raise SystemExit(main())
