extern void trace_event(char);
int c_data=7;
int c_func(int value){return value+c_data;}
__attribute__((constructor)) void c_ctor(void){trace_event('C');}
__attribute__((destructor)) void c_fini(void){trace_event('c');}
