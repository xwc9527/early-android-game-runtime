#!/usr/bin/env python3
"""Focused contract tests for physical evidence identity and draw-boundary classification."""

import importlib.util
import contextlib
import hashlib
import json
import pathlib
import secrets
import shutil
import subprocess
import sys
import tempfile

SCRIPT = pathlib.Path(__file__).resolve().parents[2] / "ci" / "physical-runtime-evidence.py"
spec = importlib.util.spec_from_file_location("physical_runtime_evidence", SCRIPT)
evidence = importlib.util.module_from_spec(spec)
spec.loader.exec_module(evidence)
CHAIN_SCRIPT = pathlib.Path(__file__).resolve().parents[2] / "ci" / "physical-bitmap-chain-contract.py"
chain_spec = importlib.util.spec_from_file_location("physical_bitmap_chain_contract", CHAIN_SCRIPT)
chain_contract = importlib.util.module_from_spec(chain_spec)
chain_spec.loader.exec_module(chain_contract)

RUN_ID = "run-001"
LAUNCH_ID = "launch-001"
COMMIT = "abc123"
TREE = "def456"
PID = 1234
START = "2026-09-23T02:00:00.123Z"
START_MONO = 123456789
APK = evidence.EXPECTED_APK_SHA256


@contextlib.contextmanager
def temporary_test_directory():
    if not sys.platform.startswith("win"):
        with tempfile.TemporaryDirectory() as path:
            yield path
        return
    parent = pathlib.Path(__file__).resolve().parents[2] / "build"
    parent.mkdir(exist_ok=True)
    path = parent / ("physical-evidence-test-" + secrets.token_hex(12))
    path.mkdir()
    try:
        yield str(path)
    finally:
        if path.resolve().parent != parent.resolve():
            raise AssertionError("test cleanup escaped workspace build directory")
        shutil.rmtree(path)


def environment():
    return {
        "target_type": "physical_device",
        "os": {"system_version": "26.3.1", "os_build": "23D"},
        "hardware": {"hw_machine": "iPhone99,1", "architecture": "arm64", "page_size": 16384,
                     "logical_cpu_count": 6, "physical_memory": 8000000000},
        "display": {"logical_width": 402, "logical_height": 874, "native_width": 1206,
                    "native_height": 2622, "scale": 3, "native_scale": 3, "maximum_fps": 60,
                    "runtime_host_width": 1206, "runtime_host_height": 2622},
        "graphics": {"device_name": "Apple GPU"},
        "power": {"thermal_state": "NOMINAL", "low_power_mode_enabled": False,
                  "battery_monitoring_available": True},
        "lifecycle": {"state": "ACTIVE", "active": True},
        "process": {"environment_target": "iphoneos"},
        "app": {"bundle_id": "dev.agr.simulator"},
        "binaries": [{"role": role, "uuid": role + "-uuid", "sha256": role + "-sha"}
                     for role in ("executable", "libEGL", "libGLESv2")],
        "build_environment": {"branch": "phase/test", "commit": COMMIT, "tree": TREE,
                              "xcode": "Xcode 26", "sdk_name": "iphoneos", "sdk_version": "26.0",
                              "deployment_target": "15.0", "angle_version": "v2.1.28252",
                              "angle_identity": "angle-sha", "interpreter_build_identity": "rust-arm64"},
        "simulator": {"physical_target_os": "26.3.1 (a)", "runtime_requested": "iOS-26-3",
                      "runtime_actual": "iOS-26-3", "runtime_version": "26.3",
                      "os_version_parity": "SAME_26_3_MINOR", "device_type": "iPhone 16 Pro"},
    }


def run_record():
    return {"run_id": RUN_ID, "process_launch_id": LAUNCH_ID, "pid": PID,
            "process_start_wall_time": START, "process_start_monotonic_ns": START_MONO,
            "branch": "phase/test", "commit": COMMIT, "tree": TREE,
            "architecture": "arm64", "device_platform": "iphoneos",
            "apk_sha256_expected": APK, "apk_sha256_actual": APK,
            "environment": environment()}


