#!/usr/bin/env python3
"""Validate the expensive-run admission record and resolve the sample set."""
from __future__ import annotations

import json
import os
import pathlib

VALID = ("falsification-discovery", "falsification-holdout")
REQUIRED = (
    "question", "current_uncertainty", "expected_outcome_a", "expected_outcome_b",
    "why_cheaper_test_is_insufficient",
)


def main() -> None:
    request = json.loads(
        pathlib.Path("ci/falsification-run-request.json").read_text(encoding="utf-8"))
    missing = [key for key in REQUIRED if not request.get(key)]
    if missing:
        raise SystemExit(f"run request is missing admission fields: {missing}")
    if request["expensive_runs_used"] >= request["expensive_run_budget"]:
        raise SystemExit("expensive run budget exhausted for this experiment")
    profile = os.environ.get("DISPATCH_PROFILE") or request["sample_set"]
    if profile not in VALID:
        raise SystemExit(f"unknown sample set {profile!r}")
    print(f"profile={profile}")


if __name__ == "__main__":
    main()
