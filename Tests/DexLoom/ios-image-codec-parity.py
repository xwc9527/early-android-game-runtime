#!/usr/bin/env python3
"""Prevent a device-only BitmapFactory decoder gap in the common iOS host."""

import hashlib
import pathlib
import re
import zipfile

ROOT = pathlib.Path(__file__).resolve().parents[2]
SIM = (ROOT / "scripts/build-and-run-simulator.sh").read_text()
DEVICE = (ROOT / "scripts/build-iphoneos.sh").read_text()
CODECS = (ROOT / "scripts/build-ios-image-codecs.sh").read_text()
EXPECTED_APK = "57f4735297befc68c0a7aa6cd9e442ecd250b1b2b38104324a12b6c2d4e18569"


def sources(script):
    match = re.search(r"SKIA_SOURCES=\(([^\n]+)\)", script)
    assert match, "missing KitKat Skia source list"
    return set(re.findall(r'"([^"]+)"', match.group(1)))


sim_sources = sources(SIM)
device_sources = sources(DEVICE)
assert sim_sources == device_sources, "Simulator and device compile different Skia decoder sources"
for name in ("SkImageDecoder_libpng.cpp", "SkJpegUtility.cpp",
             "SkImageDecoder_libjpeg_host.cpp", "SkImageDecoder_libgif_host.cpp"):
    assert any(item.endswith(name) for item in device_sources), name
for label, script in (("Simulator", SIM), ("iphoneos", DEVICE)):
    assert 'build-ios-image-codecs.sh" "$BUILD/image-codecs" "$SDK" "$TARGET"' in script, label
    assert '"${CODEC_OBJECTS[@]}"' in script, label + " omits libjpeg/giflib objects at link"
    assert '-I"$JPEG_INC"' in script and '-I"$GIF_INC"' in script, label
assert 'MIN_VERSION=(-mios-simulator-version-min=15.0)' in CODECS
assert 'MIN_VERSION=(-miphoneos-version-min=15.0)' in CODECS

apk = ROOT / "samples/frozen-bubble.apk"
if apk.is_file():
    assert hashlib.sha256(apk.read_bytes()).hexdigest() == EXPECTED_APK
    with zipfile.ZipFile(apk) as z:
        assert z.read("res/drawable/background.jpg")[:2] == b"\xff\xd8"
        assert z.read("res/drawable/bubble_1.gif")[:6] in (b"GIF87a", b"GIF89a")
print("PASS iOS device/Simulator PNG+JPEG+GIF decoder parity and APK resource formats")
