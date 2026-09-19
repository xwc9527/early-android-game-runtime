# AGR CI governance

`state.json`, `modules.json`, target contracts, and closure evidence are machine-readable mirrors of the authoritative short documents. They exist to reject state drift rather than replace architecture documentation.

- `run-suite.py` executes independent cases after failures and marks dependants blocked when a hard prerequisite is absent.
- `build-summary.py` creates the sole compact per-run result.
- `validate-governance.py` protects stable modules and validates candidate identity.
- `verify-merge.py` enforces candidate commit/tree equivalence.
- `failure-signature.py` emits both normalized cluster identity and raw fingerprint.
- `collect-diagnostics.py` writes bounded diagnostic JSON.

Closure CI invokes `build-summary.py --run-kind closure`; merge review accepts only a valid summary whose commit and tree match the current candidate. A main merge with a different tree requires new closure evidence.

After the post-merge gate passes, `promote-state.py <closure-run-summary.json> --merged` prepares the baseline, last-known-good, module status, and merge record update. That governance-only follow-up commit is excluded from the expensive post-merge workflow; the baseline remains the merge commit that actually passed the gate.
