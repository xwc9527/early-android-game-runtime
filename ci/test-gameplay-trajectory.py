#!/usr/bin/env python3
import importlib.util
import pathlib
import json
from unittest.mock import patch

ROOT = pathlib.Path(__file__).resolve().parent
spec = importlib.util.spec_from_file_location("gameplay_trajectory", ROOT / "gameplay_trajectory.py")
mod = importlib.util.module_from_spec(spec)
spec.loader.exec_module(mod)

base = {"schema": mod.CANONICAL_SCHEMA,
        "game": {"package": "org.jfedor.frozenbubble", "version_code": 8,
                 "version_name": "1.7", "apk_sha256": mod.APK_SHA256},
        "reference": {"android_api": 19, "android_release": "4.4.4"},
        "steps": [{"id": "cold", "action": None, "wait_ms": 1000},
                  {"id": "tap", "action": {"type": "tap", "coordinate_space": "normalized_root_view",
                                           "x": 0.5, "y": 0.75}, "wait_ms": 500}]}
with patch.object(pathlib.Path, "read_text", return_value=json.dumps(base)):
    assert len(mod.load_canonical("canonical.json")["steps"]) == 2
mapped = mod.map_action(base["steps"][1]["action"],
                        {"coordinate_space": "normalized_root_view", "x": 10,
                         "y": 20, "width": 480, "height": 800})
assert mapped["x"] == 250 and mapped["y"] == 619, mapped
base["steps"][1]["action"]["x"] = 240
with patch.object(pathlib.Path, "read_text", return_value=json.dumps(base)):
    try:
        mod.load_canonical("canonical.json")
    except ValueError:
        pass
    else:
        raise AssertionError("raw pixel coordinate accepted")
print("gameplay trajectory contract PASS")
