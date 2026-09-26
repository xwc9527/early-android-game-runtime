#!/usr/bin/env python3
"""Build and run the Dalvik.JNINativeBinding CLEAN and AGR fixtures.

The comparator result is an observation. It does not write governance state.
The guest .so is linked with the pinned AOSP NDK android-18 sysroot so it can
load on the x86 image; the process that executes RegisterNatives is dalvikvm
from /agr-reference/clean-image system.img.
"""
import hashlib
import os
import pathlib
import signal
import subprocess
import sys
import time


REPO = pathlib.Path(__file__).resolve().parents[2]
LAB = pathlib.Path(os.environ.get("AGR_REFERENCE_ROOT", "/agr-reference"))
OUT = pathlib.Path(os.environ.get("AGR_JNI_BINDING_OUT", "/var/tmp/agr-jni-binding"))
PORT = 5584
SOURCES = [
    "Runtime/DexLoom/Base/dx_log.c",
    "Runtime/DexLoom/Base/dx_memory.c",
    "Runtime/DexLoom/Base/dx_arena.c",
    "Runtime/DexLoom/DEX/dx_dex.c",
    "Runtime/DexLoom/DEX/dx_opcode.c",
    "Runtime/DexLoom/DEX/dx_verifier.c",
    "Runtime/DexLoom/VM/dx_vm.c",
    "Runtime/DexLoom/VM/dx_interpreter.c",
    "Runtime/DexLoom/VM/dx_jni.c",
    "Runtime/DexLoom/VM/dx_exec.c",
    "Runtime/DexLoom/VM/dx_indirect_ref.c",
]


def sha256(path):
    digest = hashlib.sha256()
    with open(path, "rb") as handle:
        for chunk in iter(lambda: handle.read(1024 * 1024), b""):
            digest.update(chunk)
    return digest.hexdigest()


def run(command, **kwargs):
    print("+", " ".join(str(part) for part in command), flush=True)
    return subprocess.run(command, check=True, **kwargs)


def build_agr():
    obj = OUT / "obj"
    obj.mkdir(parents=True, exist_ok=True)
    common = ["-std=gnu11", "-O1", "-I", "Runtime/DexLoom/Include",
              "-I", "Runtime/DexLoom", "-I", "Tests/DexLoom/JniNativeBinding",
              "-w", "-pthread"]
    objects = []
    for source in SOURCES:
        output = obj / (pathlib.Path(source).stem + ".o")
        run(["cc", *common, "-c", source, "-o", str(output)], cwd=REPO)
        objects.append(output)
    host_object = obj / "jni-native-binding-host.o"
    run(["cc", *common, "-Wall", "-Wextra", "-Werror", "-c",
         "Tests/DexLoom/jni-native-binding-host.c", "-o", str(host_object)], cwd=REPO)
    binary = OUT / "jni-native-binding-host"
    run(["cc", "-pthread", *[str(path) for path in objects], str(host_object),
         "-lz", "-lm", "-o", str(binary)])
    agr_json = OUT / "agr.json"
    with agr_json.open("w", encoding="utf-8") as handle:
        run([str(binary)], cwd=REPO, stdout=handle)
    return binary, agr_json


def build_clean():
    gcc = (LAB / "aosp-official-sync-4.4.4-r2/prebuilts/gcc/linux-x86/x86/"
           "i686-linux-android-4.7/bin/i686-linux-android-gcc")
    sysroot = (LAB / "aosp-official-sync-4.4.4-r2/prebuilts/ndk/current/platforms/"
               "android-18/arch-x86")
    dx = LAB / "clean-image/build-out/host/linux-x86/bin/dx"
    classes = OUT / "classes"
    classes.mkdir(parents=True, exist_ok=True)
    run(["javac", "--release", "7", "-d", str(classes),
         "Tests/DexLoom/JniNativeBinding/Probe.java"], cwd=REPO)
    dex = OUT / "probe.dex"
    run([str(dx), "--dex", "--output", str(dex), str(classes)])
    library = OUT / "libjnibind.so"
    run([str(gcc), "--sysroot", str(sysroot), "-shared", "-fPIC", "-O2", "-std=gnu99",
         "-Wall", "-Wextra", "-I", str(REPO / "Tests/DexLoom/JniNativeBinding"),
         "-o", str(library),
         str(REPO / "Tests/DexLoom/JniNativeBinding/jni_native_binding_clean.c")])
    return dex, library


