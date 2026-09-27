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
REGISTER_NATIVES_EDGE = "JNI thread state around RegisterNatives"
REGISTER_NATIVES_SCOPE = (
    "entry THREAD_NATIVE published by JNI_CreateJavaVM",
    "RegisterNatives enters THREAD_RUNNING after publication",
    "same-status change returns without a store",
    "a THREAD_SUSPENDED request is not stored",
    "a non-RUNNING status does not read suspendCount",
    "nonzero suspendCount enters fullSuspendCheck",
    "fullSuspendCheck waits through the D010 host words and the closed Bionic self-suspend operations",
    "wake restores the previous status",
    "RegisterNatives leave restores THREAD_NATIVE",
)
REGISTER_NATIVES_SOURCE_PATH = (
    "JNI_CreateJavaVM",
    "dvmChangeStatus(THREAD_NATIVE)",
    "RegisterNatives",
    "ScopedJniThreadState",
    "dvmChangeStatus(THREAD_RUNNING)",
    "suspendCount",
    "fullSuspendCheck",
    "D010 threadSuspendCountLock",
    "D010 threadSuspendCountCond",
    "closed Bionic self-suspend",
    "dvmChangeStatus(THREAD_NATIVE)",
)
REGISTER_NATIVES_UNVERIFIED = (
    "Java Thread API",
    "general thread startup",
    "arbitrary JNI entry/exit",
    "debugger suspend",
    "GC suspend-all",
    "monitor wait/notify",
    "Sync.cpp",
    "pthread_cond_timedwait",
    "clock_gettime",
)
REGISTER_NATIVES_MODULE = "DalvikThreadState"
REGISTER_NATIVES_FILES = (
    "Runtime/DexLoom/Include/dx_thread_state.h",
    "Runtime/DexLoom/VM/dx_thread_state.c",
)
REGISTER_NATIVES_ORIGIN = {
    "source_repo": "platform/dalvik",
    "revision": "36e356c96640775f0a3f167bd2426ea0f0093b8b",
    "source_file": "vm/Jni.cpp",
    "source_symbol": "RegisterNatives",
    "source_sha256": "ebba645673d34d23be01b20891cb18c432ce67a4d7d76fdfbf023cc944b2dbed",
}
REGISTER_NATIVES_PROBE = (
    "THREADSTATE_PORT ok=1 waits=1 broadcasts=1 cond=4294967294 body=1 java=3 dalvik=7\n"
    "entry THREAD_NATIVE\n"
    "failure body THREAD_RUNNING restore THREAD_NATIVE\n"
    "success body THREAD_RUNNING restore THREAD_NATIVE\n"
    "nonzero suspendCount entered SUSPENDED\n"
    "wait consumed agr_bionic_cond_wait_relative\n"
    "broadcast consumed agr_bionic_cond_broadcast\n"
    "cond word 0xfffffffe is the closed pulse step\n"
    "DxJavaThreadState TERMINATED 3 remained independent of Dalvik THREAD_NATIVE 7\n"
    "second execution context THREAD_WAIT did not change the root context\n"
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


def register_natives_threadstate_differential():
    """Recompute the RegisterNatives thread-state differential from committed evidence."""
    source_path = _normalized(
        ROOT / "tools/reference-lab/evidence/dalvik-threadstate-register-natives-closure/source-path.txt")
    probe = _normalized(
        ROOT / "tools/reference-lab/evidence/dalvik-threadstate-production-port/host-output.txt")
    required = (
        "JNI_CreateJavaVM",
        "ScopedJniThreadState",
        "RUNNING publication before suspendCount",
        "same status returns without a store",
        "THREAD_SUSPENDED request is not stored",
        "non-RUNNING status does not check suspendCount",
        "nonzero suspendCount enters fullSuspendCheck",
        "D010 gDvm.threadSuspendCountLock gDvm.threadSuspendCountCond",
        "closed Bionic self-suspend",
        "wake restores previous status",
        "DxJavaThreadState is independent",
        "ed1fb72d49c9f59a5fe9f72b204891a7071ecf36c68371cbfd8a65e235f69dd7",
        "ebba645673d34d23be01b20891cb18c432ce67a4d7d76fdfbf023cc944b2dbed",
        "8ac45c046e0b410bac44a4d8f5c49de002483371e7d374b62d61eecf0f5d672d",
    )
    if probe != REGISTER_NATIVES_PROBE or any(item not in source_path for item in required):
        raise ValueError("differential does not match")
    if any(item in source_path for item in ("Java Thread.start", "dvmSuspendAllThreads", "pthread_cond_timedwait")):
        raise ValueError("differential does not match")
    return {
        "result": "NO_DIVERGENCE",
        "source_path_sha256": hashlib.sha256(source_path.encode("utf-8")).hexdigest(),
        "agr_probe_sha256": hashlib.sha256(probe.encode("utf-8")).hexdigest(),
        "production_scope": list(REGISTER_NATIVES_SCOPE),
        "source_path": list(REGISTER_NATIVES_SOURCE_PATH),
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
    if crossing.get("edge") == SUSPEND_EDGE:
        _require_suspend_crossing_body(record, declarer, source_revision, source_owner_digest, modules)
    elif crossing.get("edge") == REGISTER_NATIVES_EDGE:
        _require_register_natives_crossing_body(
            record, contracts, declarer, source_revision, source_owner_digest, modules)
    else:
        raise ValueError("crossing closure does not match the prerequisite edge")
    _require_git_tree(record["tested_commit"], record["tested_tree"])
    _require_crossing_run(record, ledger)
    return record


def _require_suspend_crossing_body(record, declarer, source_revision, source_owner_digest, modules):
    derived_production_scope(record)
    declared = record.get("production_scope")
    if any(item in UNVERIFIED_CAPABILITIES for item in declared or []):
        raise ValueError("production scope includes an unverified capability")
    if list(declared) != list(SUSPEND_SCOPE):
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


def _require_register_natives_crossing_body(record, contracts, declarer, source_revision,
                                            source_owner_digest, modules):
    declared = record.get("production_scope")
    if any(item in REGISTER_NATIVES_UNVERIFIED or item in UNVERIFIED_CAPABILITIES
           for item in declared or []):
        raise ValueError("production scope includes an unverified capability")
    if list(declared) != list(REGISTER_NATIVES_SCOPE):
        raise ValueError("production scope is short of the crossing")
    if list(record.get("source_path") or []) != list(REGISTER_NATIVES_SOURCE_PATH):
        raise ValueError("crossing closure source path does not match")
    origin = record.get("origin") or {}
    files = (declarer or {}).get("source_file_sha256") or {}
    if (origin != REGISTER_NATIVES_ORIGIN or
            origin.get("source_sha256") != files.get("vm/Jni.cpp") or
            (declarer or {}).get("source_repo") != REGISTER_NATIVES_ORIGIN["source_repo"] or
            (declarer or {}).get("revision") != REGISTER_NATIVES_ORIGIN["revision"] or
            "RegisterNatives" not in ((declarer or {}).get("required_symbols") or []) or
            "JNI_CreateJavaVM" not in ((declarer or {}).get("required_symbols") or [])):
        raise ValueError("crossing closure origin does not match")
    if (record.get("source_revision") != source_revision or
            record.get("source_owner_digest") != source_owner_digest or
            record.get("semantic_cluster") != "Dalvik.ThreadState" or
            record.get("source_symbol") != "dvmChangeStatus"):
        raise ValueError("crossing closure does not bind the source owner")
    if record.get("production_module") != REGISTER_NATIVES_MODULE or record["production_module"] not in modules:
        raise ValueError("production contract module is not registered")
    document = json.loads(MODULES_PATH.read_text(encoding="utf-8"))
    module = next((item for item in document.get("modules") or []
                   if item.get("name") == REGISTER_NATIVES_MODULE), None)
    if module is None or set(module.get("paths") or []) != set(REGISTER_NATIVES_FILES):
        raise ValueError("production files do not match module ownership")
    jni_module = next((item for item in document.get("modules") or []
                       if item.get("name") == "DalvikJNI"), None)
    if any(path in set((jni_module or {}).get("paths") or []) for path in REGISTER_NATIVES_FILES):
        raise ValueError("production files do not match module ownership")
    downstream = next((item for item in contracts.get("crossing_closures") or []
                       if item.get("edge") == SUSPEND_EDGE
                       and item.get("semantic_cluster") == "Bionic.PthreadCondition"), None)
    if (downstream is None or downstream.get("status") != "CROSSING_CLOSED" or
            downstream.get("source_symbol") != "pthread_cond_wait" or
            downstream.get("source_sha256") !=
            "8ac45c046e0b410bac44a4d8f5c49de002483371e7d374b62d61eecf0f5d672d" or
            downstream.get("production_module") != "pthread" or
            list(downstream.get("production_scope") or []) != list(SUSPEND_SCOPE)):
        raise ValueError("downstream Bionic crossing does not match")
    if any(item.get("semantic_cluster") == "Bionic.PthreadCondition" and item.get("status") == "PRODUCTION_CLOSED"
           for item in contracts.get("contracts") or []):
        raise ValueError("downstream Bionic crossing does not match")
    binding_document = load_host_storage_consumer_bindings()
    binding = (binding_document.get("bindings") or [None])[0]
    if (not isinstance(binding, dict) or binding.get("authorization_decision") != "D010" or
            binding.get("consumer") != "Dalvik.ThreadState" or
            list(binding.get("objects") or []) != list(HOST_STORAGE_OBJECTS) or
            binding.get("edge") != SUSPEND_EDGE or
            binding.get("semantic_owner") != "Bionic.PthreadCondition"):
        raise ValueError("D010 consumer binding does not match")
    differential = register_natives_threadstate_differential()
    claimed = record.get("differential") or {}
    if (claimed.get("producer") != "substrate_contracts.register_natives_threadstate_differential" or
            claimed.get("result") != differential["result"] or
            claimed.get("source_path_sha256") != differential["source_path_sha256"] or
            claimed.get("agr_probe_sha256") != differential["agr_probe_sha256"]):
        raise ValueError("differential does not match")


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


HOST_STORAGE_BINDING_PATH = ROOT / "ci/governance/host-storage-consumer-bindings.json"
DECISIONS_PATH = ROOT / "docs/DECISIONS.md"
GUEST_SYNC_HEADER = ROOT / "Runtime/Bionic/agr_bionic_sync.h"
HOST_SERVICES_HEADER = ROOT / "Runtime/HostServices/agr_host_services.h"
HOST_STORAGE_DECISION = "D010"
HOST_STORAGE_CLASS = "HOST-DEX private VM state"
HOST_STORAGE_OBJECTS = ("gDvm.threadSuspendCountLock", "gDvm.threadSuspendCountCond")
HOST_STORAGE_SEMANTIC_REQUIREMENT = (
    "closed Bionic state machine, ordering, and full-barrier behavior")
HOST_STORAGE_CONSUMER = "Dalvik.ThreadState"
HOST_STORAGE_OWNER = "Bionic.PthreadCondition"
DECISION_KEYS = {
    "id", "status", "selected_fork", "consumer", "semantic_owner", "edge",
    "storage_class", "objects", "guest_abi_exposure", "guest_address_requirement",
    "guest_address_requirement_scope", "guest_pthread_binding",
    "semantic_ownership_separated", "host_pthread_substitution",
    "host_services_pthread_policy", "new_semantic_owner",
    "whole_owner_production_closed",
}
BINDING_KEYS = DECISION_KEYS - {"id", "status", "selected_fork"} | {
    "authorization_decision", "crossing_status", "semantic_cluster",
    "source_repo", "revision", "source_file", "source_symbol", "source_sha256",
    "source_revision", "source_owner_digest", "origin", "production_scope",
    "production_module", "tested_commit", "tested_tree", "closure_run",
    "semantic_requirement",
}
CROSSING_STORAGE_KEYS = {
    "host_dex_consumption", "storage_class", "guest_abi_exposure", "consumer",
    "authorization_decision", "objects",
}
D010_REQUIRED_TEXT = (
    "Status: LOCKED",
    "representation-split",
    "Dalvik.ThreadState",
    "Bionic.PthreadCondition",
    SUSPEND_EDGE,
    "HOST-DEX private VM state",
    "gDvm.threadSuspendCountLock",
    "gDvm.threadSuspendCountCond",
    "Guest ABI exposure is false",
    "Guest-address requirement is false for this consumer only",
    "Semantic ownership stays with the existing CROSSING_CLOSED record",
    "Storage representation may split",
    "Semantic ownership may not split",
    "guest-visible pthread representation stays unchanged",
    "does not create a pthread semantic owner",
    "does not mark `Bionic.PthreadCondition` PRODUCTION_CLOSED",
    "does not authorize host pthread substitution",
    "does not authorize HostServices pthread policy",
)


def load_host_storage_consumer_bindings(path=None):
    document = json.loads(Path(path or HOST_STORAGE_BINDING_PATH).read_text(encoding="utf-8"))
    if not isinstance(document, dict) or document.get("schema_version") != 1:
        raise ValueError("host storage consumer binding is malformed")
    return document


def _d010_section(decisions_text=None):
    text = decisions_text if decisions_text is not None else DECISIONS_PATH.read_text(encoding="utf-8")
    marker = "## D010 — "
    start = text.find(marker)
    if start < 0:
        raise ValueError("handwritten consumer authorization")
    rest = text[start:]
    end = rest.find("\n## ", 1)
    section = rest if end < 0 else rest[:end]
    if any(item not in section for item in D010_REQUIRED_TEXT):
        raise ValueError("handwritten consumer authorization")
    return section


def require_host_storage_consumer_binding(binding, contracts=None, decision=None,
                                           decisions_text=None, guest_header=None,
                                           host_header=None):
    """One HOST-DEX consumer may use private storage for one closed crossing."""
    if not isinstance(binding, dict) or set(binding) != BINDING_KEYS or "authorized" in binding:
        raise ValueError("handwritten consumer authorization" if isinstance(binding, dict) and "authorized" in binding
                         else "consumer binding is malformed")
    if binding.get("authorization_decision") != HOST_STORAGE_DECISION:
        raise ValueError("handwritten consumer authorization")
    if not isinstance(decision, dict) or set(decision) != DECISION_KEYS:
        raise ValueError("handwritten consumer authorization")
    if (decision.get("id") != HOST_STORAGE_DECISION or decision.get("status") != "LOCKED"
            or decision.get("selected_fork") != "representation-split"):
        raise ValueError("handwritten consumer authorization")
    _d010_section(decisions_text)
    shared = (
        "consumer", "semantic_owner", "edge", "storage_class", "objects",
        "guest_abi_exposure", "guest_address_requirement",
        "guest_address_requirement_scope", "guest_pthread_binding",
        "semantic_ownership_separated", "host_pthread_substitution",
        "host_services_pthread_policy", "new_semantic_owner",
        "whole_owner_production_closed",
    )
    if any(binding.get(field) != decision.get(field) for field in shared):
        raise ValueError("handwritten consumer authorization")
    if contracts is None:
        contracts = load_substrate_production_contracts()
    else:
        validate_registry_document(contracts)
    if any(isinstance(item, dict) and item.get("semantic_cluster") == HOST_STORAGE_OWNER
           and item.get("status") == "PRODUCTION_CLOSED"
           for item in contracts.get("contracts") or []):
        raise ValueError("consumer binding is not whole-owner authority")
    if binding.get("whole_owner_production_closed") is not False or binding.get("new_semantic_owner") is not False:
        raise ValueError("consumer binding is not whole-owner authority" if binding.get("whole_owner_production_closed") is not False
                         else "consumer binding creates a pthread semantic owner")
    record = next((item for item in contracts.get("crossing_closures") or []
                   if isinstance(item, dict) and item.get("edge") == SUSPEND_EDGE
                   and item.get("semantic_cluster") == HOST_STORAGE_OWNER), None)
    if record is None:
        raise ValueError("consumer binding crossing does not match")
    if CROSSING_STORAGE_KEYS & set(record):
        raise ValueError("consumer binding modifies crossing identity")
    if any(binding.get(field) != record.get(field) for field in CROSSING_FIELDS):
        raise ValueError("consumer binding crossing does not match")
    if (binding.get("source_revision") != record.get("source_revision")
            or binding.get("source_owner_digest") != record.get("source_owner_digest")
            or binding.get("tested_commit") != record.get("tested_commit")
            or binding.get("tested_tree") != record.get("tested_tree")
            or binding.get("closure_run") != record.get("closure_run")
            or binding.get("origin") != record.get("origin")
            or binding.get("production_module") != record.get("production_module")
            or binding.get("crossing_status") != "CROSSING_CLOSED"):
        raise ValueError("consumer binding modifies crossing identity")
    if binding.get("consumer") != HOST_STORAGE_CONSUMER:
        raise ValueError("consumer binding consumer does not match")
    if binding.get("semantic_owner") != HOST_STORAGE_OWNER or binding.get("semantic_cluster") != HOST_STORAGE_OWNER:
        raise ValueError("consumer binding semantic owner does not match")
    scope = list(binding.get("production_scope") or [])
    if any(item not in SUSPEND_SCOPE for item in scope) or len(scope) != len(set(scope)):
        raise ValueError("consumer binding production scope exceeds the crossing")
    if scope != list(SUSPEND_SCOPE) or list(record.get("production_scope") or []) != list(SUSPEND_SCOPE):
        raise ValueError("consumer binding production scope does not match")
    if binding.get("semantic_requirement") != HOST_STORAGE_SEMANTIC_REQUIREMENT:
        raise ValueError("consumer binding semantic requirement does not match")
    if (binding.get("storage_class") != HOST_STORAGE_CLASS
            or list(binding.get("objects") or []) != list(HOST_STORAGE_OBJECTS)):
        raise ValueError("guest-visible pthread object cannot use host storage")
    if (binding.get("guest_abi_exposure") is not False
            or binding.get("guest_address_requirement") is not False
            or binding.get("guest_address_requirement_scope") != "this consumer only"):
        raise ValueError("guest-visible pthread object cannot use host storage")
    if binding.get("guest_pthread_binding") != "unchanged":
        raise ValueError("guest pthread binding is not unchanged")
    header = guest_header if guest_header is not None else GUEST_SYNC_HEADER.read_text(encoding="utf-8")
    if "ARM32 addresses" not in header:
        raise ValueError("guest pthread binding is not unchanged")
    if binding.get("host_pthread_substitution") is not False:
        raise ValueError("host pthread behavior is not Bionic semantics")
    if binding.get("semantic_ownership_separated") is not False:
        raise ValueError("consumer binding separates semantic ownership")
    if binding.get("host_services_pthread_policy") is not False:
        raise ValueError("HostServices pthread policy is not authorized")
    services = host_header if host_header is not None else HOST_SERVICES_HEADER.read_text(encoding="utf-8")
    if "futex" in services:
        raise ValueError("HostServices pthread policy is not authorized")
    return binding


def validate_committed_host_storage_bindings(contracts=None, document=None):
    """The committed binding must cite D010 and the unchanged crossing record."""
    document = document if document is not None else load_host_storage_consumer_bindings()
    decision = document.get("decision")
    bindings = document.get("bindings")
    if not isinstance(bindings, list) or len(bindings) != 1:
        raise ValueError("host storage consumer binding is not unique")
    require_host_storage_consumer_binding(bindings[0], contracts, decision)
    if contracts is None:
        contracts = load_substrate_production_contracts()
    binding = bindings[0]
    binding_identity = tuple(binding.get(field) for field in CROSSING_FIELDS)
    bionic_records = [record for record in contracts.get("crossing_closures") or []
                      if isinstance(record, dict) and record.get("semantic_cluster") == HOST_STORAGE_OWNER]
    if (len(bionic_records) != 1 or
            tuple(bionic_records[0].get(field) for field in CROSSING_FIELDS) != binding_identity):
        raise ValueError("consumer binding crossing does not match")


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
    resources = json.loads((ROOT / "tools/reference-lab/indexes/shared-resources-api19-locations.json").read_text(encoding="utf-8"))
    binding = resources["external_cluster_sources"]["Dalvik.JNINativeBinding"]
    jni_edge = next(item for item in binding["prerequisite_edges"]
                    if item.get("edge") == REGISTER_NATIVES_EDGE)
    jni_crossing = next(item for item in binding["cross_cluster_source_edges"]
                        if item.get("edge") == REGISTER_NATIVES_EDGE)
    thread = owners["Dalvik.ThreadState"]
    thread_digest = hashlib.sha256(json.dumps(
        thread, sort_keys=True, separators=(",", ":"), ensure_ascii=False).encode("utf-8")).hexdigest()
    identities = {tuple(record.get(field) for field in CROSSING_FIELDS)
                  for record in document.get("crossing_closures") or []}
    suspend_identity = tuple(edge.get(field) for field in CROSSING_FIELDS)
    jni_identity = tuple(jni_edge.get(field) for field in CROSSING_FIELDS)
    if jni_edge.get("relationship") == "PREREQUISITE_CLOSED":
        if identities != {suspend_identity, jni_identity}:
            raise ValueError("crossing closure does not match the prerequisite edge")
        require_exact_crossing_closure(
            jni_edge, jni_crossing, binding, thread["revision"], thread_digest, document)
        if binding.get("status") != "SOURCE_LOCATED" or binding.get("closure_reviewed") is not False:
            raise ValueError("JNINativeBinding owner status changed")
        others = [item for item in binding["prerequisite_edges"] if item.get("edge") != REGISTER_NATIVES_EDGE]
        if any(item.get("relationship") != "UNRESOLVED" for item in others):
            raise ValueError("unrelated JNI prerequisite changed")
    else:
        if identities != {suspend_identity}:
            raise ValueError("crossing closure does not match the prerequisite edge")
        if jni_edge.get("relationship") != "REOPEN_REQUIRED":
            raise ValueError("handwritten prerequisite relationship")


def _normalized(path):
    if not path.is_file():
        raise ValueError("differential does not match")
    return path.read_bytes().replace(b"\r\n", b"\n").decode("utf-8")
