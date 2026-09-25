#!/usr/bin/env python3
"""Recreate ordered events from a pinned direct TRACE file, preserving lineage."""

import argparse
import hashlib
import json
from pathlib import Path

from parse_trace_log import parse_lines


def sha256(path):
    digest = hashlib.sha256()
    with path.open("rb") as stream:
        for chunk in iter(lambda: stream.read(1024 * 1024), b""):
            digest.update(chunk)
    return digest.hexdigest()


def rebuild(direct, old_events, old_evidence, probe, out_events, out_evidence):
    evidence = json.loads(old_evidence.read_text())
    runtime = json.loads(probe.read_text())
    expected_direct = evidence.get("direct_trace_sha256", {}).get(direct.name)
    if not expected_direct or sha256(direct) != expected_direct:
        raise ValueError("direct TRACE file hash differs from run evidence")
    old_hash = sha256(old_events)
    if old_hash != evidence.get("events_sha256"):
        raise ValueError("original event file hash differs from run evidence")
    pids = evidence.get("process_ids")
    if not pids or runtime.get("status") != "PASS" or \
            runtime.get("apk_sha256") != evidence.get("apk_sha256"):
        raise ValueError("run identity or process list is invalid")
    with direct.open(errors="replace") as stream:
        events = parse_lines(stream, allowed_pids=set(pids))
    if len(events) != runtime.get("event_count"):
        raise ValueError("reprocessed event count differs from passing probe")
    out_events.parent.mkdir(parents=True, exist_ok=True)
    out_events.write_text("".join(json.dumps(event, sort_keys=True) + "\n"
                                  for event in events))
    updated = dict(evidence)
    updated["events_sha256"] = sha256(out_events)
    updated["reprocessing"] = {
        "reason": "restore sequence fields from original direct v2 records",
        "original_events_sha256": old_hash,
        "direct_trace_sha256": expected_direct,
        "new_game_process_event_count": len(events),
    }
    out_evidence.write_text(json.dumps(updated, indent=2) + "\n")
    return len(events)


def main():
    parser = argparse.ArgumentParser()
    for name in ("direct", "old-events", "old-evidence", "probe",
                 "out-events", "out-evidence"):
        parser.add_argument("--" + name, required=True, type=Path)
    args = parser.parse_args()
    count = rebuild(args.direct, args.old_events, args.old_evidence,
                    args.probe, args.out_events, args.out_evidence)
    print(f"reprocessed {count} game-process events with sequence fields")


if __name__ == "__main__":
    main()
