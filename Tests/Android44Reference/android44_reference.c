#define _GNU_SOURCE
#include <dlfcn.h>
#include <elf.h>
#include <errno.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>

static int file_span(const char *path, uint32_t *span) {
    FILE*f=fopen(path,"rb");if(!f)return -1;Elf32_Ehdr e;if(fread(&e,1,sizeof(e),f)!=sizeof(e)){fclose(f);return -1;}
    if(fseek(f,e.e_phoff,SEEK_SET)){fclose(f);return -1;}uint32_t min=0xffffffffu,max=0;
    for(uint32_t i=0;i<e.e_phnum;i++){Elf32_Phdr p;if(fread(&p,1,sizeof(p),f)!=sizeof(p)){fclose(f);return -1;}if(p.p_type==PT_LOAD){if(p.p_vaddr<min)min=p.p_vaddr;if(p.p_vaddr+p.p_memsz>max)max=p.p_vaddr+p.p_memsz;}}
    fclose(f);*span=((max+4095u)&~4095u)-(min&~4095u);return 0;
}
static int map_writable(uintptr_t address) {
    FILE*f=fopen("/proc/self/maps","r");char line[512],perm[8];unsigned long a,b;int result=-1;
    while(f&&fgets(line,sizeof(line),f))if(sscanf(line,"%lx-%lx %7s",&a,&b,perm)==3&&address>=a&&address<b){result=strchr(perm,'w')!=0;break;}
    if(f)fclose(f);return result;
}
int main(int argc,char**argv){if(argc!=2)return 2;uint32_t span=0;if(file_span(argv[1],&span))return 3;
    errno=0;void*bad=mmap(0,4096,PROT_READ,MAP_PRIVATE,-1,1);int offset_einval=bad==MAP_FAILED&&errno==EINVAL;
    void*first=mmap(0,4096,PROT_READ|PROT_WRITE,MAP_PRIVATE|MAP_ANONYMOUS,-1,0);int fixed_replace=0,protect_ok=0,unmap_ok=0;
    if(first!=MAP_FAILED){memset(first,0x5a,4096);void*second=mmap(first,4096,PROT_READ|PROT_WRITE,MAP_FIXED|MAP_PRIVATE|MAP_ANONYMOUS,-1,0);fixed_replace=second==first&&((unsigned char*)second)[0]==0;protect_ok=mprotect(second,4096,PROT_READ)==0;unmap_ok=munmap(second,4096)==0;}
    void*h=dlopen(argv[1],RTLD_NOW);if(!h){fprintf(stderr,"%s\n",dlerror());return 4;}unsigned char*b=(unsigned char*)dlsym(h,"agr_reference_bss");void*relro=dlsym(h,"agr_reference_relro");void*entry=dlsym(h,"agr_reference_entry");Dl_info info;if(!b||!relro||!entry||!dladdr(entry,&info))return 5;
    int bss_zero=1;for(int i=0;i<8192;i++)if(b[i])bss_zero=0;uintptr_t base=(uintptr_t)info.dli_fbase;int relro_ro=map_writable((uintptr_t)relro)==0;dlclose(h);
    void*h2=dlopen(argv[1],RTLD_NOW);void*entry2=h2?dlsym(h2,"agr_reference_entry"):0;Dl_info info2;int reload_ok=h2&&entry2&&dladdr(entry2,&info2);int reload_reused=reload_ok&&(uintptr_t)info2.dli_fbase==base;if(h2)dlclose(h2);
    printf("{\"page_size\":%ld,\"load_span\":%u,\"load_bias_page\":%u,\"bss_zero\":%s,\"relro_ro\":%s,\"offset_einval\":%s,\"map_fixed_replace\":%s,\"mprotect_ok\":%s,\"munmap_ok\":%s,\"reload_ok\":%s,\"reload_reused\":%s}\n",sysconf(_SC_PAGESIZE),span,(unsigned)(base&4095u),bss_zero?"true":"false",relro_ro?"true":"false",offset_einval?"true":"false",fixed_replace?"true":"false",protect_ok?"true":"false",unmap_ok?"true":"false",reload_ok?"true":"false",reload_reused?"true":"false");return 0;}
