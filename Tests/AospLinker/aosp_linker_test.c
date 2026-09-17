#include "../../Runtime/AospLinker/agr_aosp_linker.h"
#include "../../Runtime/NativeCore/agr_runtime.h"

#include <errno.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CHECK(x) do { if (!(x)) { fprintf(stderr,"FAIL %s:%d: %s\n",__FILE__,__LINE__,#x); return 1; } } while (0)
enum { MEMORY_SIZE = 0x100000, FIXTURE_SIZE = 0x4000 };
typedef struct harness { uint8_t memory[MEMORY_SIZE]; uint8_t page_protection[MEMORY_SIZE/4096]; const uint8_t *file; uint32_t file_size; } harness;

static int32_t write_guest(void *opaque,uint32_t address,const void *data,uint32_t size){
    harness *h=(harness*)opaque;if(address>MEMORY_SIZE||size>MEMORY_SIZE-address)return EFAULT;
    memcpy(h->memory+address,data,size);return 0;
}
static int32_t read_guest(void *opaque,uint32_t address,void *data,uint32_t size){
    harness *h=(harness*)opaque;if(address>MEMORY_SIZE||size>MEMORY_SIZE-address)return EFAULT;
    memcpy(data,h->memory+address,size);return 0;
}
static int32_t file_view(void *opaque,int32_t fd,const uint8_t **bytes,uint32_t *size){
    harness*h=(harness*)opaque;if(fd!=7)return EBADF;*bytes=h->file;*size=h->file_size;return 0;
}
static int32_t protect_guest(void *opaque,uint32_t address,uint32_t size,uint32_t protection){
    harness*h=(harness*)opaque;if(address%4096||size%4096||address>MEMORY_SIZE||size>MEMORY_SIZE-address)return EFAULT;
    memset(h->page_protection+address/4096,(int)protection,size/4096);return 0;
}
static void fixture(uint8_t *data){
    memset(data,0,FIXTURE_SIZE);Elf32_Ehdr*e=(Elf32_Ehdr*)data;
    memcpy(e->e_ident,ELFMAG,SELFMAG);e->e_ident[EI_CLASS]=ELFCLASS32;e->e_machine=EM_ARM;
    e->e_type=3;e->e_version=1;e->e_ehsize=sizeof(*e);e->e_phoff=sizeof(*e);e->e_phentsize=sizeof(Elf32_Phdr);e->e_phnum=3;
    Elf32_Phdr*p=(Elf32_Phdr*)(data+e->e_phoff);
    p[0]=(Elf32_Phdr){PT_LOAD,0x1000,0x1000,0,0x1800,0x1800,5,0x1000};
    p[1]=(Elf32_Phdr){PT_LOAD,0x2800,0x2800,0,0x500,0x2900,6,0x1000};
    p[2]=(Elf32_Phdr){0x6474e552u,0,0x3000,0,0,0x1000,4,1};
    for(uint32_t i=0x1000;i<0x2d00;i++)data[i]=(uint8_t)(i*37u+11u);
}

static void dynamic_fixture(uint8_t *data){
    fixture(data);
    Elf32_Ehdr*e=(Elf32_Ehdr*)data;e->e_phnum=4;
    Elf32_Phdr*p=(Elf32_Phdr*)(data+e->e_phoff);
    p[3]=(Elf32_Phdr){PT_DYNAMIC,0x2900,0x2900,0,4*sizeof(Elf32_Dyn),4*sizeof(Elf32_Dyn),6,4};
    Elf32_Dyn*d=(Elf32_Dyn*)(data+0x2900);
    d[0].d_tag=DT_STRTAB;d[0].d_un.d_ptr=0x2a00;
    d[1].d_tag=DT_SYMTAB;d[1].d_un.d_ptr=0x2a40;
    d[2].d_tag=DT_HASH;d[2].d_un.d_ptr=0x2b00;
    d[3].d_tag=DT_NULL;
    memcpy(data+0x2a00,"\0fixture_entry\0",15);
    Elf32_Sym*s=(Elf32_Sym*)(data+0x2a40);
    memset(s,0,2*sizeof(*s));s[1].st_name=1;s[1].st_value=0x1100;
    s[1].st_info=(STB_GLOBAL<<4)|2;s[1].st_shndx=1;
    ((uint32_t*)(data+0x2b00))[0]=1;((uint32_t*)(data+0x2b00))[1]=2;
}

