#!/usr/bin/env python3
"""Architecture census static scanner.

Reads the locked APK set and emits, per sample, the execution-structure facts
needed to judge the AGR architecture hypotheses: manifest surface, DEX-visible
Android Framework references split from third-party SDK references, JNI/native
method surface, ARMv7 shared-library topology and dynamic imports, plus the
graphics/audio/system-service categories each sample can reach.

Static references prove only that a code path exists in the binary. They never
prove that core gameplay executes it, so every consumer of this artifact must
treat the output as discovery data, not as a verdict.
"""
from __future__ import annotations

import argparse
import collections
import hashlib
import json
import pathlib
import re
import struct
import zipfile

from scan_apks import inspect_elf

# ---------------------------------------------------------------------------
# Binary AndroidManifest.xml
# ---------------------------------------------------------------------------

_RES_STRING_POOL = 0x0001
_RES_XML_START_ELEMENT = 0x0102
_ANDROID_NS = "http://schemas.android.com/apk/res/android"


def _parse_string_pool(data: bytes, offset: int) -> list[str]:
    count, _style_count, flags, strings_start, _styles_start = struct.unpack_from("<IIIII", data, offset + 8)
    utf8 = bool(flags & (1 << 8))
    offsets = struct.unpack_from(f"<{count}I", data, offset + 28)
    base = offset + strings_start
    result = []
    for item in offsets:
        position = base + item
        if utf8:
            length = data[position]
            position += 2 if length < 0x80 else 3
            byte_length = data[position - 1]
            if byte_length >= 0x80:
                byte_length = ((byte_length & 0x7F) << 8) | data[position]
                position += 1
            result.append(data[position:position + byte_length].decode("utf-8", "replace"))
        else:
            length = struct.unpack_from("<H", data, position)[0]
            position += 2
            if length & 0x8000:
                length = ((length & 0x7FFF) << 16) | struct.unpack_from("<H", data, position)[0]
                position += 2
            result.append(data[position:position + length * 2].decode("utf-16-le", "replace"))
    return result


def parse_axml(data: bytes) -> list[dict]:
    """Return the element stream as {tag, attributes:{name: value}} records."""
    strings: list[str] = []
    elements: list[dict] = []
    offset = 8
    while offset + 8 <= len(data):
        chunk_type, header_size, chunk_size = struct.unpack_from("<HHI", data, offset)
        if chunk_size <= 0 or offset + chunk_size > len(data):
            break
        if chunk_type == _RES_STRING_POOL:
            strings = _parse_string_pool(data, offset)
        elif chunk_type == _RES_XML_START_ELEMENT:
            body = offset + header_size
            name_index = struct.unpack_from("<I", data, body + 4)[0]
            attribute_start, _attribute_size, attribute_count = struct.unpack_from("<HHH", data, body + 8)
            attributes: dict[str, object] = {}
            for index in range(attribute_count):
                item = body + attribute_start + index * 20
                ns_index, attr_name, raw_value, typed, value = struct.unpack_from("<IIIII", data, item)
                key = strings[attr_name] if attr_name < len(strings) else f"?{attr_name}"
                if ns_index != 0xFFFFFFFF and ns_index < len(strings) and strings[ns_index] == _ANDROID_NS:
                    key = f"android:{key}"
                data_type = (typed >> 24) & 0xFF
                if data_type == 0x03:
                    attributes[key] = strings[value] if value < len(strings) else ""
                elif data_type == 0x12:
                    attributes[key] = bool(value)
                elif raw_value != 0xFFFFFFFF and raw_value < len(strings):
                    attributes[key] = strings[raw_value]
                else:
                    attributes[key] = value
            elements.append({
                "tag": strings[name_index] if name_index < len(strings) else f"?{name_index}",
                "attributes": attributes,
            })
        offset += chunk_size
    return elements


# ---------------------------------------------------------------------------
# DEX
# ---------------------------------------------------------------------------

