# AGR 新架构与工程方案

`REFERENCE_MIGRATION_RULES.md` 仍是 Android-visible source ownership 的最高规则。本文是 Phase 3 CLOSED 之后的工程方案。Phase 3 已 CLOSED。当前已有本机同源 CLEAN/TRACE x86 与 ARM 构建对、四个合格样本的成对回归证据、Migration Book、owner/source mapping 队列及 Source Manifest 工具。实验室是支撑设施：只有源码归属、依赖闭包或差分判定出现具体证据缺口才扩建。已观测入口不等于子簇闭包；闭包不等于迁移授权。当前 Framework 资源和 libcore 整数装箱候选仍是 `SOURCE_LOCATED`。本文不授权原创 Android 语义、游戏缺口补丁或新的 Framework/HLE。

已闭合或稳定的底座保持不动：ARM interpreter、linker/libdl、Bionic、pthread/TLS/futex、EHABI、allocator、APK bootstrap、ClassLoader、JNI、method/field resolution、class init、exception/native binding、GC root/lifetime、HostServices。要改变的是后续 Android Runtime / Framework 能力的发现、裁剪、迁移和修复方式。

## 1. 总体目标

唯一主路径：

```text
原始 APK
→ Android 4.4.4 Reference Lab
→ Game Dependency Mapper
→ Migration Book
→ API19 Source Closure
→ 按 Cluster 裁剪 Android 源码
→ 迁入 AGR
→ iOS Simulator / Device differential
→ 出现 divergence
→ 回 Reference + API19 Source 定位
→ 修正源码迁移 / Host Adapter
```

游戏发现实际入口和验证优先级；Android 4.4.4/API19 源码与子簇闭包决定候选迁移范围和实现结构。未观测不等于未使用，AGR 不允许原创 Android guest-visible semantics。

禁止：

```text
APK → AGR 运行 → 遇到缺口 → 根据现象补 API / HLE / patch → 再运行
```

## 2. 系统架构

五个部分：Android Reference Lab、Game Dependency Mapper、Migration Book、API19 Source Closure、Cluster Source Port。产物进入 AGR Runtime，再经过 iOS Differential Gate。Divergence 回到 Reference 和 API19 source，不在 AGR 里猜语义。

### Android Reference Lab

本地固定 API19 研究环境。Android discovery 不依赖 GitHub CI。

API19-CLEAN 是未经 AGR instrumentation 的 Android 4.4.4 reference。它是 semantic oracle，用于 differential、判断 Android 原始行为，以及验证 TRACE build 是否改变语义。

API19-TRACE 使用同一 API19/AOSP 基线，只加入最小 Dependency Mapper instrumentation。它运行样本 APK，发现真实 Android dependency surface，并生成 Migration Book。

TRACE 不能代替 CLEAN 成为最终语义 oracle。

## 3. Game Dependency Mapper

Mapper 不追踪完整 Android 内部运行。它只找游戏进入 Android Runtime 的真实入口和动态产生的依赖。默认只保留最小观测集。

### DEX / Java

记录游戏侧实际触发的 Android/libcore 入口：caller、dex_pc、opcode、method_idx、target descriptor、resolved callee。同时记录 class load、class initialization、field resolution、reflection discovery、`Class.forName`、`ClassLoader.loadClass`、`Method.invoke`、layout inflate class。

不要求动态跟踪 `Activity.setContentView` 之后的 PhoneWindow、LayoutInflater、Resources 内部链。那些内部依赖由 API19 Source Closure 展开。Mapper 只需要证明 `Game → Activity.setContentView(I)V` 是真实依赖。

### JNI

持续记录 Java method → native library → native symbol/address → registration type。覆盖 `JNI_OnLoad`、`RegisterNatives`、static JNI binding、`FindClass`、`GetMethodID`、`GetFieldID`、`Call*Method`、native callback。Java→native 映射必须明确。动态注册不能依赖静态猜测。

