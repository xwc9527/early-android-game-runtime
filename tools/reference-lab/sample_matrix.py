#!/usr/bin/env python3
"""Verify the five locked APKs and extract their API19 launch identities."""

import argparse
import hashlib
import json
import re
import subprocess
import zipfile
from pathlib import Path


def sha256(path):
    digest = hashlib.sha256()
    with path.open("rb") as stream:
        for chunk in iter(lambda: stream.read(1024 * 1024), b""):
            digest.update(chunk)
    return digest.hexdigest()


def quoted_field(text, key):
    match = re.search(r"(?:^|\s)" + re.escape(key) + r"='([^']*)'", text)
    return match.group(1) if match else None


def matrix(lock_path, apk_dir, aapt):
    lock = json.loads(lock_path.read_text())
    if lock.get("schema_version") != 1 or len(lock.get("samples", [])) != 5:
        raise ValueError("expected the repository's five-sample F-Droid lock")
    result = []
    for sample in lock["samples"]:
        apk = apk_dir / (sample["id"] + ".apk")
        if sha256(apk) != sample["sha256"]:
            raise ValueError("locked APK hash mismatch: " + sample["id"])
        badging = subprocess.check_output([str(aapt), "dump", "badging", str(apk)], text=True)
        lines = badging.splitlines()
        package_line = next((line for line in lines if line.startswith("package:")), "")
        launch_line = next((line for line in lines if line.startswith("launchable-activity:")), "")
        sdk_line = next((line for line in lines if line.startswith("sdkVersion:")), "")
        package = quoted_field(package_line, "name")
        activity = quoted_field(launch_line, "name")
        if package != sample["package"] or not activity:
            raise ValueError("APK manifest identity or launcher missing: " + sample["id"])
        min_sdk = int(sdk_line.split("'", 2)[1]) if sdk_line else None
        if min_sdk is not None and min_sdk > 19:
            raise ValueError("APK requires an SDK newer than API19: " + sample["id"])
        with zipfile.ZipFile(apk) as archive:
            native = sorted(name for name in archive.namelist()
                            if name.startswith("lib/") and name.endswith(".so"))
        result.append({"id": sample["id"], "package": package,
                       "version_code": sample["version_code"], "apk_sha256": sample["sha256"],
                       "apk": str(apk), "component": package + "/" + activity,
                       "min_sdk": min_sdk, "native_libraries": native})
    return {"schema_version": 1, "baseline": "android-4.4.4_r2",
            "samples": result}


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--lock", required=True, type=Path)
    parser.add_argument("--apk-dir", required=True, type=Path)
    parser.add_argument("--aapt", required=True, type=Path)
    parser.add_argument("--out", required=True, type=Path)
    args = parser.parse_args()
    document = matrix(args.lock, args.apk_dir, args.aapt)
    args.out.parent.mkdir(parents=True, exist_ok=True)
    args.out.write_text(json.dumps(document, indent=2) + "\n")
    print(json.dumps({"sample_ids": [sample["id"] for sample in document["samples"]]}))


if __name__ == "__main__":
    main()
