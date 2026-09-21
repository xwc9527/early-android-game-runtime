#!/usr/bin/env python3
"""Static API-surface union and public-contract convergence for the census.

Consumes `architecture-census.json` and the frozen contract-family granularity
and emits `api-surface-union.json`: per-sample contract families, raw API
unions, execution clusters, product-scope classification with recorded reasons,
and the marginal/cumulative/reuse curves over the pre-registered census order.

Static surface proves only that a reference exists in the binary. It can raise a
warning and select dynamic targets; it cannot decide H1 or H2.
"""
from __future__ import annotations

import argparse
import json
import pathlib

from contract_families import (
    FAMILIES, families_for_native, family_for_class, fingerprint, table,
)

# Product-scope classification. Every entry records the objective basis; nothing
# here is derived from AGR run results.
SCOPE_DECISIONS: dict[str, tuple[str, str]] = {
    "kungfoo-barracuda": ("IN_SCOPE",
        "Single-player NativeActivity game; no online permission or service dependency."),
    "gloomy-dungeons-2": ("IN_SCOPE_WITH_OPTIONAL_EXTERNAL_FEATURES",
        "Local single-player FPS; bundled promo/news view and wallpaper/widget components are "
        "separable from core gameplay."),
    "pixel-dungeon": ("IN_SCOPE", "Local single-player roguelike; no network gameplay authority."),
    "frozen-bubble": ("IN_SCOPE", "Local single-player puzzle game."),
    "vector-pinball": ("IN_SCOPE", "Local single-player pinball; libGDX + Box2D JNI."),
    "prboom": ("OUT_OF_SCOPE_EXTERNAL_DEPENDENCY",
        "Core game content (Doom IWAD) is acquired by doom.util.GameFileDownloader from a "
        "retired remote host; only the engine WAD (assets/prboom.zip) ships in the APK. "
        "Content-provisioning exclusion, not an Android cross-process semantic dependency."),
    "minetest": ("IN_SCOPE_WITH_OPTIONAL_EXTERNAL_FEATURES",
        "Bundled assets support local singleplayer world creation; server play is optional."),
    "tanks-of-freedom": ("IN_SCOPE", "Local single-player/hotseat strategy game on Godot 2."),
    "minilens": ("IN_SCOPE", "Local single-player puzzle platformer on Godot 2."),
    "qt-minesweeper": ("IN_SCOPE", "Local single-player minesweeper on Qt5 for Android."),
    "pysolfc": ("IN_SCOPE", "Local solitaire collection on python-for-android/SDL."),
    "heriswap": ("IN_SCOPE", "Local single-player match-3 on the SoupeAuCaillou engine."),
    "recursive-runner": ("IN_SCOPE", "Local single-player runner on the SoupeAuCaillou engine."),
    "liquid-wars": ("IN_SCOPE_WITH_OPTIONAL_EXTERNAL_FEATURES",
        "Local play against computer opponents with bundled assets/maps; WiFi multiplayer is "
        "an additional mode."),
    "meritous": ("IN_SCOPE", "Local single-player action-adventure SDL port."),
    "gloomy-dungeons-1": ("IN_SCOPE", "Local single-player FPS."),
    "clash-of-balls": ("OUT_OF_SCOPE_EXTERNAL_DEPENDENCY",
        "Multiplayer-only over AllJoyn WiFi transport; DEX contains no single-player, AI or "
        "offline game mode. Explicitly out of product scope per the multiplayer-only rule."),
    "hyperroid": ("IN_SCOPE", "Local single-player roguelike; JNI core with Canvas presentation."),
    "sgt-puzzles": ("IN_SCOPE", "Local single-player puzzle collection; JNI core with Canvas."),
    "droidfish": ("IN_SCOPE", "Local play against the bundled Stockfish JNI engine."),
    "crosswords": ("IN_SCOPE_WITH_OPTIONAL_EXTERNAL_FEATURES",
        "Local solo play against the bundled robot; SMS/Bluetooth/relay multiplayer is an "
        "additional mode."),
    "flickit": ("IN_SCOPE", "Local single-player libGDX game."),
    "geometri-destroyer": ("IN_SCOPE", "Local single-player libGDX/Box2D game."),
    "kids-memory": ("IN_SCOPE", "Local single-player libGDX memory game."),
    "glxy": ("IN_SCOPE", "Local single-player libGDX sandbox game."),
    "replica-island": ("IN_SCOPE", "Local single-player platformer; pure Java GLES1 engine."),
    "shattered-pixel": ("IN_SCOPE", "Local single-player roguelike; pure Java GLES2 engine."),
    "andors-trail": ("IN_SCOPE", "Local single-player RPG; pure Java Canvas engine."),
    "blockinger": ("IN_SCOPE", "Local single-player block game; pure Java."),
    "gravity-defied": ("IN_SCOPE", "Local single-player J2ME-derived motorbike game."),
    "a2048": ("IN_SCOPE",
        "Local single-player game whose entire presentation is a bundled HTML/JS asset rendered "
        "in an in-process WebView; no remote content."),
    "sudoku-free": ("IN_SCOPE", "Local single-player sudoku; pure Java."),
}


