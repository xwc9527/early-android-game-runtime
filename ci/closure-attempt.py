#!/usr/bin/env python3
"""Validate closure accounting, authorization, and run classification."""

import argparse
import json
import pathlib

ROOT = pathlib.Path(__file__).resolve().parents[1]
ATTEMPT_CLASSIFICATIONS = {"VALID_PASS", "VALID_FAIL", "INVALID"}
INVALID_DEFECTS = {
    "HARNESS_DEFECT", "RUNNER_DEFECT", "COLLECTOR_DEFECT", "ARTIFACT_DEFECT",
    "TIMEOUT_HIERARCHY_DEFECT", "WORKFLOW_DEFECT", "EXTERNAL_SERVICE_FAILURE",
}
FAILURE_CLASSIFICATIONS = {
    "ANDROID_SEMANTIC_BUG", "HOST_ADAPTATION_BUG", "AGR_INTERNAL_BUG",
    "HARNESS_BUG", "WORKFLOW_DEFECT", "REFERENCE_MISMATCH", "UNKNOWN",
    "EXTERNAL_SERVICE_FAILURE",
}
TERMINAL_STAGES = {"PASS", "FAIL", "BLOCKED_BY_VALID_FAILURE"}


def attempts_for_target(doc, target):
    return [item for item in doc.get("attempts", []) if item.get("target") == target]


def _approval_errors(item):
    approval = item.get("approval_reference")
    if not isinstance(approval, dict):
        return [f"attempt {item.get('run_id')} lacks structured exact-candidate approval"]
    errors = []
    for field in ("target", "commit", "tree", "reference"):
        if not approval.get(field):
            errors.append(f"attempt {item.get('run_id')} approval lacks {field}")
    if approval.get("target") != item.get("target"):
        errors.append(f"attempt {item.get('run_id')} approval target mismatch")
    if approval.get("commit") != item.get("tested_commit"):
        errors.append(f"attempt {item.get('run_id')} approval commit mismatch")
    if approval.get("tree") != item.get("tested_tree"):
        errors.append(f"attempt {item.get('run_id')} approval tree mismatch")
    return errors


def validate_ledger(doc):
    errors = []
    policy = doc.get("policy", {})
    attempts = doc.get("attempts", [])
    valid_attempts = [item for item in attempts if item.get("classification") in ("VALID_PASS", "VALID_FAIL")]
    if policy.get("invalid_attempts_consume_budget") is not False:
        errors.append("INVALID attempts must not consume closure budget")
    if policy.get("automatic_reruns_after_invalid") != 1:
        errors.append("exactly one automatic rerun may follow a corrected INVALID attempt")
    if policy.get("second_run_after_valid_fail_requires_approval") is not True:
        errors.append("a second run after VALID_FAIL must require approval")

    histories = {}
    seen_run_ids = set()
    for item in attempts:
        run_id = item.get("run_id")
        target = item.get("target")
        classification = item.get("classification")
        if not run_id or run_id in seen_run_ids:
            errors.append(f"duplicate or missing run_id: {run_id}")
        seen_run_ids.add(run_id)
        if not target:
            errors.append(f"attempt {run_id} lacks target")
        if classification not in ATTEMPT_CLASSIFICATIONS:
            errors.append(f"attempt {run_id} has invalid classification")
        expected_budget = classification in ("VALID_PASS", "VALID_FAIL")
        if item.get("consumes_budget") is not expected_budget:
            errors.append(f"attempt {run_id} has wrong consumes_budget")
        if classification == "INVALID" and item.get("defect_class") not in INVALID_DEFECTS:
            errors.append(f"attempt {run_id} lacks a recognized invalid-run defect class")
        if classification != "INVALID" and item.get("automatic_rerun") == "AVAILABLE_AFTER_FIX":
            errors.append(f"attempt {run_id} exposes automatic rerun after a valid attempt")

        history = histories.setdefault(target, [])
        previous = history[-1] if history else None
        if previous and previous.get("classification") == "VALID_PASS":
            errors.append(f"attempt {run_id} follows terminal VALID_PASS for {target}")
        latest_valid = next((entry for entry in reversed(history)
                             if entry.get("classification") in ("VALID_PASS", "VALID_FAIL")), None)
        if latest_valid and latest_valid.get("classification") == "VALID_FAIL":
            errors.extend(_approval_errors(item))
        automatic_of = item.get("automatic_rerun_of")
        if automatic_of:
            if not previous or previous.get("classification") != "INVALID" or automatic_of != previous.get("run_id"):
                errors.append(f"attempt {run_id} is not the single immediate rerun of an INVALID attempt for {target}")
        history.append(item)

    for target, history in histories.items():
        for index, item in enumerate(history):
            if item.get("classification") != "INVALID":
                continue
            reruns = [entry for entry in history[index + 1:] if entry.get("automatic_rerun_of") == item.get("run_id")]
            if len(reruns) > 1:
                errors.append(f"INVALID attempt {item.get('run_id')} has more than one automatic rerun")
            state = item.get("automatic_rerun")
            if reruns:
                expected = f"USED_BY_{reruns[0].get('run_id').upper().replace(':', '_').replace('-', '_')}"
                if state != expected:
                    errors.append(f"INVALID attempt {item.get('run_id')} does not record its consumed automatic rerun")
            elif index == len(history) - 1 and state != "AVAILABLE_AFTER_FIX":
                errors.append(f"latest INVALID attempt for {target} must expose one corrected automatic rerun")

    budget = doc.get("budget", {})
    if budget.get("valid_attempts_used") != len(valid_attempts):
        errors.append("valid_attempts_used does not match attempt ledger")
    expected_remaining = max(0, policy.get("valid_attempt_budget", 0) - len(valid_attempts))
    if budget.get("valid_attempts_remaining") != expected_remaining:
        errors.append("valid_attempts_remaining does not match attempt ledger")
    return errors


