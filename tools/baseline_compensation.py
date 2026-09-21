#!/usr/bin/env python3
"""Baseline compensation validation for the architecture falsification result.

The original dynamic Discovery and Holdout ran on formal main `5a6962d2`, before
First Traversal / Relayout / Surface Acquisition entered the baseline. This tool
re-evaluates H2 against a newer formal baseline using the same frozen sample
sets, frozen contract granularity and frozen thresholds, and reports the
per-game frontier difference between the two baselines.

It refuses to produce a verdict when its precondition is unmet. A missing newer
baseline, or a First Traversal phase that has not actually been merged with a
passing post-merge gate and a promoted baseline, yields
`BLOCKED_PRECONDITION` - never a provisional pass and never a reuse of the old
numbers dressed up as new evidence.
"""
from __future__ import annotations

import argparse
import json
import pathlib
import subprocess

ORIGINAL_BASELINE = "5a6962d2c84b06425e8c489e855d71529f50ba3b"
ORIGINAL_RUNS = {
    "discovery": "35654415068",
    "holdout": "35656209596",
    "falsification_branch_commit": "bae6d40a83bdf28e055dbfe4fdb9b6ed15ed08b4",
}
FIRST_TRAVERSAL_BRANCH = "phase/framework-first-traversal-surface-1"


def git(*args: str) -> str:
    return subprocess.run(["git", *args], capture_output=True, text=True).stdout.strip()


def load(path: pathlib.Path):
    return json.loads(path.read_text(encoding="utf-8")) if path.exists() else None


def check_precondition(root: pathlib.Path) -> dict:
    """Is a newer formal baseline containing First Traversal actually available?"""
    main = git("rev-parse", "origin/main")
    main_tree = git("rev-parse", "origin/main^{tree}")
    traversal = git("rev-parse", f"origin/{FIRST_TRAVERSAL_BRANCH}")
    merged = bool(traversal) and bool(main) and subprocess.run(
        ["git", "merge-base", "--is-ancestor", traversal, main]).returncode == 0

    state = json.loads(git("show", "origin/main:ci/governance/state.json") or "{}")
    baseline = (state.get("baseline") or {}).get("commit")
    promoted = merged and baseline == main

    try:
        closure = json.loads(git("show", f"origin/{FIRST_TRAVERSAL_BRANCH}:ci/governance/closure.json") or "{}")
    except json.JSONDecodeError:
        closure = {}

    reasons = []
    if not merged:
        reasons.append(
            f"First Traversal head {traversal[:8] or 'unknown'} is not an ancestor of formal "
            f"main {main[:8] or 'unknown'}; the phase is not MERGED.")
    if closure.get("state") and closure["state"] != "MERGED":
        reasons.append(
            f"First Traversal closure ledger state is {closure['state']!r} with "
            f"closure_tested_commit={closure.get('closure_tested_commit')!r} and "
            f"eligible_for_merge={closure.get('eligible_for_merge')!r}.")
    if not promoted:
        reasons.append(
            f"Governance baseline on formal main is {str(baseline)[:8]}, which is not the "
            "merged First Traversal commit; the baseline was not promoted.")
    if main == ORIGINAL_BASELINE:
        reasons.append(
            "Formal main is still the exact baseline the original dynamic runs used, so a "
            "compensation run would reproduce the original experiment rather than validate it "
            "against a deeper frontier.")

    return {
        "satisfied": bool(merged and promoted and main != ORIGINAL_BASELINE),
        "formal_main_commit": main,
        "formal_main_tree": main_tree,
        "governance_baseline_commit": baseline,
        "first_traversal_head": traversal,
        "first_traversal_merged_into_main": merged,
        "first_traversal_closure_state": closure.get("state"),
        "first_traversal_closure_tested_commit": closure.get("closure_tested_commit"),
        "first_traversal_eligible_for_merge": closure.get("eligible_for_merge"),
        "baseline_promoted": promoted,
        "blocking_reasons": reasons,
    }


def rows_by_id(classification: dict | None) -> dict[str, dict]:
    return {row["id"]: row for row in (classification or {}).get("rows", [])}


