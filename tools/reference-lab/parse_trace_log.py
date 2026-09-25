#!/usr/bin/env python3
"""Turn API19 AGRTRACE logcat records into checked Mapper events."""

import argparse
import json
import re
from pathlib import Path

MARKER_V1 = "AGRTRACE|v1|"
MARKER_V2 = "AGRTRACE|v2|"
PREFIX = re.compile(r"^\S+\s+\S+\s+(\d+)\s+(\d+)\s+")


def parse_lines(lines, allowed_pids=None):
    events = []
    sequences = {}
    for line_number, line in enumerate(lines, 1):
        if "AGRTRACE|" not in line:
            continue
        if MARKER_V1 not in line and MARKER_V2 not in line:
            raise ValueError(f"unsupported TRACE record at line {line_number}")
        if MARKER_V2 in line:
            _, _, payload = line.partition(MARKER_V2)
            fields = payload.rstrip("\r\n").split("|")
            if len(fields) != 9:
                raise ValueError(f"truncated TRACE record at line {line_number}")
            pid, tid = map(int, fields[:2])
            fields = fields[2:]
        else:
            prefix, _, payload = line.partition(MARKER_V1)
            match = PREFIX.match(prefix)
            if match is None:
                raise ValueError(f"TRACE log lacks threadtime pid at line {line_number}")
            pid, tid = map(int, match.groups())
            fields = payload.rstrip("\r\n").split("|")
        if allowed_pids is not None and pid not in allowed_pids:
            continue
        if len(fields) != 7:
            raise ValueError(f"truncated TRACE record at line {line_number}")
        seq, caller, dex_pc, opcode, method_idx, target, resolved = fields
        seq = int(seq)
        seen = sequences.setdefault(pid, set())
        if seq in seen:
            raise ValueError(f"duplicate TRACE sequence for pid {pid}: {seq}")
        seen.add(seq)
        if not all((caller, target, resolved)) or "->" not in target:
            raise ValueError(f"invalid TRACE method at line {line_number}")
        events.append({
            "kind": "JAVA_METHOD", "canonical_name": target,
            "caller": caller, "dex_pc": int(dex_pc), "opcode": int(opcode),
            "method_idx": -1 if int(method_idx) == 0xffffffff else int(method_idx),
            "resolved_callee": resolved, "process_id": pid, "thread_id": tid,
            "sequence": seq,
        })
    if not events:
        raise ValueError("no AGRTRACE method events found")
    # Sequence is reserved before ALOGI, so simultaneous threads may reach
    # logcat in a different order. Completeness is a set property per process.
    for pid, seen in sequences.items():
        maximum = max(seen)
        if len(seen) != maximum or min(seen) != 1:
            missing = next(number for number in range(1, maximum + 1)
                           if number not in seen)
            raise ValueError(f"TRACE sequence gap for pid {pid}: missing {missing}")
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