def approval_required(doc, target):
    valid = [item for item in attempts_for_target(doc, target)
             if item.get("classification") in ("VALID_PASS", "VALID_FAIL")]
    if not valid:
        return False, None
    latest = valid[-1]
    if latest.get("classification") == "VALID_PASS":
        return False, "TARGET_ALREADY_CLOSED"
    return True, None


def validate_dispatch_approval(doc, target, commit, tree, supplied_target, supplied_commit, supplied_tree):
    required, terminal = approval_required(doc, target)
    if terminal:
        return [f"{target} already has a terminal VALID_PASS"]
    if not required:
        return []
    errors = []
    if supplied_target != target:
        errors.append("approval target does not match closure target")
    if supplied_commit != commit:
        errors.append("approval commit does not match candidate HEAD")
    if supplied_tree != tree:
        errors.append("approval tree does not match candidate tree")
    return errors


def classify_summary(summary):
    run = summary.get("run", {})
    attempt = run.get("closure_attempt", {})
    if run.get("kind") != "closure":
        return "NOT_APPLICABLE", []
    defects = attempt.get("infrastructure_defects", [])
    stages = attempt.get("required_stages", {})
    evidence = attempt.get("required_evidence", {})
    reasons = [f"infrastructure defect: {item}" for item in defects]
    if not stages:
        reasons.append("required closure stages were not recorded")
    if not evidence:
        reasons.append("required closure evidence was not recorded")
    reasons.extend(f"stage lacked configured completion opportunity: {name}"
                   for name, state in stages.items() if state not in TERMINAL_STAGES)
    reasons.extend(f"required evidence missing: {name}"
                   for name, present in evidence.items() if not present)
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
    parser.add_argument("--check-dispatch-approval", action="store_true")
    parser.add_argument("--target")
    parser.add_argument("--commit")
    parser.add_argument("--tree")
    parser.add_argument("--approval-target", default="")
    parser.add_argument("--approval-commit", default="")
    parser.add_argument("--approval-tree", default="")
    args = parser.parse_args()
    ledger = json.loads((ROOT / args.ledger).read_text(encoding="utf-8"))
    errors = validate_ledger(ledger)
    result = {"ledger_valid": not errors, "errors": errors}
    if args.check_dispatch_approval:
        approval_errors = validate_dispatch_approval(
            ledger, args.target, args.commit, args.tree,
            args.approval_target, args.approval_commit, args.approval_tree)
        errors.extend(approval_errors)
        result["approval_valid"] = not approval_errors
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
            attempt["failure_classification"] = (
                "EXTERNAL_SERVICE_FAILURE" if args.defect == "EXTERNAL_SERVICE_FAILURE" else
                "HARNESS_BUG" if args.defect == "HARNESS_DEFECT" else "WORKFLOW_DEFECT")
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
    result["errors"] = errors
    result["ledger_valid"] = not validate_ledger(ledger)
    print(json.dumps(result, separators=(",", ":")))
    return 0 if not errors else 1


if __name__ == "__main__":
    raise SystemExit(main())
