/*
 * Android 4.4 ARM EHABI oracle. Must be compiled with NDK r10e GCC 4.8 and
 * statically linked libgcc so `_Unwind_Backtrace` is GCC-era ARM EHABI, not
 * NDK r23+ LLVM libunwind. See scripts/build-android44-unwind-gcc.sh.
 */
#include <dlfcn.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <unwind.h>

typedef struct {
  int count;
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

static int fixture_dso(const char *name) {
  return name && strstr(name, "libagr_unwind_") && !strstr(name, "probe");
}

static _Unwind_Reason_Code trace(_Unwind_Context *ctx, void *arg) {
  dump_state *dump = (dump_state *)arg;
  unsigned pc = (unsigned)_Unwind_GetGR(ctx, 15);
  unsigned sp = (unsigned)_Unwind_GetGR(ctx, 13);
  Dl_info info;
  const char *dso;
  memset(&info, 0, sizeof(info));
  if (!dladdr((void *)(uintptr_t)(pc & ~1u), &info) || !info.dli_fbase) return _URC_END_OF_STACK;
  dso = basename_of(info.dli_fname);
  if (!fixture_dso(dso)) return _URC_END_OF_STACK;
  if (dump->count < 16) {
    snprintf(dump->frames[dump->count].dso, sizeof(dump->frames[0].dso), "%s", dso);
    dump->frames[dump->count].relative_pc = (pc & ~1u) - (unsigned)(uintptr_t)info.dli_fbase;
    dump->frames[dump->count].sp = sp;
    dump->frames[dump->count].thumb = (pc & 1u) ? 1 : 0;
    dump->count++;
  }
  return _URC_NO_REASON;
}

void agr_unwind_probe(void) {
  dump_state dump;
  int i;
  memset(&dump, 0, sizeof(dump));
  _Unwind_Backtrace(trace, &dump);
  printf("{\"frames\":[");
  for (i = 0; i < dump.count; i++) {
    unsigned sp_delta = dump.frames[i].sp - dump.frames[0].sp;
    printf("%s{\"dso\":\"%s\",\"relative_pc\":%u,\"sp_delta\":%u,\"thumb\":%s}",
           i ? "," : "", dump.frames[i].dso, dump.frames[i].relative_pc, sp_delta,
           dump.frames[i].thumb ? "true" : "false");
  }
  printf("],\"stop\":\"no_module\"}\n");
}
