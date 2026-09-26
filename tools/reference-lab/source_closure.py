"""API19 source closure from a supplied source index.

The trace entry names the dependency. The index names the source files.
This step does not invent callees that the index does not contain.
"""

import hashlib
import json

from substrate_contracts import require_production_contract

MIGRATION_TYPES = ("SOURCE_PORT", "AOSP_NATIVE_ADAPT", "HOST_BOUNDARY", "SERVICE_HLE")
FORBIDDEN = ("ORIGINAL_IMPLEMENTATION", "APPROXIMATION", "GAME_PATCH", "SYNTHETIC_ANDROID_BEHAVIOR")
EXTERNAL_DEPENDENCY_FIELDS = ("init_deps", "registration_deps", "cross_cluster_deps",
                              "excluded_deps", "service_boundaries", "host_adaptation_points")
# Confirmed shared runtime substrate. Adding an owner requires an explicit confirmation.
SHARED_RUNTIME_SUBSTRATE_OWNERS = frozenset((
    "Libcore.BootClassLoading",
    "Dalvik.BootClassResolution",
    "Dalvik.ClassInitialization",
    "Dalvik.ClassVerification",
    "Dalvik.Monitor",
    "Dalvik.ThreadState",
    "Dalvik.MethodInvocation",
    "Dalvik.ObjectAllocation",
    "Dalvik.StaticFieldArrayRoots",
    "Dalvik.JNINativeBinding",
    "Bionic.PthreadCondition",
    "Bionic.ClockGettime",
))
PREREQUISITE_RELATIONSHIPS = ("UNRESOLVED", "PREREQUISITE_CLOSED", "REOPEN_REQUIRED")
OWNER_SOURCE_STATUSES = ("SOURCE_LOCATED", "SOURCE_CLOSED")
UPPER_CLOSURE_STATUSES = ("SOURCE_CLOSED", "BOUNDARY", "MIGRATION_AUTHORIZED")
PREREQUISITE_EDGE_FIELDS = ("edge", "semantic_cluster", "relationship", "owner_source_status",
                            "source_repo", "revision", "source_file", "source_symbol", "source_sha256")
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
    "blocking_edges",
    "cross_cluster_source_edges",
)


def reviewed_edge_contracts(item, evidence):
    """A reviewed edge must stay in-source, reach a closed owner, or stop at a real boundary."""
    edges = {edge for field in ("init_deps", "registration_deps",
                                "cross_cluster_deps", "excluded_deps",
                                "service_boundaries", "host_adaptation_points")
             for edge in (item.get(field) or [])}
    reviews = evidence.get("edge_reviews") or {}
    if not isinstance(reviews, dict) or set(reviews) != edges:
        return False
    boundary_edges = set(item.get("excluded_deps") or []) | \
        set(item.get("service_boundaries") or []) | \
        set(item.get("host_adaptation_points") or [])
    for edge, review in reviews.items():
        if not isinstance(review, dict):
            return False
        kind = review.get("disposition")
        if kind == "IN_CLUSTER":
            if (review.get("source_repo") != item.get("source_repo") or
                    review.get("revision") != item.get("source_revision") or
                    review.get("source_file") not in (item.get("source_files") or []) or
                    not review.get("source_symbol")):
                return False
        elif kind == "SOURCE_CLOSED_EXTERNAL":
            revision = review.get("revision")
            digest = review.get("source_manifest_sha256")
            if (not review.get("semantic_cluster") or not review.get("source_repo") or
                    not review.get("source_file") or not review.get("source_symbol") or
                    not isinstance(revision, str) or len(revision) != 40 or
                    not isinstance(digest, str) or len(digest) != 64):
                return False
        elif kind == "EXCLUDED_BOUNDARY":
            contract = review.get("boundary_contract") or {}
            if (edge not in boundary_edges or not isinstance(contract, dict) or
                    not all(contract.get(key) for key in
                            ("request_schema", "response_schema", "lifecycle",
                             "error_semantics")) or
                    not isinstance(contract.get("callbacks"), list)):
                return False
        else:
            return False
    return True


