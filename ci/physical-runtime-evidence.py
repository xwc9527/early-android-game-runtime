#!/usr/bin/env python3
"""Recover a physical-device run from durable trace files.

The final runtime JSON may be missing. A truncated last NDJSON line is ignored.
A crash marker is optional. This does not declare physical Runtime closure.
"""

import argparse
import json
import pathlib
import struct
import sys

TRACE_NAME = "agr-physical-trace.ndjson"
RUN_NAME = "agr-physical-run.json"
FINAL_NAME = "agr-physical-runtime.json"
CRASH_NAME = "agr-physical-crash.bin"
CRASH_MAGIC = b"AGRCRSH1"
# magic, version, signal, last_phase, last_exec, has_exec, canvas_locked,
# lock_owner, lock, unlock, post, draw, pixels, generation, surface_valid,
# thread_state, last_seq, host_thread, surface_identity
# Packed image: magic, version, signal, 13 uint32 fields, 3 uint64 fields.
CRASH_STRUCT = struct.Struct("<8sIi" + "I" * 13 + "QQQ")

THREAD_STATE = {0: "NONE", 1: "STARTING", 2: "RUNNING", 3: "WAITING", 4: "TERMINATED"}


def load_json(path):
    if not path.is_file():
        return None
    try:
        return json.loads(path.read_text(encoding="utf-8"))
    except (OSError, json.JSONDecodeError):
        return None


def load_trace(path):
    events = []
    truncated = False
    if not path.is_file():
        return events, truncated
    raw = path.read_bytes()
    lines = raw.splitlines()
    for index, line in enumerate(lines):
        if not line.strip():
            continue
        try:
            events.append(json.loads(line.decode("utf-8")))
        except (UnicodeDecodeError, json.JSONDecodeError):
            if index == len(lines) - 1:
                truncated = True
            else:
                truncated = True
    return events, truncated


def load_crash(path):
    if not path.is_file():
        return None
    data = path.read_bytes()
    if len(data) < CRASH_STRUCT.size:
        return None
    fields = CRASH_STRUCT.unpack_from(data)
    if fields[0] != CRASH_MAGIC:
        return None
    ints = fields[1:16]
    quads = fields[16:19]
    return {
        "version": ints[0],
        "signal": ints[1],
        "last_phase": ints[2],
        "last_exec": ints[3],
        "has_exec": ints[4],
        "canvas_locked": ints[5],
        "lock_owner_exec": ints[6],
        "lock_count": ints[7],
        "unlock_count": ints[8],
        "post_count": ints[9],
        "draw_bitmap_count": ints[10],
        "pixel_change_count": ints[11],
        "generation": ints[12],
        "surface_valid": ints[13],
        "thread_state": ints[14],
        "last_seq": quads[0],
        "host_thread": quads[1],
        "surface_identity": quads[2],
    }


def phase_seen(events, name):
    return any(event.get("phase") == name or event.get("event") == name for event in events)


def last_phase(events, name):
    found = None
    for event in events:
        if event.get("phase") == name or event.get("event") == name:
            found = event
    return found


def counter_value(final, events, name):
    source = final if isinstance(final, dict) and name in final else (events[-1] if events else {})
    try:
        return int(source.get(name) or 0)
    except (TypeError, ValueError):
        return 0


