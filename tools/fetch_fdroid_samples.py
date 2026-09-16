#!/usr/bin/env python3
"""Resolve and fetch licensed test APKs from the official F-Droid indexes."""
from __future__ import annotations

import argparse
import hashlib
import json
import pathlib
import shutil
import urllib.request
import zipfile

INDEXES = (
    ("repo", "https://f-droid.org/repo/index-v1.json"),
    ("archive", "https://f-droid.org/archive/index-v1.json"),
)


def fetch_json(url: str, cache: pathlib.Path) -> dict:
    if not cache.exists():
        request = urllib.request.Request(url, headers={"User-Agent": "agr-compat-ci/1"})
        with urllib.request.urlopen(request, timeout=120) as response, cache.open("wb") as output:
            shutil.copyfileobj(response, output)
    return json.loads(cache.read_text(encoding="utf-8"))


def select_version(sample: dict, candidates: list[tuple[str, dict]]) -> tuple[str, dict]:
    wanted = sample.get("version_code")
    if wanted is not None:
        matches = [(repo, item) for repo, item in candidates if int(item["versionCode"]) == int(wanted)]
        if not matches:
            raise RuntimeError(f"{sample['package']}: versionCode {wanted} absent from F-Droid indexes")
        return matches[0]
    ordered = sorted(candidates, key=lambda pair: int(pair[1]["versionCode"]))
    return ordered[0] if sample.get("selection") == "oldest" else ordered[-1]


def download(url: str, target: pathlib.Path, expected: str) -> None:
    if not target.exists():
        request = urllib.request.Request(url, headers={"User-Agent": "agr-compat-ci/1"})
        with urllib.request.urlopen(request, timeout=180) as response, target.open("wb") as output:
            shutil.copyfileobj(response, output)
    actual = hashlib.sha256(target.read_bytes()).hexdigest()
    if actual.lower() != expected.lower():
        target.unlink(missing_ok=True)
        raise RuntimeError(f"SHA-256 mismatch for {url}: {actual} != {expected}")


def extract_member(apk: pathlib.Path, names: list[str], output: pathlib.Path) -> str:
    with zipfile.ZipFile(apk) as archive:
        available = set(archive.namelist())
        selected = next((name for name in names if name in available), None)
        if not selected:
            raise RuntimeError(f"{apk.name}: none of {names} found")
        output.write_bytes(archive.read(selected))
        return selected


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("--manifest", default="Tests/Samples/fdroid.json")
    parser.add_argument("--output", default="samples")
    parser.add_argument("--resources", default="App/Resources")
    args = parser.parse_args()
    root = pathlib.Path(__file__).resolve().parents[1]
    manifest = json.loads((root / args.manifest).read_text(encoding="utf-8-sig"))
    output = root / args.output
    resources = root / args.resources
    cache = output / "indexes"
    cache.mkdir(parents=True, exist_ok=True)
    resources.mkdir(parents=True, exist_ok=True)

    indexes: list[tuple[str, dict]] = []
    for name, url in INDEXES:
        indexes.append((name, fetch_json(url, cache / f"{name}-index-v1.json")))

    resolved = []
    for sample in manifest["samples"]:
        candidates: list[tuple[str, dict]] = []
        for repo, index in indexes:
            candidates += [(repo, item) for item in index.get("packages", {}).get(sample["package"], [])]
        if not candidates:
            raise RuntimeError(f"{sample['package']}: absent from F-Droid indexes")
        repo, package = select_version(sample, candidates)
        if package.get("hashType", "sha256").lower() != "sha256":
            raise RuntimeError(f"{sample['package']}: unsupported hash type {package.get('hashType')}")
        apk_name = package["apkName"]
        apk_path = output / f"{sample['id']}.apk"
        download(f"https://f-droid.org/{repo}/{apk_name}", apk_path, package["hash"])
        public_name = f"sample--{sample['id']}.apk"
        shutil.copyfile(apk_path, resources / public_name)
        entry = dict(sample)
        entry.update({
            "version_code": int(package["versionCode"]),
            "version_name": package.get("versionName", ""),
            "apk_name": apk_name,
            "resource": public_name,
            "sha256": package["hash"].lower(),
            "repository": repo,
        })
        resolved.append(entry)

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

    (output / "resolved.json").write_text(json.dumps({"samples": resolved}, indent=2), encoding="utf-8")


if __name__ == "__main__":
    main()
