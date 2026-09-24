#!/usr/bin/env python3
"""Compare physical and Simulator evidence without assigning causality."""

import json
import sys


ENV_PATHS = {
    "OS_VERSION_PARITY": ("os", "system_version"),
    "OS_BUILD_PARITY": ("os", "os_build"),
    "SIMULATOR_TARGET_OS_PARITY": ("simulator", "physical_target_os"),
    "SIMULATOR_RUNTIME_VERSION_PARITY": ("simulator", "runtime_version"),
    "SIMULATOR_OS_VERSION_PARITY": ("simulator", "os_version_parity"),
    "HW_MACHINE_PARITY": ("hardware", "hw_machine"),
    "ARCHITECTURE_PARITY": ("hardware", "architecture"),
    "RUNTIME_HOST_DIMENSIONS_PARITY": ("display", "runtime_host_width", "runtime_host_height"),
    "NATIVE_DIMENSIONS_PARITY": ("display", "native_width", "native_height"),
    "LOGICAL_DIMENSIONS_PARITY": ("display", "logical_width", "logical_height"),
    "SCALE_PARITY": ("display", "scale"),
    "NATIVE_SCALE_PARITY": ("display", "native_scale"),
    "MAXIMUM_FPS_PARITY": ("display", "maximum_fps"),
    "METAL_DEVICE_PARITY": ("graphics", "device_name"),
    "SIMULATOR_RUNTIME_REQUESTED_PARITY": ("simulator", "runtime_requested"),
    "SIMULATOR_RUNTIME_ACTUAL_PARITY": ("simulator", "runtime_actual"),
    "SIMULATOR_DEVICE_TYPE_PARITY": ("simulator", "device_type"),
    "BUNDLE_IDENTITY_PARITY": ("app", "bundle_id"),
    "ANGLE_VERSION_PARITY": ("build_environment", "angle_version"),
    "ANGLE_IDENTITY_PARITY": ("build_environment", "angle_identity"),
    "INTERPRETER_BUILD_IDENTITY_PARITY": ("build_environment", "interpreter_build_identity"),
    "XCODE_VERSION_PARITY": ("build_environment", "xcode"),
    "SDK_VERSION_PARITY": ("build_environment", "sdk_version"),
}


def env_of(report):
    for key in ("environment_start", "environment"):
        if isinstance(report.get(key), dict):
            return report[key]
    return report


def dig(obj, path):
    value = obj
    for key in path:
        if not isinstance(value, dict):
            return None
        value = value.get(key)
    return value


def identity(report, env):
    build = env.get("build_environment") if isinstance(env.get("build_environment"), dict) else {}
    direct = env.get("build") if isinstance(env.get("build"), dict) else {}
    return {
        "branch": report.get("branch") or dig(env, ("build", "branch")) or build.get("branch") or direct.get("branch"),
        "commit": report.get("commit") or dig(env, ("build", "commit")) or build.get("commit") or direct.get("commit"),
        "tree": report.get("tree") or dig(env, ("build", "tree")) or build.get("tree") or direct.get("tree"),
        "bundle_id": dig(env, ("app", "bundle_id")),
        "angle_identity": build.get("angle_identity"),
        "interpreter_build_identity": build.get("interpreter_build_identity"),
    }


def binary_map(report, env):
    values = report.get("binaries") or env.get("binaries") or []
    result = {}
    for item in values:
        if isinstance(item, dict) and item.get("role"):
            result[item["role"]] = {"uuid": item.get("uuid"), "sha256": item.get("sha256")}
    return result


def compare(label, left, right, differences):
    if left is None or right is None or left == "" or right == "":
        status = "UNKNOWN"
    else:
        status = "MATCH" if left == right else "DIFFERENT"
    if status != "MATCH":
        differences.append({"field": label, "physical": left, "simulator": right,
                            "parity": status, "causal_status": "OBSERVED_ONLY"})
    return status


def main():
    if len(sys.argv) != 3:
        print("usage: physical-environment-diff.py <physical.json> <simulator.json>", file=sys.stderr)
        return 2
    with open(sys.argv[1], encoding="utf-8") as handle:
        physical = json.load(handle)
    with open(sys.argv[2], encoding="utf-8") as handle:
        simulator = json.load(handle)
    pe, se = env_of(physical), env_of(simulator)
    differences, parity = [], {}
    pid, sid = identity(physical, pe), identity(simulator, se)
    for key in ("branch", "commit", "tree"):
        parity[key.upper() + "_PARITY"] = compare(key.upper() + "_PARITY", pid[key], sid[key], differences)
    apk_p = physical.get("apk_sha256") or physical.get("apk_sha256_actual")
    apk_s = simulator.get("apk_sha256") or simulator.get("apk_sha256_actual")
    parity["APK_PARITY"] = compare("APK_PARITY", apk_p, apk_s, differences)
    for name, path in ENV_PATHS.items():
        if name.endswith("DIMENSIONS_PARITY") and len(path) == 3:
            left = [dig(pe, (path[0], path[1])), dig(pe, (path[0], path[2]))]
            right = [dig(se, (path[0], path[1])), dig(se, (path[0], path[2]))]
        else:
            left, right = dig(pe, path), dig(se, path)
        parity[name] = compare(name, left, right, differences)
    physical_product = dig(pe, ("os", "system_version"))
    simulator_product = dig(se, ("simulator", "runtime_version"))
    parity["PRODUCT_VERSION_PARITY"] = (
        "EXACT" if physical_product == simulator_product == "27.0" else "MISMATCH")
    parity["BUILD_ARTIFACT_IDENTITY"] = (
        "EXACT" if all(parity.get(name) == "MATCH" for name in
                       ("COMMIT_PARITY", "TREE_PARITY", "APK_PARITY")) else "MISMATCH")
    pbin, sbin = binary_map(physical, pe), binary_map(simulator, se)
    binary_roles = {}
    for role in sorted(set(pbin) | set(sbin)):
        label = "BINARY_" + role.upper().replace("-", "_") + "_PARITY"
        binary_roles[role] = compare(label, pbin.get(role), sbin.get(role), differences)
    parity["EXECUTABLE_ANGLE_BINARY_PARITY"] = all(binary_roles.get(r) == "MATCH"
                                                   for r in ("executable", "libEGL", "libGLESv2"))
    if parity["EXECUTABLE_ANGLE_BINARY_PARITY"] is False:
        differences.append({"field": "EXECUTABLE_ANGLE_BINARY_PARITY",
                            "physical": {r: pbin.get(r) for r in ("executable", "libEGL", "libGLESv2")},
                            "simulator": {r: sbin.get(r) for r in ("executable", "libEGL", "libGLESv2")},
                            "parity": "DIFFERENT_OR_UNKNOWN", "causal_status": "OBSERVED_ONLY"})
    report = {
        "schema": "agr.physical-environment-diff.v2",
        "root_cause": None,
        "parity": parity,
        "physical_product_version": physical_product,
        "simulator_product_version": simulator_product,
        "product_version_parity": parity["PRODUCT_VERSION_PARITY"],
        "difference_count": len(differences),
        "differences": differences,
    }
    json.dump(report, sys.stdout, indent=2, sort_keys=True)
    sys.stdout.write("\n")
    return 0


if __name__ == "__main__":
    sys.exit(main())
