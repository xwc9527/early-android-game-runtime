#!/usr/bin/env python3
"""Prepare fixed, hash-verified F-Droid APK inputs for AGR CI."""
from __future__ import annotations

import argparse
import gzip
import hashlib
import json
import pathlib
import shutil
import time
import urllib.request
import zipfile

INDEXES = (
    ("repo", "https://f-droid.org/repo/index-v1.json"),
    ("archive", "https://f-droid.org/archive/index-v1.json"),
)
# The Runtime migration baseline set. `full` stays pinned to it so that closure
# and validation runs of the existing workflows keep their exact sample scope
# while the architecture census uses a wider, separate profile.
RUNTIME_BASELINE = {
    "kungfoo-barracuda", "gloomy-dungeons-2", "pixel-dungeon",
    "frozen-bubble", "vector-pinball",
}
PROFILES = {
    "focused-activity": {"pixel-dungeon", "frozen-bubble"},
    "focused-framework": {"frozen-bubble"},
    "runtime-regression": RUNTIME_BASELINE,
    "full": RUNTIME_BASELINE,
    "census": None,
}


def fetch_json(url: str, cache: pathlib.Path) -> dict:
    if cache.exists():
        try:
            return json.loads(cache.read_text(encoding="utf-8"))
        except (OSError, UnicodeError, json.JSONDecodeError):
            cache.unlink(missing_ok=True)
    request = urllib.request.Request(url, headers={
        "User-Agent": "agr-compat-ci/1",
        "Accept-Encoding": "gzip",
    })
    with urllib.request.urlopen(request, timeout=180) as response:
        data = response.read()
        if response.headers.get("Content-Encoding", "").lower() == "gzip":
            data = gzip.decompress(data)
    parsed = json.loads(data)
    cache.parent.mkdir(parents=True, exist_ok=True)
    temporary = cache.with_suffix(cache.suffix + ".tmp")
    temporary.write_bytes(data)
    temporary.replace(cache)
    return parsed


def select_version(sample: dict, candidates: list[tuple[str, dict]]) -> tuple[str, dict]:
    wanted = sample.get("version_code")
    if wanted is not None:
        matches = [(repo, item) for repo, item in candidates if int(item["versionCode"]) == int(wanted)]
        if not matches:
            raise RuntimeError(f"{sample['package']}: versionCode {wanted} absent from F-Droid indexes")
        return matches[0]
    ordered = sorted(candidates, key=lambda pair: int(pair[1]["versionCode"]))
    return ordered[0] if sample.get("selection") == "oldest" else ordered[-1]


def update_lock(root: pathlib.Path, manifest: dict, lock_path: pathlib.Path) -> dict:
    cache = root / "samples" / "indexes"
    cache.mkdir(parents=True, exist_ok=True)
    indexes = [(name, fetch_json(url, cache / f"{name}-index-v1.json")) for name, url in INDEXES]
    locked = []
    for sample in manifest["samples"]:
        candidates = [
            (repo, item)
            for repo, index in indexes
            for item in index.get("packages", {}).get(sample["package"], [])
        ]
        if not candidates:
            raise RuntimeError(f"{sample['package']}: absent from F-Droid indexes")
        repo, package = select_version(sample, candidates)
        if package.get("hashType", "sha256").lower() != "sha256":
            raise RuntimeError(f"{sample['package']}: unsupported hash type {package.get('hashType')}")
        entry = {key: sample[key] for key in ("id", "package", "license", "source", "profile")}
        entry.update({
            "version_code": int(package["versionCode"]),
            "version_name": package.get("versionName", ""),
            "apk_name": package["apkName"],
            "repository": repo,
            "sha256": package["hash"].lower(),
        })
        locked.append(entry)
    lock = {"schema_version": 1, "origin": "F-Droid repo/archive index-v1.json", "samples": locked}
    lock_path.parent.mkdir(parents=True, exist_ok=True)
    lock_path.write_text(json.dumps(lock, indent=2) + "\n", encoding="utf-8")
    return lock


def download(url: str, target: pathlib.Path, expected: str) -> None:
    target.parent.mkdir(parents=True, exist_ok=True)
    if target.exists():
        actual = hashlib.sha256(target.read_bytes()).hexdigest()
        if actual.lower() == expected.lower():
            return
        target.unlink()
    temporary = target.with_suffix(target.suffix + ".download")
    request = urllib.request.Request(url, headers={"User-Agent": "agr-compat-ci/1"})
    try:
        with urllib.request.urlopen(request, timeout=180) as response, temporary.open("wb") as output:
            shutil.copyfileobj(response, output)
        actual = hashlib.sha256(temporary.read_bytes()).hexdigest()
        if actual.lower() != expected.lower():
            raise RuntimeError(f"SHA-256 mismatch for {url}: {actual} != {expected}")
        temporary.replace(target)
    finally:
        temporary.unlink(missing_ok=True)


