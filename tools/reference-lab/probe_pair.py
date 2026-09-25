#!/usr/bin/env python3
"""Boot one API19 image and record a pinned APK launch and optional actions."""

import argparse
import hashlib
import json
import os
import re
import signal
import subprocess
import time
from contextlib import ExitStack
from itertools import chain
from pathlib import Path

from parse_trace_log import parse_lines
from preload_inventory import preload_inventory
from png_frame import has_visible_variation


def hash_file(path):
    digest = hashlib.sha256()
    with path.open("rb") as stream:
        for chunk in iter(lambda: stream.read(1024 * 1024), b""):
            digest.update(chunk)
    return digest.hexdigest()


def adb(serial, *args, timeout=120, text=True):
    result = subprocess.run(["adb", "-s", serial, *args], check=True,
                            capture_output=True, text=text, timeout=timeout)
    return result.stdout


def guest_pid(serial, process_name):
    for line in adb(serial, "shell", "ps", timeout=30).splitlines()[1:]:
        fields = line.split()
        if len(fields) >= 3 and fields[-1] == process_name and fields[1].isdigit():
            return fields[1]
    raise RuntimeError(f"guest process not found: {process_name}")


def mapped_libraries(maps):
    return sorted({path for line in maps.splitlines()
                   for path in line.split()[5:6] if path.endswith(".so")})


def process_snapshot(serial, package):
    try:
        pid = guest_pid(serial, package)
    except RuntimeError:
        return {"alive": False}
    status = adb(serial, "shell", "cat", f"/proc/{pid}/status", timeout=30)
    stat = adb(serial, "shell", "cat", f"/proc/{pid}/stat", timeout=30)
    fields = stat.rsplit(") ", 1)[-1].split()
    values = {}
    for line in status.splitlines():
        if line.startswith(("Threads:", "VmRSS:", "VmSize:")):
            key, value = line.split(":", 1)
            values[key] = value.strip()
    return {"alive": True, "pid": int(pid), "threads": values.get("Threads"),
            "rss": values.get("VmRSS"), "vmsize": values.get("VmSize"),
            "utime_ticks": int(fields[11]), "stime_ticks": int(fields[12])}


def app_crash_lines(logcat, package, pids):
    incidents = []
    for line in logcat.splitlines():
        if "AndroidRuntime: Process: " + package + "," in line:
            incidents.append(line)
        elif "Fatal signal " in line:
            parts = line.split()
            if any(str(pid) in parts[:5] for pid in pids):
                incidents.append(line)
    return incidents


