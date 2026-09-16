#!/usr/bin/env python3
"""Static scan and clustering pre-pass for the Simulator compatibility jobs."""
from __future__ import annotations

import argparse
import json
import pathlib
import re
import subprocess
import tempfile
import zipfile

NEEDED = re.compile(r"NEEDED\s+Shared library: \[(.+?)\]")
UNDEFINED = re.compile(r"\bUND\b.*?\s([A-Za-z_.$][A-Za-z0-9_.$@]*)$")


def inspect_elf(data: bytes) -> dict:
    with tempfile.NamedTemporaryFile(suffix=".so") as handle:
        handle.write(data); handle.flush()
        command = ["xcrun", "llvm-readelf", "--dynamic", "--dyn-symbols", handle.name]
        text = subprocess.run(command, check=True, text=True, capture_output=True).stdout
    return {
        "needed": sorted(set(NEEDED.findall(text))),
        "imports": sorted(set(UNDEFINED.findall(text, re.MULTILINE))),
    }


def scan(sample: dict, root: pathlib.Path) -> dict:
    apk = root / "samples" / f"{sample['id']}.apk"
    with zipfile.ZipFile(apk) as archive:
        names = archive.namelist()
        arm = [name for name in names if name.startswith(("lib/armeabi-v7a/", "lib/armeabi/")) and name.endswith(".so")]
        libraries = []
        needed: set[str] = set()
        imports: set[str] = set()
        for name in arm:
            elf = inspect_elf(archive.read(name))
            libraries.append({"member": name, **elf})
            needed.update(elf["needed"]); imports.update(elf["imports"])
        has_dex = any(name == "classes.dex" or re.fullmatch(r"classes\d+\.dex", name) for name in names)
    mode = "mixed" if arm and has_dex else "native" if arm else "dex" if has_dex else "resources"
    cluster_material = [mode, *sorted(needed)]
    return {
        **sample,
        "apk_path": str(apk),
        "mode": mode,
        "has_dex": has_dex,
        "armv7_libraries": libraries,
        "needed": sorted(needed),
        "imports": sorted(imports),
        "static_cluster": "|".join(cluster_material),
    }


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("--resolved", default="samples/resolved.json")
    parser.add_argument("--output", default="samples/static-scan.json")
    parser.add_argument("--plan", default="App/Resources/batch-plan.json")
    parser.add_argument("--shard-index", type=int, default=0)
    parser.add_argument("--shard-count", type=int, default=1)
    args = parser.parse_args()
    root = pathlib.Path(__file__).resolve().parents[1]
    samples = json.loads((root / args.resolved).read_text(encoding="utf-8"))["samples"]
    selected = [sample for index, sample in enumerate(samples) if index % args.shard_count == args.shard_index]
    records = [scan(sample, root) for sample in selected]
    (root / args.output).parent.mkdir(parents=True, exist_ok=True)
    (root / args.output).write_text(json.dumps({"samples": records}, indent=2), encoding="utf-8")
    plan = {"samples": [{
        "id": item["id"], "package": item["package"], "resource": item["resource"],
        "profile": item["profile"], "has_dex": item["has_dex"],
        "armv7_libraries": [lib["member"] for lib in item["armv7_libraries"]],
        "static_cluster": item["static_cluster"],
    } for item in records]}
    (root / args.plan).write_text(json.dumps(plan, indent=2), encoding="utf-8")


if __name__ == "__main__":
    main()