def compare(old: dict | None, new: dict | None) -> list[dict]:
    old_rows, new_rows = rows_by_id(old), rows_by_id(new)
    out = []
    for sample_id in [row["id"] for row in (old or {}).get("rows", [])]:
        before, after = old_rows.get(sample_id, {}), new_rows.get(sample_id)
        entry = {
            "id": sample_id,
            "cluster": before.get("cluster"),
            "old_last_stage": before.get("last_stage"),
            "old_classification": before.get("classification"),
            "old_blocking_family": before.get("blocking_family"),
            "old_blocking_method": before.get("blocking_method"),
            "old_executed_families": before.get("families", []),
        }
        if after is None:
            entry.update({"new_result": "MISSING", "frontier_change": "NOT_MEASURED"})
        else:
            gained = sorted(set(after.get("families", [])) - set(before.get("families", [])))
            lost = sorted(set(before.get("families", [])) - set(after.get("families", [])))
            if after.get("last_stage") == before.get("last_stage") and not gained:
                change = "UNCHANGED"
            elif gained:
                change = "DEEPER"
            else:
                change = "CHANGED"
            entry.update({
                "new_last_stage": after.get("last_stage"),
                "new_classification": after.get("classification"),
                "new_blocking_family": after.get("blocking_family"),
                "new_blocking_method": after.get("blocking_method"),
                "new_executed_families": after.get("families", []),
                "contract_families_gained": gained,
                "contract_families_no_longer_observed": lost,
                "frontier_change": change,
            })
        out.append(entry)
    return out


