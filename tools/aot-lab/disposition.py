#!/usr/bin/env python3
"""Compare the interpreter trace with the AOT run and record the measured result."""

import json
import pathlib
import sys


def rows(path):
    parsed = []
    for line in pathlib.Path(path).read_text(encoding="utf-8").splitlines():
        if line.strip():
            parsed.append([int(item) for item in line.split()])
    return parsed


def main():
    evidence = pathlib.Path(sys.argv[1])
    interpreter = json.loads((evidence / "interpreter-result.json").read_text(encoding="utf-8"))
    aot = json.loads((evidence / "aot-result.json").read_text(encoding="utf-8"))
    hosts_a = (evidence / "interpreter-hosts.txt").read_text(encoding="utf-8").splitlines()
    hosts_b = (evidence / "aot-hosts.txt").read_text(encoding="utf-8").splitlines()
    trace = rows(evidence / "interpreter-trace.txt")
    checkpoints = rows(evidence / "aot-checkpoints.txt") if (evidence / "aot-checkpoints.txt").exists() else []
    manifest = json.loads((evidence / "translation-manifest.json").read_text(encoding="utf-8"))
    guest_rows = [row for row in trace if row[3] or (row[1] & 0xff000000) != 0xef000000]
    cursor = 0
    checkpoint_mismatches = []
    for checkpoint in checkpoints:
        pc = checkpoint[0]
        while cursor < len(trace) and trace[cursor][0] != pc:
            cursor += 1
        if cursor >= len(trace) or len(trace[cursor]) < 21 or len(checkpoint) < 18:
            checkpoint_mismatches.append({"pc": pc, "reason": "missing-interpreter-checkpoint"})
            break
        observed = trace[cursor]
        if observed[4] != checkpoint[1] or observed[5:20] != checkpoint[2:17]:
            checkpoint_mismatches.append({"pc": pc, "reason": "register-or-cpsr"})
            break
        cursor += 1
    same_hosts = hosts_a == hosts_b
    same_frame = interpreter.get("framebuffer_fnv") == aot.get("framebuffer_fnv")
    same_pixels = interpreter.get("nonblack_pixels") == aot.get("nonblack_pixels")
    fallback = int(aot.get("fallback_count") or 0)
    translated = int(aot.get("aot_instructions") or 0)
    executed_blocks = int(aot.get("aot_blocks") or 0)
    semantic = bool(
        interpreter.get("passed") and aot.get("passed") and same_hosts and same_frame
        and same_pixels and fallback == 0 and translated == len(guest_rows)
        and executed_blocks == len(checkpoints) and executed_blocks > 0
        and not checkpoint_mismatches)
    base = float(interpreter.get("seconds") or 0)
    fast = float(aot.get("seconds") or 0)
    base_boundary = float(interpreter.get("boundary_seconds") or 0)
    fast_boundary = float(aot.get("boundary_seconds") or 0)
    summary = {
        "semantic_pass": semantic,
        "hosts_equal": same_hosts,
        "host_calls": len(hosts_a),
        "framebuffer_equal": same_frame,
        "nonblack_equal": same_pixels,
        "checkpoint_mismatches": checkpoint_mismatches,
        "fallback_count": fallback,
        "boundary_count": int(aot.get("boundary_count") or 0),
        "translated_blocks": len(manifest.get("blocks") or []),
        "executed_blocks": executed_blocks,
        "interpreter_guest_instructions": len(guest_rows),
        "aot_instructions": translated,
        "thumb_instructions": manifest.get("thumb_instructions"),
        "arm_instructions": manifest.get("arm_instructions"),
        "vfp_instructions": manifest.get("vfp_instructions"),
        "interpreter_seconds": base,
        "aot_seconds": fast,
        "interpreter_boundary_seconds": base_boundary,
        "aot_boundary_seconds": fast_boundary,
        "interpreter_arm_seconds": base - base_boundary,
        "aot_arm_seconds": fast - fast_boundary,
        "wall_clock_speedup": (base / fast) if fast else 0,
        "miss_pc": aot.get("miss_pc"),
        "framebuffer_fnv": aot.get("framebuffer_fnv"),
        "nonblack_pixels": aot.get("nonblack_pixels"),
    }
    (evidence / "differential.json").write_text(json.dumps(summary, indent=2) + "\n", encoding="utf-8", newline="\n")
    print(json.dumps(summary, indent=2))
    raise SystemExit(0 if semantic else 1)


if __name__ == "__main__":
    main()
