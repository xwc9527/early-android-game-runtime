#!/usr/bin/env python3
"""Exact-target post-merge identity contracts; no GitHub access required."""

import copy
import importlib.util
import json
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]


def module(name, path):
    spec = importlib.util.spec_from_file_location(name, ROOT / path)
    result = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(result)
    return result


verify = module("verify_merge", "ci/verify-merge.py")


def fixture():
    tested, tree, target = "a" * 40, "b" * 40, "Android Framework ViewRoot Attach Phase 1"
    run = "35595440089"
    summary = {"run": {"workflow_id": run, "closure_attempt": {"classification": "VALID_PASS"}},
               "closure": {"target": target, "tested_commit": tested,
                           "tested_tree": tree, "eligible_for_merge": True}}
    state = {"active": {"target": target, "lifecycle": "CLOSED"}}
    closure = {"target": target, "state": "CLOSED", "closure_tested_commit": tested,
               "closure_tested_tree": tree, "merged_commit": tested, "merged_tree": tree}
    ledger = {"active_target": target, "attempts": [{"target": target, "run_id": run,
              "tested_commit": tested, "tested_tree": tree, "classification": "VALID_PASS"}]}
    binding = {"target": target, "closure_run_id": run, "closure_tested_commit": tested,
               "closure_tested_tree": tree, "merged_commit": tested, "merged_tree": tree}
    kwargs = dict(head=tested, head_tree=tree, tested_commit_tree=tree,
                  merged_commit_tree=tree, tested_is_ancestor=True,
                  merged_is_ancestor=True, followup_changes=[])
    return summary, state, closure, ledger, binding, kwargs


def errors(parts):
    return verify.merged_identity_errors(*parts[:5], **parts[5])


def test_identity_cases():
    # A: exact closure and merged main tree.
    base = fixture()
    assert errors(base) == [], errors(base)
    # B: a successful historical closure reachable as an ancestor is not evidence.
    old = copy.deepcopy(base)
    old[0]["closure"].update(target="PVS1", tested_commit="c" * 40)
    assert "POST_MERGE_TARGET_MISMATCH" in errors(old)
    assert "POST_MERGE_CLOSURE_IDENTITY_MISMATCH" in errors(old)
    # C: even a matching commit cannot stand in for another active target.
    wrong_target = copy.deepcopy(base)
    wrong_target[0]["closure"]["target"] = "Framework / Activity Launch Compatibility Phase 1"
    assert "POST_MERGE_TARGET_MISMATCH" in errors(wrong_target)
    # D: the closure-tested tree must equal the actual merged tree.
    wrong_tree = copy.deepcopy(base)
    wrong_tree[5]["merged_commit_tree"] = "d" * 40
    assert "POST_MERGE_TREE_MISMATCH" in errors(wrong_tree)
    # E: conflict-free merge commit has a new SHA, but an identical tree.
    merged = copy.deepcopy(base)
    merged[4]["merged_commit"] = merged[2]["merged_commit"] = "e" * 40
    merged[5]["head"] = "e" * 40
    assert errors(merged) == [], errors(merged)
    merged[4]["merged_tree"] = merged[2]["merged_tree"] = "f" * 40
    assert "POST_MERGE_TREE_MISMATCH" in errors(merged)
    # A governance-only follow-up can move main HEAD; Runtime changes cannot.
    followup = copy.deepcopy(base)
    followup[5].update(head="f" * 40, head_tree="1" * 40,
                       followup_changes=["ci/verify-merge.py"])
    assert errors(followup) == [], errors(followup)
    followup[5]["followup_changes"] = ["Runtime/DexLoom/game_dex_runner.c"]
    assert any(e.startswith("POST_MERGE_UNVERIFIED_FOLLOWUP") for e in errors(followup))


def test_formal_binding():
    binding = json.loads((ROOT / "ci/governance/post-merge-binding.json").read_text(encoding="utf-8"))
    assert binding["target"] == "Android Framework ViewRoot Attach Phase 1"
    assert binding["closure_run_id"] == "35595440089"
    assert binding["closure_tested_commit"] == binding["merged_commit"]
    assert binding["closure_tested_tree"] == binding["merged_tree"]
    assert binding["invalid_post_merge_run"]["run_id"] == "35596315143"


if __name__ == "__main__":
    test_identity_cases()
    test_formal_binding()
    print("post-merge evidence binding: PASS")
