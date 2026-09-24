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
        "native": kind in ("NATIVE_SYMBOL", "JNI_BINDING"),
        "owner_cluster": fields.get("owner_cluster"),
        "caller": fields.get("caller"),
        "callsite": fields.get("callsite"),
        "lifecycle_phase": fields.get("lifecycle_phase"),
        "source_repo": "platform/dalvik",
        "source_revision": "android-4.4.4_r2",
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
    )


def from_static(item):
    if item["confidence"] not in ("STATIC_REACHABLE", "STATIC_REFERENCED", "STATIC_SUSPECT"):
        raise ValueError("static input cannot claim OBSERVED_RUNTIME or DYNAMIC_DISCOVERED")
    return _record(
        item["kind"],
        item["canonical_name"],
        item["confidence"],
        caller=item.get("caller"),
    )


def build_book(apk, trace_events, static_items):
    by_id = {}
    for event in trace_events:
        record = from_trace_event(event)
        by_id[record["dependency_id"]] = record
    for item in static_items:
        record = from_static(item)
        by_id.setdefault(record["dependency_id"], record)
    return {
        "schema_version": 1,
        "variant": "TRACE",
        "role": "dependency_mapper",
        "apk": apk,
        "dependencies": list(by_id.values()),
        "rule": "Confidence levels are not one verified bit. TRACE does not authorize implementation.",
    }


def write_book(path, book):
    Path(path).write_text(json.dumps(book, indent=2) + "\n", encoding="utf-8")
    return book
