import json
import subprocess
import unittest
from pathlib import Path

from cluster_seed import build_cluster_seed
from source_closure import (
    CROSSING_FIELDS,
    SHARED_RUNTIME_SUBSTRATE_OWNERS,
    close_entry,
    closure_work_queue,
    external_edge_closed,
    external_owner_digest,
    source_derived_clusters,
)
from substrate_contracts import require_production_contract
from workflow import cluster_manifests, validate_source_manifests

PHASE3_RUN = "36039287996"
PHASE3_COMMIT = "851a025a14a75429c975da43853269f9d98ed8ef"
PHASE3_TREE = "9ece3c2b0f1bea5d8275bde75f13d91b5b3e63d6"

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


def _relation(edge, relationship, owner_status, internals=None):
    relation = {field: edge[field] for field in CROSSING_FIELDS}
    relation["relationship"] = relationship
    relation["owner_source_status"] = owner_status
    if internals is not None:
        relation["internal_clusters"] = list(internals)
    return relation


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

    def test_forged_closed_prerequisite_without_source_closure_is_rejected(self):
        index, _ = self._expansion_index()
        manifest = self._expansion_manifest("PREREQUISITE_CLOSED")
        with self.assertRaisesRegex(ValueError, "source owner is not closed"):
            source_derived_clusters([manifest], index)
        with self.assertRaisesRegex(ValueError, "source owner is not closed"):
            validate_source_manifests({
                "schema_version": 1, "manifests": [manifest], "source_derived_clusters": {},
                "closure_work_queue": []}, index)

    def test_unresolved_prerequisite_also_stops_recursion(self):
        index, _ = self._expansion_index()
        manifest = self._expansion_manifest("UNRESOLVED")
        manifest["prerequisite_edges"][0]["owner_source_status"] = "SOURCE_LOCATED"
        stopped = source_derived_clusters([manifest], index)
        self.assertIn("Framework.ZygotePreload", stopped)
        direct = manifest["canonical_name"] + " -> Dalvik.ClassInitialization"
        nested = manifest["canonical_name"] + " -> Framework.ZygotePreload -> Dalvik.ClassInitialization"
        self.assertNotIn(direct, stopped["Dalvik.ClassInitialization"]["source_paths"])
        self.assertIn(nested, stopped["Dalvik.ClassInitialization"]["source_paths"])
        self.assertIn("Bionic.PthreadCondition", stopped)
        queue = closure_work_queue([manifest], stopped)
        blockers = [item for item in queue if item.get("scope") == "PREREQUISITE"]
        self.assertEqual(blockers, [{
            "scope": "PREREQUISITE", "semantic_cluster": "Dalvik.ClassInitialization",
            "blocking_edge": "class initialization", "relationship": "UNRESOLVED",
            "origin_dependency_ids": [manifest["dependency_id"]],
            "source_paths": [manifest["canonical_name"]]}])
        validate_source_manifests({
            "schema_version": 1, "manifests": [manifest], "source_derived_clusters": stopped,
            "closure_work_queue": queue})

    def test_reopen_prerequisite_stays_in_the_work_queue(self):
        index, _ = self._expansion_index()
        manifest = self._expansion_manifest("REOPEN_REQUIRED")
        stopped = source_derived_clusters([manifest], index)
        direct = manifest["canonical_name"] + " -> Dalvik.ClassInitialization"
        nested = manifest["canonical_name"] + " -> Framework.ZygotePreload -> Dalvik.ClassInitialization"
        self.assertNotIn(direct, stopped["Dalvik.ClassInitialization"]["source_paths"])
        self.assertIn(nested, stopped["Dalvik.ClassInitialization"]["source_paths"])
        queue = closure_work_queue([manifest], stopped)
        self.assertTrue(any(item.get("scope") == "PREREQUISITE" and
                            item["relationship"] == "REOPEN_REQUIRED" and
                            item["blocking_edge"] == "class initialization" and
                            item["origin_dependency_ids"] == [manifest["dependency_id"]]
                            for item in queue))
        self.assertFalse(any(item.get("relationship") == "PREREQUISITE_CLOSED" for item in queue))
        validate_source_manifests({
            "schema_version": 1, "manifests": [manifest], "source_derived_clusters": stopped,
            "closure_work_queue": queue})

    def test_only_the_declaring_origin_stops_at_its_exact_edge(self):
        index, _ = self._expansion_index()
        stopped = self._expansion_manifest("UNRESOLVED")
        stopped["prerequisite_edges"][0]["owner_source_status"] = "SOURCE_LOCATED"
        stopped["dependency_id"] = "JAVA_METHOD:stopped"
        stopped["canonical_name"] = "Lexample/Stopped;->valueOf()V"
        stopped["semantic_cluster"] = "libcore.Stopped"
        expanded = self._expansion_manifest("UNRESOLVED")
        expanded["prerequisite_edges"][0]["owner_source_status"] = "SOURCE_LOCATED"
        expanded.pop("prerequisite_edges")
        expanded["dependency_id"] = "JAVA_METHOD:expanded"
        expanded["canonical_name"] = "Lexample/Expanded;->valueOf()V"
        expanded["semantic_cluster"] = "libcore.Expanded"
        derived = source_derived_clusters([stopped, expanded], index)
        class_paths = derived["Dalvik.ClassInitialization"]["source_paths"]
        self.assertIn("JAVA_METHOD:expanded", derived["Dalvik.ClassInitialization"]["origin_dependency_ids"])
        self.assertIn("JAVA_METHOD:stopped", derived["Dalvik.ClassInitialization"]["origin_dependency_ids"])
        self.assertNotIn("Lexample/Stopped;->valueOf()V -> Dalvik.ClassInitialization", class_paths)
        self.assertIn("Lexample/Stopped;->valueOf()V -> Framework.ZygotePreload -> Dalvik.ClassInitialization",
                      class_paths)
        self.assertIn("Lexample/Expanded;->valueOf()V -> Dalvik.ClassInitialization", class_paths)
        self.assertIn("JAVA_METHOD:expanded", derived["Bionic.ClockGettime"]["origin_dependency_ids"])
        self.assertIn("JAVA_METHOD:stopped", derived["Dalvik.Monitor"]["origin_dependency_ids"])
        self.assertTrue(any(path.startswith("Lexample/Expanded;->valueOf()V")
                            for path in derived["Dalvik.MethodInvocation"]["source_paths"]))
        self.assertTrue(any(path.startswith("Lexample/Stopped;->valueOf()V")
                            for path in derived["Framework.ZygotePreload"]["source_paths"]))
        queue = closure_work_queue([stopped, expanded], derived)
        self.assertTrue(any(item.get("scope") == "PREREQUISITE" and
                            item["origin_dependency_ids"] == ["JAVA_METHOD:stopped"]
                            for item in queue))
        self.assertFalse(any(item.get("scope") == "PREREQUISITE" and
                             "JAVA_METHOD:expanded" in item["origin_dependency_ids"]
                             for item in queue))
        validate_source_manifests({
            "schema_version": 1, "manifests": [stopped, expanded],
            "source_derived_clusters": derived, "closure_work_queue": queue})
        index["external_cluster_sources"]["Dalvik.ClassInitialization"]["required_symbols"].append(
            "initSFields")
        other = _edge("late class init", "Dalvik.ClassInitialization", CLASS_CPP,
                      "initSFields", SHA_CLASS)
        same = self._expansion_manifest("UNRESOLVED")
        same["prerequisite_edges"][0]["owner_source_status"] = "SOURCE_LOCATED"
        same["cross_cluster_source_edges"].append(other)
        walked = source_derived_clusters([same], index)
        self.assertIn(same["dependency_id"], walked["Dalvik.ClassInitialization"]["origin_dependency_ids"])
        self.assertIn(same["dependency_id"], walked["Bionic.PthreadCondition"]["origin_dependency_ids"])

    def test_prerequisite_must_match_the_crossing_edge(self):
        manifest = self._expansion_manifest("UNRESOLVED")
        manifest["prerequisite_edges"][0]["owner_source_status"] = "SOURCE_LOCATED"
        manifest["prerequisite_edges"][0]["source_sha256"] = "9" * 64
        stopped = source_derived_clusters([manifest], self._expansion_index()[0])
        with self.assertRaisesRegex(ValueError, "does not match a crossing source edge"):
            validate_source_manifests({
                "schema_version": 1, "manifests": [manifest], "source_derived_clusters": stopped,
                "closure_work_queue": closure_work_queue([manifest], stopped)})
        invented = self._expansion_manifest("REOPEN_REQUIRED")
        invented["prerequisite_edges"][0]["semantic_cluster"] = "Dalvik.MethodInvocation"
        invented["prerequisite_edges"][0]["source_symbol"] = "dvmCallMethod"
        with self.assertRaisesRegex(ValueError, "does not match a crossing source edge"):
            validate_source_manifests({
                "schema_version": 1, "manifests": [invented], "source_derived_clusters": {},
                "closure_work_queue": []})

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

    def _contract(self, index, cluster="Dalvik.ClassInitialization", **overrides):
        owner = index["external_cluster_sources"][cluster]
        contract = {"semantic_cluster": cluster, "status": "PRODUCTION_CLOSED",
                    "source_revision": owner["revision"],
                    "source_owner_digest": external_owner_digest(owner),
                    "production_module": "SyntheticSubstrate",
                    "tested_commit": PHASE3_COMMIT, "tested_tree": PHASE3_TREE,
                    "closure_run": PHASE3_RUN}
        contract.update(overrides)
        return {"schema_version": 1, "contracts": [contract]}, ["SyntheticSubstrate"]

    def _closed_manifest(self, index):
        pinned = index["entries"][UPPER]
        return {"dependency_id": "JAVA_METHOD:box", "canonical_name": UPPER,
                "semantic_cluster": CLUSTER, "status": "SOURCE_LOCATED",
                "migration_authorized": False,
                "cross_cluster_source_edges": pinned["cross_cluster_source_edges"],
                "prerequisite_edges": pinned["prerequisite_edges"]}

    def test_prerequisite_closed_stays_rejected_without_clean_producer(self):
        index = self._closed_substrate_index()
        self.assertTrue(external_edge_closed(
            index["entries"][UPPER]["cross_cluster_source_edges"][0], index))
        entry = {"dependency_id": "JAVA_METHOD:box", "canonical_name": UPPER}
        contracts, modules = self._contract(index)
        handwritten = json.loads(json.dumps(contracts))
        handwritten["contracts"][0]["clean_differential"] = "synthetic/clean.json"
        evidence = {"synthetic/clean.json": {
            "kind": "API19_CLEAN_DIFFERENTIAL", "result": "NO_DIVERGENCE",
            "semantic_cluster": "Dalvik.ClassInitialization",
            "tested_commit": PHASE3_COMMIT, "tested_tree": PHASE3_TREE,
            "source_revision": REV,
            "source_owner_digest": contracts["contracts"][0]["source_owner_digest"]}}
        for bound in (contracts, handwritten):
            with self.assertRaisesRegex(ValueError, "no API19 CLEAN differential authority"):
                close_entry(entry, index, contracts=bound, production_evidence=evidence, modules=modules)
        manifest = self._closed_manifest(index)
        with self.assertRaisesRegex(ValueError, "no API19 CLEAN differential authority"):
            source_derived_clusters([manifest], index, contracts, evidence, modules)
        with self.assertRaisesRegex(ValueError, "no API19 CLEAN differential authority"):
            closure_work_queue([manifest], {}, index, contracts, evidence, modules)
        claimed = {"schema_version": 1, "manifests": [manifest], "source_derived_clusters": {},
                   "closure_work_queue": []}
        claimed["manifests"][0]["status"] = "SOURCE_CLOSED"
        with self.assertRaisesRegex(ValueError, "no API19 CLEAN differential authority"):
            validate_source_manifests(claimed, index, contracts, evidence, modules)

    def test_unresolved_and_reopen_block_upper_closure_and_authorization(self):
        for relationship in ("UNRESOLVED", "REOPEN_REQUIRED"):
            index = self._closed_substrate_index(relationship)
            manifest = close_entry({"dependency_id": "JAVA_METHOD:box", "canonical_name": UPPER}, index)
            self.assertEqual(manifest["status"], "SOURCE_LOCATED")
            self.assertFalse(manifest["migration_authorized"])
            self.assertEqual(manifest["prerequisite_edges"][0]["owner_source_status"], "SOURCE_CLOSED")
            clusters = cluster_manifests([manifest], index)
            self.assertEqual(clusters[CLUSTER]["status"], "SOURCE_LOCATED")
            self.assertFalse(clusters[CLUSTER]["migration_authorized"])
            forged = {"schema_version": 1, "manifests": [json.loads(json.dumps(manifest))],
                      "source_derived_clusters": {}, "closure_work_queue": []}
            forged["manifests"][0]["status"] = "SOURCE_CLOSED"
            with self.assertRaisesRegex(ValueError, "blocks upper closure"):
                validate_source_manifests(forged, index)

    def test_closed_upper_cluster_cannot_absorb_substrate_without_relationship(self):
        index = self._closed_substrate_index()
        document = {"schema_version": 1, "manifests": [{
            "status": "SOURCE_CLOSED", "dependency_id": "JAVA_METHOD:box",
            "canonical_name": UPPER, "semantic_cluster": CLUSTER,
            "cross_cluster_source_edges": index["entries"][UPPER]["cross_cluster_source_edges"]}],
            "source_derived_clusters": {}, "closure_work_queue": []}
        with self.assertRaisesRegex(ValueError, "requires a prerequisite relationship"):
            validate_source_manifests(document, index)
        claimed = json.loads(json.dumps(document))
        claimed["manifests"][0]["prerequisite_edges"] = index["entries"][UPPER]["prerequisite_edges"]
        claimed["source_derived_clusters"] = {"Dalvik.Monitor": {
            "semantic_cluster": "Dalvik.Monitor",
            "origin_dependency_ids": ["JAVA_METHOD:box"],
            "source_paths": [UPPER + " -> Dalvik.ClassInitialization -> Dalvik.Monitor"]}}
        contracts, modules = self._contract(index)
        with self.assertRaisesRegex(ValueError, "no API19 CLEAN differential authority"):
            validate_source_manifests(claimed, index, contracts, modules=modules)

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

    def _zygote_owner_index(self, relationship, owner_status):
        index, zygote_edge = self._expansion_index()
        zygote = index["external_cluster_sources"]["Framework.ZygotePreload"]
        class_edge = zygote["cross_cluster_source_edges"][0]
        boot_edge = _edge("boot class loading", "Libcore.BootClassLoading",
                          "java/lang/Class.java", "forName", "a" * 64)
        boot_edge["source_repo"] = "platform/libcore"
        resolve_edge = _edge("boot class resolution", "Dalvik.BootClassResolution",
                             CLASS_CPP, "dvmFindClass", "b" * 64)
        zygote["cross_cluster_source_edges"] = [class_edge, boot_edge]
        zygote["prerequisite_edges"] = [
            _relation(class_edge, relationship, owner_status, [
                "Dalvik.Monitor", "Dalvik.MethodInvocation",
                "Bionic.PthreadCondition", "Bionic.ClockGettime"]),
            _relation(boot_edge, relationship, owner_status, ["Dalvik.BootClassResolution"]),
        ]
        index["external_cluster_sources"]["Libcore.BootClassLoading"] = {
            "source_repo": "platform/libcore", "revision": REV,
            "source_file_sha256": {"java/lang/Class.java": "a" * 64},
            "required_symbols": ["forName"], "status": "SOURCE_LOCATED",
            "blocking_edges": ["boot class"],
            "cross_cluster_source_edges": [resolve_edge]}
        index["external_cluster_sources"]["Dalvik.BootClassResolution"] = _owner(
            CLASS_CPP, "b" * 64, ["dvmFindClass"], blocking=["boot resolution"])
        other_edge = {"edge": "other host", "semantic_cluster": "Framework.OtherHost",
                      "source_repo": "platform/frameworks/base", "revision": REV,
                      "source_file": "Other.java", "source_symbol": "preload",
                      "source_sha256": "c" * 64, "status": "SOURCE_LOCATED"}
        index["external_cluster_sources"]["Framework.OtherHost"] = {
            "source_repo": "platform/frameworks/base", "revision": REV,
            "source_file_sha256": {"Other.java": "c" * 64},
            "required_symbols": ["preload"], "status": "SOURCE_LOCATED",
            "cross_cluster_source_edges": [dict(class_edge)]}
        second = "Lexample/Second;->valueOf()V"
        other = "Lexample/Other;->valueOf()V"
        manifests = [
            {"dependency_id": "JAVA_METHOD:box", "canonical_name": UPPER,
             "semantic_cluster": CLUSTER, "status": "SOURCE_LOCATED",
             "migration_authorized": False, "cross_cluster_source_edges": [zygote_edge]},
            {"dependency_id": "JAVA_METHOD:second", "canonical_name": second,
             "semantic_cluster": "libcore.Second", "status": "SOURCE_LOCATED",
             "migration_authorized": False, "cross_cluster_source_edges": [zygote_edge]},
            {"dependency_id": "JAVA_METHOD:other", "canonical_name": other,
             "semantic_cluster": "libcore.Other", "status": "SOURCE_LOCATED",
             "migration_authorized": False, "cross_cluster_source_edges": [other_edge]},
        ]
        return index, manifests, second

    def test_derived_owner_prerequisite_stops_only_its_own_crossings(self):
        cases = (("UNRESOLVED", "SOURCE_LOCATED"),
                 ("REOPEN_REQUIRED", "SOURCE_LOCATED"))
        for relationship, owner_status in cases:
            index, manifests, second = self._zygote_owner_index(relationship, owner_status)
            derived = source_derived_clusters(manifests, index)
            zygote = derived["Framework.ZygotePreload"]
            self.assertEqual(zygote["origin_dependency_ids"],
                             ["JAVA_METHOD:box", "JAVA_METHOD:second"])
            self.assertEqual(zygote["source_paths"], [
                UPPER + " -> Framework.ZygotePreload",
                second + " -> Framework.ZygotePreload"])
            walked = " ".join(path for row in derived.values() for path in row["source_paths"])
            self.assertNotIn("Framework.ZygotePreload -> Dalvik.ClassInitialization", walked)
            self.assertNotIn("Framework.ZygotePreload -> Libcore.BootClassLoading", walked)
            self.assertNotIn("Libcore.BootClassLoading", derived)
            self.assertNotIn("Dalvik.BootClassResolution", derived)
            self.assertEqual(derived["Dalvik.ClassInitialization"]["origin_dependency_ids"],
                             ["JAVA_METHOD:other"])
            self.assertTrue(all("Framework.OtherHost -> Dalvik.ClassInitialization" in path
                                for path in derived["Dalvik.ClassInitialization"]["source_paths"]))
            self.assertNotIn("JAVA_METHOD:box", derived["Dalvik.Monitor"]["origin_dependency_ids"])
            self.assertNotIn("JAVA_METHOD:second", derived["Bionic.ClockGettime"]["origin_dependency_ids"])
            queue = closure_work_queue(manifests, derived)
            blockers = [item for item in queue if item.get("scope") == "PREREQUISITE"]
            self.assertEqual(blockers, [
                {"scope": "PREREQUISITE", "semantic_cluster": "Dalvik.ClassInitialization",
                 "blocking_edge": "class initialization", "relationship": relationship,
                 "origin_dependency_ids": list(zygote["origin_dependency_ids"]),
                 "source_paths": list(zygote["source_paths"])},
                {"scope": "PREREQUISITE", "semantic_cluster": "Libcore.BootClassLoading",
                 "blocking_edge": "boot class loading", "relationship": relationship,
                 "origin_dependency_ids": list(zygote["origin_dependency_ids"]),
                 "source_paths": list(zygote["source_paths"])}])
            document = {"schema_version": 1, "manifests": manifests,
                        "source_derived_clusters": derived, "closure_work_queue": queue}
            validate_source_manifests(document)
            blocked = json.loads(json.dumps(document))
            blocked["manifests"][0]["status"] = "SOURCE_CLOSED"
            with self.assertRaisesRegex(ValueError, "blocks upper closure"):
                validate_source_manifests(blocked)
            other_closed = json.loads(json.dumps(document))
            other_closed["manifests"][2]["status"] = "SOURCE_CLOSED"
            with self.assertRaises(ValueError) as caught:
                validate_source_manifests(other_closed)
            self.assertNotIn("blocks upper closure", str(caught.exception))
        forged_index, forged_manifests, _ = self._zygote_owner_index("PREREQUISITE_CLOSED", "SOURCE_CLOSED")
        with self.assertRaisesRegex(ValueError, "source owner is not closed"):
            source_derived_clusters(forged_manifests, forged_index)
        index, manifests, _ = self._zygote_owner_index("UNRESOLVED", "SOURCE_LOCATED")
        index["external_cluster_sources"]["Framework.ZygotePreload"]["prerequisite_edges"][0][
            "source_sha256"] = "9" * 64
        with self.assertRaisesRegex(ValueError, "does not match a crossing source edge"):
            source_derived_clusters(manifests, index)
        reopen_index, reopen_manifests, _ = self._zygote_owner_index(
            "REOPEN_REQUIRED", "SOURCE_LOCATED")
        derived = source_derived_clusters(reopen_manifests, reopen_index)
        derived["Dalvik.ClassInitialization"]["source_paths"].append(
            UPPER + " -> Framework.ZygotePreload -> Dalvik.ClassInitialization")
        with self.assertRaisesRegex(ValueError, "absorbed shared substrate internals"):
            validate_source_manifests({
                "schema_version": 1, "manifests": reopen_manifests,
                "source_derived_clusters": derived, "closure_work_queue": []})

    def test_source_closed_owner_without_production_authority_is_rejected(self):
        index = self._closed_substrate_index()
        self.assertTrue(external_edge_closed(
            index["entries"][UPPER]["cross_cluster_source_edges"][0], index))
        with self.assertRaisesRegex(ValueError, "no production contract authority"):
            close_entry({"dependency_id": "JAVA_METHOD:box", "canonical_name": UPPER}, index)
        manifest = self._expansion_manifest("PREREQUISITE_CLOSED")
        with self.assertRaisesRegex(ValueError, "source owner is not closed"):
            closure_work_queue([manifest], {})

    def test_production_contract_missing_binding_is_rejected(self):
        index = self._closed_substrate_index()
        contracts, modules = self._contract(index)
        entry = {"dependency_id": "JAVA_METHOD:box", "canonical_name": UPPER}
        for key, message in (
                ("source_owner_digest", "lacks source owner digest"),
                ("tested_commit", "lacks tested commit"),
                ("tested_tree", "lacks tested tree"),
                ("closure_run", "lacks closure run")):
            broken = json.loads(json.dumps(contracts))
            broken["contracts"][0].pop(key)
            with self.assertRaisesRegex(ValueError, message):
                close_entry(entry, index, contracts=broken, modules=modules)
        unbound = json.loads(json.dumps(contracts))
        unbound["contracts"][0]["source_owner_digest"] = "f" * 64
        with self.assertRaisesRegex(ValueError, "does not bind the source owner"):
            close_entry(entry, index, contracts=unbound, modules=modules)
        unknown = json.loads(json.dumps(contracts))
        unknown["contracts"][0]["closure_run"] = "not-a-recorded-run"
        with self.assertRaisesRegex(ValueError, "closure run is not a recorded VALID_PASS"):
            close_entry(entry, index, contracts=unknown, modules=modules)
        invalid = json.loads(json.dumps(contracts))
        invalid["contracts"][0].update({
            "closure_run": "35469009073",
            "tested_commit": "15dcd2223eaead03837a4645fbc5d044fb2b3502",
            "tested_tree": "a372ece3c0b62f694abd268a6adf596c878fe0c4"})
        with self.assertRaisesRegex(ValueError, "closure run is not a recorded VALID_PASS"):
            close_entry(entry, index, contracts=invalid, modules=modules)
        mismatched = json.loads(json.dumps(contracts))
        mismatched["contracts"][0]["tested_tree"] = "a" * 40
        with self.assertRaisesRegex(ValueError, "closure run is not a recorded VALID_PASS"):
            close_entry(entry, index, contracts=mismatched, modules=modules)

    def test_git_identity_is_required_and_clean_authority_stays_absent(self):
        index = self._closed_substrate_index()
        owner = index["external_cluster_sources"]["Dalvik.ClassInitialization"]
        digest = external_owner_digest(owner)

        def bound(commit, tree, run_id="injected-run"):
            contracts, modules = self._contract(
                index, tested_commit=commit, tested_tree=tree, closure_run=run_id)
            return contracts, modules

        missing = "b" * 40
        contracts, modules = bound(missing, "a" * 40)
        with self.assertRaisesRegex(ValueError, "tested commit is not in git"):
            require_production_contract(
                "Dalvik.ClassInitialization", owner["revision"], digest, contracts,
                modules=modules, ledger={"attempts": [{
                    "run_id": "injected-run", "classification": "VALID_PASS",
                    "tested_commit": missing, "tested_tree": "a" * 40}]})
        head = subprocess.check_output(["git", "rev-parse", "HEAD"], cwd=ROOT, text=True).strip()
        contracts, modules = bound(head, "a" * 40)
        row = {"run_id": "injected-run", "classification": "VALID_PASS",
               "tested_commit": head, "tested_tree": "a" * 40}
        with self.assertRaisesRegex(ValueError, "closure run is not a recorded VALID_PASS"):
            require_production_contract(
                "Dalvik.ClassInitialization", owner["revision"], digest, contracts,
                modules=modules, ledger={"attempts": [row, dict(row)]})
        with self.assertRaisesRegex(ValueError, "tested tree does not match git"):
            require_production_contract(
                "Dalvik.ClassInitialization", owner["revision"], digest, contracts,
                modules=modules, ledger={"attempts": [row]})
        contracts, modules = self._contract(index)
        with self.assertRaisesRegex(ValueError, "no API19 CLEAN differential authority"):
            require_production_contract(
                "Dalvik.ClassInitialization", owner["revision"], digest, contracts, modules=modules)

    def test_substrate_registry_rejects_a_second_reopen_ledger(self):
        with self.assertRaisesRegex(ValueError, "must not carry a reopen ledger"):
            require_production_contract(
                "Dalvik.ClassInitialization", REV, "1" * 64,
                {"schema_version": 1, "contracts": [], "reopens": []})

    def test_substrate_production_registry_starts_empty(self):
        registry = json.loads((ROOT / "ci/governance/substrate-production-contracts.json").read_text())
        self.assertEqual(registry, {"schema_version": 1, "contracts": []})
        self.assertNotIn("reopens", registry)
        encoded = json.dumps(registry)
        self.assertNotIn("PRODUCTION_CLOSED", encoded)
        for name in SHARED_RUNTIME_SUBSTRATE_OWNERS:
            self.assertNotIn(name, encoded)

    def test_real_integer_crossings_stay_unresolved_and_resources_binding_requires_reopen(self):
        evidence = ROOT / "tools/reference-lab/evidence"
        corpus = json.loads((evidence / "four-game-corpus-manifest.json").read_text())
        integer_index = json.loads((ROOT / "tools/reference-lab/indexes/integer-boxing-api19-locations.json").read_text())
        resource_index = json.loads((ROOT / "tools/reference-lab/indexes/shared-resources-api19-locations.json").read_text())
        integer = json.loads((evidence / "integer-boxing-source-seed.json").read_text())
        resources = json.loads((evidence / "shared-resource-source-seed.json").read_text())
        self.assertEqual(build_cluster_seed(corpus, integer_index, "libcore.IntegerBoxing"), integer)
        self.assertEqual(build_cluster_seed(corpus, resource_index, "Framework.Resources"), resources)
        value_of = "Ljava/lang/Integer;->valueOf(I)Ljava/lang/Integer;"
        cluster = integer["cluster_source_manifests"]["libcore.IntegerBoxing"]
        self.assertEqual(cluster["status"], "SOURCE_LOCATED")
        self.assertFalse(cluster["migration_authorized"])
        derived = integer["source_derived_clusters"]
        self.assertEqual(set(derived), {"Framework.ZygotePreload"})
        self.assertTrue(all(path == value_of + " -> Framework.ZygotePreload"
                            for path in derived["Framework.ZygotePreload"]["source_paths"]))
        absorbed = {
            "Dalvik.ClassInitialization", "Dalvik.ObjectAllocation", "Dalvik.MethodInvocation",
            "Dalvik.StaticFieldArrayRoots", "Libcore.BootClassLoading", "Dalvik.BootClassResolution",
            "Dalvik.ClassVerification", "Dalvik.Monitor", "Dalvik.ThreadState",
            "Bionic.PthreadCondition", "Bionic.ClockGettime", "Framework.ZygoteVMOptions",
            "AndroidNative.InitZygote"}
        self.assertTrue(absorbed.isdisjoint(derived))
        relations = [(edge["semantic_cluster"], edge["relationship"], edge["owner_source_status"])
                     for edge in cluster["prerequisite_edges"]]
        self.assertEqual(relations, [
            ("Dalvik.ClassInitialization", "UNRESOLVED", "SOURCE_LOCATED"),
            ("Dalvik.MethodInvocation", "UNRESOLVED", "SOURCE_LOCATED"),
            ("Dalvik.ObjectAllocation", "UNRESOLVED", "SOURCE_LOCATED"),
            ("Dalvik.StaticFieldArrayRoots", "UNRESOLVED", "SOURCE_CLOSED")])
        zygote_relations = [(edge["semantic_cluster"], edge["relationship"])
                            for edge in derived["Framework.ZygotePreload"]["prerequisite_edges"]]
        self.assertEqual(zygote_relations, [
            ("Dalvik.ClassInitialization", "UNRESOLVED"),
            ("Libcore.BootClassLoading", "UNRESOLVED")])
        value_of_id = next(item["dependency_id"] for item in integer["manifests"]
                           if item["canonical_name"] == value_of)
        zygote_path = value_of + " -> Framework.ZygotePreload"
        self.assertEqual([
            (item["scope"], item["semantic_cluster"], item["blocking_edge"],
             item.get("relationship"), item["origin_dependency_ids"], item["source_paths"])
            for item in integer["closure_work_queue"]], [
            ("OBSERVED_ENTRY", "libcore.IntegerBoxing",
             "AGR boot-class Integer ownership and GC integration", None,
             [value_of_id], [value_of]),
            ("OBSERVED_ENTRY", "libcore.IntegerBoxing",
             "Zygote preload and inherited Integer cache source closure", None,
             [value_of_id], [value_of]),
            ("PREREQUISITE", "Dalvik.ClassInitialization",
             "Dalvik class initialization before app fork", "UNRESOLVED",
             [value_of_id], [zygote_path]),
            ("PREREQUISITE", "Dalvik.ClassInitialization",
             "Dalvik class initialization for Integer.<clinit>", "UNRESOLVED",
             [value_of_id], [value_of]),
            ("PREREQUISITE", "Dalvik.MethodInvocation",
             "Dalvik constructor invocation", "UNRESOLVED",
             [value_of_id], [value_of]),
            ("PREREQUISITE", "Dalvik.ObjectAllocation",
             "Dalvik object allocation", "UNRESOLVED",
             [value_of_id], [value_of]),
            ("PREREQUISITE", "Dalvik.StaticFieldArrayRoots",
             "Dalvik static field and array GC roots", "UNRESOLVED",
             [value_of_id], [value_of]),
            ("PREREQUISITE", "Libcore.BootClassLoading",
             "libcore Class.forName and boot loader delegation", "UNRESOLVED",
             [value_of_id], [zygote_path]),
            ("SOURCE_DERIVED", "Framework.ZygotePreload",
             "AGR one-process inherited-state installation review", None,
             [value_of_id], [zygote_path])])
        stale = {
            "Dalvik class initialization source cluster closure",
            "Dalvik allocation source cluster closure",
            "Dalvik initialization contract before fork"}
        self.assertTrue(stale.isdisjoint(
            edge for item in integer["closure_work_queue"] for edge in (item["blocking_edge"],)))
        encoded = json.dumps(integer)
        self.assertNotIn("PREREQUISITE_CLOSED", encoded)
        self.assertNotIn("REOPEN_REQUIRED", encoded)
        resources_cluster = resources["cluster_source_manifests"]["Framework.Resources"]
        self.assertEqual(resources_cluster["status"], "SOURCE_LOCATED")
        self.assertFalse(resources_cluster["migration_authorized"])
        self.assertEqual(len(resources["source_derived_clusters"]), 15)
        self.assertNotIn("Dalvik.JNINativeBinding", resources["source_derived_clusters"])
        jni_help = resources["source_derived_clusters"]["AndroidNative.JNIHelp"]
        self.assertEqual(jni_help["blocking_edges"], [
            "nativehelper class lookup, method table and fatal failure source closure",
            "AGR JNI native registration contract review"])
        self.assertEqual([(edge["semantic_cluster"], edge["edge"], edge["relationship"],
                           edge["owner_source_status"])
                          for edge in jni_help["prerequisite_edges"]], [
            ("Dalvik.JNINativeBinding", "Dalvik RegisterNatives method binding",
             "REOPEN_REQUIRED", "SOURCE_LOCATED")])
        self.assertEqual(len(resources["closure_work_queue"]), 36)
        self.assertEqual([
            (item["scope"], item["semantic_cluster"], item["blocking_edge"], item.get("relationship"))
            for item in resources["closure_work_queue"]
            if item["semantic_cluster"] in ("AndroidNative.JNIHelp", "Dalvik.JNINativeBinding")], [
            ("PREREQUISITE", "Dalvik.JNINativeBinding",
             "Dalvik RegisterNatives method binding", "REOPEN_REQUIRED"),
            ("SOURCE_DERIVED", "AndroidNative.JNIHelp",
             "AGR JNI native registration contract review", None),
            ("SOURCE_DERIVED", "AndroidNative.JNIHelp",
             "nativehelper class lookup, method table and fatal failure source closure", None)])
        resources_encoded = json.dumps(resources)
        self.assertNotIn("PREREQUISITE_CLOSED", resources_encoded)
        self.assertEqual([
            (item["semantic_cluster"], item["blocking_edge"])
            for item in resources["closure_work_queue"]
            if item.get("relationship") == "REOPEN_REQUIRED"], [
            ("Dalvik.JNINativeBinding", "Dalvik RegisterNatives method binding")])

    def test_jni_native_binding_source_closure_stays_located(self):
        index = json.loads((ROOT / "tools/reference-lab/indexes/shared-resources-api19-locations.json").read_text())
        owner = index["external_cluster_sources"]["Dalvik.JNINativeBinding"]
        self.assertEqual(owner["status"], "SOURCE_LOCATED")
        self.assertIs(owner["closure_reviewed"], False)
        self.assertNotIn("PREREQUISITE_CLOSED", json.dumps(owner))
        crossings = [(edge["semantic_cluster"], edge["source_file"], edge["source_symbol"],
                      edge["relationship"], edge["owner_source_status"])
                     for edge in owner["prerequisite_edges"]]
        self.assertEqual(crossings, [
            ("Dalvik.ThreadState", "vm/Thread.cpp", "dvmChangeStatus",
             "UNRESOLVED", "SOURCE_LOCATED"),
            ("Dalvik.ClassInitialization", "vm/oo/Class.cpp", "dvmInitClass",
             "UNRESOLVED", "SOURCE_LOCATED"),
            ("Dalvik.ObjectAllocation", "vm/alloc/Alloc.cpp", "dvmAllocObject",
             "UNRESOLVED", "SOURCE_LOCATED"),
            ("Dalvik.MethodInvocation", "vm/interp/Stack.cpp", "dvmCallMethod",
             "UNRESOLVED", "SOURCE_LOCATED"),
            ("Dalvik.Monitor", "vm/Sync.cpp", "dvmLockObject",
             "UNRESOLVED", "SOURCE_LOCATED")])
        self.assertEqual(owner["source_file_sha256"]["vm/Jni.cpp"],
                         "ebba645673d34d23be01b20891cb18c432ce67a4d7d76fdfbf023cc944b2dbed")
        self.assertIn("method->fastJni is written and has no reader in the pinned Dalvik or libcore trees",
                      owner["internal_deps"])
        self.assertIn("platform invoke always passes JNIEnv* and jclass or this", owner["internal_deps"])
        help_edge = index["external_cluster_sources"]["AndroidNative.JNIHelp"]["prerequisite_edges"][0]
        self.assertEqual(help_edge["relationship"], "REOPEN_REQUIRED")
        self.assertEqual(help_edge["owner_source_status"], "SOURCE_LOCATED")

    def test_method_invocation_source_stays_located(self):
        integer_index = json.loads((ROOT / "tools/reference-lab/indexes/integer-boxing-api19-locations.json").read_text())
        resource_index = json.loads((ROOT / "tools/reference-lab/indexes/shared-resources-api19-locations.json").read_text())
        owner = integer_index["external_cluster_sources"]["Dalvik.MethodInvocation"]
        self.assertEqual(owner["status"], "SOURCE_LOCATED")
        self.assertIs(owner["closure_reviewed"], False)
        self.assertNotIn("PREREQUISITE_CLOSED", json.dumps(owner))
        self.assertEqual([(edge["semantic_cluster"], edge["source_symbol"], edge["relationship"])
                          for edge in owner["prerequisite_edges"]], [
            ("Dalvik.BootClassResolution", "dvmFindClassNoInit", "UNRESOLVED"),
            ("Dalvik.ClassInitialization", "dvmInitClass", "UNRESOLVED"),
            ("Dalvik.ObjectAllocation", "dvmAllocObject", "UNRESOLVED"),
            ("Dalvik.JNINativeBinding", "dvmCallJNIMethod", "UNRESOLVED")])
        binding = resource_index["external_cluster_sources"]["Dalvik.JNINativeBinding"]
        constructor = next(edge for edge in binding["prerequisite_edges"]
                           if edge["edge"] == "exception constructor invocation")
        self.assertEqual(constructor["semantic_cluster"], "Dalvik.MethodInvocation")
        self.assertEqual(constructor["relationship"], "UNRESOLVED")
        self.assertEqual(constructor["owner_source_status"], "SOURCE_LOCATED")
        other = [edge["relationship"] for edge in binding["prerequisite_edges"]
                 if edge["semantic_cluster"] != "Dalvik.MethodInvocation"]
        self.assertEqual(other, ["UNRESOLVED", "UNRESOLVED", "UNRESOLVED", "UNRESOLVED"])

    def test_thread_state_source_stays_located(self):
        integer_index = json.loads((ROOT / "tools/reference-lab/indexes/integer-boxing-api19-locations.json").read_text())
        resource_index = json.loads((ROOT / "tools/reference-lab/indexes/shared-resources-api19-locations.json").read_text())
        owner = integer_index["external_cluster_sources"]["Dalvik.ThreadState"]
        self.assertEqual(owner["status"], "SOURCE_LOCATED")
        self.assertIs(owner["closure_reviewed"], False)
        self.assertNotIn("PREREQUISITE_CLOSED", json.dumps(owner))
        self.assertNotIn("waitCond", owner["required_symbols"])
        self.assertNotIn("waitMutex", owner["required_symbols"])
        self.assertEqual([(edge["semantic_cluster"], edge["source_file"], edge["source_symbol"], edge["relationship"])
                          for edge in owner["prerequisite_edges"]], [
            ("Bionic.PthreadCondition", "libc/bionic/pthread.c", "pthread_cond_wait", "UNRESOLVED")])
        binding = resource_index["external_cluster_sources"]["Dalvik.JNINativeBinding"]
        thread_edge = next(edge for edge in binding["prerequisite_edges"]
                           if edge["edge"] == "JNI thread state around RegisterNatives")
        self.assertEqual(thread_edge["semantic_cluster"], "Dalvik.ThreadState")
        self.assertEqual(thread_edge["relationship"], "UNRESOLVED")
        self.assertEqual(thread_edge["owner_source_status"], "SOURCE_LOCATED")
        monitor = integer_index["external_cluster_sources"]["Dalvik.Monitor"]
        monitor_edge = next(edge for edge in monitor["cross_cluster_source_edges"]
                            if edge["semantic_cluster"] == "Dalvik.ThreadState")
        self.assertEqual(monitor_edge["status"], "SOURCE_LOCATED")
        self.assertEqual(monitor_edge["source_symbol"], "dvmChangeStatus")
        self.assertNotIn("prerequisite_edges", monitor)


if __name__ == "__main__":
    unittest.main()
