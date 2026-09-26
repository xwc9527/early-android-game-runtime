"""Bind a semantic substrate owner to production-contract closure evidence.

A registry record cannot certify itself. PRODUCTION_CLOSED is authority only
when the cited closure run and API19 CLEAN differential repeat the same owner
digest, revision, commit, and tree, and no reopen names that owner.
"""

import json
import re
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
REGISTRY_PATH = ROOT / "ci/governance/substrate-production-contracts.json"
MODULES_PATH = ROOT / "ci/governance/modules.json"
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
    contracts = document.get("contracts")
    reopens = document.get("reopens")
    if not isinstance(contracts, list) or not isinstance(reopens, list):
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
        _require_field(contract, "clean_differential", None, "production contract lacks clean differential")
        _require_field(contract, "closure_evidence", None, "production contract lacks closure evidence")
        _require_field(contract, "closure_run", None, "production contract lacks closure evidence")
        _require_field(contract, "production_module", None, "production contract lacks production module")
    for reopen in reopens:
        if not isinstance(reopen, dict) or not all(reopen.get(key) for key in (
                "semantic_cluster", "reason", "evidence")):
            raise ValueError("substrate production reopen lacks evidence")


def require_production_contract(semantic_cluster, source_revision, source_owner_digest,
                                contracts=None, evidence=None, modules=None):
    """Reject PRODUCTION_CLOSED unless cited evidence binds this exact source owner."""
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
    _require_field(record, "clean_differential", None, "production contract lacks clean differential")
    _require_field(record, "closure_evidence", None, "production contract lacks closure evidence")
    _require_field(record, "closure_run", None, "production contract lacks closure evidence")
    _require_field(record, "production_module", None, "production contract lacks production module")
    if record["production_module"] not in modules:
        raise ValueError("production contract module is not registered")
    if any(item.get("semantic_cluster") == semantic_cluster and item.get("reason") and item.get("evidence")
           for item in contracts.get("reopens") or [] if isinstance(item, dict)):
        raise ValueError("production contract reopen blocks closed prerequisite")
    closure = _load_artifact(evidence, record["closure_evidence"])
    differential = _load_artifact(evidence, record["clean_differential"])
    if not _same(closure, record, ("semantic_cluster", "tested_commit", "tested_tree",
                                   "source_revision", "source_owner_digest")):
        raise ValueError("production contract evidence does not bind the source owner")
    if closure.get("run_id") != record["closure_run"] or closure.get("classification") != "VALID_PASS":
        raise ValueError("production contract lacks closure evidence")
    if (differential.get("kind") != "API19_CLEAN_DIFFERENTIAL" or
            differential.get("result") != "NO_DIVERGENCE" or
            not _same(differential, record, ("semantic_cluster", "tested_commit", "tested_tree",
                                             "source_revision", "source_owner_digest"))):
        raise ValueError("production contract lacks clean differential")


def _require_field(record, key, pattern, message):
    value = record.get(key)
    if not isinstance(value, str) or not value or (pattern is not None and not pattern.fullmatch(value)):
        raise ValueError(message)


def _same(artifact, record, keys):
    return isinstance(artifact, dict) and all(artifact.get(key) == record.get(key) for key in keys)


def _load_artifact(evidence, ref):
    if not isinstance(ref, str) or not ref or ref.startswith("/") or ".." in ref.split("/"):
        raise ValueError("production contract evidence is missing")
    if isinstance(evidence, dict) and ref in evidence:
        artifact = evidence[ref]
    else:
        path = ROOT / ref
        if not path.is_file():
            raise ValueError("production contract evidence is missing")
        artifact = json.loads(path.read_text(encoding="utf-8"))
    if not isinstance(artifact, dict):
        raise ValueError("production contract evidence is missing")
    return artifact