def event(phase, **extra):
    value = {"run_id": RUN_ID, "process_launch_id": LAUNCH_ID,
             "commit": COMMIT, "tree": TREE, "seq": 1, "phase": phase,
             "event": phase, "detail": ""}
    value.update(extra)
    return value


def critical(method, phase, cls="Lsample/GameThread;"):
    return event("GUEST_METHOD_" + phase, method=method, **{"class": cls},
                 detail="CRITICAL;" + phase + ";V", guest_pc=0x1020, has_guest_pc=True,
                 exec_id=2, host_thread_id=200)


def complete_fixture():
    run = run_record()
    events = [
        event("APK_SHA_OK"),
        event("APK_OPEN_OK"),
        event("ACTIVITY_STAGE", detail="resumed", activity_stage="resumed"),
        event("SURFACE_CALLBACK_OK", method="surfaceCreated"),
        event("SURFACE_CREATED", created_count=1, changed_count=0),
        event("SURFACE_CALLBACK_OK", method="surfaceChanged"),
        event("SURFACE_CHANGED", created_count=1, changed_count=1),
        critical("setSurfaceSize", "ENTER"), critical("setSurfaceSize", "EXIT"),
        critical("resizeBitmaps", "ENTER"), critical("resizeBitmaps", "EXIT"),
        event("DIAGNOSTIC_FIELD_WITNESS", method="mImagesReady", detail="when=draw mImagesReady=1"),
        event("EXEC_PUBLISHED", exec_id=1, host_thread_id=100),
        event("THREAD_RUN_ENTER", exec_id=2, host_thread_id=200, thread_state=2),
        critical("<init>", "ENTER", "Lsample/FrozenGame;"),
        critical("<init>", "EXIT", "Lsample/FrozenGame;"),
        critical("doDraw", "ENTER"), critical("doDraw", "EXIT"),
        critical("drawBitmap", "ENTER", "Landroid/graphics/Canvas;"),
        event("VECTOR_SIZE", detail="size=1"), event("VECTOR_ELEMENT", detail="PenguinSprite"),
        event("PENGUIN_SPRITE_PAINT_WITNESS", detail="paint"),
        event("CANVAS_LOCK_ACQUIRED", lock_count=1),
        event("DRAW_BITMAP_END", draw_bitmap_count=1),
        event("PIXEL_MUTATION", pixel_change_count=1),
        event("CANVAS_POST_END", post_count=1),
    ]
    final = {
        "run_id": RUN_ID, "process_launch_id": LAUNCH_ID, "pid": PID,
        "process_start_wall_time": START, "process_start_monotonic_ns": START_MONO,
        "branch": "phase/test", "commit": COMMIT, "tree": TREE,
        "device_platform": "iphoneos", "architecture": "arm64",
        "apk_package": evidence.EXPECTED_PACKAGE, "apk_sha256": APK,
        "apk_sha256_expected": APK, "activity_launch_stage": "resumed", "activity_resumed": True,
        "game_thread_exec": 2, "surface_created": 1, "surface_changed": 1,
        "surface_callback_ok_count": 2, "content_surface_valid": True,
        "content_surface_identity": "22", "root_surface_identity": "11",
        "lock_count": 1, "unlock_count": 1, "post_count": 1,
        "draw_bitmap_count": 1, "pixel_change_count": 10,
        "hash_before": "abcd", "hash_after": "ef01", "vector_size": "1",
        "element_at_class": "PenguinSprite", "penguin_sprite_paint": True,
        "runtime_error": "", "vm_error": "", "pending_exception": False,
        "termination_reason": "CONTENT_POSTED",
        "environment_start": environment(),
        "environment_end": environment(),
        "environment_changed": [],
    }
    return run, events, final


