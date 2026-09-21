#!/usr/bin/env python3
"""Summarize the exact closure target actually exercised after a main merge."""

import argparse
import json
import os
import pathlib
import subprocess

ROOT = pathlib.Path(__file__).resolve().parents[1]


def git(*args):
    return subprocess.check_output(["git", *args], cwd=ROOT, text=True).strip()


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--closure", default="build/artifacts/closure-run-summary.json")
    parser.add_argument("--identity-status", required=True)
    parser.add_argument("--governance-status", required=True)
    parser.add_argument("--contracts-status", required=True)
    parser.add_argument("--smoke-status", required=True)
    parser.add_argument("--output", default="build/artifacts/post-merge-summary.json")
    args = parser.parse_args()
    closure_path = ROOT / args.closure
    closure = json.loads(closure_path.read_text(encoding="utf-8")) if closure_path.is_file() else {}
    identity = closure.get("closure", {})
    attempt = closure.get("run", {}).get("closure_attempt", {})
    binding = json.loads((ROOT / "ci/governance/post-merge-binding.json").read_text(encoding="utf-8"))
    tested = identity.get("tested_commit")
    tree = identity.get("tested_tree")
    main_head, main_tree = git("rev-parse", "HEAD"), git("rev-parse", "HEAD^{tree}")
    workflow_commit = os.getenv("GITHUB_SHA", main_head)
    passed = (identity.get("eligible_for_merge") is True
              and attempt.get("classification") == "VALID_PASS"
              and identity.get("target") == binding["target"]
              and tested == binding["closure_tested_commit"]
              and tree == binding["closure_tested_tree"]
              and str(closure.get("run", {}).get("workflow_id")) == binding["closure_run_id"]
              and main_head == workflow_commit
              and args.identity_status == "success"
              and args.governance_status == "success"
              and args.contracts_status == "success"
              and args.smoke_status == "success")
    summary = {
        "schema_version": 1,
        "run_id": os.getenv("GITHUB_RUN_ID", "local"),
        "main_head": main_head,
        "main_tree": main_tree,
        "workflow_commit": workflow_commit,
        "target": identity.get("target"),
        "closure_run_id": closure.get("run", {}).get("workflow_id"),
        "closure_tested_commit": tested,
        "closure_tested_tree": tree,
        "merged_commit": binding["merged_commit"],
        "merged_tree": binding["merged_tree"],
        "governance_only_followup": main_head != binding["merged_commit"],
        "identity": args.identity_status,
        "governance": args.governance_status,
        "contracts": args.contracts_status,
        "smoke": args.smoke_status,
        "passed": passed,
    }
    out = ROOT / args.output
    out.parent.mkdir(parents=True, exist_ok=True)
    out.write_text(json.dumps(summary, indent=2) + "\n", encoding="utf-8")
    print(json.dumps(summary, separators=(",", ":")))
    return 0 if passed else 1


if __name__ == "__main__":
    raise SystemExit(main())
