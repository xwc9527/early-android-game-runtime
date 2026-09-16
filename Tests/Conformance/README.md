# Runtime contract suite

The suite runs in the iOS Simulator process against the native Runtime. It is a
selected API/ABI contract suite, not CTS. Each JSON result records the case,
observed value and expected value. Cases are adapted into deterministic inputs;
the upstream test code is not copied.

Source definitions used for the first set:

- Android 4.4.4 Bionic `tests/string_test.cpp`: `strlen`, `memmove` overlap,
  `memchr` pointer semantics.
- Android 4.4.4 Bionic `tests/pthread_test.cpp` and
  `libc/bionic/__errno.c`: mutex ownership, per-thread TLS and `errno`
  storage.
- Android 4.4.4 Bionic `tests/dlfcn_test.cpp`: failed `dlopen` and one-shot
  `dlerror` retrieval.
- Android 4.4.4 Bionic `tests/pthread_test.cpp` and ARM
  `clock_gettime.S`: monotonic time and nanosecond range.
- CTS `AssetManagerTest`, `BitmapTest`, OpenGL framebuffer tests, and AOSP
  NativeActivity callback contracts inform the component smoke cases in
  `App/main.m`.

Reference source trees:

- <https://android.googlesource.com/platform/bionic/+/android-4.4.4_r2/tests/>
- <https://android.googlesource.com/platform/cts/+/android-4.4.4_r2/tests/tests/content/src/android/content/res/cts/AssetManagerTest.java>
- <https://android.googlesource.com/platform/cts/+/android-4.4.4_r2/tests/tests/graphics/src/android/graphics/cts/BitmapTest.java>
- <https://android.googlesource.com/platform/frameworks/base/+/android-4.4.4_r2/core/java/android/app/NativeActivity.java>

The current `reference` field explicitly says `source-derived expectations`.
It must not be labeled an Android 4.4 differential result until identical
case binaries have run on an Android 4.4 reference image and the outputs have
been compared. Input and audio are excluded from the conformance score until
their Runtime contracts are formalized.
