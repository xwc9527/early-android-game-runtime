"""Bind a semantic substrate owner to production-contract closure evidence.

A registry record cannot certify itself. ``closure_run`` is authority only when
it is one ``VALID_PASS`` in ``ci/governance/closure-attempts.json`` and that
row's tested commit and tree match the record, and ``git rev-parse`` resolves
the same tree. This repository has no API19 CLEAN differential producer, so a
record that passes those checks is still not ``PREREQUISITE_CLOSED``.
"""

import hashlib
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
CROSSING_FIELDS = ("edge", "semantic_cluster", "source_repo", "revision",
                   "source_file", "source_symbol", "source_sha256")
SUSPEND_EDGE = "self-suspend on the thread suspend-count condition"
SUSPEND_SCOPE = (
    "futex wait/wake with full barrier on normal lock, normal unlock, and broadcast pulse",
    "normal pthread_mutex_lock",
    "normal pthread_mutex_unlock",
    "pthread_cond_broadcast",
    "untimed pthread_cond_wait",
)
SUSPEND_SOURCE_PATH = (
    "dvmChangeStatus",
    "fullSuspendCheck",
    "pthread_mutex_lock",
    "pthread_cond_wait",
    "pthread_cond_broadcast",
    "__pthread_cond_pulse",
)
UNVERIFIED_CAPABILITIES = (
    "absolute pthread_cond_timedwait",
    "clock_gettime",
    "monotonic pthread_cond_timedwait",
    "pthread_cond_signal",
    "pthread_mutex_lock_timeout_np",
)
SUSPEND_PROBE = (
    "SUSPEND_WAIT_WAKE rc=0 payload=0 relocked=1\n"
    "UNLOCK_ERROR_IGNORED waited=1 returned=0\n"
    "SUSPEND_PATH ok=1\n"
)


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
    closures = document.get("crossing_closures", [])
    if not isinstance(closures, list):
        raise ValueError("substrate crossing closure registry is malformed")
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
    seen_crossings = set()
    for record in closures:
        if not isinstance(record, dict):
            raise ValueError("substrate crossing closure is malformed")
        if record.get("status") != "CROSSING_CLOSED":
            raise ValueError("crossing closure cannot use owner production status")
        identity = tuple(record.get(field) for field in CROSSING_FIELDS)
        if not all(identity) or identity in seen_crossings:
            raise ValueError("substrate crossing closure is not unique")
        seen_crossings.add(identity)
        _require_field(record, "source_owner_digest", HEX64, "crossing closure lacks source owner digest")
        _require_field(record, "source_revision", HEX40, "crossing closure does not bind the source owner")
        _require_field(record, "tested_commit", HEX40, "crossing closure lacks tested commit")
        _require_field(record, "tested_tree", HEX40, "crossing closure lacks tested tree")
        _require_field(record, "closure_run", None, "crossing closure lacks closure run")
        _require_field(record, "production_module", None, "crossing closure lacks production module")
        _require_field(record, "closure_target", None, "crossing closure lacks closure target")
        if not isinstance(record.get("production_scope"), list) or not record["production_scope"]:
            raise ValueError("crossing closure lacks production scope")
        if not isinstance(record.get("source_path"), list) or not record["source_path"]:
            raise ValueError("crossing closure lacks source path")
        origin = record.get("origin")
        if not isinstance(origin, dict):
            raise ValueError("crossing closure lacks origin")
        for key in ("source_repo", "revision", "source_file", "source_symbol", "source_sha256"):
            if not origin.get(key):
                raise ValueError("crossing closure lacks origin")


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


