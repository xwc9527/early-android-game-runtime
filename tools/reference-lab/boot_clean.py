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
        "live_release": release,
        "live_sdk": sdk,
        "live_fingerprint": adb_getprop(serial, "ro.build.fingerprint"),
        "image_sha1": ISO_SHA1,
        "accel": accel,
    }
    (emulator / "clean-live.json").write_text(json.dumps(evidence, indent=2) + "\n", encoding="utf-8")
    return evidence


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--root", default="/agr-reference")
    parser.add_argument("--timeout", type=int, default=180)
    args = parser.parse_args()
    print(json.dumps(boot(Path(args.root), args.timeout), indent=2))


if __name__ == "__main__":
    main()