def extract_member(apk: pathlib.Path, names: list[str], output: pathlib.Path) -> str:
    with zipfile.ZipFile(apk) as archive:
        available = set(archive.namelist())
        selected = next((name for name in names if name in available), None)
        if not selected:
            raise RuntimeError(f"{apk.name}: none of {names} found")
        output.write_bytes(archive.read(selected))
        return selected


def select_profile(samples: list[dict], profile: str) -> list[dict]:
    selected_ids = PROFILES[profile]
    if selected_ids is None:
        return samples
    result = [item for item in samples if item["id"] in selected_ids]
    if {item["id"] for item in result} != selected_ids:
        raise RuntimeError(f"sample lock does not contain the {profile} sample set")
    return result


def remove_generated(path: pathlib.Path) -> None:
    for attempt in range(8):
        try:
            path.unlink(missing_ok=True)
            return
        except PermissionError:
            if attempt == 7:
                raise
            # Windows scanners can briefly retain a just-written APK handle.
            time.sleep(0.1 * (attempt + 1))


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("--manifest", default="Tests/Samples/fdroid.json")
    parser.add_argument("--lock", default="Tests/Samples/fdroid.lock.json")
    parser.add_argument("--output", default="samples")
    parser.add_argument("--resources", default="App/Resources")
    parser.add_argument("--profile", choices=tuple(PROFILES), default="full")
    parser.add_argument("--inputs-only", action="store_true",
                        help="download and verify locked APKs without preparing app bundle resources")
    parser.add_argument("--update-lock", action="store_true",
                        help="explicitly resolve the manifest against F-Droid indexes and rewrite the lock")
    args = parser.parse_args()
    root = pathlib.Path(__file__).resolve().parents[1]
    manifest = json.loads((root / args.manifest).read_text(encoding="utf-8-sig"))
    lock_path = root / args.lock
    lock = update_lock(root, manifest, lock_path) if args.update_lock else json.loads(lock_path.read_text(encoding="utf-8"))
    if lock.get("schema_version") != 1:
        raise RuntimeError("unsupported F-Droid sample lock schema")
    manifest_by_id = {item["id"]: item for item in manifest["samples"]}
    locked_by_id = {item["id"]: item for item in lock.get("samples", [])}
    if set(locked_by_id) != set(manifest_by_id):
        raise RuntimeError("sample lock ids differ from Tests/Samples/fdroid.json; update the lock explicitly")
    for sample_id, sample in manifest_by_id.items():
        locked = locked_by_id[sample_id]
        for key in ("package", "license", "source", "profile"):
            if locked.get(key) != sample.get(key):
                raise RuntimeError(f"{sample_id}: locked {key} differs from sample manifest")
    samples = select_profile([locked_by_id[item["id"]] for item in manifest["samples"]], args.profile)
    output = root / args.output
    resources = root / args.resources
    output.mkdir(parents=True, exist_ok=True)
    if not args.inputs_only:
        resources.mkdir(parents=True, exist_ok=True)
        for pattern in ("sample--*.apk", "batch--*.so"):
            for path in resources.glob(pattern):
                remove_generated(path)
        for name in ("kungfoo.apk", "kungfoo-classes.dex", "kungfoo-native.so", "gloomy-librenderer.so"):
            remove_generated(resources / name)

    resolved = []
    for sample in samples:
        repo = sample["repository"]
        if repo not in {"repo", "archive"}:
            raise RuntimeError(f"{sample['id']}: invalid F-Droid repository {repo}")
        apk_name = sample["apk_name"]
        if pathlib.PurePosixPath(apk_name).name != apk_name:
            raise RuntimeError(f"{sample['id']}: apk_name must be a filename")
        apk_path = output / f"{sample['id']}.apk"
        download(f"https://f-droid.org/{repo}/{apk_name}", apk_path, sample["sha256"])
        public_name = f"sample--{sample['id']}.apk"
        if not args.inputs_only:
            shutil.copyfile(apk_path, resources / public_name)
        entry = dict(sample)
        entry.update({"resource": public_name, "apk_path": str(apk_path)})
        resolved.append(entry)
        if args.inputs_only:
            continue
        if sample["profile"] == "kungfoo":
            shutil.copyfile(apk_path, resources / "kungfoo.apk")
            extract_member(apk_path, ["classes.dex"], resources / "kungfoo-classes.dex")
            extract_member(apk_path, [
                "lib/armeabi-v7a/libKungFooBarracudaNativeActivity.so",
                "lib/armeabi/libKungFooBarracudaNativeActivity.so",
            ], resources / "kungfoo-native.so")
        elif sample["profile"] == "gloomy":
            extract_member(apk_path, [
                "lib/armeabi-v7a/librenderer.so", "lib/armeabi/librenderer.so"
            ], resources / "gloomy-librenderer.so")
    (output / "resolved.json").write_text(json.dumps({"profile": args.profile, "samples": resolved}, indent=2) + "\n", encoding="utf-8")


if __name__ == "__main__":
    main()
