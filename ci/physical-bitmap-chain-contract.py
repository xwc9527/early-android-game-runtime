#!/usr/bin/env python3
"""Validate and correlate one identity-consistent real Bitmap witness trace."""

import argparse
import json
from pathlib import Path


def build_result(summary, width, height):
    run = summary
    runtime = summary
    events = summary.get("bitmap_object_chain") or []
    environment = runtime.get("environment_start") or {}
    display = environment.get("display") or {}
    decodes = [event for event in events if event.get("phase") == "BITMAP_DECODE_WITNESS"]
    fields = [event for event in events if event.get("phase") == "BITMAP_FIELD_WITNESS"]
    references = [event for event in events if event.get("phase") == "BITMAP_REFERENCE_WITNESS"]
    scales = [event for event in references if event.get("method") == "createScaledBitmap"]
    dimensions = [event for event in references if event.get("method") in ("getWidth", "getHeight")]

    decoded_ids = sorted({event.get("object_identity") for event in decodes
                          if event.get("object_identity")})
    scale_sources = []
    for event in scales:
        source_id = event.get("object_identity") or 0
        matching_decodes = [item for item in decodes if item.get("object_identity") == source_id]
        matching_fields = [item for item in fields if item.get("related_identity") == source_id]
        matching_dimensions = [item for item in dimensions if item.get("object_identity") == source_id]
        scale_sources.append({
            "seq": event.get("seq"),
            "exec_id": event.get("exec_id"),
            "source_identity": source_id,
            "matches_decode_return": bool(source_id and matching_decodes),
            "matching_decode_sequences": [item.get("seq") for item in matching_decodes],
            "matches_bitmap_field_value": bool(matching_fields),
            "matching_field_sequences": [item.get("seq") for item in matching_fields],
            "matches_get_width_or_height_receiver": bool(matching_dimensions),
            "matching_dimension_sequences": [item.get("seq") for item in matching_dimensions],
            "backing_flags": event.get("witness_flags"),
            "detail": event.get("detail"),
        })

    first_missing = None
    for item in scale_sources:
        if not item["source_identity"]:
            first_missing = "createScaledBitmap_received_null"
            break
        if not item["matches_decode_return"]:
            first_missing = "scale_source_not_identified_as_decode_return"
            break
        if not item["matches_bitmap_field_value"]:
            first_missing = "no_observed_bitmap_field_link_for_scale_source"
            break
    if not scales and decodes:
        first_missing = "no_createScaledBitmap_source_witness"

    dropped = int(runtime.get("passive_dropped_count") or 0)
    valid = (
        summary.get("classification") != "STALE_OR_MIXED_EVIDENCE"
        and summary.get("manifest_integrity_ok") is True
        and summary.get("identity_valid") is True
        and summary.get("truncated_final_line") is False
        and dropped == 0
        and bool(run.get("run_id"))
        and bool(run.get("commit"))
        and run.get("commit") != "unknown"
        and bool(run.get("tree"))
        and run.get("tree") != "unknown"
        and summary.get("evidence_source") == "current"
        and environment.get("target_type") == "simulator"
        and display.get("runtime_host_width") == width
        and display.get("runtime_host_height") == height
        and bool(decodes)
        and bool(scales)
    )
    result = {
        "schema": "agr.physical-bitmap-chain.v1",
        "evidence_collection_valid": valid,
        "candidate_identity": {"run_id": run.get("run_id"), "commit": run.get("commit"),
                               "tree": run.get("tree")},
        "runtime_host": {"width": display.get("runtime_host_width"),
                         "height": display.get("runtime_host_height"),
                         "native_width": display.get("native_width"),
                         "native_height": display.get("native_height")},
        "passive_dropped_count": dropped,
        "decode_count": len(decodes),
        "decode_events": [{"seq": event.get("seq"), "exec_id": event.get("exec_id"),
                           "resource_id": event.get("resource_id"),
                           "object_identity": event.get("object_identity"),
                           "width": event.get("width"), "height": event.get("height"),
                           "backing_identity": event.get("backing_identity"),
                           "witness_flags": event.get("witness_flags"),
                           "witness_status": event.get("witness_status"),
                           "detail": event.get("detail")} for event in decodes],
        "decoded_bitmap_identities": decoded_ids,
        "bitmap_field_event_count": len(fields),
        "bitmap_field_events": [{"seq": event.get("seq"), "exec_id": event.get("exec_id"),
                                 "owner_identity": event.get("object_identity"),
                                 "value_identity": event.get("related_identity"),
                                 "field": event.get("method"), "detail": event.get("detail")}
                                for event in fields],
        "dimension_receiver_identities": sorted({event.get("object_identity") for event in dimensions
                                                   if event.get("object_identity")}),
        "scale_sources": scale_sources,
        "first_missing_identity_link": first_missing,
        "causality_claimed": False,
        "limitations": [
            "Trace sequence is recorder order; cross-thread order is not treated as causality without a shared guest execution context or synchronization edge.",
            "A missing witness is only decisive when passive_dropped_count is zero and the trace identity/hash checks pass.",
            "Simulator evidence does not replace a new physical-device run of the exact candidate."
        ],
    }
    return result


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("summary", type=Path)
    parser.add_argument("--output", required=True, type=Path)
    parser.add_argument("--width", type=int, required=True)
    parser.add_argument("--height", type=int, required=True)
    args = parser.parse_args()
    summary = json.loads(args.summary.read_text(encoding="utf-8"))
    result = build_result(summary, args.width, args.height)
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(json.dumps(result, indent=2, sort_keys=True) + "\n", encoding="utf-8")
    print(json.dumps(result, indent=2, sort_keys=True))
    return 0 if result["evidence_collection_valid"] else 1


if __name__ == "__main__":
    raise SystemExit(main())
