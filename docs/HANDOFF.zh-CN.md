# Early Android Game Runtime 工程交接文档

[`REFERENCE_MIGRATION_RULES.md`](../REFERENCE_MIGRATION_RULES.md) 是所有 Android-visible semantics 的最高优先级迁移规则，覆盖 Dalvik、libcore、Framework、JNI semantics、Bionic 和 Android native userspace。本文档服从该文件。真实游戏只产生 dependency evidence 和 regression evidence。Runtime gap 本身不授权新增 Android implementation 或 HLE。只要 API19/AOSP 存在源码 owner，不得仅凭语义等价自行重写。

## 交接状态

交接基线是 GitHub `main`。接手时先执行：

```bash
git clone https://github.com/xwc9527/early-android-game-runtime.git
cd early-android-game-runtime
git switch main
git status --short
git rev-parse HEAD
```

`git status --short` 必须为空。不要从本机 `build/`、`artifacts/`、`.tools/`、`.tmp/` 或 `App/Resources` 中复制生成物来补仓库；这些目录包含缓存、设备证据或外部游戏输入。干净 checkout 的可重建性由构建脚本和 CI 负责。

当前工程阶段是 Phase 3 Dalvik semantics。3A0、3A、3B、3C、3D 已 CLOSED，Phase 3 整体尚未 CLOSED。AOSP linker/libdl、guest VMA、Bionic pthread/TLS/futex、线程模型以及 GCC 4.8 ARM EHABI Phase 1/2A/2B 已完成 production closure。Framework 迁移尚未开始，也没有预先声明的 Framework 类清单。

## 开发环境

正式 iOS 构建需要：

- macOS，带可用的 Xcode、iPhoneOS SDK 和 iOS Simulator runtime；CI 当前使用 `macos-15`。
- Xcode command line tools：`xcrun`、`clang`、`codesign`、`simctl`、`PlistBuddy`、`security`。
- Rust stable toolchain 和 `rustup`；脚本会安装 `aarch64-apple-ios` 或 `aarch64-apple-ios-sim` target。
- Python 3、`curl`、`unzip`、`zip`、`shasum` 和常规 Bash 工具。
- 网络访问，用于下载固定版本 F-Droid APK 和 ANGLE XCFramework。

Windows 可以用于 Git 管理、APK 静态扫描和通过 USB 读取 iPhone 状态，但不是正式 Runtime 构建 host。仓库没有需要恢复的 Windows Runtime 分支。

ANGLE 固定为 `v2.1.28252`，下载包 SHA-256 在 `scripts/build-iphoneos.sh` 和 `scripts/build-and-run-simulator.sh` 中校验。不要无验证地替换版本或跳过 hash。

## 构建与验证

Simulator 完整构建、安装和回归：

```bash
bash scripts/build-and-run-simulator.sh
```

交互启动：

```bash
INTERACTIVE=1 bash scripts/build-and-run-simulator.sh
```

零输入启动证据：

```bash
ZERO_INPUT_AB=1 bash scripts/build-and-run-simulator.sh
```

有硬超时的 smoke：

```bash
python3 scripts/run-simulator-smoke-bounded.py --timeout-seconds 900
```

iphoneos arm64 构建：

```bash
bash scripts/build-iphoneos.sh
```

未配置签名时输出位于 `build/iphoneos/AGRDevice.app` 和 `AGRDevice-unsigned.ipa`，它们只能证明 device SDK 编译和链接。配置签名后才会生成可安装的 `AGRDevice.ipa`。

关键契约测试可单独执行：

```bash
bash scripts/test-nativecore-allocator.sh
bash scripts/test-jni-methods.sh
bash scripts/test-host-services-darwin.sh
bash scripts/test-guest-vma.sh
bash scripts/test-aosp-linker.sh
bash scripts/test-bionic-futex-host.sh
bash scripts/test-guest-fd-darwin.sh
cargo test --manifest-path Runtime/ArmInterpreter/Cargo.toml --lib
```

不要以单个真实游戏画面代替这些契约测试。修改 linker、VMA、Bionic、线程或 ARM memory 权限后，还必须运行 Android 4.4 differential workflow。

## GitHub Actions

| Workflow | 文件 | 作用 |
|---|---|---|
| AGR Runtime | `.github/workflows/runtime.yml` | 独立 contracts、bounded Simulator smoke、真实游戏 target、统一 run-summary 和 closure identity gate |
| AGR device build | `.github/workflows/device-build.yml` | iphoneos arm64 编译、可选签名、IPA artifact 和 device run-summary |
| Android 4.4 linker differential | `.github/workflows/android44-linker-reference.yml` | 在真实 API19 ARM emulator 与 AGR 比较 mmap/linker/libdl/pthread 结果 |
| iOS Simulator smoke (bounded) | `.github/workflows/ios-simulator-smoke.yml` | 独立硬超时 smoke 与 hang 现场采集 |
| AGR governance | `.github/workflows/governance.yml` | 文档/状态/schema、stable-module reopen 和治理工具校验 |

