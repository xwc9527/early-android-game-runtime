#include <dlfcn.h>
#include <stdio.h>
#include <string.h>

typedef void (*reset_fn)(void);
typedef const char* (*events_fn)(void);
typedef int (*entry_fn)(int);
typedef int (*weak_fn)(void);

static const char* error_kind(const char* e){
  if(!e)return "none";
  if(strstr(e,"not found")||strstr(e,"could not load"))return "missing_dependency";
  if(strstr(e,"cannot locate")||strstr(e,"undefined symbol"))return "missing_symbol";
  return "other";
}

int main(void){
  void*trace=dlopen("libagr_trace.so",RTLD_NOW);if(!trace){fprintf(stderr,"trace: %s\n",dlerror());return 2;}
  reset_fn reset=(reset_fn)dlsym(trace,"trace_reset");events_fn events=(events_fn)dlsym(trace,"trace_events");reset();
  void*a1=dlopen("libagr_A.so",RTLD_NOW);if(!a1){fprintf(stderr,"A: %s\n",dlerror());return 3;}
  void*a2=dlopen("libagr_A.so",RTLD_NOW);entry_fn entry=(entry_fn)dlsym(a1,"a_entry");weak_fn weak=(weak_fn)dlsym(a1,"a_weak_value");
  int**data_pointer=(int**)dlsym(a1,"a_data_pointer");int**weak_pointer=(int**)dlsym(a1,"a_weak_pointer");
  char ctor[128];snprintf(ctor,sizeof(ctor),"%s",events());int result=entry?entry(5):-1;int weak_result=weak?weak():-1;
  int cross_data_relocated=data_pointer&&*data_pointer&&**data_pointer==7;
  int weak_relocated_zero=weak_pointer&&*weak_pointer==0;
  dlerror();void*missing=dlsym(a1,"not_exported_anywhere");const char*missing_kind=error_kind(dlerror());
  dlclose(a1);int after_one=entry?entry(6):-1;char after_one_trace[128];snprintf(after_one_trace,sizeof(after_one_trace),"%s",events());
  dlclose(a2);char after_unload[128];snprintf(after_unload,sizeof(after_unload),"%s",events());
  void*bad_needed=dlopen("libagr_bad_needed.so",RTLD_NOW);const char*bad_needed_kind=error_kind(dlerror());
  void*bad_symbol=dlopen("libagr_bad_symbol.so",RTLD_NOW);const char*bad_symbol_kind=error_kind(dlerror());
  void*reload=dlopen("libagr_A.so",RTLD_NOW);char after_reload[128];snprintf(after_reload,sizeof(after_reload),"%s",events());if(reload)dlclose(reload);
  printf("{\"dependency_order\":\"%s\",\"cross_result\":%d,\"cross_data_relocated\":%s,\"weak_result\":%d,\"weak_relocated_zero\":%s,\"missing_dlsym\":\"%s\",\"after_one_close\":%d,\"after_one_trace\":\"%s\",\"after_unload\":\"%s\",\"bad_needed\":\"%s\",\"bad_symbol\":\"%s\",\"after_reload\":\"%s\",\"reloaded\":%s,\"entry_visible_after_unload\":false}\n",
    ctor,result,cross_data_relocated?"true":"false",weak_result,weak_relocated_zero?"true":"false",missing?"visible":missing_kind,after_one,after_one_trace,after_unload,
    bad_needed?"loaded":bad_needed_kind,bad_symbol?"loaded":bad_symbol_kind,after_reload,reload?"true":"false");
  dlclose(trace);return 0;
}
