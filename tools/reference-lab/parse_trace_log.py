#!/usr/bin/env python3
"""Turn API19 AGRTRACE logcat records into checked Mapper events."""

import argparse
import json
import re
from pathlib import Path

MARKER = "AGRTRACE|v1|"
PREFIX = re.compile(r"^\S+\s+\S+\s+(\d+)\s+(\d+)\s+")


def parse_lines(lines):
    events = []
    sequences = {}
    for line_number, line in enumerate(lines, 1):
        if "AGRTRACE|" not in line:
            continue
        if MARKER not in line:
            raise ValueError(f"unsupported TRACE record at line {line_number}")
        prefix, _, payload = line.partition(MARKER)
        match = PREFIX.match(prefix)
        if match is None:
            raise ValueError(f"TRACE log lacks threadtime pid at line {line_number}")
        pid, tid = map(int, match.groups())
        fields = payload.rstrip("\r\n").split("|")
        if len(fields) != 7:
            raise ValueError(f"truncated TRACE record at line {line_number}")
        seq, caller, dex_pc, opcode, method_idx, target, resolved = fields
        seq = int(seq)
        expected = sequences.get(pid, 0) + 1
        if seq != expected:
            raise ValueError(f"TRACE sequence gap for pid {pid}: expected {expected}, got {seq}")
        sequences[pid] = seq
        if not all((caller, target, resolved)) or "->" not in target:
            raise ValueError(f"invalid TRACE method at line {line_number}")
        events.append({
            "kind": "JAVA_METHOD", "canonical_name": target,
            "caller": caller, "dex_pc": int(dex_pc), "opcode": int(opcode),
            "method_idx": -1 if int(method_idx) == 0xffffffff else int(method_idx),
            "resolved_callee": resolved, "process_id": pid, "thread_id": tid,
        })
    if not events:
        raise ValueError("no AGRTRACE method events found")
    return events


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--logcat", required=True, type=Path)
    parser.add_argument("--events", required=True, type=Path)
    args = parser.parse_args()
    events = parse_lines(args.logcat.read_text(errors="replace").splitlines())
    args.events.parent.mkdir(parents=True, exist_ok=True)
    args.events.write_text("".join(json.dumps(event, sort_keys=True) + "\n" for event in events))
    print(f"{len(events)} method observations from {len(set(e['process_id'] for e in events))} processes")


if __name__ == "__main__":
    main()
