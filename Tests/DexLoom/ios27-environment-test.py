#!/usr/bin/env python3
"""Prevent fallback to another iOS runtime or an obsolete device type."""

import importlib.util
from pathlib import Path
import unittest


PATH = Path(__file__).resolve().parents[2] / "ci" / "select-simulator-runtime.py"
SPEC = importlib.util.spec_from_file_location("agr_ios27_selector", PATH)
SELECTOR = importlib.util.module_from_spec(SPEC)
SPEC.loader.exec_module(SELECTOR)
PARITY_SPEC = importlib.util.spec_from_file_location(
    "agr_ios27_parity", PATH.parent / "check-ios27-parity.py")
PARITY = importlib.util.module_from_spec(PARITY_SPEC)
PARITY_SPEC.loader.exec_module(PARITY)


class ExactBaseline(unittest.TestCase):
    def setUp(self):
        self.runtime = {"identifier": SELECTOR.RUNTIME_ID, "version": "27.0",
                        "isAvailable": True}
        self.device = {"identifier": "com.apple.CoreSimulator.SimDeviceType.iPhone-17",
                       "name": "iPhone 17"}

    def test_exact_runtime_and_available_iphone(self):
        runtime, device, existing = SELECTOR.select(
            [self.runtime], [self.device], {SELECTOR.RUNTIME_ID: []})
        self.assertEqual(runtime["version"], "27.0")
        self.assertEqual(device["name"], "iPhone 17")
        self.assertIsNone(existing)

    def test_no_runtime_fallback(self):
        for version in ("26.3", "27.1", "27.2"):
            with self.subTest(version=version), self.assertRaises(ValueError):
                SELECTOR.select([{**self.runtime, "version": version}],
                                [self.device], {})
        with self.assertRaises(ValueError):
            SELECTOR.select([{**self.runtime, "isAvailable": False}],
                            [self.device], {})

    def test_no_requested_override(self):
        with self.assertRaises(ValueError):
            SELECTOR.select([self.runtime], [self.device], {},
                            "com.apple.CoreSimulator.SimRuntime.iOS-27-1")

    def test_available_phone_is_discovered(self):
        runtime, device, existing = SELECTOR.select(
            [self.runtime], [{"identifier": "com.apple.CoreSimulator.SimDeviceType.iPad-Pro",
                              "name": "iPad Pro"}, self.device],
            {SELECTOR.RUNTIME_ID: [{"deviceTypeIdentifier": self.device["identifier"],
                                    "udid": "EXACT-DEVICE"}]})
        self.assertEqual(existing["udid"], "EXACT-DEVICE")

    def test_build_and_physical_parity_are_separate(self):
        common = {"commit": "c", "tree": "t", "apk_sha256": "a",
                  "xcode_version": "Xcode 27.0", "xcode_build": "17A", "sdk_version": "27.0"}
        simulator = {**common, "simulator_runtime_version": "27.0",
                     "simulator_runtime_actual": SELECTOR.RUNTIME_ID}
        self.assertEqual(PARITY.compare(simulator, common)["product_version_parity"],
                         "PENDING_PHYSICAL")
        exact = PARITY.compare(simulator, common, {"product_version": "27.0"})
        self.assertTrue(exact["baseline_valid"])
        self.assertEqual(exact["product_version_parity"], "EXACT")
        self.assertFalse(PARITY.compare(simulator, {**common, "tree": "other"})["baseline_valid"])


if __name__ == "__main__":
    unittest.main()
