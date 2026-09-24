#!/usr/bin/env python3
"""Admit a full discovery run only when it asks a discriminating question."""

import argparse
import json
import pathlib

VAGUE = ("run again", "try again", "see what happens", "more logs", "再跑一次", "试试看", "多加点日志")


def main():
    parser = argparse.ArgumentParser(); parser.add_argument("plan"); args = parser.parse_args()
    doc = json.loads(pathlib.Path(args.plan).read_text(encoding="utf-8")); errors = []
    if not doc.get("enabled"):
        print("expensive discovery plan is disabled")
        return 1
    question = doc.get("question", "").strip()
    if not question: errors.append("QUESTION is empty")
    if any(value in question.lower() for value in VAGUE): errors.append("QUESTION is non-discriminating")
    if not doc.get("current_uncertainty"): errors.append("CURRENT UNCERTAINTY is empty")
    for name in ("expected_outcome_a", "expected_outcome_b"):
        outcome = doc.get(name, {})
        if not outcome.get("result") or not outcome.get("excludes"): errors.append(f"{name} must state result and exclusions")
    if not doc.get("why_cheaper_test_is_insufficient", "").strip(): errors.append("WHY CHEAPER TEST IS INSUFFICIENT is empty")
    if doc.get("prior_expensive_runs_without_information_gain", 0) >= 2:
        errors.append("discovery loop breaker: change diagnostic strategy before another expensive run")
    for error in errors: print(f"::error title=AGR expensive-run admission::{error}")
    return 1 if errors else 0


if __name__ == "__main__": raise SystemExit(main())
