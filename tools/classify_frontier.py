#!/usr/bin/env python3
"""Classify architecture-falsification frontier results and compute H2 metrics.

Each sample's stopping point is normalized into one public-contract family
using the frozen granularity, then classified against what AGR already
implements. The H2 curves are computed over the pre-registered Discovery order,
never over the order the samples happened to execute in; every probe runs on a
fresh Runtime instance, so execution order cannot affect a sample's result.

Anything this tool cannot map is reported as UNRESOLVED. It never guesses a
family in order to produce a cleaner curve.
"""
from __future__ import annotations

import argparse
import json
import pathlib
import re

from contract_families import FAMILIES, family_for_class

# Families AGR already implements as guest-visible behavior, derived from
# docs/MODULE_STATUS.md stable modules at the phase baseline.
IMPLEMENTED = {
    "app.activity_lifecycle", "app.application_lifecycle", "app.context",
    "app.native_activity", "app.package_info", "resources.asset_access",
    "window.session", "concurrency.handler_looper", "input.motion_event",
    "input.key_event", "jni.bridge", "bionic.libc", "runtime.dex_classloader",
    "native.app_glue", "native.asset_manager", "native.native_window",
    "native.input_queue", "native.looper", "native.log", "native.zlib",
    "native.stlport_gnustl", "graphics.egl_native", "graphics.gles_native",
    "graphics.bitmap", "system.log",
}

DESCRIPTOR = re.compile(r"L([A-Za-z0-9_$/]+);")
DOTTED = re.compile(r"\b((?:android|dalvik|javax\.microedition)(?:\.[A-Za-z0-9_$]+)+)")

# Attribution the automatic rule cannot make, each backed by evidence that is
# independent of the metric it affects. Recorded explicitly so a reviewer can
# check the attribution instead of trusting it.
MANUAL_ATTRIBUTION: dict[str, dict] = {
    "crosswords": {
        "classification": "KNOWN_PUBLIC_CONTRACT",
        "blocking_family": "app.activity_lifecycle",
        "blocking_method": "activity class resolution of a platform Activity subclass",
        "basis": "The launcher activity chain in the APK is GamesList -> XWListActivity -> "
                 "android.app.ListActivity, verified from classes.dex. AGR resolves only "
                 "android.app.Activity as an Activity base, so this is a gap inside the already "
                 "implemented activity lifecycle contract, shared by every app using a platform "
                 "Activity subclass.",
    },
    "flickit": {
        "classification": "RUNTIME_INTERNAL_GAP",
        "blocking_family": None,
        "blocking_method": "Ljava/lang/Object;-><init>V during com.badlogic.gdx.utils.Array.<init>",
        "basis": "ClassCastException raised by AGR's host DEX type system while constructing a "
                 "generic array inside the engine's own code, two frames below any Android API. "
                 "This is an AGR interpreter completeness defect, not an Android public contract "
                 "and not specific to this game; it is excluded from the public-contract counts.",
    },
}

HARNESS_MARKERS = (
    "APK package open failed", "apk_missing", "batch-plan", "resource missing",
    "DEX Runtime creation failed",
)


def families_in(detail: str) -> list[str]:
    """Families in order of first appearance, so the first entry is the blocker."""
    matches = [(m.start(), m.group(1).replace("/", ".")) for m in DESCRIPTOR.finditer(detail)]
    matches += [(m.start(), m.group(1)) for m in DOTTED.finditer(detail)]
    found: list[str] = []
    for _, name in sorted(matches):
        family = family_for_class(name)
        if family and family not in found:
            found.append(family)
    return found


def executed_families(record: dict) -> list[str]:
    """Families of API19 methods the sample actually executed.

    The method trace is a bounded ring, so this is a lower bound on what the
    sample reached, never an upper bound.
    """
    snapshot = record.get("snapshot") or {}
    found: list[str] = []
    for event in snapshot.get("method_trace") or []:
        name = (event.get("method") or "").split(";->")[0]
        if not name.startswith("L"):
            continue
        family = family_for_class(name[1:].replace("/", "."))
        if family and family not in found:
            found.append(family)
    return found


def blocking_method_family(record: dict) -> tuple[str | None, str | None]:
    """The last API19 method the sample executed before it stopped."""
    snapshot = record.get("snapshot") or {}
    last = snapshot.get("last_method") or ""
    name = last.split(";->")[0]
    if name.startswith("L"):
        family = family_for_class(name[1:].replace("/", "."))
        if family:
            return family, last
    for event in reversed(snapshot.get("method_trace") or []):
        method = event.get("method") or ""
        owner = method.split(";->")[0]
        if not owner.startswith("L"):
            continue
        family = family_for_class(owner[1:].replace("/", "."))
        if family:
            return family, method
    return None, last or None


