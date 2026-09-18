#!/usr/bin/env python3
"""Run the existing Simulator smoke with a deadline and preserve timeout evidence."""

import argparse
import json
import os
import pathlib
import shutil
import signal
import subprocess
import sys
import threading
import time


ROOT = pathlib.Path(__file__).resolve().parents[1]
ARTIFACTS = ROOT / "build" / "artifacts"


def capture(name, command, timeout=12):
    path = ARTIFACTS / name
    try:
        result = subprocess.run(command, capture_output=True, text=True, timeout=timeout)
        path.write_text(result.stdout + "\nSTDERR:\n" + result.stderr, encoding="utf-8")
        return {"exit_code": result.returncode, "file": name}
    except (OSError, subprocess.TimeoutExpired) as exc:
        path.write_text(str(exc), encoding="utf-8")
        return {"error": str(exc), "file": name}


def snapshot():
    evidence = {"reason": "simulator_smoke_timeout", "captured_at_epoch": time.time(),
                "guest_pc": "unavailable", "recent_calls": [], "runtime_failure": "unavailable"}
    evidence["processes"] = capture("timeout-processes.txt", ["ps", "-axo", "pid,ppid,stat,etime,comm"])
    device_file = ARTIFACTS / "simulator-device.txt"
    if not device_file.exists():
        evidence["simulator_devices"] = capture("timeout-simulators.json", ["xcrun", "simctl", "list", "devices", "booted", "-j"])
        return evidence
    device = device_file.read_text(encoding="utf-8").strip()
    evidence["device"] = device
    evidence["launchctl"] = capture("timeout-launchctl.txt", ["xcrun", "simctl", "spawn", device, "launchctl", "list"])
    evidence["syslog"] = capture("timeout-syslog.txt", ["xcrun", "simctl", "spawn", device, "log", "show", "--last", "5m", "--style", "compact", "--predicate", 'process == "AGRSimulator"'], 20)
    evidence["screenshot"] = capture("timeout-screenshot-command.txt", ["xcrun", "simctl", "io", device, "screenshot", str(ARTIFACTS / "timeout-screen.png")])
    try:
        container = subprocess.run(["xcrun", "simctl", "get_app_container", device, "dev.agr.simulator", "data"], capture_output=True, text=True, timeout=12)
        if container.returncode == 0:
            documents = pathlib.Path(container.stdout.strip()) / "Documents"
            copied = []
            for name in ("runtime-status.json", "runtime-failure.json", "debug-failure.json", "manual-replay.json", "failure-frame.png", "kungfoo-frame.png"):
                source = documents / name
                if source.is_file():
                    shutil.copy2(source, ARTIFACTS / ("timeout-" + name))
                    copied.append(name)
            evidence["app_documents"] = copied
            status_path = ARTIFACTS / "timeout-runtime-status.json"
            if status_path.is_file():
                try:
                    status = json.loads(status_path.read_text(encoding="utf-8"))
                    evidence["guest_pc"] = status.get("guest_pc", "unavailable")
                    evidence["recent_calls"] = status.get("recent_calls", [])
                    evidence["runtime_failure"] = status.get("failure_signature") or status.get("runtime_error") or ""
                    evidence["last_frame"] = status.get("frame")
                    evidence["last_android_log"] = status.get("android_log")
                except (OSError, ValueError) as exc:
                    evidence["runtime_status_parse_error"] = str(exc)
        else:
            evidence["app_container_error"] = container.stderr.strip()
    except (OSError, subprocess.TimeoutExpired) as exc:
        evidence["app_container_error"] = str(exc)
    processes = (ARTIFACTS / "timeout-processes.txt").read_text(encoding="utf-8", errors="replace")
    app_processes = [line for line in processes.splitlines()[1:] if line.split() and line.split()[-1].endswith("AGRSimulator")]
    if app_processes:
        pid = app_processes[0].split()[0]
        evidence["host_process_state"] = app_processes[0].strip()
        evidence["host_stack"] = capture("timeout-host-stack.txt", ["sample", pid, "2"], 12)
        evidence["app_pid"] = pid
    return evidence


def relay(stream, path, destination):
    with path.open("w", encoding="utf-8", errors="replace") as output:
        for line in iter(stream.readline, ""):
            output.write(line)
            output.flush()
            destination.write(line)
            destination.flush()


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--timeout-seconds", type=int, default=900)
    args = parser.parse_args()
    deadline = max(1, min(args.timeout_seconds, 900))
    ARTIFACTS.mkdir(parents=True, exist_ok=True)
    env = dict(os.environ, ZERO_INPUT_AB="1")
    child = subprocess.Popen(["bash", "scripts/build-and-run-simulator.sh"], cwd=ROOT, env=env, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True, bufsize=1, start_new_session=True)
    threads = [
        threading.Thread(target=relay, args=(child.stdout, ARTIFACTS / "smoke-stdout.log", sys.stdout), daemon=True),
        threading.Thread(target=relay, args=(child.stderr, ARTIFACTS / "smoke-stderr.log", sys.stderr), daemon=True),
    ]
    for thread in threads:
        thread.start()
    try:
        result = child.wait(timeout=deadline)
    except subprocess.TimeoutExpired:
        evidence = snapshot()
        evidence["timeout_seconds"] = deadline
        evidence["last_progress_lines"] = (ARTIFACTS / "smoke-stdout.log").read_text(encoding="utf-8", errors="replace").splitlines()[-20:]
        (ARTIFACTS / "simulator-smoke-timeout.json").write_text(json.dumps(evidence, indent=2), encoding="utf-8")
        try:
            os.killpg(child.pid, signal.SIGTERM)
            child.wait(timeout=10)
        except (ProcessLookupError, subprocess.TimeoutExpired):
            try:
                os.killpg(child.pid, signal.SIGKILL)
            except ProcessLookupError:
                pass
        print("Simulator smoke exceeded hard timeout; evidence saved in build/artifacts", file=sys.stderr)
        return 124
    for thread in threads:
        thread.join(timeout=5)
    if result != 0:
        evidence = snapshot()
        evidence["reason"] = "simulator_smoke_failed"
        evidence["exit_code"] = result
        evidence["last_progress_lines"] = (ARTIFACTS / "smoke-stdout.log").read_text(
            encoding="utf-8", errors="replace").splitlines()[-20:]
        (ARTIFACTS / "simulator-smoke-failure.json").write_text(
            json.dumps(evidence, indent=2), encoding="utf-8")
        print("Simulator smoke failed; evidence saved in build/artifacts",
              file=sys.stderr)
    return result


if __name__ == "__main__":
    raise SystemExit(main())
