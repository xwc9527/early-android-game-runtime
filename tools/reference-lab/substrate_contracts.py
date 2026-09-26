"""Bind a semantic substrate owner to production-contract closure evidence.

A registry record cannot certify itself. ``closure_run`` is authority only when
it is one ``VALID_PASS`` in ``ci/governance/closure-attempts.json`` and that
row's tested commit and tree match the record, and ``git rev-parse`` resolves
the same tree. This repository has no API19 CLEAN differential producer, so a
record that passes those checks is still not ``PREREQUISITE_CLOSED``.
"""

import json
import re
import subprocess
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
REGISTRY_PATH = ROOT / "ci/governance/substrate-production-contracts.json"
MODULES_PATH = ROOT / "ci/governance/modules.json"
LEDGER_PATH = ROOT / "ci/governance/closure-attempts.json"
HEX40 = re.compile(r"^[0-9a-f]{40}$")
HEX64 = re.compile(r"^[0-9a-f]{64}$")


def load_substrate_production_contracts(path=None):
    document = json.loads(Path(path or REGISTRY_PATH).read_text(encoding="utf-8"))
    validate_registry_document(document)
    return document


def production_module_names(modules=None):
    if modules is not None:
        return set(modules)
    document = json.loads(MODULES_PATH.read_text(encoding="utf-8"))
    return {item.get("name") for item in document.get("modules") or [] if item.get("name")}


def validate_registry_document(document):
    """Schema-check the registry. An empty contract list is the initial authority."""
    if not isinstance(document, dict) or document.get("schema_version") != 1:
        raise ValueError("unsupported substrate production contract registry")
    if "reopens" in document:
        raise ValueError("substrate production contract registry must not carry a reopen ledger")
    contracts = document.get("contracts")
    if not isinstance(contracts, list):
        raise ValueError("substrate production contract registry is malformed")
    seen = set()
    for contract in contracts:
        if not isinstance(contract, dict):
            raise ValueError("substrate production contract is malformed")
        name = contract.get("semantic_cluster")
        if not name or name in seen:
            raise ValueError("substrate production contract owner is not unique")
        seen.add(name)
        if contract.get("status") != "PRODUCTION_CLOSED":
            raise ValueError("production contract cannot self-certify closure")
        _require_field(contract, "source_owner_digest", HEX64, "production contract lacks source owner digest")
        _require_field(contract, "source_revision", HEX40, "production contract does not bind the source owner")
        _require_field(contract, "tested_commit", HEX40, "production contract lacks tested commit")
        _require_field(contract, "tested_tree", HEX40, "production contract lacks tested tree")
        _require_field(contract, "closure_run", None, "production contract lacks closure run")
        _require_field(contract, "production_module", None, "production contract lacks production module")


def require_production_contract(semantic_cluster, source_revision, source_owner_digest,
                                contracts=None, evidence=None, modules=None, ledger=None):
    """Reject PRODUCTION_CLOSED. Ledger and git identity are necessary and not sufficient."""
    del evidence  # A caller-supplied differential payload is not CLEAN authority.
    if contracts is None:
        contracts = load_substrate_production_contracts()
    else:
        validate_registry_document(contracts)
    modules = production_module_names(modules)
    record = next((item for item in contracts.get("contracts") or []
                   if item.get("semantic_cluster") == semantic_cluster
                   and item.get("status") == "PRODUCTION_CLOSED"), None)
    if record is None:
        raise ValueError("no production contract authority")
    _require_field(record, "source_owner_digest", HEX64, "production contract lacks source owner digest")
    if record["source_owner_digest"] != source_owner_digest or record.get("source_revision") != source_revision:
        raise ValueError("production contract does not bind the source owner")
    _require_field(record, "tested_commit", HEX40, "production contract lacks tested commit")
    _require_field(record, "tested_tree", HEX40, "production contract lacks tested tree")
    _require_field(record, "closure_run", None, "production contract lacks closure run")
    _require_field(record, "production_module", None, "production contract lacks production module")
    if record["production_module"] not in modules:
        raise ValueError("production contract module is not registered")
    _require_recorded_valid_pass(record, ledger)
    _require_git_tree(record["tested_commit"], record["tested_tree"])
    raise ValueError("no API19 CLEAN differential authority")


def _require_field(record, key, pattern, message):
    value = record.get(key)
    if not isinstance(value, str) or not value or (pattern is not None and not pattern.fullmatch(value)):
        raise ValueError(message)


def _require_recorded_valid_pass(record, ledger):
    if ledger is None:
        ledger = json.loads(LEDGER_PATH.read_text(encoding="utf-8"))
    attempts = ledger.get("attempts") if isinstance(ledger, dict) else None
    matches = [item for item in attempts or []
               if isinstance(item, dict) and item.get("run_id") == record["closure_run"]]
    if (len(matches) != 1 or matches[0].get("classification") != "VALID_PASS"
            or matches[0].get("tested_commit") != record["tested_commit"]
            or matches[0].get("tested_tree") != record["tested_tree"]):
        raise ValueError("closure run is not a recorded VALID_PASS")


def _require_git_tree(tested_commit, tested_tree):
    try:
        resolved = subprocess.check_output(
            ["git", "rev-parse", tested_commit + "^{tree}"],
            cwd=ROOT, text=True, stderr=subprocess.DEVNULL).strip()
    except subprocess.CalledProcessError:
        raise ValueError("tested commit is not in git") from None
    if resolved != tested_tree:
        raise ValueError("tested tree does not match git")
