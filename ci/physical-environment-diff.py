#!/usr/bin/env python3
"""Report observed environment differences. This does not assign a root cause."""

import json
import sys


KEYS = (
    ("target_type", ("target_type",)),
    ("system_version", ("os", "system_version")),
    ("os_build", ("os", "os_build")),
    ("hw_machine", ("hardware", "hw_machine")),
    ("architecture", ("hardware", "architecture")),
    ("runtime_host_width", ("display", "runtime_host_width")),
    ("runtime_host_height", ("display", "runtime_host_height")),
    ("native_width", ("display", "native_width")),
    ("native_height", ("display", "native_height")),
    ("metal_device", ("graphics", "device_name")),
    ("thermal_state", ("power", "thermal_state")),
    ("low_power_mode_enabled", ("power", "low_power_mode_enabled")),
)


def dig(obj, path):
    current = obj
    for key in path:
        if not isinstance(current, dict) or key not in current:
            return None
        current = current[key]
    return current


def binaries(obj):
    found = {}
    for item in obj.get("binaries") or []:
        if isinstance(item, dict) and item.get("role"):
            found[item["role"]] = {"uuid": item.get("uuid"), "sha256": item.get("sha256")}
    return found


def main():
    if len(sys.argv) != 3:
        print("usage: physical-environment-diff.py <physical.json> <simulator.json>", file=sys.stderr)
        return 2
    with open(sys.argv[1], encoding="utf-8") as handle:
        physical = json.load(handle)
    with open(sys.argv[2], encoding="utf-8") as handle:
        simulator = json.load(handle)
    physical_env = physical.get("environment") if isinstance(physical.get("environment"), dict) else physical
    simulator_env = simulator.get("environment") if isinstance(simulator.get("environment"), dict) else simulator
    differences = []
    for name, path in KEYS:
        left = dig(physical_env, path)
        right = dig(simulator_env, path)
        if left != right:
            differences.append({"field": name, "physical": left, "simulator": right, "causal_status": "OBSERVED"})
    left_bins = binaries(physical_env)
    right_bins = binaries(simulator_env)
    for role in sorted(set(left_bins) | set(right_bins)):
        if left_bins.get(role) != right_bins.get(role):
            differences.append({
                "field": "binary." + role,
                "physical": left_bins.get(role),
                "simulator": right_bins.get(role),
                "causal_status": "OBSERVED",
            })
    report = {
        "schema": "agr.physical-environment-diff.v1",
        "root_cause": None,
        "difference_count": len(differences),
        "differences": differences,
    }
    json.dump(report, sys.stdout, indent=2)
    sys.stdout.write("\n")
    return 0


if __name__ == "__main__":
    sys.exit(main())
