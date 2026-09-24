#!/usr/bin/env python3
"""Classify one physical AGR launch from its bounded Documents evidence."""

import argparse
import hashlib
import json
import pathlib
import struct
import sys

CURRENT_NAMES = {"run": "agr-current-run.json", "trace": "agr-current-trace.ndjson",
                 "runtime": "agr-current-runtime.json", "crash": "agr-current-crash.bin"}
LEGACY_NAMES = {"run": "agr-physical-run.json", "trace": "agr-physical-trace.ndjson",
                "runtime": "agr-physical-runtime.json", "crash": "agr-physical-crash.bin"}
PREVIOUS_NAMES = {"run": "agr-prev-run.json", "trace": "agr-prev-trace.ndjson",
                  "runtime": "agr-prev-runtime.json", "crash": "agr-prev-crash.bin"}
CURRENT_MANIFEST = "agr-current-manifest.json"


def sha256_file(path):
    digest = hashlib.sha256()
    with pathlib.Path(path).open("rb") as stream:
        for block in iter(lambda: stream.read(1024 * 1024), b""):
            digest.update(block)
    return digest.hexdigest()
EXPECTED_APK_SHA256 = "57f4735297befc68c0a7aa6cd9e442ecd250b1b2b38104324a12b6c2d4e18569"
EXPECTED_PACKAGE = "org.jfedor.frozenbubble"
CRASH_MAGIC = b"AGRCRSH1"
CRASH_STRUCT = struct.Struct("<8sIi" + "I" * 13 + "QQQ")
THREAD_STATE = {0: "NONE", 1: "STARTING", 2: "RUNNING", 3: "WAITING", 4: "TERMINATED"}


def load_json(path):
    try:
        return json.loads(pathlib.Path(path).read_text(encoding="utf-8"))
    except (OSError, json.JSONDecodeError):
        return None


def evidence_source(root, source="auto", run_id=None):
    root = pathlib.Path(root)
    if source == "history":
        if not run_id:
            raise ValueError("--run-id is required for --source history")
        history = root / "previous" / run_id
        manifest = load_json(history / "manifest.json")
        names = PREVIOUS_NAMES if manifest or any((history / name).exists()
                                                  for name in PREVIOUS_NAMES.values()) else LEGACY_NAMES
        return history, names, manifest, False
    if source == "current":
        return root, CURRENT_NAMES, load_json(root / CURRENT_MANIFEST), False
    if source == "legacy":
        return root, LEGACY_NAMES, None, False
    has_current = (root / CURRENT_MANIFEST).exists() or any(
        (root / name).exists() for name in CURRENT_NAMES.values())
    has_legacy = any((root / name).exists() for name in LEGACY_NAMES.values())
    if has_current and has_legacy:
        return root, CURRENT_NAMES, load_json(root / CURRENT_MANIFEST), True
    if has_current or (root / CURRENT_MANIFEST).exists():
        return root, CURRENT_NAMES, load_json(root / CURRENT_MANIFEST), False
    return root, LEGACY_NAMES, None, False


def manifest_integrity_ok(root, manifest, names):
    if not isinstance(manifest, dict):
        return True
    files = manifest.get("files")
    if not isinstance(files, dict):
        return False
    if any(key not in files for key in names):
        return False
    for key, expected_name in names.items():
        item = files.get(key)
        if not isinstance(item, dict):
            return False
        name = item.get("name") or expected_name
        if pathlib.PurePosixPath(str(name)).name != str(name) or name != expected_name:
            return False
        state = str(item.get("state", "")).upper()
        if state in ("MISSING", "NOT_GENERATED", "OPTIONAL_ABSENT"):
            continue
        if state not in ("PRESENT", "WRITING"):
            return False
        path = pathlib.Path(root) / expected_name
        if not path.is_file():
            return False
        # An active run/trace/crash image is intentionally mutable. Identity is
        # checked separately; only sealed files have fixed digests.
        if state == "WRITING":
            if key not in ("run", "trace", "crash"):
                return False
            continue
        if item.get("size") is not None and path.stat().st_size != item.get("size"):
            return False
        if item.get("sha256") and sha256_file(path) != item.get("sha256"):
            return False
    return True


