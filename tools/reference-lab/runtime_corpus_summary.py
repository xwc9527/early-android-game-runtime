#!/usr/bin/env python3
"""Compact cross-game runtime evidence without discarding raw trajectories."""

import argparse
import gzip
import hashlib
import json
from collections import Counter, defaultdict
from pathlib import Path


def digest(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def load_json(path):
    if path.suffix == ".gz":
        with gzip.open(path, "rt", encoding="utf-8") as handle:
            return json.load(handle)
    return json.loads(path.read_text(encoding="utf-8"))


def summarize(entries):
    games = []
    edge_games = defaultdict(set)
    names = set()
    for entry in entries:
        name = entry["name"]
        if name in names:
            raise ValueError(f"duplicate game name: {name}")
        names.add(name)
        clean_path = Path(entry["clean"])
        trace_path = Path(entry["trace"])
        book_path = Path(entry["book"])
        concordance_path = Path(entry["concordance"])
        clean = load_json(clean_path)
        trace = load_json(trace_path)
        book = load_json(book_path)
        concordance = load_json(concordance_path)
        if clean["status"] != "PASS" or trace["status"] != "PASS" or \
                concordance["status"] != "STATE_CONCORDANT":
            raise ValueError(f"{name}: paired runtime evidence is not complete")
        if clean["apk_sha256"] != trace["apk_sha256"] or \
                clean["apk_sha256"] != book["apk"]["sha256"] or \
                clean["apk_sha256"] != concordance["apk_sha256"] or \
                clean["scenario"] != trace["scenario"] or \
                clean["scenario"] != concordance["scenario"]:
            raise ValueError(f"{name}: evidence identity differs")
        if book.get("may_authorize_pruning") is not False or \
                concordance.get("pruning_authorized") is not False:
            raise ValueError(f"{name}: invalid pruning claim")
        observed = [dep for dep in book["dependencies"]
                    if dep["confidence"] in ("OBSERVED_RUNTIME", "DYNAMIC_DISCOVERED")]
        missing_sequence_bounds = sum(
            observation.get("first_seq") is None or observation.get("last_seq") is None
            for dep in observed for observation in dep.get("observations", []))
        missing_owner = ("OWNER_UNRESOLVED_IN_BOOT_JARS" if book.get("owner_index_basis")
                         else "OWNER_INDEX_NOT_APPLIED")
        clusters = Counter(dep.get("owner_cluster") or missing_owner
                           for dep in observed)
        for dep in observed:
            edge_games[dep["dependency_id"]].add(name)
        games.append({
            "name": name, "apk_sha256": clean["apk_sha256"],
            "arch": clean["arch"], "scenario": clean["scenario"],
            "clean_probe_sha256": digest(clean_path),
            "trace_probe_sha256": digest(trace_path),
            "book_sha256": digest(book_path),
            "concordance_sha256": digest(concordance_path),
            "concordance": concordance["status"],
            "trace_event_count": trace["event_count"],
            "observed_unique_dependencies": len(observed),
            "observations_missing_sequence_bounds": missing_sequence_bounds,
            "observed_owner_clusters": dict(sorted(clusters.items())),
            "clean_app_native_libraries": sorted({library
                for library in (
                    [path for path in clean.get("app_loaded_libraries", [])
                     if path.startswith("/data/app-lib/")] +
                    [path for step in clean["steps"]
                     for path in step["process"].get("app_native_libraries", [])])}),
            "clean_lifecycle_steps": [step["label"] for step in clean["steps"]],
            "clean_visual_status": clean["visual_status"],
            "trace_visual_status": trace["visual_status"],
            "app_crash_lines": clean.get("app_crash_lines", []) +
                               trace.get("app_crash_lines", []),
            "observation_scope": book["observation_scope"],
            "may_authorize_pruning": book["may_authorize_pruning"],
        })
    sharing = Counter(len(names) for names in edge_games.values())
    return {"schema_version": 1, "baseline": "android-4.4.4_r2",
            "scope": "matched lifecycle states and app DEX to boot invoke lower bound",
            "may_authorize_pruning": False,
            "games": games,
            "shared_observed_dependency_counts_by_game_count":
                {str(count): sharing[count] for count in sorted(sharing)},
            "distinct_observed_dependencies": len(edge_games)}


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--manifest", type=Path, required=True)
    parser.add_argument("--out", type=Path, required=True)
    args = parser.parse_args()
    entries = json.loads(args.manifest.read_text())
    result = summarize(entries)
    args.out.write_text(json.dumps(result, indent=2) + "\n")
    print(json.dumps({"games": len(result["games"]),
                      "distinct_observed_dependencies":
                          result["distinct_observed_dependencies"]}))


if __name__ == "__main__":
    main()
