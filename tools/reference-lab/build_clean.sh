#!/usr/bin/env bash
# API19 envsetup.sh reads optional variables without nounset guards.
set -eo pipefail

if [[ $# -ne 4 ]]; then
    echo "usage: build_clean.sh AOSP_ROOT JDK6_ROOT MAKE382_ROOT OUT_DIR" >&2
    exit 2
fi

source_root=$(realpath "$1")
jdk_root=$(realpath "$2")
make_root=$(realpath "$3")
out_dir=$(realpath -m "$4")
test -f "$source_root/build/envsetup.sh"
test -f "$jdk_root/lib/tools.jar"
test -x "$make_root/bin/make"
test -d "$source_root/.repo"
mkdir -p "$out_dir"
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

# The only source difference is the reviewed host build-tool vendor gate.
repo forall -e -c 'if [ "$REPO_PATH" != build ]; then test -z "$(git status --porcelain)"; fi'
test "$(git -C build rev-parse HEAD)" = b34d556982095a8fe84273ffceadd80f41325acf
test "$(git -C build status --porcelain)" = ' M core/main.mk'
test "$(git -C build diff -- core/main.mk | sha256sum | cut -d' ' -f1)" = \
    1d5d120d54935eab8ecef496c9e95659c5767ccf5f1c7b5ec9d20e0f294592ef
sha256sum "$(dirname "$0")/api19-openjdk6-build.patch" \
    > "$out_dir/host-build-patch.sha256"
repo manifest -r -o "$out_dir/source-manifest.xml"
{
    "$JAVA_HOME/bin/java" -version
    "$make_root/bin/make" --version
    python --version
    uname -a
} > "$out_dir/host-toolchain.txt" 2>&1

source build/envsetup.sh >/dev/null
lunch aosp_x86-eng
make -j4

test -s "$out_dir/target/product/generic_x86/system.img"
sha256sum "$out_dir/target/product/generic_x86/system.img" \
    > "$out_dir/system.img.sha256"