### Native

不追踪游戏 `.so` 内部每个函数。只记录外部 Android dependency：`DT_NEEDED`、ELF imports、`dlopen`、`dlsym`、resolved Android symbol。例如 `libgame.so → libandroid.so!ALooper_pollAll`。

### Service boundary

Binder 不做完整跨进程 tracing。游戏进程进入 service boundary 时记录 service name、interface descriptor、transaction code，并标记 `HOST_SERVICE_HLE_BOUNDARY`。默认停在 system_server、SurfaceFlinger、AudioFlinger 等边界。只有 differential 无法解释时才专项深入。

### Lifecycle anchors

极轻量锚点：process start；Application attach/create；Activity create/start/resume/pause/stop/destroy；Thread start/end；Surface create/change/destroy。它们只给依赖增加运行阶段，不承担 Android lifecycle 模拟。

## 4. 静态补全

动态观测是 under-approximation。每个 APK 同时做静态分析：DEX method/class/field references、DEX invoke graph、ELF `DT_NEEDED`、ELF imports/exports、JNI declarations、`resources.arsc`、layout XML class references、reflection/string candidates。

等级不得混成一个“已验证依赖”：

| 等级 | 含义 |
|---|---|
| `OBSERVED_RUNTIME` | 在 API19 TRACE 中实际发生。最高优先级 |
| `DYNAMIC_DISCOVERED` | reflection、inflate、RegisterNatives、dlopen 等运行时发现 |
| `STATIC_REACHABLE` | 从游戏入口静态可达，当前 run 未执行 |
| `STATIC_REFERENCED` | 存在代码引用，尚不能证明可达 |
| `STATIC_SUSPECT` | 字符串、反射目标、动态 class name 等候选 |

## 5. Migration Book

正式产物是 Migration Book，不是日志。统一 ID：`dependency_id`、`kind`、`canonical_name`、`owner_cluster`。

示例：`Ljava/util/Vector;->addElement(Ljava/lang/Object;)V` 属于 libcore；`libandroid.so!ALooper_pollAll` 属于 AndroidNative；`android.view.IWindowSession#relayout` 属于 HostService。

每条至少包含：game caller、callsite、target、dependency kind、confidence、native yes/no、lifecycle phase、source repo、source revision、source module、source file、source symbol、owner cluster、migration status。

Migration Book 是后续 Work 的正式输入。Work 不得根据游戏报错自行决定实现内容。

## 6. API19 Source Closure

Migration Book 回答游戏使用了什么。Source Closure 回答为了保持该 API19 行为需要迁哪些源码。

从 Android 4.4.4_r2 源码入口展开，按源码 ownership 和已有 AGR cluster 边界裁剪，不机械复制整棵 Framework。输出 Source Manifest：source files、required symbols、required data structures、initialization dependencies、registration dependencies、cross-cluster dependencies、excluded dependencies、service boundaries、host adaptation points。

动态 trace 决定 source entry。API19 源码决定 source closure。动态 trace 不承担完整调用图。

