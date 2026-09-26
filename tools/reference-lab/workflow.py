#!/usr/bin/env python3
"""Offline Reference Lab artifact pipeline.

TRACE events are accepted only with a matching instrumented-run manifest.
The producer of that manifest is a separate Android build, never AGR.
"""

import argparse
import json
from pathlib import Path

from mapper import build_book, corpus_union, union_books, write_book
from source_closure import (close_entry, closure_work_queue, prerequisite_relations_allow_closure,
                            required_derived_names, reviewed_edge_contracts, source_derived_clusters,
                            validate_prerequisite_relations)
from static_scan import apk_identity, scan_apk


def load(path):
    return json.loads(Path(path).read_text(encoding="utf-8"))


def save(path, value):
    target = Path(path)
    target.parent.mkdir(parents=True, exist_ok=True)
    target.write_text(json.dumps(value, indent=2, sort_keys=True) + "\n", encoding="utf-8")


def trace_events(path, evidence, apk):
    meta = load(evidence)
    required = ("variant", "instrumented", "role", "baseline", "image_sha256",
                "apk_sha256", "scenario", "events_sha256", "observer_coverage",
                "observation_scope", "zygote_preload_sha256", "runtime_config")
    missing = [name for name in required if not meta.get(name)]
    if missing:
        raise ValueError("TRACE evidence missing " + ", ".join(missing))
    if meta["variant"] != "TRACE" or meta["instrumented"] is not True or meta["role"] != "dependency_mapper":
        raise ValueError("input is not API19 TRACE evidence")
    if meta["baseline"] != "android-4.4.4_r2" or meta["apk_sha256"] != apk["sha256"]:
        raise ValueError("TRACE baseline or APK identity mismatch")
    if meta["observation_scope"] != "APP_TRIGGERED_OBSERVED_LOWER_BOUND" or \
            meta.get("may_authorize_pruning") is not False or \
            meta["runtime_config"].get("dalvik.vm.execution-mode") != "int:portable":
        raise ValueError("TRACE observation or execution scope is invalid")
    import hashlib
    data = Path(path).read_bytes()
    if hashlib.sha256(data).hexdigest() != meta["events_sha256"]:
        raise ValueError("TRACE event hash mismatch")
    events = []
    phases = {}
    for line in data.splitlines():
        if not line.strip():
            continue
        event = json.loads(line)
        thread = event.get("thread_id", "process")
        if event.get("event_type") == "LIFECYCLE":
            if not event.get("phase"):
                raise ValueError("lifecycle event missing phase")
            phases[thread] = event["phase"]
            continue
        if event.get("kind") is None or event.get("canonical_name") is None:
            raise ValueError("TRACE event missing dependency kind or canonical name")
        if event["kind"] == "JAVA_METHOD":
            required_java = ("caller", "dex_pc", "opcode", "method_idx", "resolved_callee")
            if any(event.get(name) is None for name in required_java):
                raise ValueError("Java method event lacks a game callsite or resolved callee")
        if event["kind"] == "SERVICE":
            required_service = ("interface_descriptor", "transaction_code", "service_boundary")
            if any(event.get(name) is None for name in required_service):
                raise ValueError("service event lacks boundary identity")
        if event["kind"] == "JNI_BINDING":
            required_jni = ("caller", "registration", "native_library", "native_address")
            if any(event.get(name) is None for name in required_jni):
                raise ValueError("JNI event lacks native registration identity")
        event.setdefault("lifecycle_phase", phases.get(thread, "process_start"))
        events.append(event)
    return events


