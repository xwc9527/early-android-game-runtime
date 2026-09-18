#include <dlfcn.h>
#include <stdio.h>

int main(void) {
  void *a = dlopen("libagr_unwind_A.so", RTLD_NOW);
  void (*entry)(void);
  if (!a) { fprintf(stderr, "A: %s\n", dlerror()); return 2; }
  entry = (void (*)(void))dlsym(a, "A");
  if (!entry) { fprintf(stderr, "A symbol: %s\n", dlerror()); return 3; }
  entry();
  dlclose(a);
  return 0;
}