def load_trace(path):
    path = pathlib.Path(path)
    events, truncated = [], False
    if not path.is_file():
        return events, truncated
    lines = path.read_bytes().splitlines()
    for index, line in enumerate(lines):
        if not line.strip():
            continue
        try:
            events.append(json.loads(line.decode("utf-8")))
        except (UnicodeDecodeError, json.JSONDecodeError):
            truncated = True
    return events, truncated


def load_crash(path):
    path = pathlib.Path(path)
    if not path.is_file():
        return None
    try:
        data = path.read_bytes()
        if len(data) < CRASH_STRUCT.size:
            return None
        fields = CRASH_STRUCT.unpack_from(data)
    except (OSError, struct.error):
        return None
    if fields[0] != CRASH_MAGIC:
        return None
    ints, quads = fields[1:16], fields[16:19]
    return {"version": ints[0], "signal": ints[1], "last_phase": ints[2],
            "last_exec": ints[3], "has_exec": ints[4], "canvas_locked": ints[5],
            "lock_owner_exec": ints[6], "lock_count": ints[7], "unlock_count": ints[8],
            "post_count": ints[9], "draw_bitmap_count": ints[10],
            "pixel_change_count": ints[11], "generation": ints[12],
            "surface_valid": ints[13], "thread_state": ints[14],
            "last_seq": quads[0], "host_thread": quads[1], "surface_identity": quads[2]}


def phase_seen(events, name):
    return any(e.get("phase") == name or e.get("event") == name for e in events)


def dig(obj, path):
    value = obj
    for key in path:
        if not isinstance(value, dict):
            return None
        value = value.get(key)
    return value


def phase_events(events, name):
    return [e for e in events if e.get("phase") == name or e.get("event") == name]


def last_phase(events, name):
    found = phase_events(events, name)
    return found[-1] if found else None


def valid_process_identity(run):
    return (isinstance(run, dict) and bool(run.get("run_id")) and
            bool(run.get("process_launch_id")) and isinstance(run.get("pid"), int) and run["pid"] > 0 and
            bool(run.get("process_start_wall_time")) and
            isinstance(run.get("process_start_monotonic_ns"), int) and run["process_start_monotonic_ns"] > 0 and
            bool(run.get("commit")) and bool(run.get("tree")))


def current_run_identity_ok(run, events):
    if not valid_process_identity(run):
        return False
    keys = ("run_id", "process_launch_id", "commit", "tree")
    identity = {k: run.get(k) for k in keys}
    for event in events:
        if any(event.get(k) != v for k, v in identity.items()):
            return False
    return True


def evidence_identity_ok(run, events, final):
    if not current_run_identity_ok(run, events) or not isinstance(final, dict):
        return False
    keys = ("run_id", "process_launch_id", "commit", "tree")
    if any(final.get(k) != run.get(k) for k in keys):
        return False
    for field in ("pid", "process_start_wall_time", "process_start_monotonic_ns"):
        if final.get(field) != run.get(field):
            return False
    return True


def identity_conflict(run, events, final):
    """True only for contradictory present evidence, not merely an absent final file."""
    if not isinstance(run, dict):
        return False
    keys = ("run_id", "process_launch_id", "commit", "tree")
    for event in events:
        for key in keys:
            if event.get(key) is not None and run.get(key) is not None and event.get(key) != run.get(key):
                return True
    if isinstance(final, dict):
        for key in keys + ("pid", "process_start_wall_time", "process_start_monotonic_ns"):
            if final.get(key) is not None and run.get(key) is not None and final.get(key) != run.get(key):
                return True
    return False


def method_events(events, method, phase=None):
    return [e for e in events if e.get("method") == method and
            (phase is None or e.get("phase") == phase)]


def method_seen(events, method, direction):
    return any(e.get("method") == method and e.get("phase") == direction and
               "CRITICAL" in str(e.get("detail", "")) for e in events)


def latest_field(events, method):
    found = [e for e in events if e.get("phase") == "DIAGNOSTIC_FIELD_WITNESS" and e.get("method") == method]
    return found[-1] if found else None


