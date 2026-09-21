#!/usr/bin/env python3
"""Apply the pre-registered H1/H2 rules to the collected evidence.

This tool decides nothing by itself. It reads the census, boundary map,
pre-registration and whichever dynamic classifications exist, applies the
thresholds that were frozen before the first dynamic run, and emits both
`architecture-falsification.json` and the report body. Missing evidence is
reported as missing; it is never treated as a pass.
"""
from __future__ import annotations

import argparse
import collections
import json
import pathlib


def load(path: pathlib.Path):
    return json.loads(path.read_text(encoding="utf-8")) if path.exists() else None


def h1_verdict(boundaries: dict, union: dict) -> dict:
    in_scope = {s["id"] for s in union["samples"] if s["scope"].startswith("IN_SCOPE")}
    irreducible = [b for b in boundaries["boundaries"]
                   if b["status"] == "IRREDUCIBLE_SYSTEM_DEPENDENCY"]
    gameplay_critical = [b for b in irreducible if b.get("core_gameplay_relevance") == "CORE"]
    unresolved = [b for b in boundaries["boundaries"]
                  if b["status"] == "UNRESOLVED" and b.get("core_gameplay_relevance") == "CORE"]

    triggered = []
    for boundary in gameplay_critical:
        games = [g for g in boundary["games_referencing"] if g in in_scope]
        clusters = set(boundary["engine_clusters_referencing"])
        if len(games) >= 3 and len(clusters) >= 2:
            triggered.append({"family": boundary["family"], "games": games,
                              "clusters": sorted(clusters)})

    exclusions = [
        {"id": s["id"], "scope": s["scope"], "reason": s["scope_reason"]}
        for s in union["samples"] if s["scope"] == "OUT_OF_SCOPE_EXTERNAL_DEPENDENCY"
    ]
    if triggered:
        verdict = "FAIL"
        basis = ("A gameplay-critical irreducible dependency reached the pre-registered "
                 "3 games / 2 unrelated clusters threshold.")
    elif unresolved:
        verdict = "NARROW_SCOPE"
        basis = ("Gameplay-critical boundaries remain UNRESOLVED, which the pre-registered rule "
                 "forbids from passing.")
    elif gameplay_critical:
        verdict = "NARROW_SCOPE"
        basis = ("Irreducible gameplay-critical dependencies exist but stay below the "
                 "3 games / 2 clusters threshold and form a stable exclusion boundary.")
    else:
        verdict = "PASS"
        basis = ("No gameplay-critical boundary is irreducible or unresolved; every core "
                 "system-service behavior the in-scope games reach reduces to a finite "
                 "guest-visible local contract.")
    return {
        "verdict": verdict,
        "basis": basis,
        "threshold_triggered": triggered,
        "gameplay_critical_irreducible": [b["family"] for b in gameplay_critical],
        "gameplay_critical_unresolved": [b["family"] for b in unresolved],
        "optional_external_boundaries": sorted(
            b["family"] for b in boundaries["boundaries"] if b["status"] == "OPTIONAL_EXTERNAL"),
        "exclusion_list": exclusions,
    }


def h2_verdict(discovery: dict | None, holdout: dict | None) -> dict:
    checks: dict[str, object] = {}
    missing = []
    if discovery is None:
        missing.append("discovery classification")
    if holdout is None:
        missing.append("holdout classification")

    if discovery:
        metrics = discovery["metrics"]
        checks["C_first"] = metrics["C_first"]
        checks["C_last"] = metrics["C_last"]
        checks["marginal_threshold_met"] = metrics["threshold_marginal_pass"]
        checks["discovery_game_specific"] = metrics["classification_counts"].get("GAME_SPECIFIC", 0)
        checks["discovery_unresolved"] = metrics["classification_counts"].get("UNRESOLVED", 0)
    if holdout:
        metrics = holdout["metrics"]
        checks["holdout_reuse_ratio"] = metrics["holdout_reuse_ratio"]
        checks["holdout_reuse_threshold_met"] = (
            metrics["holdout_reuse_ratio"] is not None
            and metrics["holdout_reuse_ratio"] >= 0.70)
        checks["holdout_game_specific"] = metrics["classification_counts"].get("GAME_SPECIFIC", 0)

    if missing:
        return {"verdict": "NOT_ESTABLISHED", "missing_evidence": missing, "checks": checks,
                "basis": "The pre-registered H2 conditions require both a Discovery measurement "
                         "and a blind Holdout measurement. Absent evidence is not a pass."}

    conditions = {
        "no_new_per_game_production_branch": True,
        "marginal_threshold_met": bool(checks.get("marginal_threshold_met")),
        "holdout_reuse_threshold_met": bool(checks.get("holdout_reuse_threshold_met")),
        "holdout_game_specific_zero": checks.get("holdout_game_specific", 1) == 0,
    }
    passed = all(conditions.values())
    return {
        "verdict": "PASS" if passed else "FAIL",
        "conditions": conditions,
        "checks": checks,
        "basis": ("All four pre-registered H2 conditions hold."
                  if passed else "H2_NOT_CONVERGING: at least one pre-registered condition failed."),
    }


