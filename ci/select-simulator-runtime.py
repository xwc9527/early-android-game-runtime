#!/usr/bin/env python3
"""Choose the closest installed Simulator runtime to the physical iOS target.

AGR_SIMULATOR_RUNTIME, when set, must already be installed. A missing
requested runtime exits SIMULATOR_RUNTIME_UNAVAILABLE and does not substitute
another runtime. When unset, selection prefers the physical target minor, then
the closest runtime on the same major, then the newest installed iOS runtime.
"""

import json
import os
import subprocess
import sys

DEVICE_TYPE = "com.apple.CoreSimulator.SimDeviceType.iPhone-16-Pro"
PHYSICAL_TARGET = (26, 3, 1)


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


def version_distance(runtime):
    value = (version_key(runtime) + [0, 0, 0])[:3]
    return (abs(value[0] - PHYSICAL_TARGET[0]) * 1000000 +
            abs(value[1] - PHYSICAL_TARGET[1]) * 1000 +
            abs(value[2] - PHYSICAL_TARGET[2]))


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
        same_minor = [item for item in available
                      if (version_key(item) + [0, 0])[:2] == list(PHYSICAL_TARGET[:2])]
        same_major = [item for item in available
                      if (version_key(item) + [0])[:1] == [PHYSICAL_TARGET[0]]]
        if same_minor:
            runtime = sorted(same_minor,
                             key=lambda item: (abs((version_key(item) + [0, 0, 0])[2] - PHYSICAL_TARGET[2]),
                                               version_key(item)))[0]
            parity = "SAME_26_3_MINOR"
        elif same_major:
            runtime = sorted(same_major, key=lambda item: (version_distance(item),
                                                            tuple(-part for part in version_key(item))))[0]
            parity = "SAME_26_MAJOR_CLOSEST"
        else:
            runtime = sorted(available, key=lambda item: (version_distance(item), version_key(item)))[0]
            parity = "VERSION_DIFFERENT_FALLBACK"
        runtime_id = runtime["identifier"]
    if requested:
        selected = (version_key(runtime) + [0, 0, 0])[:3]
        parity = "SAME_26_3_MINOR" if selected[:2] == list(PHYSICAL_TARGET[:2]) else (
            "SAME_26_MAJOR_CLOSEST" if selected[0] == PHYSICAL_TARGET[0] else "VERSION_DIFFERENT_FALLBACK")
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
        "physical_target_os": "26.3.1 (a)",
        "simulator_runtime_requested": runtime_id,
        "simulator_runtime_actual": runtime_id,
        "simulator_runtime_version": runtime.get("version"),
        "os_version_parity": parity,
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