def execution_cluster(sample: dict) -> str:
    """Coarse execution-structure cluster used for heterogeneity accounting."""
    engines = set(sample["engines"])
    mode = sample["execution_mode"]
    graphics = set(sample["graphics_paths"])
    if "libgdx" in engines:
        return "libgdx"
    if "godot" in engines:
        return "godot"
    if "qt" in engines:
        return "qt"
    if "python-sdl" in engines:
        return "python-sdl"
    if "soupeaucaillou" in engines:
        return "soupeaucaillou"
    if "irrlicht" in engines:
        return "irrlicht-nativeactivity"
    if "sdl" in engines:
        return "sdl"
    if mode == "native_activity":
        return "custom-nativeactivity"
    if mode == "dex_plus_jni":
        if graphics & {"gles1", "gles2", "gles3", "glsurfaceview"}:
            return "custom-jni-gl"
        return "custom-jni-canvas"
    if mode == "pure_dex":
        if "webview" in graphics and not (graphics & {"gles1", "gles2", "glsurfaceview"}):
            return "pure-java-webview"
        if graphics & {"gles1", "gles2", "gles3", "glsurfaceview"}:
            return "pure-java-gl"
        return "pure-java-canvas"
    return mode


def sample_families(sample: dict) -> tuple[dict[str, list[str]], list[str]]:
    mapped: dict[str, list[str]] = {}
    unmapped: list[str] = []
    for name in sample["core_android_classes"]:
        family = family_for_class(name)
        if family is None:
            unmapped.append(name)
            continue
        mapped.setdefault(family, []).append(name)
    for family in families_for_native(sample["native_dt_needed"], sample["native_imports"]):
        mapped.setdefault(family, [])
    if sample["counts"]["jni_native_methods"]:
        mapped.setdefault("jni.bridge", [])
    if sample["native_activity"]:
        mapped.setdefault("app.native_activity", [])
        mapped.setdefault("native.app_glue", [])
    if sample["counts"]["defined_classes"]:
        mapped.setdefault("app.activity_lifecycle", [])
        mapped.setdefault("app.application_lifecycle", [])
        mapped.setdefault("resources.asset_access", [])
    return mapped, sorted(unmapped)


