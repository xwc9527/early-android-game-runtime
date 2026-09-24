#!/usr/bin/env python3
"""Offline Reference Lab artifact pipeline.

TRACE events are accepted only with a matching instrumented-run manifest.
The producer of that manifest is a separate Android build, never AGR.
"""

import argparse
import json
from pathlib import Path

from mapper import build_book, corpus_union, union_books, write_book
from source_closure import close_entry
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
                "apk_sha256", "scenario", "events_sha256")
    missing = [name for name in required if not meta.get(name)]
    if missing:
        raise ValueError("TRACE evidence missing " + ", ".join(missing))
    if meta["variant"] != "TRACE" or meta["instrumented"] is not True or meta["role"] != "dependency_mapper":
        raise ValueError("input is not API19 TRACE evidence")
    if meta["baseline"] != "android-4.4.4_r2" or meta["apk_sha256"] != apk["sha256"]:
        raise ValueError("TRACE baseline or APK identity mismatch")
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
                or not all(run.get(key) for key in ("image_sha256", "scenario", "events_sha256"))):
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
    for item in document.get("manifests", []):
        if item.get("status") not in ("UNRESOLVED", "PARTIAL", "SOURCE_LOCATED",
                                      "SOURCE_CLOSED", "BOUNDARY_CANDIDATE", "BOUNDARY"):
            raise ValueError("invalid source closure status")
        if item["status"] in ("SOURCE_CLOSED", "BOUNDARY"):
            evidence = item.get("closure_evidence") or {}
            if not all(evidence.get(key) for key in ("source_sha256", "reviewed_by", "closure_notes")):
                raise ValueError("closed source manifest lacks review evidence")
            if not all(item.get(key) for key in ("owner_cluster", "source_repo",
                                                 "source_file", "source_symbol")):
                raise ValueError("closed source manifest lacks ownership")
            revision = item.get("source_revision")
            if not isinstance(revision, str) or len(revision) != 40:
                raise ValueError("closed source manifest lacks exact source revision")
        if item["status"] == "BOUNDARY" and item.get("migration_type") != "SERVICE_HLE":
            raise ValueError("closed service boundary lacks SERVICE_HLE type")


def manifests(book, index):
    validate_book(book)
    if book["variant"] == "STATIC_ONLY":
        raise ValueError("static-only book cannot authorize source closure")
    results = [close_entry(dep, index) for dep in book["dependencies"]
               if dep["confidence"] in ("OBSERVED_RUNTIME", "DYNAMIC_DISCOVERED")]
    if not results:
        raise ValueError("book has no observed TRACE dependencies to close")
    clusters = {}
    for item in results:
        if item["status"] not in ("SOURCE_CLOSED", "BOUNDARY"):
            continue
        owner = item["owner_cluster"]
        cluster = clusters.setdefault(owner, {
            "owner_cluster": owner, "dependency_ids": [], "source_files": [],
            "required_symbols": [], "data_structures": [], "init_deps": [],
            "registration_deps": [], "cross_cluster_deps": [], "excluded_deps": [],
            "service_boundaries": [], "host_adaptation_points": [],
        })
        cluster["dependency_ids"].append(item["dependency_id"])
        for key in ("source_files", "required_symbols", "data_structures", "init_deps",
                    "registration_deps", "cross_cluster_deps", "excluded_deps",
                    "service_boundaries", "host_adaptation_points"):
            cluster[key] = sorted(set(cluster[key]) | set(item[key]))
    for cluster in clusters.values():
        cluster["dependency_ids"].sort()
    artifact = {"schema_version": 1, "apk": book["apk"], "source_index_revision": index.get("revision"),
                "manifests": results, "cluster_source_manifests": dict(sorted(clusters.items()))}
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
                              load(args.trace_evidence) if events else None)
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
