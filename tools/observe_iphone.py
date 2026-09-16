"""Collect AGR device status, replay, syslog and crash reports over USB."""

import argparse
import json
import os
import subprocess
import sys
import threading
import time
from pathlib import Path


def device_command(root: Path) -> list[str]:
    local = root / ".tools" / "run_pmd3.py"
    return [sys.executable, str(local)] if local.exists() else [sys.executable, "-m", "pymobiledevice3"]


def copy_stream(process: subprocess.Popen, output: Path, statuses: Path | None = None) -> None:
    with output.open("a", encoding="utf-8") as log:
        for line in process.stdout:
            log.write(line)
            log.flush()
            if statuses is not None and "AGR_STATUS " in line:
                payload = line.split("AGR_STATUS ", 1)[1].strip()
                try:
                    state = json.loads(payload)
                except json.JSONDecodeError:
                    continue
                with statuses.open("a", encoding="utf-8") as target:
                    target.write(json.dumps(state, ensure_ascii=False) + "\n")
                print(f"swap={state.get('swap')} pc={state.get('guest_pc')} "
                      f"inputs={len(state.get('recent_inputs', []))} "
                      f"failure={state.get('failure_signature', '')}", flush=True)


def pull(base: list[str], bundle: str, remote: str, local: Path) -> bool:
    temporary = local.with_suffix(local.suffix + ".download")
    try:
        result = subprocess.run(
            base + ["apps", "pull", bundle, remote, str(temporary), "--documents"],
            capture_output=True,
            timeout=20,
        )
        if result.returncode or not temporary.is_file():
            return False
        os.replace(temporary, local)
        return True
    except (OSError, subprocess.TimeoutExpired):
        return False
    finally:
        temporary.unlink(missing_ok=True)


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--bundle-id", default="dev.agr.simulator")
    parser.add_argument("--interval", type=float, default=3.0)
    parser.add_argument("--output", type=Path)
    args = parser.parse_args()
    root = Path(__file__).resolve().parents[1]
    output = args.output or root / "artifacts" / "iphone-live" / time.strftime("%Y%m%d-%H%M%S")
    output.mkdir(parents=True, exist_ok=True)
    base = device_command(root)
    streams = [
        ("syslog", base + ["syslog", "live", "-m", "AGR"]),
        ("crash", base + ["crash", "watch", "--name", "AGRSimulator", "--format", "json"]),
    ]
    processes = []
    for name, command in streams:
        error = (output / f"{name}.stderr.log").open("a", encoding="utf-8")
        process = subprocess.Popen(command, stdout=subprocess.PIPE, stderr=error,
                                   text=True, encoding="utf-8", errors="replace", bufsize=1)
        target = output / ("syslog.log" if name == "syslog" else "crash.ndjson")
        thread = threading.Thread(target=copy_stream, args=(process, target,
                                  output / "runtime-status.ndjson" if name == "syslog" else None), daemon=True)
        thread.start()
        processes.append((process, error))
    print(f"AGR iPhone evidence: {output}", flush=True)
    try:
        while True:
            for name in ("runtime-status.json", "manual-replay.json"):
                pull(base, args.bundle_id, name, output / name)
            failure = output / "runtime-failure.json"
            if pull(base, args.bundle_id, failure.name, failure):
                for name in ("debug-failure.json", "failure-frame.png"):
                    pull(base, args.bundle_id, name, output / name)
            time.sleep(args.interval)
    except KeyboardInterrupt:
        pass
    finally:
        for process, error in processes:
            process.terminate()
            try:
                process.wait(timeout=5)
            except subprocess.TimeoutExpired:
                process.kill()
            error.close()


if __name__ == "__main__":
    main()