def classify(record: dict, scope: str) -> dict:
    detail = f"{record.get('failure_signature','')} {record.get('raw_detail','')}"
    snapshot = record.get("snapshot") or {}
    detail = f"{detail} {snapshot.get('error','')} {snapshot.get('exception_class','')}"
    found = executed_families(record) or families_in(detail)
    if record.get("launch_result") == 0:
        return {"classification": "KNOWN_PUBLIC_CONTRACT", "families": found,
                "blocking_family": None, "blocking_method": None,
                "basis": "sample reached activity_resumed on the unchanged Runtime"}
    if any(marker.lower() in detail.lower() for marker in HARNESS_MARKERS):
        return {"classification": "HARNESS_DEFECT", "families": found, "blocking_family": None,
                "blocking_method": None,
                "basis": "input or harness precondition failed before Runtime semantics applied"}
    if not scope.startswith("IN_SCOPE"):
        return {"classification": "OUT_OF_SCOPE", "families": found, "blocking_family": None,
                "blocking_method": None, "basis": f"sample scope is {scope}"}
    override = MANUAL_ATTRIBUTION.get(record.get("id"))
    if override:
        return {**override, "families": found or override.get("families", [])}
    blocking, method = blocking_method_family(record)
    if blocking is None:
        return {"classification": "UNRESOLVED", "families": found, "blocking_family": None,
                "blocking_method": method,
                "basis": "no Android public API could be attributed to the stopping point; "
                         "requires manual source attribution"}
    known = blocking in IMPLEMENTED
    return {
        "classification": "KNOWN_PUBLIC_CONTRACT" if known else "NEW_PUBLIC_CONTRACT",
        "families": found,
        "blocking_family": blocking,
        "blocking_method": method,
        "basis": ("blocked inside an already implemented public contract"
                  if known else "blocked on a public API19 contract AGR has not implemented"),
    }


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("--results", default="build/artifacts/architecture-falsification-discovery.json")
    parser.add_argument("--union", default="build/artifacts/api-surface-union.json")
    parser.add_argument("--prereg", default="build/artifacts/preregistered-samples.json")
    parser.add_argument("--set", dest="sample_set", default="falsification-discovery")
    parser.add_argument("--output", default="build/artifacts/frontier-classification.json")
    args = parser.parse_args()
    root = pathlib.Path(__file__).resolve().parents[1]
    results = json.loads((root / args.results).read_text(encoding="utf-8"))
    union = json.loads((root / args.union).read_text(encoding="utf-8"))
    prereg = json.loads((root / args.prereg).read_text(encoding="utf-8"))
    scopes = {s["id"]: s["scope"] for s in union["samples"]}
    clusters = {s["id"]: s["cluster"] for s in union["samples"]}
    by_id = {item["id"]: item for item in results["results"]}

    order = (prereg["phase_d"]["discovery_ids"] if args.sample_set == "falsification-discovery"
             else prereg["phase_d"]["holdout_ids"])

    rows = []
    for index, sample_id in enumerate(order):
        record = by_id.get(sample_id)
        if record is None:
            rows.append({"index": index, "id": sample_id, "cluster": clusters.get(sample_id, ""),
                         "classification": "HARNESS_DEFECT", "families": [],
                         "blocking_family": None,
                         "basis": "sample produced no result record in this run",
                         "last_stage": None, "failure_signature": None})
            continue
        verdict = classify(record, scopes.get(sample_id, "UNKNOWN"))
        rows.append({
            "index": index,
            "id": sample_id,
            "cluster": clusters.get(sample_id, ""),
            "last_stage": record.get("last_stage"),
            "activity_launch_crossed": record.get("activity_launch_crossed"),
            "viewroot_attach_completed": record.get("viewroot_attach_completed"),
            "failure_signature": record.get("failure_signature"),
            "raw_detail": record.get("raw_detail"),
            "framework_trace_length": len((record.get("snapshot") or {}).get("framework_trace") or []),
            "elapsed_ms": record.get("elapsed_ms"),
            **verdict,
        })

    seen: set[str] = set()
    curve = []
    for row in rows:
        families = set(row["families"])
        new = families - seen
        reused = families & seen
        seen |= families
        curve.append({
            "index": row["index"], "id": row["id"], "cluster": row["cluster"],
            "touched": len(families), "marginal_new_contracts": len(new),
            "cumulative_unique_contracts": len(seen),
            "contract_reuse_ratio": round(len(reused) / len(families), 4) if families else None,
            "new_contracts": sorted(new),
        })
    half = min(5, len(curve) // 2) or 1
    c_first = sum(r["marginal_new_contracts"] for r in curve[:half]) / half
    c_last = sum(r["marginal_new_contracts"] for r in curve[-half:]) / half

    in_scope_rows = [r for r in rows if r["classification"] in
                     {"KNOWN_PUBLIC_CONTRACT", "NEW_PUBLIC_CONTRACT"}]
    known = sum(1 for r in in_scope_rows if r["classification"] == "KNOWN_PUBLIC_CONTRACT")
    denominator = len(in_scope_rows)

    payload = {
        "schema_version": 1,
        "sample_set": args.sample_set,
        "granularity_fingerprint": union["granularity_fingerprint"],
        "order_source": "build/artifacts/preregistered-samples.json",
        "rows": rows,
        "curve": curve,
        "metrics": {
            "C_first": c_first,
            "C_last": c_last,
            "c_last_over_c_first": round(c_last / c_first, 4) if c_first else None,
            "threshold_marginal_pass": bool(c_first) and c_last <= 0.5 * c_first,
            "known_over_in_scope_ratio": round(known / denominator, 4) if denominator else None,
            "holdout_reuse_ratio": (round(known / denominator, 4)
                                    if denominator and args.sample_set == "falsification-holdout"
                                    else None),
            "classification_counts": {
                key: sum(1 for r in rows if r["classification"] == key)
                for key in sorted({r["classification"] for r in rows})
            },
        },
        "unmapped_families_seen": sorted(
            {f for r in rows for f in r["families"] if f not in FAMILIES}),
        "limitations": [
            "A single run exposes only the first blocker of each game, not every gap on its "
            "complete gameplay path.",
            "These numbers describe the current compatibility frontier only.",
        ],
    }
    output = root / args.output
    output.parent.mkdir(parents=True, exist_ok=True)
    output.write_text(json.dumps(payload, indent=2) + "\n", encoding="utf-8")
    print(json.dumps(payload["metrics"], indent=2))
    for row in rows:
        print(f"{row['index']:>2} {row['id']:<22} {str(row['last_stage']):<22} "
              f"{row['classification']:<26} {row['blocking_family'] or '-'}")


if __name__ == "__main__":
    main()
