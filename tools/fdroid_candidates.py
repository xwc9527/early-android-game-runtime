#!/usr/bin/env python3
"""Query the cached F-Droid indexes for API19-era game candidates.

Discovery helper for the architecture census. It never downloads anything; it
only reports package/version metadata so that a heterogeneous sample set can be
chosen deliberately instead of by download order.
"""
from __future__ import annotations

import argparse
import json
import pathlib


def load_indexes(cache: pathlib.Path) -> list[tuple[str, dict]]:
    return [
        (name, json.loads((cache / f"{name}-index-v1.json").read_text(encoding="utf-8")))
        for name in ("repo", "archive")
        if (cache / f"{name}-index-v1.json").exists()
    ]


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("--cache", default="samples/indexes")
    parser.add_argument("--max-target-sdk", type=int, default=19)
    parser.add_argument("--max-size", type=int, default=40 * 1024 * 1024)
    parser.add_argument("--category", default="Game",
                        help="substring matched against F-Droid category names")
    parser.add_argument("--packages", nargs="*", default=None,
                        help="report every known version of these packages instead of searching")
    parser.add_argument("--output", default="build/artifacts/fdroid-candidates.json")
    args = parser.parse_args()
    root = pathlib.Path(__file__).resolve().parents[1]
    indexes = load_indexes(root / args.cache)

    app_meta: dict[str, dict] = {}
    for _, index in indexes:
        for app in index.get("apps", []):
            app_meta.setdefault(app["packageName"], app)

    rows: list[dict] = []
    wanted = set(args.packages) if args.packages else None
    for repo, index in indexes:
        for package, versions in index.get("packages", {}).items():
            meta = app_meta.get(package, {})
            categories = meta.get("categories", [])
            if wanted is None:
                if not any(args.category in item for item in categories):
                    continue
            elif package not in wanted:
                continue
            for item in versions:
                target = int(item.get("targetSdkVersion") or 0)
                if wanted is None:
                    if not target or target > args.max_target_sdk:
                        continue
                    if int(item.get("size") or 0) > args.max_size:
                        continue
                rows.append({
                    "package": package,
                    "name": meta.get("name", ""),
                    "license": meta.get("license", ""),
                    "source": meta.get("sourceCode") or meta.get("webSite") or "",
                    "summary": meta.get("summary", ""),
                    "categories": categories,
                    "repository": repo,
                    "version_code": int(item["versionCode"]),
                    "version_name": item.get("versionName", ""),
                    "apk_name": item["apkName"],
                    "sha256": (item.get("hash") or "").lower(),
                    "hash_type": item.get("hashType", ""),
                    "min_sdk": int(item.get("minSdkVersion") or 0),
                    "target_sdk": target,
                    "size": int(item.get("size") or 0),
                    "nativecode": sorted(item.get("nativecode") or []),
                })
    rows.sort(key=lambda row: (row["package"], row["version_code"]))
    output = root / args.output
    output.parent.mkdir(parents=True, exist_ok=True)
    output.write_text(json.dumps({"count": len(rows), "candidates": rows}, indent=2) + "\n",
                      encoding="utf-8")
    print(f"{len(rows)} candidate versions across "
          f"{len({row['package'] for row in rows})} packages -> {output}")


if __name__ == "__main__":
    main()
