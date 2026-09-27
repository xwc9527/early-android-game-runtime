#!/usr/bin/env python3
"""Compare one KungFoo interpreter loader stage with the partial AOT run."""

import json
from pathlib import Path
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
    result = {
        "schema_version": 1,
        "workload": "kungfoo-armv7-native-loader-stage",
        "semantic_pass": bool(all(equal_fields.values()) and baseline.get("passed") and
                              aot.get("passed") and baseline_hosts == aot_hosts and
                              not mismatches and checkpoints and int(aot.get("aot_instructions") or 0) > 0),
        "observable_fields_equal": equal_fields,
        "host_sequence_equal": baseline_hosts == aot_hosts,
        "host_call_count": len(aot_hosts),
        "checkpoint_count": len(checkpoints),
        "checkpoint_mismatches": mismatches,
        "interpreter_instructions": int(baseline.get("interpreter_instructions") or 0),
        "aot_instructions": int(aot.get("aot_instructions") or 0),
        "aot_blocks": int(aot.get("aot_blocks") or 0),
        "fallback_count": int(aot.get("fallback_count") or 0),
        "miss_pc": aot.get("miss_pc"),
        "interpreter_seconds": baseline_seconds,
        "aot_seconds": aot_seconds,
        "interpreter_boundary_seconds": baseline_boundary,
        "aot_boundary_seconds": aot_boundary,
        "interpreter_guest_seconds": baseline_guest,
        "aot_guest_seconds": aot_guest,
        "guest_speedup": baseline_guest / aot_guest if aot_guest else 0,
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
