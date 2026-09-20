#!/usr/bin/env python3
"""Focused contracts for V2.1 target failure and process-death evidence."""

import importlib.util,json,pathlib,subprocess,sys

ROOT=pathlib.Path(__file__).resolve().parents[1]

def load_module(name,path):
 spec=importlib.util.spec_from_file_location(name,ROOT/path);module=importlib.util.module_from_spec(spec);spec.loader.exec_module(module);return module

def require(value,message):
 if not value:raise AssertionError(message)

def summary_contract():
 result={"pvs1_closure":{"passed":True,"clean_teardown":True},"teardown_completed":True,
         "runtime_failure_signature":"","gameplay_failure":"checkpoint:swap_timeout","gameplay_outcome":"replay_incomplete"}
 diagnostic={"classification":"WATCHDOG","passive":True,"intrusive":False}
 scratch=ROOT/"build"/"artifacts";scratch.mkdir(parents=True,exist_ok=True)
 rp=scratch/"classifier-test-result.json";dp=scratch/"classifier-test-diagnostic.json";op=scratch/"classifier-test-summary.json"
 try:
  rp.write_text(json.dumps(result));dp.write_text(json.dumps(diagnostic))
  subprocess.run([sys.executable,str(ROOT/"ci/build-summary.py"),"--platform","ios-simulator","--run-kind","discovery",
                  "--build-status","success","--contracts-status","success","--regressions-status","success",
                  "--result",str(rp),"--diagnostic",str(dp),"--output",str(op)],cwd=ROOT,check=True,capture_output=True,text=True)
  summary=json.loads(op.read_text())
 finally:
  for path in (rp,dp,op):path.unlink(missing_ok=True)
 require(summary["target"]["status"]=="pass","target did not remain PASS")
 require(summary["target"]["normalized_signature"]=="","PASS produced normalized failure signature")
 require(summary["target"]["process_exit_classification"]=="","PASS retained process-death classification")

def process_contract():
 f=load_module("forensic",pathlib.Path("ci/forensic-simulator-process.py"));pid=4242;bundle="dev.agr.runtime"
 classify=lambda **kw:f.classify_target_exit(pid=pid,bundle=bundle,disappeared=kw.get("disappeared"),result_produced=kw.get("result",False),launch_rc=0,launch_text="",app_text=kw.get("app",""),system_text=kw.get("system",""),crash_reports=kw.get("reports",[]))
 require(classify(disappeared=None,result=True,system="runningboardd killed OtherApp pid 111 watchdog")=="","unrelated RunningBoard noise classified target death")
 require(classify(disappeared=2.0,reports=["AGRSimulator.ips"])=="HOST_CRASH","matching crash report not classified HOST_CRASH")
 require(classify(disappeared=2.0,system="runningboardd watchdog termination AGRSimulator pid 4242 0x8badf00d")=="WATCHDOG","matching target watchdog not classified")

if __name__=="__main__":
 summary_contract();process_contract();print("evidence classifier contracts passed")