def curve(order: list[dict], key: str) -> list[dict]:
    seen: set[str] = set()
    rows = []
    for index, item in enumerate(order):
        values = set(item[key])
        new = values - seen
        reused = values & seen
        seen |= values
        rows.append({
            "index": index,
            "id": item["id"],
            "cluster": item["cluster"],
            "touched": len(values),
            "marginal_new": len(new),
            "cumulative_unique": len(seen),
            "reuse_ratio": round(len(reused) / len(values), 4) if values else None,
            "new_items": sorted(new),
        })
    return rows


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("--census", default="build/artifacts/architecture-census.json")
    parser.add_argument("--output", default="build/artifacts/api-surface-union.json")
    args = parser.parse_args()
    root = pathlib.Path(__file__).resolve().parents[1]
    census = json.loads((root / args.census).read_text(encoding="utf-8"))

    per_sample = []
    for sample in census["samples"]:
        mapped, unmapped = sample_families(sample)
        scope, reason = SCOPE_DECISIONS.get(sample["id"], ("NEEDS_DYNAMIC_CLASSIFICATION", "unassigned"))
        core_families = sorted(f for f in mapped if FAMILIES[f][0] == "CORE")
        per_sample.append({
            "id": sample["id"],
            "package": sample["package"],
            "cluster": execution_cluster(sample),
            "execution_mode": sample["execution_mode"],
            "engines": sample["engines"],
            "graphics_paths": sample["graphics_paths"],
            "audio_paths": sample["audio_paths"],
            "system_services": sample["system_services"],
            "scope": scope,
            "scope_reason": reason,
            "contract_families": sorted(mapped),
            "core_contract_families": core_families,
            "families_by_scope": {
                bucket: sorted(f for f in mapped if FAMILIES[f][0] == bucket)
                for bucket in ("CORE", "SHELL", "OPTIONAL", "EXTERNAL")
            },
            "unmapped_core_classes": unmapped,
            "raw_core_classes": sample["core_android_classes"],
            "raw_core_methods": sample["core_android_methods"],
            "native_dt_needed": sample["native_dt_needed"],
            "counts": sample["counts"],
        })

    in_scope = [item for item in per_sample
                if item["scope"].startswith("IN_SCOPE")]
    curves = {
        "census_order_all": {
            "contract_families": curve(per_sample, "contract_families"),
            "core_contract_families": curve(per_sample, "core_contract_families"),
            "raw_core_classes": curve(per_sample, "raw_core_classes"),
            "raw_core_methods": curve(per_sample, "raw_core_methods"),
        },
        "census_order_in_scope": {
            "contract_families": curve(in_scope, "contract_families"),
            "core_contract_families": curve(in_scope, "core_contract_families"),
            "raw_core_classes": curve(in_scope, "raw_core_classes"),
            "raw_core_methods": curve(in_scope, "raw_core_methods"),
        },
    }

    clusters: dict[str, list[str]] = {}
    for item in per_sample:
        clusters.setdefault(item["cluster"], []).append(item["id"])

    union_families = sorted({f for item in per_sample for f in item["contract_families"]})
    payload = {
        "schema_version": 1,
        "granularity": table(),
        "granularity_fingerprint": fingerprint(),
        "sample_count": len(per_sample),
        "execution_clusters": {k: sorted(v) for k, v in sorted(clusters.items())},
        "union": {
            "contract_families": union_families,
            "contract_family_count": len(union_families),
            "core_contract_families": sorted(
                f for f in union_families if FAMILIES[f][0] == "CORE"),
            "raw_core_classes": len({c for item in per_sample for c in item["raw_core_classes"]}),
            "raw_core_methods": len({m for item in per_sample for m in item["raw_core_methods"]}),
            "unmapped_core_classes": sorted(
                {c for item in per_sample for c in item["unmapped_core_classes"]}),
        },
        "curves": curves,
        "samples": per_sample,
        "limitations": [
            "Static references prove that a code path exists in the binary, not that core "
            "gameplay executes it.",
            "Unexecuted references are UNKNOWN_REACHABILITY until a dynamic run or source "
            "analysis resolves them.",
            "These curves are discovery data. H2 is decided only by the dynamic Discovery and "
            "Holdout measurements.",
        ],
    }
    output = root / args.output
    output.parent.mkdir(parents=True, exist_ok=True)
    output.write_text(json.dumps(payload, indent=2) + "\n", encoding="utf-8")
    print(f"{len(per_sample)} samples, {len(union_families)} contract families -> {output}")


if __name__ == "__main__":
    main()
