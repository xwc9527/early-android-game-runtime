# Native androidfw resource core

This module is the native resource layer used by the runtime PoC.  Python only
loads its C ABI and moves bytes between the host component and guest memory; it
does not parse APK, ZIP, `resources.arsc`, or resource configurations.

The implementation compiles these unmodified Android 4.4.4 AOSP
`frameworks/base/libs/androidfw` host sources:

- `Asset.cpp`
- `AssetDir.cpp`
- `AssetManager.cpp`
- `misc.cpp`
- `ResourceTypes.cpp`
- `StreamingZipInflater.cpp`
- `ZipFileRO.cpp`
- `ZipUtils.cpp`

It also compiles the required KitKat `libutils` subset (`FileMap`, `RefBase`,
`SharedBuffer`, `String8`, `String16`, `Unicode`, `VectorImpl`, mutex/thread and
timer support), AOSP `libcutils/atomic.c`, and AOSP zlib.  `ObbFile.cpp` is the
only androidfw host commonSource omitted because the runtime resource path does
not mount OBB containers.

`agr_androidfw.cpp` is a narrow, portable C ABI over the original
`AssetManager`, `Asset`, and `ResTable` classes.  It exposes APK mounting,
streaming asset I/O, configuration, resource table/package inspection, name
lookup, and selected string retrieval.  The guest-facing `AAsset*` handles stay
32-bit; host C++ pointers never enter guest memory.

The files under `compat/` and `host_compat.h` are build-boundary adaptations,
not resource implementations.  KitKat assumes its own `char16_t` typedef and a
2014 C++ runtime, so the Windows validation target compiles without modern C++
headers.  `host_cxx_runtime.cpp` supplies the minimal disabled-exception/runtime
symbols for that validation target.  On Windows, `host_compat.h` duplicates the
CRT file handle before KitKat `FileMap` takes ownership; this preserves
`ZipFileRO` across repeated asset opens.  An iOS target should link the platform
C++ ABI and use the POSIX `FileMap` path, so neither Windows adaptation changes
the portable resource core.

The Kung Foo Barracuda regression mounts the original APK through this module,
enumerates 315 assets, parses one resource table/package, selects
`com.onetwofivegames.kungfoobarracuda:string/kungfoobarracuda_activity` as
`Kung Foo Barracuda`, then supplies seven original PNG assets to the existing
DEX/native/GLES path.
