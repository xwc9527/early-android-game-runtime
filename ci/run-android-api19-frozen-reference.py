#!/usr/bin/env python3
"""Collect an unmodified Frozen Bubble APK trajectory on Android 4.4.4.

This is an Android reference harness, not part of the AGR Runtime.
"""

import argparse
import hashlib
import json
import pathlib
import subprocess
import time


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
    return {
        "timestamp_utc": time.strftime("%Y-%m-%dT%H:%M:%SZ", time.gmtime()),
        "screenshot": local.name,
        "screenshot_sha256": hashlib.sha256(payload).hexdigest(),
        "process": adb("shell", "ps", check=False),
        "activity": adb("shell", "dumpsys", "activity", "activities", timeout=60, check=False),
    }


def fresh_launch(apk):
    adb("shell", "am", "force-stop", PACKAGE, check=False)
    adb("uninstall", PACKAGE, check=False)
    adb("install", str(apk), timeout=180)
    adb("shell", "pm", "clear", PACKAGE, timeout=60)
    adb("shell", "am", "force-stop", PACKAGE, check=False)
    adb("logcat", "-c")
    return adb("shell", "am", "start", "-W", "-n", ACTIVITY, timeout=60)


def run_cold_start(apk, out, prefix):
    launch = fresh_launch(apk)
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
        plan = json.loads(args.replay.read_text(encoding="utf-8"))
        reference["replay_launch_result"] = fresh_launch(args.apk)
        time.sleep(15)
        reference["normal_user_trajectory"].append({"state": "pre_input", "input": None,
            **capture(args.out, "replay-initial")})
        for index, step in enumerate(plan["steps"]):
            before = capture(args.out, f"step-{index:02d}-before")
            action = step["input"]
            if action["type"] == "tap":
                adb("shell", "input", "tap", str(action["x"]), str(action["y"]))
            elif action["type"] == "keyevent":
                adb("shell", "input", "keyevent", str(action["keycode"]))
            elif action["type"] == "swipe":
                adb("shell", "input", "swipe", *(str(action[key]) for key in
                    ("x0", "y0", "x1", "y1", "duration_ms")))
            else:
                raise RuntimeError(f"unsupported reference input: {action['type']}")
            time.sleep(step.get("wait_seconds", 2))
            after = capture(args.out, f"step-{index:02d}-after")
            reference["normal_user_trajectory"].append({
                "state": step.get("state", "UNCLASSIFIED"), "input": action,
                "before": before, "after": after})
        (args.out / "replay-logcat.txt").write_text(adb("logcat", "-d", "-v", "threadtime", timeout=90), encoding="utf-8")
    (args.out / "android-api19-reference-trajectory.json").write_text(
        json.dumps(reference, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")
    print(f"API19 reference captured: {len(reference['cold_start']['states'])} cold states, "
          f"{len(reference['normal_user_trajectory'])} replay states, APK {actual}")


if __name__ == "__main__":
    main()
