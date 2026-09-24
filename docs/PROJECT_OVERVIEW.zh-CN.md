# Early Android Game Runtime 项目说明

后续 Framework migration 的最高优先级规则是 [`REFERENCE_MIGRATION_RULES.md`](../REFERENCE_MIGRATION_RULES.md)。真实游戏只产生 dependency evidence 和 regression evidence。Runtime gap 本身不授权新增 Android implementation。

## 项目定位

Early Android Game Runtime（AGR）是在一个原生 iOS 进程内运行早期 Android 游戏原始 APK、DEX 和 ARMv7 ELF 的兼容运行环境。它不启动 Android 内核、system_server、SurfaceFlinger 或完整 Android userspace，也不把游戏改写成 iOS 工程。游戏携带的逻辑、引擎、Runner、资源和 native 库继续作为原始二进制执行；AGR 提供这些二进制能够观察到的 Android 4.4.4/API 19 用户态行为，并把最终的设备能力映射到 Darwin、UIKit 和 Metal。

当前仓库是“部分正式化 Runtime + 工程验证壳”，不是消费者产品，也不是已经闭合的通用 Android 游戏模拟器。已有真实 APK 的执行结果是 dependency evidence 或 regression evidence，不授权补一个 Android API。

## 固定技术边界

- Guest ABI：32 位 little-endian ARM EABI，主要目标为 `armeabi-v7a`。
- 行为与源码母版：AOSP Android 4.4.4/API 19。
- Host：iOS arm64 或 iOS Simulator arm64。
- CPU：touchHLE 派生的 ARM A32/Thumb-2/VFP 无 JIT interpreter。
- 图形：guest EGL/GLES 调用经桥接进入 ANGLE，iOS 正式后端为 Metal。
- Java：host-side DEX runtime；native ARMv7 位于 guest 执行域，JNI 负责双向边界。
- 线程：一个 guest Android pthread 对应一个 Darwin pthread；进程共享状态由 `ProcessRuntime` 持有，每个 guest 线程都有独立 `GuestThreadContext`。
- 不在当前范围：普通 Android App、完整 Android OS、多 Android 进程、Binder/system_server、Google Play Services、登录、支付和后台服务。

## 当前实现组成

| 目录 | 职责 | 当前性质 |
|---|---|---|
| `Runtime/ArmInterpreter` | ARMv7 指令执行、guest memory 和页权限 | touchHLE 派生 Rust 核心，正式执行后端，但指令覆盖仍需独立扩充 |
| `Runtime/Process` | 32 位 guest VMA、fd namespace | 公共 substrate；VMA 已用于正式 linker/Bionic 路径 |
| `Runtime/HostServices` | Darwin VM、文件、时钟、线程等原语 | Host 边界，不承载 Android policy |
| `Runtime/AospLinker` | ELF segment mapping、dynamic section、依赖、符号、ARM relocation、constructor/finalizer、libdl 生命周期 | 裁剪自 KitKat linker 的正式 production path |
| `Runtime/Bionic` | `mmap/__mmap2`、pthread、futex、TLS、errno、同步语义 | 已接入 production 的 AOSP/Bionic source port；其余 libc/libm 仍未整体迁移 |
| `Runtime/NativeCore` | guest ABI import、allocator、系统调用桥和 native fixture | 混合状态；部分是正式公共能力，部分仍保留固定表和 PoC 实现 |
| `Runtime/GuestRuntime` | `ProcessRuntime`、`GuestThreadContext`、ARM/DEX/JNI/GLES/输入整合 | production 编排层，但 JNI 与若干 handle/array/trap 表仍未正式化 |
| `Runtime/DexLoom` | DEX 解析、解释、对象模型、JNI 和 AndroidMini Framework | 可执行真实 DEX；仍是大范围 Partial/PoC，不能视为完整 Dalvik/Framework |
| `Runtime/AndroidFw` | APK/ZIP、AssetManager、资源表和资源选择 | 直接编译选定 KitKat `androidfw`/`libutils` 源码，host adapter 边界稳定 |
| `Runtime/Bitmap` | KitKat Skia PNG 解码和 Bitmap host object | 已进入 native build；Bitmap Framework 语义仍通过 HLE 暴露 |
| `App` | UIKit host、Simulator/device 测试入口、真实游戏回归和状态输出 | 调试/验证壳，仍含 Kung Foo、Gloomy 和 synthetic fixture 入口，不是通用 launcher |
| `Tests` | 契约、Android 4.4 differential、stress、真实游戏和 trajectory fixture | 当前正确性的主要证据来源 |
| `Vendor` | 固定 AOSP、Skia、libpng、zlib 和 ANGLE headers | 第三方源码/头文件；ANGLE 二进制由构建脚本按 hash 下载 |

