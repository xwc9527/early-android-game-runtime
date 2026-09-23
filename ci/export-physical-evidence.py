#!/usr/bin/env python3
"""Export one identity-consistent AGR physical trace bundle from Documents."""

import argparse
import hashlib
import json
import os
import pathlib
import shutil
import subprocess
import sys
import tempfile

CURRENT_MANIFEST = "agr-current-manifest.json"
LEGACY = {
    "run": "agr-physical-run.json",
    "trace": "agr-physical-trace.ndjson",
    "runtime": "agr-physical-runtime.json",
    "crash": "agr-physical-crash.bin",
}
PREVIOUS = {
    "run": "agr-prev-run.json",
    "trace": "agr-prev-trace.ndjson",
    "runtime": "agr-prev-runtime.json",
    "crash": "agr-prev-crash.bin",
}


def sha256(path):
    h = hashlib.sha256()
    with pathlib.Path(path).open("rb") as f:
        for block in iter(lambda: f.read(1024 * 1024), b""):
            h.update(block)
    return h.hexdigest()


def read_json(path):
    try:
        return json.loads(pathlib.Path(path).read_text(encoding="utf-8"))
    except (OSError, UnicodeDecodeError, json.JSONDecodeError):
        return None


def remote_pull(bundle, remote, local, udid=None):
    local.parent.mkdir(parents=True, exist_ok=True)
    cmd = ["pymobiledevice3", "apps", "pull", "--documents"]
    if udid:
        cmd += ["--udid", udid]
    cmd += [bundle, remote, str(local)]
    subprocess.run(cmd, check=True)


def pull_one(args, remote, local):
    # A failed device pull must never be mistaken for a previous export left at
    # the same path. Each export also uses a fresh staging directory.
    local.unlink(missing_ok=True)
    if args.documents:
        source = args.documents.joinpath(*pathlib.PurePosixPath(remote).parts)
        if not source.is_file():
            return False
        local.parent.mkdir(parents=True, exist_ok=True)
        shutil.copyfile(source, local)
        return True
    try:
        remote_pull(args.bundle_id, remote, local, args.udid)
        return local.is_file()
    except subprocess.CalledProcessError:
        local.unlink(missing_ok=True)
        return False


def names_for(manifest, legacy=False, previous=False):
    if legacy:
        return dict(LEGACY)
    files = manifest.get("files") if isinstance(manifest, dict) else None
    if not isinstance(files, dict):
        return None
    result = {}
    expected = {"run": "agr-prev-run.json", "trace": "agr-prev-trace.ndjson",
                "runtime": "agr-prev-runtime.json", "crash": "agr-prev-crash.bin"} if previous else {
                    "run": "agr-current-run.json", "trace": "agr-current-trace.ndjson",
                    "runtime": "agr-current-runtime.json", "crash": "agr-current-crash.bin"}
    for key in ("run", "trace", "runtime", "crash"):
        item = files.get(key)
        name = item.get("name") if isinstance(item, dict) else None
        if name is not None and name != expected[key]:
            return None
        result[key] = name
    return result


def identity_check(run, runtime, trace_events):
    if not isinstance(run, dict):
        return False, "run_missing_or_invalid"
    keys = ("run_id", "process_launch_id", "commit", "tree")
    identity = {key: run.get(key) for key in keys}
    if not all(identity.values()):
        return False, "run_identity_incomplete"
    if isinstance(runtime, dict) and any(runtime.get(k) not in (None, v) for k, v in identity.items()):
        return False, "runtime_identity_mismatch"
    for event in trace_events:
        for key, value in identity.items():
            if event.get(key) not in (None, value):
                return False, "trace_identity_mismatch"
    return True, ""


def manifest_identity_check(manifest, run):
    if manifest is None:
        return False, "manifest_unavailable"
    if not isinstance(manifest, dict) or not isinstance(run, dict):
        return False, "manifest_or_run_invalid"
    for key in ("run_id", "process_launch_id", "commit", "tree"):
        if manifest.get(key) != run.get(key):
            return False, "manifest_{}_mismatch".format(key)
    return True, ""


