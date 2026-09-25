#!/usr/bin/env python3
"""Verify a source index against a pinned local AOSP checkout."""

import argparse
import hashlib
import json
import os
import subprocess
from pathlib import Path


def verify(index, checkout, external_checkouts=None):
    checkout = checkout.resolve()
    external_checkouts = external_checkouts or {}
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
    external_count = 0
    for entry in (index.get("entries") or {}).values():
        for edge in entry.get("cross_cluster_source_edges") or []:
            repo = edge["source_repo"]
            if repo not in external_checkouts:
                raise ValueError("external source checkout is missing: " + repo)
            external = external_checkouts[repo].resolve()
            external_revision = subprocess.check_output(
                ["git", "-C", str(external), "rev-parse", "HEAD"],
                env=environment, text=True).strip()
            if external_revision != edge["revision"]:
                raise ValueError("external source revision differs: " + repo)
            target = (external / edge["source_file"]).resolve()
            if not target.is_relative_to(external) or not target.is_file():
                raise ValueError("external source file escapes or is missing")
            if hashlib.sha256(target.read_bytes()).hexdigest() != edge["source_sha256"]:
                raise ValueError("external source file digest differs")
            external_count += 1
    return {"source_repo": index.get("source_repo"),
            "revision": revision, "verified_files": len(hashes),
            "verified_external_edges": external_count}


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--index", required=True, type=Path)
    parser.add_argument("--checkout", required=True, type=Path)
    parser.add_argument("--external-checkout", action="append", default=[],
                        metavar="REPO=PATH")
    args = parser.parse_args()
    external = {}
    for mapping in args.external_checkout:
        repo, separator, path = mapping.partition("=")
        if not separator or not repo or not path:
            parser.error("external checkout must be REPO=PATH")
        external[repo] = Path(path)
    print(json.dumps(verify(json.loads(args.index.read_text(encoding="utf-8")),
                            args.checkout, external), sort_keys=True))


if __name__ == "__main__":
    main()
