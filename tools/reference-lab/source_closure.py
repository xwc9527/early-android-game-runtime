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
        "source_revision": "Android 4.4.4_r2",
    }
    for name in LIST_FIELDS:
        manifest[name] = []
    if entry.get("service_boundary") == "HOST_SERVICE_HLE_BOUNDARY":
        manifest["migration_type"] = "SERVICE_HLE"
        manifest["service_boundaries"] = [entry["canonical_name"]]
        manifest["status"] = "BOUNDARY"
        return manifest
    pinned = (index.get("entries") or {}).get(entry["canonical_name"])
    if not pinned:
        return manifest
    for name in LIST_FIELDS:
        manifest[name] = list(pinned.get(name) or [])
    for name in ("owner_cluster", "source_repo", "source_module", "source_file", "source_symbol"):
        if pinned.get(name):
            manifest[name] = pinned[name]
    if manifest["source_files"] and manifest["required_symbols"]:
        manifest["status"] = "SOURCE_CLOSED"
    else:
        manifest["status"] = "PARTIAL"
    manifest["migration_type"] = pinned.get("migration_type") or migration_type
    if manifest["migration_type"] in FORBIDDEN:
        raise ValueError("forbidden migration type: " + manifest["migration_type"])
    return manifest
