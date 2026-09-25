import json
import tempfile
import unittest
from pathlib import Path

from rebuild_trace_sequences import rebuild, sha256


class RebuildTraceSequencesTest(unittest.TestCase):
    def test_rebuild_requires_original_hashes_and_restores_sequence(self):
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            direct = root / "trace-all.log"
            direct.write_text(
                "AGRTRACE|v2|7|8|1|Lgame/A;->a()V|0|110|1|"
                "Ljava/lang/System;->currentTimeMillis()J|"
                "Ljava/lang/System;->currentTimeMillis()J\n")
            old_events = root / "old.ndjson"
            old_events.write_text('{"kind":"JAVA_METHOD"}\n')
            evidence = root / "trace-run.json"
            evidence.write_text(json.dumps({
                "apk_sha256": "a", "process_ids": [7],
                "events_sha256": sha256(old_events),
                "direct_trace_sha256": {direct.name: sha256(direct)},
            }))
            probe = root / "probe.json"
            probe.write_text(json.dumps({"status": "PASS", "apk_sha256": "a",
                                         "event_count": 1}))
            events_out = root / "events-seq.ndjson"
            evidence_out = root / "trace-run-seq.json"
            self.assertEqual(rebuild(direct, old_events, evidence, probe,
                                     events_out, evidence_out), 1)
            self.assertEqual(json.loads(events_out.read_text())["sequence"], 1)
            self.assertEqual(json.loads(evidence_out.read_text())
                             ["reprocessing"]["original_events_sha256"],
                             sha256(old_events))
            direct.write_text(direct.read_text() + "extra")
            with self.assertRaisesRegex(ValueError, "direct TRACE file hash"):
                rebuild(direct, old_events, evidence, probe,
                        events_out, evidence_out)


if __name__ == "__main__":
    unittest.main()