上层 cluster 只在自己的一条 crossing edge 上记录 prerequisite 并停止该 origin 的递归。`external_cluster_sources` 里的 source-derived owner 也可以带 `prerequisite_edges`，但只能匹配该 owner 自己的 `cross_cluster_source_edges`。截断绑定当前 owner、exact crossing 和到达它的 origin；observed entry 的 stop key 不沿递归树传播。例如 `Framework.ZygotePreload` 留在上层 closure，只截断它进入 `Dalvik.ClassInitialization` 和 `Libcore.BootClassLoading` 的边。截断字段必须与该 crossing 的 edge、owner、repo、revision、file、symbol、SHA 一致，禁止凭空声明。`UNRESOLVED` 与 `REOPEN_REQUIRED` 进入 closure work queue，并保留声明该边的 owner 自己的 `origin_dependency_ids` 和完整 `source_paths`。`PREREQUISITE_CLOSED` 在正式 API19 CLEAN differential producer 存在之前一律拒绝，不能视为已满足，也不能靠省略 work queue 放行。记录仍须通过 `external_edge_closed`，并且 `ci/governance/substrate-production-contracts.json` 里有同一 semantic owner 的 `PRODUCTION_CLOSED` 记录，绑定 source digest/revision、production module、tested commit/tree 和 `closure_run`。`closure_run` 必须是 `ci/governance/closure-attempts.json` 中 tested commit 与 tested tree 完全一致的唯一一条 `VALID_PASS`，并且 `git rev-parse <tested_commit>^{tree}` 等于该 tree。手写 differential、ledger `VALID_PASS` 和 git tree 一致都不能充当 CLEAN authority。source `SOURCE_CLOSED` 不等于 production contract。该 registry 初始为空，不能自证，也不映射任何真实 substrate owner。substrate 的内部依赖属于 substrate 自己的 closure，不计入声明了该边的上层 origin。当前确认的 substrate owner 是 `Libcore.BootClassLoading`、`Dalvik.BootClassResolution`、`Dalvik.ClassInitialization`、`Dalvik.ClassVerification`、`Dalvik.Monitor`、`Dalvik.ThreadState`、`Dalvik.MethodInvocation`、`Dalvik.ObjectAllocation`、`Dalvik.StaticFieldArrayRoots`、`Dalvik.JNINativeBinding`、`Bionic.PthreadCondition`、`Bionic.ClockGettime`。`Framework.ZygotePreload` 仍是 Integer 的启动环境 source owner。`Framework.ZygoteVMOptions` 与 `AndroidNative.InitZygote` 保持现有窄 source owner。新增 substrate owner 必须先确认。

`prerequisite_edges` 是上层 cluster 到公共 substrate 的关系，不是 owner 的 `SOURCE_LOCATED` / `SOURCE_CLOSED` 状态。关系只有 `UNRESOLVED`、`PREREQUISITE_CLOSED`、`REOPEN_REQUIRED`。`PREREQUISITE_CLOSED` 只表示该公共 owner 已在自己的闭包和生产合同中独立关闭。在正式 API19 CLEAN differential producer 存在之前，该关系一律被拒绝，不能满足上层 prerequisite。即便将来被接受，上层仍须完成自己的 source files、inline edges、boundary contracts、零 unresolved edge 和 cluster review，才能 `MIGRATION_AUTHORIZED`。`UNRESOLVED` 与 `REOPEN_REQUIRED` 都阻止上层 `SOURCE_CLOSED` 和 `MIGRATION_AUTHORIZED`。私有 source file、`SERVICE_HLE`、excluded HLE boundary 和 `GAME_PATCH` 不能绕过。公共 substrate 的缺陷必须 evidence-backed REOPEN 该公共 owner，由它单独完成 source repair、differential 和 CLOSE 后，上层再引用。本规则的引入不重分类现有 Integer / Resources index 或 seed；两者继续保持 `SOURCE_LOCATED` 且 `MIGRATION_AUTHORIZED=false`。

## 7. Cluster Source Port

迁移单位是 cluster，不是游戏、不是真实 bug、也不是单个 method。同一 cluster 的状态机、核心数据结构、错误行为、初始化、对象生命周期和内部调用关系原则上一起保留。

允许修改的只有 Linux kernel、Binder/service、SurfaceFlinger、AudioFlinger、device interface，以及 Darwin/UIKit/Metal/CoreAudio adapter。Android policy 不得下沉到 HostServices。

## 8. Source Ownership

任何 Android-visible production change 必须声明 API19 source revision、source repository、source file、source symbol、owner cluster、migration type。