static int test_bionic_contracts(void){
    harness h={0};uint8_t file[8192];for(uint32_t i=0;i<sizeof(file);i++)file[i]=(uint8_t)i;h.file=file;h.file_size=sizeof(file);
    agr_guest_vma_space v;CHECK(!agr_guest_vma_init(&v,4096,0x10000,0x100000000ull));
    agr_bionic_mmap_context c={&v,&h,write_guest,file_view,protect_guest};uint32_t a=0;int32_t ge=0;
    CHECK(agr_bionic_mmap(&c,0,4096,AGR_PROT_READ,AGR_MAP_PRIVATE,7,1,&a,&ge)==-1&&ge==EINVAL);
    CHECK(!agr_bionic_mmap2(&c,0,4096,AGR_PROT_READ,AGR_MAP_PRIVATE,7,1,&a,&ge));
    CHECK(a==0x10000&&h.memory[a]==0&&h.memory[a+1]==1);
    uint32_t fixed=0;CHECK(!agr_bionic_mmap2(&c,a,4096,AGR_PROT_READ|AGR_PROT_WRITE,AGR_MAP_FIXED|AGR_MAP_PRIVATE|AGR_MAP_ANONYMOUS,-1,0,&fixed,&ge));
    CHECK(fixed==a&&h.memory[a]==0);
    h.memory[a]=0x5a;
    CHECK(agr_bionic_mmap2(&c,a,4096,AGR_PROT_READ,AGR_MAP_FIXED|AGR_MAP_PRIVATE,-1,0,&fixed,&ge)==-1&&ge==EBADF);
    CHECK(h.memory[a]==0x5a&&agr_guest_vma_find(&v,a)->protection==(AGR_PROT_READ|AGR_PROT_WRITE));
    ge=123;CHECK(!agr_bionic_mprotect(&c,a,4096,AGR_PROT_READ,&ge));CHECK(ge==123);CHECK(agr_guest_vma_find(&v,a)->protection==AGR_PROT_READ);
    CHECK(h.page_protection[a/4096]==AGR_PROT_READ);
    CHECK(!agr_bionic_munmap(&c,a,4096,&ge));CHECK(!agr_guest_vma_find(&v,a));
    CHECK(h.page_protection[a/4096]==AGR_PROT_NONE);
    for(uint32_t i=0;i<100000;i++){CHECK(!agr_bionic_mmap2(&c,0,4096,AGR_PROT_READ|AGR_PROT_WRITE,AGR_MAP_PRIVATE|AGR_MAP_ANONYMOUS,-1,0,&a,&ge));CHECK(a==0x10000);CHECK(!agr_bionic_munmap(&c,a,4096,&ge));}
    agr_guest_vma_destroy(&v);return 0;
}

static int test_linker(void){
    uint8_t *elf=(uint8_t*)malloc(FIXTURE_SIZE);CHECK(elf);fixture(elf);harness h={0};h.file=elf;h.file_size=FIXTURE_SIZE;
    agr_guest_vma_space v;CHECK(!agr_guest_vma_init(&v,4096,0x10000,0x100000000ull));
    agr_bionic_mmap_context c={&v,&h,write_guest,file_view,protect_guest};agr_aosp_linker_image image={0};int32_t ge=0;
    CHECK(!agr_aosp_linker_map(&c,elf,FIXTURE_SIZE,0x20000,&image,&ge));
    CHECK(image.load_bias==0x20000&&image.load_start==0x21000&&image.load_size==0x5000);
    CHECK(!memcmp(h.memory+0x21000,elf+0x1000,0x1800));
    CHECK(!memcmp(h.memory+0x22800,elf+0x2800,0x500));
    for(uint32_t i=0x22d00;i<0x25100;i++)CHECK(h.memory[i]==0);
    CHECK(!agr_aosp_linker_finalize(&c,elf,FIXTURE_SIZE,&image,&ge));
    CHECK(agr_guest_vma_find(&v,0x21000)->protection==(AGR_PROT_READ|AGR_PROT_EXEC));
    CHECK(agr_guest_vma_find(&v,0x23000)->protection==AGR_PROT_READ);
    CHECK(agr_guest_vma_find(&v,0x24000)->protection==(AGR_PROT_READ|AGR_PROT_WRITE));
    CHECK(h.page_protection[0x21000/4096]==(AGR_PROT_READ|AGR_PROT_EXEC));
    CHECK(h.page_protection[0x23000/4096]==AGR_PROT_READ);
    CHECK(h.page_protection[0x24000/4096]==(AGR_PROT_READ|AGR_PROT_WRITE));
    uint32_t original=image.load_start;CHECK(!agr_aosp_linker_unload(&c,&image,&ge));CHECK(v.count==0);
    CHECK(h.page_protection[original/4096]==AGR_PROT_NONE);
    CHECK(!agr_aosp_linker_map(&c,elf,FIXTURE_SIZE,0x20000,&image,&ge));CHECK(image.load_start==original);CHECK(!agr_aosp_linker_unload(&c,&image,&ge));
    Elf32_Phdr*p=(Elf32_Phdr*)(elf+sizeof(Elf32_Ehdr));p[1].p_offset=0x2801;
    CHECK(agr_aosp_linker_map(&c,elf,FIXTURE_SIZE,0x20000,&image,&ge)==-1&&ge==ENOEXEC);
    agr_guest_vma_destroy(&v);free(elf);return 0;
}

