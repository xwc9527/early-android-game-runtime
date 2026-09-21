#!/bin/bash
set -euo pipefail
ROOT="$(cd "$(dirname "$0")/.." && pwd)"; BUILD="$ROOT/build/iphoneos"; APP="$BUILD/AGRDevice.app"
SDK="$(xcrun --sdk iphoneos --show-sdk-path)"; TARGET="arm64-apple-ios15.0"
mkdir -p "$BUILD/obj" "$APP"
python3 "$ROOT/tools/fetch_fdroid_samples.py"
python3 "$ROOT/tools/scan_apks.py" --shard-index "${SHARD_INDEX:-0}" --shard-count "${SHARD_COUNT:-1}"
ANGLE_VERSION="v2.1.28252"
ANGLE_SHA256="59e4b1f68956c92441cde4dca0e9eb1a835bbccd107cefdd1d3d3d60e27410be"
ANGLE_ARCHIVE="$BUILD/angle-xcframeworks-$ANGLE_VERSION.zip"
ANGLE_ROOT="$BUILD/angle-$ANGLE_VERSION"
ANGLE_CACHED_SHA=""
if [[ -s "$ANGLE_ARCHIVE" ]]; then ANGLE_CACHED_SHA="$(shasum -a 256 "$ANGLE_ARCHIVE" | awk '{print $1}')"; fi
if [[ "$ANGLE_CACHED_SHA" != "$ANGLE_SHA256" || ! -d "$ANGLE_ROOT/dist/EGL.xcframework" || ! -d "$ANGLE_ROOT/dist/GLESv2.xcframework" ]]; then
  rm -f "$ANGLE_ARCHIVE"; rm -rf "$ANGLE_ROOT"
  curl -L --fail --retry 3 -o "$ANGLE_ARCHIVE" \
    "https://github.com/EdgeFirstAI/angle-package/releases/download/$ANGLE_VERSION/angle-xcframeworks-$ANGLE_VERSION.zip"
  echo "$ANGLE_SHA256  $ANGLE_ARCHIVE" | shasum -a 256 -c -
  rm -rf "$ANGLE_ROOT"; mkdir -p "$ANGLE_ROOT"; unzip -q "$ANGLE_ARCHIVE" -d "$ANGLE_ROOT"
fi
ANGLE_DIST="$ANGLE_ROOT/dist"
ANGLE_EGL="$ANGLE_DIST/EGL.xcframework/ios-arm64/libEGL.framework"
ANGLE_GLES="$ANGLE_DIST/GLESv2.xcframework/ios-arm64/libGLESv2.framework"
ANGLE_FRAMEWORKS="$BUILD/angle-frameworks"
rm -rf "$ANGLE_FRAMEWORKS"; mkdir -p "$ANGLE_FRAMEWORKS"
ditto "$ANGLE_EGL" "$ANGLE_FRAMEWORKS/libEGL.framework"
ditto "$ANGLE_GLES" "$ANGLE_FRAMEWORKS/libGLESv2.framework"
rustup target add aarch64-apple-ios
cargo build --manifest-path "$ROOT/Runtime/ArmInterpreter/Cargo.toml" --target aarch64-apple-ios --release
COMMON=(-target "$TARGET" -isysroot "$SDK" -miphoneos-version-min=15.0 -O2)
clang "${COMMON[@]}" -std=c11 -I"$ROOT/Runtime/NativeCore" -c "$ROOT/Runtime/NativeCore/agr_runtime.c" -o "$BUILD/obj/agr_runtime.o"
clang++ "${COMMON[@]}" -std=c++17 -fno-exceptions -fno-rtti -I"$ROOT/Runtime/Bionic" -I"$ROOT/Runtime/Process" -c "$ROOT/Runtime/Bionic/agr_bionic_allocator.cpp" -o "$BUILD/obj/agr_bionic_allocator.o"
clang "${COMMON[@]}" -std=c11 -I"$ROOT/Runtime/Process" -c "$ROOT/Runtime/Process/agr_guest_vma.c" -o "$BUILD/obj/agr_guest_vma.o"
clang "${COMMON[@]}" -std=c11 -I"$ROOT/Runtime/HostServices" -c "$ROOT/Runtime/HostServices/agr_host_services_darwin.c" -o "$BUILD/obj/agr_host_services_darwin.o"
clang "${COMMON[@]}" -std=c11 -I"$ROOT/Runtime/Bionic" -c "$ROOT/Runtime/Bionic/agr_bionic_thread_attr.c" -o "$BUILD/obj/agr_bionic_thread_attr.o"
for SOURCE in agr_futex_host.cpp agr_bionic_sync.cpp agr_bionic_tls.cpp agr_bionic_errno_host.cpp agr_bionic_thread_lifecycle.cpp; do
  clang++ "${COMMON[@]}" -std=c++17 -fexceptions -fno-rtti -I"$ROOT/Runtime/Bionic" -I"$ROOT/Runtime/HostServices" -c "$ROOT/Runtime/Bionic/$SOURCE" -o "$BUILD/obj/${SOURCE%.cpp}.o"