def activity_resumed(run, events, final):
    stage_event = last_phase(events, "ACTIVITY_STAGE")
    stage = (stage_event or {}).get("activity_stage") or (stage_event or {}).get("detail") or ""
    final_stage = str((final or {}).get("activity_launch_stage", ""))
    runtime_stage = str(final_stage).upper() == "RESUMED"
    traced_stage = str(stage).upper() == "RESUMED"
    return bool((final or {}).get("activity_resumed") is True and (runtime_stage or traced_stage))


def build_identity_ok(run, final):
    if not isinstance(run, dict) or not isinstance(final, dict):
        return False
    if not all(run.get(k) and run.get(k) != "unknown" for k in ("branch", "commit", "tree")):
        return False
    if any(final.get(k) != run.get(k) for k in ("branch", "commit", "tree")):
        return False
    env = (final.get("environment_start") or final.get("environment") or {})
    embedded = env.get("build_environment") if isinstance(env, dict) else None
    if not isinstance(embedded, dict):
        return False
    identity = all(embedded.get(k) == run.get(k) for k in ("branch", "commit", "tree"))
    required = ("xcode", "sdk_name", "sdk_version", "deployment_target", "angle_version",
                "angle_identity", "interpreter_build_identity")
    return identity and all(embedded.get(k) not in (None, "", "unknown") for k in required)


def environment_complete(env):
    if not isinstance(env, dict):
        return False
    paths = (("target_type",), ("os", "system_version"), ("os", "os_build"),
             ("hardware", "hw_machine"),
             ("hardware", "architecture"), ("hardware", "page_size"),
             ("hardware", "logical_cpu_count"), ("hardware", "physical_memory"),
             ("display", "logical_width"), ("display", "logical_height"),
             ("display", "native_width"), ("display", "native_height"),
             ("display", "scale"), ("display", "native_scale"),
             ("display", "maximum_fps"), ("display", "runtime_host_width"),
             ("display", "runtime_host_height"), ("graphics", "device_name"),
             ("power", "thermal_state"), ("power", "low_power_mode_enabled"),
             ("power", "battery_monitoring_available"), ("lifecycle", "state"),
             ("lifecycle", "active"), ("lifecycle", "foreground"),
             ("app", "bundle_id"), ("process", "environment_target"))
    if any(dig(env, path) in (None, "") for path in paths):
        return False
    bins = {item.get("role"): item for item in (env.get("binaries") or []) if isinstance(item, dict)}
    return all(bins.get(role, {}).get("uuid") and bins.get(role, {}).get("sha256")
               for role in ("executable", "libEGL", "libGLESv2"))


BOUNDARY_NAMES = [
    "APK_OPEN_OK", "ACTIVITY_RESUMED", "SURFACE_CREATED", "SURFACE_CHANGED",
    "GameThread.setSurfaceSize ENTER", "GameThread.setSurfaceSize EXIT",
    "resizeBitmaps ENTER", "resizeBitmaps EXIT", "mImagesReady=true",
    "THREAD_RUN_ENTER", "GameThread.doDraw ENTER", "GameThread.doDraw EXIT",
    "Canvas operation", "DRAW_BITMAP_END", "PIXEL_MUTATION", "CANVAS_POST_END",
    "HOST_SURFACE_ACQUIRED", "HOST_SURFACE_SUBMITTED",
]


