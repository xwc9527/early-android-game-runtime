#!/usr/bin/env python3
"""Fail when production Runtime grows Android Java/Framework HLE outside the freeze."""

import argparse
import json
import pathlib
import re
import sys

ROOT = pathlib.Path(__file__).resolve().parents[1]
BASELINE_PATH = ROOT / "ci/governance/java-architecture-baseline.json"
OWNER_PATH = ROOT / "ci/governance/java-public-owner.json"
ROLES_PATH = ROOT / "ci/governance/java-component-roles.json"

SCAN_ROOTS = (
    ROOT / "Runtime/DexLoom",
    ROOT / "Runtime/GuestRuntime",
)
PRODUCTION_LISTS = (
    ROOT / "scripts/build-iphoneos.sh",
    ROOT / "scripts/build-and-run-simulator.sh",
)
PUBLIC_DESC = re.compile(r'"(L(?:android|java|javax|dalvik)/[^"]*;)"')
GAME_TOKEN = re.compile(
    r"frozen[\s._-]*bubble|kung[\s._-]*foo|pixel[\s._-]*dungeon|"
    r"org\.jfedor|com\.example\.frozen|apk[_-]?hash",
    re.IGNORECASE,
)
FIXED_DEFINE = re.compile(
    r"#define\s+(DX_MAX_(?:DEX_FILES|JOBJECT\w*|JCLASS\w*|JNI\w*|GLOBAL_REF\w*|"
    r"LOCAL_REF\w*|FIELD_ID\w*|METHOD_ID\w*|JAVA_ARRAY\w*))\s+(\d+)"
)
FIXED_ARRAY = re.compile(
    r"\b(jobject|jclass|jfieldID|jmethodID|JNIEnv\s*\*)\s+\**(\w+)\s*\[(\d+)\]"
)
APP_PACKAGE = re.compile(r'"(L(?!android/|java/|javax/|dalvik/|kotlin/|androidx/)[A-Za-z0-9_$/]+;)"')


def rel(path: pathlib.Path) -> str:
    return str(path.relative_to(ROOT))


def source_files():
    files = []
    for root in SCAN_ROOTS:
        if not root.exists():
            continue
        for path in root.rglob("*"):
            if path.suffix in {".c", ".h", ".m", ".mm", ".cpp"} and path.is_file():
                files.append(path)
    return files


def scan():
    public = []
    packages = []
    games = []
    fixed = []
    for path in source_files():
        text = path.read_text(encoding="utf-8", errors="replace")
        name = rel(path)
        for match in PUBLIC_DESC.finditer(text):
            public.append({"file": name, "descriptor": match.group(1)})
        for match in APP_PACKAGE.finditer(text):
            packages.append({"file": name, "descriptor": match.group(1)})
        for line_no, line in enumerate(text.splitlines(), 1):
            if GAME_TOKEN.search(line):
                games.append({"file": name, "line": line_no, "text": line.strip()[:180]})
            define = FIXED_DEFINE.search(line)
            if define:
                fixed.append({"file": name, "name": define.group(1), "capacity": int(define.group(2))})
            array = FIXED_ARRAY.search(line)
            if array:
                fixed.append({
                    "file": name,
                    "name": f"{array.group(1)} {array.group(2)}",
                    "capacity": int(array.group(3)),
                })
    return {
        "public_descriptors": {(item["file"], item["descriptor"]) for item in public},
        "app_packages": {(item["file"], item["descriptor"]) for item in packages},
        "game_lines": {(item["file"], item["text"]) for item in games},
        "fixed_tables": {(item["file"], item["name"], item["capacity"]) for item in fixed},
    }


def as_records(snapshot):
    return {
        "public_descriptors": [{"file": a, "descriptor": b} for a, b in snapshot["public_descriptors"]],
        "app_packages": [{"file": a, "descriptor": b} for a, b in snapshot["app_packages"]],
        "game_lines": [{"file": a, "text": b} for a, b in snapshot["game_lines"]],
        "fixed_tables": [{"file": a, "name": b, "capacity": c} for a, b, c in snapshot["fixed_tables"]],
    }