done
clang++ "${COMMON[@]}" -std=gnu++98 -fno-exceptions -fno-rtti -I"$ROOT/Runtime/Bionic" -I"$ROOT/Runtime/Process" -c "$ROOT/Runtime/Bionic/agr_bionic_mmap.cpp" -o "$BUILD/obj/agr_bionic_mmap.o"
clang++ "${COMMON[@]}" -std=gnu++98 -fno-exceptions -fno-rtti -I"$ROOT/Runtime/AospLinker" -I"$ROOT/Runtime/Bionic" -I"$ROOT/Runtime/Process" -I"$ROOT/Runtime/NativeCore" -c "$ROOT/Runtime/AospLinker/agr_aosp_linker.cpp" -o "$BUILD/obj/agr_aosp_linker.o"
clang++ "${COMMON[@]}" -std=gnu++98 -fno-exceptions -fno-rtti -I"$ROOT/Runtime/AospLinker" -I"$ROOT/Runtime/Bionic" -I"$ROOT/Runtime/Process" -I"$ROOT/Runtime/NativeCore" -c "$ROOT/Runtime/AospLinker/agr_aosp_dynamic.cpp" -o "$BUILD/obj/agr_aosp_dynamic.o"
clang "${COMMON[@]}" -std=c11 -I"$ROOT/Runtime/NativeCore" -c "$ROOT/Tests/Conformance/agr_contracts.c" -o "$BUILD/obj/agr_contracts.o"
clang "${COMMON[@]}" -std=c11 -DGL_GLES_PROTOTYPES=1 -I"$ROOT/Vendor/ANGLE-Headers" -I"$ROOT/Runtime/NativeCore" -I"$ROOT/Runtime/GuestRuntime" -I"$ROOT/Runtime/Ehabi" -c "$ROOT/Runtime/GuestRuntime/agr_guest_runtime.c" -o "$BUILD/obj/agr_guest_runtime.o"
clang "${COMMON[@]}" -std=c11 -I"$ROOT/Runtime/GuestRuntime" -c "$ROOT/Runtime/GuestRuntime/agr_thread_context.c" -o "$BUILD/obj/agr_thread_context.o"
clang "${COMMON[@]}" -std=c11 -I"$ROOT/Runtime/Ehabi" -I"$ROOT/Runtime/GuestRuntime" -I"$ROOT/Runtime/NativeCore" -c "$ROOT/Runtime/Ehabi/agr_ehabi.c" -o "$BUILD/obj/agr_ehabi.o"
clang "${COMMON[@]}" -std=c11 -I"$ROOT/Runtime/GuestRuntime" -c "$ROOT/Runtime/GuestRuntime/agr_service_dispatch.c" -o "$BUILD/obj/agr_service_dispatch.o"
clang "${COMMON[@]}" -std=c11 -c "$ROOT/Runtime/GuestRuntime/agr_jni_methods.c" -o "$BUILD/obj/agr_jni_methods.o"

