#!/usr/bin/env python3
"""Audit a second game's ELF-only AOT run against its later interpreter trace."""

import hashlib
import json
from pathlib import Path
import sys
from collections import Counter


def read_json(path):
    return json.loads(path.read_text(encoding="utf-8"))


def read_rows(path):
    return [[int(value) for value in line.split()]
            for line in path.read_text(encoding="utf-8").splitlines() if line.strip()]


def main():
    evidence = Path(sys.argv[1])
    identity = read_json(evidence / "input-identity.json")
    manifest = read_json(evidence / "translation-manifest.json")
    interpreter = read_json(evidence / "interpreter-result.json")
    aot = read_json(evidence / "aot-result.json")
    trace = read_rows(evidence / "interpreter-trace.txt")
    checkpoints = read_rows(evidence / "aot-checkpoints.txt")
    source_identity = (hashlib.sha256((evidence / "input-armv7.so").read_bytes()).hexdigest() ==
                       identity["native_sha256"] == manifest["elf_sha256"])
    generated_identity = (hashlib.sha256((evidence / "aot_blocks.c").read_bytes()).hexdigest() ==
                          manifest["generated_c_sha256"])
    observable_fields = ("passed", "lines", "triangles", "bytes", "framebuffer_fnv",
                         "nonblack_pixels", "error")
    observables = {key: interpreter.get(key) == aot.get(key) for key in observable_fields}
    host_equal = ((evidence / "interpreter-hosts.txt").read_bytes() ==
                  (evidence / "aot-hosts.txt").read_bytes())
    fallback_events = [line.split() for line in (evidence / "aot-fallbacks.txt").read_text().splitlines()]
    fallback_counts = Counter(row[0] for row in fallback_events)
    ordinary_fallbacks = sum(count for reason, count in fallback_counts.items() if reason != "svc")
    fallback_accounting = (not aot.get("fallback_log_incomplete") and
                           ordinary_fallbacks == aot.get("fallback_count") and
                           fallback_counts.get("svc", 0) == aot.get("boundary_count"))
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
    accounted = (int(aot.get("aot_instructions") or 0) +
                 int(aot.get("interpreter_instructions") or 0) ==
                 int(interpreter.get("interpreter_instructions") or 0))
    result = {
        "schema": "agr.offline-gloomy-differential.v1",
        "tested_commit": identity["tested_commit"],
        "tested_tree": identity["tested_tree"],
        "input_elf_sha256": identity["native_sha256"],
        "input_elf_bytes": identity["native_bytes"],
        "generated_c_sha256": manifest["generated_c_sha256"],
        "translation_used_execution_trace": manifest["execution_trace_input"],
        "input_identity_valid": source_identity,
        "generated_identity_valid": generated_identity,
        "interpreter_trace_sha256": hashlib.sha256((evidence / "interpreter-trace.txt").read_bytes()).hexdigest(),
        "interpreter_trace_instructions": len(trace),
        "checkpoint_count": len(checkpoints),
        "checkpoint_mismatch": mismatch,
        "observables_equal": observables,
        "host_calls_equal": host_equal,
        "instruction_accounting": accounted,
        "aot_instructions": aot.get("aot_instructions"),
        "interpreter_fallback_instructions": aot.get("interpreter_instructions"),
        "fallback_count": aot.get("fallback_count"),
        "fallback_reason_counts": dict(sorted(fallback_counts.items())),
        "fallback_log_accounting": fallback_accounting,
        "boundary_count": aot.get("boundary_count"),
        "aot_coverage": (aot.get("aot_instructions", 0) /
                         interpreter["interpreter_instructions"] if interpreter.get("interpreter_instructions") else 0),
        "semantic_pass": bool(source_identity and generated_identity and
                              not manifest["execution_trace_input"] and
                              interpreter.get("passed") and aot.get("passed") and
                              all(observables.values()) and host_equal and
                              checkpoints and mismatch is None and accounted and fallback_accounting),
    }
    (evidence / "differential.json").write_text(json.dumps(result, indent=2) + "\n", encoding="utf-8")
    print(json.dumps(result, indent=2))
    return 0 if result["semantic_pass"] else 1


if __name__ == "__main__":
    raise SystemExit(main())