def classify(run, events, final):
    return evidence.classify(events, run, final, None,
                             evidence.stage_states(run, events, final, None))


def check(condition, label):
    if not condition:
        raise AssertionError(label)


def main():
    run, events, final = complete_fixture()
    check(classify(run, events, final) == "CONTENT_POSTED_NO_HOST_CONSUMER",
          "a completed producer post is not a visible frame")
    submitted = events + [event("HOST_SURFACE_ACQUIRED"), event("HOST_SURFACE_SUBMITTED")]
    submitted_final = dict(final, host_surface_submissions=1)
    check(classify(run, submitted, submitted_final) == "HOST_SUBMITTED_SCREEN_UNVERIFIED",
          "host submission is distinct from physical screen presentation")

    wrong_final = dict(final, tree="different")
    check(classify(run, events, wrong_final) == "STALE_OR_MIXED_EVIDENCE", "final tree mismatch")
    wrong_commit = dict(final, commit="different")
    check(classify(run, events, wrong_commit) == "STALE_OR_MIXED_EVIDENCE", "final commit mismatch")
    wrong_event = list(events) + [event("RUNTIME_ERROR", process_launch_id="other-launch")]
    check(classify(run, wrong_event, final) == "STALE_OR_MIXED_EVIDENCE", "trace launch mismatch")
    wrong_apk = dict(final, apk_sha256="0" * 64)
    check(classify(run, events, wrong_apk) == "APK_IDENTITY_MISMATCH", "APK mismatch distinct")

    # Each missing strict gate must independently prevent a host-submitted result.
    for field, bad_value in (
        ("activity_resumed", False), ("content_surface_valid", False),
        ("content_surface_identity", "11"), ("pending_exception", True),
        ("runtime_error", "unexpected"), ("vector_size", ""),
        ("pixel_change_count", 0), ("hash_after", "abcd"),
    ):
        mutated = dict(final, **{field: bad_value})
        check(classify(run, submitted, dict(submitted_final, **{field: bad_value})) !=
              "HOST_SUBMITTED_SCREEN_UNVERIFIED", "strict gate " + field)
    no_paint = [e for e in events if e["phase"] != "PENGUIN_SPRITE_PAINT_WITNESS"]
    check(classify(run, no_paint, final) != "HOST_SUBMITTED_SCREEN_UNVERIFIED", "penguin witness required")

    prefix = [event("THREAD_RUN_ENTER", exec_id=2, host_thread_id=200),
              event("CANVAS_LOCK_ACQUIRED"), event("CANVAS_POST_END")]
    no_draw = [critical("doDraw", "ENTER"), critical("doDraw", "EXIT")]
    check(classify(run, prefix + no_draw, final | {"post_count": 1, "draw_bitmap_count": 0}) ==
          "DRAW_RETURNED_WITHOUT_CANVAS_OP", "doDraw returned before Canvas")
    canvas = critical("drawColor", "ENTER", "Landroid/graphics/Canvas;")
    check(classify(run, prefix + no_draw + [canvas], final | {"post_count": 1, "draw_bitmap_count": 0}) ==
          "DRAW_BITMAP_NOT_REACHED", "Canvas path without drawBitmap")
    check(classify(run, prefix, final | {"post_count": 1, "draw_bitmap_count": 0}) ==
          "DRAW_NOT_ENTERED", "doDraw not entered")
    check(classify(run, events, final | {"pixel_change_count": 0, "hash_after": "abcd"}) ==
          "DRAW_BITMAP_WITHOUT_PIXEL_MUTATION", "draw without pixel mutation")
    check(classify(run, [], final | {"post_count": 1, "draw_bitmap_count": 0}) ==
          "CONTENT_POSTED_WITHOUT_DRAW", "posted without draw thread witness")
    for phase, expected in (
        ("SURFACE_CALLBACK_THROW", "CALLBACK_THROW"),
        ("SURFACE_CALLBACK_EXEC_ERROR", "CALLBACK_EXEC_ERROR"),
        ("BITMAP_SCALE_FAIL", "BITMAP_SCALE_FAIL"),
        ("EVIDENCE_CHANNEL_FAILED", "EVIDENCE_CHANNEL_FAILED"),
        ("WATCHDOG_STALL", "WATCHDOG_STALL"),
        ("RUNTIME_ERROR", "RUNTIME_ERROR"),
    ):
        check(classify(run, [event(phase)], final) == expected, "classification " + expected)
    check(evidence.classify(events, run, final, {"signal": 6},
                            evidence.stage_states(run, events, final, {"signal": 6})) ==
          "NATIVE_SIGNAL_CRASH", "signal crash classification")

    missing = dict(final)
    missing.pop("process_start_monotonic_ns")
    check(classify(run, events, missing) != "HOST_SUBMITTED_SCREEN_UNVERIFIED", "process identity required")
    check(classify(run, events, None) == "ABRUPT_TERMINATION", "missing final report is abrupt termination")
    states = evidence.stage_states(run, events, final, None)
    for key in ("build_identity_confirmed", "current_run_identity_confirmed", "environment_captured",
                "apk_confirmed", "activity_confirmed", "game_thread_confirmed",
                "surface_callback_confirmed", "bitmap_preparation_confirmed",
                "draw_path_confirmed", "content_produced", "content_posted",
                "host_surface_acquired", "host_surface_submitted", "screen_presented"):
        check(key in states, "summary stage " + key)
    check(evidence.boundary_report(events, run, final)[1] == "HOST_SURFACE_ACQUIRED",
          "producer-only trace stops at host acquisition")
    check(evidence.boundary_report(submitted, run, submitted_final)[1] == "",
          "host-submitted trace completes the observable host boundary")
    missing_size_enter = [e for e in events if not (e.get("method") == "setSurfaceSize" and
                                                     e.get("phase") == "GUEST_METHOD_ENTER")]
    last_boundary, first_missing = evidence.boundary_report(missing_size_enter, run, final)
    check(last_boundary == "SURFACE_CHANGED" and first_missing == "GameThread.setSurfaceSize ENTER",
          "first missing causal boundary is retained")

    chain = [event("BITMAP_SCALE_FAIL", seq=40, object_identity=77, detail="src null"),
             event("SURFACE_CALLBACK_THROW", seq=41, method="surfaceChanged", detail="NullPointerException"),
             event("THREAD_RUN_ENTER", seq=42, exec_id=2, host_thread_id=200),
             event("CANVAS_POST_END", seq=43, post_count=3)]
    report = evidence.failure_chain(chain, run, dict(final, termination_reason="CONTENT_POSTED"))
    check(report["first_observed_failure"]["phase"] == "BITMAP_SCALE_FAIL",
          "first observed failure is retained")
    check(report["first_observed_failure_is_proven_cause"] is False,
          "first observed failure is not promoted to proven cause")
    check(report["direct_exception_or_callback_failure"]["method"] == "surfaceChanged",
          "callback method distinguishes surfaceChanged")
    check([e["phase"] for e in report["subsequent_guest_execution"]] ==
          ["THREAD_RUN_ENTER", "CANVAS_POST_END"], "later guest work survives earlier failure")
    check(report["final_stop_reason"] == "CONTENT_POSTED", "final stop does not overwrite failure chain")

    chain_summary = {
        "run_id": RUN_ID, "commit": COMMIT, "tree": TREE,
        "evidence_source": "current", "classification": "CONTENT_POSTED_WITHOUT_DRAW",
        "manifest_integrity_ok": True, "identity_valid": True, "truncated_final_line": False,
        "passive_dropped_count": 0,
        "environment_start": {"target_type": "simulator", "display": {
            "runtime_host_width": 1080, "runtime_host_height": 2340,
            "native_width": 1206, "native_height": 2622}},
        "bitmap_object_chain": [
            {"phase": "BITMAP_DECODE_WITNESS", "seq": 10, "exec_id": 1,
             "method": "decodeResource", "object_identity": 7, "resource_id": 100,
             "witness_flags": 56, "witness_status": 0},
            {"phase": "BITMAP_FIELD_WITNESS", "seq": 11, "exec_id": 1,
             "method": "bitmap", "object_identity": 8, "related_identity": 7},
            {"phase": "BITMAP_REFERENCE_WITNESS", "seq": 12, "exec_id": 1,
             "method": "getWidth", "object_identity": 7},
            {"phase": "BITMAP_REFERENCE_WITNESS", "seq": 13, "exec_id": 1,
             "method": "createScaledBitmap", "object_identity": 7,
             "witness_flags": 56, "detail": "scale_source"},
        ]}
    chain_result = chain_contract.build_result(chain_summary, 1080, 2340)
    check(chain_result["evidence_collection_valid"], "object-linked Bitmap witness contract")
    check(chain_result["scale_sources"][0]["matches_decode_return"] and
          chain_result["scale_sources"][0]["matches_bitmap_field_value"],
          "decoded object is correlated through field to scaling")
    derived_summary = json.loads(json.dumps(chain_summary))
    derived_summary["bitmap_object_chain"].extend([
        {"phase": "BITMAP_REFERENCE_WITNESS", "seq": 14, "exec_id": 1,
         "method": "createScaledBitmap", "object_identity": 9,
         "related_identity": 7, "detail": "scale_return_new_object"},
        {"phase": "BITMAP_REFERENCE_WITNESS", "seq": 15, "exec_id": 1,
         "method": "createScaledBitmap", "object_identity": 9,
         "detail": "scale_source"},
    ])
    derived_result = chain_contract.build_result(derived_summary, 1080, 2340)
    check(derived_result["first_missing_identity_link"] is None and
          derived_result["scale_sources"][-1]["matches_prior_scale_return"],
          "scaled Bitmap reused as source has a valid origin without a decode or field witness")
    chain_summary["bitmap_object_chain"][-1]["object_identity"] = 0
    null_chain = chain_contract.build_result(chain_summary, 1080, 2340)
    check(null_chain["first_missing_identity_link"] == "createScaledBitmap_received_null" and
          null_chain["causality_claimed"] is False,
          "null scale source remains an observation rather than a root-cause claim")

    # Exercise current, previous and legacy evidence exports on both hosts.
    # Windows uses an ACL-inheriting workspace directory for subprocess access.
    with temporary_test_directory() as temp:
            root = pathlib.Path(temp)
            bitmap_contract = pathlib.Path(__file__).resolve().parents[2] / "ci" / "physical-bitmap-chain-contract.py"
            valid_summary = root / "valid-bitmap-summary.json"
            valid_summary.write_text(json_dumps(chain_summary), encoding="utf-8")
            valid_cli = subprocess.run([sys.executable, str(bitmap_contract), str(valid_summary),
                                        "--output", str(root / "valid-bitmap-result.json"),
                                        "--width", "1080", "--height", "2340"],
                                       capture_output=True, text=True)
            check(valid_cli.returncode == 0, "bitmap witness CLI accepts valid evidence")
            invalid_summary = dict(chain_summary)
            invalid_summary["identity_valid"] = False
            invalid_path = root / "invalid-bitmap-summary.json"
            invalid_path.write_text(json_dumps(invalid_summary), encoding="utf-8")
            invalid_cli = subprocess.run([sys.executable, str(bitmap_contract), str(invalid_path),
                                          "--output", str(root / "invalid-bitmap-result.json"),
                                          "--width", "1080", "--height", "2340"],
                                         capture_output=True, text=True)
            check(invalid_cli.returncode == 1, "bitmap witness CLI rejects invalid evidence")

            docs = root / "documents"
            docs.mkdir()
            out = root / "export"
            payloads = {
                "run": json.dumps(run, sort_keys=True) + "\n",
                "trace": json.dumps(event("TRACE_READY")) + "\n",
                "runtime": json.dumps(final, sort_keys=True) + "\n",
            }
            manifest = {"schema": "agr.physical-manifest.v1", "run_id": RUN_ID,
                        "process_launch_id": LAUNCH_ID, "commit": COMMIT, "tree": TREE,
                        "archive_state": "CURRENT", "evidence_complete": True, "files": {}}
            for key, body in payloads.items():
                name = evidence.CURRENT_NAMES[key]
                (docs / name).write_text(body, encoding="utf-8")
                raw = (docs / name).read_bytes()
                manifest["files"][key] = {"name": name, "state": "PRESENT", "size": len(raw),
                                          "sha256": hashlib.sha256(raw).hexdigest()}
            manifest["files"]["crash"] = {"name": evidence.CURRENT_NAMES["crash"],
                                          "state": "OPTIONAL_ABSENT", "size": 0, "sha256": None}
            (docs / evidence.CURRENT_MANIFEST).write_text(json.dumps(manifest), encoding="utf-8")
            writing_manifest = json.loads(json.dumps(manifest))
            for key in ("run", "trace"):
                writing_manifest["files"][key]["state"] = "WRITING"
            (docs / evidence.CURRENT_NAMES["trace"]).write_text(
                payloads["trace"] + json.dumps(event("LATER_EVENT")) + "\n", encoding="utf-8")
            check(evidence.manifest_integrity_ok(docs, writing_manifest, evidence.CURRENT_NAMES),
                  "active run and trace may grow without invalidating their identity")
            writing_manifest["files"]["crash"] = {
                "name": evidence.CURRENT_NAMES["crash"], "state": "WRITING",
                "size": 0, "sha256": hashlib.sha256(b"").hexdigest()}
            (docs / evidence.CURRENT_NAMES["crash"]).write_bytes(b"signal image")
            check(evidence.manifest_integrity_ok(docs, writing_manifest, evidence.CURRENT_NAMES),
                  "a crash image written after launch does not invalidate active evidence")
            (docs / evidence.CURRENT_NAMES["crash"]).unlink()
            empty_crash_manifest = json.loads(json.dumps(manifest))
            empty_crash_manifest["files"]["crash"] = {
                "name": evidence.CURRENT_NAMES["crash"], "state": "PRESENT",
                "size": 0, "sha256": hashlib.sha256(b"").hexdigest()}
            (docs / evidence.CURRENT_NAMES["crash"]).write_bytes(b"")
            (docs / evidence.CURRENT_NAMES["trace"]).write_text(payloads["trace"], encoding="utf-8")
            check(evidence.manifest_integrity_ok(docs, empty_crash_manifest, evidence.CURRENT_NAMES),
                  "sealed empty crash marker is valid when preserved")
            (docs / evidence.CURRENT_NAMES["crash"]).unlink()
            check(not evidence.manifest_integrity_ok(docs, empty_crash_manifest, evidence.CURRENT_NAMES),
                  "omitting sealed empty crash marker invalidates the manifest")
            writing_manifest["files"]["runtime"]["state"] = "WRITING"
            check(not evidence.manifest_integrity_ok(docs, writing_manifest, evidence.CURRENT_NAMES),
                  "runtime evidence cannot bypass sealed digest validation")
            (docs / evidence.CURRENT_NAMES["trace"]).write_text(payloads["trace"], encoding="utf-8")
            exporter = pathlib.Path(__file__).resolve().parents[2] / "ci" / "export-physical-evidence.py"
            proc = subprocess.run([sys.executable, str(exporter), "--bundle-id", "dev.agr.simulator",
                                   "--documents", str(docs), "--output", str(out)],
                                  capture_output=True, text=True)
            check(proc.returncode == 0, "sealed current evidence export")
            exported = json.loads((out / "export-manifest.json").read_text(encoding="utf-8"))
            check(exported["snapshot_state"] == "SEALED_CONSISTENT", "export is sealed and consistent")
            check(exported["run_id"] == RUN_ID and exported["commit"] == COMMIT,
                  "export manifest preserves run identity")

            reused = subprocess.run([sys.executable, str(exporter), "--bundle-id", "dev.agr.simulator",
                                     "--documents", str(docs), "--output", str(out)],
                                    capture_output=True, text=True)
            check(reused.returncode != 0 and "refusing to mix" in reused.stderr,
                  "export refuses stale destination contents")

            mixed_docs = root / "mixed-documents"
            shutil.copytree(docs, mixed_docs)
            mixed_manifest_path = mixed_docs / evidence.CURRENT_MANIFEST
            mixed_manifest = json.loads(mixed_manifest_path.read_text(encoding="utf-8"))
            mixed_manifest["commit"] = "f" * 40
            mixed_manifest_path.write_text(json.dumps(mixed_manifest), encoding="utf-8")
            mixed_out = root / "mixed-export"
            mixed_proc = subprocess.run([sys.executable, str(exporter), "--bundle-id", "dev.agr.simulator",
                                         "--documents", str(mixed_docs), "--output", str(mixed_out)],
                                        capture_output=True, text=True)
            mixed_export = json.loads((mixed_out / "export-manifest.json").read_text(encoding="utf-8"))
            check(mixed_proc.returncode == 2 and not mixed_export["consistent"] and
                  mixed_export["manifest_identity_error"] == "manifest_commit_mismatch",
                  "manifest and run identity must match")

            old_docs = root / "old-documents"
            old_history = old_docs / "previous" / RUN_ID
            old_history.mkdir(parents=True)
            for key, body in payloads.items():
                (old_history / evidence.LEGACY_NAMES[key]).write_text(body, encoding="utf-8")
            old_out = root / "old-export"
            old_proc = subprocess.run([sys.executable, str(exporter), "--bundle-id", "dev.agr.simulator",
                                       "--documents", str(old_docs), "--run-id", RUN_ID,
                                       "--output", str(old_out)], capture_output=True, text=True)
            old_export = json.loads((old_out / "export-manifest.json").read_text(encoding="utf-8"))
            check(old_proc.returncode == 2 and old_export["source"] == "legacy" and
                  old_export["run_id"] == RUN_ID, "legacy history exports without claiming sealed")

            previous_docs = root / "previous-documents"
            previous_run = previous_docs / "previous" / RUN_ID
            previous_run.mkdir(parents=True)
            for key, body in payloads.items():
                (previous_run / evidence.PREVIOUS_NAMES[key]).write_text(body, encoding="utf-8")
            _, history_names, _, _ = evidence.evidence_source(previous_docs, "history", RUN_ID)
            check(history_names == evidence.PREVIOUS_NAMES,
                  "classifier selects agr-prev naming without requiring archive manifest")
            previous_out = root / "previous-export"
            previous_proc = subprocess.run([sys.executable, str(exporter), "--bundle-id", "dev.agr.simulator",
                                            "--documents", str(previous_docs), "--run-id", RUN_ID,
                                            "--output", str(previous_out)], capture_output=True, text=True)
            previous_export = json.loads((previous_out / "export-manifest.json").read_text(encoding="utf-8"))
            check(previous_proc.returncode == 2 and previous_export["source"] == "previous" and
                  previous_export["run_id"] == RUN_ID,
                  "pre-manifest agr-prev history remains readable without sealing")

    print("physical-runtime-evidence PASS")


def json_dumps(value):
    import json
    return json.dumps(value, sort_keys=True)


if __name__ == "__main__":
    main()