def classify(events, final, crash):
    if crash and crash.get("signal"):
        return "NATIVE_CRASH"
    if phase_seen(events, "APK_LOCATE_FAIL") or phase_seen(events, "APK_SHA_FAIL") or phase_seen(events, "APK_OPEN_FAIL"):
        if not phase_seen(events, "APK_OPEN_OK"):
            return "FAIL_BEFORE_APK_OPEN"
    if phase_seen(events, "GAME_CREATE_FAIL") and not phase_seen(events, "GAME_CREATE_OK"):
        return "FAIL_GAME_CREATE"
    if phase_seen(events, "ACTIVITY_START_FAIL") and not phase_seen(events, "ACTIVITY_START_OK"):
        return "FAIL_ACTIVITY_START"
    reason = ""
    if isinstance(final, dict):
        reason = str(final.get("termination_reason") or final.get("final_state") or "")
    posted = reason == "CONTENT_POSTED" or (
        phase_seen(events, "CANVAS_POST_END") and isinstance(final, dict) and final.get("content_posted") == "YES"
    )
    if posted and not (crash and crash.get("signal")):
        lock_count = counter_value(final, events, "lock_count")
        unlock_count = counter_value(final, events, "unlock_count")
        post_count = counter_value(final, events, "post_count")
        draw_count = counter_value(final, events, "draw_bitmap_count")
        pixel_count = counter_value(final, events, "pixel_change_count")
        if lock_count > 0 and unlock_count > 0 and post_count > 0 and draw_count > 0 and pixel_count > 0:
            return "PHYSICAL_PASS"
        if post_count > 0 and (draw_count == 0 or pixel_count == 0):
            return "CONTENT_POSTED_WITHOUT_DRAW"
    last = events[-1] if events else {}
    canvas_locked = bool(last.get("canvas_locked"))
    lock_count = int(last.get("lock_count") or 0)
    unlock_count = int(last.get("unlock_count") or 0)
    stalled = phase_seen(events, "WATCHDOG_STALL") or phase_seen(events, "WATCHDOG_NO_PROGRESS_8S") or reason == "WATCHDOG_STALL"
    if (canvas_locked or lock_count > unlock_count) and not phase_seen(events, "CANVAS_POST_END"):
        if stalled or final is None:
            return "STALL_CANVAS_LOCKED"
    if (phase_seen(events, "DRAW_BITMAP_END") or phase_seen(events, "CANVAS_POST_BEGIN")) and not phase_seen(events, "CANVAS_POST_END"):
        if stalled or final is None:
            return "STALL_BEFORE_POST"
    if phase_seen(events, "THREAD_RUN_ENTER") and not phase_seen(events, "THREAD_RUN_EXIT") and stalled:
        return "STALL_GAME_THREAD"
    if phase_seen(events, "TRAVERSAL_BEGIN") and not phase_seen(events, "TRAVERSAL_END") and stalled:
        return "STALL_IN_TRAVERSAL"
    if phase_seen(events, "ACTIVITY_START_OK") and not phase_seen(events, "SURFACE_CREATED") and stalled:
        return "STALL_BEFORE_SURFACE"
    if phase_seen(events, "ACTIVITY_START_OK") and not phase_seen(events, "PHYSICAL_FRAME_END") and stalled:
        return "STALL_BEFORE_FIRST_FRAME"
    if final is None:
        return "EVIDENCE_INCOMPLETE"
    return "EVIDENCE_INCOMPLETE"


def termination_surfaces(run, events, final):
    run_state = ""
    if isinstance(run, dict) and isinstance(run.get("state"), str):
        run_state = run["state"]
    finalize = last_phase(events, "FINALIZE_END") or last_phase(events, "FINALIZE_BEGIN")
    finalize_reason = ""
    if isinstance(finalize, dict) and isinstance(finalize.get("detail"), str):
        finalize_reason = finalize["detail"]
    final_reason = ""
    if isinstance(final, dict):
        final_reason = str(final.get("termination_reason") or final.get("final_state") or "")
    authoritative = finalize_reason or final_reason
    if not authoritative and run_state not in ("", "RUNNING"):
        authoritative = run_state
    consistent = True
    if finalize_reason:
        if run_state and run_state != finalize_reason:
            consistent = False
        if final_reason and final_reason != finalize_reason:
            consistent = False
    elif final_reason and run_state not in ("", "RUNNING") and run_state != final_reason:
        consistent = False
    return authoritative, run_state, finalize_reason, consistent