def _uleb128(data: bytes, offset: int) -> tuple[int, int]:
    result = shift = 0
    while True:
        byte = data[offset]
        offset += 1
        result |= (byte & 0x7F) << shift
        if not byte & 0x80:
            return result, offset
        shift += 7


def _descriptor_to_class(descriptor: str) -> str:
    if descriptor.startswith("L") and descriptor.endswith(";"):
        return descriptor[1:-1].replace("/", ".")
    return descriptor


class Dex:
    def __init__(self, data: bytes):
        self.data = data
        (string_count, string_off, type_count, type_off, _proto_count, _proto_off,
         field_count, field_off, method_count, method_off,
         class_count, class_off) = struct.unpack_from("<IIIIIIIIIIII", data, 56)
        self.strings = []
        for index in range(string_count):
            item = struct.unpack_from("<I", data, string_off + index * 4)[0]
            _size, item = _uleb128(data, item)
            end = data.index(b"\0", item)
            self.strings.append(data[item:end].decode("utf-8", "replace"))
        self.types = [
            _descriptor_to_class(self.strings[struct.unpack_from("<I", data, type_off + i * 4)[0]])
            for i in range(type_count)
        ]
        self.method_refs: list[tuple[str, str]] = []
        for index in range(method_count):
            class_idx, _proto_idx, name_idx = struct.unpack_from("<HHI", data, method_off + index * 8)
            self.method_refs.append((self.types[class_idx], self.strings[name_idx]))
        self.field_refs: list[tuple[str, str]] = []
        for index in range(field_count):
            class_idx, _type_idx, name_idx = struct.unpack_from("<HHI", data, field_off + index * 8)
            self.field_refs.append((self.types[class_idx], self.strings[name_idx]))
        self.defined: set[str] = set()
        self.superclasses: set[str] = set()
        self.native_methods: list[str] = []
        for index in range(class_count):
            class_idx, _access, super_idx, _interfaces, _source, _annotations, class_data_off, _static = \
                struct.unpack_from("<IIIIIIII", data, class_off + index * 32)
            self.defined.add(self.types[class_idx])
            if super_idx != 0xFFFFFFFF:
                self.superclasses.add(self.types[super_idx])
            if class_data_off:
                self._scan_class_data(class_data_off, self.types[class_idx])

    def _scan_class_data(self, offset: int, owner: str) -> None:
        data = self.data
        static_fields, offset = _uleb128(data, offset)
        instance_fields, offset = _uleb128(data, offset)
        direct_methods, offset = _uleb128(data, offset)
        virtual_methods, offset = _uleb128(data, offset)
        for _ in range(static_fields + instance_fields):
            _, offset = _uleb128(data, offset)
            _, offset = _uleb128(data, offset)
        for count in (direct_methods, virtual_methods):
            index = 0
            for _ in range(count):
                delta, offset = _uleb128(data, offset)
                index += delta
                access, offset = _uleb128(data, offset)
                _code_off, offset = _uleb128(data, offset)
                if access & 0x0100:  # ACC_NATIVE
                    self.native_methods.append(f"{owner}.{self.method_refs[index][1]}")


# ---------------------------------------------------------------------------
# Classification tables
# ---------------------------------------------------------------------------

