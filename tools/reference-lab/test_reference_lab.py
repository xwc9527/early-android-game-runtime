import json
import tempfile
import unittest
from pathlib import Path

from lab import assert_matched_reference, assert_not_oracle, describe, ensure_layout
from mapper import build_book, write_book
from source_closure import close_entry
from source_index import build_index
from workflow import validate_source_manifests

EVIDENCE = Path(__file__).with_name("clean_boot_evidence.json")


class ReferenceLabTest(unittest.TestCase):
    def test_trace_is_not_oracle(self):
        trace = describe("TRACE")
        trace["variant"] = "TRACE"
        assert_not_oracle(trace)
        self.assertEqual(trace["role"], "dependency_mapper")
        self.assertFalse(trace["may_authorize_implementation"])
        clean = describe("CLEAN")
        self.assertEqual(clean["role"], "semantic_oracle")
        self.assertFalse(clean["instrumented"])
        with self.assertRaises(ValueError):
            assert_matched_reference(
                {"variant": "CLEAN", "instrumented": False, "baseline": "android-x86-4.4-r5"},
                {"variant": "TRACE", "instrumented": True, "baseline": "android-4.4.4_r2"})

    def test_matched_pair_requires_same_build_base_and_clean_role(self):
        common = {"baseline": "android-4.4.4_r2", "source_manifest_sha256": "a" * 64,
                  "host_toolchain_sha256": "b" * 64, "build_only_patch_sha256": "c" * 64,
                  "build_flavor": "aosp_x86-eng", "execution_mode": "int:portable"}
        clean = dict(common, variant="CLEAN", instrumented=False,
                     image_sha256="d" * 64, libdvm_sha256="1" * 64)
        trace = dict(common, variant="TRACE", instrumented=True,
                     image_sha256="e" * 64, libdvm_sha256="2" * 64,
                     trace_patch_sha256="f" * 64)
        assert_matched_reference(clean, trace)
        arm_common = dict(common, build_flavor="aosp_arm-eng")
        assert_matched_reference(dict(clean, **arm_common), dict(trace, **arm_common))
        with self.assertRaisesRegex(ValueError, "Dalvik library"):
            assert_matched_reference(clean, dict(trace, libdvm_sha256="1" * 64))
        with self.assertRaisesRegex(ValueError, "source_manifest_sha256"):
            assert_matched_reference(clean, dict(trace, source_manifest_sha256="0" * 64))
        with self.assertRaisesRegex(ValueError, "CLEAN image carries"):
            assert_matched_reference(dict(clean, trace_patch_sha256="f" * 64), trace)

    def test_layout_keeps_clean_and_trace_apart(self):
        with tempfile.TemporaryDirectory() as tmp:
            document = ensure_layout(tmp)
            self.assertFalse(document["images_provisioned"])
            self.assertTrue((Path(tmp) / "clean-image").is_dir())
            self.assertTrue((Path(tmp) / "trace-image").is_dir())
            self.assertNotEqual(document["clean"]["role"], document["trace"]["role"])

    def test_repeated_dependency_edges_are_aggregated(self):
        base = {"kind": "JAVA_METHOD", "canonical_name": "Ljava/util/Vector;->size()I",
                "caller": "Lgame/A;->paint()V", "dex_pc": 7, "opcode": 110,
                "method_idx": 12, "resolved_callee": "Ljava/util/Vector;->size()I",
                "process_id": 42}
        events = [dict(base, sequence=sequence) for sequence in (1, 2, 3)]
        book = build_book({"name": "game"}, events, [], {"variant": "TRACE"})
        observations = book["dependencies"][0]["observations"]
        self.assertEqual(len(observations), 1)
        self.assertEqual((observations[0]["count"], observations[0]["first_seq"],
                          observations[0]["last_seq"]), (3, 1, 3))

    def test_book_does_not_collapse_confidence_or_invent_callees(self):
        book = build_book(
            {"name": "sample"},
            [{
                "kind": "JAVA_METHOD",
                "canonical_name": "Activity.setContentView(I)V",
                "caller": "FrozenBubble.onCreate",
                "dex_pc": 20,
                "opcode": "invoke-virtual",
                "method_idx": 185,
                "lifecycle_phase": "create",
            }],
            [{
                "kind": "JAVA_METHOD",
                "canonical_name": "Vector.addElement",
                "confidence": "STATIC_REFERENCED",
            }],
            trace_evidence={"variant": "TRACE", "instrumented": True,
                            "role": "dependency_mapper", "baseline": "android-4.4.4_r2",
                            "apk_sha256": "a" * 64, "image_sha256": "b" * 64,
                            "scenario": "cold_start", "events_sha256": "c" * 64,
                            "observer_coverage": ["APP_DEX_TO_BOOT_METHOD_INVOKE"],
                            "observation_scope": "APP_TRIGGERED_OBSERVED_LOWER_BOUND",
                            "zygote_preload_sha256": "d" * 64,
                            "runtime_config": {"dalvik.vm.execution-mode": "int:portable"},
                            "may_authorize_pruning": False},
        )
        names = {item["canonical_name"]: item["confidence"] for item in book["dependencies"]}
        self.assertEqual(names["Activity.setContentView(I)V"], "OBSERVED_RUNTIME")
        self.assertEqual(names["Vector.addElement"], "STATIC_REFERENCED")
        text = json.dumps(book)
        self.assertNotIn("PhoneWindow", text)
        self.assertEqual(book["variant"], "TRACE")
        with tempfile.TemporaryDirectory() as tmp:
            path = Path(tmp) / "book.json"
            write_book(path, book)
            self.assertEqual(json.loads(path.read_text())["role"], "dependency_mapper")

    def test_static_cannot_claim_runtime(self):
        with self.assertRaises(ValueError):
            build_book({}, [], [{
                "kind": "JAVA_METHOD",
                "canonical_name": "Vector.addElement",
                "confidence": "OBSERVED_RUNTIME",
            }])

    def test_source_closure_uses_index_only(self):
        entry = {
            "dependency_id": "JAVA_METHOD:abc",
            "canonical_name": "Activity.setContentView(I)V",
        }
        unresolved = close_entry(entry, {"entries": {}})
        self.assertEqual(unresolved["status"], "UNRESOLVED")
        self.assertEqual(unresolved["source_files"], [])
        closed = close_entry(entry, {"entries": {
            "Activity.setContentView(I)V": {
                "source_files": ["platform/frameworks/base/core/java/android/app/Activity.java"],
                "required_symbols": ["setContentView"],
            }
        }})
        self.assertEqual(closed["status"], "SOURCE_LOCATED")
        self.assertEqual(closed["migration_type"], "SOURCE_PORT")
        self.assertNotIn("PhoneWindow", json.dumps(closed))

    def test_multifile_closure_requires_all_hashes_and_edges(self):
        entry = {"dependency_id": "JAVA_METHOD:stream", "canonical_name": "Stream.close"}
        pinned = {"owner_cluster": "Framework", "semantic_cluster": "Framework.AssetStream",
                  "source_repo": "platform/frameworks/base",
                  "source_file": "A.java", "source_symbol": "close",
                  "source_files": ["A.java", "Bridge.cpp"],
                  "required_symbols": ["close", "destroyAsset"],
                  "registration_deps": ["native registration"],
                  "cross_cluster_deps": ["androidfw Asset"],
                  "closure_reviewed": True,
                  "closure_evidence": {"reviewed_by": "source-audit",
                                       "closure_notes": "Reviewed both owners",
                                       "source_file_sha256": {"A.java": "a" * 64,
                                                              "Bridge.cpp": "b" * 64},
                                       "reviewed_dependency_edges": ["native registration",
                                                                     "androidfw Asset"],
                                       "edge_reviews": {
                                           "native registration": {
                                               "disposition": "IN_CLUSTER",
                                               "source_repo": "platform/frameworks/base",
                                               "revision": "c" * 40,
                                               "source_file": "Bridge.cpp",
                                               "source_symbol": "registerAsset"},
                                           "androidfw Asset": {
                                               "disposition": "SOURCE_CLOSED_EXTERNAL",
                                               "semantic_cluster": "AndroidNative.Asset",
                                               "source_repo": "platform/frameworks/base",
                                               "revision": "c" * 40,
                                               "source_file": "Asset.cpp",
                                               "source_symbol": "Asset::read",
                                               "source_manifest_sha256": "d" * 64}},
                                       "unresolved_dependency_edges": []}}
        index = {"revision": "c" * 40,
                 "source_file_sha256": {"A.java": "a" * 64,
                                        "Bridge.cpp": "b" * 64},
                 "entries": {entry["canonical_name"]: pinned}}
        complete = close_entry(entry, index)
        self.assertEqual(complete["status"], "SOURCE_CLOSED")
        validate_source_manifests({"schema_version": 1, "manifests": [complete]})
        pinned["blocking_edges"] = ["unresolved host boundary"]
        self.assertEqual(close_entry(entry, index)["status"], "SOURCE_LOCATED")
        pinned.pop("blocking_edges")
        pinned["cross_cluster_source_edges"] = [{"status": "SOURCE_LOCATED"}]
        self.assertEqual(close_entry(entry, index)["status"], "SOURCE_LOCATED")
        pinned.pop("cross_cluster_source_edges")
        pinned["closure_evidence"]["edge_reviews"].pop("androidfw Asset")
        self.assertEqual(close_entry(entry, index)["status"], "SOURCE_LOCATED")
        pinned["closure_evidence"]["edge_reviews"]["androidfw Asset"] = {
            "disposition": "SOURCE_CLOSED_EXTERNAL", "semantic_cluster": "AndroidNative.Asset",
            "source_repo": "platform/frameworks/base", "revision": "c" * 40,
            "source_file": "Asset.cpp", "source_symbol": "Asset::read",
            "source_manifest_sha256": "d" * 64}
        pinned["closure_evidence"]["reviewed_dependency_edges"] = ["native registration"]
        self.assertEqual(close_entry(entry, index)["status"], "SOURCE_LOCATED")
        pinned["closure_evidence"]["reviewed_dependency_edges"] = ["native registration",
                                                                     "androidfw Asset"]
        pinned["closure_evidence"]["unresolved_dependency_edges"] = ["androidfw Asset"]
        self.assertEqual(close_entry(entry, index)["status"], "SOURCE_LOCATED")
        pinned["closure_evidence"]["unresolved_dependency_edges"] = []
        pinned["closure_evidence"]["source_file_sha256"]["Bridge.cpp"] = "d" * 64
        self.assertEqual(close_entry(entry, index)["status"], "SOURCE_LOCATED")
        pinned["closure_evidence"]["source_file_sha256"]["Bridge.cpp"] = "b" * 64
        pinned["closure_evidence"]["source_file_sha256"].pop("Bridge.cpp")
        self.assertEqual(close_entry(entry, index)["status"], "SOURCE_LOCATED")

    def test_service_boundary_stops(self):
        manifest = close_entry({
            "dependency_id": "SERVICE:relayout",
            "canonical_name": "android.view.IWindowSession#relayout",
            "service_boundary": "HOST_SERVICE_HLE_BOUNDARY",
        }, {"entries": {}})
        self.assertEqual(manifest["status"], "BOUNDARY_CANDIDATE")
        self.assertEqual(manifest["migration_type"], "SOURCE_PORT")
        forged = dict(manifest, status="BOUNDARY", migration_type="SERVICE_HLE",
                      owner_cluster="WindowManager", source_repo="frameworks/base",
                      source_file="services/java/com/android/server/wm/WindowManagerService.java",
                      source_symbol="relayoutWindow", source_revision="a" * 40,
                      closure_evidence={"source_sha256": "b" * 64,
                                        "reviewed_by": "reviewer", "closure_notes": "reviewed"})
        with self.assertRaisesRegex(ValueError, "transaction contract"):
            validate_source_manifests({"schema_version": 1, "manifests": [forged]})

    def test_jni_table_index_uses_only_listed_symbols(self):
        with tempfile.TemporaryDirectory() as tmp:
            path = Path(tmp) / "Jni.cpp"
            path.write_text(
                "static const struct JNINativeInterface gNativeInterface = {\n"
                "    GetStaticIntField,\n"
                "    CallIntMethod,\n"
                "    NULL,\n"
                "};\n",
                encoding="utf-8",
            )
            document = build_index(path)
            self.assertIn("GetStaticIntField", document["entries"])
            self.assertNotIn("PhoneWindow", document["entries"])
            manifest = close_entry({
                "dependency_id": "JNI_BINDING:GetStaticIntField",
                "canonical_name": "GetStaticIntField",
            }, document)
            self.assertEqual(manifest["status"], "SOURCE_LOCATED")
            self.assertEqual(manifest["source_file"], "vm/Jni.cpp")
            self.assertEqual(manifest["owner_cluster"], "JNI")

    def test_clean_boot_evidence_is_not_trace(self):
        evidence = json.loads(EVIDENCE.read_text(encoding="utf-8"))
        self.assertEqual(evidence["variant"], "CLEAN")
        self.assertFalse(evidence["instrumented"])
        self.assertEqual(evidence["live_release"], "4.4.4")
        self.assertEqual(evidence["live_sdk"], "19")
        self.assertFalse(evidence["trace_image_built"])
        self.assertFalse(evidence["oracle_ready"])
        self.assertEqual(evidence["image_sha1"], "4c0edceef12bf4b8afb1b8390d94a9af29bbbca8")

    def test_original_implementation_is_rejected(self):
        with self.assertRaises(ValueError):
            close_entry({
                "dependency_id": "JAVA_METHOD:abc",
                "canonical_name": "Activity.setContentView(I)V",
            }, {"entries": {}}, migration_type="ORIGINAL_IMPLEMENTATION")


if __name__ == "__main__":
    unittest.main()