def identity_ok(run, events):
    if not isinstance(run, dict):
        return False
    run_id = run.get("run_id")
    commit = run.get("commit")
    tree = run.get("tree")
    if not run_id or not commit or not tree:
        return False
    for event in events:
        if event.get("run_id") != run_id or event.get("commit") != commit or event.get("tree") != tree:
            return False
    return True


def summarize(directory):
    root = pathlib.Path(directory)
    run = load_json(root / RUN_NAME)
    events, truncated = load_trace(root / TRACE_NAME)
    final = load_json(root / FINAL_NAME)
    crash = load_crash(root / CRASH_NAME)
    last = events[-1] if events else {}
    seqs = [int(event.get("seq") or 0) for event in events]
    monotonic = all(seqs[i] < seqs[i + 1] for i in range(len(seqs) - 1))
    termination_reason, run_state, finalize_reason, termination_consistent = termination_surfaces(
        run, events, final)
    game = last_phase(events, "THREAD_RUN_ENTER") or last_phase(events, "THREAD_START") or last_phase(events, "CANVAS_LOCK_ACQUIRED")
    stage = ""
    for event in events:
        if event.get("phase") == "ACTIVITY_STAGE" and event.get("activity_stage"):
            stage = event.get("activity_stage")
        elif event.get("phase") == "ACTIVITY_STAGE" and event.get("detail"):
            stage = event.get("detail")
    summary = {
        "identity_valid": identity_ok(run, events),
        "run_id": None if not isinstance(run, dict) else run.get("run_id"),
        "commit": None if not isinstance(run, dict) else run.get("commit"),
        "tree": None if not isinstance(run, dict) else run.get("tree"),
        "architecture": None if not isinstance(run, dict) else run.get("architecture"),
        "device_platform": None if not isinstance(run, dict) else run.get("device_platform"),
        "last_durable_seq": seqs[-1] if seqs else (crash.get("last_seq") if crash else 0),
        "last_event": last.get("event") or last.get("phase") or "",
        "last_phase": last.get("phase") or "",
        "sequence_monotonic": monotonic,
        "truncated_final_line": truncated,
        "last_exec": game.get("exec_id") if game else (crash.get("last_exec") if crash else None),
        "last_host_thread": game.get("host_thread_id") if game else (crash.get("host_thread") if crash else None),
        "thread_state": THREAD_STATE.get(int(game.get("thread_state") or 0), "NONE") if game else "NONE",
        "activity_stage": stage,
        "surface_valid": bool(last.get("surface_valid")),
        "surface_identity": last.get("surface_identity"),
        "canvas_locked": bool(last.get("canvas_locked")),
        "lock_owner_exec": last.get("lock_owner_exec"),
        "lock_count": last.get("lock_count"),
        "unlock_count": last.get("unlock_count"),
        "post_count": last.get("post_count"),
        "draw_bitmap_count": last.get("draw_bitmap_count"),
        "pixel_change_count": last.get("pixel_change_count"),
        "crash_marker": crash,
        "stall": phase_seen(events, "WATCHDOG_STALL") or phase_seen(events, "WATCHDOG_NO_PROGRESS_8S"),
        "final_json_present": final is not None,
        "final_json_missing": final is None,
        "classification": classify(events, final, crash),
        "event_count": len(events),
        "termination_reason": termination_reason,
        "run_state": run_state,
        "finalize_reason": finalize_reason,
        "termination_consistent": termination_consistent,
    }
    if crash and crash.get("last_seq") and (not seqs or crash["last_seq"] >= seqs[-1]):
        summary["last_durable_seq"] = crash["last_seq"]
        summary["last_phase_id"] = crash.get("last_phase")
    return summary


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--dir", required=True)
    parser.add_argument("--summary")
    args = parser.parse_args()
    summary = summarize(args.dir)
    text = json.dumps(summary, indent=2, sort_keys=True)
    if args.summary:
        pathlib.Path(args.summary).write_text(text + "\n", encoding="utf-8")
    sys.stdout.write(text + "\n")
    return 0


if __name__ == "__main__":
    sys.exit(main())
