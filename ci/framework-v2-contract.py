#!/usr/bin/env python3
"""Deterministic contract for the AGR Framework V2 discovery-to-closure data flow."""

import importlib.util
import copy
import json
import pathlib

ROOT = pathlib.Path(__file__).resolve().parents[1]


def load(path):
    return json.loads((ROOT / path).read_text(encoding="utf-8"))


def require(condition, message):
    if not condition:
        raise AssertionError(message)


def main():
    spec = importlib.util.spec_from_file_location("semantic_diff", ROOT / "ci/semantic-diff.py")
    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)

    upstream = load("ci/governance/upstream-map.json")
    require(upstream["android_baseline"] == "Android 4.4.4_r2", "wrong upstream baseline")
    require(upstream.get("role") == "NAVIGATION_CACHE_NOT_ORACLE", "upstream map role is ambiguous")
    require(len(upstream["entries"]) >= 10, "encountered Runtime paths are not mapped")
    mapped_subsystems = {entry["subsystem"] for entry in upstream["entries"]}
    map_spec = importlib.util.spec_from_file_location("upstream_map", ROOT / "ci/upstream-map.py")
    map_module = importlib.util.module_from_spec(map_spec); map_spec.loader.exec_module(map_module)
    map_errors, map_entries = map_module.evaluate(upstream)
    require(not map_errors, f"invalid upstream map: {map_errors}")
    require(map_entries["dalvik.nativeactivity.activity_root"]["effective_status"] == "VALID", "current PVS source map is stale")
    stale_fixture = copy.deepcopy(upstream)
    stale_entry = next(item for item in stale_fixture["entries"] if item["id"] == "dalvik.nativeactivity.activity_root")
    stale_entry["agr"]["source_hashes"]["Runtime/DexLoom/game_dex_runner.c"] = "0" * 64
    _, stale_results = map_module.evaluate(stale_fixture)
    require(stale_results["dalvik.nativeactivity.activity_root"]["effective_status"] == "STALE", "AGR hash change does not stale map entry")

    samples = sorted((ROOT / "ci/governance/semantic-diffs").glob("*.json"))
    require(samples, "no real semantic differential is committed")
    for path in samples:
        doc = json.loads(path.read_text(encoding="utf-8"))
        experiment_doc = load("ci/experiments.json")
        experiments = {item["id"] for item in experiment_doc.get("experiments", [])}
        require(not module.validate(doc, experiments), f"invalid semantic differential: {path.name}")
        require(doc["earliest_evidenced_divergence"], f"missing divergence: {path.name}")
        for agr_path in doc["agr"]["files"]:
            require((ROOT / agr_path).exists(), f"missing AGR counterpart: {agr_path}")
        if doc["upstream"]["files"]:
            require(doc["upstream"]["map_entry"] in map_entries, f"unmapped subsystem: {doc['subsystem']}")

    state = load("ci/governance/state.json")["active"]
    for key in ("observed_discontinuity", "android_subsystem", "agr_path",
                "active_explanations", "earliest_evidenced_divergence", "semantic_class", "causal_status",
                "evidence_level", "classification", "next_validation"):
        require(key in state, f"state lacks V2 diagnosis field: {key}")

    schema = load("artifacts/schema/run-summary.schema.json")
    require("diagnosis" in schema["required"], "run summary does not require diagnosis")
    attempt_spec = importlib.util.spec_from_file_location("closure_attempt", ROOT / "ci/closure-attempt.py")
    attempt_module = importlib.util.module_from_spec(attempt_spec); attempt_spec.loader.exec_module(attempt_module)
    ledger = load("ci/governance/closure-attempts.json")
    require(not attempt_module.validate_ledger(ledger), "invalid closure attempt ledger")
    valid_attempts = [item for item in ledger["attempts"]
                      if item["classification"] in ("VALID_PASS", "VALID_FAIL")]
    require(ledger["budget"]["valid_attempts_used"] == len(valid_attempts),
            "valid closure budget does not match the ledger")
    require(all(not item["consumes_budget"] for item in ledger["attempts"]
                if item["classification"] == "INVALID"),
            "INVALID closure run consumed budget")
    latest_attempt = ledger["attempts"][-1]
    if latest_attempt["classification"] == "INVALID":
        require(latest_attempt.get("automatic_rerun") == "AVAILABLE_AFTER_FIX",
                "latest corrected INVALID run lacks automatic rerun")
    if latest_attempt["classification"] == "VALID_FAIL":
        require(ledger["policy"]["second_run_after_valid_fail_requires_approval"] is True,
                "VALID_FAIL does not protect the next closure attempt")
    cutpoints = load("ci/governance/diagnostic-cutpoints.json")
    require(cutpoints["rules"]["test_only"] is True, "cut points must be test-only")
    require(cutpoints["rules"]["production_shortcut"] is False, "cut points became production shortcuts")
    require(not [item for item in load("ci/experiments.json").get("experiments", []) if item.get("enabled")], "enabled experiment in clean framework tree")
    activity = load("ci/governance/semantic-diffs/pvs1-activity-gc-root.json")
    require(module.derived_evidence_level(activity["evidence"]) == "REAL_GAME_CONFIRMED", "evidence level is not artifact-derived")
    print(f"framework-v2.1 contract passed: {len(upstream['entries'])} mappings, {len(samples)} semantic differentials")


if __name__ == "__main__":
    main()
