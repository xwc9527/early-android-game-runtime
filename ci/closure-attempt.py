#!/usr/bin/env python3
"""Validate closure-attempt accounting and classify a run summary."""

import argparse
import json
import pathlib
import re

ROOT = pathlib.Path(__file__).resolve().parents[1]
INVALID_DEFECTS = {
    "HARNESS_DEFECT", "RUNNER_DEFECT", "COLLECTOR_DEFECT", "ARTIFACT_DEFECT",
    "TIMEOUT_HIERARCHY_DEFECT", "WORKFLOW_DEFECT",
}
TERMINAL_STAGES = {"PASS", "FAIL", "BLOCKED_BY_VALID_FAILURE"}


def validate_ledger(doc):
    errors = []
    if doc.get("schema_version") != 2:
        errors.append("closure attempt ledger must use schema_version 2")
    policy = doc.get("policy", {})
    attempts = doc.get("attempts", [])
    active_target = doc.get("active_target")
    if not isinstance(active_target, str) or not active_target:
        errors.append("active_target must identify the target whose budget is recorded")
    active_attempts = [item for item in attempts if item.get("target") == active_target]
    valid_attempts = [item for item in active_attempts if item.get("classification") in ("VALID_PASS", "VALID_FAIL")]
    if policy.get("invalid_attempts_consume_budget") is not False:
        errors.append("INVALID attempts must not consume closure budget")
    if policy.get("automatic_reruns_after_invalid") != 1:
        errors.append("exactly one automatic rerun must follow a corrected INVALID attempt")
    if policy.get("second_run_after_valid_fail_requires_approval") is not True:
        errors.append("a second run after VALID_FAIL must require approval")
    run_ids = set()
    by_target = {}
    for item in attempts:
        target = item.get("target")
        if not isinstance(target, str) or not target:
            errors.append(f"attempt {item.get('run_id')} lacks target identity")
            continue
        if not item.get("target_evidence"):
            errors.append(f"attempt {item.get('run_id')} lacks target attribution evidence")
        by_target.setdefault(target, []).append(item)

    for item in attempts:
        classification = item.get("classification")
        run_id = item.get("run_id")
        target = item.get("target")
        if not isinstance(run_id, str) or not run_id:
            errors.append("attempt lacks run_id")
        elif run_id in run_ids:
            errors.append(f"duplicate closure attempt run_id {run_id}")
        else:
            run_ids.add(run_id)
        for field in ("tested_commit", "tested_tree"):
            if not isinstance(item.get(field), str) or not re.fullmatch(r"[0-9a-f]{40}", item[field]):
                errors.append(f"attempt {run_id} has invalid {field}")
        if classification not in ("VALID_PASS", "VALID_FAIL", "INVALID"):
            errors.append(f"attempt {run_id} has invalid classification")
        expected = classification in ("VALID_PASS", "VALID_FAIL")
        if item.get("consumes_budget") is not expected:
            errors.append(f"attempt {run_id} has wrong consumes_budget")
        if classification == "INVALID" and item.get("defect_class") not in INVALID_DEFECTS:
            errors.append(f"attempt {run_id} lacks an infrastructure defect class")
        if classification == "INVALID" and not item.get("reason"):
            errors.append(f"INVALID attempt {run_id} lacks a reason")

    for target, chain in by_target.items():
        previous = None
        approval_required = False
        for item in chain:
            run_id = item.get("run_id")
            if approval_required and not item.get("approval_reference"):
                errors.append(f"attempt {run_id} for {target} follows VALID_FAIL without explicit approval")
            approval_required = False
            rerun_of = item.get("automatic_rerun_of")
            if rerun_of:
                if not previous or previous.get("classification") != "INVALID" or rerun_of != previous.get("run_id"):
                    errors.append(f"attempt {run_id} is not the immediate same-target rerun of an INVALID attempt")
                elif previous.get("automatic_rerun") not in (
                    f"USED_BY_{run_id.replace(':', '_').replace('-', '_').upper()}", "AVAILABLE_AFTER_FIX"
                ):
                    errors.append(f"INVALID attempt {rerun_of} does not authorize the recorded same-target rerun")
            if item.get("classification") == "VALID_FAIL":
                approval_required = True
            previous = item
    if doc.get("budget", {}).get("valid_attempts_used") != len(valid_attempts):
        errors.append("valid_attempts_used does not match active-target attempts")
    expected_remaining = max(0, policy.get("valid_attempt_budget", 0) - len(valid_attempts))
    if doc.get("budget", {}).get("valid_attempts_remaining") != expected_remaining:
        errors.append("valid_attempts_remaining does not match active-target attempts")
    return errors


def validate_governance_records(state, closure, ledger):
    """Check that the active state, formal closure, and attempt ledger tell one story."""
    errors = []
    active = state.get("active", {})
    target = active.get("target")
    if target != closure.get("target"):
        errors.append("state.active.target != closure.target")
    if ledger.get("active_target") != target:
        errors.append("ledger.active_target != state.active.target")

    attempts = ledger.get("attempts", [])
    last = state.get("ci_budget", {}).get("last_closure_attempt")
    state_last_entry = None
    if active.get("lifecycle") in ("CLOSED", "MERGED"):
        if not last:
            errors.append("CLOSED/MERGED state lacks ci_budget.last_closure_attempt")
        else:
            try:
                run_id, classification = last.rsplit(" ", 1)
            except ValueError:
                errors.append("state last_closure_attempt must contain run_id and classification")
            else:
                matching_last = [item for item in attempts if item.get("target") == target
                                 and item.get("run_id") == run_id and item.get("classification") == classification]
                if not matching_last:
                    errors.append("state last_closure_attempt has no matching target-scoped ledger entry")
                else:
                    state_last_entry = matching_last[0]

    formal_closure_entries = []
    if closure.get("state") in ("CLOSED", "MERGE-ELIGIBLE", "MERGED"):
        formal_closure_entries = [item for item in attempts if item.get("target") == closure.get("target")
                                  and item.get("classification") == "VALID_PASS"
                                  and item.get("tested_commit") == closure.get("closure_tested_commit")
                                  and item.get("tested_tree") == closure.get("closure_tested_tree")]
        if not formal_closure_entries:
            errors.append("formal closure has no matching target-scoped VALID_PASS ledger entry")

    if closure.get("state") == "MERGED":
        merged_commit = closure.get("merged_commit")
        if not merged_commit or state.get("baseline", {}).get("commit") != merged_commit:
            errors.append("MERGED closure identity does not match state.baseline.commit")
        if merged_commit != closure.get("closure_tested_commit"):
            errors.append("MERGED commit differs from closure-tested commit")
        if closure.get("merged_tree") != closure.get("closure_tested_tree"):
            errors.append("MERGED closure tree differs from closure-tested tree")
        if state_last_entry and formal_closure_entries and state_last_entry not in formal_closure_entries:
            errors.append("state last closure attempt does not identify the merged closure VALID_PASS")

    active_target = ledger.get("active_target")
    active_valid_count = sum(1 for item in attempts if item.get("target") == active_target
                             and item.get("classification") in ("VALID_PASS", "VALID_FAIL"))
    state_budget = state.get("ci_budget", {}).get("closure_runs_used")
    if state_budget is not None and active_target == target and state_budget != active_valid_count:
        errors.append("state closure_runs_used does not match active-target ledger budget")
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
