#!/usr/bin/env python3
"""Choose one installed Simulator runtime and an iPhone 16 Pro device.

AGR_SIMULATOR_RUNTIME, when set, must already be installed. A missing
requested runtime exits SIMULATOR_RUNTIME_UNAVAILABLE and does not substitute
another runtime. When it is unset, the newest available iOS runtime that can
host iPhone 16 Pro is both the requested and the actual runtime.
"""

import json
import os
import subprocess
import sys

DEVICE_TYPE = "com.apple.CoreSimulator.SimDeviceType.iPhone-16-Pro"


def simctl_json(kind):
    raw = subprocess.check_output(["xcrun", "simctl", "list", kind, "-j"], text=True)
    return json.loads(raw)


def version_key(runtime):
    parts = []
    for piece in str(runtime.get("version") or "0").split("."):
        try:
            parts.append(int(piece))
        except ValueError:
            parts.append(0)
    return parts


def main():
    if len(sys.argv) != 2:
        print("usage: select-simulator-runtime.py <ci-environment.json>", file=sys.stderr)
        return 2
    requested = os.environ.get("AGR_SIMULATOR_RUNTIME", "").strip()
    runtimes = simctl_json("runtimes").get("runtimes", [])
    available = [
        runtime for runtime in runtimes
        if runtime.get("isAvailable") and str(runtime.get("identifier", "")).startswith("com.apple.CoreSimulator.SimRuntime.iOS-")
    ]
    if requested:
        chosen = [runtime for runtime in available if runtime.get("identifier") == requested]
        if not chosen:
            print(f"SIMULATOR_RUNTIME_UNAVAILABLE {requested}", file=sys.stderr)
            return 3
        runtime = chosen[0]
        runtime_id = requested
    else:
        if not available:
            print("SIMULATOR_RUNTIME_UNAVAILABLE", file=sys.stderr)
            return 3
        runtime = sorted(available, key=version_key)[-1]
        runtime_id = runtime["identifier"]
    device_types = simctl_json("devicetypes").get("devicetypes", [])
    if not any(item.get("identifier") == DEVICE_TYPE for item in device_types):
        print(f"SIMULATOR_RUNTIME_UNAVAILABLE {DEVICE_TYPE}", file=sys.stderr)
        return 3
    devices = simctl_json("devices").get("devices", {}).get(runtime_id, [])
    found = [
        device for device in devices
        if device.get("isAvailable", True) and device.get("deviceTypeIdentifier") == DEVICE_TYPE
    ]
    payload = {
        "simulator_runtime_requested": runtime_id,
        "simulator_runtime_actual": runtime_id,
        "simulator_runtime_version": runtime.get("version"),
        "simulator_runtime_name": runtime.get("name"),
        "simulator_device_type_requested": DEVICE_TYPE,
        "simulator_device_type_actual": DEVICE_TYPE,
        "udid": found[0]["udid"] if found else "",
        "create_device": not found,
    }
    with open(sys.argv[1], "w", encoding="utf-8") as handle:
        json.dump(payload, handle, indent=2)
        handle.write("\n")
    if payload["udid"]:
        print(payload["udid"])
    else:
        print("CREATE")
    return 0


if __name__ == "__main__":
    sys.exit(main())
