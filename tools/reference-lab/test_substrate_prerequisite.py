import json
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

    def _authority(self, index, cluster="Dalvik.ClassInitialization"):
        owner = index["external_cluster_sources"][cluster]
        digest = external_owner_digest(owner)
        commit = "d" * 40
        tree = "e" * 40
        closure_ref = "synthetic/" + cluster + "-closure.json"
        clean_ref = "synthetic/" + cluster + "-clean.json"
        contract = {"semantic_cluster": cluster, "status": "PRODUCTION_CLOSED",
                    "source_revision": owner["revision"], "source_owner_digest": digest,
                    "production_module": "SyntheticSubstrate", "tested_commit": commit,
                    "tested_tree": tree, "closure_evidence": closure_ref,
                    "closure_run": "synthetic-run", "clean_differential": clean_ref}
        evidence = {closure_ref: {
            "semantic_cluster": cluster, "run_id": "synthetic-run", "tested_commit": commit,
            "tested_tree": tree, "classification": "VALID_PASS",
            "source_revision": owner["revision"], "source_owner_digest": digest},
            clean_ref: {
                "kind": "API19_CLEAN_DIFFERENTIAL", "result": "NO_DIVERGENCE",
                "semantic_cluster": cluster, "tested_commit": commit, "tested_tree": tree,
                "source_revision": owner["revision"], "source_owner_digest": digest}}
        return {"schema_version": 1, "contracts": [contract], "reopens": []}, evidence, ["SyntheticSubstrate"]

    def _document(self, index, review=True):
        if review:
            index = json.loads(json.dumps(index))
            index["cluster_reviews"] = {CLUSTER: {
                "closure_reviewed": True, "source_revision": REV, "entry_names": [UPPER],
                "source_file_sha256": {BOX: SHA_BOX},
                "reviewed_dependency_edges": ["class initialization"],
                "unresolved_dependency_edges": [], "reviewed_by": "source-audit",
                "closure_notes": "Upper cluster reviewed without absorbing substrate internals"}}
        contracts, evidence, modules = None, None, None
        closed = [edge for entry in (index.get("entries") or {}).values()
                  for edge in (entry.get("prerequisite_edges") or [])
                  if isinstance(edge, dict) and edge.get("relationship") == "PREREQUISITE_CLOSED"]
        if closed:
            contracts, evidence, modules = self._authority(index, closed[0]["semantic_cluster"])
        entry = {"dependency_id": "JAVA_METHOD:box", "canonical_name": UPPER}
        manifest = close_entry(entry, index, contracts=contracts, production_evidence=evidence, modules=modules)
        derived = source_derived_clusters([manifest], index, contracts, evidence, modules)
        clusters = cluster_manifests([manifest], index, contracts, evidence, modules)
        document = {"schema_version": 1, "source_index_revision": REV, "manifests": [manifest],
                    "cluster_source_manifests": clusters, "source_derived_clusters": derived,
                    "closure_work_queue": closure_work_queue(
                        [manifest], derived, index, contracts, evidence, modules)}
        return manifest, clusters, derived, document, index, contracts, evidence, modules

    def test_closed_prerequisite_satisfies_one_edge_without_lowering_authorization(self):
        index = self._closed_substrate_index()
        self.assertTrue(external_edge_closed(
            index["entries"][UPPER]["cross_cluster_source_edges"][0], index))
        manifest, clusters, derived, _, _, contracts, evidence, modules = self._document(index, review=False)
        self.assertEqual(manifest["status"], "SOURCE_CLOSED")
        self.assertFalse(manifest["migration_authorized"])
        self.assertEqual(derived, {})
        self.assertEqual(clusters[CLUSTER]["status"], "SOURCE_CLOSED")
        self.assertFalse(clusters[CLUSTER]["migration_authorized"])
        index["source_sha256"] = "8" * 64
        self.assertEqual(close_entry(
            {"dependency_id": "JAVA_METHOD:box", "canonical_name": UPPER}, index,
            contracts=contracts, production_evidence=evidence, modules=modules)["status"],
            "SOURCE_LOCATED")
        index["source_sha256"] = SHA_BOX
        _, authorized_clusters, _, document, authorized_index, authorized_contracts, authorized_evidence, authorized_modules = self._document(index, review=True)
        self.assertEqual(authorized_clusters[CLUSTER]["status"], "MIGRATION_AUTHORIZED")
        self.assertTrue(authorized_clusters[CLUSTER]["migration_authorized"])
        self.assertFalse(any(item.get("scope") == "PREREQUISITE" for item in document["closure_work_queue"]))
        validate_source_manifests(document, authorized_index, authorized_contracts,
                                  authorized_evidence, authorized_modules)
        incomplete = json.loads(json.dumps(index))
        incomplete["cluster_reviews"] = {CLUSTER: {
            "closure_reviewed": True, "source_revision": REV, "entry_names": [UPPER],
            "source_file_sha256": {BOX: SHA_BOX}, "reviewed_dependency_edges": [],
            "unresolved_dependency_edges": [], "reviewed_by": "source-audit",
            "closure_notes": "Upper review omitted the prerequisite edge"}}
        bound_contracts, bound_evidence, bound_modules = self._authority(incomplete)
        incomplete_clusters = cluster_manifests(
            [close_entry({"dependency_id": "JAVA_METHOD:box", "canonical_name": UPPER}, incomplete,
                         contracts=bound_contracts, production_evidence=bound_evidence,
                         modules=bound_modules)],
            incomplete, bound_contracts, bound_evidence, bound_modules)
        self.assertEqual(incomplete_clusters[CLUSTER]["status"], "SOURCE_CLOSED")
        self.assertFalse(incomplete_clusters[CLUSTER]["migration_authorized"])

    def test_unresolved_and_reopen_block_upper_closure_and_authorization(self):
        _, _, _, closed, closed_index, closed_contracts, closed_evidence, closed_modules = self._document(
            self._closed_substrate_index(), review=True)
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
                validate_source_manifests(forged, closed_index, closed_contracts,
                                          closed_evidence, closed_modules)

    def test_closed_upper_cluster_cannot_absorb_substrate_without_relationship(self):
        _, _, _, document, index, contracts, evidence, modules = self._document(
            self._closed_substrate_index(), review=True)
        forged = json.loads(json.dumps(document))
        forged["manifests"][0].pop("prerequisite_edges")
        forged["cluster_source_manifests"][CLUSTER].pop("prerequisite_edges")
        with self.assertRaisesRegex(ValueError, "requires a prerequisite relationship"):
            validate_source_manifests(forged, index, contracts, evidence, modules)
        absorbed = json.loads(json.dumps(document))
        absorbed["source_derived_clusters"] = {"Dalvik.Monitor": {
            "semantic_cluster": "Dalvik.Monitor",
            "origin_dependency_ids": ["JAVA_METHOD:box"],
            "source_paths": [UPPER + " -> Dalvik.ClassInitialization -> Dalvik.Monitor"]}}
        with self.assertRaisesRegex(ValueError, "absorbed shared substrate internals"):
            validate_source_manifests(absorbed, index, contracts, evidence, modules)

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
        contracts, evidence, modules = self._authority(index)
        entry = {"dependency_id": "JAVA_METHOD:box", "canonical_name": UPPER}
        for key, message in (
                ("source_owner_digest", "lacks source owner digest"),
                ("tested_commit", "lacks tested commit"),
                ("tested_tree", "lacks tested tree"),
                ("clean_differential", "lacks clean differential")):
            broken = json.loads(json.dumps(contracts))
            broken["contracts"][0].pop(key)
            with self.assertRaisesRegex(ValueError, message):
                close_entry(entry, index, contracts=broken, production_evidence=evidence, modules=modules)
        unbound = json.loads(json.dumps(evidence))
        unbound[contracts["contracts"][0]["closure_evidence"]]["source_owner_digest"] = "f" * 64
        with self.assertRaisesRegex(ValueError, "does not bind the source owner"):
            close_entry(entry, index, contracts=contracts, production_evidence=unbound, modules=modules)
        missing = dict(evidence)
        missing.pop(contracts["contracts"][0]["clean_differential"])
        with self.assertRaisesRegex(ValueError, "evidence is missing"):
            close_entry(entry, index, contracts=contracts, production_evidence=missing, modules=modules)

    def test_bound_production_contract_closes_prerequisite_without_queueing_it(self):
        manifest, _, derived, document, index, contracts, evidence, modules = self._document(
            self._closed_substrate_index(), review=False)
        self.assertEqual(manifest["status"], "SOURCE_CLOSED")
        self.assertEqual(derived, {})
        self.assertFalse(any(item.get("scope") == "PREREQUISITE" for item in document["closure_work_queue"]))
        validate_source_manifests(document, index, contracts, evidence, modules)
        reopened = json.loads(json.dumps(contracts))
        reopened["reopens"] = [{"semantic_cluster": "Dalvik.ClassInitialization",
                                "reason": "synthetic contract reopen",
                                "evidence": "synthetic reopen evidence"}]
        with self.assertRaisesRegex(ValueError, "reopen blocks closed prerequisite"):
            close_entry({"dependency_id": "JAVA_METHOD:box", "canonical_name": UPPER}, index,
                        contracts=reopened, production_evidence=evidence, modules=modules)

    def test_substrate_production_registry_starts_empty(self):
        registry = json.loads((ROOT / "ci/governance/substrate-production-contracts.json").read_text())
        self.assertEqual(registry, {"schema_version": 1, "contracts": [], "reopens": []})
        encoded = json.dumps(registry)
        self.assertNotIn("PRODUCTION_CLOSED", encoded)
        for name in SHARED_RUNTIME_SUBSTRATE_OWNERS:
            self.assertNotIn(name, encoded)

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
