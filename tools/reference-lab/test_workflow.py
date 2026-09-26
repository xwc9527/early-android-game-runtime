import hashlib
import json
import struct
import tempfile
import unittest
import zipfile
from pathlib import Path

from cluster_seed import build_cluster_seed, build_seed
from mapper import build_book, corpus_union, union_books
from source_mapping_queue import build_queue
from source_closure import close_entry, external_edge_closed
from static_scan import _dex_refs, _elf_refs, apk_identity, scan_apk
from workflow import manifests, trace_events, validate_book, validate_source_manifests

ROOT = Path(__file__).resolve().parents[2]


class WorkflowTest(unittest.TestCase):
    def test_resource_asset_lifetime_chain_remains_source_located(self):
        evidence = ROOT / "tools/reference-lab/evidence"
        corpus = json.loads((evidence / "four-game-corpus-manifest.json").read_text())
        index = json.loads((ROOT / "tools/reference-lab/indexes/shared-resources-api19-locations.json").read_text())
        generated = build_cluster_seed(corpus, index, "Framework.Resources")
        committed = json.loads((evidence / "shared-resource-source-seed.json").read_text())
        self.assertEqual(committed, generated)
        validate_source_manifests(committed)
        self.assertEqual(len(committed["manifests"]), 2)
        self.assertEqual(len(committed["source_derived_clusters"]), 16)
        asset = committed["source_derived_clusters"]["AndroidNative.AssetObject"]
        self.assertEqual(asset["status"], "SOURCE_LOCATED")
        self.assertFalse(asset["migration_authorized"])
        self.assertTrue(any("Framework.AssetStreamLifecycle -> Framework.AssetManagerJNI -> "
                            "AndroidNative.AssetObject" in path for path in asset["source_paths"]))
        self.assertTrue(any(item["semantic_cluster"] == "AndroidNative.AssetObject"
                            for item in committed["closure_work_queue"]))
        mapped = committed["source_derived_clusters"]["AndroidNative.FileMap"]
        self.assertTrue(any("AndroidNative.AssetObject -> AndroidNative.ZipFileRO -> "
                            "AndroidNative.FileMap" in path for path in mapped["source_paths"]))
        self.assertTrue(any("AndroidNative.AssetObject -> AndroidNative.StreamingZipInflater -> "
                            "AndroidNative.FileMap" in path for path in mapped["source_paths"]))
        self.assertIn("Linux file descriptor and mmap boundary", mapped["boundary_contracts"])
        inflater = committed["source_derived_clusters"]["External.ZlibInflate"]
        self.assertEqual(inflater["status"], "SOURCE_LOCATED")
        self.assertTrue(any("AndroidNative.ZipFileRO -> External.ZlibInflate" in path
                            for path in inflater["source_paths"]))
        self.assertTrue(any("AndroidNative.StreamingZipInflater -> External.ZlibInflate" in path
                            for path in inflater["source_paths"]))
        binding = committed["source_derived_clusters"]["Dalvik.JNINativeBinding"]
        self.assertTrue(any("Framework.AssetManagerJNI -> Framework.NativeRegistration -> "
                            "AndroidNative.JNIHelp -> Dalvik.JNINativeBinding" in path
                            for path in binding["source_paths"]))
        self.assertFalse(binding["migration_authorized"])
        context = committed["source_derived_clusters"]["Framework.ContextResourceDispatch"]
        self.assertEqual(context["status"], "SOURCE_LOCATED")
        cache = committed["source_derived_clusters"]["Framework.ResourcesManagerCache"]
        self.assertTrue(any("Framework.ContextResourceDispatch -> Framework.LoadedApkResources -> "
                            "Framework.ResourcesManagerCache" in path
                            for path in cache["source_paths"]))
        self.assertTrue(any("Framework.ContextResourceDispatch -> Framework.ResourcesManagerCache"
                            in path for path in cache["source_paths"]))
        paths = committed["source_derived_clusters"]["Framework.AssetManagerPaths"]
        self.assertTrue(any("Framework.ResourcesManagerCache -> Framework.AssetManagerPaths"
                            in path for path in paths["source_paths"]))
        display = committed["source_derived_clusters"]["Framework.DisplayMetricsBridge"]
        boundary = display["boundary_contracts"][
            "IDisplayManager.getDisplayInfo Binder service boundary"]
        self.assertEqual(boundary["service_name"], "display")
        self.assertEqual(display["status"], "SOURCE_LOCATED")
        self.assertEqual(boundary["get_display_info_transaction_code"], 1)
        self.assertEqual(boundary["register_callback_transaction_code"], 3)
        self.assertEqual(boundary["on_display_event_callback_code"], 1)
        self.assertTrue(boundary["on_display_event_oneway"])
        self.assertIn("Framework.CompatibilityScale", committed["source_derived_clusters"])

    def test_integer_cluster_seed_keeps_probe_scope_and_blocks_authority(self):
        evidence = ROOT / "tools/reference-lab/evidence"
        manifest = json.loads((evidence / "four-game-corpus-manifest.json").read_text())
        index = json.loads((ROOT / "tools/reference-lab/indexes/integer-boxing-api19-locations.json").read_text())
        name = "Ljava/lang/Integer;->valueOf(I)Ljava/lang/Integer;"
        result = build_seed(manifest, index, name)
        self.assertEqual(len(result["seeds"]), 3)
        self.assertEqual(sum(item["observed_count"] for item in result["seeds"]), 11702)
        self.assertEqual(result["cluster_source_manifests"]["libcore.IntegerBoxing"]["status"],
                         "SOURCE_LOCATED")
        self.assertFalse(result["may_authorize_pruning"])
        cluster = build_cluster_seed(manifest, index, "libcore.IntegerBoxing")
        self.assertEqual(len(cluster["manifests"]), 5)
        self.assertEqual(len(cluster["seeds"]), 8)
        self.assertEqual(sum(item["observed_count"] for item in cluster["seeds"]), 41776)
        self.assertEqual(sum(item["status"] == "SOURCE_CLOSED" for item in cluster["manifests"]), 4)
        self.assertEqual(sum(item["status"] == "SOURCE_LOCATED" for item in cluster["manifests"]), 1)
        self.assertEqual(cluster["cluster_source_manifests"]["libcore.IntegerBoxing"]["status"],
                         "SOURCE_LOCATED")
        value_of = index["entries"]["Ljava/lang/Integer;->valueOf(I)Ljava/lang/Integer;"]
        root_edge = next(item for item in value_of["cross_cluster_source_edges"]
                         if item["semantic_cluster"] == "Dalvik.StaticFieldArrayRoots")
        self.assertTrue(external_edge_closed(root_edge, index))
        self.assertFalse(cluster["cluster_source_manifests"]["libcore.IntegerBoxing"]["migration_authorized"])
        derived = cluster["source_derived_clusters"]
        self.assertEqual(len(derived), 14)
        self.assertNotIn("Dalvik.OOMException", derived)
        self.assertEqual(derived["Libcore.BootClassLoading"]["status"], "SOURCE_LOCATED")
        self.assertEqual(derived["Dalvik.BootClassResolution"]["status"], "SOURCE_LOCATED")
        self.assertTrue(any("Framework.ZygotePreload -> Libcore.BootClassLoading -> "
                            "Dalvik.BootClassResolution" in path
                            for path in derived["Dalvik.BootClassResolution"]["source_paths"]))
        self.assertTrue(any("Dalvik.BootClassResolution -> Dalvik.ClassInitialization" in path
                            for path in derived["Dalvik.ClassInitialization"]["source_paths"]))
        self.assertTrue(any("Dalvik.BootClassResolution -> Dalvik.MethodInvocation" in path
                            for path in derived["Dalvik.MethodInvocation"]["source_paths"]))
        self.assertTrue(any("Dalvik.Monitor -> Dalvik.ThreadState" in path
                            for path in derived["Dalvik.ThreadState"]["source_paths"]))
        self.assertTrue(any("Dalvik.Monitor -> Bionic.PthreadCondition" in path
                            for path in derived["Bionic.PthreadCondition"]["source_paths"]))
        self.assertIn("Linux futex wait/wake boundary",
                      derived["Bionic.PthreadCondition"]["boundary_contracts"])
        self.assertTrue(any("Bionic.PthreadCondition -> Bionic.ClockGettime" in path
                            for path in derived["Bionic.ClockGettime"]["source_paths"]))
        self.assertEqual(derived["Dalvik.StaticFieldArrayRoots"]["status"], "SOURCE_CLOSED")
        self.assertEqual(derived["Framework.ZygoteVMOptions"]["status"], "SOURCE_CLOSED")
        self.assertEqual(derived["AndroidNative.InitZygote"]["status"], "SOURCE_CLOSED")
        self.assertFalse(any(item["migration_authorized"] for item in derived.values()))
        self.assertTrue(all(item["origin_dependency_ids"] and item["source_paths"]
                            for item in derived.values()))
        queue = cluster["closure_work_queue"]
        self.assertTrue(any(item["scope"] == "SOURCE_DERIVED" and
                            item["semantic_cluster"] == "Dalvik.ClassVerification"
                            for item in queue))
        self.assertTrue(any(item["semantic_cluster"] == "Dalvik.BootClassResolution"
                            for item in queue))
        self.assertFalse(any(item["semantic_cluster"] == "Dalvik.StaticFieldArrayRoots"
                             for item in queue))
        forged = json.loads(json.dumps(cluster))
        forged["closure_work_queue"].pop()
        with self.assertRaisesRegex(ValueError, "differs from denied gates"):
            validate_source_manifests(forged)
        forged = json.loads(json.dumps(cluster))
        forged.pop("closure_work_queue")
        with self.assertRaisesRegex(ValueError, "differs from denied gates"):
            validate_source_manifests(forged)
        forged = json.loads(json.dumps(cluster))
        forged.pop("source_derived_clusters")
        with self.assertRaisesRegex(ValueError, "omits a pinned source edge"):
            validate_source_manifests(forged)
        forged = json.loads(json.dumps(cluster))
        forged["source_derived_clusters"]["Dalvik.StaticFieldArrayRoots"]["source_paths"] = [
            "Unrelated.method -> Dalvik.StaticFieldArrayRoots"]
        with self.assertRaisesRegex(ValueError, "observed parent"):
            validate_source_manifests(forged)
        forged = json.loads(json.dumps(cluster))
        root = forged["source_derived_clusters"]["Dalvik.StaticFieldArrayRoots"]
        root["source_paths"] = [path.replace(" -> Dalvik.StaticFieldArrayRoots",
                                             " -> Dalvik.Monitor -> Dalvik.StaticFieldArrayRoots")
                                for path in root["source_paths"]]
        with self.assertRaisesRegex(ValueError, "pinned source edge"):
            validate_source_manifests(forged)
        forged = json.loads(json.dumps(cluster))
        forged["source_derived_clusters"]["Dalvik.StaticFieldArrayRoots"]["source_file_sha256"][
            "vm/alloc/MarkSweep.cpp"] = "0" * 64
        with self.assertRaisesRegex(ValueError, "pinned source edge"):
            validate_source_manifests(forged)

    def test_integer_preload_is_inherited_in_each_qualified_trace(self):
        evidence = ROOT / "tools/reference-lab/evidence"
        corpus = json.loads((evidence / "four-game-corpus-manifest.json").read_text())
        boot = json.loads((evidence / "paired-core-odex-preverification.json").read_text())
        self.assertEqual(boot["clean"]["embedded_dex_sha256"],
                         boot["trace"]["embedded_dex_sha256"])
        self.assertEqual(boot["clean"]["class_access_flags"],
                         boot["trace"]["class_access_flags"])
        self.assertEqual(set(boot["clean"]["class_access_flags"]),
                         {"Ljava/lang/Integer;", "Ljava/lang/Number;",
                          "Ljava/lang/Comparable;"})
        self.assertTrue(all(flags & 0x30000 == 0x30000
                            for flags in boot["clean"]["class_access_flags"].values()))
        index = json.loads((ROOT / "tools/reference-lab/indexes/integer-boxing-api19-locations.json").read_text())
        preload = index["external_cluster_sources"]["Framework.ZygotePreload"]
        expected = preload["source_file_sha256"]["preloaded-classes"]
        edge = index["entries"]["Ljava/lang/Integer;->valueOf(I)Ljava/lang/Integer;"]["cross_cluster_source_edges"]
        self.assertEqual(sum(item["semantic_cluster"] == "Framework.ZygotePreload" for item in edge), 1)
        for probe in corpus:
            trace = json.loads((ROOT / probe["trace"]).read_text())
            clean = json.loads((ROOT / probe["clean"]).read_text())
            self.assertEqual(clean["vm_config"]["dalvik.vm.dexopt-flags"], "")
            self.assertEqual(trace["vm_config"]["dalvik.vm.dexopt-flags"], "")
            self.assertEqual(trace["zygote_preload"]["class_state"], "PRELOADED_IN_ZYGOTE")
            self.assertEqual(trace["zygote_preload"]["configured_classes_sha256"], expected)
            self.assertNotIn("java.lang.Integer", trace["zygote_preload"]["failed_classes"])
            self.assertNotIn("java.lang.Number", trace["zygote_preload"]["failed_classes"])
            self.assertNotIn("java.lang.Comparable", trace["zygote_preload"]["failed_classes"])

    def test_multi_repo_queue_keeps_source_and_authority_separate(self):
        root = ROOT / "tools/reference-lab"
        corpus = json.loads((root / "evidence/four-game-corpus-manifest.json").read_text())
        indexes = [json.loads((root / "indexes" / name).read_text()) for name in
                   ("shared-resources-api19-locations.json",
                    "integer-boxing-api19-locations.json")]
        queue = build_queue(corpus, indexes)
        self.assertEqual(len(queue["methods"]), 779)
        self.assertEqual(sum(item["source_mapping_status"] == "SOURCE_LOCATED"
                             for item in queue["methods"]), 7)
        self.assertFalse(queue["migration_authorized"])
        with self.assertRaisesRegex(ValueError, "duplicate source location"):
            build_queue(corpus, indexes + indexes[:1])

    def test_api19_scan_ignores_64_bit_abi_but_keeps_x86(self):
        elf32 = (ROOT / "App/Resources/libpocbridge.so").read_bytes()
        with tempfile.TemporaryDirectory() as tmp:
            apk = Path(tmp) / "mixed.apk"
            with zipfile.ZipFile(apk, "w") as archive:
                archive.writestr("lib/arm64-v8a/libgame.so", b"\x7fELF\x02" + b"\0" * 60)
                archive.writestr("lib/x86/libgame.so", elf32)
            self.assertEqual(
                {(item["kind"], item["canonical_name"]) for item in scan_apk(apk)},
                {(item["kind"], item["canonical_name"])
                 for item in _elf_refs(elf32, "lib/x86/libgame.so")},
            )

    def test_repository_binary_refs_and_apk_scan(self):
        dex = (ROOT / "App/Resources/classes.dex").read_bytes()
        elf = (ROOT / "App/Resources/libpocbridge.so").read_bytes()
        self.assertTrue(any(x["kind"] == "JAVA_METHOD" for x in _dex_refs(dex, "classes.dex")))
        self.assertTrue(any(x["kind"] == "JNI_BINDING" for x in _dex_refs(dex, "classes.dex")))
        self.assertFalse(any(x["canonical_name"].startswith("Lpoc/Bridge;->run")
                             for x in _dex_refs(dex, "classes.dex")))
        self.assertIsInstance(_elf_refs(elf, "lib/armeabi/libpocbridge.so"), list)
        with tempfile.TemporaryDirectory() as tmp:
            apk = Path(tmp) / "sample.apk"
            with zipfile.ZipFile(apk, "w") as archive:
                archive.writestr("classes.dex", dex)
                archive.writestr("lib/armeabi/libpocbridge.so", elf)
            records = scan_apk(apk)
            self.assertTrue(any(x["kind"] == "JAVA_METHOD" for x in records))
            self.assertEqual(len(apk_identity(apk)["sha256"]), 64)

    def test_elf_needed_and_import(self):
        blob = bytearray(512)
        blob[:6] = b"\x7fELF\x01\x01"
        struct.pack_into("<I", blob, 28, 52)
        struct.pack_into("<HH", blob, 42, 32, 2)
        struct.pack_into("<IIIIIIII", blob, 52, 1, 256, 0x1000, 0, 256, 256, 0, 0)
        struct.pack_into("<IIIIIIII", blob, 84, 2, 256, 0x1000, 0, 80, 80, 0, 0)
        dynamic = [(5, 0x1080), (10, 32), (1, 1), (6, 0x10a0), (11, 16), (4, 0x10d0), (0, 0)]
        for i, pair in enumerate(dynamic):
            struct.pack_into("<II", blob, 256 + i * 8, *pair)
        strings = b"\x00libandroid.so\x00ALooper_pollAll\x00"
        blob[384:384 + len(strings)] = strings
        struct.pack_into("<II", blob, 464, 1, 2)
        struct.pack_into("<IIIBBH", blob, 416 + 16, 15, 0, 0, 0, 0, 0)
        result = _elf_refs(blob, "libgame.so")
        self.assertEqual({(x["kind"], x["canonical_name"]) for x in result},
                         {("NATIVE_LIBRARY", "libandroid.so"), ("NATIVE_SYMBOL", "ALooper_pollAll")})

    def test_trace_identity_and_fail_closed_manifest(self):
        with tempfile.TemporaryDirectory() as tmp:
            root = Path(tmp)
            apk = root / "game.apk"
            apk.write_bytes(b"sample")
            identity = apk_identity(apk)
            events_file = root / "events.ndjson"
            event = {"kind": "JAVA_METHOD",
                     "canonical_name": "Landroid/app/Activity;->setContentView(I)V",
                     "caller": "Lgame/Main;->onCreate()V", "dex_pc": 18,
                     "opcode": "invoke-virtual", "method_idx": 42,
                     "resolved_callee": "Landroid/app/Activity;->setContentView(I)V"}
            events_file.write_text(json.dumps({"event_type": "LIFECYCLE", "phase": "activity_create"})
                                   + "\n" + json.dumps(event) + "\n", encoding="utf-8")
            evidence = {"variant": "TRACE", "instrumented": True, "role": "dependency_mapper",
                        "baseline": "android-4.4.4_r2", "image_sha256": "a" * 64,
                        "apk_sha256": identity["sha256"], "scenario": "cold_start",
                        "events_sha256": hashlib.sha256(events_file.read_bytes()).hexdigest(),
                        "observer_coverage": ["APP_DEX_TO_BOOT_METHOD_INVOKE"],
                        "observation_scope": "APP_TRIGGERED_OBSERVED_LOWER_BOUND",
                        "zygote_preload_sha256": "b" * 64,
                        "runtime_config": {"dalvik.vm.execution-mode": "int:portable"},
                        "may_authorize_pruning": False}
            evidence_file = root / "trace.json"
            evidence_file.write_text(json.dumps(evidence), encoding="utf-8")
            events = trace_events(events_file, evidence_file, identity)
            self.assertEqual(events[0]["lifecycle_phase"], "activity_create")
            book = build_book(identity, events, [], evidence)
            self.assertEqual(book["dependencies"][0]["confidence"], "OBSERVED_RUNTIME")
            self.assertEqual(book["trace_runs"][0]["events_sha256"], evidence["events_sha256"])
            validate_book(book)
            with self.assertRaises(ValueError):
                validate_book({**book, "trace_runs": []})
            merged = union_books([book, book])
            self.assertEqual(merged["run_count"], 2)
            self.assertEqual(len(merged["trace_runs"]), 2)
            validate_book(merged)
            self.assertEqual(len(corpus_union([book, book])["games"]), 1)
            with self.assertRaises(ValueError):
                union_books([book, {**book, "apk": {"sha256": "b" * 64}}])
            source = {"revision": "d" * 40, "source_sha256": "c" * 64,
                      "source_file_sha256": {"core/java/android/app/Activity.java": "c" * 64},
                      "entries": {event["canonical_name"]: {
                "source_files": ["core/java/android/app/Activity.java"],
                "required_symbols": ["setContentView"],
                "owner_cluster": "Framework", "semantic_cluster": "Framework.WindowContent",
                "source_repo": "platform/frameworks/base",
                "source_file": "core/java/android/app/Activity.java", "source_symbol": "setContentView"}}}
            self.assertEqual(manifests(book, source)["manifests"][0]["status"], "SOURCE_LOCATED")
            source["entries"][event["canonical_name"]]["closure_reviewed"] = True
            source["entries"][event["canonical_name"]]["closure_evidence"] = {
                "source_sha256": "c" * 64, "reviewed_by": "source-audit",
                "closure_notes": "Reviewed entry and callees"}
            self.assertEqual(close_entry(book["dependencies"][0], source)["status"], "SOURCE_CLOSED")
            source["source_sha256"] = "d" * 64
            self.assertEqual(close_entry(book["dependencies"][0], source)["status"], "SOURCE_LOCATED")
            source["source_sha256"] = "c" * 64
            cluster = manifests(book, source)["cluster_source_manifests"]["Framework.WindowContent"]
            self.assertEqual(cluster["status"], "SOURCE_CLOSED")
            self.assertFalse(cluster["migration_authorized"])
            source["cluster_reviews"] = {"Framework.WindowContent": {
                "closure_reviewed": True, "source_revision": "d" * 40,
                "entry_names": [event["canonical_name"]],
                "source_file_sha256": {"core/java/android/app/Activity.java": "c" * 64},
                "reviewed_dependency_edges": [], "unresolved_dependency_edges": [],
                "reviewed_by": "source-audit", "closure_notes": "Reviewed semantic owner"}}
            cluster = manifests(book, source)["cluster_source_manifests"]["Framework.WindowContent"]
            self.assertEqual(cluster["status"], "MIGRATION_AUTHORIZED")
            source["cluster_reviews"]["Framework.WindowContent"]["source_file_sha256"]["core/java/android/app/Activity.java"] = "e" * 64
            cluster = manifests(book, source)["cluster_source_manifests"]["Framework.WindowContent"]
            self.assertEqual(cluster["status"], "SOURCE_CLOSED")
            evidence["apk_sha256"] = "wrong"
            evidence_file.write_text(json.dumps(evidence), encoding="utf-8")
            with self.assertRaises(ValueError):
                trace_events(events_file, evidence_file, identity)

    def test_service_hle_requires_reviewed_source_boundary(self):
        entry = {"dependency_id": "SERVICE:1", "canonical_name": "android.view.IWindowSession#relayout",
                 "service_boundary": "HOST_SERVICE_HLE_BOUNDARY"}
        self.assertEqual(close_entry(entry, {"entries": {}})["status"], "BOUNDARY_CANDIDATE")
        source = {"source_files": ["platform/frameworks/base/core/java/android/view/IWindowSession.aidl"],
                  "required_symbols": ["relayout"], "service_boundaries": [entry["canonical_name"]],
                  "owner_cluster": "HostService", "source_repo": "platform/frameworks/base",
                  "source_file": "core/java/android/view/IWindowSession.aidl", "source_symbol": "relayout",
                  "migration_type": "SERVICE_HLE", "closure_reviewed": True,
                  "closure_evidence": {"source_sha256": "f" * 64, "reviewed_by": "source-audit",
                                       "closure_notes": "Service boundary reviewed"}}
        self.assertEqual(close_entry(entry, {"revision": "e" * 40, "source_sha256": "f" * 64,
                                             "entries": {entry["canonical_name"]: source}})["status"],
                         "BOUNDARY_CANDIDATE")
        source["service_contract"] = {
            "interface_descriptor": "android.view.IWindowSession",
            "transaction_code": 5, "request_schema": "relayout inputs",
            "response_schema": "relayout outputs", "callbacks": [],
            "lifecycle": "window open to close", "error_semantics": "RemoteException"}
        self.assertEqual(close_entry(entry, {"revision": "e" * 40, "source_sha256": "f" * 64,
                                             "entries": {entry["canonical_name"]: source}})["status"], "BOUNDARY")