def external_edge_closed(edge, index, seen=None):
    """An edge label alone cannot certify a different semantic owner's closure."""
    if not isinstance(edge, dict) or edge.get("status") != "SOURCE_CLOSED":
        return False
    cluster = edge.get("semantic_cluster")
    seen = seen or frozenset()
    if cluster in seen:
        return False
    owner = (index.get("external_cluster_sources") or {}).get(cluster)
    if not isinstance(owner, dict) or owner.get("status") != "SOURCE_CLOSED":
        return False
    if owner.get("source_repo") != edge.get("source_repo") or owner.get("revision") != edge.get("revision"):
        return False
    files = owner.get("source_file_sha256") or {}
    if (not isinstance(files, dict) or files.get(edge.get("source_file")) != edge.get("source_sha256")
            or edge.get("source_symbol") not in (owner.get("required_symbols") or [])):
        return False
    if owner.get("blocking_edges") or owner.get("closure_reviewed") is not True:
        return False
    cross = owner.get("cross_cluster_deps") or []
    pinned_cross = owner.get("cross_cluster_source_edges") or []
    if (set(cross) != {item.get("edge") for item in pinned_cross if isinstance(item, dict)}
            or len(cross) != len(pinned_cross)
            or any(not external_edge_closed(item, index, seen | {cluster})
                   for item in pinned_cross)):
        return False
    boundaries = owner.get("boundary_contracts") or {}
    if set(boundaries) != set(owner.get("excluded_deps") or []):
        return False
    for contract in boundaries.values():
        if (not isinstance(contract, dict) or
                not all(contract.get(key) for key in
                        ("request_schema", "response_schema", "lifecycle", "error_semantics")) or
                not isinstance(contract.get("callbacks"), list)):
            return False
    review = owner.get("closure_evidence") or {}
    deps = {dep for field in EXTERNAL_DEPENDENCY_FIELDS for dep in (owner.get(field) or [])}
    return (review.get("source_file_sha256") == files
            and set(review.get("reviewed_dependency_edges") or []) == deps
            and review.get("unresolved_dependency_edges") == []
            and bool(review.get("reviewed_by")) and bool(review.get("closure_notes")))


def external_owner_digest(owner):
    return hashlib.sha256(json.dumps(owner, sort_keys=True, separators=(",", ":"),
                                     ensure_ascii=False).encode("utf-8")).hexdigest()


CROSSING_FIELDS = ("edge", "semantic_cluster", "source_repo", "revision",
                   "source_file", "source_symbol", "source_sha256")


def crossing_identity(edge):
    if not isinstance(edge, dict):
        return None
    return tuple(edge.get(field) for field in CROSSING_FIELDS)


def prerequisite_matches_crossing(prerequisite, crossing):
    """A relationship may name only the edge, owner, repo, revision, file, symbol, and SHA it stops."""
    return (isinstance(prerequisite, dict) and isinstance(crossing, dict) and
            all(prerequisite.get(field) == crossing.get(field) for field in CROSSING_FIELDS))


def matching_stop_keys(item):
    """Stop keys belong to one owner and only to crossings that owner actually has."""
    if not isinstance(item, dict):
        return set()
    crossings = [edge for edge in (item.get("cross_cluster_source_edges") or [])
                 if isinstance(edge, dict)]
    return {crossing_identity(edge) for edge in (item.get("prerequisite_edges") or [])
            if any(prerequisite_matches_crossing(edge, crossing) for crossing in crossings)}


def path_absorbs_stopped_edge(paths, owner_label, stopped_child, cluster_name):
    """Absorption is the declaring owner's own hop into the stopped child, not another path."""
    if not owner_label or not stopped_child or not cluster_name:
        return False
    for path in paths or []:
        nodes = path.split(" -> ")
        for index, node in enumerate(nodes):
            if node != owner_label:
                continue
            tail = nodes[index + 1:]
            if tail and tail[0] == stopped_child and cluster_name in tail:
                return True
    return False


def _declaring_labels(item):
    labels = []
    if item.get("canonical_name"):
        labels.append(item["canonical_name"])
    for name in item.get("entry_names") or []:
        if name not in labels:
            labels.append(name)
    return labels


def required_derived_names(manifests, derived):
    """A nested stop comes from that derived owner, not from an ancestor's stop keys."""
    required = set()
    manifests = [item for item in manifests if isinstance(item, dict)]
    for item in manifests:
        stops = matching_stop_keys(item)
        for edge in item.get("cross_cluster_source_edges") or []:
            if crossing_identity(edge) not in stops:
                required.add(edge.get("semantic_cluster"))
    for cluster in (derived or {}).values():
        if not isinstance(cluster, dict):
            continue
        stops = matching_stop_keys(cluster)
        reached = set(cluster.get("origin_dependency_ids") or [])
        for edge in cluster.get("cross_cluster_source_edges") or []:
            if crossing_identity(edge) in stops and reached:
                continue
            required.add(edge.get("semantic_cluster"))
    return required