def main():
    p = argparse.ArgumentParser()
    p.add_argument("--bundle-id", required=True)
    p.add_argument("--udid")
    p.add_argument("--documents", type=pathlib.Path,
                   help="read an already exported Documents folder instead of connecting to USB")
    p.add_argument("--run-id", help="export previous/<run_id>; default exports current")
    p.add_argument("--output", required=True, type=pathlib.Path)
    args = p.parse_args()
    out = args.output.resolve()
    out.parent.mkdir(parents=True, exist_ok=True)
    if out.exists() and (not out.is_dir() or any(out.iterdir())):
        raise SystemExit("output must be a new or empty directory; refusing to mix with prior export")
    stage = pathlib.Path(tempfile.mkdtemp(prefix=".agr-physical-export-", dir=out.parent))

    previous = bool(args.run_id)
    base = pathlib.PurePosixPath("previous") / args.run_id if previous else pathlib.PurePosixPath()
    manifest_remote = base / ("manifest.json" if previous else CURRENT_MANIFEST)
    manifest_path = stage / "manifest.before.json"
    if not pull_one(args, str(manifest_remote), manifest_path):
        # Pre-manifest releases are supported as legacy input, without inventing a manifest.
        before = None
        if previous:
            probe = stage / "previous-run-probe.json"
            file_names = dict(PREVIOUS) if pull_one(args, str(base / PREVIOUS["run"]), probe) else dict(LEGACY)
        else:
            file_names = dict(LEGACY)
        legacy = True
    else:
        before = read_json(manifest_path)
        if not isinstance(before, dict):
            raise SystemExit("manifest is unreadable; evidence not exported")
        legacy = False
        file_names = names_for(before, previous=previous)
        if not file_names:
            raise SystemExit("manifest has no file map")
        if previous and before.get("run_id") not in (None, args.run_id):
            raise SystemExit("requested run id disagrees with archive manifest")

    source_files = {}
    files_meta = (before or {}).get("files", {}) if isinstance(before, dict) else {}
    for key, name in file_names.items():
        if not name:
            source_files[key] = {"state": "NOT_GENERATED", "sha256": None}
            continue
        local = stage / name
        state = files_meta.get(key, {}).get("state") if isinstance(files_meta.get(key), dict) else None
        should_pull = legacy or str(state or "").upper() not in (
            "MISSING", "OPTIONAL_ABSENT", "NOT_GENERATED")
        if not should_pull:
            source_files[key] = {"name": name, "state": state, "sha256": None}
            continue
        remote = base / name
        present = pull_one(args, str(remote), local)
        source_files[key] = {"name": name, "state": "PRESENT" if present else "MISSING",
                             "size": local.stat().st_size if present else None,
                             "sha256": sha256(local) if present else None}

    # Re-read manifest after copying. A changing or actively written run is never sealed.
    manifest_after_path = stage / "manifest.after.json"
    after_ok = pull_one(args, str(manifest_remote), manifest_after_path)
    after = read_json(manifest_after_path) if after_ok else None
    same_manifest = before is None or (isinstance(after, dict) and before == after)
    source_state = (before or {}).get("archive_state", "LEGACY")
    trace_state = (((before or {}).get("files") or {}).get("trace") or {}).get("state", "UNKNOWN")
    required_present = all(source_files.get(key, {}).get("state") == "PRESENT"
                           for key in ("run", "trace", "runtime"))
    sealed = (previous and source_state == "ARCHIVED" or (
        not previous and source_state == "CURRENT" and trace_state == "PRESENT" and
        source_files.get("runtime", {}).get("state") == "PRESENT")) and required_present
    run = read_json(stage / str(file_names.get("run") or ""))
    runtime = read_json(stage / str(file_names.get("runtime") or ""))
    trace_path = stage / str(file_names.get("trace") or "")
    events, truncated = [], False
    if trace_path.is_file():
        for line in trace_path.read_bytes().splitlines():
            if not line.strip():
                continue
            try:
                events.append(json.loads(line.decode("utf-8")))
            except (UnicodeDecodeError, json.JSONDecodeError):
                truncated = True
    identity_ok, identity_error = identity_check(run, runtime, events)
    manifest_identity_ok, manifest_identity_error = ((True, "") if legacy else
                                                       manifest_identity_check(before, run))
    expected_archive_id = args.run_id if previous else None
    identity_ok = identity_ok and (expected_archive_id is None or run.get("run_id") == expected_archive_id)
    consistent = identity_ok and manifest_identity_ok and same_manifest and not truncated and required_present and sealed
    snapshot_state = "SEALED_CONSISTENT" if consistent and sealed else (
        "ACTIVE_OR_CHANGED" if not same_manifest or not sealed else "INCOMPLETE_OR_MIXED")

    # Cross-check any device-side manifest digest and size; always hash the copied bytes.
    digest_errors = []
    for key, item in source_files.items():
        expected = (files_meta.get(key) or {}).get("sha256") if isinstance(files_meta, dict) else None
        expected_size = (files_meta.get(key) or {}).get("size") if isinstance(files_meta, dict) else None
        if item.get("state") == "PRESENT" and expected and item.get("sha256") != expected:
            digest_errors.append(key)
        elif item.get("state") == "PRESENT" and expected_size is not None and item.get("size") != expected_size:
            digest_errors.append(key)
    if digest_errors:
        consistent = False
        snapshot_state = "HASH_MISMATCH"
    bundle = {
        "schema": "agr.physical-export.v1",
        "source": "previous" if previous else ("legacy" if legacy else "current"),
        "requested_run_id": args.run_id,
        "run_id": (run or {}).get("run_id"),
        "process_launch_id": (run or {}).get("process_launch_id"),
        "commit": (run or {}).get("commit"),
        "tree": (run or {}).get("tree"),
        "apk_sha256": (runtime or {}).get("apk_sha256") or (run or {}).get("apk_sha256_actual"),
        "snapshot_state": snapshot_state,
        "sealed": bool(sealed),
        "consistent": bool(consistent),
        "identity_error": identity_error,
        "manifest_identity_error": manifest_identity_error,
        "manifest_stable_during_copy": bool(same_manifest),
        "trace_truncated": truncated,
        "hash_mismatch_files": digest_errors,
        "files": source_files,
        "classification": None,
    }
    if previous and isinstance(before, dict):
        bundle["classification"] = before.get("classification")
    (stage / "export-manifest.json").write_text(json.dumps(bundle, indent=2, sort_keys=True) + "\n", encoding="utf-8")
    if out.exists():
        out.rmdir()
    os.replace(stage, out)
    print(json.dumps(bundle, indent=2, sort_keys=True))
    return 0 if consistent and sealed else 2


if __name__ == "__main__":
    sys.exit(main())
