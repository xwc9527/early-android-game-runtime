# AGR CI governance

`state.json`, `modules.json`, target contracts, and closure evidence are machine-readable mirrors of the authoritative short documents. They exist to reject state drift rather than replace architecture documentation.

- `run-suite.py` executes independent cases after failures and marks dependants blocked when a hard prerequisite is absent.
- `build-summary.py` creates the sole compact per-run result.
- `validate-governance.py` protects stable modules and validates candidate identity.
- `verify-merge.py` enforces candidate commit/tree equivalence.
- `failure-signature.py` emits both normalized cluster identity and raw fingerprint.
- `collect-diagnostics.py` writes bounded diagnostic JSON.
- `semantic-diff.py` creates and validates the source/runtime semantic differential used during discovery and closure.
- `upstream-map.py` computes VALID/STALE/UNVERIFIED/INVALID map state from pinned revision, tracked AGR hashes, and dependencies. The map is a cache, not an oracle.
- `validate-expensive-run.py` admits a discovery Simulator run only when the committed plan asks a discriminating question and the loop breaker permits it.
- `closure-attempt.py` derives and validates schema-v2, target-scoped `VALID_PASS`, `VALID_FAIL`, and `INVALID` closure-attempt accounting. Only valid attempts for `active_target` consume the recorded budget; it also cross-checks `state.json`, `closure.json`, and the ledger.
- `experiments.json` registers temporary counterfactual code. Closure rejects enabled or unresolved entries and `AGR_EXPERIMENTAL_*` in production code.
- `governance/diagnostic-cutpoints.json` registers test-only cut points.

Discovery uses `validate-governance.py --mode discovery`: stable-module investigation is reported but does not require a reopen. Closure requires an upstream mapping, a proved first relevant semantic difference, no active experiment, and an exact tested commit/tree.

Closure CI invokes `build-summary.py --run-kind closure`; merge review accepts only a valid summary whose commit and tree match the current candidate. A main merge with a different tree requires new closure evidence.

After the post-merge gate passes, `promote-state.py <closure-run-summary.json> --merged` prepares the baseline, last-known-good, module status, and merge record update. That governance-only follow-up commit is excluded from the expensive post-merge workflow; the baseline remains the merge commit that actually passed the gate.
