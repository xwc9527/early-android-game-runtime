#!/usr/bin/env bash
set -euo pipefail

if [[ $# -ne 3 ]]; then
    echo "usage: build_clean.sh AOSP_ROOT JDK6_ROOT OUT_DIR" >&2
    exit 2
fi

source_root=$(realpath "$1")
jdk_root=$(realpath "$2")
out_dir=$(realpath -m "$3")
test -f "$source_root/build/envsetup.sh"
test -f "$jdk_root/lib/tools.jar"
test -d "$source_root/.repo"
mkdir -p "$out_dir"
mkdir -p "$out_dir/host-bin"
ln -sfn "$(command -v python2)" "$out_dir/host-bin/python"

cd "$source_root"
export JAVA_HOME="$jdk_root"
export PATH="$out_dir/host-bin:$JAVA_HOME/bin:$PATH"
export OUT_DIR="$out_dir"

# The CLEAN oracle must contain only the pinned upstream source.
repo forall -e -c 'test -z "$(git status --porcelain)"'
repo manifest -r -o "$out_dir/source-manifest.xml"

source build/envsetup.sh >/dev/null
lunch aosp_x86-eng
make -j4

test -s "$out_dir/target/product/generic_x86/system.img"
sha256sum "$out_dir/target/product/generic_x86/system.img" \
    > "$out_dir/system.img.sha256"