def capture_step(serial, result_dir, package, label, expect_foreground=True,
                 expect_alive=None):
    activity = adb(serial, "shell", "dumpsys", "activity", "activities", timeout=60)
    window = adb(serial, "shell", "dumpsys", "window", "windows", timeout=60)
    resumed = any("mResumedActivity" in line and package in line
                  for line in activity.splitlines())
    focused = any("mCurrentFocus" in line and package in line
                  for line in window.splitlines())
    if expect_foreground and not resumed:
        raise RuntimeError(f"{label}: sample activity is not resumed")
    if expect_foreground and not focused:
        raise RuntimeError(f"{label}: sample activity is not the visible focused window")
    if not expect_foreground and (resumed or focused):
        raise RuntimeError(f"{label}: sample unexpectedly remains in foreground")
    remote = "/data/local/tmp/agr-reference.png"
    screenshot = result_dir / f"screen-{label}.png"
    adb(serial, "shell", "screencap", "-p", remote, timeout=60)
    adb(serial, "pull", remote, str(screenshot), timeout=60)
    if not screenshot.read_bytes().startswith(b"\x89PNG\r\n\x1a\n"):
        raise RuntimeError(f"{label}: screenshot is not PNG")
    process = process_snapshot(serial, package)
    if expect_alive is not None and process["alive"] != expect_alive:
        raise RuntimeError(f"{label}: app process liveness differs from scenario")
    return {"label": label, "resumed": resumed, "focused": focused,
            "screenshot": str(screenshot), "screenshot_sha256": hash_file(screenshot),
            "visible_variation": has_visible_variation(screenshot),
            "process": process,
            "resumed_line": next((line.strip() for line in activity.splitlines()
                                  if "mResumedActivity" in line), ""),
            "focus_line": next((line.strip() for line in window.splitlines()
                                if "mCurrentFocus" in line), "")}


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--pair", type=Path,
                        help="omit only for an unpaired CLEAN smoke test")
    parser.add_argument("--root", default="/agr-reference", type=Path)
    parser.add_argument("--apk", required=True, type=Path)
    parser.add_argument("--variant", required=True, choices=("CLEAN", "TRACE"))
    parser.add_argument("--arch", choices=("x86", "arm"), default="x86")
    parser.add_argument("--component", default="org.jfedor.frozenbubble/.FrozenBubble")
    parser.add_argument("--scenario", default="cold_start")
    parser.add_argument("--boot-timeout", type=int, default=600)
    parser.add_argument("--settle", type=int, default=20)
    parser.add_argument("--reuse-data", action="store_true")
    parser.add_argument("--gpu", choices=("auto", "on", "off"), default="auto")
    parser.add_argument("--show-window", action="store_true")
    parser.add_argument("--actions", type=Path,
                        help="JSON list of timed tap, swipe, keyevent, home, or resume actions")
    args = parser.parse_args()
    actions = json.loads(args.actions.read_text()) if args.actions else []
    if not isinstance(actions, list):
        raise SystemExit("actions must be a JSON list")
    for index, action in enumerate(actions):
        if not isinstance(action, dict) or action.get("type") not in \
                ("wait", "tap", "swipe", "keyevent", "home", "resume",
                 "force_stop", "relaunch"):
            raise SystemExit(f"invalid action {index}")
        if not 0 <= action.get("delay", 0) <= 300:
            raise SystemExit(f"invalid action delay {index}")
        if "expect_foreground" in action and not isinstance(action["expect_foreground"], bool):
            raise SystemExit(f"invalid foreground expectation {index}")
        if "expect_alive" in action and not isinstance(action["expect_alive"], bool):
            raise SystemExit(f"invalid process expectation {index}")

    variant = args.variant.lower()
    image_dir = ("clean-image" if variant == "clean" else "trace-image")
    if args.arch == "arm":
        image_dir = "arm-" + image_dir
    out = args.root / image_dir / "build-out"
    product = out / "target/product" / ("generic_x86" if args.arch == "x86" else "generic")
    if args.pair:
        pair = json.loads(args.pair.read_text())
        if pair.get("status") != "BUILD_VERIFIED":
            raise SystemExit("CLEAN/TRACE pair is not build-verified")
        image = pair[variant]
        if image.get("build_flavor") != f"aosp_{args.arch}-eng":
            raise SystemExit("pair build flavor does not match requested architecture")
        pair_status = "BUILD_VERIFIED"
    elif variant == "clean":
        image = {"image_sha256": (out / "system.img.sha256").read_text().split()[0],
                 "execution_mode": "int:portable",
                 "libdvm_sha256": hash_file(product / "system/lib/libdvm.so")}
        pair_status = "UNPAIRED_CLEAN_SMOKE"
    else:
        raise SystemExit("TRACE probe requires a build-verified pair")
    if hash_file(product / "system.img") != image["image_sha256"]:
        raise SystemExit("system image changed after pair verification")
    if image["execution_mode"] != "int:portable":
        raise SystemExit("reference execution mode is not portable")
    apk_hash = hash_file(args.apk)
    package = args.component.split("/")[0]
    if not re.fullmatch(r"[A-Za-z0-9_.]+", package):
        raise SystemExit("invalid package in component")
    lab_name = "aosp-r2" if args.arch == "x86" else "aosp-r2-arm"
    result_dir = args.root / "emulator" / lab_name / variant / package / args.scenario
    result_dir.mkdir(parents=True, exist_ok=True)
    record_path = result_dir / "probe.json"
    record = {"status": "FAILED", "stage": "launch_emulator", "variant": args.variant,
              "baseline": "android-4.4.4_r2", "image_sha256": image["image_sha256"],
              "apk_sha256": apk_hash, "scenario": args.scenario,
              "package": package, "arch": args.arch,
              "execution_mode": "int:portable", "pair_status": pair_status,
              "data_reused": args.reuse_data,
              "actions_sha256": (hash_file(args.actions) if args.actions else
                                 hashlib.sha256(b"[]").hexdigest())}
    port = 5554 if variant == "clean" else 5556
    serial = f"emulator-{port}"
    emulator = args.root / "clean-image/build-out/host/linux-x86/bin" / \
        ("emulator64-x86" if args.arch == "x86" else "emulator64-arm")
    command = [str(emulator), "-sysdir", str(product), "-system", str(product / "system.img"),
               "-ramdisk", str(product / "ramdisk.img"), "-data", str(result_dir / "userdata.img"),
               "-memory", "1024", "-no-audio", "-no-boot-anim", "-no-snapshot",
               "-gpu", args.gpu,
               "-ports", f"{port},{port + 1}",
               "-prop", "dalvik.vm.execution-mode=int:portable"]
    if not args.reuse_data:
        command.append("-wipe-data")
    if not args.show_window:
        command.append("-no-window")
    kernel = product / "kernel"
    if not kernel.is_file():
        kernel = args.root / "aosp-official-sync-4.4.4-r2/prebuilts/qemu-kernel" / \
            args.arch / "kernel-qemu"
    if not kernel.is_file():
        raise SystemExit("pinned QEMU kernel is missing")
    command += ["-kernel", str(kernel)]
    record["kernel_sha256"] = hash_file(kernel)
    if (product / "userdata.img").is_file():
        command += ["-initdata", str(product / "userdata.img")]
    # WSL exposes /dev/kvm here, but this 2014 emulator's KVM_CREATE_VM ioctl
    # fails. Its pinned QEMU source supports -disable-kvm for software boot.
    command += ["-qemu", "-disable-kvm"]
    record["kvm_device_accessible"] = os.access("/dev/kvm", os.R_OK | os.W_OK)
    record["accel"] = "tcg"
    record["gpu_mode"] = args.gpu
    record["show_window"] = args.show_window
    record["command"] = command
    existing = subprocess.run(["pgrep", "-a", "emulator64-x86"],
                              capture_output=True, text=True, check=False)
    if f"-ports {port},{port + 1}" in existing.stdout:
        raise SystemExit(f"emulator ports {port},{port + 1} are already owned")
    emulator_env = os.environ.copy()
    if args.show_window:
        gl_dir = args.root / "toolchains/legacy-emulator-gl"
        if not (gl_dir / "libGL.so").is_file():
            raise SystemExit("windowed GPU probe requires a host libGL.so")
        emulator_env["LD_LIBRARY_PATH"] = (str(gl_dir) + ":" +
                                            emulator_env.get("LD_LIBRARY_PATH", ""))
        record["host_libgl_sha256"] = hash_file(gl_dir / "libGL.so")
    process = None
    boot_stream = None
    boot_logger = None
    trace_stream = None
    trace_logger = None
    try:
        with (result_dir / "emulator.log").open("wb") as log:
            process = subprocess.Popen(command, stdout=log, stderr=subprocess.STDOUT,
                                       env=emulator_env,
                                       start_new_session=True)
            deadline = time.monotonic() + args.boot_timeout
            record["stage"] = "boot"
            while time.monotonic() < deadline:
                if process.poll() is not None:
                    raise RuntimeError(f"emulator exited with {process.returncode}")
                try:
                    completed = adb(serial, "shell", "getprop", "sys.boot_completed", timeout=12).strip()
                    if boot_logger is None:
                        boot_stream = (result_dir / "boot.logcat").open("wb")
                        boot_logger = subprocess.Popen(
                            ["adb", "-s", serial, "logcat", "-v", "threadtime"],
                            stdout=boot_stream, stderr=subprocess.PIPE,
                            start_new_session=True)
                except (subprocess.SubprocessError, OSError):
                    completed = ""
                if completed == "1":
                    break
                time.sleep(5)
            else:
                raise RuntimeError("API19 boot timed out")
            record["release"] = adb(serial, "shell", "getprop", "ro.build.version.release").strip()
            record["sdk"] = adb(serial, "shell", "getprop", "ro.build.version.sdk").strip()
            record["live_execution_mode"] = adb(
                serial, "shell", "getprop", "dalvik.vm.execution-mode").strip()
            record["fingerprint"] = adb(serial, "shell", "getprop", "ro.build.fingerprint").strip()
            if (record["release"], record["sdk"], record["live_execution_mode"]) != \
                    ("4.4.4", "19", "int:portable"):
                raise RuntimeError("guest release, SDK, or execution mode mismatched")
            if boot_logger is None or boot_logger.poll() is not None:
                raise RuntimeError("streaming boot logcat did not start")
            time.sleep(2)
            boot_logger.terminate()
            boot_logger.wait(timeout=10)
            boot_stream.close()
            boot_stream = None
            boot_log = (result_dir / "boot.logcat").read_text(errors="replace")
            guest_framework = result_dir / "guest-framework.jar"
            adb(serial, "pull", "/system/framework/framework.jar", str(guest_framework),
                timeout=120)
            if hash_file(guest_framework) != hash_file(product / "system/framework/framework.jar"):
                raise RuntimeError("guest framework.jar differs from verified image output")
            preload = preload_inventory(guest_framework, boot_log)
            (result_dir / "zygote-preload.json").write_text(
                json.dumps(preload, indent=2) + "\n")
            record["zygote_preload"] = {
                key: preload[key] for key in ("configured_class_count",
                                             "configured_classes_sha256",
                                             "completed_count", "failed_classes",
                                             "class_state")}
            if preload["class_state"] != "PRELOADED_IN_ZYGOTE":
                raise RuntimeError("Zygote preload closure is not proven")
            zygote_pid = guest_pid(serial, "zygote")
            zygote_maps = adb(serial, "shell", "cat", f"/proc/{zygote_pid}/maps", timeout=30)
            (result_dir / "zygote.maps").write_text(zygote_maps)
            record["zygote_loaded_libraries"] = mapped_libraries(zygote_maps)
            vm_keys = ("dalvik.vm.execution-mode", "dalvik.vm.dexopt-flags",
                       "dalvik.vm.checkjni", "ro.kernel.android.checkjni",
                       "dalvik.vm.jit.codecachesize", "dalvik.vm.jit.threshold",
                       "dalvik.vm.lib")
            record["vm_config"] = {key: adb(serial, "shell", "getprop", key).strip()
                                   for key in vm_keys}
            # API19 Init.cpp starts the JIT compiler only for kExecutionModeJit.
            record["jit_effective"] = "disabled_by_int_portable"
            guest_dvm = result_dir / "guest-libdvm.so"
            adb(serial, "pull", "/system/lib/libdvm.so", str(guest_dvm), timeout=120)
            record["guest_libdvm_sha256"] = hash_file(guest_dvm)
            if record["guest_libdvm_sha256"] != image["libdvm_sha256"]:
                raise RuntimeError("guest libdvm differs from verified build artifact")
            if variant == "trace":
                clean_record_path = (args.root / "emulator" / lab_name / "clean" /
                                     package / args.scenario / "probe.json")
                if not clean_record_path.is_file():
                    raise RuntimeError("matched CLEAN probe is missing for this scenario")
                clean_record = json.loads(clean_record_path.read_text())
                matched_fields = ("apk_sha256", "scenario", "arch", "execution_mode",
                                  "vm_config", "jit_effective", "gpu_mode", "show_window",
                                  "data_reused", "accel", "zygote_preload",
                                  "zygote_loaded_libraries", "actions_sha256")
                if clean_record.get("status") != "PASS" or \
                        clean_record.get("pair_status") != "BUILD_VERIFIED" or \
                        any(clean_record.get(key) != record.get(key) for key in matched_fields):
                    raise RuntimeError("CLEAN/TRACE runtime config or input mismatch")
            record["stage"] = "package_manager"
            package_deadline = time.monotonic() + 300
            while True:
                try:
                    packages = adb(serial, "shell", "pm", "list", "packages", timeout=45)
                    if "package:com.android.settings" in packages:
                        break
                except subprocess.SubprocessError:
                    pass
                if time.monotonic() >= package_deadline:
                    raise RuntimeError("package manager did not become ready in 300 seconds")
                time.sleep(5)
            record["stage"] = "install"
            install = adb(serial, "install", "-r", str(args.apk), timeout=240)
            if "Success" not in install:
                raise RuntimeError("APK installation did not succeed: " + install.strip())
            record["install_result"] = install.strip()
            adb(serial, "logcat", "-c", timeout=30)
            # Keep the guest filesystem setup identical in CLEAN and TRACE.
            adb(serial, "shell", "chmod", "777", "/data/local/tmp")
            adb(serial, "shell", "mkdir", "-p", "/data/local/tmp/agrtrace")
            adb(serial, "shell", "chmod", "777", "/data/local/tmp/agrtrace")
            lifecycle_log = result_dir / ("trace.logcat" if variant == "trace"
                                          else "runtime.logcat")
            trace_stream = lifecycle_log.open("wb")
            trace_logger = subprocess.Popen(
                ["adb", "-s", serial, "logcat", "-v", "threadtime"],
                stdout=trace_stream, stderr=subprocess.PIPE,
                start_new_session=True)
            adb(serial, "shell", "input", "keyevent", "82", timeout=30)
            adb(serial, "shell", "input", "swipe", "160", "370", "160", "80", "300",
                timeout=30)
            record["stage"] = "activity"
            record["activity_result"] = adb(
                serial, "shell", "am", "start", "-W", "-n", args.component,
                timeout=120).strip()
            if "Status: ok" not in record["activity_result"]:
                raise RuntimeError("Activity launch did not report Status: ok")
            time.sleep(args.settle)
            record["stage"] = "capture"
            record["steps"] = [capture_step(serial, result_dir, package, "launch")]
            record["screenshot_sha256"] = record["steps"][0]["screenshot_sha256"]
            app_pid = guest_pid(serial, package)
            app_maps = adb(serial, "shell", "cat", f"/proc/{app_pid}/maps", timeout=30)
            (result_dir / "app.maps").write_text(app_maps)
            app_libraries = mapped_libraries(app_maps)
            record["app_loaded_libraries"] = app_libraries
            record["inherited_library_candidates"] = sorted(
                set(app_libraries) & set(record["zygote_loaded_libraries"]))
            for index, action in enumerate(actions):
                kind = action["type"]
                record["stage"] = f"action_{index}_{kind}"
                if kind == "tap":
                    adb(serial, "shell", "input", "tap", str(action["x"]), str(action["y"]))
                elif kind == "swipe":
                    adb(serial, "shell", "input", "swipe", *(str(action[key]) for key in
                        ("x1", "y1", "x2", "y2", "duration_ms")))
                elif kind == "keyevent":
                    adb(serial, "shell", "input", "keyevent", str(action["keycode"]))
                elif kind == "home":
                    adb(serial, "shell", "input", "keyevent", "3")
                elif kind == "force_stop":
                    adb(serial, "shell", "am", "force-stop", package)
                elif kind in ("resume", "relaunch"):
                    adb(serial, "shell", "am", "start", "-W", "-n", args.component)
                time.sleep(action.get("delay", 2))
                step = capture_step(
                    serial, result_dir, package, f"{index:02d}-{kind}",
                    expect_foreground=action.get("expect_foreground",
                                                 kind not in ("home", "force_stop")),
                    expect_alive=action.get("expect_alive",
                                            False if kind == "force_stop" else None))
                step["action"] = action
                record["steps"].append(step)
            record["visual_status"] = (
                "VISIBLE_CONTENT" if any(step["visible_variation"] for step in record["steps"])
                else "UNIFORM_FRAME_INCONCLUSIVE")
            time.sleep(2)
            if trace_logger.poll() is not None:
                raise RuntimeError("streaming lifecycle logcat exited before capture")
            trace_logger.terminate()
            trace_logger.wait(timeout=10)
            trace_stream.close()
            trace_stream = None
            runtime_log = lifecycle_log.read_text(errors="replace")
            observed_pids = {step["process"]["pid"] for step in record["steps"]
                             if step["process"]["alive"]}
            record["app_crash_lines"] = app_crash_lines(runtime_log, package, observed_pids)
            if record["app_crash_lines"]:
                raise RuntimeError("app crash observed during lifecycle scenario")
            if variant == "trace":
                direct_dir = result_dir / "trace-direct"
                direct_dir.mkdir(exist_ok=True)
                direct_files = []
                for pid in sorted(observed_pids):
                    target = direct_dir / f"trace-{pid}.log"
                    adb(serial, "pull", f"/data/local/tmp/agrtrace/trace-{pid}.log",
                        str(target), timeout=240)
                    direct_files.append(target)
                with ExitStack() as stack:
                    streams = [stack.enter_context(path.open(errors="replace"))
                               for path in direct_files]
                    events = parse_lines(chain.from_iterable(streams),
                                         allowed_pids=observed_pids)
                events_path = result_dir / "events.ndjson"
                events_path.write_text("".join(json.dumps(event, sort_keys=True) + "\n"
                                               for event in events))
                record["event_count"] = len(events)
                evidence = {"variant": "TRACE", "instrumented": True,
                            "role": "dependency_mapper", "baseline": "android-4.4.4_r2",
                            "image_sha256": image["image_sha256"], "apk_sha256": apk_hash,
                            "scenario": args.scenario, "events_sha256": hash_file(events_path),
                            "process_ids": sorted(observed_pids),
                            "streamed_logcat_sha256": hash_file(result_dir / "trace.logcat"),
                            "direct_trace_sha256": {path.name: hash_file(path)
                                                    for path in direct_files},
                            "trace_transport": "guest_per_pid_direct_file_v2",
                            "observer_coverage": ["APP_DEX_TO_BOOT_METHOD_INVOKE"],
                            "observation_scope": "APP_TRIGGERED_OBSERVED_LOWER_BOUND",
                            "zygote_preload_sha256": hash_file(result_dir / "zygote-preload.json"),
                            "runtime_config": record["vm_config"],
                            "may_authorize_pruning": False}
                (result_dir / "trace-run.json").write_text(json.dumps(evidence, indent=2) + "\n")
            record["status"] = "PASS"
            record["stage"] = "complete"
    except (OSError, RuntimeError, subprocess.SubprocessError, ValueError) as exc:
        record["error"] = str(exc)
        raise
    finally:
        if boot_logger is not None and boot_logger.poll() is None:
            boot_logger.terminate()
            try:
                boot_logger.wait(timeout=10)
            except subprocess.TimeoutExpired:
                boot_logger.kill()
        if boot_stream is not None:
            boot_stream.close()
        if trace_logger is not None and trace_logger.poll() is None:
            trace_logger.terminate()
            try:
                trace_logger.wait(timeout=10)
            except subprocess.TimeoutExpired:
                trace_logger.kill()
        if trace_stream is not None:
            trace_stream.close()
        if process is not None and process.poll() is None and not \
                (result_dir / "runtime.logcat").is_file() and not \
                (result_dir / "trace.logcat").is_file():
            try:
                diagnostic_log = result_dir / "runtime.logcat"
                diagnostic_log.write_text(adb(serial, "logcat", "-d", "-v", "threadtime",
                                              timeout=30))
                record["runtime_logcat_sha256"] = hash_file(diagnostic_log)
            except (OSError, subprocess.SubprocessError):
                pass
        record_path.write_text(json.dumps(record, indent=2) + "\n")
        if process is not None and process.poll() is None:
            os.killpg(process.pid, signal.SIGTERM)
            try:
                process.wait(timeout=15)
            except subprocess.TimeoutExpired:
                os.killpg(process.pid, signal.SIGKILL)
        print(json.dumps({"status": record["status"], "stage": record["stage"],
                          "record": str(record_path)}))


if __name__ == "__main__":
    main()
