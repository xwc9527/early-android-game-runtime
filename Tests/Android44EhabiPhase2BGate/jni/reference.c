#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>
typedef int (*run_fn)(void);
typedef int (*get_fn)(int);
static void *open_lib(const char *name) { void *h=dlopen(name,RTLD_NOW|RTLD_GLOBAL); if(!h){fprintf(stderr,"dlopen %s: %s\n",name,dlerror());exit(2);}return h; }
static void *sym(void *h,const char *name){void*p=dlsym(h,name);if(!p){fprintf(stderr,"dlsym %s: %s\n",name,dlerror());exit(3);}return p;}
static void events(get_fn count,get_fn get){int n=count(0);putchar('[');for(int i=0;i<n;i++)printf("%s%d",i?",":"",get(i));putchar(']');}
int main(void){
  void *probe=open_lib("libagr_eh2b_probe.so"),*types=open_lib("libagr_eh2b_types.so"),*suite=open_lib("libagr_eh2b_suite.so"),*cross=open_lib("libagr_eh2b_A.so");
  get_fn count=(get_fn)sym(probe,"agr_eh2b_count"),get=(get_fn)sym(probe,"agr_eh2b_get"),value=(get_fn)sym(probe,"agr_eh2b_value");
  const char *names[]={"typed","inheritance","multiple","pointer","rethrow","lifetime_ref","lifetime_value","lifetime_rethrow","nested","threads"};
  const char *symbols[]={"agr_eh2b_typed","agr_eh2b_inheritance","agr_eh2b_multiple","agr_eh2b_pointer","agr_eh2b_rethrow","agr_eh2b_lifetime_ref","agr_eh2b_lifetime_value","agr_eh2b_lifetime_rethrow","agr_eh2b_nested","agr_eh2b_threads"};
  printf("{");
  int thread_values[4]={0};
  for(int i=0;i<10;i++){int r=((run_fn)sym(suite,symbols[i]))();printf("%s\"%s\":%d",i?",":"",names[i],r);if(i>=5&&i<=7){printf(",\"%s_events\":",names[i]);events(count,get);}if(i==9)for(int j=0;j<4;j++)thread_values[j]=value(20+j);}
  int first=((run_fn)sym(cross,"agr_eh2b_cross"))();printf(",\"cross\":%d,\"cross_events\":",first);events(count,get);printf(",\"cross_base\":%d,\"cross_derived\":%d",value(10),value(11));
  if(dlclose(cross))return 4; cross=open_lib("libagr_eh2b_A.so"); int reload=((run_fn)sym(cross,"agr_eh2b_cross"))();
  printf(",\"reload_cross\":%d,\"thread_one\":%d,\"thread_two\":%d,\"thread_ret_one\":%d,\"thread_ret_two\":%d}\n",reload,thread_values[0],thread_values[1],thread_values[2],thread_values[3]);
  dlclose(cross);dlclose(suite);dlclose(types);dlclose(probe);return 0;
}
