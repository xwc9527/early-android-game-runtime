#!/usr/bin/env python3
"""Reject the retired Framework migration ledgers as active governance input."""

import pathlib
import sys

ROOT = pathlib.Path(__file__).resolve().parents[1]
ACTIVE = (
    ROOT / "ci/governance/java-legacy-migration.json",
    ROOT / "ci/governance/java-public-owner.json",
)
HISTORY = (
    ROOT / "ci/governance/history/java-legacy-migration.json",
    ROOT / "ci/governance/history/java-public-owner.json",
)


def main() -> int:
    errors = []
    for path in ACTIVE:
        if path.is_file():
            errors.append(f"retired ledger is still an active governance input: {path.relative_to(ROOT)}")
    for path in HISTORY:
        if not path.is_file():
            errors.append(f"historical ledger missing: {path.relative_to(ROOT)}")
    if errors:
        for error in errors:
            print(f"::error title=Java owner ledger::{error}")
        return 1
    print("java owner ledger: PASS (historical only; not a production migration input)")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
