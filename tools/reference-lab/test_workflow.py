import hashlib
import json
import struct
import tempfile
import unittest
import zipfile
from pathlib import Path

from mapper import build_book, corpus_union, union_books
from source_closure import close_entry
from static_scan import _dex_refs, _elf_refs, apk_identity, scan_apk
from workflow import manifests, trace_events

ROOT = Path(__file__).resolve().parents[2]


class WorkflowTest(unittest.TestCase):
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
                        "events_sha256": hashlib.sha256(events_file.read_bytes()).hexdigest()}
            evidence_file = root / "trace.json"
            evidence_file.write_text(json.dumps(evidence), encoding="utf-8")
            events = trace_events(events_file, evidence_file, identity)
            self.assertEqual(events[0]["lifecycle_phase"], "activity_create")
            book = build_book(identity, events, [])
            self.assertEqual(book["dependencies"][0]["confidence"], "OBSERVED_RUNTIME")
            self.assertEqual(union_books([book, book])["run_count"], 2)
            self.assertEqual(len(corpus_union([book, book])["games"]), 1)
            with self.assertRaises(ValueError):
                union_books([book, {**book, "apk": {"sha256": "b" * 64}}])
            source = {"revision": "d" * 40, "source_sha256": "c" * 64,
                      "entries": {event["canonical_name"]: {
                "source_files": ["platform/frameworks/base/core/java/android/app/Activity.java"],
                "required_symbols": ["setContentView"],
                "owner_cluster": "Framework", "source_repo": "platform/frameworks/base",
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
            self.assertIn("Framework", manifests(book, source)["cluster_source_manifests"])
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
                                             "entries": {entry["canonical_name"]: source}})["status"], "BOUNDARY")
