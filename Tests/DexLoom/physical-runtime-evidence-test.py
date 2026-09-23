#!/usr/bin/env python3
"""Focused contract tests for physical evidence identity and draw-boundary classification."""

import importlib.util
import pathlib

SCRIPT = pathlib.Path(__file__).resolve().parents[2] / "ci" / "physical-runtime-evidence.py"
spec = importlib.util.spec_from_file_location("physical_runtime_evidence", SCRIPT)
evidence = importlib.util.module_from_spec(spec)
spec.loader.exec_module(evidence)

RUN_ID = "run-001"
LAUNCH_ID = "launch-001"
COMMIT = "abc123"
TREE = "def456"
PID = 1234
START = "2026-09-23T02:00:00.123Z"
START_MONO = 123456789
APK = evidence.EXPECTED_APK_SHA256


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
    check(classify(run, events, final) == "PHYSICAL_PASS", "complete fixture must pass")

    wrong_final = dict(final, tree="different")
    check(classify(run, events, wrong_final) == "STALE_OR_MIXED_EVIDENCE", "final tree mismatch")
    wrong_commit = dict(final, commit="different")
    check(classify(run, events, wrong_commit) == "STALE_OR_MIXED_EVIDENCE", "final commit mismatch")
    wrong_event = list(events) + [event("RUNTIME_ERROR", process_launch_id="other-launch")]
    check(classify(run, wrong_event, final) == "STALE_OR_MIXED_EVIDENCE", "trace launch mismatch")
    wrong_apk = dict(final, apk_sha256="0" * 64)
    check(classify(run, events, wrong_apk) == "APK_IDENTITY_MISMATCH", "APK mismatch distinct")

    # Each missing strict gate must independently prevent PHYSICAL_PASS.
    for field, bad_value in (
        ("activity_resumed", False), ("content_surface_valid", False),
        ("content_surface_identity", "11"), ("pending_exception", True),
        ("runtime_error", "unexpected"), ("vector_size", ""),
        ("pixel_change_count", 0), ("hash_after", "abcd"),
    ):
        mutated = dict(final, **{field: bad_value})
        check(classify(run, events, mutated) != "PHYSICAL_PASS", "strict gate " + field)
    no_paint = [e for e in events if e["phase"] != "PENGUIN_SPRITE_PAINT_WITNESS"]
    check(classify(run, no_paint, final) != "PHYSICAL_PASS", "penguin witness required")

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
    check(classify(run, events, missing) != "PHYSICAL_PASS", "process identity required")
    check(classify(run, events, None) == "ABRUPT_TERMINATION", "missing final report is abrupt termination")
    states = evidence.stage_states(run, events, final, None)
    for key in ("build_identity_confirmed", "current_run_identity_confirmed", "environment_captured",
                "apk_confirmed", "activity_confirmed", "game_thread_confirmed",
                "surface_callback_confirmed", "bitmap_preparation_confirmed",
                "draw_path_confirmed", "content_produced", "content_posted", "screen_presented"):
        check(key in states, "summary stage " + key)
    check(evidence.boundary_report(events, run, final)[1] == "", "full boundary chain")
    missing_size_enter = [e for e in events if not (e.get("method") == "setSurfaceSize" and
                                                     e.get("phase") == "GUEST_METHOD_ENTER")]
    last_boundary, first_missing = evidence.boundary_report(missing_size_enter, run, final)
    check(last_boundary == "SURFACE_CHANGED" and first_missing == "GameThread.setSurfaceSize ENTER",
          "first missing causal boundary is retained")
    print("physical-runtime-evidence PASS")


def json_dumps(value):
    import json
    return json.dumps(value, sort_keys=True)


if __name__ == "__main__":
    main()
