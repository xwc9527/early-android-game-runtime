#!/usr/bin/env python3
"""Target-scoped closure-attempt ledger and cross-file governance contracts."""

import importlib.util
import json
import pathlib

ROOT = pathlib.Path(__file__).resolve().parents[1]
spec = importlib.util.spec_from_file_location("closure_attempt", ROOT / "ci/closure-attempt.py")
closure_attempt = importlib.util.module_from_spec(spec)
spec.loader.exec_module(closure_attempt)
gov_spec = importlib.util.spec_from_file_location("validate_governance", ROOT / "ci/validate-governance.py")
validate_governance = importlib.util.module_from_spec(gov_spec)
gov_spec.loader.exec_module(validate_governance)


def require(condition, message):
    if not condition:
        raise AssertionError(message)


def attempt(target, run_id, classification, *, commit=None, tree=None, **extra):
    result = {
        "target": target,
        "target_evidence": "test fixture target identity",
        "run_id": run_id,
        "tested_commit": commit or "a" * 40,
        "tested_tree": tree or "b" * 40,
        "classification": classification,
        "consumes_budget": classification != "INVALID",
        "reason": "fixture evidence",
    }
    if classification == "INVALID":
        result.update(defect_class="HARNESS_DEFECT", automatic_rerun="AVAILABLE_AFTER_FIX")
    result.update(extra)
    return result


def ledger(target, attempts, used):
    return {
        "schema_version": 2,
        "active_target": target,
        "policy": {
            "valid_attempt_budget": 1,
            "invalid_attempts_consume_budget": False,
            "automatic_reruns_after_invalid": 1,
            "second_run_after_valid_fail_requires_approval": True,
        },
        "budget": {"valid_attempts_used": used, "valid_attempts_remaining": max(0, 1 - used)},
        "attempts": attempts,
    }


def test_a_invalid_then_auto_rerun_pass():
    first = attempt("T", "1", "INVALID", automatic_rerun="USED_BY_2")
    second = attempt("T", "2", "VALID_PASS", automatic_rerun_of="1")
    require(not closure_attempt.validate_ledger(ledger("T", [first, second], 1)), "A: corrected INVALID rerun should pass")


def test_b_valid_fail_requires_approval():
    items = [attempt("T", "1", "VALID_FAIL"), attempt("T", "2", "VALID_PASS")]
    errors = closure_attempt.validate_ledger(ledger("T", items, 2))
    require(any("explicit approval" in error for error in errors), "B: same-target VALID_FAIL must require approval")


def test_c_approval_is_target_scoped():
    items = [attempt("A", "1", "VALID_FAIL"), attempt("B", "2", "VALID_PASS")]
    require(not closure_attempt.validate_ledger(ledger("B", items, 1)), "C: target A approval must not block target B")


def test_d_budget_is_active_target_only():
    items = [attempt("A", "1", "VALID_PASS")]
    require(not closure_attempt.validate_ledger(ledger("B", items, 0)), "D: prior target must not consume active target budget")


def test_e_state_requires_ledger_attempt():
    state = {"active": {"target": "T", "lifecycle": "MERGED"},
             "ci_budget": {"last_closure_attempt": "2 VALID_PASS", "closure_runs_used": 1},
             "baseline": {"commit": "a" * 40}}
    closure = {"target": "T", "state": "MERGED", "closure_tested_commit": "a" * 40,
               "closure_tested_tree": "b" * 40, "merged_commit": "a" * 40, "merged_tree": "b" * 40}
    items = [attempt("T", "1", "VALID_PASS")]
    errors = closure_attempt.validate_governance_records(state, closure, ledger("T", items, 1))
    require(any("last_closure_attempt" in error for error in errors), "E: missing state-referenced attempt must fail")


def test_f_closure_commit_tree_must_match_ledger():
    state = {"active": {"target": "T", "lifecycle": "IMPLEMENTED"},
             "ci_budget": {}, "baseline": {"commit": "c" * 40}}
    closure = {"target": "T", "state": "MERGED", "closure_tested_commit": "a" * 40,
               "closure_tested_tree": "b" * 40, "merged_commit": "c" * 40, "merged_tree": "b" * 40}
    items = [attempt("T", "1", "VALID_PASS", commit="c" * 40, tree="b" * 40)]
    errors = closure_attempt.validate_governance_records(state, closure, ledger("T", items, 1))
    require(any("formal closure" in error for error in errors), "F: mismatched closure identity must fail")