def h2(discovery: dict | None, holdout: dict | None, sensitivity: dict | None) -> dict:
    missing = [name for name, value in (("discovery", discovery), ("holdout", holdout))
               if value is None]
    if missing:
        return {"verdict": "NOT_ESTABLISHED", "missing_evidence": missing,
                "basis": "Both frozen sets must be measured on the new baseline before H2 can be "
                         "restated. Absent evidence is not a pass."}
    dm, hm = discovery["metrics"], holdout["metrics"]
    public_rows = [r for r in holdout["rows"]
                   if r["classification"] in {"KNOWN_PUBLIC_CONTRACT", "NEW_PUBLIC_CONTRACT"}]
    known = sum(1 for r in public_rows if r["classification"] == "KNOWN_PUBLIC_CONTRACT")
    conditions = {
        "no_new_per_game_production_branch": True,
        "marginal_threshold_met": bool(dm["threshold_marginal_pass"]),
        "holdout_reuse_threshold_met": bool(hm["holdout_reuse_ratio"] is not None
                                            and hm["holdout_reuse_ratio"] >= 0.70),
        "discovery_game_specific_zero": dm["classification_counts"].get("GAME_SPECIFIC", 0) == 0,
        "holdout_game_specific_zero": hm["classification_counts"].get("GAME_SPECIFIC", 0) == 0,
    }
    result = {
        "verdict": "PASS" if all(conditions.values()) else "FAIL",
        "conditions": conditions,
        "checks": {
            "C_first": dm["C_first"], "C_last": dm["C_last"],
            "c_last_over_c_first": dm["c_last_over_c_first"],
            "holdout_total_samples": len(holdout["rows"]),
            "holdout_public_contract_observable": len(public_rows),
            "holdout_reuse_numerator": known,
            "holdout_reuse_ratio": hm["holdout_reuse_ratio"],
            "discovery_classification_counts": dm["classification_counts"],
            "holdout_classification_counts": hm["classification_counts"],
        },
    }
    if result["verdict"] == "PASS" and sensitivity is not None:
        fraction = sensitivity["ratio_distribution"]["fraction_meeting_threshold"]
        result["order_sensitivity"] = {
            "registered_ratio": sensitivity["registered_ratio"],
            "reversed_ratio": sensitivity["reversed_ratio"],
            "fraction_of_permutations_meeting_threshold": fraction,
        }
        if not (sensitivity["reversed_ratio"] is not None
                and sensitivity["reversed_ratio"] <= 0.5 and fraction >= 0.5):
            result["verdict"] = "FAIL"
            result["basis"] = ("H2_NOT_CONVERGING: the threshold holds only under the registered "
                               "order, which indicates an ordering artifact.")
    result.setdefault("basis", "All frozen H2 conditions hold on the new baseline."
                      if result["verdict"] == "PASS"
                      else "H2_NOT_CONVERGING: at least one frozen condition failed.")
    return result


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("--artifacts", default="build/artifacts")
    parser.add_argument("--new-discovery", default=None)
    parser.add_argument("--new-holdout", default=None)
    parser.add_argument("--new-sensitivity", default=None)
    parser.add_argument("--compensation-run", default=None)
    parser.add_argument("--output", default="build/artifacts/architecture-falsification-compensation.json")
    args = parser.parse_args()
    root = pathlib.Path(__file__).resolve().parents[1]
    base = root / args.artifacts

    original = load(base / "architecture-falsification.json")
    if original is None:
        raise SystemExit("original falsification result is required as the comparison baseline")
    old_discovery = load(base / "frontier-classification-discovery.json")
    old_holdout = load(base / "frontier-classification-holdout.json")
    new_discovery = load(root / args.new_discovery) if args.new_discovery else None
    new_holdout = load(root / args.new_holdout) if args.new_holdout else None
    sensitivity = load(root / args.new_sensitivity) if args.new_sensitivity else None

    precondition = check_precondition(root)
    measured = new_discovery is not None and new_holdout is not None
    h2_result = h2(new_discovery, new_holdout, sensitivity)

    if not precondition["satisfied"]:
        status = "BLOCKED_PRECONDITION"
        h1 = {"verdict": "INHERITED_PASS_NOT_REVALIDATED",
              "basis": "No newer formal baseline exists to test, so the original H1 PASS stands "
                       "unchanged and unchallenged by this task."}
        project = {"verdict": "UNCHANGED_FROM_ORIGINAL",
                   "basis": "The compensation run was not executed, so the original CONTINUE "
                            "verdict is neither confirmed nor revised."}
    elif not measured:
        status = "PENDING_MEASUREMENT"
        h1 = {"verdict": "INHERITED_PASS_PENDING",
              "basis": "H1 is inherited unless the new run exposes a gameplay-critical "
                       "irreducible dependency."}
        project = {"verdict": "NOT_ESTABLISHED", "basis": "No new dynamic evidence yet."}
    else:
        status = "MEASURED"
        irreducible = [r for source in (new_discovery, new_holdout) for r in source["rows"]
                       if r["classification"] == "IRREDUCIBLE_SYSTEM_DEPENDENCY"]
        h1 = ({"verdict": "PASS",
               "basis": "The deeper frontier exposed no gameplay-critical irreducible system "
                        "dependency, so the original H1 PASS is inherited."}
              if not irreducible else
              {"verdict": "REOPEN_CANDIDATE",
               "basis": "New irreducible system dependencies appeared and must be evaluated "
                        "against the original 3 games / 2 clusters rule.",
               "observed": irreducible})
        if h1["verdict"] == "PASS" and h2_result["verdict"] == "PASS":
            project = {"verdict": "CONTINUE",
                       "basis": "The original falsification result survived a deeper Runtime "
                                "frontier."}
        elif h2_result["verdict"] == "FAIL" or h1["verdict"] != "PASS":
            project = {"verdict": "STOP_ARCHITECTURE",
                       "basis": "A frozen stop condition was met on the new baseline."}
        else:
            project = {"verdict": "NOT_ESTABLISHED", "basis": "Incomplete evidence."}

    payload = {
        "schema_version": 1,
        "experiment": "Baseline Compensation Validation - post First-Traversal formal main",
        "status": status,
        "original_experiment": {
            "name": "Architecture Falsification - baseline 5a6962d2",
            "runtime_baseline_commit": ORIGINAL_BASELINE,
            "run_ids": ORIGINAL_RUNS,
            "verdicts": {"H1": original["H1"]["verdict"], "H2": original["H2"]["verdict"],
                         "PROJECT": original["PROJECT"]["verdict"]},
            "preserved_unmodified": True,
        },
        "precondition": precondition,
        "frozen_inputs": {
            "granularity_fingerprint": original["granularity_fingerprint"],
            "discovery_order": original["preregistration"]["discovery_order"],
            "holdout": original["preregistration"]["holdout"],
            "thresholds": original["preregistration"]["thresholds"],
            "production_runtime_modified_by_this_task": False,
        },
        "compensation_run": {
            "run_id": args.compensation_run,
            "new_formal_main_commit": precondition["formal_main_commit"]
            if precondition["satisfied"] else None,
            "new_formal_main_tree": precondition["formal_main_tree"]
            if precondition["satisfied"] else None,
            "sample_profile": "falsification-compensation",
            "expensive_runs_added": 1 if measured else 0,
        },
        "discovery_metrics": {
            "old": (old_discovery or {}).get("metrics"),
            "new": (new_discovery or {}).get("metrics"),
        },
        "holdout_metrics": {
            "old": (old_holdout or {}).get("metrics"),
            "new": (new_holdout or {}).get("metrics"),
        },
        "per_game_frontier_comparison": {
            "discovery": compare(old_discovery, new_discovery),
            "holdout": compare(old_holdout, new_holdout),
        },
        "H1": h1,
        "H2": h2_result,
        "PROJECT": project,
        "limitations": [
            "First-blocker censoring still applies: each run shows only the frontmost blocker of "
            "each game on the baseline it ran against.",
            "The Holdout is a frozen non-adaptive holdout validation, not a blind holdout, "
            "because the same members were already observed on the previous baseline.",
        ],
    }
    base.mkdir(parents=True, exist_ok=True)
    output = root / args.output
    output.write_text(json.dumps(payload, indent=2) + "\n", encoding="utf-8")
    print(json.dumps({"status": status, "H1": h1["verdict"], "H2": h2_result["verdict"],
                      "PROJECT": project["verdict"]}, indent=2))
    for reason in precondition["blocking_reasons"]:
        print("BLOCKED:", reason)
    print("->", output)


if __name__ == "__main__":
    main()
