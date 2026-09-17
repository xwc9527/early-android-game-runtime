extern void trace_event(char);
extern int b_func(int);
extern int c_data;
extern int optional_value __attribute__((weak));
int *a_data_pointer=&c_data;
int *a_weak_pointer=&optional_value;
int a_entry(int value){return b_func(value)+*a_data_pointer;}
int a_weak_value(void){return &optional_value?optional_value:0;}
__attribute__((constructor)) void a_ctor(void){trace_event('A');}
__attribute__((destructor)) void a_fini(void){trace_event('a');}
void a_dt_init(void){trace_event('I');}
void a_dt_fini(void){trace_event('i');}
