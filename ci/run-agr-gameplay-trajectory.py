#!/usr/bin/env python3
"""Test-only iOS Simulator replay through external HID -> UIKit -> AGR input."""

import argparse
import json
import pathlib
import shutil
import struct
import subprocess
import time

from gameplay_trajectory import APK_SHA256, EXECUTED_SCHEMA, load_canonical, map_action

BUNDLE = "dev.agr.simulator"


def run(*command, timeout=40):
    result = subprocess.run(command, capture_output=True, text=True, timeout=timeout)
    if result.returncode:
        raise RuntimeError(f"{command}: exit {result.returncode}: {result.stderr}")
    return result.stdout.strip()


def read_state(path, min_vsync=1, timeout=30):
    deadline = time.monotonic() + timeout
    while time.monotonic() < deadline:
        try:
            state = json.loads(path.read_text(encoding="utf-8"))
            if state.get("schema") == "agr.gameplay-host-checkpoint.v1" and state.get("host_vsync", 0) >= min_vsync:
                return state
        except (OSError, ValueError):
            pass
        time.sleep(0.25)
    raise RuntimeError(f"AGR host checkpoint did not advance to vsync {min_vsync}")


def screenshot(device, out, label):
    path = out / f"{label}.png"
    run("xcrun", "simctl", "io", device, "screenshot", str(path), timeout=30)
    payload = path.read_bytes()
    if not payload.startswith(b"\x89PNG\r\n\x1a\n"):
        raise RuntimeError(f"invalid Simulator screenshot: {path}")
    width, height = struct.unpack(">II", payload[16:24])
    return {"screenshot": path.name, "screenshot_dimensions": {"width": width, "height": height}}


def mapped_viewport(state, requested):
    if requested is None or requested.get("type") == "keyevent":
        return None
    if requested.get("coordinate_space") != "normalized_root_view":
        raise ValueError("content viewport is not measured by the current iOS host shell")
    bounds = state["ui_touch_view_bounds"]
    return {"coordinate_space": "normalized_root_view", "x": round(bounds["x"]),
            "y": round(bounds["y"]), "width": round(bounds["width"]),
            "height": round(bounds["height"]), "measurement_source": "UIKit AGRPhysicalTouchView.bounds"}


def inject(device, action):
    if action is None:
        return None
    kind = action["type"]
    if kind in ("tap", "long_press"):
        args = ["idb", "ui", "tap", str(action["x"]), str(action["y"])]
        if kind == "long_press":
            args += ["--duration", str(action.get("duration_ms", 600) / 1000)]
    elif kind == "swipe":
        args = ["idb", "ui", "swipe", *(str(action[key]) for key in ("x0", "y0", "x1", "y1")),
                "--duration", str(action.get("duration_ms", 500) / 1000)]
    else:
        raise ValueError(f"no host HID mapping for canonical action {kind}")
    return run(*args, "--udid", device, timeout=35)