def validate_book(book):
    if book.get("schema_version") != 1 or book.get("variant") not in ("TRACE", "STATIC_ONLY", "UNION"):
        raise ValueError("unsupported Migration Book")
    if not book.get("apk", {}).get("sha256"):
        raise ValueError("Migration Book missing APK identity")
    if book.get("may_authorize_pruning", False) is not False or \
            book.get("unobserved_dependency_status", "UNKNOWN") != "UNKNOWN":
        raise ValueError("observations cannot authorize pruning or mark unseen code unused")
    runs = book.get("trace_runs", [])
    if not isinstance(runs, list):
        raise ValueError("TRACE run evidence must be a list")
    if book["variant"] == "TRACE" and len(runs) != 1:
        raise ValueError("per-run TRACE book must retain one run manifest")
    if book["variant"] == "STATIC_ONLY" and runs:
        raise ValueError("static book cannot claim TRACE run evidence")
    for run in runs:
        if not isinstance(run, dict):
            raise ValueError("TRACE run evidence must be an object")
        if (run.get("variant") != "TRACE" or run.get("instrumented") is not True
                or run.get("role") != "dependency_mapper"
                or run.get("baseline") != "android-4.4.4_r2"
                or run.get("apk_sha256") != book["apk"]["sha256"]
                or run.get("observation_scope") != "APP_TRIGGERED_OBSERVED_LOWER_BOUND"
                or run.get("may_authorize_pruning") is not False
                or not all(run.get(key) for key in (
                    "image_sha256", "scenario", "events_sha256", "observer_coverage",
                    "zygote_preload_sha256", "runtime_config"))):
            raise ValueError("Migration Book TRACE run identity mismatch")
    from mapper import CONFIDENCE, KINDS, dependency_id
    for dep in book.get("dependencies", []):
        if dep.get("kind") not in KINDS or dep.get("confidence") not in CONFIDENCE:
            raise ValueError("invalid dependency kind or confidence")
        if dep.get("dependency_id") != dependency_id(dep["kind"], dep["canonical_name"]):
            raise ValueError("dependency ID mismatch")
        if book["variant"] == "STATIC_ONLY" and dep["confidence"] in ("OBSERVED_RUNTIME", "DYNAMIC_DISCOVERED"):
            raise ValueError("static book claims runtime observation")
        if dep["confidence"] in ("OBSERVED_RUNTIME", "DYNAMIC_DISCOVERED") and not runs:
            raise ValueError("observed dependency lacks TRACE run evidence")


