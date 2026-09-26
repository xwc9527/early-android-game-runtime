import json
import unittest
from pathlib import Path

from source_closure import (component_source_closed, external_edge_closed, prerequisite_relations_allow_closure,
                            source_derived_clusters, strongly_connected_components, unified_substrate_catalog)

ROOT = Path(__file__).resolve().parents[2]
REV = "a" * 40
SHA_A = "a" * 64
SHA_B = "b" * 64
SHA_C = "c" * 64


def _edge(name, cluster, filename, symbol, digest, status="SOURCE_CLOSED"):
    return {"edge": name, "semantic_cluster": cluster, "source_repo": "platform/dalvik",
            "revision": REV, "source_file": filename, "source_symbol": symbol,
            "source_sha256": digest, "status": status}


def _owner(filename, digest, symbols, edges, status="SOURCE_CLOSED", reviewed=True):
    deps = [item["edge"] for item in edges]
    files = {filename: digest}
    owner = {"source_repo": "platform/dalvik", "revision": REV, "source_file_sha256": files,
             "required_symbols": symbols, "cross_cluster_deps": deps,
             "cross_cluster_source_edges": edges, "status": status,
             "closure_reviewed": reviewed, "blocking_edges": []}
    if reviewed and status == "SOURCE_CLOSED":
        owner["closure_evidence"] = {
            "source_file_sha256": dict(files), "reviewed_dependency_edges": list(deps),
            "unresolved_dependency_edges": [], "reviewed_by": "synthetic-review",
            "closure_notes": "local state, init, error, and lifetime reviewed"}
    return owner


def _pair(b_status="SOURCE_CLOSED", b_reviewed=True, extra=None):
    to_b = _edge("a-calls-b", "B", "B.cpp", "b", SHA_B)
    to_a = _edge("b-calls-a", "A", "A.cpp", "a", SHA_A)
    edges_b = [to_a] + list(extra or [])
    owners = {
        "A": _owner("A.cpp", SHA_A, ["a"], [to_b]),
        "B": _owner("B.cpp", SHA_B, ["b"], edges_b, b_status, b_reviewed),
    }
    return owners, _edge("origin-a", "A", "A.cpp", "a", SHA_A)