def boundary_report(events, run, final):
    def present(name):
        if name == "ACTIVITY_RESUMED":
            return activity_resumed(run, events, final)
        if name in ("GameThread.setSurfaceSize ENTER", "GameThread.setSurfaceSize EXIT"):
            return method_seen(events, "setSurfaceSize", "GUEST_METHOD_ENTER" if name.endswith("ENTER") else "GUEST_METHOD_EXIT")
        if name in ("resizeBitmaps ENTER", "resizeBitmaps EXIT"):
            return method_seen(events, "resizeBitmaps", "GUEST_METHOD_ENTER" if name.endswith("ENTER") else "GUEST_METHOD_EXIT")
        if name == "mImagesReady=true":
            e = latest_field(events, "mImagesReady")
            return bool(e and "mImagesReady=1" in str(e.get("detail", "")))
        if name == "GameThread.doDraw ENTER":
            return method_seen(events, "doDraw", "GUEST_METHOD_ENTER")
        if name == "GameThread.doDraw EXIT":
            return method_seen(events, "doDraw", "GUEST_METHOD_EXIT")
        if name == "Canvas operation":
            return any(e.get("phase") == "GUEST_METHOD_ENTER" and
                       str(e.get("class", "")).startswith("Landroid/graphics/Canvas;") and
                       "CRITICAL" in str(e.get("detail", "")) for e in events)
        return phase_seen(events, name)

    last, missing = "", ""
    for name in BOUNDARY_NAMES:
        if present(name) and not missing:
            last = name
        elif not present(name) and not missing:
            missing = name
    return last, missing


def stage_states(run, events, final, crash):
    env = (final or {}).get("environment_start") or (run or {}).get("environment_start") or (run or {}).get("environment")
    env_end = (final or {}).get("environment_end") or (run or {}).get("environment_end")
    apk_actual = (final or {}).get("apk_sha256") or (run or {}).get("apk_sha256_actual") or ""
    apk_expected = (final or {}).get("apk_sha256_expected") or (run or {}).get("apk_sha256_expected") or ""
    game_enters = phase_events(events, "THREAD_RUN_ENTER")
    root_exec = (final or {}).get("root_exec")
    if root_exec is None:
        root = last_phase(events, "EXEC_PUBLISHED")
        root_exec = (root or {}).get("exec_id")
    independent = any((e.get("exec_id") is not None and e.get("exec_id") != root_exec and
                       e.get("host_thread_id") not in (None, (last_phase(events, "EXEC_PUBLISHED") or {}).get("host_thread_id")))
                      for e in game_enters)
    callbacks = len(phase_events(events, "SURFACE_CALLBACK_OK"))
    created = phase_seen(events, "SURFACE_CREATED") and callbacks >= 1
    changed = phase_seen(events, "SURFACE_CHANGED") and callbacks >= 2
    content_identity = str((final or {}).get("content_surface_identity", ""))
    root_identity = str((final or {}).get("root_surface_identity", ""))
    surface_distinct = bool(content_identity and root_identity and content_identity != root_identity)
    has_critical_build = build_identity_ok(run, final)
    identity = evidence_identity_ok(run, events, final)
    return {
        "build_identity_confirmed": has_critical_build,
        "current_run_identity_confirmed": current_run_identity_ok(run, events),
        "evidence_identity_confirmed": identity,
        "environment_captured": environment_complete(env) and environment_complete(env_end),
        "environment_end_captured": environment_complete(env_end),
        "environment_changed": bool((final or {}).get("environment_changed") or (run or {}).get("environment_changed")),
        "apk_confirmed": apk_actual == EXPECTED_APK_SHA256 and apk_expected == EXPECTED_APK_SHA256 and
                         bool(phase_seen(events, "APK_SHA_OK")) and
                         (final or {}).get("apk_package") == EXPECTED_PACKAGE,
        "activity_confirmed": activity_resumed(run, events, final),
        "game_thread_confirmed": independent,
        "surface_callback_confirmed": created and changed and callbacks >= 2 and
                                      (final or {}).get("content_surface_valid") is True,
        "surface_identity_distinct": surface_distinct,
        "bitmap_preparation_confirmed": (method_seen(events, "setSurfaceSize", "GUEST_METHOD_EXIT") and
                                          method_seen(events, "resizeBitmaps", "GUEST_METHOD_EXIT") and
                                          bool(latest_field(events, "mImagesReady") and
                                               "mImagesReady=1" in str(latest_field(events, "mImagesReady").get("detail", "")))),
        "draw_path_confirmed": method_seen(events, "doDraw", "GUEST_METHOD_ENTER") and
                               phase_seen(events, "DRAW_BITMAP_END"),
        "vector_state_confirmed": phase_seen(events, "VECTOR_SIZE") and phase_seen(events, "VECTOR_ELEMENT") and
                                  bool((final or {}).get("vector_size")),
        "content_produced": int((final or {}).get("draw_bitmap_count") or 0) > 0 and
                            int((final or {}).get("pixel_change_count") or 0) > 0 and
                            bool((final or {}).get("hash_before")) and bool((final or {}).get("hash_after")) and
                            (final or {}).get("hash_before") != (final or {}).get("hash_after"),
        "content_posted": int((final or {}).get("post_count") or 0) > 0,
        "host_surface_acquired": phase_seen(events, "HOST_SURFACE_ACQUIRED"),
        "host_surface_submitted": phase_seen(events, "HOST_SURFACE_SUBMITTED") and
                                  int((final or {}).get("host_surface_submissions") or 0) > 0,
        "screen_presented": False,
        "crash_free": not bool(crash and crash.get("signal")),
        "runtime_clean": not bool((final or {}).get("runtime_error")) and
                         not bool((final or {}).get("vm_error")) and
                         (final or {}).get("pending_exception") is not True,
        "not_stalled": not (phase_seen(events, "WATCHDOG_STALL") or
                            phase_seen(events, "WATCHDOG_NO_PROGRESS_8S") or
                            (run or {}).get("termination_reason") == "WATCHDOG_STALL" or
                            (final or {}).get("termination_reason") == "WATCHDOG_STALL"),
    }


