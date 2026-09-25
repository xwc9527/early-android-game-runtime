#!/usr/bin/env python3
"""Verify a source index against a pinned local AOSP checkout."""

import argparse
import hashlib
import json
import os
import subprocess
from pathlib import Path


def verify(index, checkout):
    checkout = checkout.resolve()
    environment = os.environ.copy()
    environment.pop("GIT_DIR", None)
    environment.pop("GIT_WORK_TREE", None)
    revision = subprocess.check_output(
        ["git", "-C", str(checkout), "rev-parse", "HEAD"],
        env=environment, text=True).strip()
    if revision != index.get("revision"):
        raise ValueError("source revision differs from checkout")
    hashes = index.get("source_file_sha256") or {}
    if not hashes:
        raise ValueError("source index has no file hashes")
    for entry in (index.get("entries") or {}).values():
        if not set(entry.get("source_files") or []).issubset(hashes):
            raise ValueError("entry source file lacks a pinned digest")
    for relative, expected in hashes.items():
        target = (checkout / relative).resolve()
        if not target.is_relative_to(checkout) or not target.is_file():
            raise ValueError("source file escapes or is missing: " + relative)
        if hashlib.sha256(target.read_bytes()).hexdigest() != expected:
            raise ValueError("source file digest differs: " + relative)
    return {"source_repo": index.get("source_repo"),
            "revision": revision, "verified_files": len(hashes)}


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--index", required=True, type=Path)
    parser.add_argument("--checkout", required=True, type=Path)
    args = parser.parse_args()
    print(json.dumps(verify(json.loads(args.index.read_text(encoding="utf-8")),
                            args.checkout), sort_keys=True))


if __name__ == "__main__":
    main()
