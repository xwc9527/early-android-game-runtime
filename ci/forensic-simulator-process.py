#!/usr/bin/env python3
"""Launch one Simulator app and passively classify why its host process exits."""
import argparse,datetime,json,os,pathlib,re,shutil,signal,subprocess,time

def run(cmd,path,timeout=30):
 try:
  cp=subprocess.run(cmd,capture_output=True,text=True,timeout=timeout)
  path.write_text(cp.stdout+"\nSTDERR:\n"+cp.stderr,encoding="utf-8",errors="replace")
  return cp.returncode,cp.stdout,cp.stderr
 except Exception as e:path.write_text(repr(e),encoding="utf-8");return -1,"",repr(e)
def alive(pid):
 try:os.kill(pid,0);return True
 except OSError:return False
def read(path):
 try:return path.read_text(encoding="utf-8",errors="replace")
 except OSError:return ""
def bounded_lines(text,pattern,limit=80):
 rx=re.compile(pattern,re.I)
 return [line[-2000:] for line in text.splitlines() if rx.search(line)][-limit:]
def target_lines(text,pid,bundle,process="AGRSimulator"):
 markers=[re.compile(rf"(?<!\d){pid}(?!\d)") if pid else None,
          re.compile(re.escape(bundle),re.I) if bundle else None,
          re.compile(rf"\b{re.escape(process)}\b",re.I) if process else None]
 return [line for line in text.splitlines() if any(rx and rx.search(line) for rx in markers)]
def classify_target_exit(pid,disappeared,result_produced,launch_rc,launch_text,app_text,system_text,crash_reports,bundle):
 """Classify only direct target-process evidence; empty means no evidenced death."""
 target_system="\n".join(target_lines(system_text,pid,bundle))
 target_app="\n".join(target_lines(app_text,pid,bundle)) or app_text
 if crash_reports:return "HOST_CRASH"
 if disappeared is None:
  return "" if result_produced or launch_rc==0 else ("LAUNCH_REPLACEMENT" if "already running" in launch_text.lower() else "")
 if re.search(r"exception type|crashed thread|segmentation fault|exc_bad_access",target_system,re.I):return "HOST_CRASH"
 if re.search(r"watchdog|0x8badf00d|jetsam",target_system,re.I):return "WATCHDOG"
 if re.search(r"runningboard[^\n]*(?:terminate|kill)|termination namespace|termination reason",target_system,re.I):return "RUNNINGBOARD_TERMINATION"
 if re.search(r"(?:called abort|abort\(\)|SIGABRT|signal 6)",target_app,re.I):return "EXPLICIT_ABORT_OR_EXIT"
 if re.search(r"(?:termination request from|requested termination|launch replacement)",target_system,re.I):return "EXTERNAL_TERMINATION"
 return "TARGET_PROCESS_DISAPPEARED"
