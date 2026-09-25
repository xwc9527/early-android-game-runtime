#!/usr/bin/env python3
"""Prioritize observed API19 source locations across independently run games."""

import argparse
import json
from collections import defaultdict
from pathlib import Path

from runtime_corpus_summary import load_json
from workflow import validate_book

ROOT = Path(__file__).resolve().parents[2]


def build_queue(manifest, source_indexes):
    if isinstance(source_indexes, dict):
        source_indexes = [source_indexes]
    index = {}
    revisions = {}
    for source_index in source_indexes:
        repo = source_index.get("source_repo")
        revision = source_index.get("revision")
        if not repo or not revision or (repo in revisions and revisions[repo] != revision):
            raise ValueError("source indexes must pin one revision per repository")
        revisions[repo] = revision
        for name, location in (source_index.get("entries") or {}).items():
            if name in index:
                raise ValueError("duplicate source location: " + name)
            index[name] = {**location, "source_repo": repo, "source_revision": revision}
    methods = defaultdict(lambda: {"games": set(), "owners": set(), "event_count": 0})
    for entry in manifest:
        path = Path(entry["book"])
        book = load_json(path if path.is_absolute() else ROOT / path)
        validate_book(book)
        if book.get("variant") != "TRACE" or book.get("may_authorize_pruning") is not False:
            raise ValueError("queue requires validated per-run TRACE Books")
        for dep in book["dependencies"]:
            if dep["kind"] != "JAVA_METHOD" or dep["confidence"] not in \
                    ("OBSERVED_RUNTIME", "DYNAMIC_DISCOVERED"):
                continue
            item = methods[dep["canonical_name"]]
            item["games"].add(entry["name"])
            item["owners"].add(dep.get("owner_cluster") or "UNRESOLVED")
            item["event_count"] += sum(obs.get("count", 1)
                                       for obs in dep.get("observations", []))
    queue = []
    for method, item in methods.items():
        location = index.get(method)
        if location and location.get("owner_cluster") not in item["owners"]:
            raise ValueError("source owner differs from observed owner: " + method)
        row = {
            "canonical_name": method,
            "game_count": len(item["games"]),
            "games": sorted(item["games"]),
            "owner_clusters": sorted(item["owners"]),
            "observed_event_count": item["event_count"],
            "source_mapping_status": "SOURCE_LOCATED" if location else "UNMAPPED",
            "source_file": location.get("source_file") if location else None,
            "source_symbol": location.get("source_symbol") if location else None,
            "source_closure_complete": False,
        }
        if location:
            row.update(source_repo=location["source_repo"],
                       source_revision=location["source_revision"],
                       semantic_cluster=location.get("semantic_cluster"))
        queue.append(row)
    queue.sort(key=lambda item: (-item["game_count"],
                                 -item["observed_event_count"],
                                 item["canonical_name"]))
    return {"schema_version": 2, "baseline": "android-4.4.4_r2",
            "scope": "observed app DEX to boot method calls only",
            "may_authorize_pruning": False,
            "migration_authorized": False,
            "source_index_revisions": dict(sorted(revisions.items())),
            "methods": queue}


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--manifest", required=True, type=Path)
    parser.add_argument("--source-index", required=True, type=Path, nargs="+")
    parser.add_argument("--out", required=True, type=Path)
    args = parser.parse_args()
    queue = build_queue(json.loads(args.manifest.read_text()),
                        [json.loads(path.read_text()) for path in args.source_index])
    args.out.write_text(json.dumps(queue, indent=2) + "\n")
    print(json.dumps({"methods": len(queue["methods"]),
                      "shared": sum(item["game_count"] > 1
                                    for item in queue["methods"]),
                      "source_located": sum(item["source_mapping_status"] ==
                                            "SOURCE_LOCATED"
                                            for item in queue["methods"])}))


if __name__ == "__main__":
    main()