def snapshot(device, docs, out, label, previous_vsync):
    state = read_state(docs / "agr-gameplay-state.json", min_vsync=previous_vsync)
    image = screenshot(device, out, label)
    return {"screenshot": image["screenshot"], "screenshot_dimensions": image["screenshot_dimensions"],
            "state": {"observable_state": None, "activity_stage": state["activity_stage"],
                      "surface": state["surface"], "host_surface_submissions": state["host_surface_submissions"],
                      "host_vsync": state["host_vsync"], "instructions": state["instructions"],
                      "input_dispatched": state["input_dispatched"], "input_consumed": state["input_consumed"]},
            "host_checkpoint": f"{label}-state.json", "_state": state}


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--device", required=True)
    parser.add_argument("--canonical", type=pathlib.Path, required=True)
    parser.add_argument("--app", type=pathlib.Path, required=True)
    parser.add_argument("--out", type=pathlib.Path, required=True)
    args = parser.parse_args()
    canonical = load_canonical(args.canonical)
    args.out.mkdir(parents=True, exist_ok=True)
    subprocess.run(["xcrun", "simctl", "uninstall", args.device, BUNDLE],
                   capture_output=True, text=True, timeout=45)
    run("xcrun", "simctl", "install", args.device, str(args.app), timeout=90)
    data = pathlib.Path(run("xcrun", "simctl", "get_app_container", args.device, BUNDLE, "data"))
    docs = data / "Documents"
    run("xcrun", "simctl", "launch", args.device, BUNDLE, "--args", "--gameplay-trajectory", timeout=45)
    initial = read_state(docs / "agr-gameplay-state.json")
    env = initial["environment"]
    product_version = env.get("os", {}).get("system_version")
    runtime_version = env.get("simulator", {}).get("runtime_version")
    if product_version != "27.0" or runtime_version != "27.0":
        raise RuntimeError(f"iOS 27.0 baseline mismatch: product={product_version} runtime={runtime_version}")
    if initial["apk_sha256"] != APK_SHA256:
        raise RuntimeError("AGR loaded a different APK")
    identity = {"apk_sha256": APK_SHA256, "agr_commit": initial["commit"],
                "agr_tree": initial["tree"], "ios_product_version": product_version,
                "simulator_runtime_version": runtime_version, "run_id": initial["run_id"],
                "pid": initial["pid"], "xcode": run("xcodebuild", "-version"), "environment": env}
    executed = {"schema": EXECUTED_SCHEMA, "platform": "agr-ios-simulator",
                "identity": identity, "steps": []}
    for index, specification in enumerate(canonical["steps"]):
        label = f"step-{index:02d}"
        before = snapshot(args.device, docs, args.out, label + "-before", 1)
        state_before = before.pop("_state")
        (args.out / f"{label}-before-state.json").write_text(json.dumps(state_before, indent=2) + "\n")
        requested = specification.get("action")
        viewport = mapped_viewport(state_before, requested)
        actual = map_action(requested, viewport) if requested else None
        result = inject(args.device, actual)
        time.sleep(specification["wait_ms"] / 1000)
        after = snapshot(args.device, docs, args.out, label + "-after",
                         state_before["host_vsync"] + 1)
        state_after = after.pop("_state")
        (args.out / f"{label}-after-state.json").write_text(json.dumps(state_after, indent=2) + "\n")
        scale = state_after["environment"]["display"]["native_scale"]
        if viewport:
            after["content_bounds"] = {"x": round(viewport["x"] * scale),
                                       "y": round(viewport["y"] * scale),
                                       "width": round(viewport["width"] * scale),
                                       "height": round(viewport["height"] * scale)}
        dispatched = state_after["input_dispatched"] - state_before["input_dispatched"]
        consumed = state_after["input_consumed"] - state_before["input_consumed"]
        row = {"id": specification["id"], "action_requested": requested,
               "action_actual": actual, "before": before, "after": after,
               "input": {"host_injection_accepted": result is not None if requested else None,
                         "delivered": dispatched > 0 if requested else None,
                         "consumed": consumed > 0 if requested else None,
                         "dispatch_delta": dispatched, "consume_delta": consumed,
                         "last_touch": state_after.get("last_touch")},
               "runtime_failure": state_after.get("runtime_failure") or state_after.get("vm_error") or None}
        executed["steps"].append(row)
        (args.out / "agr-executed-trajectory.json").write_text(json.dumps(executed, indent=2) + "\n")
        if row["runtime_failure"]:
            break
    (docs / "agr-gameplay-finalize.flag").write_text("finalize\n")
    for _ in range(40):
        if (docs / "agr-current-runtime.json").exists():
            for name in ("agr-current-manifest.json", "agr-current-run.json", "agr-current-runtime.json",
                         "agr-current-trace.ndjson", "manual-replay.json"):
                source = docs / name
                if source.exists():
                    shutil.copyfile(source, args.out / name)
            break
        time.sleep(0.25)
    if len(executed["steps"]) != len(canonical["steps"]):
        raise RuntimeError("AGR replay terminated before the final canonical checkpoint")
    print(f"AGR executed {len(executed['steps'])} canonical steps through UIKit HID; run {initial['run_id']}")


if __name__ == "__main__":
    main()
