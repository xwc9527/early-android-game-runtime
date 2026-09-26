import json
import unittest
from pathlib import Path

from cluster_seed import build_cluster_seed
from source_closure import (
    SHARED_RUNTIME_SUBSTRATE_OWNERS,
    close_entry,
    closure_work_queue,
    external_edge_closed,
    external_owner_digest,
    source_derived_clusters,
)
from workflow import cluster_manifests, validate_source_manifests

ROOT = Path(__file__).resolve().parents[2]
REV = "c" * 40
BOX = "Box.java"
CLASS_CPP = "vm/oo/Class.cpp"
SYNC_CPP = "vm/Sync.cpp"
ZYGOTE = "ZygoteInit.java"
SHA_BOX = "1" * 64
SHA_CLASS = "2" * 64
SHA_SYNC = "3" * 64
SHA_ZYGOTE = "4" * 64
UPPER = "Lexample/Box;->valueOf(I)Lexample/Box;"
CLUSTER = "libcore.SyntheticBoxing"


def _edge(name, cluster, filename, symbol, digest, status="SOURCE_LOCATED"):
    return {"edge": name, "semantic_cluster": cluster, "source_repo": "platform/dalvik",
            "revision": REV, "source_file": filename, "source_symbol": symbol,
            "source_sha256": digest, "status": status}


def _owner(filename, digest, symbols, deps=None, edges=None, blocking=None, status="SOURCE_LOCATED"):
    owner = {"source_repo": "platform/dalvik", "revision": REV,
             "source_file_sha256": {filename: digest}, "required_symbols": symbols,
             "status": status}
    if deps:
        owner["cross_cluster_deps"] = deps
    if edges:
        owner["cross_cluster_source_edges"] = edges
    if blocking:
        owner["blocking_edges"] = blocking
    return owner


def _prerequisite(relationship, owner_status="SOURCE_CLOSED"):
    return {"edge": "class initialization", "semantic_cluster": "Dalvik.ClassInitialization",
            "relationship": relationship, "owner_source_status": owner_status,
            "source_repo": "platform/dalvik", "revision": REV, "source_file": CLASS_CPP,
            "source_symbol": "dvmInitClass", "source_sha256": SHA_CLASS,
            "owner_source_files": [CLASS_CPP, SYNC_CPP],
            "internal_clusters": ["Dalvik.Monitor", "Dalvik.MethodInvocation",
                                  "Bionic.PthreadCondition", "Bionic.ClockGettime"]}