AOSP="$ROOT/Vendor/AOSP"; AFW="$ROOT/Runtime/AndroidFw"; BITMAP="$ROOT/Runtime/Bitmap"
AFW_INCLUDES=(-I"$AFW/compat/include" -I"$AFW" -I"$AOSP/frameworks-base/include" -I"$AOSP/frameworks-native/include" -I"$AOSP/system-core/include")
AFW_DEFINES=(-DSTATIC_ANDROIDFW_FOR_TOOLS -DLIBUTILS_NATIVE=1 -DHAVE_PTHREADS -DHAVE_POSIX_FILEMAP -DHAVE_SYS_UIO_H -DHAVE_LITTLE_ENDIAN -DHAVE_PRINTF_ZD=1 -D_FILE_OFFSET_BITS=64 -DOS_PATH_SEPARATOR=47 -DNOT_USING_KLIBC=1)
AFW_SOURCES=("$AFW/agr_androidfw.cpp" "$AFW/host_log.cpp" "$AFW/host_cxx_runtime.cpp"
 "$AOSP/frameworks-base/libs/androidfw/Asset.cpp" "$AOSP/frameworks-base/libs/androidfw/AssetDir.cpp" "$AOSP/frameworks-base/libs/androidfw/AssetManager.cpp" "$AOSP/frameworks-base/libs/androidfw/misc.cpp" "$AOSP/frameworks-base/libs/androidfw/ResourceTypes.cpp" "$AOSP/frameworks-base/libs/androidfw/StreamingZipInflater.cpp" "$AOSP/frameworks-base/libs/androidfw/ZipFileRO.cpp" "$AOSP/frameworks-base/libs/androidfw/ZipUtils.cpp"
 "$AOSP/system-core/libutils/FileMap.cpp" "$AOSP/system-core/libutils/RefBase.cpp" "$AOSP/system-core/libutils/SharedBuffer.cpp" "$AOSP/system-core/libutils/Static.cpp" "$AOSP/system-core/libutils/String8.cpp" "$AOSP/system-core/libutils/String16.cpp" "$AOSP/system-core/libutils/Unicode.cpp" "$AOSP/system-core/libutils/VectorImpl.cpp" "$AOSP/system-core/libutils/misc.cpp" "$AOSP/system-core/libutils/Threads.cpp" "$AOSP/system-core/libutils/Timers.cpp")
INDEX=0; AFW_OBJECTS=()
for SOURCE in "${AFW_SOURCES[@]}"; do OBJECT="$BUILD/obj/afw-$INDEX.o"; clang++ "${COMMON[@]}" -std=gnu++98 -nostdinc++ -fno-exceptions -fno-rtti "${AFW_DEFINES[@]}" "${AFW_INCLUDES[@]}" -include "$AFW/host_compat.h" -c "$SOURCE" -o "$OBJECT"; AFW_OBJECTS+=("$OBJECT"); INDEX=$((INDEX+1)); done
clang "${COMMON[@]}" -std=c11 -c "$AFW/host_atomic.c" -o "$BUILD/obj/atomic.o"; AFW_OBJECTS+=("$BUILD/obj/atomic.o")

