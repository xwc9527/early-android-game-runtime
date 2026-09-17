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

static int file_span(const char *path, uint32_t *span, uint32_t *min_vaddr, uint32_t *load_count) {
    FILE*f=fopen(path,"rb");if(!f)return -1;Elf32_Ehdr e;if(fread(&e,1,sizeof(e),f)!=sizeof(e)){fclose(f);return -1;}
    if(fseek(f,e.e_phoff,SEEK_SET)){fclose(f);return -1;}uint32_t min=0xffffffffu,max=0;
    *load_count=0;
    for(uint32_t i=0;i<e.e_phnum;i++){Elf32_Phdr p;if(fread(&p,1,sizeof(p),f)!=sizeof(p)){fclose(f);return -1;}if(p.p_type==PT_LOAD){(*load_count)++;if(p.p_vaddr<min)min=p.p_vaddr;if(p.p_vaddr+p.p_memsz>max)max=p.p_vaddr+p.p_memsz;}}
    fclose(f);*min_vaddr=min&~4095u;*span=((max+4095u)&~4095u)-*min_vaddr;return 0;
}
static int map_protection(uintptr_t address) {
    FILE*f=fopen("/proc/self/maps","r");char line[512],perm[8];unsigned long a,b;int result=-1;
    while(f&&fgets(line,sizeof(line),f))if(sscanf(line,"%lx-%lx %7s",&a,&b,perm)==3&&address>=a&&address<b){result=(perm[0]=='r'?1:0)|(perm[1]=='w'?2:0)|(perm[2]=='x'?4:0);break;}
    if(f)fclose(f);return result;
}
static int print_load_layout(const char *path) {
    FILE *file=fopen(path,"rb");Elf32_Ehdr header;int first=1;
    if(!file||fread(&header,1,sizeof(header),file)!=sizeof(header)||fseek(file,header.e_phoff,SEEK_SET))return -1;
    printf("],\"pt_load_layout\":[");
    for(uint32_t i=0;i<header.e_phnum;i++){
        Elf32_Phdr p;if(fread(&p,1,sizeof(p),file)!=sizeof(p)){fclose(file);return -1;}
        if(p.p_type!=PT_LOAD)continue;
        printf("%s[%u,%u,%u,%u,%u]",first?"":",",p.p_offset,p.p_vaddr,p.p_filesz,p.p_memsz,p.p_flags);
        first=0;
    }
    fclose(file);return 0;
}
int main(int argc,char**argv){if(argc!=2)return 2;uint32_t span=0,min_vaddr=0,load_count=0;if(file_span(argv[1],&span,&min_vaddr,&load_count))return 3;
    errno=0;void*bad=mmap(0,4096,PROT_READ,MAP_PRIVATE,-1,1);int offset_einval=bad==MAP_FAILED&&errno==EINVAL;
    errno=0;void*bad_fd=mmap(0,4096,PROT_READ,MAP_PRIVATE,-1,0);int invalid_fd_ebadf=bad_fd==MAP_FAILED&&errno==EBADF;
    void*first=mmap(0,4096,PROT_READ|PROT_WRITE,MAP_PRIVATE|MAP_ANONYMOUS,-1,0);int fixed_replace=0,failed_fixed_preserves=0,protect_ok=0,unmap_ok=0,errno_preserved_success=0;
    if(first!=MAP_FAILED){memset(first,0x5a,4096);void*second=mmap(first,4096,PROT_READ|PROT_WRITE,MAP_FIXED|MAP_PRIVATE|MAP_ANONYMOUS,-1,0);fixed_replace=second==first&&((unsigned char*)second)[0]==0;((unsigned char*)second)[0]=0x5a;errno=0;void*bad_fixed=mmap(second,4096,PROT_READ,MAP_FIXED|MAP_PRIVATE,-1,0);int preserved_protection=map_protection((uintptr_t)second);failed_fixed_preserves=bad_fixed==MAP_FAILED&&errno==EBADF&&preserved_protection==3&&((unsigned char*)second)[0]==0x5a;errno=123;protect_ok=mprotect(second,4096,PROT_READ)==0;errno_preserved_success=protect_ok&&errno==123;unmap_ok=munmap(second,4096)==0;}
    void*h=dlopen(argv[1],RTLD_NOW);if(!h){fprintf(stderr,"%s\n",dlerror());return 4;}unsigned char*b=(unsigned char*)dlsym(h,"agr_reference_bss");void*relro=dlsym(h,"agr_reference_relro");void*entry=dlsym(h,"agr_reference_entry");Dl_info info;if(!b||!relro||!entry||!dladdr(entry,&info))return 5;
    int bss_zero=1;for(int i=0;i<8192;i++)if(b[i])bss_zero=0;uintptr_t base=(uintptr_t)info.dli_fbase;int relro_ro=map_protection((uintptr_t)relro)==1;
    int *pages=(int*)malloc(sizeof(int)*(span/4096));if(!pages)return 6;
    for(uint32_t i=0;i<span/4096;i++)pages[i]=map_protection(base+min_vaddr+i*4096);
    int close_ok=dlclose(h)==0;int unload_unmapped=close_ok&&map_protection(base+min_vaddr)==-1;
    void*h2=dlopen(argv[1],RTLD_NOW);void*entry2=h2?dlsym(h2,"agr_reference_entry"):0;Dl_info info2;int reload_ok=h2&&entry2&&dladdr(entry2,&info2);int reload_reused=reload_ok&&(uintptr_t)info2.dli_fbase==base;if(h2)dlclose(h2);
    printf("{\"page_size\":%ld,\"load_span\":%u,\"load_bias_page\":%u,\"pt_load_count\":%u,\"bss_zero\":%s,\"relro_ro\":%s,\"offset_einval\":%s,\"invalid_fd_ebadf\":%s,\"map_fixed_replace\":%s,\"failed_fixed_preserves\":%s,\"mprotect_ok\":%s,\"errno_preserved_success\":%s,\"munmap_ok\":%s,\"unload_unmapped\":%s,\"reload_ok\":%s,\"reload_reused\":%s,\"page_protection\":[",sysconf(_SC_PAGESIZE),span,(unsigned)(base&4095u),load_count,bss_zero?"true":"false",relro_ro?"true":"false",offset_einval?"true":"false",invalid_fd_ebadf?"true":"false",fixed_replace?"true":"false",failed_fixed_preserves?"true":"false",protect_ok?"true":"false",errno_preserved_success?"true":"false",unmap_ok?"true":"false",unload_unmapped?"true":"false",reload_ok?"true":"false",reload_reused?"true":"false");
    for(uint32_t i=0;i<span/4096;i++)printf("%s%d",i?",":"",pages[i]);
    if(print_load_layout(argv[1]))return 7;
    puts("]}");free(pages);return 0;}