def reject_unmatched_owner_prerequisites(owner):
    """A derived owner's relationships match only that owner's own crossings."""
    edges = owner.get("prerequisite_edges") if isinstance(owner, dict) else None
    if not edges:
        return
    if not isinstance(edges, list):
        raise ValueError("prerequisite edges must be a list")
    crossings = [edge for edge in (owner.get("cross_cluster_source_edges") or [])
                 if isinstance(edge, dict)]
    for edge in edges:
        validate_prerequisite_edge(edge)
        if not any(prerequisite_matches_crossing(edge, crossing) for crossing in crossings):
            raise ValueError("prerequisite does not match a crossing source edge")


def require_prerequisite_closed_authority(prerequisite, crossing, index, contracts=None,
                                          evidence=None, modules=None):
    """PREREQUISITE_CLOSED needs a closed source owner and cited production evidence."""
    if not external_edge_closed(crossing, index or {}):
        raise ValueError("source owner is not closed")
    owner = ((index or {}).get("external_cluster_sources") or {}).get(crossing.get("semantic_cluster"))
    require_production_contract(crossing.get("semantic_cluster"), owner.get("revision") if isinstance(owner, dict) else None,
                                external_owner_digest(owner) if isinstance(owner, dict) else None,
                                contracts, evidence, modules)


def _matching_crossing(prerequisite, crossings):
    return next((crossing for crossing in crossings or []
                 if isinstance(crossing, dict) and prerequisite_matches_crossing(prerequisite, crossing)), None)


def prerequisite_relations_allow_closure(edges, crossings=None, index=None, contracts=None,
                                         evidence=None, modules=None):
    """Missing edges keep the legacy closure path. A closed relationship must cite production authority."""
    if not edges:
        return True
    for edge in edges:
        if (not isinstance(edge, dict) or edge.get("relationship") != "PREREQUISITE_CLOSED"
                or edge.get("owner_source_status") != "SOURCE_CLOSED"
                or edge.get("semantic_cluster") not in SHARED_RUNTIME_SUBSTRATE_OWNERS):
            return False
        matched = _matching_crossing(edge, crossings)
        if matched is None:
            raise ValueError("prerequisite does not match a crossing source edge")
        require_prerequisite_closed_authority(edge, matched, index, contracts, evidence, modules)
    return True


def validate_prerequisite_edge(edge):
    """Relationship state stays off the owner SOURCE_LOCATED|SOURCE_CLOSED field."""
    if not isinstance(edge, dict):
        raise ValueError("prerequisite edge must be an object")
    if "status" in edge:
        raise ValueError("prerequisite relationship must not use owner source status")
    for key in PREREQUISITE_EDGE_FIELDS:
        if not edge.get(key):
            raise ValueError("prerequisite edge lacks " + key)
    if edge["semantic_cluster"] not in SHARED_RUNTIME_SUBSTRATE_OWNERS:
        raise ValueError("substrate owner is not confirmed: " + edge["semantic_cluster"])
    if edge["relationship"] not in PREREQUISITE_RELATIONSHIPS:
        raise ValueError("invalid prerequisite relationship")
    if edge["owner_source_status"] not in OWNER_SOURCE_STATUSES:
        raise ValueError("invalid substrate owner source status")
    if edge["relationship"] == "PREREQUISITE_CLOSED" and edge["owner_source_status"] != "SOURCE_CLOSED":
        raise ValueError("closed prerequisite requires a closed substrate owner")
    if not isinstance(edge["revision"], str) or len(edge["revision"]) != 40:
        raise ValueError("prerequisite edge lacks exact source revision")
    if not isinstance(edge["source_sha256"], str) or len(edge["source_sha256"]) != 64:
        raise ValueError("prerequisite edge lacks source digest")
    internals = edge.get("internal_clusters", [])
    if (not isinstance(internals, list) or
            any(name not in SHARED_RUNTIME_SUBSTRATE_OWNERS for name in internals)):
        raise ValueError("substrate internal clusters are not confirmed owners")


