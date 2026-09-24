#!/usr/bin/env python3
"""Collect an unmodified Frozen Bubble APK trajectory on Android 4.4.4.

This is an Android reference harness, not part of the AGR Runtime.
"""

import argparse
import hashlib
import json
import pathlib
import re
import struct
import subprocess
import time
import xml.etree.ElementTree as ET

from gameplay_trajectory import EXECUTED_SCHEMA, load_canonical, map_action


PACKAGE = "org.jfedor.frozenbubble"
ACTIVITY = PACKAGE + "/.FrozenBubble"
APK_SHA256 = "57f4735297befc68c0a7aa6cd9e442ecd250b1b2b38104324a12b6c2d4e18569"
SOURCE_REVISION = "43851e8d7755214b34ea8b7f4fe49bef246bc1c8"


def command(*args, timeout=45, check=True):
    result = subprocess.run(args, capture_output=True, timeout=timeout)
    if check and result.returncode:
        raise RuntimeError(f"{args}: exit {result.returncode}: {result.stderr.decode(errors='replace')}")
    return result.stdout.decode(errors="replace").strip()


def adb(*args, timeout=45, check=True):
    return command("adb", *args, timeout=timeout, check=check)


def capture(out, label):
    remote = "/sdcard/agr-api19-reference.png"
    local = out / f"{label}.png"
    adb("shell", "screencap", "-p", remote)
    adb("pull", remote, str(local))
    payload = local.read_bytes()
    if not payload.startswith(b"\x89PNG\r\n\x1a\n"):
        raise RuntimeError(f"invalid screenshot: {local}")
    width, height = struct.unpack(">II", payload[16:24])
    return {
        "timestamp_utc": time.strftime("%Y-%m-%dT%H:%M:%SZ", time.gmtime()),
        "screenshot": local.name,
        "screenshot_sha256": hashlib.sha256(payload).hexdigest(),
        "screenshot_dimensions": {"width": width, "height": height},
        "process": adb("shell", "ps", check=False),
        "activity": adb("shell", "dumpsys", "activity", "activities", timeout=60, check=False),
    }


def measure_root_viewport(out, label):
    """Measure the actual APK root view; never substitute raw screen pixels."""
    remote = "/sdcard/agr-api19-window.xml"
    dump_result = adb("shell", "uiautomator", "dump", remote, timeout=45, check=False)
    payload = adb("shell", "cat", remote, timeout=30, check=False)
    if not payload.lstrip().startswith("<?xml"):
        raise RuntimeError(f"unable to measure Android root view: {dump_result}")
    (out / f"{label}-hierarchy.xml").write_text(payload, encoding="utf-8")
    root = ET.fromstring(payload)
    bounds = []
    for node in root.iter("node"):
        if node.attrib.get("package") != PACKAGE:
            continue
        match = re.fullmatch(r"\[(\d+),(\d+)\]\[(\d+),(\d+)\]", node.attrib.get("bounds", ""))
        if match:
            x0, y0, x1, y1 = map(int, match.groups())
            if x1 > x0 and y1 > y0:
                bounds.append((x0, y0, x1 - x0, y1 - y0))
    if not bounds:
        raise RuntimeError("exact APK root view absent from UI hierarchy")
    x, y, width, height = max(bounds, key=lambda b: b[2] * b[3])
    return {"coordinate_space": "normalized_root_view", "x": x, "y": y,
            "width": width, "height": height, "measurement_source": f"{label}-hierarchy.xml"}


def execute_action(action, actual):
    if action is None:
        return None
    if action["type"] == "tap":
        return adb("shell", "input", "tap", str(actual["x"]), str(actual["y"]))
    if action["type"] == "long_press":
        return adb("shell", "input", "swipe", str(actual["x"]), str(actual["y"]),
                   str(actual["x"]), str(actual["y"]), str(actual.get("duration_ms", 600)))
    if action["type"] == "swipe":
        return adb("shell", "input", "swipe", *(str(actual[key]) for key in
                   ("x0", "y0", "x1", "y1", "duration_ms")))
    if action["type"] == "keyevent":
        return adb("shell", "input", "keyevent", str(actual["keycode"]))
    raise ValueError(f"unsupported action: {action['type']}")