def classify(events, run, final, crash, states):
    if identity_conflict(run, events, final):
        return "STALE_OR_MIXED_EVIDENCE"
    actual = (final or {}).get("apk_sha256") or (run or {}).get("apk_sha256_actual") or ""
    expected = (final or {}).get("apk_sha256_expected") or (run or {}).get("apk_sha256_expected") or ""
    if (actual and expected and actual != expected) or phase_seen(events, "APK_SHA_FAIL"):
        return "APK_IDENTITY_MISMATCH"
    if expected and expected != EXPECTED_APK_SHA256:
        return "APK_IDENTITY_MISMATCH"
    if crash and crash.get("signal"):
        return "NATIVE_SIGNAL_CRASH"
    reason = str((final or {}).get("termination_reason") or (run or {}).get("termination_reason") or
                 (final or {}).get("final_state") or "")
    if phase_seen(events, "EVIDENCE_CHANNEL_FAILED") or reason == "EVIDENCE_CHANNEL_FAILED":
        return "EVIDENCE_CHANNEL_FAILED"
    if phase_seen(events, "SURFACE_CALLBACK_THROW"):
        return "CALLBACK_THROW"
    if phase_seen(events, "SURFACE_CALLBACK_EXEC_ERROR"):
        return "CALLBACK_EXEC_ERROR"
    if phase_seen(events, "BITMAP_SCALE_FAIL"):
        return "BITMAP_SCALE_FAIL"
    stalled = (phase_seen(events, "WATCHDOG_STALL") or phase_seen(events, "WATCHDOG_NO_PROGRESS_8S") or
               reason == "WATCHDOG_STALL")
    if stalled:
        return "WATCHDOG_STALL"
    if phase_seen(events, "RUNTIME_ERROR") or (final and final.get("runtime_error")):
        return "RUNTIME_ERROR"
    if reason in ("RUNTIME_ERROR", "RUNTIME_FAILURE"):
        return "RUNTIME_ERROR"
    if phase_seen(events, "APK_LOCATE_FAIL") or phase_seen(events, "APK_OPEN_FAIL"):
        return "FAIL_BEFORE_APK_OPEN"
    if phase_seen(events, "GAME_CREATE_FAIL"):
        return "FAIL_GAME_CREATE"
    if phase_seen(events, "ACTIVITY_START_FAIL"):
        return "FAIL_ACTIVITY_START"

    do_draw_enter = method_seen(events, "doDraw", "GUEST_METHOD_ENTER")
    do_draw_exit = method_seen(events, "doDraw", "GUEST_METHOD_EXIT")
    canvas_op = any(e.get("phase") == "GUEST_METHOD_ENTER" and
                    str(e.get("class", "")).startswith("Landroid/graphics/Canvas;") and
                    "CRITICAL" in str(e.get("detail", "")) for e in events)
    draw = int((final or {}).get("draw_bitmap_count") or 0)
    pixels = int((final or {}).get("pixel_change_count") or 0)
    before, after = (final or {}).get("hash_before"), (final or {}).get("hash_after")
    posted = int((final or {}).get("post_count") or 0) > 0
    if draw > 0 and (pixels == 0 or (before is not None and before == after)):
        return "DRAW_BITMAP_WITHOUT_PIXEL_MUTATION"
    if posted and draw == 0:
        if not phase_seen(events, "THREAD_RUN_ENTER"):
            return "CONTENT_POSTED_WITHOUT_DRAW"
        if do_draw_enter and do_draw_exit and not canvas_op:
            return "DRAW_RETURNED_WITHOUT_CANVAS_OP"
        if canvas_op:
            return "DRAW_BITMAP_NOT_REACHED"
        return "DRAW_NOT_ENTERED"
    if phase_seen(events, "THREAD_RUN_ENTER") and not do_draw_enter:
        return "DRAW_NOT_ENTERED"
    if final and final.get("content_posted") == "YES" and draw == 0:
        return "CONTENT_POSTED_WITHOUT_DRAW"
    if final is None and isinstance(run, dict):
        return "ABRUPT_TERMINATION"
    if (all(states.get(k) for k in (
        "evidence_identity_confirmed", "build_identity_confirmed", "apk_confirmed",
        "activity_confirmed", "game_thread_confirmed", "surface_callback_confirmed",
        "surface_identity_distinct", "bitmap_preparation_confirmed", "draw_path_confirmed", "vector_state_confirmed",
        "content_produced", "content_posted", "runtime_clean", "crash_free", "not_stalled")) and
            int(final.get("lock_count") or 0) > 0 and int(final.get("unlock_count") or 0) > 0 and
            int(final.get("draw_bitmap_count") or 0) > 0 and int(final.get("pixel_change_count") or 0) > 0 and
            isinstance(final.get("vector_size"), str) and final.get("vector_size") != "" and
            final.get("penguin_sprite_paint") is True and
            phase_seen(events, "PENGUIN_SPRITE_PAINT_WITNESS")):
        return ("HOST_SUBMITTED_SCREEN_UNVERIFIED" if states.get("host_surface_submitted")
                and states.get("host_surface_acquired") else "CONTENT_POSTED_NO_HOST_CONSUMER")
    if run is None or not events:
        return "EVIDENCE_INCOMPLETE"
    return "EVIDENCE_INCOMPLETE"


