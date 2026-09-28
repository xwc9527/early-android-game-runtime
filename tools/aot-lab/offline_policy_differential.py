#!/usr/bin/env python3
"""Compare a trace-independent static entry policy on a bounded real path."""

from collections import Counter, defaultdict
import hashlib
import json
from pathlib import Path
import statistics
import sys


def read_json(path):
    return json.loads(path.read_text(encoding="utf-8"))


def read_rows(path):
    return [[int(value) for value in line.split()]
            for line in path.read_text(encoding="utf-8").splitlines() if line.strip()]


def main():
    evidence = Path(sys.argv[1])
    root = Path(__file__).resolve().parents[2]
    prior = root / "tools/aot-lab/evidence/offline-generalization/run-36375688370"
    manifest = read_json(evidence / "translation-manifest.json")
    identity = read_json(evidence / "input-identity.json")
    trace = read_rows(evidence / "interpreter-trace.txt")
    prior_trace = read_rows(prior / "interpreter-trace.txt")
    trace_stage = read_json(evidence / "interpreter-stage-result.json")
    baseline = read_json(evidence / "baseline-stage-result.json")
    fast = read_json(evidence / "fast-audit-stage-result.json")
    fast_prefix = read_json(evidence / "fast-audit-prefix-result.json")
    interpreter_prefix = read_json(evidence / "interpreter-prefix-result.json")
    checkpoints = read_rows(evidence / "fast-audit-checkpoints.txt")
    cursor = 0
    mismatch = None
    for index, checkpoint in enumerate(checkpoints):
        while cursor < len(trace) and trace[cursor][0] != checkpoint[0]:
            cursor += 1
        if cursor == len(trace):
            mismatch = {"index": index, "reason": "checkpoint PC absent from forward oracle"}
            break
        original = trace[cursor]
        if checkpoint[1] != original[4] or checkpoint[2:17] != original[5:20]:
            mismatch = {"index": index, "reason": "CPSR or r0-r14 differs"}
            break
        cursor += 1
    fields = ("passed", "mounted", "elf_registered", "dex_loaded",
              "jni_onload_status", "jni_version", "native_so_bytes",
              "dex_started", "constructors_status", "constructors",
              "probe_stop_host", "probe_stopped")
    observables = {key: baseline.get(key) == fast.get(key) for key in fields}
    hosts_equal = ((evidence / "baseline-hosts.txt").read_bytes() ==
                   (evidence / "fast-audit-hosts.txt").read_bytes() ==
                   (prior / "interpreter-hosts.txt").read_bytes())
    events = [line.split() for line in (evidence / "fast-audit-fallbacks.txt").read_text().splitlines()]
    reasons = Counter(row[0] for row in events)
    unique = defaultdict(set)
    for reason, pc, cpsr in events:
        unique[reason].add((pc, bool(int(cpsr, 16) & 0x20)))
    fallback_accounting = (not fast.get("fallback_log_incomplete") and
                           len(events) == sum(int(fast.get(key) or 0) for key in
                                              ("lookup_miss_count", "it_fallback_count",
                                               "guard_miss_count", "mode_miss_count",
                                               "step_limit_fallback_count", "boundary_count")))
    new_count = len(trace) - int(interpreter_prefix["trace_seen"])
    new_aot = int(fast["aot_instructions"]) - int(fast_prefix["aot_instructions"])
    new_interpreter = (int(fast["interpreter_instructions"]) -
                       int(fast_prefix["interpreter_instructions"]))
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
    input_identity = (hashlib.sha256((evidence / "input-armv7.so").read_bytes()).hexdigest() ==
                      identity["native_sha256"] == manifest["elf_sha256"])
    source_identity = (hashlib.sha256((evidence / "aot_blocks.c").read_bytes()).hexdigest() ==
                       manifest["generated_c_sha256"])
    assembly_identity = (not manifest.get("assembly_sha256") or
                         hashlib.sha256((evidence / "agr_compiled_blocks.S").read_bytes()).hexdigest() ==
                         manifest["assembly_sha256"])
    result = {
        "schema": "agr.offline-aot-policy-differential.v1",
        "entry_policy": manifest["entry_policy"],
        "tested_commit": identity["tested_commit"],
        "tested_tree": identity["tested_tree"],
        "input_elf_sha256": identity["native_sha256"],
        "generated_c_sha256": manifest["generated_c_sha256"],
        "translation_used_execution_trace": manifest["execution_trace_input"],
        "input_identity_valid": input_identity,
        "source_identity_valid": source_identity,
        "assembly_identity_valid": assembly_identity,
        "interpreter_trace_equal_to_checked_full_run": trace == prior_trace,
        "trace_instructions": len(trace),
        "trace_complete": (not trace_stage.get("trace_incomplete") and
                           trace_stage.get("trace_seen") == len(trace)),
        "fast_checkpoint_count": len(checkpoints),
        "fast_checkpoint_mismatch": mismatch,
        "observable_fields_equal": observables,
        "host_calls_equal": hosts_equal,
        "instruction_accounting": (int(fast["aot_instructions"]) +
                                   int(fast["interpreter_instructions"]) == len(trace)),
        "fallback_log_accounting": fallback_accounting,
        "fallback_reason_counts": dict(sorted(reasons.items())),
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
    result["semantic_pass"] = bool(input_identity and source_identity and assembly_identity and
                                   not manifest["execution_trace_input"] and
                                   manifest["debug_entry_count"] == 0 and
                                   trace == prior_trace and result["trace_complete"] and
                                   checkpoints and mismatch is None and
                                   all(observables.values()) and hosts_equal and
                                   result["instruction_accounting"] and fallback_accounting and
                                   new_count > 0 and result["new_path_accounting"] and
                                   len(baselines) == len(aots) == 7 and
                                   all(row.get("passed") for row in baselines + aots) and
                                   performance_hosts_equal)
    (evidence / "differential.json").write_text(json.dumps(result, indent=2) + "\n")
    print(json.dumps(result, indent=2))
    return 0 if result["semantic_pass"] else 1


if __name__ == "__main__":
    raise SystemExit(main())
