/*
 * Android 4.4 ARM EHABI oracle. Must be compiled with NDK r10e GCC 4.8 and
 * statically linked libgcc so `_Unwind_Backtrace` is GCC-era ARM EHABI, not
 * NDK r23+ LLVM libunwind. See scripts/build-android44-unwind-gcc.sh.
 *
 * Test-only frame filter. GCC 4.8.5 libgcc/unwind-arm-common.inc
 * __gnu_Unwind_Backtrace treats any callback return other than
 * _URC_NO_REASON as _URC_FAILURE and stops. _URC_END_OF_STACK is therefore
 * only a traversal terminator; the JSON "stop" field is a test protocol
 * value, not a GCC _Unwind_Reason_Code.
 */
#include <dlfcn.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <unwind.h>

enum {
  BEFORE_FIXTURE = 0,
  IN_FIXTURE = 1,
  LEFT_FIXTURE = 2
};

typedef struct {
  int count;
  int phase;
  struct {
    char dso[64];
    unsigned relative_pc;
    unsigned sp;
    int thumb;
  } frames[16];
} dump_state;

static const char *basename_of(const char *path) {
  const char *slash = path ? strrchr(path, '/') : NULL;
  return slash ? slash + 1 : path;
}

static int fixture_abc(const char *name) {
  return name &&
         (!strcmp(name, "libagr_unwind_C.so") ||
          !strcmp(name, "libagr_unwind_B.so") ||
          !strcmp(name, "libagr_unwind_A.so"));
}

static int record_frame(dump_state *dump, const char *dso, unsigned pc,
                        unsigned sp, unsigned fbase) {
  if (dump->count >= 16) return 0;
  snprintf(dump->frames[dump->count].dso, sizeof(dump->frames[0].dso), "%s", dso);
  dump->frames[dump->count].relative_pc = (pc & ~1u) - fbase;
  dump->frames[dump->count].sp = sp;
  dump->frames[dump->count].thumb = (pc & 1u) ? 1 : 0;
  dump->count++;
  return 1;
}

static _Unwind_Reason_Code leave_fixture(dump_state *dump) {
  dump->phase = LEFT_FIXTURE;
  return _URC_END_OF_STACK;
}

static _Unwind_Reason_Code trace(_Unwind_Context *ctx, void *arg) {
  dump_state *dump = (dump_state *)arg;
  unsigned pc = (unsigned)_Unwind_GetGR(ctx, 15);
  unsigned sp = (unsigned)_Unwind_GetGR(ctx, 13);
  Dl_info info;
  const char *dso;
  memset(&info, 0, sizeof(info));
  if (!dladdr((void *)(uintptr_t)(pc & ~1u), &info) || !info.dli_fbase) {
    if (dump->phase == IN_FIXTURE) return leave_fixture(dump);
    return _URC_NO_REASON;
  }
  dso = basename_of(info.dli_fname);
  if (fixture_abc(dso)) {
    dump->phase = IN_FIXTURE;
    record_frame(dump, dso, pc, sp, (unsigned)(uintptr_t)info.dli_fbase);
    return _URC_NO_REASON;
  }
  if (dump->phase == IN_FIXTURE) return leave_fixture(dump);
  return _URC_NO_REASON;
}

static int complete_cba(const dump_state *dump) {
  return dump->phase == LEFT_FIXTURE && dump->count == 3 &&
         !strcmp(dump->frames[0].dso, "libagr_unwind_C.so") &&
         !strcmp(dump->frames[1].dso, "libagr_unwind_B.so") &&
         !strcmp(dump->frames[2].dso, "libagr_unwind_A.so");
}

void agr_unwind_probe(void) {
  dump_state dump;
  int i;
  const char *stop;
  memset(&dump, 0, sizeof(dump));
  dump.phase = BEFORE_FIXTURE;
  _Unwind_Backtrace(trace, &dump);
  printf("{\"frames\":[");
  for (i = 0; i < dump.count; i++) {
    unsigned sp_delta = dump.frames[i].sp - dump.frames[0].sp;
    printf("%s{\"dso\":\"%s\",\"relative_pc\":%u,\"sp_delta\":%u,\"thumb\":%s}",
           i ? "," : "", dump.frames[i].dso, dump.frames[i].relative_pc, sp_delta,
           dump.frames[i].thumb ? "true" : "false");
  }
  stop = complete_cba(&dump) ? "fixture_boundary" : "incomplete";
  printf("],\"stop\":\"%s\"}\n", stop);
}
