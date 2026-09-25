#!/usr/bin/env python3
"""Reparse a preserved TRACE stream across every observed game-process PID."""

import argparse
import hashlib
import json
from pathlib import Path

from parse_trace_log import parse_lines
from probe_pair import app_crash_lines


def sha256(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def finalize(directory, recover_collector_timeout=False):
    record_path = directory / "probe.json"
    record = json.loads(record_path.read_text())
    if record.get("variant") != "TRACE" or record.get("pair_status") != "BUILD_VERIFIED":
        raise ValueError("TRACE run is not a successful verified-pair probe")
    recovering = record.get("status") == "FAILED" and recover_collector_timeout
    if recovering:
        if record.get("stage") != "action_7_relaunch" or \
                "logcat" not in record.get("error", "") or \
                "timed out after 90 seconds" not in record.get("error", ""):
            raise ValueError("failed run is not the known logcat collector timeout")
        if len(record.get("steps", [])) != 9 or \
                record["steps"][-1]["label"] != "07-relaunch":
            raise ValueError("lifecycle scenario was not fully captured")
        clean_path = (directory.parents[2] / "clean" / directory.parent.name /
                      directory.name / "probe.json")
        clean = json.loads(clean_path.read_text())
        fields = ("apk_sha256", "scenario", "arch", "execution_mode", "vm_config",
                  "jit_effective", "gpu_mode", "show_window", "data_reused", "accel",
                  "zygote_preload", "zygote_loaded_libraries", "actions_sha256",
                  "trace_sink_prep", "force_stop_policy")
        if clean.get("status") != "PASS" or \
                any(clean.get(field) != record.get(field) for field in fields):
            raise ValueError("matched CLEAN run or runtime configuration differs")
    elif record.get("status") != "PASS":
        raise ValueError("TRACE run is not a successful verified-pair probe")
    pids = {step["process"]["pid"] for step in record["steps"]
            if step["process"]["alive"]}
    if not pids:
        raise ValueError("TRACE run has no observed game-process PID")
    direct_files = sorted((directory / "trace-direct").glob("trace-*.log"))
    log_path = (directory / "trace-guest.logcat" if
                (directory / "trace-guest.logcat").is_file() else
                directory / "trace.logcat")
    logcat = ("".join(path.read_text(errors="replace") for path in direct_files)
              if direct_files else log_path.read_text(errors="replace"))
    if recovering:
        record["app_crash_lines"] = app_crash_lines(logcat, record["package"], pids)
        if record["app_crash_lines"]:
            raise ValueError("game crash observed in the preserved TRACE stream")
    events = parse_lines(logcat.splitlines(),
                         allowed_pids=pids)
    events_path = directory / "events.ndjson"
    events_path.write_text("".join(json.dumps(event, sort_keys=True) + "\n"
                                   for event in events))
    evidence_path = directory / "trace-run.json"
    if recovering:
        evidence = {"variant": "TRACE", "instrumented": True,
                    "role": "dependency_mapper", "baseline": "android-4.4.4_r2",
                    "image_sha256": record["image_sha256"],
                    "apk_sha256": record["apk_sha256"],
                    "scenario": record["scenario"],
                    "observer_coverage": ["APP_DEX_TO_BOOT_METHOD_INVOKE"],
                    "observation_scope": "APP_TRIGGERED_OBSERVED_LOWER_BOUND",
                    "zygote_preload_sha256": sha256(directory / "zygote-preload.json"),
                    "runtime_config": record["vm_config"],
                    "may_authorize_pruning": False}
    else:
        evidence = json.loads(evidence_path.read_text())
    if evidence.get("apk_sha256") != record["apk_sha256"] or \
            evidence.get("image_sha256") != record["image_sha256"]:
        raise ValueError("TRACE run evidence identity differs from probe")
    evidence["process_ids"] = sorted(pids)
    evidence.pop("process_id", None)
    evidence["streamed_logcat_sha256"] = sha256(directory / "trace.logcat")
    if log_path.name == "trace-guest.logcat":
        evidence["guest_logcat_sha256"] = sha256(log_path)
    if direct_files:
        evidence["direct_trace_sha256"] = {path.name: sha256(path)
                                           for path in direct_files}
        evidence["trace_transport"] = "guest_precreated_direct_file_v2"
    evidence["events_sha256"] = sha256(events_path)
    evidence_path.write_text(json.dumps(evidence, indent=2) + "\n")
    record["event_count"] = len(events)
    record["trace_process_ids"] = sorted(pids)
    if recovering:
        record["collector_error"] = record.pop("error")
        record["recovery_source"] = "preserved_stream_after_snapshot_timeout"
        record["status"] = "PASS"
        record["stage"] = "complete"
    record_path.write_text(json.dumps(record, indent=2) + "\n")
    return len(events)


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--run", required=True, type=Path)
    parser.add_argument("--recover-collector-timeout", action="store_true")
    args = parser.parse_args()
    print(json.dumps({"event_count": finalize(args.run, args.recover_collector_timeout)}))


if __name__ == "__main__":
    main()