class SubstrateSccTests(unittest.TestCase):
    def test_mutual_pair_with_local_review_closes_source_scc(self):
        owners, origin = _pair()
        index = {"external_cluster_sources": owners}
        derived = source_derived_clusters(
            [{"dependency_id": "SYNTH:1", "canonical_name": "Origin",
              "cross_cluster_source_edges": [origin]}], index)
        self.assertEqual(derived["A"]["status"], "SOURCE_CLOSED")
        self.assertEqual(derived["B"]["status"], "SOURCE_CLOSED")
        self.assertEqual(owners["A"]["status"], "SOURCE_CLOSED")
        self.assertTrue(external_edge_closed(origin, index))

    def test_mutual_pair_stays_open_when_one_member_is_unreviewed(self):
        owners, origin = _pair(b_status="SOURCE_LOCATED", b_reviewed=False)
        index = {"external_cluster_sources": owners}
        derived = source_derived_clusters(
            [{"dependency_id": "SYNTH:1", "canonical_name": "Origin",
              "cross_cluster_source_edges": [origin]}], index)
        self.assertEqual(derived["A"]["status"], "SOURCE_LOCATED")
        self.assertEqual(derived["B"]["status"], "SOURCE_LOCATED")
        self.assertFalse(component_source_closed(("A", "B"), owners))

    def test_outgoing_unclosed_owner_blocks_scc(self):
        to_c = _edge("b-calls-c", "C", "C.cpp", "c", SHA_C)
        owners, origin = _pair(extra=[to_c])
        owners["C"] = _owner("C.cpp", SHA_C, ["c"], [], status="SOURCE_LOCATED", reviewed=False)
        index = {"external_cluster_sources": owners}
        derived = source_derived_clusters(
            [{"dependency_id": "SYNTH:1", "canonical_name": "Origin",
              "cross_cluster_source_edges": [origin]}], index)
        self.assertEqual(strongly_connected_components(owners), (("A", "B"), ("C",)))
        self.assertEqual(derived["A"]["status"], "SOURCE_LOCATED")
        self.assertEqual(derived["C"]["status"], "SOURCE_LOCATED")

    def test_outgoing_closed_owner_lets_scc_close(self):
        to_c = _edge("b-calls-c", "C", "C.cpp", "c", SHA_C)
        owners, origin = _pair(extra=[to_c])
        owners["C"] = _owner("C.cpp", SHA_C, ["c"], [])
        index = {"external_cluster_sources": owners}
        derived = source_derived_clusters(
            [{"dependency_id": "SYNTH:1", "canonical_name": "Origin",
              "cross_cluster_source_edges": [origin]}], index)
        self.assertEqual(derived["A"]["status"], "SOURCE_CLOSED")
        self.assertEqual(derived["B"]["status"], "SOURCE_CLOSED")
        self.assertEqual(derived["C"]["status"], "SOURCE_CLOSED")

    def test_owners_in_separate_indexes_resolve_through_one_catalog(self):
        monitor = _owner("Sync.cpp", SHA_A, ["dvmLockObject"], [
            _edge("thread wait", "Dalvik.ThreadState", "Thread.cpp", "dvmChangeStatus", SHA_B)])
        thread = _owner("Thread.cpp", SHA_B, ["dvmChangeStatus"], [])
        first = {"external_cluster_sources": {"Dalvik.Monitor": monitor}}
        second = {"external_cluster_sources": {"Dalvik.ThreadState": thread}}
        catalog = unified_substrate_catalog([first, second])
        merged = {"external_cluster_sources": catalog}
        self.assertEqual(set(catalog), {"Dalvik.Monitor", "Dalvik.ThreadState"})
        self.assertTrue(external_edge_closed(monitor["cross_cluster_source_edges"][0], merged))
        self.assertFalse(external_edge_closed(monitor["cross_cluster_source_edges"][0], first))

    def test_conflicting_owner_definitions_fail_closed(self):
        left = {"revision": REV, "source_file_sha256": {"Thread.cpp": SHA_A},
                "required_symbols": ["dvmChangeStatus"], "cross_cluster_source_edges": []}
        right = dict(left, revision="c" * 40)
        unified_substrate_catalog([
            {"external_cluster_sources": {"Dalvik.ThreadState": left}},
            {"external_cluster_sources": {"Dalvik.ThreadState": dict(left)}}])
        with self.assertRaisesRegex(ValueError, "substrate owner definition conflict: Dalvik.ThreadState"):
            unified_substrate_catalog([
                {"external_cluster_sources": {"Dalvik.ThreadState": left}},
                {"external_cluster_sources": {"Dalvik.ThreadState": right}}])

    def test_source_scc_closure_does_not_grant_prerequisite_closed(self):
        to_state = _edge("thread wait", "Dalvik.ThreadState", "Thread.cpp", "dvmChangeStatus", SHA_B)
        to_monitor = _edge("monitor enter", "Dalvik.Monitor", "Sync.cpp", "dvmLockObject", SHA_A)
        owners = {
            "Dalvik.Monitor": _owner("Sync.cpp", SHA_A, ["dvmLockObject"], [to_state]),
            "Dalvik.ThreadState": _owner("Thread.cpp", SHA_B, ["dvmChangeStatus"], [to_monitor]),
        }
        index = {"external_cluster_sources": owners}
        self.assertTrue(component_source_closed(("Dalvik.Monitor", "Dalvik.ThreadState"), owners))
        prerequisite = dict(to_state, relationship="PREREQUISITE_CLOSED", owner_source_status="SOURCE_CLOSED")
        with self.assertRaisesRegex(ValueError, "no production contract authority"):
            prerequisite_relations_allow_closure([prerequisite], [to_state], index)

    def test_cycle_paths_remain_on_a_closed_scc(self):
        owners, origin = _pair()
        derived = source_derived_clusters(
            [{"dependency_id": "SYNTH:1", "canonical_name": "Origin",
              "cross_cluster_source_edges": [origin]}],
            {"external_cluster_sources": owners})
        self.assertEqual(derived["A"]["status"], "SOURCE_CLOSED")
        self.assertEqual(derived["A"]["cycle_paths"], ["Origin -> A -> B -> A"])

    def test_real_substrate_indexes_report_computed_sccs_without_status_change(self):
        integer = json.loads((ROOT / "tools/reference-lab/indexes/integer-boxing-api19-locations.json").read_text(encoding="utf-8"))
        resources = json.loads((ROOT / "tools/reference-lab/indexes/shared-resources-api19-locations.json").read_text(encoding="utf-8"))
        before = {
            name: (owner.get("status"), owner.get("closure_reviewed"),
                   [(edge.get("edge"), edge.get("relationship"))
                    for edge in owner.get("prerequisite_edges") or []])
            for source in (integer, resources)
            for name, owner in source["external_cluster_sources"].items()}
        catalog = unified_substrate_catalog([integer, resources])
        components = strongly_connected_components(catalog)
        multi = [component for component in components if len(component) > 1]
        self.assertEqual(multi, [(
            "Dalvik.BootClassResolution",
            "Dalvik.ClassInitialization",
            "Dalvik.JNINativeBinding",
            "Dalvik.MethodInvocation",
            "Dalvik.ObjectAllocation")])
        self.assertFalse(component_source_closed(multi[0], catalog))
        after = {
            name: (owner.get("status"), owner.get("closure_reviewed"),
                   [(edge.get("edge"), edge.get("relationship"))
                    for edge in owner.get("prerequisite_edges") or []])
            for source in (integer, resources)
            for name, owner in source["external_cluster_sources"].items()}
        self.assertEqual(after, before)


if __name__ == "__main__":
    unittest.main()