workflow 使用 path filter。只修改文档或 `tools/observe_iphone.py` 不会自动触发 Runtime 构建；迁移到新仓库后应手动运行前三个 workflow 建立新环境的基线。

## 真机签名和 IPA

device workflow 支持以下 GitHub Actions secrets：

- `IOS_CERTIFICATE_P12_BASE64`
- `IOS_CERTIFICATE_PASSWORD`
- `IOS_PROVISIONING_PROFILE_BASE64`
- `IOS_BUNDLE_ID`
- `IOS_ARTIFACT_PASSWORD`

证书和 profile 同时存在时，workflow 创建临时 keychain、签名 ANGLE frameworks 和 App，再把 IPA 用 `IOS_ARTIFACT_PASSWORD` 加密后上传。没有 secrets 时只上传 unsigned link-validation build。证书、profile、Apple ID、设备凭据和解密密码不得进入 Git。

如继续使用 Windows 免费签名工具，应该对 CI 生成的 unsigned IPA 重新签名；该步骤是外部部署流程，不属于 Runtime source of truth。

## 真机状态采集

AGR 把运行状态写到 App Documents，并通过日志发出结构化状态。Windows 上可安装 `pymobiledevice3`，连接并信任设备后运行：

```powershell
python tools/observe_iphone.py --bundle-id dev.agr.simulator
```

如果签名时改变了 bundle ID，参数必须使用实际 ID。默认输出目录为 `artifacts/iphone-live/<timestamp>/`，包括：

- `syslog.log`、`runtime-status.ndjson`
- `runtime-status.json`
- `manual-replay.json`
- `runtime-failure.json`、`debug-failure.json`
- `failure-frame.png`
- `crash.ndjson`

这些文件用于关联输入、frame/swap、guest PC、Android log、recent calls、failure signature 和系统 crash。发生 hang 时必须保留硬超时现场，禁止无限等待 CI。

## 外部样本和可重建性

真实 APK 不在仓库。`tools/fetch_fdroid_samples.py` 根据 `Tests/Samples/fdroid.json` 下载并校验样本，再生成：

- `App/Resources/kungfoo.apk`
- `App/Resources/kungfoo-classes.dex`
- `App/Resources/kungfoo-native.so`
- `App/Resources/gloomy-librenderer.so`
- `samples/resolved.json`

这些文件、ANGLE binaries、`.app`、`.ipa`、构建对象和设备日志均被 `.gitignore` 排除。仓库只保存获取规则、hash、测试和源码。

## 当前必须保留的架构决策

1. `ProcessRuntime + GuestThreadContext + service-specific execution affinity` 是冻结的线程模型。
2. 一个 guest pthread 对应一个 Darwin pthread；不得退回 cooperative scheduler，也不得用全局 Runtime 锁把整个进程串行化。
3. Android-visible policy 来自固定的 Android 4.4.4 AOSP source port。HLE 不是 Android semantics 的实现方式；只有调用链最终到达明确排除的 Linux kernel、Binder/system_server、SurfaceFlinger、AudioFlinger 或真实 device/service boundary 时才允许终止为 HLE。HostServices 只提供 Darwin primitive。
4. AOSP linker 是唯一 production segment/dynamic owner；不得恢复 custom ELF policy。
5. guest pointer、`size_t`、fd、pthread 和 struct 均保持 32 位 Android ABI，禁止泄露 host arm64/Darwin layout。
6. Python 只用于构建、测试、审计和设备采集，不进入正式 Runtime 执行链。

## 开发顺序

新开发顺序固定为：

Phase 3 closure → Local Android Reference Lab → Game Dependency Mapper → Migration Book → API19 Source Closure → Cluster Source Port → Differential

不要从真实游戏缺口直接补 Android API 或 HLE。不要预先声明某个 Framework 类应该迁移。Framework owner 只由 Migration Book → API19 Source Closure → Cluster Source Manifest 产生。

ARM C++ ABI / EHABI 的既定 Phase 1、2A、2B 已完成。不得把已闭合的 guest GCC exception ownership 改回 host HLE。

已 CLOSED 的 Runtime semantics 保持不动。Reference Lab 尚未开始。

## 接手验收清单

- `main` 可从空目录 clone，工作区无本地依赖。
- `THIRD_PARTY_NOTICES.md` 和第三方源码 license 保持完整。
- Simulator workflow、iphoneos build 和 Android 4.4 differential 在新组织/新仓库中手动运行成功。
- GitHub secrets 重新配置，但没有任何 secret 被提交。
- F-Droid 样本 hash 校验通过。
- bounded smoke 能在超时后失败退出并上传证据。
- 真机 observer 能拉取 Documents 状态和 crash/syslog。
- 后续每个模块都有 source baseline、execution placement、host boundary、contract、differential、stress、production cutover 和旧 PoC 退役记录。
