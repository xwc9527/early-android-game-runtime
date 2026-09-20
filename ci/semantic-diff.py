#!/usr/bin/env python3
"""Create or validate AGR V2.1 semantic differentials without subjective confidence."""

import argparse
import json
import pathlib
import sys

CLASSIFICATIONS = {"ANDROID_SEMANTIC_BUG", "HOST_ADAPTATION_BUG", "AGR_INTERNAL_BUG", "HARNESS_BUG", "REFERENCE_MISMATCH", "UNKNOWN"}
SEMANTIC_CLASSES = {"PUBLIC_OBSERVABLE", "SEMANTIC_INVARIANT", "ARCHITECTURE_INVARIANT", "UPSTREAM_IMPLEMENTATION_DETAIL"}
CAUSAL = {"OBSERVED", "PLAUSIBLE", "COUNTERFACTUAL_SUPPORTED", "CONTRACT_CONFIRMED", "REAL_GAME_CONFIRMED"}
LEVEL_BY_TYPE = {"SOURCE": "SOURCE_INFERRED", "RUNTIME": "RUNTIME_OBSERVED", "REFERENCE": "REFERENCE_CONFIRMED",
                 "COUNTERFACTUAL": "COUNTERFACTUAL_SUPPORTED", "CONTRACT": "CONTRACT_CONFIRMED", "REAL_GAME": "REAL_GAME_CONFIRMED"}
LEVEL_ORDER = list(LEVEL_BY_TYPE.values())


def derived_evidence_level(evidence):
    levels = [LEVEL_BY_TYPE[item.get("type")] for item in evidence if item.get("type") in LEVEL_BY_TYPE]
    return max(levels, key=LEVEL_ORDER.index) if levels else None


def validate(doc, experiments=None):
    errors = []
    required = ("schema_version", "classification", "subsystem", "observed_discontinuity", "upstream", "semantic_class",
                "required_semantics", "agr", "differences", "earliest_evidenced_divergence", "causal_status",
                "evidence_level", "evidence", "remaining_uncertainty", "next_action", "needs_experiment", "experimental")
    for key in required:
        if key not in doc: errors.append(f"missing:{key}")
    if doc.get("schema_version") != 2: errors.append("schema_version must be 2")
    if doc.get("classification") not in CLASSIFICATIONS: errors.append("invalid classification")
    if doc.get("semantic_class") not in SEMANTIC_CLASSES: errors.append("invalid semantic_class")
    if doc.get("causal_status") not in CAUSAL: errors.append("invalid causal_status")
    upstream = doc.get("upstream", {})
    for key in ("map_entry", "map_status", "revision", "source_verified", "files", "call_path"):
        if key not in upstream: errors.append(f"upstream missing {key}")
    if upstream.get("revision") not in ("Android 4.4.4_r2", "NOT_APPLICABLE"): errors.append("invalid upstream revision")
    if upstream.get("map_status") not in ("VALID", "STALE", "UNVERIFIED", "INVALID", "NOT_APPLICABLE"): errors.append("invalid map_status")
    if upstream.get("source_verified") and not upstream.get("files"): errors.append("source_verified requires source files")
    if upstream.get("map_status") == "VALID" and not upstream.get("map_entry"): errors.append("VALID map status requires map_entry")
    if upstream.get("source_verified") and not any(item.get("type") == "SOURCE" for item in doc.get("evidence", []) if isinstance(item, dict)):
        errors.append("source_verified requires SOURCE evidence")
    agr = doc.get("agr", {})
    if not isinstance(agr.get("files"), list) or not isinstance(agr.get("call_path"), list): errors.append("agr files/call_path must be arrays")
    if not isinstance(doc.get("required_semantics"), list): errors.append("required_semantics must be an array")
    if not isinstance(doc.get("remaining_uncertainty"), list): errors.append("remaining_uncertainty must be an array")
    for index, difference in enumerate(doc.get("differences", [])):
        if not isinstance(difference, dict) or not all(key in difference for key in ("id", "description", "relevance")):
            errors.append(f"difference {index} requires id/description/relevance")
    evidence = doc.get("evidence", [])
    if not isinstance(evidence, list): errors.append("evidence must be an array")
    derived = derived_evidence_level(evidence if isinstance(evidence, list) else [])
    if doc.get("evidence_level") != derived: errors.append(f"evidence_level must be derived as {derived}")
    types = {item.get("type") for item in evidence if isinstance(item, dict)}
    causal_requirements = {"COUNTERFACTUAL_SUPPORTED": "COUNTERFACTUAL", "CONTRACT_CONFIRMED": "CONTRACT", "REAL_GAME_CONFIRMED": "REAL_GAME"}
    required_type = causal_requirements.get(doc.get("causal_status"))
    if required_type and required_type not in types: errors.append(f"causal_status requires {required_type} evidence")
    if doc.get("needs_experiment"):
        experiment_id = doc.get("experiment_id")
        if not experiment_id: errors.append("needs_experiment requires experiment_id")
        if not doc.get("next_action"): errors.append("needs_experiment requires next_action")
        if experiments is not None and experiment_id not in experiments: errors.append(f"experiment is not registered: {experiment_id}")
    if doc.get("experimental") and not doc.get("experiment_id"): errors.append("experimental artifact requires experiment_id")
    if "confidence" in doc: errors.append("free-form confidence is forbidden in V2.1")
    return errors


def main():
    parser = argparse.ArgumentParser(); sub = parser.add_subparsers(dest="command", required=True)
    new = sub.add_parser("new"); new.add_argument("--subsystem", required=True); new.add_argument("--observed", required=True); new.add_argument("--output", required=True)
    check = sub.add_parser("validate"); check.add_argument("path"); check.add_argument("--experiments", default="ci/experiments.json")
    args = parser.parse_args()
    if args.command == "new":
        doc = {"schema_version": 2, "classification": "UNKNOWN", "subsystem": args.subsystem,
               "observed_discontinuity": args.observed,
               "upstream": {"map_entry": "", "map_status": "UNVERIFIED", "revision": "Android 4.4.4_r2", "source_verified": False, "files": [], "call_path": []},
               "semantic_class": "PUBLIC_OBSERVABLE", "required_semantics": [], "agr": {"files": [], "call_path": []},
               "differences": [], "earliest_evidenced_divergence": "not yet identified", "causal_status": "OBSERVED",
               "evidence_level": "SOURCE_INFERRED", "evidence": [{"type": "SOURCE", "artifact": "pending pinned-source audit"}],
               "remaining_uncertainty": [], "next_action": "inspect pinned source and AGR counterpart", "needs_experiment": False, "experimental": False}
        out = pathlib.Path(args.output); out.parent.mkdir(parents=True, exist_ok=True); out.write_text(json.dumps(doc, indent=2) + "\n", encoding="utf-8"); return 0
    experiment_doc = json.loads(pathlib.Path(args.experiments).read_text(encoding="utf-8"))
    experiments = {item["id"] for item in experiment_doc.get("experiments", [])}
    doc = json.loads(pathlib.Path(args.path).read_text(encoding="utf-8")); errors = validate(doc, experiments)
    for error in errors: print(error, file=sys.stderr)
    return 1 if errors else 0


if __name__ == "__main__": raise SystemExit(main())
