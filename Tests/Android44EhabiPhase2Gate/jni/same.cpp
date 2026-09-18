extern "C" void agr_eh2_event(int);
extern "C" void agr_eh2_reset(void);

static __attribute__((noinline)) void same_throw(void) {
    agr_eh2_event(1);
    throw 17;
}

extern "C" __attribute__((noinline)) int agr_eh2_same_run(void) {
    agr_eh2_reset();
    try {
        same_throw();
    } catch (...) {
        agr_eh2_event(2);
        return 1;
    }
    return 0;
}

