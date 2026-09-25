"""API19 source closure from a supplied source index.

The trace entry names the dependency. The index names the source files.
This step does not invent callees that the index does not contain.
"""

MIGRATION_TYPES = ("SOURCE_PORT", "AOSP_NATIVE_ADAPT", "HOST_BOUNDARY", "SERVICE_HLE")
FORBIDDEN = ("ORIGINAL_IMPLEMENTATION", "APPROXIMATION", "GAME_PATCH", "SYNTHETIC_ANDROID_BEHAVIOR")
LIST_FIELDS = (
    "source_files",
    "required_symbols",
    "data_structures",
    "init_deps",
    "registration_deps",
    "cross_cluster_deps",
    "excluded_deps",
    "service_boundaries",
    "host_adaptation_points",
)


def close_entry(entry, index, migration_type="SOURCE_PORT"):
    if migration_type in FORBIDDEN:
        raise ValueError("forbidden migration type: " + migration_type)
    if migration_type not in MIGRATION_TYPES:
        raise ValueError("unknown migration type: " + migration_type)
    manifest = {
        "dependency_id": entry["dependency_id"],
        "canonical_name": entry["canonical_name"],
        "migration_type": migration_type,
        "status": "UNRESOLVED",
        "source_revision": index.get("revision"),
    }
    for name in LIST_FIELDS:
        manifest[name] = []
    manifest["closure_evidence"] = None
    manifest["service_contract"] = None
    service_candidate = entry.get("service_boundary") == "HOST_SERVICE_HLE_BOUNDARY"
    if service_candidate:
        manifest["service_boundaries"] = [entry["canonical_name"]]
        manifest["status"] = "BOUNDARY_CANDIDATE"
    pinned = (index.get("entries") or {}).get(entry["canonical_name"])
    if not pinned:
        return manifest
    for name in LIST_FIELDS:
        manifest[name] = list(pinned.get(name) or [])
    for name in ("owner_cluster", "source_repo", "source_module", "source_file", "source_symbol"):
        if pinned.get(name):
            manifest[name] = pinned[name]
    manifest["status"] = "SOURCE_LOCATED" if manifest["source_files"] and manifest["required_symbols"] else "PARTIAL"
    evidence = pinned.get("closure_evidence")
    revision = index.get("revision")
    if (manifest["status"] == "SOURCE_LOCATED" and pinned.get("closure_reviewed") is True
            and isinstance(evidence, dict) and evidence.get("source_sha256")
            and evidence["source_sha256"] == index.get("source_sha256")
            and evidence.get("reviewed_by") and evidence.get("closure_notes")
            and isinstance(revision, str) and len(revision) == 40
            and all(char in "0123456789abcdef" for char in revision.lower())
            and pinned.get("source_repo") and pinned.get("source_file")
            and pinned.get("source_symbol") and pinned.get("owner_cluster")):
        manifest["status"] = "SOURCE_CLOSED"
        manifest["closure_evidence"] = evidence
    manifest["migration_type"] = pinned.get("migration_type") or migration_type
    if manifest["migration_type"] in FORBIDDEN:
        raise ValueError("forbidden migration type: " + manifest["migration_type"])
    if manifest["migration_type"] not in MIGRATION_TYPES:
        raise ValueError("unknown migration type: " + manifest["migration_type"])
    if service_candidate:
        contract = pinned.get("service_contract")
        if isinstance(contract, dict):
            manifest["service_contract"] = contract
        complete_contract = (isinstance(contract, dict) and
                             contract.get("transaction_code") is not None and
                             all(contract.get(key) for key in (
                                 "interface_descriptor", "request_schema", "response_schema",
                                 "lifecycle", "error_semantics")) and
                             "callbacks" in contract and
                             isinstance(contract["callbacks"], list))
        if manifest["status"] == "SOURCE_CLOSED" and manifest["migration_type"] == "SERVICE_HLE":
            if entry["canonical_name"] not in manifest["service_boundaries"]:
                raise ValueError("reviewed service boundary is not in the source index")
            manifest["status"] = "BOUNDARY" if complete_contract else "BOUNDARY_CANDIDATE"
        else:
            manifest["status"] = "BOUNDARY_CANDIDATE"
    return manifest