## 已经形成正式路径的部分

1. KitKat linker 的 load span、load bias、`PT_LOAD`、BSS、保护、RELRO、dynamic linking、`DT_NEEDED`、SYSV hash、ARM relocation、constructor/finalizer 和 `dlopen/dlsym/dlclose/dlerror` 生命周期已经成为 production owner。旧 custom segment/dynamic loader 不再是正式语义来源。
2. guest VMA 权限会约束 ARM instruction fetch/read/write；image unload 会释放映射并允许地址复用。
3. `ProcessRuntime + GuestThreadContext` 已进入 Apple Runtime；主线程和 worker 使用同一种 thread context。Bionic lifecycle、TLS/errno、futex、mutex/cond/once/timed wait 经过契约和 Android 4.4 differential 测试。
4. APK/Asset/resources 路径实际编译 AOSP `androidfw` 公共源码；PNG 解码使用 KitKat Skia/libpng 子集。
5. Simulator 和 iphoneos 使用同一套 native core、Rust interpreter、DEX/JNI、AOSP components 和 ANGLE 接口，不维护独立 Windows Runtime。

## 已验证但尚未闭合的部分

- ARM interpreter 已运行真实 ARMv7 ELF，但尚无覆盖全部 A32/Thumb-2/VFP 行为的完备架构测试集。
- DEX 能执行、调用 native、接收 native callback 并经历 GC，但 DexLoom 尚未达到 Dalvik 语义完整度。
- JNI method registry 已改为动态结构，但 `agr_guest_runtime.c` 仍有 64 项 JNI string handle、32 项 primitive array、512 项 trap 等固定容量；local/global/weak reference、ID 生命周期和 GC roots 尚未按 Dalvik 完整迁移。
- `AndroidMini/dx_android_framework.c` 是 `LEGACY_REFERENCE`，不是 production source，也不是待补 API 清单。
- NativeActivity、Looper、Window 和触摸已经打通真实样本路径，但生命周期、队列、线程 affinity 和多窗口语义没有完成全面 API19 对照。
- EGL/GLES1 的真实 draw/swap/readback 已验证；GLES2/3、完整 EGL 对象生命周期和所有 guest pointer/offset 组合尚未声明为完整支持。
- ARM EHABI Phase 1、2A、2B 已闭合：未经修改的 NDK r10e GCC 4.8 guest runtime 已通过跨 DSO ARM/Thumb unwind、cleanup/resume、typed catch、继承与多继承调整、pointer catch、rethrow、exception lifetime、nested catch、双 guest thread TLS 隔离及 unload/reload differential。更广的 C++ 标准库能力仍不在该结论内。
- 音频主要是 Framework stub/HLE，占位行为不能作为 SoundPool、AudioTrack 或 OpenSL ES 已实现的证据。
- `App/main.m` 仍是测试 harness，包含样本名、固定 native load base、fixture 入口和回归流程；通用 APK launcher 尚未实现。

## 当前真实游戏证据

自动回归包含 Kung Foo Barracuda 与 Gloomy Dungeons 2，两条路径要求执行原始 APK/DEX/native 代码并产生可见 framebuffer。样本由 `tools/fetch_fdroid_samples.py` 按 `Tests/Samples/fdroid.json` 的版本和 SHA-256 获取，APK 与提取出的商业/第三方资源不进入 Git。

这些结果证明 ARM、DEX/JNI、ELF、资源、Bitmap、EGL/GLES 和 iOS host 可以组成同一执行闭环；它们不能证明游戏已经能够完整游玩。Kung Foo 的长期 gameplay、完整菜单交互和所有公共 Runtime 语义仍需在后续 closure 后重新验证。

## 仓库与许可证

远程仓库为 `https://github.com/xwc9527/early-android-game-runtime.git`，正式集成分支为 `main`。项目自有代码使用 Apache-2.0；AOSP、Skia、zlib、libpng、touchHLE 和 JNI headers 保留各自许可证。具体来源见 `THIRD_PARTY_NOTICES.md`、`Runtime/AospLinker/SOURCE_PORT.md` 及各 Runtime 子目录 README。

完整迁移决策、源码 placement 和 closure 标准见 `docs/MIGRATION_ARCHITECTURE_PLAN.md`。
