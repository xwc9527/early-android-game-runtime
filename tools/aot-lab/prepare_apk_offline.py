#!/usr/bin/env python3
"""Prepare every selected ARM native ELF in an APK with one public AOT policy."""

import argparse
import hashlib
import json
from pathlib import Path
import subprocess
import sys
import time
import zipfile


def sha256(data):
    return hashlib.sha256(data).hexdigest()


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--apk", required=True)
    parser.add_argument("--out", required=True)
    parser.add_argument("--entry-policy", choices=("all-exidx",), default="all-exidx")
    args = parser.parse_args()
    started = time.perf_counter()
    apk = Path(args.apk)
    out = Path(args.out)
    out.mkdir(parents=True, exist_ok=True)
    apk_data = apk.read_bytes()
    with zipfile.ZipFile(apk) as archive:
        names = archive.namelist()
        if len(names) != len(set(names)):
            raise ValueError("duplicate APK member names")
        available = [abi for abi in ("armeabi-v7a", "armeabi") if any(
            name.startswith(f"lib/{abi}/") and name.endswith(".so") for name in names)]
        if not available:
            raise ValueError("APK has no 32-bit ARM native ELF")
        abi = available[0]
        selected = sorted(name for name in names if name.startswith(f"lib/{abi}/") and
                          name.endswith(".so") and name.count("/") == 2)
        libraries = []
        for ordinal, member in enumerate(selected):
            elf = archive.read(member)
            if not elf.startswith(b"\x7fELF"):
                raise ValueError(f"not an ELF: {member}")
            directory = out / f"elf-{ordinal:03d}-{sha256(elf)[:12]}"
            directory.mkdir()
            input_path = directory / "input-armv7.so"
            input_path.write_bytes(elf)
            command = [sys.executable, str(Path(__file__).with_name("translate_offline.py")),
                       "--elf", str(input_path), "--entry-policy", args.entry_policy,
                       "--load-bias", "runtime", "--relocatable", "--no-diagnostic",
                       "--out", str(directory / "aot_blocks.c"),
                       "--manifest", str(directory / "translation-manifest.json")]
            with (directory / "translation.log").open("w", encoding="utf-8") as log:
                subprocess.run(command, check=True, stdout=log, stderr=subprocess.STDOUT)
            manifest = json.loads((directory / "translation-manifest.json").read_text())
            libraries.append({
                "apk_member": member,
                "elf_sha256": sha256(elf),
                "elf_bytes": len(elf),
                "artifact_c_sha256": manifest["generated_c_sha256"],
                "artifact_c_bytes": manifest["generated_c_bytes"],
                "fast_block_count": manifest["fast_block_count"],
                "preparation_wall_seconds": manifest["preparation_wall_seconds"],
                "output_directory": directory.name,
            })
    result = {
        "schema": "agr.offline-apk-preparation.v1",
        "apk_sha256": sha256(apk_data),
        "apk_bytes": len(apk_data),
        "selected_abi": abi,
        "available_arm_abis": available,
        "entry_policy": args.entry_policy,
        "translation_uses_execution_trace": False,
        "native_library_count": len(libraries),
        "libraries": libraries,
        "total_elf_bytes": sum(item["elf_bytes"] for item in libraries),
        "total_generated_c_bytes": sum(item["artifact_c_bytes"] for item in libraries),
        "total_preparation_wall_seconds": time.perf_counter() - started,
    }
    (out / "preparation.json").write_text(json.dumps(result, indent=2) + "\n")
    print(json.dumps(result, indent=2))


if __name__ == "__main__":
    main()
