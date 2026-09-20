#!/usr/bin/env python3
"""Fast deterministic contracts for closure state, budget, and prerequisites."""

import importlib.util
import json
import pathlib

ROOT = pathlib.Path(__file__).resolve().parents[1]
SPEC = importlib.util.spec_from_file_location("closure_attempt", ROOT / "ci/closure-attempt.py")
TOOL = importlib.util.module_from_spec(SPEC)
SPEC.loader.exec_module(TOOL)
TARGET = "fixture-target"
COMMIT = "a" * 40
TREE = "b" * 40


def approval():
    return {"target": TARGET, "commit": COMMIT, "tree": TREE, "reference": "contract-fixture"}


def ledger(attempts, used):
    return {"schema_version": 1,
            "policy": {"valid_attempt_budget": 2,
                       "invalid_attempts_consume_budget": False,
                       "automatic_reruns_after_invalid": 1,
                       "second_run_after_valid_fail_requires_approval": True},
            "budget": {"valid_attempts_used": used, "valid_attempts_remaining": max(0, 2-used)},
            "attempts": attempts}


def attempt(run_id, classification, **extra):
    base = {"run_id": run_id, "target": TARGET, "tested_commit": COMMIT,
            "tested_tree": TREE, "classification": classification,
            "consumes_budget": classification != "INVALID"}
    base.update(extra)
    return base


def require(condition, message):
    if not condition:
        raise AssertionError(message)


def summary(stage="PASS", evidence=True, target="pass"):
    return {"run": {"kind": "closure", "closure_attempt": {
        "infrastructure_defects": [],
        "required_stages": {"source": stage},
        "required_evidence": {"fixture": evidence}}},
        "target": {"status": target}}


def main():
    invalid_a = attempt("invalid-a", "INVALID", defect_class="WORKFLOW_DEFECT",
                        consumes_budget=False, automatic_rerun="AVAILABLE_AFTER_FIX")
    errors = TOOL.validate_ledger(ledger([invalid_a], 0))
    require(not errors, "INVALID must permit one corrected automatic rerun")

    invalid_b = attempt("invalid-b", "INVALID", defect_class="WORKFLOW_DEFECT",
                        consumes_budget=False, automatic_rerun="USED_BY_INVALID_B2")
    invalid_b2 = attempt("invalid-b2", "INVALID", defect_class="HARNESS_DEFECT",
                         consumes_budget=False, automatic_rerun="USED_BY_FAILED",
                         automatic_rerun_of="invalid-b")
    failed = attempt("failed", "VALID_FAIL", approval_reference=approval(), automatic_rerun_of="invalid-b2")
    errors = TOOL.validate_ledger(ledger([invalid_b, invalid_b2, failed], 1))
    require(not errors, "VALID_FAIL must consume budget and require approval")
    require(TOOL.validate_dispatch_approval(ledger([invalid_b, invalid_b2, failed], 1),
                                            TARGET, COMMIT, TREE, TARGET, COMMIT, TREE) == [],
            "exact approval should authorize candidate")
    passed = attempt("passed", "VALID_PASS", approval_reference=approval())
    errors = TOOL.validate_ledger(ledger([invalid_b, invalid_b2, failed, passed], 2))
    require(not errors, "VALID_PASS should close the target")
    require(TOOL.validate_dispatch_approval(ledger([invalid_b, invalid_b2, failed, passed], 2),
                                            TARGET, COMMIT, TREE, TARGET, COMMIT, TREE),
            "terminal VALID_PASS must reject another dispatch")

    require(TOOL.classify_summary(summary(stage="PASS", evidence=False))[0] == "INVALID",
            "missing prerequisite/evidence must be INVALID")
    require(TOOL.classify_summary(summary(stage="FAIL", evidence=True, target="fail"))[0] == "VALID_FAIL",
            "executed target failure must be VALID_FAIL")
    require(TOOL.classify_summary(summary())[0] == "VALID_PASS",
            "complete candidate must be VALID_PASS")
    print("closure governance contracts passed: state machine, exact approval, prerequisites")


if __name__ == "__main__":
    main()
