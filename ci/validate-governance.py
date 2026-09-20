#!/usr/bin/env python3
"""Validate AGR state, stable-module protection, and closure/merge identity."""

import argparse, fnmatch, json, pathlib, subprocess, sys

from importlib.util import module_from_spec, spec_from_file_location

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
    parser.add_argument("--mode", choices=("working", "discovery", "closure", "merge", "post-merge"), default="working")
    parser.add_argument("--summary")
    parser.add_argument("--output", default="build/artifacts/governance-report.json")
    args = parser.parse_args()
    required = ["AGENTS.md", "docs/ARCHITECTURE.md", "docs/CURRENT_STATE.md", "docs/DECISIONS.md", "docs/UPSTREAM_MAP.md",
                "docs/MODULE_STATUS.md", "docs/TESTING.md", "ci/governance/state.json",
                "ci/governance/modules.json", "ci/governance/reopens.json", "ci/governance/closure.json",
                "ci/governance/upstream-map.json", "ci/governance/diagnostic-cutpoints.json",
                "ci/governance/expensive-run-plan.json", "ci/governance/closure-attempts.json", "ci/experiments.json",
                "artifacts/schema/semantic-diff.schema.json", "artifacts/schema/upstream-map.schema.json",
                "artifacts/schema/experiments.schema.json", "artifacts/schema/closure-attempts.schema.json"]
    errors = [f"missing:{p}" for p in required if not (ROOT / p).is_file()]
    state, registry, closure = load("ci/governance/state.json"), load("ci/governance/modules.json"), load("ci/governance/closure.json")
    upstream_map = load("ci/governance/upstream-map.json")
    experiments = load("ci/experiments.json")
    reopens = load("ci/governance/reopens.json").get("reopens", [])
    attempt_spec = spec_from_file_location("closure_attempt_tool", ROOT / "ci/closure-attempt.py")
    attempt_tool = module_from_spec(attempt_spec); attempt_spec.loader.exec_module(attempt_tool)
    errors.extend(attempt_tool.validate_ledger(load("ci/governance/closure-attempts.json")))
    if state["baseline"]["last_known_good"] != state["baseline"]["commit"]:
        errors.append("last_known_good must be the formal main baseline commit")
    if upstream_map.get("android_baseline") != "Android 4.4.4_r2":
        errors.append("upstream map must use Android 4.4.4_r2")
    experiment_ids = set()
    for index, experiment in enumerate(experiments.get("experiments", [])):
        required_experiment = {"id","purpose","explanations","outcome_a","outcome_b","files","enabled","status"}
        missing = sorted(required_experiment - set(experiment))
        if missing: errors.append(f"experiment {index} missing: {','.join(missing)}")
        if experiment.get("id") in experiment_ids: errors.append(f"duplicate experiment id: {experiment.get('id')}")
        experiment_ids.add(experiment.get("id"))
        if len(experiment.get("explanations", [])) < 2: errors.append(f"experiment {experiment.get('id')} does not distinguish two explanations")
        if experiment.get("status") not in ("ACTIVE", "RESOLVED"): errors.append(f"experiment {experiment.get('id')} has invalid status")
    map_spec = spec_from_file_location("upstream_map_tool", ROOT / "ci/upstream-map.py")
    map_tool = module_from_spec(map_spec); map_spec.loader.exec_module(map_tool)
    map_errors, map_entries = map_tool.evaluate(upstream_map)
    errors.extend(map_errors)
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
            classification, classification_reasons = attempt_tool.classify_summary(summary)
            declared = summary.get("run", {}).get("closure_attempt", {}).get("classification")
            if declared != classification: errors.append(f"closure attempt classification mismatch: {declared} != {classification}")
            if classification != "VALID_PASS": errors.append("closure attempt is not VALID_PASS: " + "; ".join(classification_reasons))
            diagnosis = summary.get("diagnosis", {})
            upstream = diagnosis.get("upstream", {})
            map_entry = upstream.get("map_entry")
            if upstream.get("map_status") != "NOT_APPLICABLE":
                if not map_entry: errors.append("closure diagnosis has no upstream map entry")
                elif map_entries.get(map_entry, {}).get("effective_status") != "VALID": errors.append("closure upstream map entry is not effectively VALID")
                if not upstream.get("source_verified"): errors.append("closure upstream source is not verified")
            divergence = diagnosis.get("earliest_evidenced_divergence", {})
            if not divergence.get("description"): errors.append("closure diagnosis has no earliest evidenced divergence")
            if summary.get("diagnostics", {}).get("experimental"): errors.append("closure retains experimental diagnostics")
            unresolved = [item.get("id", "") for item in experiments.get("experiments", [])
                          if item.get("enabled") or item.get("status") != "RESOLVED"]
            if unresolved: errors.append("closure has enabled or unresolved experiments: " + ",".join(unresolved))
            runtime_hits = []
            for base in (ROOT / "Runtime", ROOT / "App"):
                if not base.exists(): continue
                for path in base.rglob("*"):
                    if path.is_file():
                        try:
                            if "AGR_EXPERIMENTAL_" in path.read_text(encoding="utf-8", errors="ignore"): runtime_hits.append(str(path.relative_to(ROOT)))
                        except OSError: pass
            if runtime_hits: errors.append("closure production tree contains AGR_EXPERIMENTAL_*: " + ",".join(runtime_hits))
            semantic_path = diagnosis.get("semantic_diff_artifact")
            if semantic_path:
                semantic = load(semantic_path)
                semantic_spec = spec_from_file_location("semantic_diff_tool", ROOT / "ci/semantic-diff.py")
                semantic_tool = module_from_spec(semantic_spec); semantic_spec.loader.exec_module(semantic_tool)
                experiment_ids = {item.get("id") for item in experiments.get("experiments", [])}
                errors.extend("semantic-diff: " + error for error in semantic_tool.validate(semantic, experiment_ids))
                if semantic.get("experimental") or semantic.get("needs_experiment"):
                    errors.append("closure semantic differential still contains an active experiment")
                semantic_entry = semantic.get("upstream", {}).get("map_entry")
                if semantic_entry and map_entries.get(semantic_entry, {}).get("effective_status") != semantic.get("upstream", {}).get("map_status"):
                    errors.append("semantic differential map_status differs from computed upstream map status")
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
