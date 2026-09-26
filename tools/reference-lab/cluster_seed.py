#!/usr/bin/env python3
"""Carry a validated cross-game dependency seed into semantic-cluster review."""

import argparse
import hashlib
import json
from pathlib import Path

from runtime_corpus_summary import load_json
from source_closure import close_entry, closure_work_queue, source_derived_clusters
from workflow import cluster_manifests, validate_book, validate_source_manifests

ROOT = Path(__file__).resolve().parents[2]


def build_seed(corpus_manifest, source_index, canonical_name):
    pinned = (source_index.get("entries") or {}).get(canonical_name)
    if not pinned or not pinned.get("semantic_cluster"):
        raise ValueError("seed lacks a pinned semantic cluster")
    seeds = []
    selected = None
    for probe in corpus_manifest:
        path = Path(probe["book"])
        book_path = path if path.is_absolute() else ROOT / path
        book = load_json(book_path)
        validate_book(book)
        if book.get("may_authorize_pruning") is not False:
            raise ValueError("probe book claims pruning authority")
        matches = [dep for dep in book["dependencies"]
                   if dep["canonical_name"] == canonical_name and
                   dep["confidence"] in ("OBSERVED_RUNTIME", "DYNAMIC_DISCOVERED")]
        if not matches:
            continue
        if len(matches) != 1 or matches[0].get("owner_cluster") != pinned["owner_cluster"]:
            raise ValueError("seed owner or identity differs from source index")
        dep = matches[0]
        if selected is not None and dep["dependency_id"] != selected["dependency_id"]:
            raise ValueError("cross-game dependency ID differs")
        selected = dep
        seeds.append({"game": probe["name"], "canonical_name": canonical_name,
                      "book": path.as_posix(),
                      "book_sha256": hashlib.sha256(book_path.read_bytes()).hexdigest(),
                      "apk_sha256": book["apk"]["sha256"],
                      "dependency_id": dep["dependency_id"],
                      "confidence": dep["confidence"],
                      "observed_count": sum(obs.get("count", 1)
                                            for obs in dep.get("observations", []))})
    if selected is None:
        raise ValueError("no qualified probe observed the source entry")
    source_manifest = close_entry(selected, source_index)
    derived = source_derived_clusters([source_manifest], source_index)
    artifact = {"schema_version": 1, "baseline": "android-4.4.4_r2",
                "source_repo": source_index["source_repo"],
                "source_index_revision": source_index["revision"],
                "may_authorize_pruning": False, "seeds": seeds,
                "manifests": [source_manifest],
                "cluster_source_manifests": cluster_manifests([source_manifest], source_index),
                "source_derived_clusters": derived,
                "closure_work_queue": closure_work_queue([source_manifest], derived)}
    validate_source_manifests(artifact)
    return artifact


def build_cluster_seed(corpus_manifest, source_index, semantic_cluster):
    names = sorted(name for name, entry in (source_index.get("entries") or {}).items()
                   if entry.get("semantic_cluster") == semantic_cluster)
    if not names:
        raise ValueError("semantic cluster has no pinned entries")
    parts = [build_seed(corpus_manifest, source_index, name) for name in names]
    manifests = [part["manifests"][0] for part in parts]
    derived = source_derived_clusters(manifests, source_index)
    artifact = {"schema_version": 1, "baseline": "android-4.4.4_r2",
                "source_repo": source_index["source_repo"],
                "source_index_revision": source_index["revision"],
                "may_authorize_pruning": False,
                "seeds": [seed for part in parts for seed in part["seeds"]],
                "manifests": manifests,
                "cluster_source_manifests": cluster_manifests(manifests, source_index),
                "source_derived_clusters": derived,
                "closure_work_queue": closure_work_queue(manifests, derived)}
    validate_source_manifests(artifact)
    return artifact


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--corpus-manifest", required=True, type=Path)
    parser.add_argument("--source-index", required=True, type=Path)
    selector = parser.add_mutually_exclusive_group(required=True)
    selector.add_argument("--canonical-name")
    selector.add_argument("--semantic-cluster")
    parser.add_argument("--out", required=True, type=Path)
    args = parser.parse_args()
    corpus = json.loads(args.corpus_manifest.read_text(encoding="utf-8"))
    index = json.loads(args.source_index.read_text(encoding="utf-8"))
    artifact = (build_cluster_seed(corpus, index, args.semantic_cluster)
                if args.semantic_cluster else build_seed(corpus, index, args.canonical_name))
    args.out.parent.mkdir(parents=True, exist_ok=True)
    args.out.write_text(json.dumps(artifact, indent=2) + "\n", encoding="utf-8")


if __name__ == "__main__":
    main()
