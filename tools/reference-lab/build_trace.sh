#!/usr/bin/env bash
# API19 envsetup.sh reads optional variables without nounset guards.
set -eo pipefail

if [[ $# -ne 5 && $# -ne 6 ]]; then
    echo "usage: build_trace.sh TRACE_ROOT JDK6_ROOT MAKE382_ROOT OUT_DIR CLEAN_OUT_DIR [--vm-only]" >&2
    exit 2
fi
if [[ $# -eq 6 && "$6" != --vm-only ]]; then
    echo "unknown build mode: $6" >&2
    exit 2
fi

source_root=$(realpath "$1")
jdk_root=$(realpath "$2")
make_root=$(realpath "$3")
out_dir=$(realpath -m "$4")
clean_out=$(realpath "$5")
build_target=${AGR_BUILD_TARGET:-aosp_x86-eng}
case "$build_target" in
    aosp_x86-eng) product=generic_x86 ;;
    aosp_arm-eng) product=generic ;;
    *) echo "unsupported API19 build target: $build_target" >&2; exit 2 ;;
esac
test -f "$source_root/build/envsetup.sh"
test -f "$jdk_root/lib/tools.jar"
test -x "$make_root/bin/make"
test -s "$clean_out/source-manifest.xml"
mkdir -p "$out_dir/host-bin"
ln -sfn "$(command -v python2)" "$out_dir/host-bin/python"
ln -sfn "$source_root/prebuilts/misc/linux-x86/bison/bison" \
    "$out_dir/host-bin/bison"

cd "$source_root"
export JAVA_HOME="$jdk_root"
export PATH="$make_root/bin:$out_dir/host-bin:$JAVA_HOME/bin:$PATH"
export OUT_DIR="$out_dir"
export ALLOW_OPENJDK6=true
export BISON_PKGDATADIR="$source_root/external/bison/data"

repo forall -e -c 'if [ "$REPO_PATH" != build ] && [ "$REPO_PATH" != dalvik ]; then test -z "$(git status --porcelain)"; fi'
test "$(git -C build rev-parse HEAD)" = b34d556982095a8fe84273ffceadd80f41325acf
test "$(git -C build status --porcelain)" = ' M core/main.mk'
test "$(git -C build diff -- core/main.mk | sha256sum | cut -d' ' -f1)" = \
    1d5d120d54935eab8ecef496c9e95659c5767ccf5f1c7b5ec9d20e0f294592ef
test "$(git -C dalvik rev-parse HEAD)" = 36e356c96640775f0a3f167bd2426ea0f0093b8b
test "$(git -C dalvik diff --binary | sha256sum | cut -d' ' -f1)" = \
    007a79014245d2ec4628668f83c6f9f72529f84bc22421376fe315d00dd14c87
test "$(git -C dalvik status --porcelain | wc -l)" = 5
git -C dalvik diff --binary > "$out_dir/dalvik-trace.patch"
sha256sum "$out_dir/dalvik-trace.patch" > "$out_dir/dalvik-trace.patch.sha256"
repo manifest -r -o "$out_dir/source-manifest.xml"
cmp "$out_dir/source-manifest.xml" "$clean_out/source-manifest.xml"
{
    "$JAVA_HOME/bin/java" -version
    "$make_root/bin/make" --version
    python --version
    uname -a
} > "$out_dir/host-toolchain.txt" 2>&1

source build/envsetup.sh >/dev/null
lunch "$build_target"
if [[ $# -eq 6 ]]; then
    make -j1 libdvm
    test -s "$out_dir/target/product/$product/system/lib/libdvm.so"
    sha256sum "$out_dir/target/product/$product/system/lib/libdvm.so" \
        > "$out_dir/libdvm.so.sha256"
    exit 0
fi
make -j4

test -s "$out_dir/target/product/$product/system.img"
sha256sum "$out_dir/target/product/$product/system.img" \
    > "$out_dir/system.img.sha256"
