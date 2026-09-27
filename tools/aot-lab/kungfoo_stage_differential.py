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
    baseline_stage_residual = max(0.0, baseline_seconds - baseline_boundary)
    aot_stage_residual = max(0.0, aot_seconds - aot_boundary)
    baseline_engine_samples = [float(row.get("baseline_interpreter_seconds") or 0)
                               for row in baseline_performance]
    aot_engine_samples = [float(row.get("aot_drive_seconds") or 0) for row in performance]
    fallback_engine_samples = [float(row.get("fallback_interpreter_seconds") or 0)
                               for row in performance]
    route_engine_samples = [aot_time + fallback_time for aot_time, fallback_time in
                            zip(aot_engine_samples, fallback_engine_samples)]
    baseline_engine_median = statistics.median(baseline_engine_samples) if baseline_engine_samples else 0
    route_engine_median = statistics.median(route_engine_samples) if route_engine_samples else 0
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
        "interpreter_stage_residual_seconds": baseline_stage_residual,
        "aot_correctness_stage_residual_seconds": aot_stage_residual,
        "stage_residual_is_execution_metric": False,
        "performance_sample_count": len(performance),
        "timing_definition": "CLOCK_MONOTONIC intervals directly around agr_aot_drive and arm_interp_run; excludes loader/linker host work, SVC execution, and Runtime boundary dispatch",
        "interpreter_engine_seconds_samples": baseline_engine_samples,
        "aot_drive_seconds_samples": aot_engine_samples,
        "fallback_interpreter_seconds_samples": fallback_engine_samples,
        "aot_route_engine_seconds_samples": route_engine_samples,
        "interpreter_engine_seconds_median": baseline_engine_median,
        "aot_route_engine_seconds_median": route_engine_median,
        "interpreter_engine_seconds_range": [min(baseline_engine_samples), max(baseline_engine_samples)] if baseline_engine_samples else [],
        "aot_route_engine_seconds_range": [min(route_engine_samples), max(route_engine_samples)] if route_engine_samples else [],
        "engine_speedup_median": baseline_engine_median / route_engine_median if route_engine_median else 0,
        "performance_aot_instructions": sorted({int(row.get("aot_instructions") or 0) for row in performance}),
        "performance_fallback_count": sorted({int(row.get("fallback_count") or 0) for row in performance}),
        "performance_fallback_interpreter_instructions": sorted({int(row.get("fallback_interpreter_instructions") or 0) for row in performance}),
        "performance_svc_interpreter_instructions": sorted({int(row.get("svc_interpreter_instructions") or 0) for row in performance}),
        "performance_lookup_miss_count": sorted({int(row.get("lookup_miss_count") or 0) for row in performance}),
        "performance_it_fallback_count": sorted({int(row.get("it_fallback_count") or 0) for row in performance}),
        "performance_guard_miss_count": sorted({int(row.get("guard_miss_count") or 0) for row in performance}),
        "performance_step_limit_fallback_count": sorted({int(row.get("step_limit_fallback_count") or 0) for row in performance}),
        "performance_dynamic_dispatch_count": sorted({int(row.get("aot_blocks") or 0) for row in performance}),
        "performance_runtime_boundary_seconds": [float(row.get("boundary_seconds") or 0) for row in performance],
        "performance_svc_interpreter_seconds": [float(row.get("svc_interpreter_seconds") or 0) for row in performance],
        "stage_wall_seconds_samples": [float(row.get("seconds") or 0) for row in performance],
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