SKIA="$AOSP/skia"; PNG="$AOSP/libpng"; ZLIB="$AOSP/zlib"
PNG_OBJECTS=()
for SOURCE in "$PNG"/*.c "$ZLIB"/*.c; do
  case "$(basename "$SOURCE")" in example.c|pngtest.c) continue;; esac
  OBJECT="$BUILD/obj/codec-$(basename "$SOURCE" .c).o"; clang "${COMMON[@]}" -w -UMACOS -I"$PNG" -I"$ZLIB" -c "$SOURCE" -o "$OBJECT"; PNG_OBJECTS+=("$OBJECT")
done
SKIA_INCLUDES=(-I"$BITMAP" -I"$SKIA/include/core" -I"$SKIA/include/images" -I"$SKIA/include/utils" -I"$SKIA/src/core" -I"$SKIA/src/image" -I"$SKIA/src/images" -I"$SKIA/src/utils" -I"$PNG" -I"$ZLIB")
SKIA_SOURCES=("$BITMAP/agr_bitmap.cpp" "$SKIA/src/core/Sk64.cpp" "$SKIA/src/core/SkBitmap.cpp" "$SKIA/src/core/SkColor.cpp" "$SKIA/src/core/SkColorTable.cpp" "$SKIA/src/core/SkDebug.cpp" "$SKIA/src/core/SkDither.cpp" "$SKIA/src/core/SkError.cpp" "$SKIA/src/core/SkFlattenable.cpp" "$SKIA/src/core/SkImageInfo.cpp" "$SKIA/src/core/SkMallocPixelRef.cpp" "$SKIA/src/core/SkMath.cpp" "$SKIA/src/core/SkPixelRef.cpp" "$SKIA/src/core/SkStream.cpp" "$SKIA/src/core/SkString.cpp" "$SKIA/src/core/SkTLS.cpp" "$SKIA/src/core/SkTSearch.cpp" "$SKIA/src/core/SkUnPreMultiply.cpp" "$SKIA/src/core/SkUtils.cpp" "$SKIA/src/images/SkImageDecoder.cpp" "$SKIA/src/images/SkImageDecoder_FactoryDefault.cpp" "$SKIA/src/images/SkImageDecoder_FactoryRegistrar.cpp" "$SKIA/src/images/SkImageDecoder_libpng.cpp" "$SKIA/src/images/SkImageEncoder.cpp" "$SKIA/src/images/SkImageEncoder_Factory.cpp" "$SKIA/src/images/SkScaledBitmapSampler.cpp" "$SKIA/src/ports/SkDebug_stdio.cpp" "$SKIA/src/ports/SkMemory_malloc.cpp" "$SKIA/src/ports/SkThread_pthread.cpp" "$SKIA/src/ports/SkTLS_pthread.cpp")
INDEX=0; SKIA_OBJECTS=()
for SOURCE in "${SKIA_SOURCES[@]}"; do OBJECT="$BUILD/obj/skia-$INDEX.o"; clang++ "${COMMON[@]}" -std=gnu++98 -nostdinc++ -I"$AFW/compat/include" -w -fno-exceptions -fno-rtti -ffunction-sections -fdata-sections -include "$BITMAP/host_skia_config.h" "${SKIA_INCLUDES[@]}" -c "$SOURCE" -o "$OBJECT"; SKIA_OBJECTS+=("$OBJECT"); INDEX=$((INDEX+1)); done
DEX="$ROOT/Runtime/DexLoom"; DEX_INCLUDE="$DEX/Include"
DEX_SOURCES=("$DEX/Base/dx_log.c" "$DEX/Base/dx_memory.c" "$DEX/Base/dx_arena.c" "$DEX/DEX/dx_dex.c" "$DEX/DEX/dx_opcode.c" "$DEX/DEX/dx_verifier.c" "$DEX/VM/dx_vm.c" "$DEX/VM/dx_interpreter.c" "$DEX/VM/dx_jni.c" "$DEX/VM/dx_verifier.c" "$DEX/APK/dx_apk.c" "$DEX/APK/dx_manifest.c" "$DEX/poc_host.c" "$DEX/game_dex_runner.c")
INDEX=0; DEX_OBJECTS=()
for SOURCE in "${DEX_SOURCES[@]}"; do OBJECT="$BUILD/obj/dex-$INDEX.o"; clang "${COMMON[@]}" -std=gnu11 -DGL_GLES_PROTOTYPES=1 -I"$ROOT/Vendor/ANGLE-Headers" -I"$DEX_INCLUDE" -c "$SOURCE" -o "$OBJECT"; DEX_OBJECTS+=("$OBJECT"); INDEX=$((INDEX+1)); done
clang "${COMMON[@]}" -fobjc-arc -DAGR_DEVICE_INTERACTIVE=1 -I"$ROOT/Vendor/ANGLE-Headers" -I"$ROOT/Runtime/NativeCore" -I"$ROOT/Runtime/GuestRuntime" -I"$DEX" -I"$DEX_INCLUDE" -I"$AFW" -I"$BITMAP" -c "$ROOT/App/main.m" -o "$BUILD/obj/main.o"
clang++ "${COMMON[@]}" -Wl,-dead_strip -Wl,-rpath,@executable_path/Frameworks -F"$ANGLE_FRAMEWORKS" "$BUILD/obj/main.o" "$BUILD/obj/agr_runtime.o" "$BUILD/obj/agr_bionic_allocator.o" "$BUILD/obj/agr_guest_vma.o" "$BUILD/obj/agr_host_services_darwin.o" "$BUILD/obj/agr_bionic_thread_attr.o" "$BUILD/obj/agr_futex_host.o" "$BUILD/obj/agr_bionic_sync.o" "$BUILD/obj/agr_bionic_tls.o" "$BUILD/obj/agr_bionic_errno_host.o" "$BUILD/obj/agr_bionic_thread_lifecycle.o" "$BUILD/obj/agr_bionic_mmap.o" "$BUILD/obj/agr_aosp_linker.o" "$BUILD/obj/agr_aosp_dynamic.o" "$BUILD/obj/agr_ehabi.o" "$BUILD/obj/agr_contracts.o" "$BUILD/obj/agr_guest_runtime.o" "$BUILD/obj/agr_thread_context.o" "$BUILD/obj/agr_service_dispatch.o" "$BUILD/obj/agr_jni_methods.o" "${DEX_OBJECTS[@]}" "${AFW_OBJECTS[@]}" "${SKIA_OBJECTS[@]}" "${PNG_OBJECTS[@]}" "$ROOT/Runtime/ArmInterpreter/target/aarch64-apple-ios/release/libtouchhle_arm_interpreter.a" -lz -framework UIKit -framework Foundation -framework CoreGraphics -framework Security -framework Metal -framework QuartzCore -framework libEGL -framework libGLESv2 -o "$APP/AGRSimulator"
cp "$ROOT/App/Info.plist" "$APP/Info.plist"; cp "$ROOT/App/Resources/"* "$APP/"
/usr/libexec/PlistBuddy -c "Set :CFBundleIdentifier ${IOS_BUNDLE_ID:-dev.agr.simulator}" "$APP/Info.plist"
/usr/libexec/PlistBuddy -c 'Add :UIFileSharingEnabled bool true' "$APP/Info.plist"
/usr/libexec/PlistBuddy -c 'Add :LSSupportsOpeningDocumentsInPlace bool true' "$APP/Info.plist"
cp "$ROOT/Tests/Trajectories/kungfoo-barracuda.json" "$APP/"
mkdir -p "$APP/Frameworks"; ditto "$ANGLE_FRAMEWORKS/libEGL.framework" "$APP/Frameworks/libEGL.framework"; ditto "$ANGLE_FRAMEWORKS/libGLESv2.framework" "$APP/Frameworks/libGLESv2.framework"
mkdir -p "$BUILD/Payload"; ditto "$APP" "$BUILD/Payload/AGRDevice.app"
(cd "$BUILD" && zip -qr AGRDevice-unsigned.ipa Payload)
if [[ -n "${IOS_SIGNING_IDENTITY:-}" && -n "${IOS_PROVISIONING_PROFILE:-}" ]]; then
  cp "$IOS_PROVISIONING_PROFILE" "$APP/embedded.mobileprovision"
  security cms -D -i "$APP/embedded.mobileprovision" > "$BUILD/profile.plist"
  plutil -extract Entitlements xml1 -o "$BUILD/entitlements.plist" "$BUILD/profile.plist"
  codesign --force --sign "$IOS_SIGNING_IDENTITY" "$APP/Frameworks/libEGL.framework"
  codesign --force --sign "$IOS_SIGNING_IDENTITY" "$APP/Frameworks/libGLESv2.framework"
  codesign --force --sign "$IOS_SIGNING_IDENTITY" --entitlements "$BUILD/entitlements.plist" "$APP"
  ditto "$APP" "$BUILD/Payload/AGRDevice.app"
  (cd "$BUILD" && zip -qr AGRDevice.ipa Payload)
  codesign --verify --deep --strict --verbose=2 "$APP"
else
  echo 'No signing identity/profile supplied; produced an unsigned iphoneos .app for link validation only.'
fi
file "$APP/AGRSimulator"
otool -l "$APP/AGRSimulator" | grep -A3 LC_BUILD_VERSION | head -n 4
