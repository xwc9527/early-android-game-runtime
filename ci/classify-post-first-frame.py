#!/usr/bin/env python3
"""Classify bounded zero-input observation; never infer an Android root cause."""
import argparse
import json
from pathlib import Path


def classify(report):
    checkpoints = report.get("post_first_frame_checkpoints", [])
    if report.get("observation_mode") != "POST_FIRST_FRAME_ZERO_INPUT":
        raise ValueError("wrong observation mode")
    if report.get("stop_reason") not in ("POST_FIRST_FRAME_DEADLINE", "RUNTIME_ERROR", "WATCHDOG_STALL"):
        raise ValueError("unexpected observation termination")
    first, last = (checkpoints[0], checkpoints[-1]) if checkpoints else ({}, {})
    if report.get("stop_reason") == "RUNTIME_ERROR" or report.get("runtime_error") or last.get("pending_exception") or last.get("vm_error"):
        state = "RUNTIME_FAILURE"
    elif len(checkpoints) < 3:
        state = "INSUFFICIENT_CHECKPOINTS"
    elif last.get("posts", 0) > first.get("posts", 0):
        state = "PRODUCER_CONTINUES"
    elif last.get("instructions", 0) > first.get("instructions", 0) or last.get("methods", 0) > first.get("methods", 0):
        state = "GUEST_PROGRESS_WITHOUT_NEW_POST"
    else:
        state = "NO_MEASURED_PROGRESS"
    return {
        "schema": "agr.post-first-frame-observation.v1",
        "commit": report.get("commit"),
        "tree": report.get("tree"),
        "apk_sha256": report.get("apk_sha256"),
        "observation_mode": report["observation_mode"],
        "observation_state": state,
        "raw_stop_reason": report.get("stop_reason"),
        "watchdog_progress_conflict": report.get("stop_reason") == "WATCHDOG_STALL" and state == "PRODUCER_CONTINUES",
        "trace_capacity_reached": bool(report.get("trace_capacity_reached")),
        "trace_events_omitted": report.get("trace_events_omitted", 0),
        "checkpoint_count": len(checkpoints),
        "first": first,
        "last": last,
        "host_submissions_final": report.get("host_surface_submissions"),
        "runtime_error": report.get("runtime_error"),
    }


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("report")
    parser.add_argument("--output", required=True)
    args = parser.parse_args()
    result = classify(json.loads(Path(args.report).read_text(encoding="utf-8")))
    Path(args.output).write_text(json.dumps(result, indent=2) + "\n", encoding="utf-8")
    print(json.dumps(result, sort_keys=True))


if __name__ == "__main__":
    main()
