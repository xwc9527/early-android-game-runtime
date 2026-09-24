#!/usr/bin/env python3
"""Validate the Java legacy-migration ledger and the public owner manifest."""

import json
import pathlib
import sys

ROOT = pathlib.Path(__file__).resolve().parents[1]
LEGACY = ROOT / "ci/governance/java-legacy-migration.json"
OWNERS = ROOT / "ci/governance/java-public-owner.json"
BASELINE = ROOT / "ci/governance/java-architecture-baseline.json"
DISPOSITIONS = {
    "KEEP_HOST_BOUNDARY",
    "KEEP_TEST_ORACLE",
    "MIGRATE_DALVIK",
    "MIGRATE_AOSP_JAVA",
    "MIGRATE_AOSP_NATIVE",
    "DELETE_AFTER_PARITY",
}
OWNER_NAMES = {"AOSP_JAVA", "DALVIK_VM", "AOSP_NATIVE", "HOST_SERVICE_HLE", "UNSUPPORTED", "TEST_ONLY"}
HLE_FIELDS = (
    "api19_source",
    "upstream_boundary",
    "why_original_cannot_run",
    "removed_android_dependency",
    "agr_host_replacement",
    "observable_contract",
    "differential_evidence",
)
MAP = {
    "KEEP_HOST_BOUNDARY": "HOST_SERVICE_HLE",
    "KEEP_TEST_ORACLE": "TEST_ONLY",
    "MIGRATE_DALVIK": "DALVIK_VM",
    "MIGRATE_AOSP_JAVA": "AOSP_JAVA",
    "MIGRATE_AOSP_NATIVE": "AOSP_NATIVE",
    "DELETE_AFTER_PARITY": "UNSUPPORTED",
}


def load(path):
    return json.loads(path.read_text(encoding="utf-8"))


def main() -> int:
    errors = []
    legacy = load(LEGACY)
    owners = load(OWNERS)
    baseline = load(BASELINE)
    clusters = legacy.get("clusters", [])
    symbols = owners.get("symbols", [])
    if set(legacy.get("allowed_dispositions", [])) != DISPOSITIONS:
        errors.append("legacy ledger dispositions drifted")
    if set(owners.get("allowed_owners", [])) != OWNER_NAMES:
        errors.append("owner manifest owners drifted")
    seen = {}
    for cluster in clusters:
        symbol = cluster.get("symbol")
        disposition = cluster.get("disposition")
        if disposition not in DISPOSITIONS:
            errors.append(f"invalid disposition for {symbol}")
        if symbol in seen:
            errors.append(f"duplicate legacy cluster {symbol}")
        seen[symbol] = disposition
    production = {}
    owner_by_symbol = {}
    for entry in symbols:
        symbol = entry.get("symbol")
        owner = entry.get("owner")
        if owner not in OWNER_NAMES:
            errors.append(f"invalid owner for {symbol}")
        if symbol in owner_by_symbol:
            errors.append(f"duplicate owner entry {symbol}")
        owner_by_symbol[symbol] = owner
        if entry.get("production"):
            if owner == "TEST_ONLY":
                errors.append(f"TEST_ONLY symbol is production-visible: {symbol}")
            if symbol in production:
                errors.append(f"two production owners for {symbol}")
            production[symbol] = owner
        if owner == "HOST_SERVICE_HLE":
            for field in HLE_FIELDS:
                if not entry.get(field):
                    errors.append(f"HOST_SERVICE_HLE {symbol} missing {field}")
        expected = MAP.get(seen.get(symbol))
        if expected and owner != expected:
            errors.append(f"owner/disposition mismatch for {symbol}: {owner} != {expected}")
    for item in baseline["public_descriptors"]:
        if item["descriptor"] not in seen:
            errors.append(f"baseline symbol missing from legacy ledger: {item['descriptor']}")
        if item["descriptor"] not in owner_by_symbol:
            errors.append(f"baseline symbol missing from owner manifest: {item['descriptor']}")
    if errors:
        for error in errors:
            print(f"::error title=Java owner ledger::{error}")
        return 1
    print(f"java owner ledger: PASS ({len(clusters)} clusters)")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