def load_baseline():
    document = json.loads(BASELINE_PATH.read_text(encoding="utf-8"))
    return {
        "public_descriptors": {(item["file"], item["descriptor"]) for item in document["public_descriptors"]},
        "app_packages": {(item["file"], item["descriptor"]) for item in document["app_packages"]},
        "game_lines": {(item["file"], item["text"]) for item in document["game_lines"]},
        "fixed_tables": {(item["file"], item["name"]): item["capacity"] for item in document["fixed_tables"]},
    }


def owner_symbols():
    if not OWNER_PATH.is_file():
        return set()
    document = json.loads(OWNER_PATH.read_text(encoding="utf-8"))
    symbols = set()
    for entry in document.get("symbols", []):
        symbol = entry.get("symbol")
        if symbol:
            symbols.add(symbol)
    return symbols


def check_roles(errors):
    if not ROLES_PATH.is_file():
        errors.append("missing java-component-roles.json")
        return
    roles = json.loads(ROLES_PATH.read_text(encoding="utf-8"))
    expected = {
        "Runtime/DexLoom/game_dex_runner.c": "LEGACY_BOOTSTRAP",
        "Runtime/DexLoom/AndroidMini/dx_android_framework.c": "LEGACY_REFERENCE",
    }
    for path, role in expected.items():
        if roles.get("components", {}).get(path) != role:
            errors.append(f"{path} role must be {role}")
        file_path = ROOT / path
        if not file_path.is_file() or role not in file_path.read_text(encoding="utf-8", errors="replace"):
            errors.append(f"{path} must contain marker {role}")
    if roles.get("components", {}).get("Runtime/DexLoom/AndroidMini/dx_android_framework.c") == "LEGACY_REFERENCE":
        for listing in PRODUCTION_LISTS:
            if not listing.is_file():
                continue
            text = listing.read_text(encoding="utf-8", errors="replace")
            if "dx_android_framework.c" in text:
                errors.append(f"LEGACY_REFERENCE is linked by {rel(listing)}")


def check(snapshot, baseline):
    errors = []
    check_roles(errors)
    owned = owner_symbols()
    for item in sorted(snapshot["public_descriptors"] - baseline["public_descriptors"]):
        if item[1] not in owned:
            errors.append(f"new public Java symbol without owner: {item[1]} in {item[0]}")
    for item in sorted(snapshot["app_packages"] - baseline["app_packages"]):
        errors.append(f"new application-package Runtime descriptor: {item[1]} in {item[0]}")
    for item in sorted(snapshot["game_lines"] - baseline["game_lines"]):
        errors.append(f"new game-specific Runtime text in {item[0]}: {item[1]}")
    current_fixed = {(item[0], item[1]): item[2] for item in snapshot["fixed_tables"]}
    for key, capacity in sorted(current_fixed.items()):
        previous = baseline["fixed_tables"].get(key)
        if previous is None:
            errors.append(f"new fixed semantic table {key[1]} capacity {capacity} in {key[0]}")
        elif capacity > previous:
            errors.append(f"fixed semantic table expanded {key[1]} {previous} -> {capacity} in {key[0]}")
    return errors


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--write-baseline", action="store_true")
    args = parser.parse_args()
    snapshot = scan()
    if args.write_baseline:
        BASELINE_PATH.write_text(json.dumps(as_records(snapshot), indent=2) + "\n", encoding="utf-8")
        print(f"wrote {BASELINE_PATH}")
        return 0
    if not BASELINE_PATH.is_file():
        print("missing java-architecture-baseline.json", file=sys.stderr)
        return 1
    errors = check(snapshot, load_baseline())
    if errors:
        for error in errors:
            print(f"::error title=Java architecture freeze::{error}")
        return 1
    print("java architecture freeze: PASS")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
