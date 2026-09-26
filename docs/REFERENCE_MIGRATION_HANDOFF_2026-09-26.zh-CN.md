# AGR 新架构实施交接（2026-09-26）

本文件记录 `feature/reference-migration-pipeline` 在 2026-09-26 停止开发时的状态。它取代 `docs/HANDOFF.zh-CN.md` 和 `docs/CURRENT_STATE.md` 中关于 Reference Lab 尚未构建、Framework source mapping 尚未开始的旧叙述；那些文件中的历史闭合记录仍需按各自证据核对。源码迁移规则以 `REFERENCE_MIGRATION_RULES.md` 为准，方案以 `docs/AGR_REFERENCE_MIGRATION_PLAN.zh-CN.md` 为准。本分支截至本文撰写前的最新实现提交为 `0eae37d`。

## 仓库与本地环境

- 仓库：`https://github.com/xwc9527/early-android-game-runtime.git`；当前分支：`feature/reference-migration-pipeline`。本文件随该分支提交和推送；不能把远程 `main` 当作本工作的现状。
- Windows 工作区：`C:\Users\47763\Documents\Codex\2026-09-25\he\work\agr-reference-audit`。
- WSL2 发行版：`Ubuntu-22.04-AGR`；固定 API19/AOSP checkout 位于 `/agr-reference/aosp-official-sync-4.4.4-r2`，CLEAN 与 TRACE 输出分别位于 `/agr-reference/clean-image` 和 `/agr-reference/trace-image`。大型构建产物和 APK 原件不纳入 Git，接手时须核查本机路径和哈希，不能仅凭本文件假定它们仍存在。
- AOSP 基线为 `android-4.4.4_r2`。当前固定的关键仓库 revision：`platform/frameworks/base@63ade05d76785975fc3292ca030abbaa1dda8891`、`platform/libcore@9b24ebf95f897a75c60c9c68d00694406afa6fbc`、`platform/dalvik@36e356c96640775f0a3f167bd2426ea0f0093b8b`。其他 repo 和每个文件的哈希在对应 source index 中。

## 已具备的能力与已通过的门禁

1. 同源 API19 CLEAN/TRACE x86 和 ARM 构建对已达 `BUILD_VERIFIED`。配对校验包含解析后的 manifest、镜像和工具链身份；正式差分必须调用 `assert_matched_reference`。正式配对采用相同的 portable interpreter 配置；JIT 和 x86 asm interpreter 不受当前 C++ invoke hook 覆盖。细节与限制见 `tools/reference-lab/README.md`、`tools/reference-lab/REVIEW-GATES.md`。
2. 四个固定回归探针：Frozen Bubble、KungFoo Barracuda、Gloomy Dungeons 2、Vector Pinball。各自的 CLEAN/TRACE 证据、场景、APK 哈希、Migration Book 和结构性生命周期 concordance 由 `tools/reference-lab/evidence/four-game-corpus-manifest.json` 与 `four-game-corpus-summary.json` 索引。Vector Pinball 使用 ARM reference，并在双方加载 `libgdx.so`；不能以 x86 Java 路径代替其 ARM native 路径。KungFoo 的 native gameplay 和得分后 game-over 状态已有配对证据。黑帧或截图不单独决定游戏状态。四个探针不需重做“能否运行”的证明。
3. Pixel Dungeon 没有合格的 CLEAN/TRACE 配对结果。现有诊断位于 `tools/reference-lab/evidence/pixel-reference-carrier-diagnosis.json`；样本有效性和 gameplay 未定。按当前任务范围，不继续投入 Pixel、截图或旧 emulator，除非它们成为源码归属、闭包或差分判定的必要条件。
4. 当前动态观测是 `APP_DEX_TO_BOOT_METHOD_INVOKE` 下界，不是全局依赖轨迹。四样本共观测 779 个不同 method identity，其中 114 个至少跨两个游戏，2 个四样本共享。原始直接文件 TRACE 记录由序号完整性校验；Book 聚合同一依赖的次数与首末序号，顺序记录仍独立保留。class/field、reflection、JNI/native、resource、service、完整生命周期等观测覆盖仍不完整。`NOT_OBSERVED != UNUSED`，这些统计不能授权删除。
5. Migration Book、per-game/corpus union、source seed、Source Manifest、source index 和 closure work queue 工具已可用。`verify_source_index.py` 检查固定 revision、每个文件的 SHA-256，且跨 owner 边的 symbol 必须出现在声称的具体源码文件。递归外部 owner、循环、遗漏 work queue、未审查边界与授权状态由验证器拒绝；拒绝项是后续闭包工作，不是完成状态。
6. 最近的资源索引验证结果：16 个外部 owner、21 条外部边、37 个外部源码文件、13 个入口源码文件和 1 个引用证据均通过固定源码校验。`tools/reference-lab` 下 `python3 -m unittest discover -p 'test_*.py'` 通过 40 项；`git diff --check` 通过。此验证只针对当前 source mapping/门禁，不代表 iOS Runtime 构建、正式 API19↔AGR 差分或生产迁移通过。

