import unittest

from pair_concordance import compare


class PairConcordanceTest(unittest.TestCase):
    def test_same_inputs_and_runtime_states_do_not_claim_semantic_equivalence(self):
        pair = {"status": "BUILD_VERIFIED", "clean": {"image_sha256": "a"},
                "trace": {"image_sha256": "b"}}
        common = {"status": "PASS", "pair_status": "BUILD_VERIFIED",
                  "apk_sha256": "c", "scenario": "gameplay", "arch": "x86",
                  "actions_sha256": "d", "vm_config": {"dalvik.vm.execution-mode": "int:portable"},
                  "execution_mode": "int:portable", "jit_effective": "disabled_by_int_portable",
                  "zygote_preload": {"class_state": "PRELOADED_IN_ZYGOTE"},
                  "zygote_loaded_libraries": ["/system/lib/libdvm.so"],
                  "gpu_mode": "auto", "show_window": False, "accel": "tcg",
                  "steps": [{"label": "launch", "resumed": True, "focused": True,
                             "process": {"alive": True}}]}
        clean = dict(common, variant="CLEAN", image_sha256="a")
        trace = dict(common, variant="TRACE", image_sha256="b")
        result = compare(clean, trace, pair)
        self.assertEqual(result["status"], "STATE_CONCORDANT")
        self.assertFalse(result["semantic_equivalence_established"])
        self.assertFalse(result["pruning_authorized"])
        with self.assertRaisesRegex(ValueError, "configuration differs"):
            compare(clean, dict(trace, actions_sha256="wrong"), pair)
        with self.assertRaisesRegex(ValueError, "skin differs"):
            compare(dict(clean, skin="480x320"), dict(trace, skin="320x480"), pair)
        with self.assertRaisesRegex(ValueError, "force_stop_policy differs"):
            compare(dict(clean, force_stop_policy="home_pause_sigstop_before_kill"),
                    dict(trace, force_stop_policy="home_pause_3s_before_kill"), pair)
        with self.assertRaisesRegex(ValueError, "partition_size_mb differs"):
            compare(dict(clean, partition_size_mb=1024),
                    dict(trace, partition_size_mb=200), pair)
        with self.assertRaisesRegex(ValueError, "data_template_sha256 differs"):
            compare(dict(clean, data_template_sha256="a"),
                    dict(trace, data_template_sha256="b"), pair)


if __name__ == "__main__":
    unittest.main()