THIRD_PARTY_SDK = {
    "advertising": (
        "com.google.ads", "com.google.android.gms.ads", "com.admob", "com.mopub",
        "com.chartboost", "com.inmobi", "com.millennialmedia", "com.adwhirl",
        "net.youmi", "com.tapjoy", "com.jirbo.adcolony", "com.applovin",
        "com.vungle", "com.startapp", "com.appbrain", "com.heyzap",
        "com.playhaven", "com.burstly", "com.mobclix", "com.adsdk",
        "com.amazon.device.ads", "com.facebook.ads", "com.unity3d.ads",
        "com.revmob", "com.sponsorpay", "com.smaato", "com.madvertise",
        "com.mdotm", "com.airpush", "com.leadbolt", "com.appflood",
    ),
    "analytics": (
        "com.google.android.gms.analytics", "com.google.analytics",
        "com.flurry", "com.mixpanel", "com.localytics", "com.kontagent",
        "com.crashlytics", "io.fabric", "com.bugsense", "com.testflightapp",
        "org.acra", "com.apsalar", "com.adjust", "com.mobileapptracker",
        "com.google.android.apps.analytics",
    ),
    "play_services": (
        "com.google.android.gms", "com.google.android.gsf",
        "com.google.example.games", "com.google.android.vending",
    ),
    "billing": (
        "com.android.vending.billing", "com.android.billingclient",
        "com.amazon.inapp", "net.robotmedia.billing",
    ),
    "login_social": (
        "com.facebook", "com.twitter.sdk", "com.openfeint", "com.scoreloop",
        "com.swarmconnect", "com.papaya", "oauth.signpost",
    ),
}
SDK_PREFIX_TO_CATEGORY = {
    prefix: category for category, prefixes in THIRD_PARTY_SDK.items() for prefix in prefixes
}

ENGINE_CLASS_MARKERS = {
    "com.badlogic.gdx": "libgdx",
    "org.libsdl.app": "sdl",
    "org.cocos2dx": "cocos2dx",
    "org.godotengine": "godot",
    "com.android.godot": "godot",
    "org.qtproject": "qt",
    "org.renpy.android": "python-sdl",
    "org.kivy.android": "python-sdl",
    "net.damsy.soupeaucaillou": "soupeaucaillou",
    "com.unity3d.player": "unity",
    "org.andengine": "andengine",
    "org.anddev.andengine": "andengine",
    "jwtc.android": "custom-java",
}
ENGINE_LIBRARY_MARKERS = (
    (re.compile(r"libsdl2?(_|\.|-)", re.I), "sdl"),
    (re.compile(r"libgdx", re.I), "libgdx"),
    (re.compile(r"libgodot", re.I), "godot"),
    (re.compile(r"libQt5", re.I), "qt"),
    (re.compile(r"libpython", re.I), "python-sdl"),
    (re.compile(r"libcocos", re.I), "cocos2dx"),
    (re.compile(r"libIrrlicht|libminetest", re.I), "irrlicht"),
    (re.compile(r"libopenal", re.I), "openal"),
    (re.compile(r"liblove", re.I), "love2d"),
)

SYSTEM_SERVICE_CLASSES = {
    "android.os.PowerManager": "power",
    "android.os.PowerManager$WakeLock": "power",
    "android.os.Vibrator": "vibrator",
    "android.hardware.SensorManager": "sensor",
    "android.hardware.Sensor": "sensor",
    "android.hardware.SensorEvent": "sensor",
    "android.hardware.SensorEventListener": "sensor",
    "android.net.ConnectivityManager": "connectivity",
    "android.net.NetworkInfo": "connectivity",
    "android.net.wifi.WifiManager": "wifi",
    "android.telephony.TelephonyManager": "telephony",
    "android.text.ClipboardManager": "clipboard",
    "android.content.ClipboardManager": "clipboard",
    "android.view.inputmethod.InputMethodManager": "ime",
    "android.location.LocationManager": "location",
    "android.app.NotificationManager": "notification",
    "android.media.AudioManager": "audio_policy",
    "android.view.WindowManager": "window",
    "android.app.ActivityManager": "activity_manager",
    "android.accounts.AccountManager": "accounts",
    "android.app.AlarmManager": "alarm",
    "android.bluetooth.BluetoothAdapter": "bluetooth",
    "android.hardware.usb.UsbManager": "usb",
    "android.nfc.NfcAdapter": "nfc",
    "android.app.DownloadManager": "download",
    "android.os.Build": "build_info",
    "android.provider.Settings$System": "settings",
    "android.provider.Settings$Secure": "settings",
    "android.speech.tts.TextToSpeech": "tts",
    "android.app.SearchManager": "search",
    "android.os.Binder": "binder_direct",
    "android.os.IBinder": "binder_direct",
    "android.os.Parcel": "binder_direct",
    "android.os.IInterface": "binder_direct",
    "android.os.RemoteException": "binder_direct",
    "android.os.DeadObjectException": "binder_direct",
}