## 子簇状态

| 候选语义子簇 | 观测入口与源码展开 | 当前状态 | 授权 |
|---|---|---|---|
| `libcore.IntegerBoxing` | 三游戏的 5 种 Integer 方法；14 个源码派生 owner，3 个窄范围 `SOURCE_CLOSED`、11 个 `SOURCE_LOCATED`；26 个 closure work item | 整体 `SOURCE_LOCATED` | `MIGRATION_AUTHORIZED=false` |
| `Framework.Resources` | 四游戏共享的 `ContextThemeWrapper.getResources()` 与 `AssetInputStream.close()`；16 个源码派生 owner，全部 `SOURCE_LOCATED`；37 个 closure work item | 整体 `SOURCE_LOCATED` | `MIGRATION_AUTHORIZED=false` |

整数装箱证据在 `docs/INTEGER_BOXING_SOURCE_MAP_API19.md`、`tools/reference-lab/indexes/integer-boxing-api19-locations.json`、`tools/reference-lab/evidence/integer-boxing-source-seed.json`。`Integer.valueOf` 的 `-128..127` 缓存、Zygote 预加载继承、boot loader 解析、Dalvik class init/monitor/thread、allocation/OOME、构造 invoke/dexopt 和 GC static root 已建立源码路径；仅 static-field array-root、Zygote VM options、init.rc launch arguments 三个窄 owner 闭合。AGR 当前有重复 Integer class 注册、新建对象代替缓存、class init 等待和 OOME pending exception 等已定位差异。Bionic timed wait 还暴露 AGR Android `clock_gettime` 固定 16.7ms 合成时钟、忽略 clock ID 的差异。这些不是已通过的 CLEAN differential，也不许可单点生产补丁。

资源证据在 `docs/RESOURCE_CLUSTER_SOURCE_MAP_API19.md`、`tools/reference-lab/indexes/shared-resources-api19-locations.json`、`tools/reference-lab/evidence/shared-resource-source-seed.json`。`AssetInputStream.close` 已沿 Java lifecycle → AssetManager JNI/registration → androidfw Asset/ZIP/FileMap/zlib 展开；`ContextThemeWrapper.getResources` 已沿 Context/LoadedApk/ActivityThread → ResourcesManager cache → AssetManager paths、DisplayMetrics、CompatibilityInfo 展开。AGR 的 `agr_afw_close` 只 `close()` 内层 Asset 再删 wrapper，API19 JNI 则 `delete Asset*`；旧 AndroidMini 还有独立合成 `AssetManager.open`。这些是迁移差异，Java/JNI handle、refcount、生命周期与 host 文件边界仍未闭合。

