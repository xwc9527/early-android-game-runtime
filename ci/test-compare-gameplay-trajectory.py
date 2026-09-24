#!/usr/bin/env python3
import importlib.util
import pathlib
import sys

HERE = pathlib.Path(__file__).resolve().parent
sys.path.insert(0, str(HERE))
spec = importlib.util.spec_from_file_location("compare", HERE / "compare-gameplay-trajectory.py")
mod = importlib.util.module_from_spec(spec)
spec.loader.exec_module(mod)
from gameplay_trajectory import APK_SHA256, EXECUTED_SCHEMA

canonical = {"steps": [{"id": "cold", "action": None},
                       {"id": "begin", "action": {"type": "tap"}},
                       {"id": "fire", "action": {"type": "tap"}}]}


def record(platform, states):
    identity = {"apk_sha256": APK_SHA256}
    if platform == "android-api19":
        identity.update(android_release="4.4.4", android_api=19)
    else:
        identity.update(ios_product_version="27.0", simulator_runtime_version="27.0")
    return {"schema": EXECUTED_SCHEMA, "platform": platform, "identity": identity,
            "steps": [{"id": name, "before": {"state": {"observable_state": before}},
                       "after": {"state": {"observable_state": after}},
                       "input": {"delivered": True, "consumed": True}, "runtime_failure": None}
                      for (name, before, after) in states]}


android = record("android-api19", [("cold", "launch", "paused"),
                                   ("begin", "paused", "running"),
                                   ("fire", "running", "shot")])
agr = record("agr-ios-simulator", [("cold", "launch", "paused"),
                                   ("begin", "paused", "running"),
                                   ("fire", "running", "running")])
result = mod.compare(canonical, android, agr)
assert result["last_matching_step"] == "begin", result
assert result["first_divergent_step"] == "fire", result
assert result["classification"] == "STATE_DIVERGENCE", result
assert "root cause" not in str(result).lower()

agr["identity"]["ios_product_version"] = "26.3"
assert mod.compare(canonical, android, agr)["trajectory_result"] == "ENVIRONMENT_MISMATCH"
agr["identity"]["ios_product_version"] = "27.0"
agr["steps"][2]["after"]["state"].pop("observable_state")
assert mod.compare(canonical, android, agr)["trajectory_result"] == "INSUFFICIENT_EVIDENCE"
print("gameplay trajectory comparator contract PASS")
