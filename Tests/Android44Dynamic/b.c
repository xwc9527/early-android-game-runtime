extern void trace_event(char);
extern int c_func(int);
extern int c_data;
int b_func(int value){return c_func(value)+c_data;}
__attribute__((constructor)) void b_ctor(void){trace_event('B');}
__attribute__((destructor)) void b_fini(void){trace_event('b');}