def derived_production_scope(crossing):
    """Scope comes from the one pinned suspend path. Shared helpers do not add APIs."""
    if not isinstance(crossing, dict):
        raise ValueError("crossing has no derived production scope")
    if (crossing.get("edge") != SUSPEND_EDGE or
            crossing.get("semantic_cluster") != "Bionic.PthreadCondition" or
            crossing.get("source_repo") != "platform/bionic" or
            crossing.get("revision") != "081db840befec895fb86e709ae95832ade2d065c" or
            crossing.get("source_file") != "libc/bionic/pthread.c" or
            crossing.get("source_symbol") != "pthread_cond_wait" or
            crossing.get("source_sha256") !=
            "8ac45c046e0b410bac44a4d8f5c49de002483371e7d374b62d61eecf0f5d672d"):
        raise ValueError("crossing has no derived production scope")
    return list(SUSPEND_SCOPE)


def suspend_crossing_differential(evidence_dir):
    """Recompute the suspend differential from committed source-path and AGR probe bytes."""
    directory = ROOT / evidence_dir
    source_path = _normalized(directory / "source-path.txt")
    probe = _normalized(directory / "runs" / "36262733436" / "bionic-suspend-cond.txt")
    required = (
        "pthread_mutex_lock", "pthread_mutex_unlock", "pthread_cond_wait",
        "pthread_cond_broadcast", "ANDROID_MEMBAR_FULL",
        "does not call clock_gettime",
        "pthread_cond_signal is not called on threadSuspendCountCond",
        "8ac45c046e0b410bac44a4d8f5c49de002483371e7d374b62d61eecf0f5d672d",
        "ed1fb72d49c9f59a5fe9f72b204891a7071ecf36c68371cbfd8a65e235f69dd7",
    )
    if probe != SUSPEND_PROBE or any(item not in source_path for item in required):
        raise ValueError("differential does not match")
    if "abstime NULL does not call clock_gettime" not in source_path:
        raise ValueError("differential does not match")
    if "pthread_mutex_lock_timeout_np" in source_path:
        raise ValueError("differential does not match")
    return {
        "result": "NO_DIVERGENCE",
        "source_path_sha256": hashlib.sha256(source_path.encode("utf-8")).hexdigest(),
        "agr_probe_sha256": hashlib.sha256(probe.encode("utf-8")).hexdigest(),
        "production_scope": list(SUSPEND_SCOPE),
        "source_path": list(SUSPEND_SOURCE_PATH),
    }


def require_exact_crossing_closure(prerequisite, crossing, declarer, source_revision,
                                   source_owner_digest, contracts=None, modules=None, ledger=None):
    """A crossing closure covers one prerequisite edge. An owner record does not."""
    if not isinstance(prerequisite, dict) or not isinstance(crossing, dict) or any(
            prerequisite.get(field) != crossing.get(field) for field in CROSSING_FIELDS):
        raise ValueError("crossing closure does not match the prerequisite edge")
    if contracts is None:
        contracts = load_substrate_production_contracts()
    else:
        validate_registry_document(contracts)
    modules = production_module_names(modules)
    identity = tuple(crossing.get(field) for field in CROSSING_FIELDS) if isinstance(crossing, dict) else None
    matches = [item for item in contracts.get("crossing_closures") or []
               if isinstance(item, dict) and tuple(item.get(field) for field in CROSSING_FIELDS) == identity]
    broad = [item for item in contracts.get("contracts") or []
             if isinstance(item, dict) and item.get("semantic_cluster") == (crossing or {}).get("semantic_cluster")
             and item.get("status") == "PRODUCTION_CLOSED"]
    if not matches:
        if broad:
            raise ValueError("broad owner closure does not cover the exact crossing")
        same_owner = [item for item in contracts.get("crossing_closures") or []
                      if isinstance(item, dict) and item.get("semantic_cluster") == (crossing or {}).get("semantic_cluster")]
        if same_owner:
            raise ValueError("crossing closure does not match the prerequisite edge")
        raise ValueError("no production contract authority")
    if len(matches) != 1:
        raise ValueError("substrate crossing closure is not unique")
    record = matches[0]
    scope = derived_production_scope(crossing)
    declared = record.get("production_scope")
    if any(item in UNVERIFIED_CAPABILITIES for item in declared or []):
        raise ValueError("production scope includes an unverified capability")
    if list(declared) != scope:
        raise ValueError("production scope is short of the crossing")
    if list(record.get("source_path") or []) != list(SUSPEND_SOURCE_PATH):
        raise ValueError("crossing closure source path does not match")
    origin = record.get("origin") or {}
    files = (declarer or {}).get("source_file_sha256") or {}
    if (origin.get("source_repo") != (declarer or {}).get("source_repo") or
            origin.get("revision") != (declarer or {}).get("revision") or
            origin.get("source_file") != "vm/Thread.cpp" or
            origin.get("source_symbol") != "dvmChangeStatus" or
            origin.get("source_sha256") != files.get("vm/Thread.cpp") or
            "dvmChangeStatus" not in ((declarer or {}).get("required_symbols") or [])):
        raise ValueError("crossing closure origin does not match")
    if (record.get("source_revision") != source_revision or
            record.get("source_owner_digest") != source_owner_digest):
        raise ValueError("crossing closure does not bind the source owner")
    if record["production_module"] not in modules:
        raise ValueError("production contract module is not registered")
    differential = suspend_crossing_differential(record.get("evidence_dir") or "")
    claimed = record.get("differential") or {}
    if (claimed.get("result") != differential["result"] or
            claimed.get("source_path_sha256") != differential["source_path_sha256"] or
            claimed.get("agr_probe_sha256") != differential["agr_probe_sha256"]):
        raise ValueError("differential does not match")
    _require_git_tree(record["tested_commit"], record["tested_tree"])
    _require_crossing_run(record, ledger)
    return record