GRAPHICS_CLASSES = {
    "android.opengl.GLSurfaceView": "glsurfaceview",
    "android.opengl.GLSurfaceView$Renderer": "glsurfaceview",
    "android.opengl.GLES10": "gles1",
    "android.opengl.GLES11": "gles1",
    "android.opengl.GLES20": "gles2",
    "android.opengl.GLES30": "gles3",
    "javax.microedition.khronos.opengles.GL10": "gles1",
    "javax.microedition.khronos.egl.EGL10": "egl_java",
    "android.opengl.EGL14": "egl_java",
    "android.view.SurfaceView": "surfaceview",
    "android.view.SurfaceHolder": "surfaceview",
    "android.view.Surface": "surface",
    "android.view.TextureView": "textureview",
    "android.graphics.Canvas": "canvas",
    "android.graphics.Bitmap": "bitmap",
    "android.webkit.WebView": "webview",
}
AUDIO_CLASSES = {
    "android.media.SoundPool": "soundpool",
    "android.media.AudioTrack": "audiotrack",
    "android.media.MediaPlayer": "mediaplayer",
    "android.media.MediaCodec": "mediacodec",
    "android.media.AudioRecord": "audiorecord",
    "android.media.JetPlayer": "jetplayer",
}
NATIVE_LIBRARY_CATEGORY = {
    "libGLESv1_CM.so": "gles1",
    "libGLESv2.so": "gles2",
    "libGLESv3.so": "gles3",
    "libEGL.so": "egl_native",
    "libOpenSLES.so": "opensles",
    "libandroid.so": "native_app_glue",
    "libjnigraphics.so": "jnigraphics",
    "libOpenMAXAL.so": "openmaxal",
    "liblog.so": "log",
    "libz.so": "zlib",
    "libm.so": "libm",
    "libc.so": "libc",
    "libdl.so": "libdl",
    "libstdc++.so": "libstdcpp",
    "libGLESv1_CM": "gles1",
}

ONLINE_PERMISSIONS = {
    "android.permission.INTERNET",
    "android.permission.ACCESS_NETWORK_STATE",
}


def classify_class(name: str) -> tuple[str, str]:
    """Return (bucket, detail) for a referenced class name."""
    for prefix, category in SDK_PREFIX_TO_CATEGORY.items():
        if name == prefix or name.startswith(prefix + "."):
            return "third_party_sdk", category
    if name.startswith(("java.", "javax.", "sun.", "org.w3c.", "org.xml.", "org.json",
                        "org.apache.", "junit.")):
        if name.startswith("javax.microedition."):
            return "core_android", "khronos"
        return "java_runtime", ""
    if name.startswith("android.support."):
        # Bundled with the app, not part of the API19 platform surface.
        return "app_or_engine", "support_library"
    if name.startswith(("android.", "dalvik.", "com.android.internal.")):
        return "core_android", ""
    if name.startswith("com.android."):
        return "core_android", "support_or_addon"
    return "app_or_engine", ""


# ---------------------------------------------------------------------------
# Scanning
# ---------------------------------------------------------------------------

