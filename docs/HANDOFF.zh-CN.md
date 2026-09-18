# Early Android Game Runtime 工程交接文档

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

当前工程阶段应定义为“部分正式化 Runtime”。AOSP linker/libdl、guest VMA、Bionic pthread/TLS/futex 和线程模型已经完成 production cutover；DEX/Dalvik、JNI lifecycle、完整 libc/libm、C++ EHABI、Framework、NativeActivity/Input 和 Audio 尚未整体闭合。接手后不能恢复“真实游戏撞到一个调用就补一个 shim”的开发方式。

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
| iOS Simulator Runtime | `.github/workflows/ios-simulator.yml` | allocator/JNI/VMA/linker/pthread/fd contracts、bounded Simulator smoke 和真实游戏回归 |
| iPhone device build | `.github/workflows/ios-device.yml` | iphoneos arm64 编译、可选签名和 IPA artifact |
| Android 4.4 linker differential | `.github/workflows/android44-linker-reference.yml` | 在真实 API19 ARM emulator 与 AGR 比较 mmap/linker/libdl/pthread 结果 |
| iOS Simulator smoke (bounded) | `.github/workflows/ios-simulator-smoke.yml` | 独立硬超时 smoke 与 hang 现场采集 |

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
3. Android-visible policy 来自固定的 Android 4.4.4 AOSP source port 或明确 HLE；HostServices 只提供 Darwin primitive。
4. AOSP linker 是唯一 production segment/dynamic owner；不得恢复 custom ELF policy。
5. guest pointer、`size_t`、fd、pthread 和 struct 均保持 32 位 Android ABI，禁止泄露 host arm64/Darwin layout。
6. Python 只用于构建、测试、审计和设备采集，不进入正式 Runtime 执行链。

## 已知技术债与优先顺序

接手后的首要工作是继续 Runtime closure，而不是扩大 APK 数量或继续针对 Kung Foo 补洞。

正式依赖顺序保持：

`Native Android userspace` → `C++ ABI / ARM EHABI` → `剩余 Bionic native environment` → `Dalvik / GC` → `JNI / JavaVM` → `Framework`

当前下一工作包是 ARM C++ ABI / EHABI / unwind 正式迁移。

Native Android userspace 剩余基础闭合后，再进入 DEX/Dalvik、GC 与 JNI/JavaVM 正式化。

当前 JNI string / array / trap fixed tables 属于明确技术债，但不得在正式 JNI 迁移前通过扩表、局部 shim 或真实游戏补丁处理。当前 `agr_guest_runtime.c` 的 64 项 string handle 和其他固定容量明确属于未闭合实现。

EHABI unwind foundation 之后的 native 公共环境剩余主体：便携 Bionic libc/libm/stdio、文件和路径语义、真实时钟、signals/fault delivery、API19 allocator source port。当前 free-list allocator 已解决历史分配耗尽，但还不是 Bionic dlmalloc 的正式迁移结果。

再之后是 Framework 与设备边界：把 AndroidMini 中的 stub/固定成功行为替换为可声明、可测试的 API19 HLE；随后闭合 NativeActivity/Looper/Input/Window、Bitmap lifecycle 和 Audio/OpenSL ES。未知 API 不得伪造成功。

完成公共模块的契约与 differential 后，真实游戏只承担集成回归、coverage 和 failure signature 发现，不再作为逐调用设计 Runtime 的依据。

## 接手验收清单

- `main` 可从空目录 clone，工作区无本地依赖。
- `THIRD_PARTY_NOTICES.md` 和第三方源码 license 保持完整。
- Simulator workflow、iphoneos build 和 Android 4.4 differential 在新组织/新仓库中手动运行成功。
- GitHub secrets 重新配置，但没有任何 secret 被提交。
- F-Droid 样本 hash 校验通过。
- bounded smoke 能在超时后失败退出并上传证据。
- 真机 observer 能拉取 Documents 状态和 crash/syslog。
- 后续每个模块都有 source baseline、execution placement、host boundary、contract、differential、stress、production cutover 和旧 PoC 退役记录。
