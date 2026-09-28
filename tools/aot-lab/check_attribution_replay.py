#!/usr/bin/env python3
"""Hard-check same-fixture replay equality and retain every timing sample."""

import json
from pathlib import Path
import statistics
import sys


def main():
    root = Path(sys.argv[1])
    groups = {
        "interpreter": [root / f"interpreter-{i}.json" for i in range(1, 6)],
        "generated-c": [root / "generated-c" / f"sample-{i}.json" for i in range(1, 6)],
        "indexed-region": [root / "indexed-region" / f"sample-{i}.json" for i in range(1, 6)],
        "guardless-region": [root / "guardless-region" / f"sample-{i}.json" for i in range(1, 6)],
        "scalar-region": [root / "scalar-region" / f"sample-{i}.json" for i in range(1, 6)],
    }
    samples = {name: [json.loads(path.read_text()) for path in paths]
               for name, paths in groups.items()}
    labels = {row["label"] for group in samples.values() for row in group}
    reps = {row["repetitions"] for group in samples.values() for row in group}
    instruction_counts = {row["guest_instructions_per_repetition"]
                          for group in samples.values() for row in group}
    memory_results = {row["final_pages_fnv64"]
                      for group in samples.values() for row in group}
    checks = {
        "single_workload": len(labels) == 1,
        "same_repetitions": len(reps) == 1,
        "same_guest_instruction_count": len(instruction_counts) == 1,
        "memory_results_equal": len(memory_results) == 1,
        "all_architectural_states_equal": all(row["state_equal"] for group in samples.values()
                                              for row in group),
        "backend_identity": all(row["backend"] == name for name, group in samples.items()
                                for row in group),
    }
    summary = {
        "schema": "agr.aot-same-job-real-segment-replay.v1",
        "label": next(iter(labels)) if labels else None,
        "checks": checks,
        "passed": all(checks.values()),
        "raw_samples": samples,
        "median_ns_per_repetition": {
            name: statistics.median(row["elapsed_ns"] / row["repetitions"] for row in group)
            for name, group in samples.items()
        },
    }
    (root / "replay-comparison.json").write_text(json.dumps(summary, indent=2) + "\n")
    print(json.dumps({key: value for key, value in summary.items() if key != "raw_samples"}))
    if not summary["passed"]:
        raise SystemExit(1)


if __name__ == "__main__":
    main()
