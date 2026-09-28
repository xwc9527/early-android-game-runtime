#!/usr/bin/env python3
"""Measure a fast-only static AOT product artifact against a checked full artifact."""

from collections import Counter, defaultdict
import hashlib
import json
from pathlib import Path
import statistics
import sys


def read_json(path):
    return json.loads(path.read_text(encoding="utf-8"))


def fast_functions(source):
    begin = source.index(b"static int aot_fast_")
    end = source.index(b"const AgrAotEntry agr_aot_debug_blocks[]", begin)
    return source[begin:end]


def main():
    evidence = Path(sys.argv[1])
    root = Path(__file__).resolve().parents[2]
    prior = root / "tools/aot-lab/evidence/offline-generalization/run-36375688370"
    manifest = read_json(evidence / "translation-manifest.json")
    prior_manifest = read_json(prior / "translation-manifest.json")
    identity = read_json(evidence / "input-identity.json")
    trace = (evidence / "interpreter-trace.txt").read_bytes()
    source = (evidence / "aot_blocks.c").read_bytes()
    prior_source = (prior / "aot_blocks.c").read_bytes()
    trace_stage = read_json(evidence / "interpreter-stage-result.json")
    baseline = read_json(evidence / "baseline-stage-result.json")
    fast = read_json(evidence / "fast-audit-stage-result.json")
    trace_equal = trace == (prior / "interpreter-trace.txt").read_bytes()
    source_equal = fast_functions(source) == fast_functions(prior_source)
    source_identity = hashlib.sha256(source).hexdigest() == manifest["generated_c_sha256"]
    input_identity = (hashlib.sha256((evidence / "input-armv7.so").read_bytes()).hexdigest() ==
                      identity["native_sha256"] == manifest["elf_sha256"])
    trace_count = len(trace.splitlines())
    observable_keys = ("passed", "mounted", "elf_registered", "dex_loaded",
                       "jni_onload_status", "jni_version", "native_so_bytes",
                       "dex_started", "constructors_status", "constructors",
                       "probe_stop_host", "probe_stopped")
    observables = {key: baseline.get(key) == fast.get(key) for key in observable_keys}
    host_equal = ((evidence / "baseline-hosts.txt").read_bytes() ==
                  (evidence / "fast-audit-hosts.txt").read_bytes() ==
                  (prior / "interpreter-hosts.txt").read_bytes())
    events = [line.split() for line in (evidence / "fast-audit-fallbacks.txt").read_text().splitlines()]
    reason_counts = Counter(row[0] for row in events)
    unique = defaultdict(set)
    for reason, pc, cpsr in events:
        unique[reason].add((pc, bool(int(cpsr, 16) & 0x20)))
    fallback_accounting = (not fast.get("fallback_log_incomplete") and
                           len(events) == sum(int(fast.get(key) or 0) for key in
                                              ("lookup_miss_count", "it_fallback_count",
                                               "guard_miss_count", "mode_miss_count",
                                               "step_limit_fallback_count", "boundary_count")))
    instruction_accounting = (int(fast["aot_instructions"]) +
                              int(fast["interpreter_instructions"]) == trace_count)
    loader = read_json(evidence / "prior-loader-fast-audit-stage-result.json")
    loader_trace_count = len((evidence / "prior-loader-interpreter-trace.txt").read_bytes().splitlines())
    new_count = trace_count - loader_trace_count
    new_aot = int(fast["aot_instructions"]) - int(loader["aot_instructions"])
    new_interpreter = int(fast["interpreter_instructions"]) - int(loader["interpreter_instructions"])
    baselines = [read_json(path) for path in sorted(evidence.glob("baseline-performance-*-stage-result.json"))]
    aots = [read_json(path) for path in sorted(evidence.glob("performance-*-stage-result.json"))]
    baseline_seconds = [float(row.get("baseline_interpreter_seconds") or 0) for row in baselines]
    aot_seconds = [(float(row.get("aot_drive_seconds") or 0) +
                    float(row.get("fallback_interpreter_seconds") or 0) +
                    float(row.get("svc_interpreter_seconds") or 0)) for row in aots]
    performance_hosts_equal = all(
        (evidence / f"baseline-performance-{index}-hosts.txt").read_bytes() ==
        (evidence / f"performance-{index}-hosts.txt").read_bytes() ==
        (evidence / "baseline-hosts.txt").read_bytes()
        for index in range(1, len(baselines) + 1))
    result = {
        "schema": "agr.offline-aot-fast-only-differential.v1",
        "tested_commit": identity["tested_commit"],
        "tested_tree": identity["tested_tree"],
        "input_elf_sha256": identity["native_sha256"],
        "generated_c_sha256": manifest["generated_c_sha256"],
        "prior_full_generated_c_sha256": prior_manifest["generated_c_sha256"],
        "translation_used_execution_trace": manifest["execution_trace_input"],
        "debug_entry_count": manifest["debug_entry_count"],
        "input_identity_valid": input_identity,
        "source_identity_valid": source_identity,
        "fast_function_source_equal_to_checked_full_artifact": source_equal,
        "interpreter_trace_equal_to_checked_full_run": trace_equal,
        "trace_instructions": trace_count,
        "trace_complete": (not trace_stage.get("trace_incomplete") and
                           int(trace_stage.get("trace_seen") or 0) == trace_count),
        "observable_fields_equal": observables,
        "host_calls_equal": host_equal,
        "instruction_accounting": instruction_accounting,
        "fallback_log_accounting": fallback_accounting,
        "fallback_reason_counts": dict(sorted(reason_counts.items())),
        "fallback_unique_pc_mode": {key: len(value) for key, value in sorted(unique.items())},
        "aot_instructions": fast["aot_instructions"],
        "interpreter_instructions": fast["interpreter_instructions"],
        "new_path_instructions": new_count,
        "new_path_aot_instructions": new_aot,
        "new_path_interpreter_instructions": new_interpreter,
        "new_path_aot_coverage": new_aot / new_count if new_count else 0,
        "new_path_accounting": new_aot + new_interpreter == new_count,
        "performance_samples": len(aot_seconds),
        "performance_host_calls_equal": performance_hosts_equal,
        "baseline_engine_seconds": baseline_seconds,
        "aot_route_engine_seconds": aot_seconds,
        "baseline_engine_median": statistics.median(baseline_seconds),
        "aot_route_engine_median": statistics.median(aot_seconds),
        "route_speedup_ratio_of_medians": (statistics.median(baseline_seconds) /
                                           statistics.median(aot_seconds)),
    }
    result["semantic_pass"] = bool(input_identity and source_identity and source_equal and
                                   trace_equal and result["trace_complete"] and
                                   manifest["debug_entry_count"] == 0 and
                                   not manifest["execution_trace_input"] and
                                   all(observables.values()) and host_equal and
                                   instruction_accounting and fallback_accounting and
                                   result["new_path_accounting"] and new_count > 0 and
                                   len(baselines) == len(aots) == 7 and
                                   all(row.get("passed") for row in baselines + aots) and
                                   performance_hosts_equal)
    (evidence / "differential.json").write_text(json.dumps(result, indent=2) + "\n")
    print(json.dumps(result, indent=2))
    return 0 if result["semantic_pass"] else 1


if __name__ == "__main__":
    raise SystemExit(main())
