extern "C" void agr_eh2b_event(int);
extern "C" void agr_eh2b_C_throw(void);
struct Cleanup { ~Cleanup() { agr_eh2b_event(812); } };
extern "C" __attribute__((noinline)) void agr_eh2b_B_call(void) {
    Cleanup cleanup; agr_eh2b_C_throw();
}
