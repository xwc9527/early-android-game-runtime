#!/usr/bin/env python3
"""Validate the encounter-driven Android 4.4.4 to AGR navigation cache."""

import argparse
import base64
import hashlib
import json
import pathlib
import ssl
import subprocess
import sys
import urllib.request

ROOT = pathlib.Path(__file__).resolve().parents[1]
MAP_PATH = ROOT / "ci/governance/upstream-map.json"
VALID_STATUSES = {"VALID", "STALE", "UNVERIFIED", "INVALID"}


def tracked_files():
    output = subprocess.check_output(["git", "ls-files"], cwd=ROOT, text=True)
    return sorted(line for line in output.splitlines() if line)


def hash_path(path, tracked):
    matches = [item for item in tracked if item == path or item.startswith(path.rstrip("/") + "/")]
    if not matches:
        return None
    digest = hashlib.sha256()
    for item in matches:
        digest.update(item.encode("utf-8") + b"\0")
        digest.update(hashlib.sha256((ROOT / item).read_bytes()).digest())
    return digest.hexdigest()


def evaluate(document, verify_upstream=False):
    errors, entries = [], {}
    baseline = document.get("android_baseline")
    tracked = tracked_files()
    required = {"id", "subsystem", "android_api", "upstream", "agr", "verified_at_commit", "status",
                "dependencies", "observable_semantics", "internal_invariants", "execution_placement",
                "host_substitutions", "known_deviations", "contracts"}
    for index, entry in enumerate(document.get("entries", [])):
        missing = sorted(required - set(entry))
        if missing:
            errors.append(f"entry {index} missing: {','.join(missing)}")
            continue
        entry_id = entry["id"]
        if entry_id in entries:
            errors.append(f"duplicate entry id: {entry_id}")
        declared = entry["status"]
        if declared not in VALID_STATUSES:
            errors.append(f"{entry_id}: invalid status {declared}")
        upstream = entry["upstream"]
        agr = entry["agr"]
        for key in ("revision", "repository", "paths", "symbols", "source_hashes"):
            if key not in upstream:
                errors.append(f"{entry_id}: upstream missing {key}")
        for key in ("paths", "symbols", "source_hashes"):
            if key not in agr:
                errors.append(f"{entry_id}: agr missing {key}")
        effective, reasons = declared, []
        if upstream.get("revision") != baseline:
            effective = "STALE"
            reasons.append("upstream revision differs from map baseline")
        for path in upstream.get("paths", []):
            value = upstream.get("source_hashes", {}).get(path)
            if not value or value == "UNVERIFIED":
                if effective == "VALID": effective = "UNVERIFIED"
                reasons.append(f"upstream source not hash-verified: {path}")
            elif verify_upstream:
                url = upstream.get("source_urls", {}).get(path)
                if not url:
                    effective = "UNVERIFIED" if effective != "INVALID" else effective
                    reasons.append(f"upstream source URL missing: {path}")
                else:
                    try:
                        # Content integrity is pinned by SHA-256 below. This also works on
                        # Windows hosts whose Python trust store lacks the corporate TLS root.
                        context = ssl._create_unverified_context()
                        source = base64.b64decode(urllib.request.urlopen(url, timeout=30, context=context).read())
                        if hashlib.sha256(source).hexdigest() != value:
                            effective = "STALE" if effective != "INVALID" else effective
                            reasons.append(f"upstream source hash changed: {path}")
                        source_text = source.decode("utf-8", errors="ignore")
                        expected_symbols = upstream.get("symbols_by_path", {}).get(path, [])
                        for symbol in expected_symbols:
                            if symbol not in source_text:
                                effective = "INVALID"
                                reasons.append(f"upstream symbol missing in {path}: {symbol}")
                    except Exception as exc:
                        effective = "UNVERIFIED" if effective != "INVALID" else effective
                        reasons.append(f"upstream source unavailable: {path}: {type(exc).__name__}")
        current_hashes = {}
        for path in agr.get("paths", []):
            current = hash_path(path, tracked)
            current_hashes[path] = current
            if current is None:
                effective = "INVALID"
                reasons.append(f"AGR path missing or wrong case: {path}")
            elif agr.get("source_hashes", {}).get(path) != current:
                if effective != "INVALID": effective = "STALE"
                reasons.append(f"AGR source hash changed: {path}")
        entries[entry_id] = {"declared_status": declared, "effective_status": effective,
                             "reasons": reasons, "current_agr_hashes": current_hashes,
                             "dependencies": entry.get("dependencies", [])}
    # Dependency invalidation is evaluated after all entries exist.
    changed = True
    while changed:
        changed = False
        for entry_id, result in entries.items():
            for dependency in result["dependencies"]:
                dep = entries.get(dependency)
                if dep is None:
                    if result["effective_status"] != "INVALID":
                        result["effective_status"] = "INVALID"; changed = True
                    message = f"dependency missing: {dependency}"
                    if message not in result["reasons"]: result["reasons"].append(message)
                elif dep["effective_status"] != "VALID" and result["effective_status"] == "VALID":
                    result["effective_status"] = "STALE"; changed = True
                    result["reasons"].append(f"dependency not VALID: {dependency}")
    return errors, entries


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--map", default=str(MAP_PATH))
    parser.add_argument("--strict", action="store_true", help="fail when any entry is not effectively VALID")
    parser.add_argument("--verify-upstream", action="store_true", help="download pinned source and verify hash/symbols")
    parser.add_argument("--require-valid", action="append", default=[], help="entry id that must be effectively VALID")
    parser.add_argument("--output")
    args = parser.parse_args()
    document = json.loads(pathlib.Path(args.map).read_text(encoding="utf-8"))
    errors, entries = evaluate(document, args.verify_upstream)
    for entry_id in args.require_valid:
        result = entries.get(entry_id)
        if not result or result["effective_status"] != "VALID":
            errors.append(f"required map entry is not VALID: {entry_id}")
    if args.strict:
        errors.extend(f"map entry is not VALID: {key}" for key, value in entries.items()
                      if value["effective_status"] != "VALID")
    report = {"schema_version": 1, "android_baseline": document.get("android_baseline"),
              "entries": entries, "errors": errors, "passed": not errors}
    if args.output:
        output = pathlib.Path(args.output); output.parent.mkdir(parents=True, exist_ok=True)
        output.write_text(json.dumps(report, indent=2) + "\n", encoding="utf-8")
    print(json.dumps(report, separators=(",", ":")))
    return 0 if not errors else 1


if __name__ == "__main__":
    raise SystemExit(main())