def reject_substrate_bypass(item):
    """A private file, HLE boundary, or forbidden migration type cannot satisfy the prerequisite."""
    edges = item.get("prerequisite_edges") or []
    if not edges:
        return
    migration = item.get("migration_type")
    if migration in FORBIDDEN or migration == "SERVICE_HLE":
        raise ValueError("migration type cannot bypass a shared substrate prerequisite")
    if item.get("status") == "BOUNDARY":
        raise ValueError("service boundary cannot bypass a shared substrate prerequisite")
    owned = set()
    for edge in edges:
        if not isinstance(edge, dict):
            continue
        if edge.get("source_file"):
            owned.add(edge["source_file"])
        for path in edge.get("owner_source_files") or []:
            owned.add(path)
    if owned & set(item.get("source_files") or []):
        raise ValueError("private source file cannot bypass a shared substrate prerequisite")
    reviews = (item.get("closure_evidence") or {}).get("edge_reviews") or {}
    if isinstance(reviews, dict):
        for review in reviews.values():
            if (isinstance(review, dict) and
                    review.get("semantic_cluster") in SHARED_RUNTIME_SUBSTRATE_OWNERS and
                    review.get("disposition") == "EXCLUDED_BOUNDARY"):
                raise ValueError("HLE boundary cannot bypass a shared substrate prerequisite")


def _reached_prerequisite_blocks_closure(derived, origin_ids):
    """A reached derived owner with an open prerequisite blocks the upper closure that reached it."""
    for cluster in derived.values():
        if not isinstance(cluster, dict):
            continue
        if not origin_ids & set(cluster.get("origin_dependency_ids") or []):
            continue
        if any(isinstance(edge, dict) and edge.get("relationship") in ("UNRESOLVED", "REOPEN_REQUIRED")
               for edge in (cluster.get("prerequisite_edges") or [])):
            return True
    return False


def _reject_absorbed_owner_crossings(cluster, derived):
    """A derived owner's stop covers only hops that leave that owner."""
    stops = matching_stop_keys(cluster)
    owner_name = cluster.get("semantic_cluster")
    for source_edge in cluster.get("cross_cluster_source_edges") or []:
        if not isinstance(source_edge, dict) or crossing_identity(source_edge) not in stops:
            continue
        stopped_child = source_edge.get("semantic_cluster")
        absorbed = [stopped_child]
        for edge in cluster.get("prerequisite_edges") or []:
            if isinstance(edge, dict) and prerequisite_matches_crossing(edge, source_edge):
                absorbed.extend(edge.get("internal_clusters") or [])
        for cluster_name in absorbed:
            row = derived.get(cluster_name)
            if not isinstance(row, dict):
                continue
            if path_absorbs_stopped_edge(row.get("source_paths"), owner_name,
                                          stopped_child, cluster_name):
                raise ValueError("upper cluster absorbed shared substrate internals")


def _require_closed_relationships(item, index, contracts, evidence, modules):
    crossings = [edge for edge in (item.get("cross_cluster_source_edges") or []) if isinstance(edge, dict)]
    for edge in item.get("prerequisite_edges") or []:
        if isinstance(edge, dict) and edge.get("relationship") == "PREREQUISITE_CLOSED":
            matched = _matching_crossing(edge, crossings)
            if matched is None:
                raise ValueError("prerequisite does not match a crossing source edge")
            require_prerequisite_closed_authority(edge, matched, index, contracts, evidence, modules)