def main():
 p=argparse.ArgumentParser();p.add_argument("--device",required=True);p.add_argument("--bundle",required=True);p.add_argument("--data",required=True);p.add_argument("--artifacts",required=True);p.add_argument("--timeout",type=int,default=150);a=p.parse_args()
 art=pathlib.Path(a.artifacts);art.mkdir(parents=True,exist_ok=True);data=pathlib.Path(a.data);documents=data/"Documents";result=documents/"runtime-smoke.json"
 state_names=["pvs-progress.json","runtime-status.json","runtime-failure.json","debug-failure.json","manual-replay.json","runtime-smoke.json","failure-frame.png"]
 for name in state_names:
  try:(documents/name).unlink(missing_ok=True)
  except OSError:pass
 started=time.time();started_local=datetime.datetime.fromtimestamp(started).strftime("%Y-%m-%d %H:%M:%S");timeline=art/"pvs-process-timeline.ndjson"
 host_log=(art/"pvs-host-log-stream.txt").open("w",encoding="utf-8",errors="replace")
 sim_log=(art/"pvs-simulator-log-stream.txt").open("w",encoding="utf-8",errors="replace")
 pred='process == "AGRSimulator" OR process == "runningboardd" OR subsystem CONTAINS "RunningBoard" OR subsystem CONTAINS "CoreSimulator"'
 streams=[]
 try:
  streams.append(subprocess.Popen(["/usr/bin/log","stream","--style","compact","--predicate",pred],stdout=host_log,stderr=subprocess.STDOUT,text=True,start_new_session=True))
  streams.append(subprocess.Popen(["xcrun","simctl","spawn",a.device,"log","stream","--style","compact","--predicate",pred],stdout=sim_log,stderr=subprocess.STDOUT,text=True,start_new_session=True))
  app_stdout=art/"pvs-app-stdout.txt";app_stderr=art/"pvs-app-stderr.txt"
  rc,out,err=run(["xcrun","simctl","launch","--terminate-running-process",f"--stdout={app_stdout}",f"--stderr={app_stderr}",a.device,a.bundle],art/"pvs-launch.txt")
  match=re.search(r":\s*(\d+)\s*$",out.strip());pid=int(match.group(1)) if match else 0
  launch_time=time.time();last_alive=None;disappeared=None
  with timeline.open("w",encoding="utf-8") as tl:
   while time.time()-launch_time<a.timeout:
    now=time.time();is_alive=bool(pid and alive(pid));tl.write(json.dumps({"epoch":now,"pid":pid,"alive":is_alive})+"\n");tl.flush()
    if is_alive:last_alive=now
    elif last_alive is not None:disappeared=now;break
    if result.is_file() and result.stat().st_size:break
    time.sleep(.1)
  ended=time.time()
 finally:
  for proc in streams:
   try:os.killpg(proc.pid,signal.SIGTERM);proc.wait(timeout=5)
   except Exception:pass
  host_log.close();sim_log.close()
 # Query retained system evidence after the observed interval.
 run(["/usr/bin/log","show","--start",started_local,"--style","compact","--predicate",pred],art/"pvs-host-log-show.txt",60)
 run(["xcrun","simctl","spawn",a.device,"log","show","--last","10m","--style","compact","--predicate",pred],art/"pvs-simulator-log-show.txt",60)
 reports=[]
 roots=[pathlib.Path.home()/"Library/Logs/DiagnosticReports",pathlib.Path.home()/f"Library/Developer/CoreSimulator/Devices/{a.device}/data/Library/Logs/CrashReporter"]
 report_dir=art/"pvs-crash-reports";report_dir.mkdir(exist_ok=True)
 for root in roots:
  if not root.exists():continue
  for source in root.rglob("*"):
   try:
    if not source.is_file() or source.stat().st_mtime<started-2 or source.suffix not in (".ips",".crash"):continue
    content=read(source)
    if "AGRSimulator" not in source.name and "AGRSimulator" not in content and a.bundle not in content:continue
    target=report_dir/(str(len(reports))+"-"+source.name);shutil.copy2(source,target);reports.append(str(target))
   except OSError:pass
 # Preserve the bounded app-side state at the moment of failure without calling guest code.
 state_files={}
 for name in state_names:
  source=documents/name
  if source.is_file():
   target=art/name
   try:shutil.copy2(source,target);state_files[name]=str(target)
   except OSError:pass
 texts=[]
 evidence_paths=[art/"pvs-app-stdout.txt",art/"pvs-app-stderr.txt",art/"pvs-host-log-stream.txt",art/"pvs-simulator-log-stream.txt",art/"pvs-host-log-show.txt",art/"pvs-simulator-log-show.txt",*map(pathlib.Path,reports)]
 for path in evidence_paths:
  if path.exists():texts.append(read(path))
 joined="\n".join(texts);remaining=[]
 crash_fields=bounded_lines("\n".join(read(pathlib.Path(p)) for p in reports),r"exception type|exception codes|termination reason|termination namespace|crashed thread|triggered by thread|faulting thread|fault address|signal")
 system_events=bounded_lines(joined,r"runningboard|termination|terminate|watchdog|jetsam|killed|exited|exit status|signal|crash|abort|invalidated",120)
 app_events=bounded_lines(read(app_stdout)+"\n"+read(app_stderr),r"abort|exit|fatal|exception|failure|guest|runtime|assert",80)
 result_produced=result.is_file() and result.stat().st_size>0
 classification=classify_target_exit(pid,disappeared,result_produced,rc,out+err,read(app_stdout)+"\n"+read(app_stderr),joined,reports,a.bundle)
 if not classification and not result_produced and disappeared is not None:remaining=["TARGET_DISAPPEARED_WITHOUT_TYPED_TERMINATION_EVIDENCE"]
 evidence={"schema_version":1,"classification":classification,"pid":pid,"launch_rc":rc,"launch_timestamp":launch_time,
  "last_alive_timestamp":last_alive,"disappearance_timestamp":disappeared,"collection_end_timestamp":ended,
  "result_produced":result_produced,"crash_reports":reports,"crash_report_fields":crash_fields,
  "system_termination_events":system_events,"app_failure_events":app_events,"state_files":state_files,"remaining_candidates":remaining,
  "missing_evidence":remaining,
  "passive":True,"intrusive":False}
 (art/"process-forensic.json").write_text(json.dumps(evidence,indent=2)+"\n",encoding="utf-8");print(json.dumps(evidence,separators=(",",":")))
 return 0 if evidence["result_produced"] else 1
if __name__=="__main__":raise SystemExit(main())
