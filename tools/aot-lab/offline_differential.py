#!/usr/bin/env python3
"""Compare trace-withheld offline AOT execution with its interpreter oracle."""

from collections import Counter, defaultdict
import hashlib
import json
from pathlib import Path
import statistics
import sys

from offline_elf import Elf32Arm
from offline_scan import scan
from translate import decode


def read_json(path):
    return json.loads(path.read_text(encoding="utf-8"))


def read_rows(path):
    return [[int(value) for value in line.split()]
            for line in path.read_text(encoding="utf-8").splitlines() if line.strip()]


def main():
    evidence = Path(sys.argv[1])
    manifest = read_json(evidence / "translation-manifest.json")
    identity = read_json(evidence / "input-identity.json")
    image = Elf32Arm(evidence / "input-armv7.so")
    if image.sha256 != manifest["elf_sha256"] or image.sha256 != identity["native_sha256"]:
        raise ValueError("input ELF identity changed")
    if hashlib.sha256((evidence / "aot_blocks.c").read_bytes()).hexdigest() != manifest["generated_c_sha256"]:
        raise ValueError("generated AOT source identity changed")
    trace = read_rows(evidence / "interpreter-trace.txt")
    trace_stage = read_json(evidence / "interpreter-stage-result.json")
    baseline = read_json(evidence / "baseline-stage-result.json")
    diagnostic = read_json(evidence / "diagnostic-stage-result.json")
    fast = read_json(evidence / "fast-audit-stage-result.json")
    baseline_hosts = (evidence / "baseline-hosts.txt").read_bytes()
    same_fields = ("passed", "mounted", "elf_registered", "dex_loaded",
                   "jni_onload_status", "jni_version", "native_so_bytes", "error")
    if "activity_created" in baseline:
        same_fields += ("dex_started", "constructors_status", "constructors")
        if baseline.get("probe_stop_host"):
            same_fields = tuple(key for key in same_fields if key != "error")
            same_fields += ("probe_stop_host", "probe_stopped")
        else:
            same_fields += ("activity_created",)
    observable = {key: baseline.get(key) == diagnostic.get(key) == fast.get(key)
                  for key in same_fields}
    hosts_equal = (baseline_hosts == (evidence / "diagnostic-hosts.txt").read_bytes() ==
                   (evidence / "fast-audit-hosts.txt").read_bytes())
    checkpoints = read_rows(evidence / "diagnostic-checkpoints.txt")
    cursor = 0
    checkpoint_mismatches = []
    for index, checkpoint in enumerate(checkpoints):
        while cursor < len(trace) and trace[cursor][0] != checkpoint[0]:
            cursor += 1
        if cursor == len(trace):
            checkpoint_mismatches.append({"index": index, "reason": "PC absent from forward trace"})
            break
        original = trace[cursor]
        if checkpoint[1] != original[4] or checkpoint[2:17] != original[5:20]:
            checkpoint_mismatches.append({"index": index, "pc": checkpoint[0],
                                          "reason": "CPSR or r0-r14 differs"})
            break
        cursor += 1
    path_accounting = {
        name: (stage.get("aot_instructions", 0) + stage.get("interpreter_instructions", 0) == len(trace))
        for name, stage in (("diagnostic", diagnostic), ("fast", fast))
    }
    fallback_events = []
    for line in (evidence / "fast-audit-fallbacks.txt").read_text().splitlines():
        reason, pc, cpsr = line.split()
        fallback_events.append((reason, int(pc, 16), int(cpsr, 16)))
    fallback_counts = Counter(reason for reason, _, _ in fallback_events)
    fallback_unique = defaultdict(set)
    for reason, pc, cpsr in fallback_events:
        fallback_unique[reason].add((pc, bool(cpsr & 0x20)))
    discovered, _, _, _ = scan(image, manifest["entry_policy"])
    oracle_rows = {(row[0], row[3]): row for row in trace}
    lookup_classes = Counter()
    for reason, pc, cpsr in fallback_events:
        if reason != "lookup_miss":
            continue
        thumb = bool(cpsr & 0x20)
        relative = pc - manifest["load_bias"]
        row = oracle_rows.get((pc, int(thumb)))
        if image.code_at(relative, 2 if thumb else 4) is None:
            category = "outside_input_elf"
        elif row is None:
            category = "not_in_oracle_trace"
        else:
            raw, length = row[1], row[2]
            try:
                decode(pc, raw, length, thumb)
            except ValueError:
                category = "unsupported_arm_semantic"
            else:
                known = discovered.get(relative)
                category = ("decoded_but_no_fast_entry" if known and known["insn"] == raw and
                            known["len"] == length and known["thumb"] == int(thumb)
                            else "static_discovery_gap")
        lookup_classes[category] += 1
    log_accounting = (not fast.get("fallback_log_incomplete") and
                      len(fallback_events) == sum(int(fast.get(name) or 0) for name in
                          ("lookup_miss_count", "it_fallback_count", "guard_miss_count", "mode_miss_count",
                           "step_limit_fallback_count", "boundary_count")))
    baselines = [read_json(path) for path in sorted(evidence.glob("baseline-performance-*-stage-result.json"))]
    aots = [read_json(path) for path in sorted(evidence.glob("performance-*-stage-result.json"))]
    baseline_times = [float(row.get("baseline_interpreter_seconds") or 0) for row in baselines]
    aot_times = [(float(row.get("aot_drive_seconds") or 0) +
                  float(row.get("fallback_interpreter_seconds") or 0) +
                  float(row.get("svc_interpreter_seconds") or 0)) for row in aots]
    performance_hosts_equal = all(
        (evidence / f"baseline-performance-{index}-hosts.txt").read_bytes() == baseline_hosts ==
        (evidence / f"performance-{index}-hosts.txt").read_bytes()
        for index in range(1, len(baselines) + 1))
    prior_path = evidence / "prior-loader-interpreter-trace.txt"
    heldout = None
    if prior_path.exists():
        prior = read_rows(prior_path)
        prior_stage = read_json(evidence / "prior-loader-fast-audit-stage-result.json")
        prior_manifest = read_json(evidence / "prior-loader-translation-manifest.json")
        prefix_equal = len(trace) > len(prior) and trace[:len(prior)] == prior
        same_generated_code = (prior_manifest["generated_c_sha256"] == manifest["generated_c_sha256"])
        suffix = trace[len(prior):] if prefix_equal else []
        prior_pc_modes = {(row[0], row[3]) for row in prior}
        heldout = {
            "prior_trace_instructions": len(prior),
            "exact_loader_prefix_equal": prefix_equal,
            "same_generated_code_as_loader_probe": same_generated_code,
            "new_path_instructions": len(suffix),
            "new_pc_modes": len({(row[0], row[3]) for row in suffix} - prior_pc_modes),
        }
        if prefix_equal and same_generated_code:
            suffix_aot = int(fast["aot_instructions"]) - int(prior_stage["aot_instructions"])
            suffix_interp = int(fast["interpreter_instructions"]) - int(prior_stage["interpreter_instructions"])
            heldout.update({"new_path_aot_instructions": suffix_aot,
                            "new_path_interpreter_instructions": suffix_interp,
                            "new_path_instruction_accounting": suffix_aot + suffix_interp == len(suffix),
                            "new_path_aot_coverage": suffix_aot / len(suffix) if suffix else 0})
    result = {
        "schema": "agr.offline-aot-differential.v1",
        "input_elf_sha256": image.sha256,
        "generated_c_sha256": manifest["generated_c_sha256"],
        "tested_commit": identity["tested_commit"],
        "tested_tree": identity["tested_tree"],
        "translation_used_execution_trace": manifest["execution_trace_input"],
        "oracle_trace_sha256": hashlib.sha256((evidence / "interpreter-trace.txt").read_bytes()).hexdigest(),
        "interpreter_trace_instructions": len(trace),
        "interpreter_trace_complete": (not trace_stage.get("trace_incomplete") and
                                        trace_stage.get("trace_seen") == len(trace)),
        "observable_fields_equal": observable,
        "host_calls_equal": hosts_equal,
        "checkpoint_count": len(checkpoints),
        "checkpoint_mismatches": checkpoint_mismatches,
        "instruction_accounting": path_accounting,
        "diagnostic_aot_instructions": diagnostic.get("aot_instructions"),
        "fast_aot_instructions": fast.get("aot_instructions"),
        "fast_interpreter_instructions": fast.get("interpreter_instructions"),
        "fast_lookup_misses": fast.get("lookup_miss_count"),
        "fast_fallback_counts": dict(sorted(fallback_counts.items())),
        "fast_fallback_unique_pc_mode": {key: len(value) for key, value in sorted(fallback_unique.items())},
        "lookup_miss_classes": dict(sorted(lookup_classes.items())),
        "fallback_log_accounting": log_accounting,
        "performance_samples": len(aot_times),
        "heldout_path": heldout,
        "performance_host_calls_equal": performance_hosts_equal,
        "baseline_engine_seconds": baseline_times,
        "aot_route_engine_seconds": aot_times,
        "baseline_engine_median": statistics.median(baseline_times),
        "aot_route_engine_median": statistics.median(aot_times),
        "route_speedup_ratio_of_medians": statistics.median(baseline_times) / statistics.median(aot_times),
        "semantic_pass": bool(not trace_stage.get("trace_incomplete") and
                              trace_stage.get("trace_seen") == len(trace) and
                              all(observable.values()) and hosts_equal and
                              all(path_accounting.values()) and not checkpoint_mismatches and
                              checkpoints and log_accounting and len(baselines) == len(aots) == 3 and
                              all(row.get("passed") for row in baselines + aots) and
                              performance_hosts_equal and
                              (heldout is None or
                               (heldout["exact_loader_prefix_equal"] and
                                heldout["same_generated_code_as_loader_probe"] and
                                heldout.get("new_path_instruction_accounting")))),
    }
    (evidence / "differential.json").write_text(json.dumps(result, indent=2) + "\n")
    print(json.dumps(result, indent=2))
    return 0 if result["semantic_pass"] else 1


if __name__ == "__main__":
    raise SystemExit(main())
