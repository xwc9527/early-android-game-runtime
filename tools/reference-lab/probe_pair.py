#!/usr/bin/env python3
"""Boot one matched API19 image and record an actual Frozen Bubble launch."""

import argparse
import hashlib
import json
import os
import signal
import subprocess
import time
from pathlib import Path

from parse_trace_log import parse_lines


def hash_file(path):
    digest = hashlib.sha256()
    with path.open("rb") as stream:
        for chunk in iter(lambda: stream.read(1024 * 1024), b""):
            digest.update(chunk)
    return digest.hexdigest()


def adb(serial, *args, timeout=120, text=True):
    result = subprocess.run(["adb", "-s", serial, *args], check=True,
                            capture_output=True, text=text, timeout=timeout)
    return result.stdout


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--pair", required=True, type=Path)
    parser.add_argument("--root", default="/agr-reference", type=Path)
    parser.add_argument("--apk", required=True, type=Path)
    parser.add_argument("--variant", required=True, choices=("CLEAN", "TRACE"))
    parser.add_argument("--component", default="org.jfedor.frozenbubble/.FrozenBubble")
    parser.add_argument("--scenario", default="cold_start")
    parser.add_argument("--boot-timeout", type=int, default=600)
    parser.add_argument("--settle", type=int, default=20)
    args = parser.parse_args()

    pair = json.loads(args.pair.read_text())
    if pair.get("status") != "BUILD_VERIFIED":
        raise SystemExit("CLEAN/TRACE pair is not build-verified")
    variant = args.variant.lower()
    image = pair[variant]
    out = args.root / ("clean-image" if variant == "clean" else "trace-image") / "build-out"
    product = out / "target/product/generic_x86"
    if hash_file(product / "system.img") != image["image_sha256"]:
        raise SystemExit("system image changed after pair verification")
    if image["execution_mode"] != "int:portable":
        raise SystemExit("reference execution mode is not portable")
    apk_hash = hash_file(args.apk)
    result_dir = args.root / "emulator" / "aosp-r2" / variant / args.scenario
    result_dir.mkdir(parents=True, exist_ok=True)
    record_path = result_dir / "probe.json"
    record = {"status": "FAILED", "stage": "launch_emulator", "variant": args.variant,
              "baseline": "android-4.4.4_r2", "image_sha256": image["image_sha256"],
              "apk_sha256": apk_hash, "scenario": args.scenario,
              "execution_mode": "int:portable"}
    port = 5554 if variant == "clean" else 5556
    serial = f"emulator-{port}"
    emulator = args.root / "clean-image/build-out/host/linux-x86/bin/emulator"
    command = [str(emulator), "-sysdir", str(product), "-system", str(product / "system.img"),
               "-ramdisk", str(product / "ramdisk.img"), "-data", str(result_dir / "userdata.img"),
               "-no-window", "-no-audio", "-no-boot-anim", "-no-snapshot",
               "-ports", f"{port},{port + 1}",
               "-prop", "dalvik.vm.execution-mode=int:portable"]
    if (product / "kernel").is_file():
        command += ["-kernel", str(product / "kernel")]
    if (product / "userdata.img").is_file():
        command += ["-initdata", str(product / "userdata.img")]
    if os.access("/dev/kvm", os.R_OK | os.W_OK):
        command += ["-qemu", "-enable-kvm"]
        record["accel"] = "kvm"
    else:
        record["accel"] = "tcg"
    record["command"] = command
    process = None
    try:
        with (result_dir / "emulator.log").open("wb") as log:
            process = subprocess.Popen(command, stdout=log, stderr=subprocess.STDOUT,
                                       start_new_session=True)
            deadline = time.monotonic() + args.boot_timeout
            record["stage"] = "boot"
            while time.monotonic() < deadline:
                if process.poll() is not None:
                    raise RuntimeError(f"emulator exited with {process.returncode}")
                try:
                    completed = adb(serial, "shell", "getprop", "sys.boot_completed", timeout=12).strip()
                except (subprocess.SubprocessError, OSError):
                    completed = ""
                if completed == "1":
                    break
                time.sleep(5)
            else:
                raise RuntimeError("API19 boot timed out")
            record["release"] = adb(serial, "shell", "getprop", "ro.build.version.release").strip()
            record["sdk"] = adb(serial, "shell", "getprop", "ro.build.version.sdk").strip()
            record["live_execution_mode"] = adb(
                serial, "shell", "getprop", "dalvik.vm.execution-mode").strip()
            record["fingerprint"] = adb(serial, "shell", "getprop", "ro.build.fingerprint").strip()
            if (record["release"], record["sdk"], record["live_execution_mode"]) != \
                    ("4.4.4", "19", "int:portable"):
                raise RuntimeError("guest release, SDK, or execution mode mismatched")
            record["stage"] = "package_manager"
            packages = adb(serial, "shell", "pm", "list", "packages", timeout=60)
            if "package:com.android.settings" not in packages:
                raise RuntimeError("package manager did not list Settings")
            record["stage"] = "install"
            install = adb(serial, "install", "-r", str(args.apk), timeout=240)
            if "Success" not in install:
                raise RuntimeError("APK installation did not succeed: " + install.strip())
            record["install_result"] = install.strip()
            adb(serial, "logcat", "-c", timeout=30)
            record["stage"] = "activity"
            record["activity_result"] = adb(
                serial, "shell", "am", "start", "-W", "-n", args.component,
                timeout=120).strip()
            if "Status: ok" not in record["activity_result"]:
                raise RuntimeError("Activity launch did not report Status: ok")
            time.sleep(args.settle)
            record["stage"] = "capture"
            record["activity_state"] = adb(
                serial, "shell", "dumpsys", "activity", "activities", timeout=60)
            package = args.component.split("/")[0]
            if not any("mResumedActivity" in line and package in line
                       for line in record["activity_state"].splitlines()):
                raise RuntimeError("sample activity is not resumed")
            adb(serial, "shell", "screencap", "-p", "/sdcard/agr-reference.png", timeout=60)
            adb(serial, "pull", "/sdcard/agr-reference.png", str(result_dir / "screen.png"),
                timeout=60)
            screenshot = result_dir / "screen.png"
            if not screenshot.read_bytes().startswith(b"\x89PNG\r\n\x1a\n"):
                raise RuntimeError("screenshot is not PNG")
            record["screenshot_sha256"] = hash_file(screenshot)
            if variant == "trace":
                logcat = adb(serial, "logcat", "-d", "-v", "threadtime", timeout=90)
                (result_dir / "trace.logcat").write_text(logcat)
                events = parse_lines(logcat.splitlines())
                events_path = result_dir / "events.ndjson"
                events_path.write_text("".join(json.dumps(event, sort_keys=True) + "\n"
                                               for event in events))
                record["event_count"] = len(events)
                evidence = {"variant": "TRACE", "instrumented": True,
                            "role": "dependency_mapper", "baseline": "android-4.4.4_r2",
                            "image_sha256": image["image_sha256"], "apk_sha256": apk_hash,
                            "scenario": args.scenario, "events_sha256": hash_file(events_path)}
                (result_dir / "trace-run.json").write_text(json.dumps(evidence, indent=2) + "\n")
            record["status"] = "PASS"
            record["stage"] = "complete"
    except (OSError, RuntimeError, subprocess.SubprocessError, ValueError) as exc:
        record["error"] = str(exc)
        raise
    finally:
        record_path.write_text(json.dumps(record, indent=2) + "\n")
        if process is not None and process.poll() is None:
            os.killpg(process.pid, signal.SIGTERM)
            try:
                process.wait(timeout=15)
            except subprocess.TimeoutExpired:
                os.killpg(process.pid, signal.SIGKILL)
        print(json.dumps({"status": record["status"], "stage": record["stage"],
                          "record": str(record_path)}))


if __name__ == "__main__":
    main()
