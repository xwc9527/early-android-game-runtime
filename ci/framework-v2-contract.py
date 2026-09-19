#!/usr/bin/env python3
"""Deterministic contract for the AGR Framework V2 discovery-to-closure data flow."""

import importlib.util
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
    require(len(upstream["entries"]) >= 10, "encountered Runtime paths are not mapped")
    mapped_subsystems = {entry["subsystem"] for entry in upstream["entries"]}
    import subprocess
    tracked = set(subprocess.check_output(["git", "ls-files"], cwd=ROOT, text=True).splitlines())
    for entry in upstream["entries"]:
        for agr_path in entry["agr_files"]:
            require(agr_path in tracked or any(path.startswith(agr_path.rstrip("/") + "/") for path in tracked),
                    f"AGR mapping is not tracked with exact case: {agr_path}")

    samples = sorted((ROOT / "ci/governance/semantic-diffs").glob("*.json"))
    require(samples, "no real semantic differential is committed")
    for path in samples:
        doc = json.loads(path.read_text(encoding="utf-8"))
        require(not module.validate(doc), f"invalid semantic differential: {path.name}")
        require(doc["first_relevant_difference"], f"missing first difference: {path.name}")
        for agr_path in doc["agr"]["files"]:
            require((ROOT / agr_path).exists(), f"missing AGR counterpart: {agr_path}")
        if doc["upstream"]["files"]:
            require(any(doc["subsystem"].startswith(item) or item.startswith(doc["subsystem"].split("/")[0])
                        for item in mapped_subsystems), f"unmapped subsystem: {doc['subsystem']}")

    state = load("ci/governance/state.json")["active"]
    for key in ("observed_discontinuity", "android_subsystem", "agr_path",
                "active_explanations", "first_proven_semantic_difference", "classification", "next_validation"):
        require(key in state, f"state lacks V2 diagnosis field: {key}")

    schema = load("artifacts/schema/run-summary.schema.json")
    require("diagnosis" in schema["required"], "run summary does not require diagnosis")
    cutpoints = load("ci/governance/diagnostic-cutpoints.json")
    require(cutpoints["rules"]["test_only"] is True, "cut points must be test-only")
    require(cutpoints["rules"]["production_shortcut"] is False, "cut points became production shortcuts")
    print(f"framework-v2 contract passed: {len(upstream['entries'])} mappings, {len(samples)} semantic differentials")


if __name__ == "__main__":
    main()
