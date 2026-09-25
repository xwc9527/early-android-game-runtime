"""Game Dependency Mapper book builder.

Confidence levels stay distinct. An observed call does not invent the
callees that Source Closure would later slice from API19.
"""

import hashlib
import json
from pathlib import Path

CONFIDENCE = (
    "OBSERVED_RUNTIME",
    "DYNAMIC_DISCOVERED",
    "STATIC_REACHABLE",
    "STATIC_REFERENCED",
    "STATIC_SUSPECT",
)
DYNAMIC_ORIGINS = {
    "reflection",
    "inflate",
    "RegisterNatives",
    "dlopen",
    "dlsym",
    "Class.forName",
    "loadClass",
    "Method.invoke",
}
KINDS = {
    "JAVA_METHOD",
    "JAVA_CLASS",
    "JAVA_FIELD",
    "NATIVE_SYMBOL",
    "NATIVE_LIBRARY",
    "SERVICE",
    "JNI_BINDING",
}


def dependency_id(kind, canonical):
    digest = hashlib.sha256((kind + "\n" + canonical).encode("utf-8")).hexdigest()[:16]
    return kind + ":" + digest


def _record(kind, canonical, confidence, **fields):
    if kind not in KINDS:
        raise ValueError("unknown dependency kind")
    if confidence not in CONFIDENCE:
        raise ValueError("unknown confidence")
    record = {
        "dependency_id": dependency_id(kind, canonical),
        "kind": kind,
        "canonical_name": canonical,
        "confidence": confidence,
        "migration_status": "UNMAPPED",
        "native": kind in ("NATIVE_SYMBOL", "NATIVE_LIBRARY", "JNI_BINDING"),
        "owner_cluster": fields.get("owner_cluster"),
        "caller": fields.get("caller"),
        "callsite": fields.get("callsite"),
        "lifecycle_phase": fields.get("lifecycle_phase"),
        "source_repo": None,
        "source_revision": None,
        "source_module": None,
        "source_file": None,
        "source_symbol": None,
    }
    record.update(fields)
    return record


def from_trace_event(event):
    origin = event.get("origin")
    confidence = "DYNAMIC_DISCOVERED" if origin in DYNAMIC_ORIGINS else "OBSERVED_RUNTIME"
    return _record(
        event["kind"],
        event["canonical_name"],
        confidence,
        caller=event.get("caller"),
        callsite={
            "dex_pc": event.get("dex_pc"),
            "opcode": event.get("opcode"),
            "method_idx": event.get("method_idx"),
        },
        lifecycle_phase=event.get("lifecycle_phase"),
        registration=event.get("registration"),
        service_boundary=event.get("service_boundary"),
        origin=origin,
        resolved_callee=event.get("resolved_callee"),
        native_library=event.get("native_library"),
        native_address=event.get("native_address"),
        transaction_code=event.get("transaction_code"),
        interface_descriptor=event.get("interface_descriptor"),
    )


def from_static(item):
    if item["confidence"] not in ("STATIC_REACHABLE", "STATIC_REFERENCED", "STATIC_SUSPECT"):
        raise ValueError("static input cannot claim OBSERVED_RUNTIME or DYNAMIC_DISCOVERED")
    return _record(
        item["kind"],
        item["canonical_name"],
        item["confidence"],
        caller=item.get("caller"),
        origin=item.get("origin"),
    )


def build_book(apk, trace_events, static_items, trace_evidence=None):
    if trace_events and not trace_evidence:
        raise ValueError("observed dependencies require TRACE run evidence")
    by_id = {}
    for item in static_items:
        record = from_static(item)
        by_id[record["dependency_id"]] = record
    for event in trace_events:
        record = from_trace_event(event)
        previous = by_id.get(record["dependency_id"])
        if previous and previous["confidence"] in ("OBSERVED_RUNTIME", "DYNAMIC_DISCOVERED"):
            previous.setdefault("observations", []).append({
                "caller": record["caller"], "callsite": record["callsite"],
                "lifecycle_phase": record["lifecycle_phase"], "origin": record.get("origin"),
            })
            continue
        record["observations"] = [{
            "caller": record["caller"], "callsite": record["callsite"],
            "lifecycle_phase": record["lifecycle_phase"], "origin": record.get("origin"),
        }]
        by_id[record["dependency_id"]] = record
    book = {
        "schema_version": 1,
        "variant": "TRACE" if trace_evidence else "STATIC_ONLY",
        "role": "dependency_mapper",
        "apk": apk,
        "dependencies": sorted(by_id.values(), key=lambda item: item["dependency_id"]),
        "rule": "Confidence levels are not one verified bit. TRACE does not authorize implementation.",
        "observation_scope": "APP_TRIGGERED_OBSERVED_LOWER_BOUND",
        "unobserved_dependency_status": "UNKNOWN",
        "may_authorize_pruning": False,
    }
    if trace_evidence:
        book["trace_runs"] = [dict(trace_evidence)]
    return book


def write_book(path, book):
    target = Path(path)
    target.parent.mkdir(parents=True, exist_ok=True)
    target.write_text(json.dumps(book, indent=2) + "\n", encoding="utf-8")
    return book


def union_books(books):
    """Union independently identified runs without upgrading static evidence."""
    if not books:
        raise ValueError("at least one book is required")
    hashes = {book["apk"]["sha256"] for book in books}
    if len(hashes) != 1:
        raise ValueError("cannot union different APK identities as one game")
    rank = {name: i for i, name in enumerate(CONFIDENCE)}
    by_id = {}
    for book in books:
        for record in book["dependencies"]:
            key = record["dependency_id"]
            current = by_id.get(key)
            if current is None or rank[record["confidence"]] < rank[current["confidence"]]:
                replacement = dict(record)
                replacement["observations"] = list(record.get("observations", []))
                if current:
                    replacement["observations"] = list(current.get("observations", [])) + replacement["observations"]
                by_id[key] = replacement
            elif current:
                current.setdefault("observations", []).extend(record.get("observations", []))
    trace_runs = [run for book in books for run in book.get("trace_runs", [])]
    return {"schema_version": 1, "variant": "UNION", "role": "dependency_mapper",
            "apk": books[0]["apk"], "run_count": len(books),
            "unobserved_dependency_status": "UNKNOWN", "may_authorize_pruning": False,
            "trace_runs": trace_runs,
            "dependencies": sorted(by_id.values(), key=lambda item: item["dependency_id"])}


def corpus_union(books):
    """Keep each APK's confidence while deduplicating the global dependency set."""
    if not books:
        raise ValueError("at least one book is required")
    by_id = {}
    games = {}
    for book in books:
        apk = book["apk"]["sha256"]
        games[apk] = book["apk"]
        for dep in book["dependencies"]:
            item = by_id.setdefault(dep["dependency_id"], {
                "dependency_id": dep["dependency_id"], "kind": dep["kind"],
                "canonical_name": dep["canonical_name"], "owner_cluster": dep.get("owner_cluster"),
                "games": {},
            })
            item["games"][apk] = dep["confidence"]
    return {"schema_version": 1, "variant": "CORPUS_UNION", "games": games,
            "unobserved_dependency_status": "UNKNOWN", "may_authorize_pruning": False,
            "dependencies": sorted(by_id.values(), key=lambda item: item["dependency_id"])}
