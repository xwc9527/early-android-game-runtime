"""Boot the uninstrumented Android 4.4.4 CLEAN image.

The image is android-x86 4.4-r5, already shown to report release 4.4.4
and SDK 19. This runner refuses to label that image TRACE.
"""

import argparse
import hashlib
import json
import os
import shutil
import subprocess
import time
from pathlib import Path

ISO_SHA1 = "4c0edceef12bf4b8afb1b8390d94a9af29bbbca8"
ISO_URL = "https://downloads.sourceforge.net/project/android-x86/Release%204.4/android-x86-4.4-r5.iso"


def sha1(path):
    digest = hashlib.sha1()
    with open(path, "rb") as handle:
        for chunk in iter(lambda: handle.read(1024 * 1024), b""):
            digest.update(chunk)
    return digest.hexdigest()


def ensure_iso(iso_path):
    iso_path.parent.mkdir(parents=True, exist_ok=True)
    if not iso_path.exists() or sha1(iso_path) != ISO_SHA1:
        subprocess.check_call(["curl", "-fL", "--retry", "3", "--retry-delay", "5", "-o", str(iso_path), ISO_URL])
    if sha1(iso_path) != ISO_SHA1:
        raise SystemExit("CLEAN image sha1 mismatch")
    return iso_path


def adb_getprop(serial, name):
    result = subprocess.run(
        ["adb", "-s", serial, "shell", "getprop", name],
        check=False, capture_output=True, text=True,
    )
    return result.stdout.replace("\r", "").strip()


def wait_boot(serial, timeout_s):
    subprocess.run(["adb", "start-server"], check=False)
    deadline = time.time() + timeout_s
    while time.time() < deadline:
        subprocess.run(["adb", "connect", serial], check=False, capture_output=True)
        if adb_getprop(serial, "sys.boot_completed") == "1":
            return
        time.sleep(5)
    raise SystemExit("CLEAN guest did not reach boot_completed")


def boot(root, timeout_s):
    root = Path(root)
    iso = ensure_iso(root / "clean-image" / "android-x86-4.4-r5.iso")
    emulator = root / "emulator"
    emulator.mkdir(parents=True, exist_ok=True)
    if not shutil.which("qemu-system-x86_64"):
        raise SystemExit("qemu-system-x86_64 is required")
    kvm = Path("/dev/kvm")
    accel = "kvm" if os.access(kvm, os.R_OK | os.W_OK) else "tcg"
    cpu = "host" if accel == "kvm" else "qemu64"
    (emulator / "qemu-acceleration.txt").write_text(f"accel={accel} cpu={cpu}\n", encoding="utf-8")
    serial = "127.0.0.1:5555"
    command = [
        "qemu-system-x86_64", "-machine", "pc", "-accel", accel, "-cpu", cpu,
        "-smp", "2", "-m", "2048", "-cdrom", str(iso), "-boot", "d",
        "-vga", "std", "-display", "none",
        "-monitor", "tcp:127.0.0.1:4444,server,nowait",
        "-serial", f"file:{emulator / 'serial.log'}",
        "-netdev", "user,id=net0,hostfwd=tcp:127.0.0.1:5555-:5555",
        "-device", "e1000,netdev=net0",
    ]
    log = open(emulator / "qemu.log", "w", encoding="utf-8")
    subprocess.Popen(command, stdout=log, stderr=subprocess.STDOUT)
    wait_boot(serial, timeout_s)
    release = adb_getprop(serial, "ro.build.version.release")
    sdk = adb_getprop(serial, "ro.build.version.sdk")
    if release != "4.4.4" or sdk != "19":
        raise SystemExit(f"CLEAN guest is {release} sdk {sdk}, not Android 4.4.4 / API 19")
    evidence = {
        "variant": "CLEAN",
        "instrumented": False,
        "role": "semantic_oracle",
        "baseline": "android-x86-4.4-r5",
        "oracle_ready": False,
        "live_release": release,
        "live_sdk": sdk,
        "live_fingerprint": adb_getprop(serial, "ro.build.fingerprint"),
        "image_sha1": ISO_SHA1,
        "accel": accel,
    }
    (emulator / "clean-live.json").write_text(json.dumps(evidence, indent=2) + "\n", encoding="utf-8")
    return evidence


def probe_apk(root, apk_path, component, settle_s):
    """Record one CLEAN launch; this does not create TRACE dependency evidence."""
    serial = "127.0.0.1:5555"
    root = Path(root)
    apk_path = Path(apk_path)
    if not apk_path.is_file():
        raise SystemExit("APK does not exist: " + str(apk_path))
    def adb(*args, timeout=120):
        return subprocess.run(["adb", "-s", serial, *args], check=True,
                              capture_output=True, text=True, timeout=timeout).stdout.strip()
    record = {"variant": "CLEAN", "apk_sha256": hashlib.sha256(apk_path.read_bytes()).hexdigest(),
              "component": component, "status": "FAILED", "stage": "package_manager"}
    output = root / "emulator" / "clean-probe.json"
    try:
        packages = adb("shell", "pm", "list", "packages", timeout=45)
        if "package:com.android.settings" not in packages:
            raise RuntimeError("CLEAN package manager did not list com.android.settings")
        record["stage"] = "install"
        install = adb("install", "-r", str(apk_path), timeout=180)
        if "Success" not in install:
            raise RuntimeError("CLEAN APK install did not succeed: " + install)
        record["install_result"] = install
        record["stage"] = "launch"
        launch = adb("shell", "am", "start", "-W", "-n", component)
        record["launch_result"] = launch
        record["stage"] = "capture"
        time.sleep(settle_s)
        remote = "/sdcard/agr-clean-probe.png"
        adb("shell", "screencap", "-p", remote)
        screenshot = root / "emulator" / "clean-probe.png"
        adb("pull", remote, str(screenshot))
        payload = screenshot.read_bytes()
        if not payload.startswith(b"\x89PNG\r\n\x1a\n"):
            raise RuntimeError("CLEAN screenshot is not PNG")
        record.update({"status": "PASS", "stage": "complete",
                       "screenshot_sha256": hashlib.sha256(payload).hexdigest(),
                       "screenshot": str(screenshot),
                       "activity": adb("shell", "dumpsys", "activity", "activities", timeout=60)})
    except (subprocess.SubprocessError, RuntimeError, OSError) as exc:
        record["error"] = str(exc)
        output.write_text(json.dumps(record, indent=2) + "\n", encoding="utf-8")
        raise SystemExit("CLEAN APK probe failed at " + record["stage"] + ": " + str(exc)) from exc
    output.write_text(json.dumps(record, indent=2) + "\n", encoding="utf-8")
    return record


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--root", default="/agr-reference")
    parser.add_argument("--timeout", type=int, default=180)
    parser.add_argument("--apk")
    parser.add_argument("--component")
    parser.add_argument("--settle", type=float, default=8)
    args = parser.parse_args()
    if bool(args.apk) != bool(args.component):
        parser.error("--apk and --component must appear together")
    result = {"boot": boot(Path(args.root), args.timeout)}
    if args.apk:
        result["probe"] = probe_apk(args.root, args.apk, args.component, args.settle)
    print(json.dumps(result, indent=2))


if __name__ == "__main__":
    main()
