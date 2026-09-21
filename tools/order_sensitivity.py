#!/usr/bin/env python3
"""Test whether the H2 marginal convergence depends on the Discovery order.

The pre-registered order is the one that decides the threshold. This tool
additionally evaluates the reversed order and a large random permutation
sample, so the report can state whether the observed convergence is a property
of the sample set or an artifact of the order that happened to be frozen.
"""
from __future__ import annotations

import argparse
import itertools
import json
import pathlib
import random
import statistics


def marginal_curve(sets: list[set[str]]) -> list[int]:
    seen: set[str] = set()
    counts = []
    for item in sets:
        counts.append(len(item - seen))
        seen |= item
    return counts


def ratio(counts: list[int]) -> float | None:
    half = min(5, len(counts) // 2) or 1
    first = sum(counts[:half]) / half
    last = sum(counts[-half:]) / half
    return last / first if first else None


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("--classification",
                        default="build/artifacts/frontier-classification-discovery.json")
    parser.add_argument("--output", default="build/artifacts/order-sensitivity.json")
    parser.add_argument("--permutations", type=int, default=20000)
    args = parser.parse_args()
    root = pathlib.Path(__file__).resolve().parents[1]
    data = json.loads((root / args.classification).read_text(encoding="utf-8"))
    rows = data["rows"]
    sets = [set(row["families"]) for row in rows]
    ids = [row["id"] for row in rows]

    registered = ratio(marginal_curve(sets))
    reversed_ratio = ratio(marginal_curve(list(reversed(sets))))

    random.seed(20260922)
    samples = []
    indices = list(range(len(sets)))
    total = 1
    for value in range(1, len(sets) + 1):
        total *= value
    if total <= args.permutations:
        permutations = list(itertools.permutations(indices))
    else:
        permutations = [random.sample(indices, len(indices)) for _ in range(args.permutations)]
    for order in permutations:
        value = ratio(marginal_curve([sets[i] for i in order]))
        if value is not None:
            samples.append(value)
    passing = sum(1 for value in samples if value <= 0.5)

    payload = {
        "schema_version": 1,
        "source": args.classification,
        "registered_order": ids,
        "registered_ratio": registered,
        "reversed_ratio": reversed_ratio,
        "permutations_evaluated": len(samples),
        "exhaustive": total <= args.permutations,
        "ratio_distribution": {
            "min": min(samples) if samples else None,
            "median": statistics.median(samples) if samples else None,
            "mean": round(statistics.fmean(samples), 4) if samples else None,
            "max": max(samples) if samples else None,
            "fraction_meeting_threshold": round(passing / len(samples), 4) if samples else None,
        },
        "per_sample_family_counts": [
            {"id": row["id"], "cluster": row["cluster"], "families": len(row["families"])}
            for row in rows
        ],
        "interpretation_rule": (
            "If the threshold is met under the registered order, the reversed order and the "
            "large majority of permutations, the convergence is a property of the sample set "
            "rather than of the chosen order."),
    }
    output = root / args.output
    output.parent.mkdir(parents=True, exist_ok=True)
    output.write_text(json.dumps(payload, indent=2) + "\n", encoding="utf-8")
    print(json.dumps({k: v for k, v in payload.items()
                      if k in ("registered_ratio", "reversed_ratio", "permutations_evaluated",
                               "exhaustive", "ratio_distribution")}, indent=2))


if __name__ == "__main__":
    main()