def validate_prerequisite_relations(document, index=None, contracts=None, evidence=None, modules=None):
    """Validate upper-cluster prerequisite relationships without reclassifying legacy documents."""
    derived = document.get("source_derived_clusters") or {}
    items = list(document.get("manifests") or [])
    items.extend((document.get("cluster_source_manifests") or {}).values())
    for item in items:
        if not isinstance(item, dict):
            continue
        edges = item.get("prerequisite_edges")
        crossing = [edge for edge in (item.get("cross_cluster_source_edges") or [])
                    if isinstance(edge, dict) and
                    edge.get("semantic_cluster") in SHARED_RUNTIME_SUBSTRATE_OWNERS]
        closed_upper = item.get("status") in UPPER_CLOSURE_STATUSES
        if edges is None and closed_upper and crossing:
            raise ValueError("shared substrate crossing requires a prerequisite relationship")
        origin_ids = set(item.get("dependency_ids") or [])
        if item.get("dependency_id"):
            origin_ids.add(item["dependency_id"])
        if edges:
            if not isinstance(edges, list):
                raise ValueError("prerequisite edges must be a list")
            reject_substrate_bypass(item)
            crossings = [edge for edge in (item.get("cross_cluster_source_edges") or [])
                         if isinstance(edge, dict)]
            seen = {}
            for edge in edges:
                validate_prerequisite_edge(edge)
                if not any(prerequisite_matches_crossing(edge, crossing) for crossing in crossings):
                    raise ValueError("prerequisite does not match a crossing source edge")
                name = edge["semantic_cluster"]
                if name in seen and seen[name] != edge["relationship"]:
                    raise ValueError("conflicting substrate prerequisite relationship")
                seen[name] = edge["relationship"]
            _require_closed_relationships(item, index, contracts, evidence, modules)
            by_owner = {}
            for source_edge in crossings:
                if source_edge.get("semantic_cluster") in SHARED_RUNTIME_SUBSTRATE_OWNERS:
                    by_owner.setdefault(source_edge["semantic_cluster"], []).append(source_edge)
            stops = matching_stop_keys(item)
            fully_truncated = {owner for owner, owner_edges in by_owner.items()
                               if owner_edges and all(crossing_identity(source_edge) in stops
                                                      for source_edge in owner_edges)}
            labels = _declaring_labels(item)
            for edge in edges:
                if edge["semantic_cluster"] not in fully_truncated:
                    continue
                stopped_child = edge["semantic_cluster"]
                absorbed = [stopped_child] + list(edge.get("internal_clusters") or [])
                for cluster_name in absorbed:
                    row = derived.get(cluster_name)
                    if not isinstance(row, dict):
                        continue
                    if any(path_absorbs_stopped_edge(row.get("source_paths"), label,
                                                     stopped_child, cluster_name)
                           for label in labels):
                        raise ValueError("upper cluster absorbed shared substrate internals")
            if closed_upper and any(edge["relationship"] != "PREREQUISITE_CLOSED" for edge in edges):
                raise ValueError("substrate prerequisite blocks upper closure")
            if closed_upper and not {edge.get("semantic_cluster") for edge in crossings
                                     if edge.get("semantic_cluster") in SHARED_RUNTIME_SUBSTRATE_OWNERS}.issubset(
                    {edge["semantic_cluster"] for edge in edges
                     if edge["relationship"] == "PREREQUISITE_CLOSED"}):
                raise ValueError("shared substrate crossing requires a closed prerequisite")
        if closed_upper and _reached_prerequisite_blocks_closure(derived, origin_ids):
            raise ValueError("substrate prerequisite blocks upper closure")
    for cluster in derived.values():
        if not isinstance(cluster, dict) or not cluster.get("prerequisite_edges"):
            continue
        reject_unmatched_owner_prerequisites(cluster)
        _require_closed_relationships(cluster, index, contracts, evidence, modules)
        _reject_absorbed_owner_crossings(cluster, derived)


def _matches_pinned_owner(edge, owner):
    return (isinstance(owner, dict) and
            owner.get("source_repo") == edge.get("source_repo") and
            owner.get("revision") == edge.get("revision") and
            owner.get("source_file_sha256", {}).get(edge.get("source_file")) == edge.get("source_sha256") and
            edge.get("source_symbol") in (owner.get("required_symbols") or []))


