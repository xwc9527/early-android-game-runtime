import json
import tempfile
import unittest
from pathlib import Path

from lab import assert_not_oracle, describe, ensure_layout
from mapper import build_book, write_book
from source_closure import close_entry


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

    def test_layout_keeps_clean_and_trace_apart(self):
        with tempfile.TemporaryDirectory() as tmp:
            document = ensure_layout(tmp)
            self.assertFalse(document["images_provisioned"])
            self.assertTrue((Path(tmp) / "clean-image").is_dir())
            self.assertTrue((Path(tmp) / "trace-image").is_dir())
            self.assertNotEqual(document["clean"]["role"], document["trace"]["role"])

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
        self.assertEqual(closed["status"], "SOURCE_CLOSED")
        self.assertEqual(closed["migration_type"], "SOURCE_PORT")
        self.assertNotIn("PhoneWindow", json.dumps(closed))

    def test_service_boundary_stops(self):
        manifest = close_entry({
            "dependency_id": "SERVICE:relayout",
            "canonical_name": "android.view.IWindowSession#relayout",
            "service_boundary": "HOST_SERVICE_HLE_BOUNDARY",
        }, {"entries": {}})
        self.assertEqual(manifest["status"], "BOUNDARY")
        self.assertEqual(manifest["migration_type"], "SERVICE_HLE")

    def test_original_implementation_is_rejected(self):
        with self.assertRaises(ValueError):
            close_entry({
                "dependency_id": "JAVA_METHOD:abc",
                "canonical_name": "Activity.setContentView(I)V",
            }, {"entries": {}}, migration_type="ORIGINAL_IMPLEMENTATION")


if __name__ == "__main__":
    unittest.main()
