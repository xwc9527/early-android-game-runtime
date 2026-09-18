#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>

typedef int (*run_fn)(void);
typedef int (*count_fn)(void);
typedef int (*get_fn)(int);

static void *must_dlopen(const char *name) {
    void *handle = dlopen(name, RTLD_NOW | RTLD_GLOBAL);
    if (!handle) {
        fprintf(stderr, "dlopen %s: %s\n", name, dlerror());
        exit(2);
    }
    return handle;
}

static void *must_dlsym(void *handle, const char *name) {
    void *symbol = dlsym(handle, name);
    if (!symbol) {
        fprintf(stderr, "dlsym %s: %s\n", name, dlerror());
        exit(3);
    }
    return symbol;
}

static void print_events(const char *name, count_fn count, get_fn get) {
    int i, n = count();
    printf("\"%s\":[", name);
    for (i = 0; i < n; ++i) printf("%s%d", i ? "," : "", get(i));
    printf("]");
}

int main(void) {
    void *probe = must_dlopen("libagr_eh2_probe.so");
    void *same = must_dlopen("libagr_eh2_same.so");
    void *cross = must_dlopen("libagr_eh2_A.so");
    run_fn same_run = (run_fn)must_dlsym(same, "agr_eh2_same_run");
    run_fn cross_run = (run_fn)must_dlsym(cross, "agr_eh2_cross_run");
    count_fn count = (count_fn)must_dlsym(probe, "agr_eh2_count");
    get_fn get = (get_fn)must_dlsym(probe, "agr_eh2_get");
    int same_ok = same_run();
    printf("{");
    print_events("same", count, get);
    cross_run();
    printf(",");
    print_events("cross", count, get);
    printf(",\"same_ok\":%d}\n", same_ok);
    return 0;
}

