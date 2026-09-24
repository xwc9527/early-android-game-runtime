#!/usr/bin/env python3
"""Fail before a device build when the toolchain or original APK differs."""

import hashlib
import json
import os
from pathlib import Path
import subprocess
import sys


ROOT = Path(__file__).resolve().parents[1]
APK = ROOT / "samples" / "org.jfedor.frozenbubble_8.apk"
EXPECTED_SHA = "57f4735297befc68c0a7aa6cd9e442ecd250b1b2b38104324a12b6c2d4e18569"


def command(*args):
    return subprocess.check_output(args, text=True).strip()


def main():
    if len(sys.argv) != 2:
        print("usage: verify-iphoneos-environment.py <output.json>", file=sys.stderr)
        return 2
    try:
        xcode = command("xcodebuild", "-version").splitlines()
        sdk = command("xcrun", "--sdk", "iphoneos", "--show-sdk-version")
        digest = hashlib.sha256(APK.read_bytes()).hexdigest()
        if xcode[0] != "Xcode 27.0" or sdk != "27.0" or digest != EXPECTED_SHA:
            raise ValueError(f"Xcode={xcode[0]} SDK={sdk} APK={digest}")
        payload = {
            "schema": "agr.ios27-iphoneos-environment.v1",
            "runner_image": os.environ.get("ImageOS", "local"),
            "runner_image_version": os.environ.get("ImageVersion", "local"),
            "runner_arch": command("uname", "-m"),
            "macos_version": command("sw_vers", "-productVersion"),
            "xcode_version": xcode[0],
            "xcode_build": xcode[1] if len(xcode) > 1 else "",
            "sdk_name": "iphoneos", "sdk_version": sdk,
            "deployment_target": "15.0",
            "commit": command("git", "-C", str(ROOT), "rev-parse", "HEAD"),
            "tree": command("git", "-C", str(ROOT), "rev-parse", "HEAD^{tree}"),
            "apk_sha256": digest,
        }
        path = Path(sys.argv[1])
        path.parent.mkdir(parents=True, exist_ok=True)
        path.write_text(json.dumps(payload, indent=2) + "\n", encoding="utf-8")
        return 0
    except (OSError, ValueError, IndexError, subprocess.CalledProcessError) as error:
        print(f"ENVIRONMENT_BASELINE_MISMATCH {error}", file=sys.stderr)
        return 3


if __name__ == "__main__":
    sys.exit(main())