最新完成的边界核对是 `DisplayManagerGlobal → IDisplayManager.getDisplayInfo`：CLEAN/TRACE 生成 AIDL 哈希一致，事务码分别为 `getDisplayInfo=1`、`registerCallback=3`、one-way `onDisplayEvent=1`，证据在 `tools/reference-lab/evidence/paired-displaymanager-aidl-transactions.json`。API19 app-process 指标链为 `ResourcesManager.getDisplayMetricsLocked → DisplayManagerGlobal.getCompatibleDisplay → Display.getMetrics → DisplayInfo.getAppMetrics/getMetricsWithSize`；它使用 app 宽高、logical density、物理 DPI、compat/noncompat 字段、`DisplayAdjustments` 缓存和兼容缩放。AGR 目前固定返回 `393×852`、`1080×2343`、density 440，只注册五个 DisplayMetrics 字段。该 owner 仍为 `SOURCE_LOCATED`。

## 停止时未完成的源码链

最后一次只读核对已在 API19 源码确认 `DisplayInfo.readFromParcel/writeToParcel` 对称传输 24 个字段；`DisplayManagerService` 是 `IDisplayManager.Stub`，其 `getDisplayInfo(int)` 位于 `services/java/com/android/server/display/DisplayManagerService.java:391`。这两个发现尚未加入 source index 或完成 service boundary contract。下一位接手者应从这里继续：核对 service 对 DisplayInfo 的生成、权限/空值/异常语义，以及 app-process callback 对缓存的失效顺序；将 Binder 截断边界限定为 app 可观察的请求、响应、callback、生命周期和错误，而不是机械迁入整个 `system_server`。随后继续闭合 `CompatibilityInfo` 的 ApplicationInfo/density 输入、ResourcesManager 缓存/配置分支，以及 AssetManager Java/JNI/native 生命周期。每条新边都应固定 repo revision、文件 SHA 和准确 symbol，再运行 index 校验和门禁。

`SOURCE_LOCATED`、新增 blocking edge、一次提交、一次门禁拒绝都不是交付终点。只有语义 owner 的状态、初始化、显式与隐式依赖、JNI/native/callback/resource/service 边以及平台截断合同审查完成，才可提交 `SOURCE_CLOSED` review；只有完整的 cluster Source Manifest 经门禁授权，才能开始 source port。生产迁移后需 API19 CLEAN 同轨迹 differential，裁剪还需删除后无分叉证据。现阶段没有新的 Framework/Integer source port，也没有宣称 AGR 新框架整体已完成。

## 接手复核

在仓库根目录先读 `AGENTS.md`、`REFERENCE_MIGRATION_RULES.md`、`docs/AGR_REFERENCE_MIGRATION_PLAN.zh-CN.md`、本文件、两个 source map、`tools/reference-lab/REVIEW-GATES.md`。`docs/HANDOFF.zh-CN.md` 与 `docs/CURRENT_STATE.md` 含早期 Reference Lab 叙述，不能用其旧 R0 段落覆盖此处当前证据。

```powershell
git switch feature/reference-migration-pipeline
git status --short
git log -1 --oneline
wsl.exe -d Ubuntu-22.04-AGR -- bash -lc 'cd /mnt/c/Users/47763/Documents/Codex/2026-09-25/he/work/agr-reference-audit/tools/reference-lab && python3 -m unittest discover -p test_\*.py'
```

源码索引校验使用 `tools/reference-lab/verify_source_index.py`，为每个 index 指定其 `--checkout`，并给跨仓库边传入对应的 `--external-checkout platform/<repo>=/agr-reference/aosp-official-sync-4.4.4-r2/<repo>`。已有资源验证涵盖 `frameworks/base`、`system/core`、`external/zlib`、`libnativehelper`、`dalvik`；整数索引还需按其文件声明检查 `libcore`。不得以测试通过替代对 source closure review 和 CLEAN differential 的判断。
