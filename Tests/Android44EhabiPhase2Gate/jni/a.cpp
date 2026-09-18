extern "C" void agr_eh2_reset(void);
extern "C" void agr_eh2_event(int);
extern "C" void agr_eh2_B_call(void);

extern "C" __attribute__((noinline)) int agr_eh2_cross_run(void) {
    agr_eh2_reset();
    agr_eh2_event(10);
    try {
        agr_eh2_B_call();
    } catch (...) {
        agr_eh2_event(13);
        return 1;
    }
    return 0;
}

