#!/usr/bin/env python3
"""Select only the installed iOS 27.0 Simulator used for device comparison."""

import hashlib
import json
import os
from pathlib import Path
import subprocess
import sys


ROOT = Path(__file__).resolve().parents[1]
RUNTIME_ID = "com.apple.CoreSimulator.SimRuntime.iOS-27-0"
PRODUCT_VERSION = "27.0"
APK_NAME = "org.jfedor.frozenbubble_8.apk"
APK_SHA256 = "57f4735297befc68c0a7aa6cd9e442ecd250b1b2b38104324a12b6c2d4e18569"


def command(*args):
    return subprocess.check_output(args, text=True).strip()


def simctl_json(kind):
    return json.loads(command("xcrun", "simctl", "list", kind, "-j"))


def select(runtimes, device_types, devices, requested=""):
    if requested and requested != RUNTIME_ID:
        raise ValueError(f"requested runtime {requested} is not {RUNTIME_ID}")
    matches = [r for r in runtimes if r.get("identifier") == RUNTIME_ID
               and r.get("version") == PRODUCT_VERSION and r.get("isAvailable")]
    if not matches:
        raise ValueError("exact iOS 27.0 Simulator runtime is unavailable")
    iphones = [d for d in device_types if d.get("identifier", "").startswith(
        "com.apple.CoreSimulator.SimDeviceType.iPhone-") and d.get("isAvailable", True)]
    if not iphones:
        raise ValueError("no available iPhone Simulator device type")
    iphones.sort(key=lambda d: ("iPhone 17" not in d.get("name", ""),
                                d.get("name", "")))
    device_type = iphones[0]
    device_id = device_type["identifier"]
    existing = next((d for d in devices.get(RUNTIME_ID, [])
                     if d.get("deviceTypeIdentifier") == device_id
                     and d.get("isAvailable", True)), None)
    return matches[0], device_type, existing


def main():
    if len(sys.argv) != 2:
        print("usage: select-simulator-runtime.py <ci-environment.json>", file=sys.stderr)
        return 2
    try:
        runtime, device_type, existing = select(
            simctl_json("runtimes").get("runtimes", []),
            simctl_json("devicetypes").get("devicetypes", []),
            simctl_json("devices").get("devices", {}),
            os.environ.get("AGR_SIMULATOR_RUNTIME", "").strip())
        xcode_lines = command("xcodebuild", "-version").splitlines()
        xcode_version = xcode_lines[0]
        sdk = command("xcrun", "--sdk", "iphonesimulator", "--show-sdk-version")
        if xcode_version != "Xcode 27.0" or sdk != PRODUCT_VERSION:
            raise ValueError(f"toolchain mismatch: {xcode_version}, SDK {sdk}")
        apk = ROOT / "samples" / APK_NAME
        digest = hashlib.sha256(apk.read_bytes()).hexdigest()
        if digest != APK_SHA256:
            raise ValueError(f"original APK hash mismatch: {digest}")
        payload = {
            "schema": "agr.ios27-simulator-environment.v1",
            "runner_image": os.environ.get("ImageOS", "local"),
            "runner_image_version": os.environ.get("ImageVersion", "local"),
            "runner_arch": command("uname", "-m"),
            "macos_version": command("sw_vers", "-productVersion"),
            "xcode_version": xcode_version,
            "xcode_build": xcode_lines[1] if len(xcode_lines) > 1 else "",
            "sdk_name": "iphonesimulator",
            "sdk_version": sdk,
            "physical_target_os": PRODUCT_VERSION,
            "simulator_runtime_requested": RUNTIME_ID,
            "simulator_runtime_actual": RUNTIME_ID,
            "simulator_runtime_version": runtime["version"],
            "simulator_runtime_build": runtime.get("buildversion", ""),
            "os_version_parity": "EXACT_27_0",
            "simulator_device_type_requested": device_type["identifier"],
            "simulator_device_type_actual": device_type["identifier"],
            "simulator_device_type_name": device_type["name"],
            "udid": existing["udid"] if existing else "",
            "create_device": existing is None,
            "commit": command("git", "-C", str(ROOT), "rev-parse", "HEAD"),
            "tree": command("git", "-C", str(ROOT), "rev-parse", "HEAD^{tree}"),
            "apk_sha256": digest,
        }
        Path(sys.argv[1]).parent.mkdir(parents=True, exist_ok=True)
        Path(sys.argv[1]).write_text(json.dumps(payload, indent=2) + "\n", encoding="utf-8")
        print(payload["udid"] or "CREATE")
        return 0
    except (OSError, subprocess.CalledProcessError, ValueError, KeyError) as error:
        print(f"ENVIRONMENT_BASELINE_MISMATCH {error}", file=sys.stderr)
        return 3


if __name__ == "__main__":
    sys.exit(main())
