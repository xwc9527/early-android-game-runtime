#!/usr/bin/env python3
"""Verify and import every byte from the pinned Gloomy Actions artifact."""

import argparse
import hashlib
import json
import shutil
import zipfile
from pathlib import Path


EXPECTED_ID = 10928445760


def sha256(data):
    return hashlib.sha256(data).hexdigest()


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--zip", type=Path, required=True)
    parser.add_argument("--metadata", type=Path, required=True)
    parser.add_argument("--out", type=Path, required=True)
    args = parser.parse_args()
    metadata = json.loads(args.metadata.read_text(encoding="utf-8"))
    blob = args.zip.read_bytes()
    digest = sha256(blob)
    if metadata.get("id") != EXPECTED_ID or metadata.get("expired") or \
            metadata.get("digest") != "sha256:" + digest or \
            metadata.get("size_in_bytes") != len(blob):
        raise ValueError("CI artifact identity, validity, size, or digest mismatch")
    args.out.mkdir(parents=True, exist_ok=True)
    entries = []
    with zipfile.ZipFile(args.zip) as archive:
        if archive.testzip() is not None:
            raise ValueError("corrupt ZIP member")
        for member in archive.infolist():
            name = Path(member.filename)
            if member.is_dir() or len(name.parts) != 1 or name.name != member.filename:
                raise ValueError(f"unexpected ZIP path: {member.filename}")
            contents = archive.read(member)
            (args.out / name).write_bytes(contents)
            entries.append({"name": name.name, "bytes": len(contents),
                            "sha256": sha256(contents)})
    shutil.copyfile(args.zip, args.out / f"ci-artifact-{EXPECTED_ID}.zip")
    identity = {"schema_version": 1, "artifact_id": EXPECTED_ID,
                "run_id": metadata["workflow_run"]["id"],
                "tested_commit": metadata["workflow_run"]["head_sha"],
                "artifact_sha256": digest, "artifact_bytes": len(blob),
                "members": sorted(entries, key=lambda item: item["name"])}
    (args.out / "artifact-contents.json").write_text(
        json.dumps(identity, indent=2) + "\n", encoding="utf-8")
    print(json.dumps({"artifact_id": EXPECTED_ID, "sha256": digest,
                      "members": len(entries)}))


if __name__ == "__main__":
    main()