def summarize(directory):
    return summarize_source(directory, "auto", None)


def failure_chain(events, run, final):
    """Keep first observed fault, thrown exception, later work, and final stop distinct."""
    failure_phases = {
        "BITMAP_SCALE_FAIL", "SURFACE_CALLBACK_THROW", "SURFACE_CALLBACK_EXEC_ERROR",
        "RUNTIME_ERROR", "EVIDENCE_CHANNEL_FAILED", "WATCHDOG_STALL",
        "WATCHDOG_NO_PROGRESS_8S", "ARM_FAULT", "JNI_EXCEPTION",
    }
    observed = [(index, event) for index, event in enumerate(events)
                if event.get("phase") in failure_phases or event.get("event") in failure_phases]
    first = observed[0][1] if observed else None
    throw = next((event for _, event in observed if event.get("phase") in
                  ("SURFACE_CALLBACK_THROW", "SURFACE_CALLBACK_EXEC_ERROR", "JNI_EXCEPTION")), None)
    start = observed[0][0] if observed else len(events)
    continuation = [event for event in events[start + 1:] if
                    event.get("phase") in ("THREAD_RUN_ENTER", "GUEST_METHOD_ENTER", "GUEST_METHOD_EXIT",
                                            "DRAW_BITMAP_END", "CANVAS_POST_END")]
    return {
        "first_observed_failure": first,
        "first_observed_failure_is_proven_cause": False,
        "direct_exception_or_callback_failure": throw,
        "subsequent_guest_execution": continuation,
        "final_stop_reason": ((final or {}).get("termination_reason") or
                              (run or {}).get("termination_reason") or
                              (final or {}).get("final_state")),
    }


