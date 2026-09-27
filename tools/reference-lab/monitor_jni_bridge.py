"""Source checks for the synchronized JNI bridge monitor path."""

from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
EVIDENCE = ROOT / "tools/reference-lab/evidence/dalvik-monitor-jni-bridge-source-closure"
LOCK_EDGES = {
    "THREAD_MONITOR around contended monitor enter": "dvmChangeStatus",
    "fat monitor pthread mutex lock": "pthread_mutex_lock",
    "fat monitor pthread mutex unlock": "pthread_mutex_unlock",
}
WAIT_EDGES = {
    "thread wait state and suspension coordination": "dvmChangeStatus",
    "Bionic pthread condition and mutex semantics": "pthread_cond_wait",
}
PATH_TOKENS = (
    "dvmCallJNIMethod",
    "ACC_SYNCHRONIZED",
    "dvmLockObject",
    "LW_SHAPE_THIN",
    "android_atomic_acquire_cas",
    "THREAD_MONITOR",
    "sched_yield",
    "nanosleep",
    "inflateMonitor",
    "lockMonitor",
    "pthread_mutex_trylock",
    "pthread_mutex_lock",
    "dvmUnlockObject",
    "pthread_mutex_unlock",
    "IllegalMonitorStateException",
)


def validate_jni_monitor_lock_source(integer_index, resource_index):
    """Reject a wait-path closure, a short lock path, or a production-proven closure."""
    monitor = integer_index["external_cluster_sources"]["Dalvik.Monitor"]
    binding = resource_index["external_cluster_sources"]["Dalvik.JNINativeBinding"]
    if monitor.get("status") != "SOURCE_CLOSED" or monitor.get("closure_reviewed") is not True:
        raise ValueError("handwritten source closure")
    if "migration_authorized" in monitor:
        raise ValueError("handwritten source closure")
    evidence = monitor.get("closure_evidence") or {}
    if evidence.get("source_file_sha256") != monitor.get("source_file_sha256"):
        raise ValueError("handwritten source closure")
    if evidence.get("unresolved_dependency_edges") != []:
        raise ValueError("handwritten source closure")
    if set(evidence.get("reviewed_dependency_edges") or []) != set(monitor.get("cross_cluster_deps") or []):
        raise ValueError("source path is short of the API19 lock path")
    symbols = set(monitor.get("required_symbols") or [])
    if not {"dvmLockObject", "dvmUnlockObject", "dvmObjectWait", "dvmObjectNotifyAll"} <= symbols:
        raise ValueError("source path is short of the API19 lock path")
    edges = {item.get("edge"): item for item in monitor.get("cross_cluster_source_edges") or []}
    for name, symbol in {**LOCK_EDGES, **WAIT_EDGES}.items():
        edge = edges.get(name)
        if edge is None or edge.get("source_symbol") != symbol:
            raise ValueError("source path is short of the API19 lock path")
    if edges["Bionic pthread condition and mutex semantics"].get("path") != "dvmObjectWait":
        raise ValueError("wait closure was used as the lock closure")
    if edges["THREAD_MONITOR around contended monitor enter"].get("path") != "dvmLockObject":
        raise ValueError("same owner crossings were mixed")
    if edges["fat monitor pthread mutex lock"].get("source_symbol") == "pthread_cond_wait":
        raise ValueError("wait closure was used as the lock closure")
    if "prerequisite_edges" in monitor:
        raise ValueError("same owner crossings were mixed")
    bridge = next(item for item in binding["prerequisite_edges"]
                  if item.get("edge") == "synchronized JNI bridge monitor")
    if bridge.get("relationship") != "UNRESOLVED" or bridge.get("source_symbol") != "dvmLockObject":
        raise ValueError("JNI monitor relationship changed")
    if bridge.get("owner_source_status") != "SOURCE_CLOSED":
        raise ValueError("handwritten source closure")
    others = [item for item in binding["prerequisite_edges"]
              if item.get("edge") != "synchronized JNI bridge monitor"
              and item.get("edge") != "JNI thread state around RegisterNatives"]
    if [item.get("relationship") for item in others] != ["UNRESOLVED", "UNRESOLVED", "UNRESOLVED"]:
        raise ValueError("another JNI prerequisite changed")
    source_path = (EVIDENCE / "source-path.txt").read_text(encoding="utf-8")
    if any(token not in source_path for token in PATH_TOKENS):
        raise ValueError("source path is short of the API19 lock path")
    if "dvmObjectWait" in source_path.split("excluded:")[0]:
        raise ValueError("wait/notify entered the lock origin")
    comparison = (EVIDENCE / "production-comparison.json").read_text(encoding="utf-8")
    if "source_authority" in comparison and '"source_authority": true' in comparison.replace(" ", ""):
        raise ValueError("production implementation certified the source closure")
    summary = (EVIDENCE / "summary.json").read_text(encoding="utf-8")
    if '"new_semantic_owner": true' in summary.replace(" ", ""):
        raise ValueError("unconfirmed semantic owner")
    return monitor