def scan_sample(sample: dict, apk: pathlib.Path) -> dict:
    record: dict = {
        "id": sample["id"],
        "package": sample["package"],
        "version_code": sample["version_code"],
        "version_name": sample.get("version_name", ""),
        "license": sample.get("license", ""),
        "source": sample.get("source", ""),
        "repository": sample.get("repository", ""),
        "sha256": sample.get("sha256", ""),
        "apk_size": apk.stat().st_size,
    }
    with zipfile.ZipFile(apk) as archive:
        names = archive.namelist()
        dex_names = sorted(n for n in names if re.fullmatch(r"classes\d*\.dex", n))
        abis = sorted({n.split("/")[1] for n in names if n.startswith("lib/") and n.count("/") >= 2})
        arm_members = [n for n in names if n.startswith("lib/armeabi-v7a/") and n.endswith(".so")] \
            or [n for n in names if n.startswith("lib/armeabi/") and n.endswith(".so")]
        manifest_elements = parse_axml(archive.read("AndroidManifest.xml"))

        method_refs: set[tuple[str, str]] = set()
        referenced_classes: set[str] = set()
        defined_classes: set[str] = set()
        native_methods: list[str] = []
        for name in dex_names:
            dex = Dex(archive.read(name))
            defined_classes |= dex.defined
            for owner, method in dex.method_refs:
                method_refs.add((owner, method))
            for owner, _field in dex.field_refs:
                referenced_classes.add(owner)
            referenced_classes |= {owner for owner, _ in dex.method_refs}
            referenced_classes |= dex.superclasses
            native_methods.extend(dex.native_methods)

        libraries = []
        needed: set[str] = set()
        imports: set[str] = set()
        for member in arm_members:
            data = archive.read(member)
            try:
                elf = inspect_elf(data)
            except Exception as error:  # noqa: BLE001 - recorded, not fatal
                libraries.append({"member": member, "error": str(error)})
                continue
            libraries.append({
                "member": member,
                "size": len(data),
                "needed": elf["needed"],
                "import_count": len(elf["imports"]),
            })
            needed.update(elf["needed"])
            imports.update(elf["imports"])

    external_classes = {name for name in referenced_classes if name not in defined_classes}
    buckets: dict[str, set[str]] = collections.defaultdict(set)
    sdk_categories: dict[str, set[str]] = collections.defaultdict(set)
    for name in external_classes:
        bucket, detail = classify_class(name)
        buckets[bucket].add(name)
        if bucket == "third_party_sdk":
            sdk_categories[detail].add(name)

    core_classes = buckets["core_android"]
    core_methods = sorted(
        f"{owner}.{method}" for owner, method in method_refs if owner in core_classes
    )
    sdk_classes = buckets["third_party_sdk"]
    sdk_methods = sorted(
        f"{owner}.{method}" for owner, method in method_refs if owner in sdk_classes
    )

    activities, services, providers, receivers, permissions = [], [], [], [], []
    min_sdk = target_sdk = 0
    native_activity = False
    for element in manifest_elements:
        tag = element["tag"]
        attributes = element["attributes"]
        name = attributes.get("android:name")
        if tag == "uses-sdk":
            min_sdk = int(attributes.get("android:minSdkVersion") or 0) if isinstance(
                attributes.get("android:minSdkVersion"), int) else 0
            target_sdk = int(attributes.get("android:targetSdkVersion") or 0) if isinstance(
                attributes.get("android:targetSdkVersion"), int) else 0
        elif tag == "uses-permission" and isinstance(name, str):
            permissions.append(name)
        elif tag == "activity" and isinstance(name, str):
            activities.append(name)
            if name == "android.app.NativeActivity":
                native_activity = True
        elif tag == "service" and isinstance(name, str):
            services.append(name)
        elif tag == "provider" and isinstance(name, str):
            providers.append(name)
        elif tag == "receiver" and isinstance(name, str):
            receivers.append(name)
        elif tag == "meta-data" and attributes.get("android:name") == "android.app.lib_name":
            native_activity = True

    engines: set[str] = set()
    for prefix, engine in ENGINE_CLASS_MARKERS.items():
        if any(name == prefix or name.startswith(prefix + ".")
               for name in defined_classes | external_classes):
            engines.add(engine)
    library_names = [pathlib.PurePosixPath(item["member"]).name for item in libraries]
    for pattern, engine in ENGINE_LIBRARY_MARKERS:
        if any(pattern.search(name) for name in library_names):
            engines.add(engine)

    graphics = sorted({GRAPHICS_CLASSES[name] for name in core_classes if name in GRAPHICS_CLASSES}
                      | {GRAPHICS_CLASSES[name] for name in external_classes if name in GRAPHICS_CLASSES})
    audio = sorted({AUDIO_CLASSES[name] for name in external_classes if name in AUDIO_CLASSES})
    services_used = sorted({SYSTEM_SERVICE_CLASSES[name] for name in external_classes
                            if name in SYSTEM_SERVICE_CLASSES})
    native_categories = sorted({NATIVE_LIBRARY_CATEGORY[name] for name in needed
                                if name in NATIVE_LIBRARY_CATEGORY})
    if "gles1" in native_categories or "gles2" in native_categories or "gles3" in native_categories:
        graphics = sorted(set(graphics) | {c for c in native_categories if c.startswith("gles")})
    if "opensles" in native_categories:
        audio = sorted(set(audio) | {"opensles"})

    has_dex = bool(dex_names)
    if arm_members and has_dex:
        execution_mode = "native_activity" if native_activity else "dex_plus_jni"
    elif arm_members:
        execution_mode = "native_only"
    elif has_dex:
        execution_mode = "pure_dex"
    else:
        execution_mode = "resources_only"

    record.update({
        "min_sdk": min_sdk,
        "target_sdk": target_sdk,
        "abis": abis,
        "multidex": len(dex_names) > 1,
        "dex_files": dex_names,
        "execution_mode": execution_mode,
        "native_activity": native_activity,
        "manifest": {
            "activities": sorted(set(activities)),
            "services": sorted(set(services)),
            "providers": sorted(set(providers)),
            "receivers": sorted(set(receivers)),
            "permissions": sorted(set(permissions)),
        },
        "engines": sorted(engines),
        "graphics_paths": graphics,
        "audio_paths": audio,
        "system_services": services_used,
        "native_library_categories": native_categories,
        "counts": {
            "defined_classes": len(defined_classes),
            "external_classes": len(external_classes),
            "core_android_classes": len(core_classes),
            "core_android_methods": len(core_methods),
            "java_runtime_classes": len(buckets["java_runtime"]),
            "third_party_sdk_classes": len(sdk_classes),
            "third_party_sdk_methods": len(sdk_methods),
            "app_or_engine_classes": len(buckets["app_or_engine"]),
            "jni_native_methods": len(native_methods),
            "armv7_libraries": len(arm_members),
            "native_dt_needed": len(needed),
            "native_imports": len(imports),
        },
        "third_party_sdk_categories": {
            key: sorted(value) for key, value in sorted(sdk_categories.items())
        },
        "armv7_libraries": libraries,
        "native_dt_needed": sorted(needed),
        "core_android_classes": sorted(core_classes),
        "core_android_methods": core_methods,
        "jni_native_methods": sorted(set(native_methods)),
        "native_imports": sorted(imports),
        "uses_internet": bool(set(permissions) & ONLINE_PERMISSIONS),
    })
    return record


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("--resolved", default="samples/resolved.json")
    parser.add_argument("--output", default="build/artifacts/architecture-census.json")
    args = parser.parse_args()
    root = pathlib.Path(__file__).resolve().parents[1]
    resolved = json.loads((root / args.resolved).read_text(encoding="utf-8"))
    records = []
    for sample in resolved["samples"]:
        apk = pathlib.Path(sample["apk_path"])
        if not apk.is_absolute():
            apk = root / apk
        records.append(scan_sample(sample, apk))
    payload = {
        "schema_version": 1,
        "sample_count": len(records),
        "scanner_fingerprint": hashlib.sha256(
            pathlib.Path(__file__).read_bytes()).hexdigest(),
        "samples": records,
    }
    output = root / args.output
    output.parent.mkdir(parents=True, exist_ok=True)
    output.write_text(json.dumps(payload, indent=2) + "\n", encoding="utf-8")
    print(f"{len(records)} samples -> {output}")


if __name__ == "__main__":
    main()