class SubstratePrerequisiteTest(unittest.TestCase):
    def test_confirmed_substrate_set_is_closed(self):
        self.assertNotIn("Framework.ZygotePreload", SHARED_RUNTIME_SUBSTRATE_OWNERS)
        self.assertNotIn("Framework.ZygoteVMOptions", SHARED_RUNTIME_SUBSTRATE_OWNERS)
        self.assertNotIn("AndroidNative.InitZygote", SHARED_RUNTIME_SUBSTRATE_OWNERS)
        self.assertIn("Dalvik.JNINativeBinding", SHARED_RUNTIME_SUBSTRATE_OWNERS)
        self.assertIn("Bionic.ClockGettime", SHARED_RUNTIME_SUBSTRATE_OWNERS)

    def _expansion_index(self):
        class_edge = _edge("class initialization", "Dalvik.ClassInitialization",
                           CLASS_CPP, "dvmInitClass", SHA_CLASS)
        monitor = _edge("monitor wait", "Dalvik.Monitor", SYNC_CPP, "dvmObjectWait", SHA_SYNC)
        invoke = _edge("method invoke", "Dalvik.MethodInvocation", "vm/interp/Stack.cpp",
                       "dvmCallMethod", "5" * 64)
        pthread = _edge("pthread condition", "Bionic.PthreadCondition",
                        "libc/bionic/pthread.c", "pthread_cond_wait", "6" * 64)
        clock = _edge("clock_gettime", "Bionic.ClockGettime",
                      "libc/arch-arm/syscalls/clock_gettime.S", "clock_gettime", "7" * 64)
        zygote_edge = {"edge": "zygote preload", "semantic_cluster": "Framework.ZygotePreload",
                       "source_repo": "platform/frameworks/base", "revision": REV,
                       "source_file": ZYGOTE, "source_symbol": "preloadClasses",
                       "source_sha256": SHA_ZYGOTE, "status": "SOURCE_LOCATED"}
        return {"revision": REV, "external_cluster_sources": {
            "Framework.ZygotePreload": {
                "source_repo": "platform/frameworks/base", "revision": REV,
                "source_file_sha256": {ZYGOTE: SHA_ZYGOTE},
                "required_symbols": ["preloadClasses"], "status": "SOURCE_LOCATED",
                "blocking_edges": ["preload contract"],
                "cross_cluster_source_edges": [class_edge]},
            "Dalvik.ClassInitialization": _owner(
                CLASS_CPP, SHA_CLASS, ["dvmInitClass"],
                ["monitor wait", "method invoke"], [monitor, invoke], ["class-init wait"]),
            "Dalvik.Monitor": _owner(
                SYNC_CPP, SHA_SYNC, ["dvmObjectWait"], ["pthread condition"], [pthread],
                ["monitor wait"]),
            "Dalvik.MethodInvocation": _owner(
                "vm/interp/Stack.cpp", "5" * 64, ["dvmCallMethod"], blocking=["invoke"]),
            "Bionic.PthreadCondition": _owner(
                "libc/bionic/pthread.c", "6" * 64, ["pthread_cond_wait"],
                ["clock_gettime"], [clock], ["pthread cond"]),
            "Bionic.ClockGettime": _owner(
                "libc/arch-arm/syscalls/clock_gettime.S", "7" * 64, ["clock_gettime"],
                blocking=["clock_gettime"]),
        }}, zygote_edge

    def _expansion_manifest(self, relationship):
        _, zygote_edge = self._expansion_index()
        class_edge = _edge("class initialization", "Dalvik.ClassInitialization",
                           CLASS_CPP, "dvmInitClass", SHA_CLASS)
        return {"dependency_id": "JAVA_METHOD:box", "canonical_name": UPPER,
                "semantic_cluster": CLUSTER, "status": "SOURCE_LOCATED",
                "migration_authorized": False,
                "cross_cluster_source_edges": [zygote_edge, class_edge],
                "prerequisite_edges": [_prerequisite(relationship)]}

    def test_closed_prerequisite_stops_upper_recursion(self):
        index, _ = self._expansion_index()
        manifest = self._expansion_manifest("PREREQUISITE_CLOSED")
        stopped = source_derived_clusters([manifest], index)
        self.assertIn("Framework.ZygotePreload", stopped)
        for name in ("Dalvik.ClassInitialization", "Dalvik.Monitor", "Dalvik.MethodInvocation",
                     "Bionic.PthreadCondition", "Bionic.ClockGettime"):
            self.assertNotIn(name, stopped)
        queue = closure_work_queue([manifest], stopped)
        self.assertTrue(any(item["semantic_cluster"] == "Framework.ZygotePreload" for item in queue))
        self.assertFalse(any(item["blocking_edge"] == "class-init wait" for item in queue))
        self.assertFalse(any(item["blocking_edge"] == "clock_gettime" for item in queue))
        bare = dict(manifest)
        bare.pop("prerequisite_edges")
        walked = source_derived_clusters([bare], index)
        self.assertIn("Dalvik.ClassInitialization", walked)
        self.assertIn("Bionic.ClockGettime", walked)
        self.assertIn("Dalvik.MethodInvocation", walked)
        validate_source_manifests({
            "schema_version": 1, "manifests": [manifest], "source_derived_clusters": stopped,
            "closure_work_queue": queue})

    def test_unresolved_prerequisite_also_stops_recursion(self):
        index, _ = self._expansion_index()
        manifest = self._expansion_manifest("UNRESOLVED")
        manifest["prerequisite_edges"][0]["owner_source_status"] = "SOURCE_LOCATED"
        stopped = source_derived_clusters([manifest], index)
        self.assertIn("Framework.ZygotePreload", stopped)
        self.assertNotIn("Bionic.PthreadCondition", stopped)
        self.assertNotIn("Dalvik.ClassInitialization", stopped)

    def test_prerequisite_pin_must_match_owner(self):
        index, _ = self._expansion_index()
        manifest = self._expansion_manifest("PREREQUISITE_CLOSED")
        manifest["cross_cluster_source_edges"][1]["source_sha256"] = "9" * 64
        with self.assertRaisesRegex(ValueError, "differs from pinned owner"):
            source_derived_clusters([manifest], index)

    def _closed_substrate_index(self, relationship="PREREQUISITE_CLOSED"):
        monitor_edge = _edge("monitor wait", "Dalvik.Monitor", SYNC_CPP, "dvmObjectWait",
                             SHA_SYNC, "SOURCE_CLOSED")
        monitor = _owner(SYNC_CPP, SHA_SYNC, ["dvmObjectWait"], status="SOURCE_CLOSED")
        monitor.update(blocking_edges=[], closure_reviewed=True, closure_evidence={
            "reviewed_by": "source-audit", "closure_notes": "Monitor closed inside the substrate owner",
            "source_file_sha256": {SYNC_CPP: SHA_SYNC}, "reviewed_dependency_edges": [],
            "unresolved_dependency_edges": []})
        owner = _owner(CLASS_CPP, SHA_CLASS, ["dvmInitClass"], ["monitor wait"],
                       [monitor_edge], status="SOURCE_CLOSED")
        owner.update(blocking_edges=[], closure_reviewed=True, closure_evidence={
            "reviewed_by": "source-audit",
            "closure_notes": "Class initialization closed inside the substrate owner",
            "source_file_sha256": {CLASS_CPP: SHA_CLASS},
            "reviewed_dependency_edges": ["monitor wait"], "unresolved_dependency_edges": []})
        cross = _edge("class initialization", "Dalvik.ClassInitialization", CLASS_CPP,
                      "dvmInitClass", SHA_CLASS, "SOURCE_CLOSED")
        prereq = _prerequisite(relationship)
        pinned = {"owner_cluster": "libcore", "semantic_cluster": CLUSTER,
                  "source_repo": "platform/libcore", "source_file": BOX, "source_symbol": "valueOf",
                  "source_files": [BOX], "required_symbols": ["valueOf"],
                  "cross_cluster_deps": ["class initialization"],
                  "cross_cluster_source_edges": [cross], "prerequisite_edges": [prereq],
                  "blocking_edges": [], "closure_reviewed": True,
                  "closure_evidence": {
                      "source_sha256": SHA_BOX, "reviewed_by": "source-audit",
                      "closure_notes": "Upper boxing owner reviewed; substrate stays a prerequisite",
                      "edge_reviews": {"class initialization": {
                          "disposition": "SOURCE_CLOSED_EXTERNAL",
                          "semantic_cluster": "Dalvik.ClassInitialization",
                          "source_repo": "platform/dalvik", "revision": REV,
                          "source_file": CLASS_CPP, "source_symbol": "dvmInitClass",
                          "source_manifest_sha256": external_owner_digest(owner)}}}}
        index = {"revision": REV, "source_sha256": SHA_BOX,
                 "source_file_sha256": {BOX: SHA_BOX},
                 "external_cluster_sources": {"Dalvik.ClassInitialization": owner,
                                              "Dalvik.Monitor": monitor},
                 "entries": {UPPER: pinned}}
        return index

    def _document(self, index, review=True):
        if review:
            index = json.loads(json.dumps(index))
            index["cluster_reviews"] = {CLUSTER: {
                "closure_reviewed": True, "source_revision": REV, "entry_names": [UPPER],
                "source_file_sha256": {BOX: SHA_BOX},
                "reviewed_dependency_edges": ["class initialization"],
                "unresolved_dependency_edges": [], "reviewed_by": "source-audit",
                "closure_notes": "Upper cluster reviewed without absorbing substrate internals"}}
        entry = {"dependency_id": "JAVA_METHOD:box", "canonical_name": UPPER}
        manifest = close_entry(entry, index)
        derived = source_derived_clusters([manifest], index)
        clusters = cluster_manifests([manifest], index)
        document = {"schema_version": 1, "source_index_revision": REV, "manifests": [manifest],
                    "cluster_source_manifests": clusters, "source_derived_clusters": derived,
                    "closure_work_queue": closure_work_queue([manifest], derived)}
        return manifest, clusters, derived, document

    def test_closed_prerequisite_satisfies_one_edge_without_lowering_authorization(self):
        index = self._closed_substrate_index()
        self.assertTrue(external_edge_closed(
            index["entries"][UPPER]["cross_cluster_source_edges"][0], index))
        manifest, clusters, derived, _ = self._document(index, review=False)
        self.assertEqual(manifest["status"], "SOURCE_CLOSED")
        self.assertFalse(manifest["migration_authorized"])
        self.assertEqual(derived, {})
        self.assertEqual(clusters[CLUSTER]["status"], "SOURCE_CLOSED")
        self.assertFalse(clusters[CLUSTER]["migration_authorized"])
        index["source_sha256"] = "8" * 64
        self.assertEqual(close_entry(
            {"dependency_id": "JAVA_METHOD:box", "canonical_name": UPPER}, index)["status"],
            "SOURCE_LOCATED")
        index["source_sha256"] = SHA_BOX
        _, authorized_clusters, _, document = self._document(index, review=True)
        self.assertEqual(authorized_clusters[CLUSTER]["status"], "MIGRATION_AUTHORIZED")
        self.assertTrue(authorized_clusters[CLUSTER]["migration_authorized"])
        validate_source_manifests(document)
        incomplete = json.loads(json.dumps(index))
        incomplete["cluster_reviews"] = {CLUSTER: {
            "closure_reviewed": True, "source_revision": REV, "entry_names": [UPPER],
            "source_file_sha256": {BOX: SHA_BOX}, "reviewed_dependency_edges": [],
            "unresolved_dependency_edges": [], "reviewed_by": "source-audit",
            "closure_notes": "Upper review omitted the prerequisite edge"}}
        incomplete_clusters = cluster_manifests(
            [close_entry({"dependency_id": "JAVA_METHOD:box", "canonical_name": UPPER}, incomplete)],
            incomplete)
        self.assertEqual(incomplete_clusters[CLUSTER]["status"], "SOURCE_CLOSED")
        self.assertFalse(incomplete_clusters[CLUSTER]["migration_authorized"])

    def test_unresolved_and_reopen_block_upper_closure_and_authorization(self):
        _, _, _, closed = self._document(self._closed_substrate_index(), review=True)
        for relationship in ("UNRESOLVED", "REOPEN_REQUIRED"):
            index = self._closed_substrate_index(relationship)
            manifest = close_entry({"dependency_id": "JAVA_METHOD:box", "canonical_name": UPPER}, index)
            self.assertEqual(manifest["status"], "SOURCE_LOCATED")
            self.assertFalse(manifest["migration_authorized"])
            self.assertEqual(manifest["prerequisite_edges"][0]["owner_source_status"], "SOURCE_CLOSED")
            clusters = cluster_manifests([manifest], index)
            self.assertEqual(clusters[CLUSTER]["status"], "SOURCE_LOCATED")
            self.assertFalse(clusters[CLUSTER]["migration_authorized"])
            forged = json.loads(json.dumps(closed))
            for item in (forged["manifests"][0], forged["cluster_source_manifests"][CLUSTER]):
                item["prerequisite_edges"][0]["relationship"] = relationship
                item["prerequisite_edges"][0]["owner_source_status"] = "SOURCE_CLOSED"
            with self.assertRaisesRegex(ValueError, "blocks upper closure"):
                validate_source_manifests(forged)

    def test_closed_upper_cluster_cannot_absorb_substrate_without_relationship(self):
        _, _, _, document = self._document(self._closed_substrate_index(), review=True)
        forged = json.loads(json.dumps(document))
        forged["manifests"][0].pop("prerequisite_edges")
        forged["cluster_source_manifests"][CLUSTER].pop("prerequisite_edges")
        with self.assertRaisesRegex(ValueError, "requires a prerequisite relationship"):
            validate_source_manifests(forged)
        absorbed = json.loads(json.dumps(document))
        absorbed["source_derived_clusters"] = {"Dalvik.Monitor": {"semantic_cluster": "Dalvik.Monitor"}}
        with self.assertRaisesRegex(ValueError, "absorbed shared substrate internals"):
            validate_source_manifests(absorbed)

    def test_private_file_hle_and_game_patch_cannot_bypass(self):
        prereq = _prerequisite("UNRESOLVED", "SOURCE_LOCATED")
        private = {"schema_version": 1, "manifests": [{
            "status": "SOURCE_LOCATED", "migration_authorized": False, "migration_type": "SOURCE_PORT",
            "source_files": [BOX, CLASS_CPP], "prerequisite_edges": [prereq]}],
            "source_derived_clusters": {}}
        with self.assertRaisesRegex(ValueError, "private source file"):
            validate_source_manifests(private)
        hle = json.loads(json.dumps(private))
        hle["manifests"][0]["source_files"] = [BOX]
        hle["manifests"][0]["migration_type"] = "SERVICE_HLE"
        with self.assertRaisesRegex(ValueError, "cannot bypass"):
            validate_source_manifests(hle)
        boundary = json.loads(json.dumps(hle))
        boundary["manifests"][0]["migration_type"] = "SOURCE_PORT"
        boundary["manifests"][0]["closure_evidence"] = {"edge_reviews": {"class initialization": {
            "disposition": "EXCLUDED_BOUNDARY", "semantic_cluster": "Dalvik.ClassInitialization"}}}
        with self.assertRaisesRegex(ValueError, "HLE boundary"):
            validate_source_manifests(boundary)
        game_patch = json.loads(json.dumps(private))
        game_patch["manifests"][0]["source_files"] = [BOX]
        game_patch["manifests"][0]["migration_type"] = "GAME_PATCH"
        with self.assertRaisesRegex(ValueError, "cannot bypass"):
            validate_source_manifests(game_patch)
        index = {"revision": REV, "entries": {UPPER: {
            "source_files": [BOX, CLASS_CPP], "required_symbols": ["valueOf"],
            "prerequisite_edges": [prereq]}}}
        with self.assertRaisesRegex(ValueError, "private source file"):
            close_entry({"dependency_id": "JAVA_METHOD:box", "canonical_name": UPPER}, index)
        with self.assertRaisesRegex(ValueError, "forbidden migration type"):
            close_entry({"dependency_id": "JAVA_METHOD:box", "canonical_name": UPPER},
                        index, "GAME_PATCH")
        hle_index = {"revision": REV, "entries": {UPPER: {
            "source_files": [BOX], "required_symbols": ["valueOf"], "migration_type": "SERVICE_HLE",
            "prerequisite_edges": [prereq]}}}
        with self.assertRaisesRegex(ValueError, "cannot bypass"):
            close_entry({"dependency_id": "JAVA_METHOD:box", "canonical_name": UPPER}, hle_index)

    def test_relationship_is_not_an_owner_status_and_new_owners_are_rejected(self):
        prereq = _prerequisite("PREREQUISITE_CLOSED")
        prereq["status"] = "SOURCE_CLOSED"
        with self.assertRaisesRegex(ValueError, "must not use owner source status"):
            validate_source_manifests({"schema_version": 1, "manifests": [{
                "status": "SOURCE_LOCATED", "prerequisite_edges": [prereq]}],
                "source_derived_clusters": {}})
        foreign = _prerequisite("UNRESOLVED", "SOURCE_LOCATED")
        foreign["semantic_cluster"] = "Framework.ZygotePreload"
        with self.assertRaisesRegex(ValueError, "not confirmed"):
            validate_source_manifests({"schema_version": 1, "manifests": [{
                "status": "SOURCE_LOCATED", "prerequisite_edges": [foreign]}],
                "source_derived_clusters": {}})
        open_owner = _prerequisite("PREREQUISITE_CLOSED", "SOURCE_LOCATED")
        with self.assertRaisesRegex(ValueError, "closed substrate owner"):
            validate_source_manifests({"schema_version": 1, "manifests": [{
                "status": "SOURCE_LOCATED", "prerequisite_edges": [open_owner]}],
                "source_derived_clusters": {}})

    def test_real_integer_and_resources_artifacts_stay_unclassified(self):
        evidence = ROOT / "tools/reference-lab/evidence"
        corpus = json.loads((evidence / "four-game-corpus-manifest.json").read_text())
        integer_index = json.loads((ROOT / "tools/reference-lab/indexes/integer-boxing-api19-locations.json").read_text())
        resource_index = json.loads((ROOT / "tools/reference-lab/indexes/shared-resources-api19-locations.json").read_text())
        integer = json.loads((evidence / "integer-boxing-source-seed.json").read_text())
        resources = json.loads((evidence / "shared-resource-source-seed.json").read_text())
        self.assertEqual(build_cluster_seed(corpus, integer_index, "libcore.IntegerBoxing"), integer)
        self.assertEqual(build_cluster_seed(corpus, resource_index, "Framework.Resources"), resources)
        for artifact, count, cluster in (
                (integer, 14, "libcore.IntegerBoxing"),
                (resources, 16, "Framework.Resources")):
            self.assertEqual(artifact["cluster_source_manifests"][cluster]["status"], "SOURCE_LOCATED")
            self.assertFalse(artifact["cluster_source_manifests"][cluster]["migration_authorized"])
            self.assertEqual(len(artifact["source_derived_clusters"]), count)
            encoded = json.dumps(artifact)
            self.assertNotIn("prerequisite_edges", encoded)
            self.assertNotIn("PREREQUISITE_CLOSED", encoded)
            self.assertNotIn("REOPEN_REQUIRED", encoded)


if __name__ == "__main__":
    unittest.main()
