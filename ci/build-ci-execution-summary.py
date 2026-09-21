#!/usr/bin/env python3
"""Record exact-tree evidence for the CI execution-composition validation."""
from __future__ import annotations

import json
import os
import pathlib
import subprocess

ROOT = pathlib.Path(__file__).resolve().parents[1]


def git(*args: str) -> str:
    return subprocess.check_output(["git", *args], cwd=ROOT, text=True).strip()


def cache_status(name: str) -> str:
    value = os.environ.get(name)
    if value is None or value == "not-run":
        return "not-run"
    if value.lower() == "true":
        return "hit"
    if value.lower() == "false" or value == "":
        return "miss"
    return value


def main() -> None:
    setup_timings = []
    for timing_path in (
        ROOT / "build/sample-preparation-evidence/ci-stage-timings.jsonl",
        ROOT / "build/artifacts/ci-stage-timings.jsonl",
        ROOT / "build/iphoneos-evidence/ci-stage-timings.jsonl",
    ):
        if timing_path.is_file():
            setup_timings.extend(json.loads(line) for line in timing_path.read_text(encoding="utf-8").splitlines() if line)
    outcomes = {
        "source_contract": os.environ.get("STAGE_SOURCE_CONTRACT", "skipped"),
        "setup": os.environ.get("STAGE_SETUP", "skipped"),
        "focused_probe": os.environ.get("STAGE_FOCUSED", "skipped"),
        "runtime_contracts": os.environ.get("STAGE_CONTRACTS", "skipped"),
        "bounded_smoke": os.environ.get("STAGE_SMOKE", "skipped"),
        "real_apk_regressions": os.environ.get("STAGE_REGRESSIONS", "skipped"),
        "iphoneos_build": os.environ.get("STAGE_IPHONEOS", "skipped"),
    }
    if os.environ.get("RUN_KIND") == "validation":
        required_stages = {
            "sample_preparation", "dependency_preparation", "compile_link",
            "simulator_boot_wait", "simulator_boot_total", "install",
            "focused_probe", "runtime_contracts", "bounded_smoke",
            "real_apk_regressions", "iphoneos_build",
        }
        present_stages = {item.get("stage") for item in setup_timings if item.get("exit_code") == 0}
        missing = sorted(required_stages - present_stages)
        if missing:
            raise SystemExit(f"validation timing evidence missing successful stages: {missing}")
    result = {
        "schema_version": 1,
        "purpose": "ci-execution-composition-validation",
        "tested_commit": git("rev-parse", "HEAD"),
        "tested_tree": git("rev-parse", "HEAD^{tree}"),
        "workflow_run_id": os.environ.get("GITHUB_RUN_ID", "local"),
        "run_kind": os.environ.get("RUN_KIND", "discovery"),
        "sample_profile": os.environ.get("AGR_SIMULATOR_PROFILE", "full"),
        "cache": {
            "samples_hit": cache_status("CACHE_SAMPLES_HIT"),
            "samples_seed_hit": cache_status("CACHE_SAMPLES_SEED_HIT"),
            "angle_hit": cache_status("CACHE_ANGLE_HIT"),
            "rust_hit": cache_status("CACHE_RUST_HIT"),
            "iphoneos_samples_hit": cache_status("CACHE_IPHONEOS_SAMPLES_HIT"),
            "iphoneos_angle_hit": cache_status("CACHE_IPHONEOS_ANGLE_HIT"),
            "iphoneos_rust_hit": cache_status("CACHE_IPHONEOS_RUST_HIT"),
        },
        "setup_stage_timings": setup_timings,
        "test_stage_outcomes": outcomes,
    }
    output = ROOT / "build/artifacts/ci-validation-summary.json"
    output.parent.mkdir(parents=True, exist_ok=True)
    output.write_text(json.dumps(result, indent=2) + "\n", encoding="utf-8")
    print(json.dumps(result, sort_keys=True))


if __name__ == "__main__":
    main()