static int test_formal_image_lifecycle(void){
    uint8_t *elf=(uint8_t*)malloc(FIXTURE_SIZE);CHECK(elf);dynamic_fixture(elf);
    harness *h=(harness*)calloc(1,sizeof(*h));CHECK(h);
    agr_callbacks cb={0};cb.user=h;cb.read=read_guest;cb.write=write_guest;cb.loader_write=write_guest;cb.protect=protect_guest;
    agr_runtime *runtime=agr_runtime_create(&cb,0x60000,0x70000,0x70000,0x90000);CHECK(runtime);
    Elf32_Ehdr *header=(Elf32_Ehdr*)elf;
    Elf32_Phdr *phdr=(Elf32_Phdr*)(elf+header->e_phoff);
    phdr[3].p_offset=FIXTURE_SIZE+1;
    agr_load_result invalid={0};
    CHECK(agr_load_elf(runtime,"invalid.so",elf,FIXTURE_SIZE,0x20000,&invalid)!=0);
    CHECK(h->page_protection[0x21000/4096]==AGR_PROT_NONE);
    phdr[3].p_offset=0x2900;
    for(uint32_t i=0;i<1000;i++){
        agr_load_result loaded={0};
        CHECK(agr_load_elf(runtime,"fixture.so",elf,FIXTURE_SIZE,0x20000,&loaded)==0);
        CHECK(loaded.object_handle==0x20000);
        CHECK(agr_find_symbol(runtime,"fixture_entry")==0x21100);
        uint32_t self=agr_dlopen(runtime,NULL);
        CHECK(self&&self!=loaded.object_handle);
        CHECK(agr_dlsym(runtime,self,"fixture_entry")==0x21100);
        CHECK(agr_dlclose(runtime,self)==0);
        CHECK(agr_find_symbol(runtime,"fixture_entry")==0x21100);
        uint32_t named=agr_dlopen(runtime,"fixture.so");
        CHECK(named==loaded.object_handle);
        CHECK(agr_dlclose(runtime,named)==0);
        CHECK(agr_find_symbol(runtime,"fixture_entry")==0x21100);
        CHECK(h->page_protection[0x23000/4096]==AGR_PROT_READ);
        CHECK(agr_dlclose(runtime,loaded.object_handle)==0);
        CHECK(agr_find_symbol(runtime,"fixture_entry")==0);
        CHECK(h->page_protection[0x21000/4096]==AGR_PROT_NONE);
    }
    agr_load_result first={0},second={0};
    CHECK(!agr_load_elf(runtime,"first.so",elf,FIXTURE_SIZE,0x20000,&first));
    CHECK(!agr_load_elf(runtime,"second.so",elf,FIXTURE_SIZE,0x30000,&second));
    CHECK(first.object_handle!=second.object_handle);
    CHECK(agr_find_symbol(runtime,"fixture_entry")==second.object_handle+0x1100);
    CHECK(!agr_dlclose(runtime,first.object_handle));
    CHECK(agr_find_symbol(runtime,"fixture_entry")==second.object_handle+0x1100);
    CHECK(!agr_dlclose(runtime,second.object_handle));
    CHECK(!agr_find_symbol(runtime,"fixture_entry"));
    agr_runtime_destroy(runtime);free(h);free(elf);return 0;
}

int main(void){CHECK(!test_bionic_contracts());CHECK(!test_linker());CHECK(!test_formal_image_lifecycle());puts("PASS API19 mmap/__mmap2 and AOSP linker segment contracts/stress/formal unload");return 0;}