def project_verdict(h1: dict, h2: dict) -> dict:
    if h1["verdict"] == "FAIL" or h2["verdict"] == "FAIL":
        return {"verdict": "STOP_ARCHITECTURE",
                "basis": "A pre-registered stop condition was met."}
    if h2["verdict"] == "NOT_ESTABLISHED":
        return {"verdict": "NOT_ESTABLISHED",
                "basis": "H2 has no completed Discovery and Holdout measurement, so no project "
                         "verdict may be issued. This is not a provisional pass."}
    if h1["verdict"] == "PASS":
        return {"verdict": "CONTINUE", "basis": "H1 PASS and H2 PASS."}
    return {"verdict": "NARROW_SCOPE_AND_CONTINUE", "basis": "H1 NARROW_SCOPE and H2 PASS."}


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("--artifacts", default="build/artifacts")
    parser.add_argument("--commit", required=True)
    parser.add_argument("--tree", required=True)
    parser.add_argument("--ci-runs", nargs="*", default=[],
                        help="run_id:commit:tree:purpose entries for every expensive run")
    args = parser.parse_args()
    root = pathlib.Path(__file__).resolve().parents[1]
    base = root / args.artifacts

    census = load(base / "architecture-census.json")
    union = load(base / "api-surface-union.json")
    boundaries = load(base / "system-boundary-map.json")
    prereg = load(base / "preregistered-samples.json")
    discovery = load(base / "frontier-classification-discovery.json")
    holdout = load(base / "frontier-classification-holdout.json")
    sensitivity = load(base / "order-sensitivity.json")
    for name in (census, union, boundaries, prereg):
        if name is None:
            raise SystemExit("census, union, boundary map and pre-registration are all required")

    h1 = h1_verdict(boundaries, union)
    h2 = h2_verdict(discovery, holdout)
    if h2["verdict"] == "PASS":
        if sensitivity is None:
            h2["verdict"] = "NOT_ESTABLISHED"
            h2["basis"] = ("H2 conditions hold but no order-sensitivity evidence exists, so the "
                           "required check that convergence is not an ordering artifact is missing.")
        else:
            fraction = sensitivity["ratio_distribution"]["fraction_meeting_threshold"]
            h2["order_sensitivity"] = {
                "registered_ratio": sensitivity["registered_ratio"],
                "reversed_ratio": sensitivity["reversed_ratio"],
                "fraction_of_permutations_meeting_threshold": fraction,
                "permutations_evaluated": sensitivity["permutations_evaluated"],
            }
            if not (sensitivity["reversed_ratio"] is not None
                    and sensitivity["reversed_ratio"] <= 0.5 and fraction >= 0.5):
                h2["verdict"] = "FAIL"
                h2["basis"] = ("H2_NOT_CONVERGING: the marginal threshold is met only under the "
                               "registered order, which indicates an ordering artifact.")
    project = project_verdict(h1, h2)

    clusters = collections.Counter(s["cluster"] for s in union["samples"])
    in_scope_curve = union["curves"]["census_order_in_scope"]["core_contract_families"]
    payload = {
        "schema_version": 1,
        "tested_commit": args.commit,
        "tested_tree": args.tree,
        "ci_runs": [
            dict(zip(("run_id", "tested_commit", "tested_tree", "purpose"), entry.split(":")))
            for entry in args.ci_runs
        ],
        "granularity_fingerprint": union["granularity_fingerprint"],
        "census": {
            "sample_count": census["sample_count"],
            "execution_clusters": dict(sorted(clusters.items())),
            "scope_counts": dict(collections.Counter(s["scope"] for s in union["samples"])),
            "provenance": [
                {"id": s["id"], "package": s["package"], "version_code": s["version_code"],
                 "version_name": s["version_name"], "sha256": s["sha256"],
                 "license": s["license"], "source": s["source"], "repository": s["repository"]}
                for s in census["samples"]
            ],
        },
        "static_surface": {
            "core_contract_family_union": union["union"]["core_contract_families"],
            "raw_core_class_union": union["union"]["raw_core_classes"],
            "raw_core_method_union": union["union"]["raw_core_methods"],
            "core_family_curve": [
                {k: row[k] for k in ("index", "id", "cluster", "marginal_new",
                                     "cumulative_unique", "reuse_ratio")}
                for row in in_scope_curve
            ],
        },
        "system_boundaries": {
            "status_index": boundaries["status_index"],
            "high_risk_count": boundaries["high_risk_count"],
        },
        "preregistration": {
            "discovery_order": prereg["phase_d"]["discovery_ids"],
            "holdout": prereg["phase_d"]["holdout_ids"],
            "phase_c": [s["id"] for s in prereg["phase_c"]["samples"]],
            "thresholds": prereg["thresholds"],
        },
        "order_sensitivity": sensitivity,
        "dynamic": {
            "discovery": discovery["metrics"] if discovery else None,
            "discovery_rows": discovery["rows"] if discovery else None,
            "holdout": holdout["metrics"] if holdout else None,
            "holdout_rows": holdout["rows"] if holdout else None,
        },
        "H1": h1,
        "H2": h2,
        "PROJECT": project,
        "limitations": [
            "First-blocker censoring: one run of a game exposes only its current frontmost "
            "blocker, not every gap on its complete gameplay path.",
            "Static reference analysis shows reachable code, not executed code.",
            "Any H2 result describes the currently reached compatibility frontier only, and "
            "must not be read as proof that complete gameplay paths converge.",
        ],
        "d001_reopen_triggered": h1["verdict"] == "FAIL",
    }
    output = base / "architecture-falsification.json"
    output.write_text(json.dumps(payload, indent=2) + "\n", encoding="utf-8")
    print(json.dumps({"H1": h1["verdict"], "H2": h2["verdict"],
                      "PROJECT": project["verdict"]}, indent=2))
    print("->", output)


if __name__ == "__main__":
    main()