def run_executed_trajectory(apk, out, plan, run_number, environment):
    prefix = f"replay-{run_number}"
    launch = fresh_launch(apk, out)
    steps = []
    for index, specification in enumerate(plan["steps"]):
        label = f"{prefix}-step-{index:02d}"
        before = capture(out, label + "-before")
        viewport = measure_root_viewport(out, label) if specification.get("action") else None
        requested = specification.get("action")
        actual = map_action(requested, viewport) if requested else None
        adb("logcat", "-c")
        injected_at = time.strftime("%Y-%m-%dT%H:%M:%SZ", time.gmtime())
        result = execute_action(requested, actual)
        time.sleep(specification["wait_ms"] / 1000)
        after = capture(out, label + "-after")
        if viewport:
            after["content_bounds"] = {k: viewport[k] for k in ("x", "y", "width", "height")}
        log_name = label + "-logcat.txt"
        (out / log_name).write_text(adb("logcat", "-d", "-v", "threadtime", timeout=90), encoding="utf-8")
        steps.append({"id": specification["id"], "action_requested": requested,
                      "action_actual": actual,
                      "before": {**before, "state": {"observable_state": None}},
                      "input": {"injection_accepted": result is not None if requested else None,
                                "delivered": None, "consumed": None,
                                "injected_at_utc": injected_at, "adb_result": result},
                      "after": {**after, "state": {"observable_state": None}},
                      "runtime_failure": None, "logcat": log_name})
    executed = {"schema": EXECUTED_SCHEMA, "platform": "android-api19",
                "identity": {**environment, "apk_sha256": APK_SHA256,
                             "run_number": run_number, "launch_result": launch}, "steps": steps}
    filename = f"android-api19-executed-trajectory-run{run_number}.json"
    (out / filename).write_text(json.dumps(executed, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")
    return executed


def fresh_launch(apk, out):
    adb("shell", "am", "force-stop", PACKAGE, check=False)
    adb("uninstall", PACKAGE, check=False)
    remote_apk = "/data/local/tmp/agr-frozen-reference.apk"
    try:
        push = adb("push", str(apk), remote_apk, timeout=90)
        (out / "apk-push-result.txt").write_text(push + "\n", encoding="utf-8")
        install = adb("shell", "pm", "install", remote_apk, timeout=300)
        if "Success" not in install:
            raise RuntimeError(f"API19 PackageManager did not install the APK: {install}")
    except (RuntimeError, subprocess.TimeoutExpired) as exc:
        diagnostics = {"install_error": str(exc)}
        for name, args in {
            "devices": ("devices", "-l"),
            "boot": ("shell", "getprop", "sys.boot_completed"),
            "package_service": ("shell", "service", "check", "package"),
            "package_path": ("shell", "pm", "path", PACKAGE),
            "data_space": ("shell", "df", "/data"),
            "mounts": ("shell", "mount"),
            "logcat": ("logcat", "-d", "-t", "300"),
        }.items():
            try:
                diagnostics[name] = adb(*args, timeout=10, check=False)
            except (OSError, subprocess.TimeoutExpired) as probe_error:
                diagnostics[name] = f"PROBE_FAILED: {probe_error}"
        (out / "install-diagnostics.json").write_text(json.dumps(diagnostics, indent=2) + "\n")
        raise
    (out / "install-result.txt").write_text(install + "\n", encoding="utf-8")
    adb("shell", "pm", "clear", PACKAGE, timeout=60)
    adb("shell", "am", "force-stop", PACKAGE, check=False)
    adb("logcat", "-c")
    return adb("shell", "am", "start", "-W", "-n", ACTIVITY, timeout=60)


def run_cold_start(apk, out, prefix):
    launch = fresh_launch(apk, out)
    started = time.monotonic()
    states = []
    for label, delay in (("t0", 0.4), ("t1", 2.0), ("t2", 6.0), ("tfinal", 15.0)):
        remaining = delay - (time.monotonic() - started)
        if remaining > 0:
            time.sleep(remaining)
        sample = capture(out, f"{prefix}-{label}")
        sample["elapsed_seconds"] = round(time.monotonic() - started, 3)
        states.append(sample)
    return {"launch_result": launch, "input_count": 0, "states": states,
            "zero_input_final_state": "VISUAL_REVIEW_REQUIRED"}


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--apk", type=pathlib.Path, required=True)
    parser.add_argument("--out", type=pathlib.Path, required=True)
    parser.add_argument("--replay", type=pathlib.Path)
    args = parser.parse_args()
    args.out.mkdir(parents=True, exist_ok=True)
    actual = hashlib.sha256(args.apk.read_bytes()).hexdigest()
    if actual != APK_SHA256:
        raise RuntimeError(f"reference APK SHA mismatch: {actual}")
    api = adb("shell", "getprop", "ro.build.version.sdk").strip()
    release = adb("shell", "getprop", "ro.build.version.release").strip()
    if api != "19" or release != "4.4.4":
        raise RuntimeError(f"reference environment mismatch: API {api}, Android {release}")
    reference = {
        "schema_version": 1,
        "apk": {"package": PACKAGE, "version_code": 8, "version_name": "1.7", "sha256": actual},
        "android_reference": {"api_level": 19, "release": release,
                              "fingerprint": adb("shell", "getprop", "ro.build.fingerprint").strip(),
                              "abi": adb("shell", "getprop", "ro.product.cpu.abi").strip()},
        "source_mapping": {"repository": "https://github.com/videogameboy76/frozenbubbleandroid",
                           "revision": SOURCE_REVISION, "exact_match": False,
                           "evidence": ["Manifest at this revision declares package, versionCode 8 and versionName 1.7; no matching release tag exists", 
                                        "APK-to-source binary identity has not been proved"]},
        "cold_start": run_cold_start(args.apk, args.out, "cold"),
        "normal_user_trajectory": [],
        "gameplay_entry": None,
        "gameplay_interaction": None,
    }
    (args.out / "cold-logcat.txt").write_text(adb("logcat", "-d", "-v", "threadtime", timeout=90), encoding="utf-8")
    (args.out / "package-dump.txt").write_text(adb("shell", "dumpsys", "package", PACKAGE, timeout=60), encoding="utf-8")
    if args.replay:
        plan = load_canonical(args.replay)
        reference["canonical_trajectory_sha256"] = hashlib.sha256(args.replay.read_bytes()).hexdigest()
        environment = {"android_api": 19, "android_release": release,
                       "android_fingerprint": reference["android_reference"]["fingerprint"]}
        for run_number in (1, 2):
            execute = run_executed_trajectory(args.apk, args.out, plan, run_number, environment)
            reference["normal_user_trajectory"].append({"run_number": run_number,
                "executed_file": f"android-api19-executed-trajectory-run{run_number}.json",
                "step_count": len(execute["steps"]), "stability": "VISUAL_REVIEW_REQUIRED"})
    (args.out / "android-api19-reference-trajectory.json").write_text(
        json.dumps(reference, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")
    print(f"API19 reference captured: {len(reference['cold_start']['states'])} cold states, "
          f"{len(reference['normal_user_trajectory'])} replay states, APK {actual}")


if __name__ == "__main__":
    main()
