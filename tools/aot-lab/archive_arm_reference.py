#!/usr/bin/env python3
"""Archive the local ARM CLEAN/TRACE probe bytes used in AOT route review."""

import argparse
import gzip
import hashlib
import json
import shutil
import zipfile
from pathlib import Path


PACKAGE = "com.onetwofivegames.kungfoobarracuda"
SCENARIO = "aot_armv7_gameplay_lifecycle"
ROOT = Path("emulator/aosp-r2-arm")
COMMON = ("probe.json", "app.maps", "boot.logcat", "emulator.log",
          "zygote-preload.json", "zygote.maps")
TRACE = ("trace.logcat", "trace-run.json", "events.ndjson",
         "trace-direct/trace-all.log")


def digest(path):
    h = hashlib.sha256()
    with path.open("rb") as source:
        for chunk in iter(lambda: source.read(1024 * 1024), b""):
            h.update(chunk)
    return h.hexdigest()


def archive_file(source, target):
    target.parent.mkdir(parents=True, exist_ok=True)
    if source.stat().st_size > 1024 * 1024:
        target = target.with_name(target.name + ".gz")
        with source.open("rb") as src, target.open("wb") as raw:
            with gzip.GzipFile(filename="", mode="wb", fileobj=raw, mtime=0) as dst:
                shutil.copyfileobj(src, dst)
        encoding = "gzip"
    else:
        shutil.copyfile(source, target)
        encoding = "identity"
    if encoding == "gzip":
        with gzip.open(target, "rb") as restored:
            restored_hash = hashlib.sha256()
            for chunk in iter(lambda: restored.read(1024 * 1024), b""):
                restored_hash.update(chunk)
            if restored_hash.hexdigest() != digest(source):
                raise ValueError(f"archive mismatch: {source}")
    elif digest(source) != digest(target):
        raise ValueError(f"archive mismatch: {source}")
    return {"source": str(source), "source_bytes": source.stat().st_size,
            "source_sha256": digest(source), "archive": str(target),
            "archive_bytes": target.stat().st_size,
            "archive_sha256": digest(target), "encoding": encoding}


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--lab", type=Path, required=True)
    parser.add_argument("--out", type=Path, required=True)
    args = parser.parse_args()
    args.out.mkdir(parents=True, exist_ok=True)
    entries = []
    for variant in ("clean", "trace"):
        source_dir = args.lab / ROOT / variant / PACKAGE / SCENARIO
        files = COMMON + (("runtime.logcat",) if variant == "clean" else TRACE)
        for name in files:
            entries.append(archive_file(source_dir / name, args.out / variant / name))
        for screenshot in sorted(source_dir.glob("screen-*.png")):
            entries.append(archive_file(screenshot, args.out / variant / screenshot.name))
    entries.append(archive_file(args.lab / "arm-reference-pair.json",
                                args.out / "arm-reference-pair.json"))
    apk = args.lab / "samples/fdroid/kungfoo-barracuda.apk"
    with zipfile.ZipFile(apk) as source:
        libs = sorted({name.split("/")[1] for name in source.namelist()
                       if name.startswith("lib/") and name.endswith(".so")})
        arm_name = "lib/armeabi-v7a/libKungFooBarracudaNativeActivity.so"
        arm_info = source.getinfo(arm_name)
        arm_sha256 = hashlib.sha256(source.read(arm_name)).hexdigest()
    identity = {"apk_path": str(apk), "apk_sha256": digest(apk),
                "available_native_abis": libs, "armv7_member": arm_name,
                "armv7_uncompressed_bytes": arm_info.file_size,
                "armv7_sha256": arm_sha256}
    (args.out / "apk-native-identity.json").write_text(
        json.dumps(identity, indent=2) + "\n")
    manifest = {"schema_version": 1, "lab_root": str(args.lab),
                "source_files": entries,
                "excluded_build_outputs": ["userdata.img", "guest-framework.jar",
                                           "guest-libdvm.so"],
                "note": "Excluded binary inputs remain hash-bound in pair/probe records."}
    (args.out / "archive-manifest.json").write_text(
        json.dumps(manifest, indent=2) + "\n")


if __name__ == "__main__":
    main()
