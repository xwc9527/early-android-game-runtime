#!/usr/bin/env python3
"""Reject closure evidence that does not cover the exact merged candidate."""

import argparse
import json
import pathlib
import subprocess

ROOT = pathlib.Path(__file__).resolve().parents[1]
GOVERNANCE_FOLLOWUP_FILES = {
    ".github/workflows/post-merge.yml",
    "ci/fetch-closure-evidence.py",
    "ci/verify-merge.py",
    "ci/build-post-merge-summary.py",
    "ci/test-post-merge-evidence.py",
    "ci/governance/post-merge-binding.json",
    "ci/governance/closure-attempts.json",
    "ci/governance/closure.json",
    "ci/governance/reopens.json",
    "ci/governance/state.json",
    "ci/test-closure-attempt-ledger.py",
    "docs/CURRENT_STATE.md",
    "docs/MODULE_STATUS.md",
}


def git(*args):
    return subprocess.check_output(["git", *args], cwd=ROOT, text=True).strip()


def load(path):
    return json.loads((ROOT / path).read_text(encoding="utf-8"))


def is_ancestor(older, newer):
    return subprocess.run(["git", "merge-base", "--is-ancestor", older, newer], cwd=ROOT).returncode == 0


def merged_identity_errors(summary, state, closure, ledger, binding, *, head,
                           head_tree, tested_commit_tree, merged_commit_tree,
                           tested_is_ancestor, merged_is_ancestor, followup_changes):
    """Check one exact closure/merge identity, with a scoped governance repair."""
    errors = []
    evidence = summary.get("closure", {})
    active = state.get("active", {}).get("target")
    target = binding.get("target")
    tested = binding.get("closure_tested_commit")
    tested_tree = binding.get("closure_tested_tree")
    merged = binding.get("merged_commit")
    merged_tree = binding.get("merged_tree")
    if not active or any(value != active for value in
                         (target, closure.get("target"), ledger.get("active_target"), evidence.get("target"))):
        errors.append("POST_MERGE_TARGET_MISMATCH")
    if (evidence.get("tested_commit") != tested or evidence.get("tested_tree") != tested_tree
            or str(summary.get("run", {}).get("workflow_id")) != str(binding.get("closure_run_id"))
            or closure.get("closure_tested_commit") != tested
            or closure.get("closure_tested_tree") != tested_tree
            or closure.get("merged_commit") != merged or closure.get("merged_tree") != merged_tree):
        errors.append("POST_MERGE_CLOSURE_IDENTITY_MISMATCH")
    if (not evidence.get("eligible_for_merge") or
            summary.get("run", {}).get("closure_attempt", {}).get("classification") != "VALID_PASS"):
        errors.append("POST_MERGE_CLOSURE_NOT_VALID_PASS")
    attempts = [item for item in ledger.get("attempts", [])
                if item.get("target") == target
                and str(item.get("run_id")) == str(binding.get("closure_run_id"))
                and item.get("tested_commit") == tested
                and item.get("tested_tree") == tested_tree
                and item.get("classification") == "VALID_PASS"]
    if (len(attempts) != 1 or closure.get("state") not in ("CLOSED", "MERGED")
            or state.get("active", {}).get("lifecycle") not in ("CLOSED", "MERGED")):
        errors.append("POST_MERGE_FORMAL_CLOSURE_MISSING")
    if tested_commit_tree != tested_tree or merged_commit_tree != tested_tree or merged_tree != tested_tree:
        errors.append("POST_MERGE_TREE_MISMATCH")
    if not tested_is_ancestor or not merged_is_ancestor:
        errors.append("POST_MERGE_ANCESTRY_MISMATCH")
    if head == merged:
        if head_tree != tested_tree:
            errors.append("POST_MERGE_HEAD_TREE_MISMATCH")
    else:
        unexpected = set(followup_changes) - GOVERNANCE_FOLLOWUP_FILES
        if unexpected:
            errors.append("POST_MERGE_UNVERIFIED_FOLLOWUP:" + ",".join(sorted(unexpected)))
    return errors


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("summary")
    parser.add_argument("--merged", action="store_true")
    args = parser.parse_args()
    summary = json.loads(pathlib.Path(args.summary).read_text(encoding="utf-8"))
    evidence = summary.get("closure", {})
    head, tree = git("rev-parse", "HEAD"), git("rev-parse", "HEAD^{tree}")
    errors = []
    if not args.merged:
        if not evidence.get("eligible_for_merge"):
            errors.append("closure evidence is not merge eligible")
        if head != evidence.get("tested_commit"):
            errors.append("MERGE_CANDIDATE_HEAD != CLOSURE_TESTED_COMMIT")
        if tree != evidence.get("tested_tree"):
            errors.append("current tree != closure tested tree")
    else:
        binding = load("ci/governance/post-merge-binding.json")
        tested, merged = binding["closure_tested_commit"], binding["merged_commit"]
        errors.extend(merged_identity_errors(
            summary, load("ci/governance/state.json"), load("ci/governance/closure.json"),
            load("ci/governance/closure-attempts.json"), binding, head=head, head_tree=tree,
            tested_commit_tree=git("rev-parse", f"{tested}^{{tree}}"),
            merged_commit_tree=git("rev-parse", f"{merged}^{{tree}}"),
            tested_is_ancestor=is_ancestor(tested, merged),
            merged_is_ancestor=is_ancestor(merged, head),
            followup_changes=git("diff", "--name-only", merged, head).splitlines() if head != merged else []))
    for error in errors:
        print(f"::error title=AGR merge gate::{error}")
    return 1 if errors else 0


if __name__ == "__main__":
    raise SystemExit(main())