def test_g_current_repository_records_match():
    state = json.loads((ROOT / "ci/governance/state.json").read_text(encoding="utf-8"))
    closure = json.loads((ROOT / "ci/governance/closure.json").read_text(encoding="utf-8"))
    attempts = json.loads((ROOT / "ci/governance/closure-attempts.json").read_text(encoding="utf-8"))
    require(not closure_attempt.validate_ledger(attempts), "G: actual attempt ledger invalid")
    require(not closure_attempt.validate_governance_records(state, closure, attempts), "G: actual state/closure/ledger diverge")
    current = [item for item in attempts["attempts"] if item["run_id"] == "35530434859"]
    require(len(current) == 1, "G: current formal closure must appear exactly once")
    item = current[0]
    require(item["target"] == "Android Framework Continuation Phase 1", "G: wrong current closure target")
    require(item["classification"] == "VALID_PASS" and item["consumes_budget"], "G: current closure classification mismatch")
    # The historical Activity/Window closure stays in the ledger when the
    # active target changes.  Only compare it with closure.json while that
    # target is still the current formal closure.
    require(item["tested_commit"] == "a5c5958af1a65763808fc2a4de669c4e76694876" and
            item["tested_tree"] == "ee8c0889437e79dacf9e8ed068a7d569100189de",
            "G: historical Activity/Window closure identity changed")
    if closure["target"] == item["target"]:
        require(item["tested_commit"] == closure["closure_tested_commit"] and
                item["tested_tree"] == closure["closure_tested_tree"],
                "G: current closure commit/tree mismatch")
    schema = json.loads((ROOT / "artifacts/schema/closure-attempts.schema.json").read_text(encoding="utf-8"))
    require(schema["properties"]["schema_version"]["const"] == 2, "G: schema version is not v2")
    require("active_target" in schema["required"], "G: schema does not require active_target")
    attempt_required = schema["properties"]["attempts"]["items"]["required"]
    require("target" in attempt_required and "target_evidence" in attempt_required,
            "G: schema does not require attempt target attribution")


def _current_governance_fixture():
    state = json.loads((ROOT / "ci/governance/state.json").read_text(encoding="utf-8"))
    closure = json.loads((ROOT / "ci/governance/closure.json").read_text(encoding="utf-8"))
    ledger_doc = json.loads((ROOT / "ci/governance/closure-attempts.json").read_text(encoding="utf-8"))
    reopens = json.loads((ROOT / "ci/governance/reopens.json").read_text(encoding="utf-8"))["reopens"]
    active = state["active"]["target"]
    stable = [{"name": "DEXRuntimeLifecycle"}, {"name": "NativeActivityInput"}]
    summary = {
        "target": {"name": active},
        "closure": {"target": active},
        "changes": {"stable_module_reopens": [r for r in reopens if r.get("target") == active]},
    }
    return state, closure, ledger_doc, reopens, stable, summary


def test_h_target_binding_contracts():
    state, closure, ledger_doc, reopens, stable, summary = _current_governance_fixture()
    require(not validate_governance.target_identity_errors(summary, state, closure, ledger_doc),
            "H-A: matching target identities should pass")
    old = "Android Framework Continuation Phase 1"
    summary["target"]["name"] = old
    errors = validate_governance.target_identity_errors(summary, state, closure, ledger_doc)
    require("CLOSURE_TARGET_MISMATCH" in errors, "H-B: stale summary target must fail")
    summary["target"]["name"] = state["active"]["target"]
    closure["target"] = old
    require("CLOSURE_TARGET_MISMATCH" in validate_governance.target_identity_errors(summary, state, closure, ledger_doc),
            "H-C: closure target mismatch must fail")
    closure["target"] = state["active"]["target"]
    ledger_doc["active_target"] = old
    require("CLOSURE_TARGET_MISMATCH" in validate_governance.target_identity_errors(summary, state, closure, ledger_doc),
            "H-D: ledger active target mismatch must fail")
    ledger_doc["active_target"] = state["active"]["target"]
    stale_reopens = [dict(record) for record in reopens]
    for record in stale_reopens:
        if record.get("target") == state["active"]["target"] and record.get("module") == "DEXRuntimeLifecycle":
            record["target"] = old
    errors = validate_governance.stable_reopen_errors(summary, stable, stale_reopens, state["active"]["target"])
    require("STABLE_REOPEN_MISSING:DEXRuntimeLifecycle" in errors, "H-E: stale-target reopen must fail")
    summary["changes"]["stable_module_reopens"] = []
    errors = validate_governance.stable_reopen_errors(summary, stable, reopens, state["active"]["target"])
    require("STABLE_REOPENS_SUMMARY_MISMATCH" in errors, "H-F: missing current-target reopen projection must fail")


def main():
    tests = [test_a_invalid_then_auto_rerun_pass, test_b_valid_fail_requires_approval,
             test_c_approval_is_target_scoped, test_d_budget_is_active_target_only,
             test_e_state_requires_ledger_attempt, test_f_closure_commit_tree_must_match_ledger,
             test_g_current_repository_records_match, test_h_target_binding_contracts]
    for test in tests:
        test()
        print(f"PASS {test.__name__}")
    print(f"closure-attempt ledger contracts passed: {len(tests)}")


if __name__ == "__main__":
    main()
