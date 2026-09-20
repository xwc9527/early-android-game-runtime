#!/usr/bin/env python3
"""Validate closure-attempt accounting and classify a run summary."""

import argparse
import json
import pathlib

ROOT = pathlib.Path(__file__).resolve().parents[1]
INVALID_DEFECTS = {
    "HARNESS_DEFECT", "RUNNER_DEFECT", "COLLECTOR_DEFECT", "ARTIFACT_DEFECT",
    "TIMEOUT_HIERARCHY_DEFECT", "WORKFLOW_DEFECT",
}
TERMINAL_STAGES = {"PASS", "FAIL", "BLOCKED_BY_VALID_FAILURE"}


def validate_ledger(doc):
    errors = []
    policy = doc.get("policy", {})
    attempts = doc.get("attempts", [])
    valid_attempts = [item for item in attempts if item.get("classification") in ("VALID_PASS", "VALID_FAIL")]
    if policy.get("invalid_attempts_consume_budget") is not False:
        errors.append("INVALID attempts must not consume closure budget")
    if policy.get("automatic_reruns_after_invalid") != 1:
        errors.append("exactly one automatic rerun must follow a corrected INVALID attempt")
    if policy.get("second_run_after_valid_fail_requires_approval") is not True:
        errors.append("a second run after VALID_FAIL must require approval")
    for index, item in enumerate(attempts):
        classification = item.get("classification")
        if classification not in ("VALID_PASS", "VALID_FAIL", "INVALID"):
            errors.append(f"attempt {item.get('run_id')} has invalid classification")
        expected = classification in ("VALID_PASS", "VALID_FAIL")
        if item.get("consumes_budget") is not expected:
            errors.append(f"attempt {item.get('run_id')} has wrong consumes_budget")
        if classification == "INVALID" and item.get("defect_class") not in INVALID_DEFECTS:
            errors.append(f"attempt {item.get('run_id')} lacks an infrastructure defect class")
        if index:
            previous = attempts[index - 1]
            if previous.get("classification") == "VALID_FAIL" and not item.get("approval_reference"):
                errors.append(f"attempt {item.get('run_id')} follows VALID_FAIL without explicit approval")
            if item.get("automatic_rerun_of"):
                if previous.get("classification") != "INVALID" or item.get("automatic_rerun_of") != previous.get("run_id"):
                    errors.append(f"attempt {item.get('run_id')} is not the single immediate rerun of an INVALID attempt")
    if doc.get("budget", {}).get("valid_attempts_used") != len(valid_attempts):
        errors.append("valid_attempts_used does not match attempt ledger")
    expected_remaining = max(0, policy.get("valid_attempt_budget", 0) - len(valid_attempts))
    if doc.get("budget", {}).get("valid_attempts_remaining") != expected_remaining:
        errors.append("valid_attempts_remaining does not match attempt ledger")
    return errors


def classify_summary(summary):
    run = summary.get("run", {})
    attempt = run.get("closure_attempt", {})
    if run.get("kind") != "closure":
        return "NOT_APPLICABLE", []
    defects = attempt.get("infrastructure_defects", [])
    stages = attempt.get("required_stages", {})
    evidence = attempt.get("required_evidence", {})
    reasons = []
    if defects:
        reasons.extend(f"infrastructure defect: {item}" for item in defects)
    missing_stages = [name for name, state in stages.items() if state not in TERMINAL_STAGES]
    missing_evidence = [name for name, present in evidence.items() if not present]
    if not stages:
        reasons.append("required closure stages were not recorded")
    if not evidence:
        reasons.append("required closure evidence was not recorded")
    reasons.extend(f"stage lacked configured completion opportunity: {name}" for name in missing_stages)
    reasons.extend(f"required evidence missing: {name}" for name in missing_evidence)
    if reasons:
        return "INVALID", reasons
    failed = any(state in ("FAIL", "BLOCKED_BY_VALID_FAILURE") for state in stages.values())
    target_pass = summary.get("target", {}).get("status") == "pass"
    return ("VALID_FAIL" if failed or not target_pass else "VALID_PASS"), []


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--ledger", default="ci/governance/closure-attempts.json")
    parser.add_argument("--summary")
    parser.add_argument("--invalidate-summary")
    parser.add_argument("--defect", choices=sorted(INVALID_DEFECTS))
    args = parser.parse_args()
    ledger = json.loads((ROOT / args.ledger).read_text(encoding="utf-8"))
    errors = validate_ledger(ledger)
    result = {"ledger_valid": not errors, "errors": errors}
    if args.invalidate_summary:
        if not args.defect:
            errors.append("--invalidate-summary requires --defect")
        else:
            path = ROOT / args.invalidate_summary
            summary = json.loads(path.read_text(encoding="utf-8"))
            attempt = summary.setdefault("run", {}).setdefault("closure_attempt", {})
            defects = attempt.setdefault("infrastructure_defects", [])
            if args.defect not in defects:
                defects.append(args.defect)
            attempt["classification"] = "INVALID"
            attempt["consumes_budget"] = False
            attempt["automatic_rerun_permitted"] = True
            summary["run"]["valid_run"] = False
            summary.setdefault("closure", {})["state"] = "IMPLEMENTED"
            summary["closure"]["eligible_for_merge"] = False
            path.write_text(json.dumps(summary, indent=2) + "\n", encoding="utf-8")
            result["invalidated_summary"] = str(path.relative_to(ROOT))
    if args.summary:
        summary = json.loads((ROOT / args.summary).read_text(encoding="utf-8"))
        classification, reasons = classify_summary(summary)
        result["classification"] = classification
        result["reasons"] = reasons
        declared = summary.get("run", {}).get("closure_attempt", {}).get("classification")
        if declared != classification:
            errors.append(f"declared closure classification {declared} != derived {classification}")
    print(json.dumps(result, separators=(",", ":")))
    return 0 if not errors else 1


if __name__ == "__main__":
    raise SystemExit(main())