def source_derived_clusters(manifests, index, contracts=None, evidence=None, modules=None):
    """Expand pinned source edges. Stop keys belong to the owner that declares them."""
    owners = index.get("external_cluster_sources") or {}
    found = {}

    def stop_authorized(item, edge):
        if crossing_identity(edge) not in matching_stop_keys(item):
            return False
        for prerequisite in item.get("prerequisite_edges") or []:
            if (isinstance(prerequisite, dict) and prerequisite.get("relationship") == "PREREQUISITE_CLOSED"
                    and prerequisite_matches_crossing(prerequisite, edge)):
                require_prerequisite_closed_authority(prerequisite, edge, index, contracts, evidence, modules)
        return True

    def stop_before_entering(edge):
        name = edge.get("semantic_cluster")
        if not _matches_pinned_owner(edge, owners.get(name)):
            raise ValueError("substrate prerequisite differs from pinned owner: " + str(name))

    def visit(edge, parent_id, path):
        name = edge.get("semantic_cluster")
        owner = owners.get(name)
        if not isinstance(owner, dict):
            raise ValueError("source-derived edge lacks a pinned owner: " + str(name))
        if not _matches_pinned_owner(edge, owner):
            raise ValueError("source-derived edge differs from pinned owner: " + name)
        reject_unmatched_owner_prerequisites(owner)
        row = found.setdefault(name, {**owner, "semantic_cluster": name,
                                      "provenance": "SOURCE_DERIVED",
                                      "migration_authorized": False,
                                      "origin_dependency_ids": set(),
                                      "source_paths": set(),
                                      "cycle_paths": set(),
                                      "status": "SOURCE_CLOSED"})
        row["origin_dependency_ids"].add(parent_id)
        source_path = " -> ".join(path + (name,))
        row["source_paths"].add(source_path)
        if not external_edge_closed(edge, index):
            row["status"] = "SOURCE_LOCATED"
        if name in path:
            row["cycle_paths"].add(source_path)
            row["status"] = "SOURCE_LOCATED"
            return
        for child in owner.get("cross_cluster_source_edges") or []:
            if stop_authorized(owner, child):
                stop_before_entering(child)
                continue
            visit(child, parent_id, path + (name,))

    for manifest in manifests:
        for edge in manifest.get("cross_cluster_source_edges") or []:
            if stop_authorized(manifest, edge):
                stop_before_entering(edge)
                continue
            visit(edge, manifest["dependency_id"], (manifest["canonical_name"],))
    for row in found.values():
        row["origin_dependency_ids"] = sorted(row["origin_dependency_ids"])
        row["source_paths"] = sorted(row["source_paths"])
        row["cycle_paths"] = sorted(row["cycle_paths"])
    return dict(sorted(found.items()))


def closure_work_queue(manifests, derived, index=None, contracts=None, evidence=None, modules=None):
    """Turn denied source-closure gates into traceable next-edge work."""
    queue = []
    for item in manifests:
        for edge in item.get("blocking_edges") or []:
            queue.append({"scope": "OBSERVED_ENTRY", "semantic_cluster": item.get("semantic_cluster"),
                          "blocking_edge": edge, "origin_dependency_ids": [item["dependency_id"]],
                          "source_paths": [item["canonical_name"]]})
        for edge in item.get("prerequisite_edges") or []:
            if not isinstance(edge, dict):
                continue
            if edge.get("relationship") == "PREREQUISITE_CLOSED":
                _require_closed_relationships(item, index, contracts, evidence, modules)
                continue
            if edge.get("relationship") not in ("UNRESOLVED", "REOPEN_REQUIRED"):
                continue
            queue.append({"scope": "PREREQUISITE", "semantic_cluster": edge.get("semantic_cluster"),
                          "blocking_edge": edge.get("edge"), "relationship": edge.get("relationship"),
                          "origin_dependency_ids": [item["dependency_id"]],
                          "source_paths": [item.get("canonical_name")]})
    for name, owner in derived.items():
        if owner["status"] != "SOURCE_CLOSED":
            for edge in owner.get("blocking_edges") or []:
                queue.append({"scope": "SOURCE_DERIVED", "semantic_cluster": name,
                              "blocking_edge": edge,
                              "origin_dependency_ids": owner["origin_dependency_ids"],
                              "source_paths": owner["source_paths"]})
        for edge in owner.get("prerequisite_edges") or []:
            if not isinstance(edge, dict):
                continue
            if edge.get("relationship") == "PREREQUISITE_CLOSED":
                _require_closed_relationships(owner, index, contracts, evidence, modules)
                continue
            if edge.get("relationship") not in ("UNRESOLVED", "REOPEN_REQUIRED"):
                continue
            if not any(prerequisite_matches_crossing(edge, crossing)
                       for crossing in (owner.get("cross_cluster_source_edges") or [])
                       if isinstance(crossing, dict)):
                continue
            queue.append({"scope": "PREREQUISITE", "semantic_cluster": edge.get("semantic_cluster"),
                          "blocking_edge": edge.get("edge"), "relationship": edge.get("relationship"),
                          "origin_dependency_ids": list(owner["origin_dependency_ids"]),
                          "source_paths": list(owner["source_paths"])})
    return sorted(queue, key=lambda item: (item["scope"], item["semantic_cluster"] or "",
                                           item["blocking_edge"]))