def boot():
    product = LAB / "clean-image/build-out/target/product/generic_x86"
    system = product / "system.img"
    hostbin = LAB / "clean-image/build-out/host/linux-x86/bin"
    kernel = product / "kernel"
    if not kernel.is_file():
        kernel = LAB / "aosp-official-sync-4.4.4-r2/prebuilts/qemu-kernel/x86/kernel-qemu"
    data = OUT / "userdata.img"
    if data.exists():
        data.unlink()
    log_path = OUT / "emulator.log"
    log = log_path.open("wb")
    command = [
        str(hostbin / "emulator64-x86"), "-sysdir", str(product), "-system", str(system),
        "-ramdisk", str(product / "ramdisk.img"), "-data", str(data), "-memory", "1024",
        "-no-audio", "-no-boot-anim", "-no-snapshot", "-gpu", "off",
        "-ports", "%d,%d" % (PORT, PORT + 1),
        "-prop", "dalvik.vm.execution-mode=int:portable", "-no-window",
        "-kernel", str(kernel), "-initdata", str(product / "userdata.img"), "-wipe-data",
        "-qemu", "-disable-kvm",
    ]
    env = os.environ.copy()
    env["PATH"] = str(hostbin) + os.pathsep + env.get("PATH", "")
    run([str(hostbin / "adb"), "start-server"])
    print("+", " ".join(command), flush=True)
    process = subprocess.Popen(command, stdout=log, stderr=subprocess.STDOUT,
                               env=env, start_new_session=True)
    adb = str(hostbin / "adb")
    serial = "emulator-%d" % PORT
    deadline = time.monotonic() + 240
    booted = False
    while time.monotonic() < deadline:
        if process.poll() is not None:
            log.close()
            sys.stderr.write(log_path.read_text(errors="replace")[-4000:])
            raise SystemExit("emulator exited %s" % process.returncode)
        probe = subprocess.run([adb, "-s", serial, "shell", "getprop", "sys.boot_completed"],
                               capture_output=True, text=True)
        if probe.stdout.replace("\r", "").strip() == "1":
            booted = True
            break
        time.sleep(5)
    if not booted:
        stop_emulator(process)
        log.close()
        sys.stderr.write(log_path.read_text(errors="replace")[-4000:])
        raise SystemExit("CLEAN image did not reach sys.boot_completed=1")
    return process, adb, serial


def stop_emulator(process):
    if process.poll() is not None:
        return
    try:
        os.killpg(process.pid, signal.SIGTERM)
    except ProcessLookupError:
        return
    deadline = time.monotonic() + 20
    while time.monotonic() < deadline and process.poll() is None:
        time.sleep(1)
    if process.poll() is None:
        os.killpg(process.pid, signal.SIGKILL)


def run_clean(adb, serial, dex, library):
    run([adb, "-s", serial, "push", str(library), "/data/local/tmp/libjnibind.so"])
    run([adb, "-s", serial, "push", str(dex), "/data/local/tmp/probe.dex"])
    guest = subprocess.run(
        [adb, "-s", serial, "shell",
         "/system/bin/dalvikvm -cp /data/local/tmp/probe.dex Probe /data/local/tmp/libjnibind.so"],
        capture_output=True, text=True)
    (OUT / "dalvikvm.stdout").write_text(guest.stdout, encoding="utf-8", errors="replace")
    (OUT / "dalvikvm.stderr").write_text(guest.stderr, encoding="utf-8", errors="replace")
    print("dalvikvm exit", guest.returncode, flush=True)
    if guest.stdout:
        print(guest.stdout, flush=True)
    if guest.stderr:
        print(guest.stderr, file=sys.stderr, flush=True)
    pulled = subprocess.run(
        [adb, "-s", serial, "pull", "/data/local/tmp/jnibind-clean.json",
         str(OUT / "clean.json")],
        capture_output=True, text=True)
    if pulled.returncode != 0 or not (OUT / "clean.json").is_file():
        sys.stderr.write(pulled.stdout + pulled.stderr)
        raise SystemExit("CLEAN fixture did not write jnibind-clean.json")
    return guest.returncode


def canonical_sha(path):
    import json
    document = json.loads(path.read_text(encoding="utf-8"))
    payload = json.dumps(document, sort_keys=True, separators=(",", ":")) + "\n"
    return hashlib.sha256(payload.encode("utf-8")).hexdigest(), payload


def main():
    OUT.mkdir(parents=True, exist_ok=True)
    system = LAB / "clean-image/build-out/target/product/generic_x86/system.img"
    image_before = sha256(system)
    print("CLEAN image SHA-256", image_before, flush=True)
    binary, agr_json = build_agr()
    dex, library = build_clean()
    process = None
    try:
        process, adb, serial = boot()
        identity = subprocess.run(
            [adb, "-s", serial, "shell", "getprop", "ro.build.fingerprint"],
            capture_output=True, text=True, check=True)
        print("fingerprint", identity.stdout.replace("\r", "").strip(), flush=True)
        guest_exit = run_clean(adb, serial, dex, library)
    finally:
        if process is not None:
            stop_emulator(process)
    image_after = sha256(system)
    print("CLEAN image SHA-256 after", image_after, flush=True)
    if image_before != image_after:
        raise SystemExit("system.img changed during the run")
    clean_sha, _ = canonical_sha(OUT / "clean.json")
    agr_sha, _ = canonical_sha(agr_json)
    print("CLEAN dex SHA-256", sha256(dex), flush=True)
    print("CLEAN so SHA-256", sha256(library), flush=True)
    print("AGR binary SHA-256", sha256(binary), flush=True)
    print("CLEAN canonical JSON SHA-256", clean_sha, flush=True)
    print("AGR canonical JSON SHA-256", agr_sha, flush=True)
    compare = subprocess.run(
        [sys.executable, str(REPO / "Tests/DexLoom/compare-jni-native-binding.py"),
         str(OUT / "clean.json"), str(agr_json)])
    print("dalvikvm exit", guest_exit, flush=True)
    print("comparator exit", compare.returncode, flush=True)
    return compare.returncode


if __name__ == "__main__":
    sys.exit(main())