def validate_source_manifests(document):
    if document.get("schema_version") != 1:
        raise ValueError("unsupported Source Manifest")
    validate_prerequisite_relations(document)
    for item in document.get("manifests", []):
        if item.get("migration_authorized", False) is not False:
            raise ValueError("entry cannot authorize a cluster migration")
        for edge in item.get("cross_cluster_source_edges") or []:
            if (not isinstance(edge, dict) or not edge.get("edge") or
                    not edge.get("semantic_cluster") or not edge.get("source_repo") or
                    not edge.get("source_file") or not edge.get("source_symbol") or
                    not isinstance(edge.get("revision"), str) or len(edge["revision"]) != 40 or
                    not isinstance(edge.get("source_sha256"), str) or
                    len(edge["source_sha256"]) != 64 or
                    edge.get("status") not in ("SOURCE_LOCATED", "SOURCE_CLOSED")):
                raise ValueError("invalid cross-cluster source edge")
        if item.get("status") not in ("UNRESOLVED", "PARTIAL", "SOURCE_LOCATED",
                                      "SOURCE_CLOSED", "BOUNDARY_CANDIDATE", "BOUNDARY"):
            raise ValueError("invalid source closure status")
        if item["status"] in ("SOURCE_CLOSED", "BOUNDARY"):
            if item.get("blocking_edges"):
                raise ValueError("closed source manifest still has blocking edges")
            if any(edge["status"] != "SOURCE_CLOSED"
                   for edge in (item.get("cross_cluster_source_edges") or [])):
                raise ValueError("closed source manifest has open external source edge")
            evidence = item.get("closure_evidence") or {}
            if not all(evidence.get(key) for key in ("reviewed_by", "closure_notes")):
                raise ValueError("closed source manifest lacks review evidence")
            files = item.get("source_files") or []
            if len(files) > 1:
                digests = evidence.get("source_file_sha256") or {}
                edges = {edge for field in ("init_deps", "registration_deps",
                                            "cross_cluster_deps", "excluded_deps",
                                            "service_boundaries", "host_adaptation_points")
                         for edge in (item.get(field) or [])}
                if (not isinstance(digests, dict) or set(digests) != set(files) or
                        any(not isinstance(value, str) or len(value) != 64 or
                            any(c not in "0123456789abcdef" for c in value.lower())
                            for value in digests.values()) or
                        set(evidence.get("reviewed_dependency_edges") or []) != edges or
                        evidence.get("unresolved_dependency_edges") != []):
                    raise ValueError("closed multi-file source manifest lacks closure coverage")
            elif not evidence.get("source_sha256"):
                raise ValueError("closed source manifest lacks source digest")
            if item.get("semantic_cluster") and not reviewed_edge_contracts(item, evidence):
                raise ValueError("closed semantic cluster has unreviewed source edge")
            if not all(item.get(key) for key in ("owner_cluster", "source_repo",
                                                 "source_file", "source_symbol")):
                raise ValueError("closed source manifest lacks ownership")
            revision = item.get("source_revision")
            if not isinstance(revision, str) or len(revision) != 40:
                raise ValueError("closed source manifest lacks exact source revision")
        if item["status"] == "BOUNDARY" and item.get("migration_type") != "SERVICE_HLE":
            raise ValueError("closed service boundary lacks SERVICE_HLE type")
        if item["status"] == "BOUNDARY":
            contract = item.get("service_contract")
            if (not isinstance(contract, dict) or
                    contract.get("transaction_code") is None or
                    not all(contract.get(key) for key in (
                        "interface_descriptor", "request_schema", "response_schema",
                        "lifecycle", "error_semantics")) or
                    not isinstance(contract.get("callbacks"), list)):
                raise ValueError("closed service boundary lacks transaction contract")
    for name, cluster in document.get("cluster_source_manifests", {}).items():
        if cluster.get("semantic_cluster") != name:
            raise ValueError("cluster identity mismatch")
        if cluster.get("status") not in ("SOURCE_LOCATED", "SOURCE_CLOSED",
                                         "MIGRATION_AUTHORIZED"):
            raise ValueError("invalid cluster status")
        if cluster.get("migration_authorized") != (
                cluster["status"] == "MIGRATION_AUTHORIZED"):
            raise ValueError("cluster authorization mismatch")
        members = [item for item in document.get("manifests", [])
                   if item.get("semantic_cluster") == name]
        if cluster["status"] in ("SOURCE_CLOSED", "MIGRATION_AUTHORIZED") and (
                not members or cluster.get("blocking_edges") or
                cluster.get("entry_names") != sorted(item["canonical_name"] for item in members) or
                not all(item["status"] in ("SOURCE_CLOSED", "BOUNDARY") for item in members)):
            raise ValueError("cluster claims closure before every entry closes")
        if cluster["status"] == "MIGRATION_AUTHORIZED":
            review = cluster.get("closure_evidence") or {}
            member_hashes = {}
            for member in members:
                evidence = member.get("closure_evidence") or {}
                files = member.get("source_files") or []
                if len(files) == 1:
                    member_hashes[files[0]] = evidence.get("source_sha256")
                else:
                    member_hashes.update(evidence.get("source_file_sha256") or {})
            edges = {edge for field in ("init_deps", "registration_deps",
                                        "cross_cluster_deps", "excluded_deps",
                                        "service_boundaries", "host_adaptation_points")
                     for edge in cluster.get(field, [])}
            if (not members or not all(item["status"] in ("SOURCE_CLOSED", "BOUNDARY")
                                       for item in members) or
                    review.get("closure_reviewed") is not True or
                    review.get("source_revision") != document.get("source_index_revision") or
                    review.get("entry_names") != sorted(item["canonical_name"] for item in members) or
                    set((review.get("source_file_sha256") or {}).keys()) !=
                    set(cluster.get("source_files") or []) or
                    review.get("source_file_sha256") != member_hashes or
                    set(review.get("reviewed_dependency_edges") or []) != edges or
                    review.get("unresolved_dependency_edges") != [] or
                    not review.get("reviewed_by") or not review.get("closure_notes")):
                raise ValueError("authorized cluster lacks complete source review")
    origins = {item["dependency_id"]: item
               for item in document.get("manifests", [])}
    derived = document.get("source_derived_clusters", {})
    if not required_derived_names(document.get("manifests", []), derived).issubset(derived):
        raise ValueError("source-derived manifest omits a pinned source edge")
    for name, cluster in derived.items():
        if (cluster.get("semantic_cluster") != name or
                cluster.get("provenance") != "SOURCE_DERIVED" or
                cluster.get("migration_authorized") is not False or
                cluster.get("status") not in ("SOURCE_LOCATED", "SOURCE_CLOSED") or
                not set(cluster.get("origin_dependency_ids") or []).issubset(origins) or
                not cluster.get("origin_dependency_ids") or
                not cluster.get("source_paths") or
                not cluster.get("source_repo") or not cluster.get("revision") or
                not cluster.get("source_file_sha256") or
                not cluster.get("required_symbols")):
            raise ValueError("invalid source-derived cluster provenance")
        expected_origins = set()
        for path in cluster["source_paths"]:
            nodes = path.split(" -> ")
            if len(nodes) < 2 or nodes[-1] != name:
                raise ValueError("source-derived path lost its observed parent")
            parents = [dependency_id for dependency_id, item in origins.items()
                       if item["canonical_name"] == nodes[0]]
            if not parents:
                raise ValueError("source-derived path lost its observed parent")
            expected_origins.update(parents)
            previous = origins[parents[0]]
            for node in nodes[1:]:
                edges = previous.get("cross_cluster_source_edges") or []
                target = derived.get(node)
                if not isinstance(target, dict):
                    raise ValueError("source-derived path has no pinned source edge")
                if not any(edge.get("semantic_cluster") == node and
                           edge.get("source_repo") == target.get("source_repo") and
                           edge.get("revision") == target.get("revision") and
                           (target.get("source_file_sha256") or {}).get(edge.get("source_file")) ==
                           edge.get("source_sha256") and
                           edge.get("source_symbol") in (target.get("required_symbols") or [])
                           for edge in edges):
                    raise ValueError("source-derived path has no pinned source edge")
                previous = target
        if expected_origins != set(cluster["origin_dependency_ids"]):
            raise ValueError("source-derived path lost its observed parent")
        actual_cycles = {path for path in cluster["source_paths"]
                         if len(path.split(" -> ")[1:]) !=
                         len(set(path.split(" -> ")[1:]))}
        if set(cluster.get("cycle_paths") or []) != actual_cycles:
            raise ValueError("source-derived cycle evidence differs from source paths")
        if actual_cycles and cluster["status"] != "SOURCE_LOCATED":
            raise ValueError("source-derived cycle cannot claim closure")
        if cluster["status"] == "SOURCE_CLOSED" and (
                cluster.get("blocking_edges") or
                cluster.get("closure_reviewed") is not True or
                not (cluster.get("closure_evidence") or {}).get("reviewed_by") or
                (cluster.get("closure_evidence") or {}).get("unresolved_dependency_edges") != []):
            raise ValueError("source-derived cluster claims closure without review")
    expected_queue = closure_work_queue(document.get("manifests", []), derived)
    if (expected_queue and "closure_work_queue" not in document) or (
            "closure_work_queue" in document and document["closure_work_queue"] != expected_queue):
        raise ValueError("source-closure work queue differs from denied gates")


