#!/usr/bin/env python3
"""Run AGR cases independently with hard timeouts and dependency-aware blocking."""

import argparse, json, os, pathlib, signal, subprocess, sys, time

ROOT=pathlib.Path(__file__).resolve().parents[1]
ART=ROOT/"build"/"artifacts"/"results"

SUITES={
 "contracts":[
  {"id":"allocator","cmd":["bash","scripts/test-nativecore-allocator.sh"],"timeout":300},
  {"id":"jni-methods","cmd":["bash","scripts/test-jni-methods.sh"],"timeout":300},
  {"id":"host-services","cmd":["bash","scripts/test-host-services-darwin.sh"],"timeout":300},
  {"id":"guest-vma","cmd":["bash","scripts/test-guest-vma.sh"],"timeout":300},
  {"id":"linker","cmd":["bash","scripts/test-aosp-linker.sh"],"timeout":420},
  {"id":"ehabi","cmd":["bash","scripts/test-ehabi-unwind.sh"],"timeout":420},
  {"id":"pthread","cmd":["bash","scripts/test-bionic-futex-host.sh"],"timeout":420},
  {"id":"guest-fd","cmd":["bash","scripts/test-guest-fd-darwin.sh"],"timeout":300},
  {"id":"arm-permissions","cmd":["cargo","test","--manifest-path","Runtime/ArmInterpreter/Cargo.toml","--lib","permission_tests"],"timeout":420},
  {"id":"arm-thread-cpu","cmd":["cargo","test","--manifest-path","Runtime/ArmInterpreter/Cargo.toml","--lib","guest_threads_share_memory_but_not_registers"],"timeout":420},
  {"id":"arm-atomics","cmd":["cargo","test","--manifest-path","Runtime/ArmInterpreter/Cargo.toml","--lib","guest_atomic_words_serialize_across_cpu_handles"],"timeout":420},
  {"id":"arm-exclusive","cmd":["cargo","test","--manifest-path","Runtime/ArmInterpreter/Cargo.toml","--lib","guest_exclusive_monitor_tests"],"timeout":420}
 ],
 "regressions":[
  {"id":"simulator-real-apk","cmd":["bash","scripts/run-simulator-regressions.sh"],"timeout":780,"requires":["simulator-build"]}
 ]
}


def main():
    p=argparse.ArgumentParser();p.add_argument("suite",choices=SUITES);p.add_argument("--satisfied",action="append",default=[]);a=p.parse_args()
    ART.mkdir(parents=True,exist_ok=True);results=[];satisfied=set(a.satisfied)
    for case in SUITES[a.suite]:
        missing=[x for x in case.get("requires",[]) if x not in satisfied]
        log=ART/f"{a.suite}-{case['id']}.log"
        if missing:
            results.append({"id":case["id"],"status":"blocked","blocked_by":missing,"duration_sec":0,"log":str(log.relative_to(ROOT))});continue
        start=time.monotonic();returncode=None
        try:
            with log.open("w",encoding="utf-8",errors="replace") as out:
                proc=subprocess.Popen(case["cmd"],cwd=ROOT,stdout=out,stderr=subprocess.STDOUT,text=True,start_new_session=True)
                try: returncode=proc.wait(timeout=case["timeout"])
                except subprocess.TimeoutExpired:
                    os.killpg(proc.pid,signal.SIGTERM)
                    try: proc.wait(timeout=10)
                    except subprocess.TimeoutExpired: os.killpg(proc.pid,signal.SIGKILL);proc.wait()
                    returncode=124
            state="pass" if returncode==0 else "fail"
            if returncode==124:
                with log.open("a",encoding="utf-8") as out:out.write("\nAGR_TIMEOUT\n")
        except OSError as exc:
            state="blocked";log.write_text(str(exc),encoding="utf-8")
        duration=round(time.monotonic()-start,3)
        results.append({"id":case["id"],"status":state,"duration_sec":duration,"exit_code":returncode,"log":str(log.relative_to(ROOT))})
        if state=="pass": satisfied.add(case["id"])
        elif state=="fail": print(f"::error title=AGR {a.suite}::{case['id']} failed; see {log}")
    overall="fail" if any(x["status"]=="fail" for x in results) else ("blocked" if any(x["status"]=="blocked" for x in results) else "pass")
    doc={"schema_version":1,"suite":a.suite,"status":overall,"cases":results}
    (ART/f"{a.suite}.json").write_text(json.dumps(doc,indent=2)+"\n",encoding="utf-8")
    print(json.dumps(doc,separators=(",",":")))
    return 0 if overall=="pass" else 1


if __name__=="__main__":raise SystemExit(main())