def _require_crossing_run(record, ledger):
    if ledger is None:
        ledger = json.loads(LEDGER_PATH.read_text(encoding="utf-8"))
    attempts = ledger.get("attempts") if isinstance(ledger, dict) else None
    matches = [item for item in attempts or []
               if isinstance(item, dict) and item.get("run_id") == record["closure_run"]]
    if (len(matches) != 1 or matches[0].get("classification") != "VALID_PASS"
            or matches[0].get("tested_commit") != record["tested_commit"]
            or matches[0].get("tested_tree") != record["tested_tree"]
            or matches[0].get("target") != record.get("closure_target")):
        raise ValueError("closure run is not a recorded VALID_PASS")


def validate_committed_crossing_closures(document=None):
    """The committed ThreadState edge must cite its own crossing closure."""
    if document is None:
        document = load_substrate_production_contracts()
    index_path = ROOT / "tools/reference-lab/indexes/integer-boxing-api19-locations.json"
    index = json.loads(index_path.read_text(encoding="utf-8"))
    owners = index["external_cluster_sources"]
    declarer = owners["Dalvik.ThreadState"]
    substrate = owners["Bionic.PthreadCondition"]
    digest = hashlib.sha256(json.dumps(
        substrate, sort_keys=True, separators=(",", ":"), ensure_ascii=False).encode("utf-8")).hexdigest()
    edge = declarer["prerequisite_edges"][0]
    crossing = declarer["cross_cluster_source_edges"][0]
    if edge.get("relationship") != "PREREQUISITE_CLOSED":
        raise ValueError("self-suspend prerequisite is not closed by an exact crossing")
    require_exact_crossing_closure(
        edge, crossing, declarer, substrate["revision"], digest, document)
    identities = {tuple(record.get(field) for field in CROSSING_FIELDS)
                  for record in document.get("crossing_closures") or []}
    if identities != {tuple(edge.get(field) for field in CROSSING_FIELDS)}:
        raise ValueError("crossing closure does not match the prerequisite edge")


def _normalized(path):
    if not path.is_file():
        raise ValueError("differential does not match")
    return path.read_bytes().replace(b"\r\n", b"\n").decode("utf-8")