def cluster_manifests(results, index):
    """Group source entries by reviewed semantic owner, never by broad owner label."""
    clusters = {}
    for item in results:
        name = item.get("semantic_cluster")
        if not name:
            continue
        cluster = clusters.setdefault(name, {
            "semantic_cluster": name, "owner_cluster": item.get("owner_cluster"),
            "status": "SOURCE_LOCATED", "migration_authorized": False,
            "dependency_ids": [], "entry_names": [], "source_files": [],
            "required_symbols": [], "data_structures": [], "init_deps": [],
            "registration_deps": [], "cross_cluster_deps": [], "excluded_deps": [],
            "service_boundaries": [], "host_adaptation_points": [], "blocking_edges": [],
            "cross_cluster_source_edges": [],
            "closure_evidence": None,
        })
        if cluster["owner_cluster"] != item.get("owner_cluster"):
            raise ValueError("semantic cluster crosses owner labels")
        cluster["dependency_ids"].append(item["dependency_id"])
        cluster["entry_names"].append(item["canonical_name"])
        for key in ("source_files", "required_symbols", "data_structures", "init_deps",
                    "registration_deps", "cross_cluster_deps", "excluded_deps",
                    "service_boundaries", "host_adaptation_points", "blocking_edges"):
            cluster[key] = sorted(set(cluster[key]) | set(item[key]))
        by_edge = {edge["edge"]: edge for edge in cluster["cross_cluster_source_edges"]}
        for edge in item.get("cross_cluster_source_edges") or []:
            if edge["edge"] in by_edge and by_edge[edge["edge"]] != edge:
                raise ValueError("cross-cluster source edge has conflicting provenance")
            by_edge[edge["edge"]] = edge
        cluster["cross_cluster_source_edges"] = [by_edge[key] for key in sorted(by_edge)]
        if any("prerequisite_edges" in item for item in results
               if item.get("semantic_cluster") == name):
            merged = {}
            for item in results:
                if item.get("semantic_cluster") != name:
                    continue
                for edge in item.get("prerequisite_edges") or []:
                    merged[edge["edge"]] = edge
            cluster["prerequisite_edges"] = [merged[key] for key in sorted(merged)]
    reviews = index.get("cluster_reviews") or {}
    for name, cluster in clusters.items():
        cluster["dependency_ids"].sort()
        cluster["entry_names"].sort()
        members = [item for item in results if item.get("semantic_cluster") == name]
        known = sorted(key for key, value in (index.get("entries") or {}).items()
                       if value.get("semantic_cluster") == name)
        if (cluster["blocking_edges"] or known != cluster["entry_names"] or not all(
                item["status"] in ("SOURCE_CLOSED", "BOUNDARY") for item in members)):
            continue
        if not prerequisite_relations_allow_closure(
                [edge for item in members for edge in (item.get("prerequisite_edges") or [])]):
            continue
        cluster["status"] = "SOURCE_CLOSED"
        review = reviews.get(name) or {}
        files = cluster["source_files"]
        edges = {edge for field in ("init_deps", "registration_deps",
                                    "cross_cluster_deps", "excluded_deps",
                                    "service_boundaries", "host_adaptation_points")
                 for edge in cluster[field]}
        edges.update(edge["edge"] for edge in cluster.get("prerequisite_edges") or []
                     if isinstance(edge, dict) and edge.get("edge"))
        indexed = index.get("source_file_sha256") or {}
        digests = review.get("source_file_sha256") or {}
        if (review.get("closure_reviewed") is True and
                review.get("source_revision") == index.get("revision") and
                review.get("entry_names") == known and
                review.get("reviewed_by") and review.get("closure_notes") and
                isinstance(digests, dict) and set(digests) == set(files) and
                all(digests[path] == indexed.get(path) for path in files) and
                set(review.get("reviewed_dependency_edges") or []) == edges and
                review.get("unresolved_dependency_edges") == []):
            cluster["status"] = "MIGRATION_AUTHORIZED"
            cluster["migration_authorized"] = True
            cluster["closure_evidence"] = review
    return dict(sorted(clusters.items()))