def reviewed_source_set(pinned, index, evidence, contracts=None, production_evidence=None, modules=None):
    """A multi-file closure must pin every file and account for every listed edge."""
    if pinned.get("blocking_edges"):
        return False
    if not prerequisite_relations_allow_closure(
            pinned.get("prerequisite_edges"), pinned.get("cross_cluster_source_edges"),
            index, contracts, production_evidence, modules):
        return False
    if any(not external_edge_closed(edge, index)
           for edge in (pinned.get("cross_cluster_source_edges") or [])):
        return False
    files = pinned.get("source_files") or []
    if len(files) <= 1:
        if evidence.get("source_sha256") != index.get("source_sha256"):
            return False
    else:
        indexed = index.get("source_file_sha256") or {}
        reviewed = evidence.get("source_file_sha256") or {}
        if not isinstance(indexed, dict) or not isinstance(reviewed, dict):
            return False
        if set(files) != set(reviewed) or not set(files).issubset(indexed):
            return False
        if any(reviewed[path] != indexed[path] or
               not isinstance(reviewed[path], str) or len(reviewed[path]) != 64 or
               any(char not in "0123456789abcdef" for char in reviewed[path].lower())
               for path in files):
            return False
    edges = {edge for field in ("init_deps", "registration_deps",
                                "cross_cluster_deps", "excluded_deps",
                                "service_boundaries", "host_adaptation_points")
             for edge in (pinned.get(field) or [])}
    if len(files) > 1 and (set(evidence.get("reviewed_dependency_edges") or []) != edges or
                           evidence.get("unresolved_dependency_edges") != []):
        return False
    if pinned.get("semantic_cluster"):
        if not reviewed_edge_contracts({**pinned, "source_revision": index.get("revision")}, evidence):
            return False
        by_name = {edge.get("edge"): edge for edge in (pinned.get("cross_cluster_source_edges") or [])
                   if isinstance(edge, dict)}
        for name, review in (evidence.get("edge_reviews") or {}).items():
            if review.get("disposition") != "SOURCE_CLOSED_EXTERNAL":
                continue
            edge = by_name.get(name)
            owner = (index.get("external_cluster_sources") or {}).get(review["semantic_cluster"])
            if (not edge or not external_edge_closed(edge, index) or not owner or
                    any(review.get(key) != edge.get(key) for key in
                        ("semantic_cluster", "source_repo", "revision", "source_file", "source_symbol")) or
                    review.get("source_manifest_sha256") != external_owner_digest(owner)):
                return False
    return True


def close_entry(entry, index, migration_type="SOURCE_PORT", contracts=None,
               production_evidence=None, modules=None):
    if migration_type in FORBIDDEN:
        raise ValueError("forbidden migration type: " + migration_type)
    if migration_type not in MIGRATION_TYPES:
        raise ValueError("unknown migration type: " + migration_type)
    manifest = {
        "dependency_id": entry["dependency_id"],
        "canonical_name": entry["canonical_name"],
        "migration_type": migration_type,
        "status": "UNRESOLVED",
        "migration_authorized": False,
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
    for name in ("owner_cluster", "semantic_cluster", "source_repo", "source_module",
                 "source_file", "source_symbol"):
        if pinned.get(name):
            manifest[name] = pinned[name]
    if "prerequisite_edges" in pinned:
        manifest["prerequisite_edges"] = [dict(edge) for edge in pinned.get("prerequisite_edges") or []]
    manifest["status"] = "SOURCE_LOCATED" if manifest["source_files"] and manifest["required_symbols"] else "PARTIAL"
    evidence = pinned.get("closure_evidence")
    revision = index.get("revision")
    if (manifest["status"] == "SOURCE_LOCATED" and pinned.get("closure_reviewed") is True
            and isinstance(evidence, dict)
            and reviewed_source_set(pinned, index, evidence, contracts, production_evidence, modules)
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
    if manifest.get("prerequisite_edges"):
        for edge in manifest["prerequisite_edges"]:
            validate_prerequisite_edge(edge)
        reject_substrate_bypass(manifest)
        _require_closed_relationships(manifest, index, contracts, production_evidence, modules)
    return manifest