migration type 只能是 `SOURCE_PORT`、`AOSP_NATIVE_ADAPT`、`HOST_BOUNDARY`、`SERVICE_HLE`。API19 有对应源码时，禁止 `ORIGINAL_IMPLEMENTATION`、`APPROXIMATION`、`GAME_PATCH`、`SYNTHETIC_ANDROID_BEHAVIOR`。

修复路径：

```text
iOS divergence
→ earliest divergence
→ CLEAN reference
→ TRACE evidence
→ upstream source owner
→ missing source / wrong source port / wrong adaptation / wrong runtime engine
→ 修迁移
```

不得看到异常后猜 Android 行为并写 if/return/HLE。

## 9. Progressive Deep Trace

默认只运行最小 Mapper。仅在以下情况加深，并且只加深一条具体调用链：iOS 出现无法解释的 divergence；AGR 出现跨样本共享缺陷但 Migration Book 没有对应 dependency；已声明的 service boundary 上 host adapter 无法通过 differential；动态 dependency 无法从现有 trace 定位 source owner。

问题闭合后回写 Migration Book / Source Manifest。深层 trace 不升级成默认常驻系统。

## 10. 本地 Reference Workbench

Android discovery 在本机。推荐 Ubuntu native、KVM、高速 NVMe、本地 AOSP 4.4.4_r2 checkout。长期目录概念是 `/agr-reference/` 下的 `aosp-4.4.4-r2`、`clean-image`、`trace-image`、`emulator`、`mapper`、`source-index`、`migration-books`、`source-manifests`。

本地负责 emulator、trace build、APK run、dependency extraction、Migration Book、AOSP indexing、source closure、source slicing、incremental rebuild。高频循环不提交 CI 才知道结果。

## 11. CI

Discovery local. Closure CI.

Linux CI：runtime contracts、governance、source ownership validation、protected regressions、Migration Book schema validation、source manifest validation。

macOS CI：AGR build、iOS Simulator regression、iphoneos build、source-port differential。

CI 不再承担 Android dependency discovery、反复修改 tracer、AOSP 高频源码搜索、Migration Book 探索、Source slicing 探索。

## 12. 样本运行

Migration Book 支持 per-run、per-game、per-cluster、global corpus union。同一 APK 多场景后做 union。最低 scenario：cold start、first frame、main menu、gameplay、touch/input、pause/resume、background/foreground、save/load（存在时）、audio start/stop（存在时）、exit。

每增加一个 APK：static scan → API19 TRACE scenarios → Migration Book → 与已有 Book union。已有 cluster dependency 不重复迁。新 dependency 才触发 source closure。

## 13. 对现有 AGR 的迁移策略

不重建项目。先完成 Phase 3 final closure，然后冻结“运行游戏 → 逐缺口补能力”。

| 阶段 | 内容 |
|---|---|
| Phase R0 | Local Android Reference Lab |
| Phase R1 | Game Dependency Mapper |
| Phase R2 | Frozen Bubble Migration Book |
| Phase R3 | API19 Source Closure + Source Manifest |
| Phase R4 | 第一组 Framework Cluster Source Port |
| Phase R5 | CLEAN API19 ↔ AGR differential |
| Phase R6 | 增加第二、第三个不同技术栈游戏，验证 dependency union 是否收敛 |

当前 legacy Framework/HLE 不立刻全部删除。对应 AOSP cluster 迁入并通过 differential 之后，再删除该 legacy owner。这是替换式迁移。

## 14. 工程原则

```text
MAP → SOURCE → SLICE → PORT → DIFFERENTIAL → CLOSE
```

禁止 `RUN → FAIL → PATCH`。

Reference discovers. Source defines. AGR ports.

游戏只能暴露 Android dependency，不能定义 Android implementation。只要 API19 源码存在，bug、缺失实现或边界条件必须回到 upstream source 修复。

目标是把早期 Android 游戏的需求压成 `Game Dependency → API19 Source Subset → AGR Cluster`，而不是把某一个游戏跑起来当作完成。
