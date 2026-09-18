__attribute__((noinline)) void C(void);
extern void agr_unwind_probe(void);
__attribute__((noinline)) void C(void) { agr_unwind_probe(); }