def manifests(book, index):
    validate_book(book)
    if book["variant"] == "STATIC_ONLY":
        raise ValueError("static-only book cannot authorize source closure")
    results = [close_entry(dep, index) for dep in book["dependencies"]
               if dep["confidence"] in ("OBSERVED_RUNTIME", "DYNAMIC_DISCOVERED")]
    if not results:
        raise ValueError("book has no observed TRACE dependencies to close")
    clusters = cluster_manifests(results, index)
    derived = source_derived_clusters(results, index)
    artifact = {"schema_version": 1, "apk": book["apk"], "source_index_revision": index.get("revision"),
                "manifests": results, "cluster_source_manifests": dict(sorted(clusters.items())),
                "source_derived_clusters": derived,
                "closure_work_queue": closure_work_queue(results, derived)}
    validate_source_manifests(artifact)
    return artifact


def main():
    parser = argparse.ArgumentParser()
    sub = parser.add_subparsers(dest="command", required=True)
    book = sub.add_parser("book")
    book.add_argument("--apk", required=True)
    book.add_argument("--events")
    book.add_argument("--trace-evidence")
    book.add_argument("--out", required=True)
    union = sub.add_parser("union")
    union.add_argument("--books", nargs="+", required=True)
    union.add_argument("--out", required=True)
    corpus = sub.add_parser("corpus-union")
    corpus.add_argument("--books", nargs="+", required=True)
    corpus.add_argument("--out", required=True)
    closure = sub.add_parser("closure")
    closure.add_argument("--book", required=True)
    closure.add_argument("--index", required=True)
    closure.add_argument("--out", required=True)
    closure.add_argument("--require-closed", action="store_true")
    closure.add_argument("--require-authorized-cluster")
    verify = sub.add_parser("validate")
    verify.add_argument("--book")
    verify.add_argument("--manifests")
    args = parser.parse_args()
    if args.command == "book":
        if bool(args.events) != bool(args.trace_evidence):
            parser.error("--events and --trace-evidence must appear together")
        apk = apk_identity(args.apk)
        events = trace_events(args.events, args.trace_evidence, apk) if args.events else []
        artifact = build_book(apk, events, scan_apk(args.apk),
                              load(args.trace_evidence) if args.trace_evidence else None)
        validate_book(artifact)
        write_book(args.out, artifact)
    elif args.command == "union":
        artifact = union_books([load(path) for path in args.books])
        validate_book(artifact)
        save(args.out, artifact)
    elif args.command == "corpus-union":
        books = [load(path) for path in args.books]
        for book in books:
            validate_book(book)
        save(args.out, corpus_union(books))
    elif args.command == "closure":
        artifact = manifests(load(args.book), load(args.index))
        if args.require_closed and any(item["status"] not in ("SOURCE_CLOSED", "BOUNDARY") for item in artifact["manifests"]):
            raise SystemExit("source closure is incomplete")
        if args.require_authorized_cluster and artifact["cluster_source_manifests"].get(
                args.require_authorized_cluster, {}).get("status") != "MIGRATION_AUTHORIZED":
            raise SystemExit("semantic cluster migration is not authorized")
        save(args.out, artifact)
    else:
        if not args.book and not args.manifests:
            parser.error("validate requires --book or --manifests")
        if args.book:
            validate_book(load(args.book))
        if args.manifests:
            validate_source_manifests(load(args.manifests))


if __name__ == "__main__":
    main()
