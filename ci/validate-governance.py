#!/usr/bin/env python3
"""Validate AGR state, stable-module protection, and closure/merge identity."""

import argparse, fnmatch, json, pathlib, subprocess, sys

ROOT = pathlib.Path(__file__).resolve().parents[1]


def git(*args: str) -> str:
    return subprocess.check_output(["git", *args], cwd=ROOT, text=True).strip()


def load(path: str):
    return json.loads((ROOT / path).read_text(encoding="utf-8"))


def changed_files(base: str) -> list[str]:
    try:
        return [p for p in git("diff", "--name-only", f"{base}...HEAD").splitlines() if p]
    except subprocess.CalledProcessError:
        return [p for p in git("diff", "--name-only", "HEAD~1", "HEAD").splitlines() if p]


def module_changes(files, modules):
    touched = []
    for module in modules:
        if any(any(path.startswith(prefix) or fnmatch.fnmatch(path, prefix) for prefix in module["paths"]) for path in files):
            touched.append(module)
    return touched


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--mode", choices=("working", "closure", "merge", "post-merge"), default="working")
    parser.add_argument("--summary")
    parser.add_argument("--output", default="build/artifacts/governance-report.json")
    args = parser.parse_args()
    required = ["AGENTS.md", "docs/ARCHITECTURE.md", "docs/CURRENT_STATE.md", "docs/DECISIONS.md",
                "docs/MODULE_STATUS.md", "docs/TESTING.md", "ci/governance/state.json",
                "ci/governance/modules.json", "ci/governance/reopens.json", "ci/governance/closure.json"]
    errors = [f"missing:{p}" for p in required if not (ROOT / p).is_file()]
    state, registry, closure = load("ci/governance/state.json"), load("ci/governance/modules.json"), load("ci/governance/closure.json")
    reopens = load("ci/governance/reopens.json").get("reopens", [])
    if state["baseline"]["last_known_good"] != state["baseline"]["commit"]:
        errors.append("last_known_good must be the formal main baseline commit")
    files = changed_files(state["baseline"]["commit"])
    touched = module_changes(files, registry["modules"])
    stable = [m for m in touched if m["status"] == "stable"]
    active_target=state["active"]["target"]
    explained={r["module"] for r in reopens if r.get("target")==active_target and r.get("reason") and r.get("evidence")}
    unexplained = [m["name"] for m in stable if m["name"] not in explained]
    warnings = [f"STABLE_MODULE_MODIFIED_WITHOUT_REOPEN_REASON:{name}" for name in unexplained]
    head, tree = git("rev-parse", "HEAD"), git("rev-parse", "HEAD^{tree}")
    dirty=bool(git("status","--porcelain"))
    summary = load(args.summary) if args.summary else None
    if args.mode in ("closure", "merge"):
        if dirty: errors.append("closure/merge candidate working tree is not clean")
        if not summary:
            errors.append("closure summary is required")
        else:
            c = summary.get("closure", {})
            if c.get("tested_commit") != head: errors.append("MERGE_CANDIDATE_HEAD != CLOSURE_TESTED_COMMIT")
            if c.get("tested_tree") != tree: errors.append("candidate tree != closure tested tree")
            if not c.get("eligible_for_merge"): errors.append("closure is not merge eligible")
            if not summary.get("run", {}).get("valid_run"): errors.append("closure run is infrastructure-invalid")
        if unexplained: errors.extend(warnings)
    if args.mode == "merge" and summary:
        base = summary.get("closure", {}).get("base_commit")
        if base:
            try: subprocess.check_call(["git","merge-base","--is-ancestor",base,"HEAD"],cwd=ROOT)
            except subprocess.CalledProcessError: errors.append("closure base is not an ancestor of merge candidate")
            try:
                current_main=git("rev-parse","origin/main")
                if current_main != base: errors.append("main changed after closure; integrate it and rerun affected closure gates")
            except subprocess.CalledProcessError:
                errors.append("origin/main is unavailable for merge-base verification")
    if args.mode == "post-merge":
        tested_tree = closure.get("closure_tested_tree")
        if tested_tree and tested_tree != tree:
            errors.append("merged tree differs from closure-tested tree")
    report = {"schema_version":1,"mode":args.mode,"head":head,"tree":tree,"dirty":dirty,"baseline":state["baseline"]["commit"],
              "changed_files":files,"modules_touched":[m["name"] for m in touched],
              "stable_modules_touched":[m["name"] for m in stable],"warnings":warnings,"errors":errors,
              "passed":not errors}
    output = ROOT / args.output
    output.parent.mkdir(parents=True, exist_ok=True)
    output.write_text(json.dumps(report, indent=2) + "\n", encoding="utf-8")
    for warning in warnings: print(f"::warning title=AGR governance::{warning}")
    for error in errors: print(f"::error title=AGR governance::{error}")
    print(json.dumps(report, separators=(",", ":")))
    return 0 if not errors else 1


if __name__ == "__main__":
    raise SystemExit(main())