def summarize_source(directory, source="auto", run_id=None):
    root, names, manifest, source_conflict = evidence_source(directory, source, run_id)
    run = load_json(root / names["run"])
    events, truncated = load_trace(root / names["trace"])
    final = load_json(root / names["runtime"])
    crash = load_crash(root / names["crash"])
    integrity_ok = manifest_integrity_ok(root, manifest, names)
    manifest_identity_conflict = False
    if isinstance(manifest, dict):
        for key, value in (("run_id", (run or {}).get("run_id")),
                           ("process_launch_id", (run or {}).get("process_launch_id")),
                           ("commit", (run or {}).get("commit")),
                           ("tree", (run or {}).get("tree"))):
            manifest_value = manifest.get(key)
            if manifest_value not in (None, "") and value not in (None, "") and manifest_value != value:
                manifest_identity_conflict = True
        if source == "history" and manifest.get("run_id") not in (None, run_id):
            manifest_identity_conflict = True
    seqs = [int(e.get("seq") or 0) for e in events]
    monotonic = all(seqs[i] < seqs[i + 1] for i in range(len(seqs) - 1))
    states = stage_states(run, events, final, crash)
    last_boundary, missing_boundary = boundary_report(events, run, final)
    last = events[-1] if events else {}
    game = last_phase(events, "THREAD_RUN_ENTER") or last_phase(events, "THREAD_START") or last_phase(events, "CANVAS_LOCK_ACQUIRED")
    classify_as = ("STALE_OR_MIXED_EVIDENCE" if source_conflict or manifest_identity_conflict else
                   "EVIDENCE_MANIFEST_INVALID" if not integrity_ok else
                   classify(events, run, final, crash, states))
    method_witnesses = {}
    for name in ("setSurfaceSize", "resizeBitmaps", "doDraw", "<init>"):
        method_witnesses[name] = {
            "entered": method_seen(events, name, "GUEST_METHOD_ENTER"),
            "returned": method_seen(events, name, "GUEST_METHOD_EXIT"),
            "events": [{"class": e.get("class"), "method": e.get("method"), "pc": e.get("guest_pc"),
                        "phase": e.get("phase"), "detail": e.get("detail"), "exec_id": e.get("exec_id")}
                       for e in events if e.get("method") == name and "CRITICAL" in str(e.get("detail", ""))],
        }
    canvas_operations = [{"class": e.get("class"), "method": e.get("method"), "pc": e.get("guest_pc"),
                         "phase": e.get("phase"), "exec_id": e.get("exec_id")}
                        for e in events if e.get("phase") == "GUEST_METHOD_ENTER" and
                        str(e.get("class", "")).startswith("Landroid/graphics/Canvas;") and
                        "CRITICAL" in str(e.get("detail", ""))]
    summary = {
        **states,
        "identity_valid": states["evidence_identity_confirmed"],
        "process_launch_id": None if not isinstance(run, dict) else run.get("process_launch_id"),
        "run_id": None if not isinstance(run, dict) else run.get("run_id"),
        "pid": None if not isinstance(run, dict) else run.get("pid"),
        "process_start_wall_time": None if not isinstance(run, dict) else run.get("process_start_wall_time"),
        "process_start_monotonic_ns": None if not isinstance(run, dict) else run.get("process_start_monotonic_ns"),
        "commit": None if not isinstance(run, dict) else run.get("commit"),
        "tree": None if not isinstance(run, dict) else run.get("tree"),
        "architecture": None if not isinstance(run, dict) else run.get("architecture"),
        "device_platform": None if not isinstance(run, dict) else run.get("device_platform"),
        "passive_dropped_count": (final or {}).get("passive_dropped_count", 0),
        "last_durable_seq": seqs[-1] if seqs else (crash.get("last_seq") if crash else 0),
        "last_event": last.get("event") or last.get("phase") or "",
        "last_phase": last.get("phase") or "",
        "sequence_monotonic": monotonic,
        "truncated_final_line": truncated,
        "last_exec": game.get("exec_id") if game else (crash.get("last_exec") if crash else None),
        "last_host_thread": game.get("host_thread_id") if game else (crash.get("host_thread") if crash else None),
        "thread_state": THREAD_STATE.get(int(game.get("thread_state") or 0), "NONE") if game else "NONE",
        "activity_stage": ((last_phase(events, "ACTIVITY_STAGE") or {}).get("activity_stage") or
                           (last_phase(events, "ACTIVITY_STAGE") or {}).get("detail") or
                           (final or {}).get("activity_launch_stage")),
        "surface_valid": bool((last or {}).get("surface_valid")),
        "surface_identity": (last or {}).get("surface_identity"),
        "canvas_locked": bool((last or {}).get("canvas_locked")),
        "lock_owner_exec": (final or {}).get("game_thread_exec") or (last or {}).get("lock_owner_exec"),
        "lock_count": (final or {}).get("lock_count", (last or {}).get("lock_count")),
        "unlock_count": (final or {}).get("unlock_count", (last or {}).get("unlock_count")),
        "post_count": (final or {}).get("post_count", (last or {}).get("post_count")),
        "draw_bitmap_count": (final or {}).get("draw_bitmap_count", (last or {}).get("draw_bitmap_count")),
        "pixel_change_count": (final or {}).get("pixel_change_count", (last or {}).get("pixel_change_count")),
        "crash_marker": crash,
        "stall": classify_as == "WATCHDOG_STALL",
        "final_json_present": final is not None,
        "final_json_missing": final is None,
        "classification": classify_as,
        "evidence_source": ("current" if names == CURRENT_NAMES else
                            "previous" if names == PREVIOUS_NAMES else "legacy"),
        "evidence_directory": str(root),
        "source_conflict": source_conflict,
        "manifest_integrity_ok": integrity_ok,
        "failure_chain": failure_chain(events, run, final),
        "bitmap_object_chain": [event for event in events if event.get("phase") in (
            "BITMAP_DECODE_WITNESS", "BITMAP_REFERENCE_WITNESS", "BITMAP_FIELD_WITNESS")],
        "surface_callback_outcomes": [{"seq": event.get("seq"), "method": event.get("method"),
                                       "phase": event.get("phase"), "detail": event.get("detail"),
                                       "exec_id": event.get("exec_id"),
                                       "host_thread_id": event.get("host_thread_id")}
                                      for event in events if event.get("phase") in (
                                          "SURFACE_CALLBACK_BEGIN", "SURFACE_CALLBACK_OK",
                                          "SURFACE_CALLBACK_THROW", "SURFACE_CALLBACK_EXEC_ERROR")],
        "last_confirmed_boundary": last_boundary,
        "first_missing_expected_boundary": missing_boundary,
        "environment_start": (final or {}).get("environment_start") or (run or {}).get("environment_start") or (run or {}).get("environment"),
        "environment_end": (final or {}).get("environment_end") or (run or {}).get("environment_end"),
        "environment_changed": (final or {}).get("environment_changed") or (run or {}).get("environment_changed") or [],
        "method_witnesses": method_witnesses,
        "canvas_operations": canvas_operations,
        "event_count": len(events),
        "termination_reason": (final or {}).get("termination_reason") or (run or {}).get("termination_reason"),
        "run_state": None if not isinstance(run, dict) else run.get("state"),
        "finalize_reason": (final or {}).get("termination_reason"),
        "termination_consistent": bool(final and run and final.get("termination_reason") == run.get("termination_reason")),
    }
    if crash and crash.get("last_seq") and (not seqs or crash["last_seq"] >= seqs[-1]):
        summary["last_durable_seq"] = crash["last_seq"]
    return summary


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--dir", required=True)
    parser.add_argument("--source", choices=("auto", "current", "history", "legacy"), default="auto")
    parser.add_argument("--run-id")
    parser.add_argument("--summary")
    args = parser.parse_args()
    summary = summarize_source(args.dir, args.source, args.run_id)
    text = json.dumps(summary, indent=2, sort_keys=True)
    if args.summary:
        pathlib.Path(args.summary).write_text(text + "\n", encoding="utf-8")
    sys.stdout.write(text + "\n")
    return 0


if __name__ == "__main__":
    sys.exit(main())
