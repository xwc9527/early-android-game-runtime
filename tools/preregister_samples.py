#!/usr/bin/env python3
"""Freeze the Phase C, Discovery and Holdout sample sets before any dynamic run.

Selection is mechanical and stated as a rule rather than a hand-picked list, so
that the ordering cannot be adjusted afterwards to manufacture a convergence
curve. The emitted artifact is the pre-registration record; later phases must
read it instead of re-deriving membership.
"""
from __future__ import annotations

import argparse
import hashlib
import json
import pathlib

# Phase C: highest architectural risk, one per execution cluster. Recorded with
# the objective risk basis for each pick.
PHASE_C_RISK: dict[str, str] = {
    "qt-minesweeper": "Largest native topology in the census (55 ARMv7 libraries), direct "
                      "libOpenSLES and libjnigraphics, LocalSocket/LocalServerSocket and local "
                      "Binder use, 87 JNI methods.",
    "minetest": "NativeActivity with a self-contained C++ engine, both GLES1 and GLES2, OpenAL "
                "over the native audio path, no Java engine layer to absorb divergence.",
    "tanks-of-freedom": "Godot 2 with the widest system-service breadth in the census "
                        "(13 categories) plus Messenger/Binder and AudioTrack.",
    "pysolfc": "SDL2 plus an embedded CPython interpreter; unusual loader, threading and asset "
               "topology relative to every other sample.",
    "meritous": "Classic SDL port: software surface presentation plus AudioTrack, 47 JNI methods.",
    "heriswap": "Self-written native engine (SoupeAuCaillou) driving GLSurfaceView with both "
                "AudioTrack and SoundPool.",
    "flickit": "Largest libGDX Framework surface with AudioRecord/AudioTrack and a declared "
               "wallpaper component.",
    "gloomy-dungeons-2": "Largest Java Framework surface in the census (320 core classes) with "
                         "widget, wallpaper and a bundled UI compatibility layer.",
    "crosswords": "Widest non-graphics system-service use: own ContentProvider, relay Service, "
                  "broadcast receiver, SMS and clipboard, on a JNI+Canvas core.",
    "kungfoo-barracuda": "Pure NativeActivity baseline with no Java engine layer.",
    "replica-island": "Pure Java GLES1 engine with SoundPool, the canonical early-Android game "
                      "structure.",
    "a2048": "Entire presentation is an in-process WebView over bundled HTML/JS, the single "
             "highest-cost core family in the census.",
}

# Phase D selection rules, fixed before the first dynamic run.
DISCOVERY_RULE = (
    "Discovery set = the first 10 in-scope execution clusters in alphabetical order by cluster "
    "name, taking the alphabetically first in-scope sample id in each cluster. The Discovery "
    "execution order is that same cluster-alphabetical order. The rule is mechanical and "
    "independent of expected difficulty, expected contract count and of any run result."
)
HOLDOUT_RULE = (
    "Holdout set = the 3 in-scope clusters not used by Discovery (one alphabetically first "
    "sample each), plus the alphabetically second in-scope sample of the two largest Discovery "
    "clusters. Holdout membership is frozen at the same moment as Discovery and may not "
    "influence any production change until Discovery is complete."
)


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("--union", default="build/artifacts/api-surface-union.json")
    parser.add_argument("--output", default="build/artifacts/preregistered-samples.json")
    args = parser.parse_args()
    root = pathlib.Path(__file__).resolve().parents[1]
    union = json.loads((root / args.union).read_text(encoding="utf-8"))
    samples = {s["id"]: s for s in union["samples"]}
    in_scope = sorted((s for s in union["samples"] if s["scope"].startswith("IN_SCOPE")),
                      key=lambda s: s["id"])

    clusters: dict[str, list[str]] = {}
    for sample in in_scope:
        clusters.setdefault(sample["cluster"], []).append(sample["id"])
    ordered_clusters = sorted(clusters)

    discovery = [(cluster, clusters[cluster][0]) for cluster in ordered_clusters[:10]]
    remaining = ordered_clusters[10:]
    largest = sorted(ordered_clusters[:10], key=lambda c: (-len(clusters[c]), c))[:2]
    holdout = [(cluster, clusters[cluster][0]) for cluster in remaining]
    holdout += [(cluster, clusters[cluster][1]) for cluster in largest]

    discovery_ids = [sample_id for _, sample_id in discovery]
    holdout_ids = [sample_id for _, sample_id in holdout]
    assert not set(discovery_ids) & set(holdout_ids)
    assert len(discovery_ids) == 10 and len(holdout_ids) == 5
    assert set(PHASE_C_RISK) <= set(samples)

    def describe(sample_id: str) -> dict:
        sample = samples[sample_id]
        return {
            "id": sample_id,
            "package": sample["package"],
            "cluster": sample["cluster"],
            "execution_mode": sample["execution_mode"],
            "engines": sample["engines"],
            "graphics_paths": sample["graphics_paths"],
            "audio_paths": sample["audio_paths"],
            "system_services": sample["system_services"],
            "core_contract_family_count": len(sample["core_contract_families"]),
        }

    payload = {
        "schema_version": 1,
        "frozen_before": "any AGR dynamic run of the expanded census",
        "granularity_fingerprint": union["granularity_fingerprint"],
        "rule_fingerprint": hashlib.sha256(pathlib.Path(__file__).read_bytes()).hexdigest(),
        "in_scope_clusters": {c: clusters[c] for c in ordered_clusters},
        "phase_c": {
            "purpose": "API19 reference and source verification of the highest-risk, mutually "
                       "heterogeneous samples",
            "count": len(PHASE_C_RISK),
            "samples": [{**describe(sample_id), "risk_basis": reason}
                        for sample_id, reason in sorted(PHASE_C_RISK.items())],
        },
        "phase_d": {
            "discovery_rule": DISCOVERY_RULE,
            "holdout_rule": HOLDOUT_RULE,
            "discovery_order": [
                {"position": index, "cluster": cluster, **describe(sample_id)}
                for index, (cluster, sample_id) in enumerate(discovery)
            ],
            "holdout": [
                {"cluster": cluster, **describe(sample_id)}
                for cluster, sample_id in sorted(holdout)
            ],
            "discovery_ids": discovery_ids,
            "holdout_ids": holdout_ids,
        },
        "thresholds": {
            "h1_irreducible_trigger": "same or equivalent irreducible gameplay-critical dependency "
                                      "in >=3 in-scope games from >=2 unrelated clusters",
            "h2_marginal": "C_last <= 0.50 * C_first over the fixed Discovery order",
            "h2_holdout_reuse": "holdout_reuse_ratio >= 0.70",
            "h2_game_specific": "0 GAME_SPECIFIC production requirements from Holdout",
        },
    }
    output = root / args.output
    output.parent.mkdir(parents=True, exist_ok=True)
    output.write_text(json.dumps(payload, indent=2) + "\n", encoding="utf-8")
    print("discovery:", discovery_ids)
    print("holdout:  ", holdout_ids)
    print("->", output)


if __name__ == "__main__":
    main()
