/*
 * Copyright (C) 2008, 2009 The Android Open Source Project
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *  * Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *  * Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES ARE DISCLAIMED.
 */

/*
 * HOST-NATIVE AOSP source port from Android 4.4.4_r2 bionic linker/linker.cpp
 * (commit 081db840befec895fb86e709ae95832ade2d065c) and linker/dlfcn.cpp.
 * The retained policy functions are named after their AOSP originals below.
 * Direct mapped pointers are replaced by explicit 32-bit guest reads/writes;
 * load_library maps through the already ported KitKat ElfReader path.
 */
#include "agr_aosp_dynamic.h"

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <vector>

#ifndef PT_ARM_EXIDX
#define PT_ARM_EXIDX 0x70000001
#endif

enum { FLAG_LINKED = 1, FLAG_EXE = 4, AGR_SELF_HANDLE = 0xfffffffeu };

struct Source {
  std::string name;
  std::vector<unsigned char> bytes;
  uint32_t preferred_bias;
};

struct soinfo {
  std::string name;
  Source* source;
  agr_aosp_linker_image image;
  std::vector<Elf32_Phdr> phdr;
  std::vector<Elf32_Dyn> dynamic;
  std::vector<soinfo*> needed;
  uint32_t flags, ref_count;
  uint32_t base, size, load_bias;
  uint32_t strtab_vaddr, symtab_vaddr, hash_vaddr;
  uint32_t nbucket, nchain;
  uint32_t plt_rel_vaddr, plt_rel_count, rel_vaddr, rel_count;
  uint32_t init_func, fini_func, init_array, init_array_count;
  uint32_t fini_array, fini_array_count, preinit_array, preinit_array_count;
  uint32_t exidx, exidx_count;
  bool constructors_called, has_text_relocations, has_DT_SYMBOLIC, host;
  soinfo():source(NULL),flags(0),ref_count(0),base(0),size(0),load_bias(0),
    strtab_vaddr(0),symtab_vaddr(0),hash_vaddr(0),nbucket(0),nchain(0),
    plt_rel_vaddr(0),plt_rel_count(0),rel_vaddr(0),rel_count(0),init_func(0),
    fini_func(0),init_array(0),init_array_count(0),fini_array(0),
    fini_array_count(0),preinit_array(0),preinit_array_count(0),exidx(0),
    exidx_count(0),constructors_called(false),has_text_relocations(false),
    has_DT_SYMBOLIC(false),host(false) { memset(&image,0,sizeof(image)); }
};

struct SymbolRecord { std::string name; uint32_t address; soinfo* owner; };
struct NeededRecord { std::string name; soinfo* owner; };
struct RelocRecord { uint32_t type,address; std::string symbol,object_name; soinfo* owner; };
struct FunctionRecord { uint32_t address; soinfo* owner; };

struct agr_aosp_dynamic {
  agr_bionic_mmap_context* mmap;
  agr_aosp_dynamic_callbacks cb;
  std::vector<Source*> sources;
  std::vector<soinfo*> solist;
  std::vector<SymbolRecord> symbols;
  std::vector<NeededRecord> needed_log;
  std::vector<RelocRecord> relocations;
  std::vector<FunctionRecord> constructors, finalizers;
  soinfo* somain;
  char linker_error[768], dlerror_buffer[1024];
  bool dlerror_pending;
  agr_aosp_dynamic():mmap(NULL),somain(NULL),dlerror_pending(false) {
    memset(&cb,0,sizeof(cb)); linker_error[0]=dlerror_buffer[0]=0;
  }
};

static const char* basename_of(const char* name) {
  const char* slash=name?strrchr(name,'/'):NULL; return slash?slash+1:name;
}
static void set_error(agr_aosp_dynamic* rt,const char* format,const char* a,const char* b) {
  snprintf(rt->linker_error,sizeof(rt->linker_error),format,a?a:"",b?b:"");
}
static void set_dlerror(agr_aosp_dynamic* rt,const char* message,const char* detail) {
  if(detail&&detail[0])snprintf(rt->dlerror_buffer,sizeof(rt->dlerror_buffer),"%s: %s",message,detail);
  else snprintf(rt->dlerror_buffer,sizeof(rt->dlerror_buffer),"%s",message);
  rt->dlerror_pending=true;
}
static bool source_range(Source* src,uint32_t off,uint32_t size,const void** out) {
  if(!src||off>src->bytes.size()||size>src->bytes.size()-off)return false;
  *out=&src->bytes[off];return true;
}
static bool source_vaddr(soinfo* si,uint32_t vaddr,uint32_t size,const void** out) {
  for(size_t i=0;i<si->phdr.size();++i){const Elf32_Phdr&p=si->phdr[i];
    if(p.p_type==PT_LOAD&&vaddr>=p.p_vaddr&&vaddr-p.p_vaddr<=p.p_filesz&&size<=p.p_filesz-(vaddr-p.p_vaddr))
      return source_range(si->source,p.p_offset+(vaddr-p.p_vaddr),size,out);
  }return false;
}
static bool read_guest(agr_aosp_dynamic*rt,uint32_t a,void*p,uint32_t n){return rt->cb.read_guest&&rt->cb.read_guest(rt->cb.opaque,a,p,n)==0;}
static bool write_guest(agr_aosp_dynamic*rt,uint32_t a,const void*p,uint32_t n){return rt->cb.write_loader&&rt->cb.write_loader(rt->cb.opaque,a,p,n)==0;}
static bool read_word(agr_aosp_dynamic*rt,uint32_t a,uint32_t*out){return read_guest(rt,a,out,4);}
static bool write_word(agr_aosp_dynamic*rt,uint32_t a,uint32_t v){return write_guest(rt,a,&v,4);}
static Source* find_source(agr_aosp_dynamic*rt,const char*name){const char*b=basename_of(name);for(size_t i=0;i<rt->sources.size();++i)if(rt->sources[i]->name==b)return rt->sources[i];return NULL;}
static soinfo* find_loaded_library(agr_aosp_dynamic*rt,const char*name){const char*b=basename_of(name);for(size_t i=0;i<rt->solist.size();++i)if(rt->solist[i]->name==b)return rt->solist[i];return NULL;}
static bool is_host_library(const char* n){
  static const char*const names[]={"libc.so","libm.so","libdl.so","liblog.so","libstdc++.so","libz.so","libGLESv1_CM.so","libGLESv2.so","libEGL.so","libandroid.so",NULL};
  const char*b=basename_of(n);for(size_t i=0;names[i];++i)if(!strcmp(b,names[i]))return true;return false;
}

/* AOSP linker.cpp: elfhash, unchanged. */
static unsigned elfhash(const char* _name) {
  const unsigned char* name=(const unsigned char*)_name;unsigned h=0,g;
  while(*name){h=(h<<4)+*name++;g=h&0xf0000000;h^=g;h^=g>>24;}return h;
}

static bool symbol_at(soinfo*si,uint32_t index,Elf32_Sym*out){const void*p=NULL;if(index>=si->nchain||!source_vaddr(si,si->symtab_vaddr+index*sizeof(*out),sizeof(*out),&p))return false;memcpy(out,p,sizeof(*out));return true;}
static const char* string_at(soinfo*si,uint32_t offset){const void*p=NULL;return source_vaddr(si,si->strtab_vaddr+offset,1,&p)?(const char*)p:NULL;}

/* AOSP linker.cpp: soinfo_elf_lookup. SYSV hash chain policy is retained. */
static bool soinfo_elf_lookup(agr_aosp_dynamic*rt,soinfo*si,unsigned hash,const char*name,uint32_t symbol_type,Elf32_Sym*out,uint32_t*out_addr){
  if(si->host){uint32_t a=rt->cb.resolve_import?rt->cb.resolve_import(rt->cb.opaque,name,symbol_type):0;if(!a)return false;memset(out,0,sizeof(*out));out->st_info=(STB_GLOBAL<<4);out->st_shndx=1;out->st_value=a;*out_addr=a;return true;}
  const void*hp=NULL;if(!si->nbucket||!source_vaddr(si,si->hash_vaddr,8+(si->nbucket+si->nchain)*4,&hp))return false;
  const uint32_t*h=(const uint32_t*)hp;const uint32_t*bucket=h+2,*chain=bucket+si->nbucket;
  for(uint32_t n=bucket[hash%si->nbucket];n!=0&&n<si->nchain;n=chain[n]){Elf32_Sym s;if(!symbol_at(si,n,&s))return false;const char*sn=string_at(si,s.st_name);if(!sn||strcmp(sn,name))continue;
    switch(ELF32_ST_BIND(s.st_info)){case STB_GLOBAL:case STB_WEAK:if(s.st_shndx==SHN_UNDEF)continue;*out=s;*out_addr=si->load_bias+s.st_value;return true;}
  }return false;
}

/* AOSP linker.cpp: soinfo_do_lookup, with gLdPreloads absent by declared scope. */
static bool soinfo_do_lookup(agr_aosp_dynamic*rt,soinfo*si,const char*name,uint32_t symbol_type,soinfo**lsi,Elf32_Sym*out,uint32_t*out_addr){
  unsigned hash=elfhash(name);
  if(si&&rt->somain){
    if(si==rt->somain){if(soinfo_elf_lookup(rt,si,hash,name,symbol_type,out,out_addr)){*lsi=si;return true;}}
    else {
      if(!si->has_DT_SYMBOLIC&&soinfo_elf_lookup(rt,rt->somain,hash,name,symbol_type,out,out_addr)){*lsi=rt->somain;return true;}
      if(soinfo_elf_lookup(rt,si,hash,name,symbol_type,out,out_addr)){*lsi=si;return true;}
      if(si->has_DT_SYMBOLIC&&soinfo_elf_lookup(rt,rt->somain,hash,name,symbol_type,out,out_addr)){*lsi=rt->somain;return true;}
    }
  }
  if(si)for(size_t i=0;i<si->needed.size();++i)if(soinfo_elf_lookup(rt,si->needed[i],hash,name,symbol_type,out,out_addr)){*lsi=si->needed[i];return true;}
  return false;
}

static bool parse_headers(agr_aosp_dynamic*rt,soinfo*si){
  const void*p=NULL;if(!source_range(si->source,0,sizeof(Elf32_Ehdr),&p)){set_error(rt,"invalid ELF header in %s",si->name.c_str(),NULL);return false;}
  Elf32_Ehdr eh;memcpy(&eh,p,sizeof(eh));if(memcmp(eh.e_ident,ELFMAG,SELFMAG)||eh.e_ident[EI_CLASS]!=ELFCLASS32||eh.e_machine!=EM_ARM||eh.e_phentsize!=sizeof(Elf32_Phdr)){set_error(rt,"not an ARM32 ELF: %s",si->name.c_str(),NULL);return false;}
  if(!source_range(si->source,eh.e_phoff,eh.e_phnum*sizeof(Elf32_Phdr),&p)){set_error(rt,"invalid program headers in %s",si->name.c_str(),NULL);return false;}
  const Elf32_Phdr*ph=(const Elf32_Phdr*)p;si->phdr.assign(ph,ph+eh.e_phnum);
  for(size_t i=0;i<si->phdr.size();++i){const Elf32_Phdr&q=si->phdr[i];if(q.p_type==PT_DYNAMIC){if(!source_range(si->source,q.p_offset,q.p_filesz,&p)){set_error(rt,"invalid PT_DYNAMIC in %s",si->name.c_str(),NULL);return false;}const Elf32_Dyn*d=(const Elf32_Dyn*)p;for(uint32_t j=0;j<q.p_filesz/sizeof(*d);++j){si->dynamic.push_back(d[j]);if(d[j].d_tag==DT_NULL)break;}}
    else if(q.p_type==PT_ARM_EXIDX){si->exidx=si->load_bias+q.p_vaddr;si->exidx_count=q.p_memsz/8;}}
  if(si->dynamic.empty()||si->dynamic.back().d_tag!=DT_NULL){set_error(rt,"missing PT_DYNAMIC in %s",si->name.c_str(),NULL);return false;}return true;
}

static soinfo* find_library(agr_aosp_dynamic*,const char*);
static int soinfo_unload(agr_aosp_dynamic*,soinfo*);
static void erase_records(agr_aosp_dynamic*,soinfo*);

/* AOSP linker.cpp: soinfo_relocate, ARM branch. Guest memory replaces casts. */
static int soinfo_relocate(agr_aosp_dynamic*rt,soinfo*si,uint32_t rel_vaddr,uint32_t count){
  for(uint32_t idx=0;idx<count;++idx){const void*p=NULL;Elf32_Rel rel;if(!source_vaddr(si,rel_vaddr+idx*sizeof(rel),sizeof(rel),&p)){set_error(rt,"invalid relocation table in %s",si->name.c_str(),NULL);return -1;}memcpy(&rel,p,sizeof(rel));
    uint32_t type=ELF32_R_TYPE(rel.r_info),sym=ELF32_R_SYM(rel.r_info),where=rel.r_offset+si->load_bias,sym_addr=0;Elf32_Sym local,s;soinfo*lsi=NULL;const char*sym_name="";
    if(type==R_ARM_NONE)continue;
    if(sym!=0){if(!symbol_at(si,sym,&local)){set_error(rt,"invalid symbol index in %s",si->name.c_str(),NULL);return -1;}sym_name=string_at(si,local.st_name);if(!sym_name){set_error(rt,"invalid symbol name in %s",si->name.c_str(),NULL);return -1;}
      if(!soinfo_do_lookup(rt,si,sym_name,ELF32_ST_TYPE(local.st_info),&lsi,&s,&sym_addr)){
        if(ELF32_ST_BIND(local.st_info)!=STB_WEAK){set_error(rt,"cannot locate symbol %s referenced by %s",sym_name,si->name.c_str());return -1;}
        switch(type){case R_ARM_JUMP_SLOT:case R_ARM_GLOB_DAT:case R_ARM_ABS32:case R_ARM_RELATIVE:sym_addr=0;break;default:set_error(rt,"unknown weak relocation in %s",si->name.c_str(),NULL);return -1;}
      }
      (void)lsi;(void)s;
    }
    uint32_t value=0;if(!read_word(rt,where,&value)){set_error(rt,"relocation read failed in %s",si->name.c_str(),NULL);return -1;}
    switch(type){
      case R_ARM_JUMP_SLOT:case R_ARM_GLOB_DAT:value=sym_addr;break;
      case R_ARM_ABS32:value+=sym_addr;break;
      case R_ARM_REL32:value+=sym_addr-rel.r_offset;break; /* exact KitKat formula */
      case R_ARM_RELATIVE:if(sym){set_error(rt,"odd RELATIVE form in %s",si->name.c_str(),NULL);return -1;}value+=si->base;break;
      case R_ARM_COPY:set_error(rt,"%s R_ARM_COPY relocations only supported for ET_EXEC",si->name.c_str(),NULL);return -1;
      default:set_error(rt,"unknown ARM relocation in %s",si->name.c_str(),NULL);return -1;
    }
    if(!write_word(rt,where,value)){set_error(rt,"relocation write failed in %s",si->name.c_str(),NULL);return -1;}
    RelocRecord rr;rr.type=type;rr.address=where;rr.symbol=sym_name?sym_name:"";rr.object_name=si->name;rr.owner=si;rt->relocations.push_back(rr);
  }return 0;
}

static bool CallFunction(agr_aosp_dynamic*rt,soinfo*si,uint32_t function,bool fini){if(!function||function==0xffffffffu)return true;if(rt->cb.invoke_guest_function&&rt->cb.invoke_guest_function(rt->cb.opaque,function)!=0){set_error(rt,"guest function failed in %s",si->name.c_str(),NULL);return false;}FunctionRecord record={function,si};(fini?rt->finalizers:rt->constructors).push_back(record);return true;}
static bool CallArray(agr_aosp_dynamic*rt,soinfo*si,uint32_t array,uint32_t count,bool reverse,bool fini){if(!array)return true;for(int i=reverse?(int)count-1:0;i!=(reverse?-1:(int)count);i+=reverse?-1:1){uint32_t fn=0;if(!read_word(rt,array+(uint32_t)i*4,&fn)){set_error(rt,"constructor/finalizer array read failed in %s",si->name.c_str(),NULL);return false;}if(!CallFunction(rt,si,fn,fini))return false;}return true;}

/* AOSP soinfo::CallConstructors/CallDestructors, preserving recursion/order. */
static bool CallConstructors(agr_aosp_dynamic*rt,soinfo*si){if(si->constructors_called)return true;si->constructors_called=true;for(size_t i=0;i<si->needed.size();++i)if(!CallConstructors(rt,si->needed[i]))return false;if(!CallFunction(rt,si,si->init_func,false))return false;return CallArray(rt,si,si->init_array,si->init_array_count,false,false);}
static bool CallDestructors(agr_aosp_dynamic*rt,soinfo*si){if(!CallArray(rt,si,si->fini_array,si->fini_array_count,true,true))return false;return CallFunction(rt,si,si->fini_func,true);}

/* AOSP linker.cpp: soinfo_link_image dynamic loop, dependencies, relocations. */
static bool soinfo_link_image(agr_aosp_dynamic*rt,soinfo*si){
  uint32_t needed_count=0;
  for(size_t i=0;i<si->dynamic.size();++i){Elf32_Dyn d=si->dynamic[i];switch(d.d_tag){
    case DT_HASH:si->hash_vaddr=d.d_un.d_ptr;{const void*p=NULL;if(!source_vaddr(si,si->hash_vaddr,8,&p))return false;const uint32_t*h=(const uint32_t*)p;si->nbucket=h[0];si->nchain=h[1];}break;
    case DT_STRTAB:si->strtab_vaddr=d.d_un.d_ptr;break;case DT_SYMTAB:si->symtab_vaddr=d.d_un.d_ptr;break;
    case DT_PLTREL:if(d.d_un.d_val!=DT_REL){set_error(rt,"unsupported DT_RELA in %s",si->name.c_str(),NULL);return false;}break;
    case DT_JMPREL:si->plt_rel_vaddr=d.d_un.d_ptr;break;case DT_PLTRELSZ:si->plt_rel_count=d.d_un.d_val/sizeof(Elf32_Rel);break;
    case DT_REL:si->rel_vaddr=d.d_un.d_ptr;break;case DT_RELSZ:si->rel_count=d.d_un.d_val/sizeof(Elf32_Rel);break;
    case DT_RELA:set_error(rt,"unsupported DT_RELA in %s",si->name.c_str(),NULL);return false;
    case DT_INIT:si->init_func=si->load_bias+d.d_un.d_ptr;break;case DT_FINI:si->fini_func=si->load_bias+d.d_un.d_ptr;break;
    case DT_INIT_ARRAY:si->init_array=si->load_bias+d.d_un.d_ptr;break;case DT_INIT_ARRAYSZ:si->init_array_count=d.d_un.d_val/4;break;
    case DT_FINI_ARRAY:si->fini_array=si->load_bias+d.d_un.d_ptr;break;case DT_FINI_ARRAYSZ:si->fini_array_count=d.d_un.d_val/4;break;
    case DT_PREINIT_ARRAY:si->preinit_array=si->load_bias+d.d_un.d_ptr;break;case DT_PREINIT_ARRAYSZ:si->preinit_array_count=d.d_un.d_val/4;break;
    case DT_TEXTREL:si->has_text_relocations=true;break;case DT_SYMBOLIC:si->has_DT_SYMBOLIC=true;break;case DT_NEEDED:++needed_count;break;default:break;}}
  if(!si->nbucket){set_error(rt,"empty/missing DT_HASH in %s",si->name.c_str(),NULL);return false;}if(!si->strtab_vaddr||!si->symtab_vaddr){set_error(rt,"missing dynamic tables in %s",si->name.c_str(),NULL);return false;}
  si->needed.reserve(needed_count);
  for(size_t i=0;i<si->dynamic.size();++i)if(si->dynamic[i].d_tag==DT_NEEDED){const char*name=string_at(si,si->dynamic[i].d_un.d_val);if(!name){set_error(rt,"invalid DT_NEEDED in %s",si->name.c_str(),NULL);return false;}NeededRecord nr;nr.name=name;nr.owner=si;rt->needed_log.push_back(nr);soinfo*dep=find_library(rt,name);if(!dep){set_error(rt,"could not load library %s needed by %s",name,si->name.c_str());return false;}si->needed.push_back(dep);}
  if(si->plt_rel_vaddr&&soinfo_relocate(rt,si,si->plt_rel_vaddr,si->plt_rel_count))return false;
  if(si->rel_vaddr&&soinfo_relocate(rt,si,si->rel_vaddr,si->rel_count))return false;
  si->flags|=FLAG_LINKED;int32_t ge=0;if(agr_aosp_linker_finalize(rt->mmap,&si->source->bytes[0],(uint32_t)si->source->bytes.size(),&si->image,&ge)){snprintf(rt->linker_error,sizeof(rt->linker_error),"AOSP linker protection/RELRO failed: errno %d",ge);return false;}
  return true;
}

/* AOSP load_library/find_library with file open replaced by registered bytes. */
static soinfo* load_library(agr_aosp_dynamic*rt,const char*name){
  Source*src=find_source(rt,name);if(!src){if(is_host_library(name)){soinfo*si=new soinfo;si->name=basename_of(name);si->host=true;si->flags=FLAG_LINKED;rt->solist.push_back(si);return si;}set_error(rt,"library %s not found",name,NULL);return NULL;}
  soinfo*si=new soinfo;si->name=basename_of(name);si->source=src;int32_t ge=0;if(agr_aosp_linker_map(rt->mmap,&src->bytes[0],(uint32_t)src->bytes.size(),src->preferred_bias,&si->image,&ge)){snprintf(rt->linker_error,sizeof(rt->linker_error),"AOSP segment map failed for %s: errno %d",name,ge);delete si;return NULL;}
  si->base=si->image.load_start;si->size=si->image.load_size;si->load_bias=si->image.load_bias;rt->solist.push_back(si);bool became_main=false;if(!rt->somain){rt->somain=si;became_main=true;}
  if(!parse_headers(rt,si)||!soinfo_link_image(rt,si)){std::vector<soinfo*>deps=si->needed;if(became_main)rt->somain=NULL;agr_aosp_linker_unload(rt->mmap,&si->image,NULL);erase_records(rt,si);rt->solist.pop_back();delete si;for(size_t i=0;i<deps.size();++i)soinfo_unload(rt,deps[i]);return NULL;}return si;
}
static soinfo* find_library_internal(agr_aosp_dynamic*rt,const char*name){if(!name)return rt->somain;soinfo*si=find_loaded_library(rt,name);if(si){if(si->flags&FLAG_LINKED)return si;set_error(rt,"recursive link to %s",si->name.c_str(),NULL);return NULL;}return load_library(rt,name);}
static soinfo* find_library(agr_aosp_dynamic*rt,const char*name){soinfo*si=find_library_internal(rt,name);if(si)si->ref_count++;return si;}

static void erase_records(agr_aosp_dynamic*rt,soinfo*si){
  for(size_t i=0;i<rt->symbols.size();)if(rt->symbols[i].owner==si)rt->symbols.erase(rt->symbols.begin()+i);else ++i;
  for(size_t i=0;i<rt->needed_log.size();)if(rt->needed_log[i].owner==si)rt->needed_log.erase(rt->needed_log.begin()+i);else ++i;
  for(size_t i=0;i<rt->relocations.size();)if(rt->relocations[i].owner==si)rt->relocations.erase(rt->relocations.begin()+i);else ++i;
  for(size_t i=0;i<rt->constructors.size();)if(rt->constructors[i].owner==si)rt->constructors.erase(rt->constructors.begin()+i);else ++i;
  for(size_t i=0;i<rt->finalizers.size();)if(rt->finalizers[i].owner==si)rt->finalizers.erase(rt->finalizers.begin()+i);else ++i;
}
/* AOSP soinfo_unload. Dependencies are released after finalizers, then image. */
static int soinfo_unload(agr_aosp_dynamic*rt,soinfo*si){if(!si)return -1;if(si->host){if(si->ref_count)si->ref_count--;return 0;}if(si->ref_count==1){if(!CallDestructors(rt,si))return -1;std::vector<soinfo*>deps=si->needed;agr_aosp_linker_unload(rt->mmap,&si->image,NULL);erase_records(rt,si);for(size_t i=0;i<rt->solist.size();++i)if(rt->solist[i]==si){rt->solist.erase(rt->solist.begin()+i);break;}if(rt->somain==si)rt->somain=NULL;delete si;for(size_t i=0;i<deps.size();++i)if(soinfo_unload(rt,deps[i]))return -1;}else if(si->ref_count>1)si->ref_count--;return 0;}

static void rebuild_symbols(agr_aosp_dynamic*rt,soinfo*si){if(si->host)return;for(size_t j=0;j<rt->symbols.size();++j)if(rt->symbols[j].owner==si)return;for(uint32_t i=1;i<si->nchain;++i){Elf32_Sym s;if(!symbol_at(si,i,&s)||s.st_shndx==SHN_UNDEF)continue;uint32_t bind=ELF32_ST_BIND(s.st_info);if(bind!=STB_GLOBAL&&bind!=STB_WEAK)continue;const char*n=string_at(si,s.st_name);if(!n)continue;SymbolRecord r;r.name=n;r.address=si->load_bias+s.st_value;r.owner=si;rt->symbols.push_back(r);}}

extern "C" agr_aosp_dynamic* agr_aosp_dynamic_create(agr_bionic_mmap_context*m,const agr_aosp_dynamic_callbacks*c){if(!m||!c||!c->read_guest||!c->write_loader)return NULL;agr_aosp_dynamic*rt=new agr_aosp_dynamic;rt->mmap=m;rt->cb=*c;return rt;}
extern "C" void agr_aosp_dynamic_destroy(agr_aosp_dynamic*rt){if(!rt)return;while(!rt->solist.empty()){soinfo*si=rt->solist.back();if(!si->host&&si->image.load_size)agr_aosp_linker_unload(rt->mmap,&si->image,NULL);delete si;rt->solist.pop_back();}for(size_t i=0;i<rt->sources.size();++i)delete rt->sources[i];delete rt;}
extern "C" int32_t agr_aosp_dynamic_register(agr_aosp_dynamic*rt,const char*name,const void*bytes,uint32_t size,uint32_t bias){if(!rt||!name||!bytes||!size)return -1;Source*s=find_source(rt,name);if(!s){s=new Source;s->name=basename_of(name);rt->sources.push_back(s);}s->bytes.assign((const unsigned char*)bytes,(const unsigned char*)bytes+size);s->preferred_bias=bias;return 0;}
extern "C" int32_t agr_aosp_dynamic_load(agr_aosp_dynamic*rt,const char*name,const void*bytes,uint32_t size,uint32_t bias,agr_aosp_dynamic_load_result*out){if(agr_aosp_dynamic_register(rt,name,bytes,size,bias))return -1;uint32_t ns=rt->needed_log.size(),rs=rt->relocations.size(),cs=rt->constructors.size(),ss=rt->symbols.size();soinfo*si=find_library(rt,name);if(!si){set_dlerror(rt,"dlopen failed",rt->linker_error);return -1;}rebuild_symbols(rt,si);if(!CallConstructors(rt,si)){set_dlerror(rt,"dlopen failed",rt->linker_error);return -1;}if(out){out->object_handle=si->load_bias;out->needed_start=ns;out->needed_count=(uint32_t)rt->needed_log.size()-ns;out->relocation_start=rs;out->relocation_count=(uint32_t)rt->relocations.size()-rs;out->constructor_start=cs;out->constructor_count=(uint32_t)rt->constructors.size()-cs;out->symbol_start=ss;out->symbol_count=(uint32_t)rt->symbols.size()-ss;}rt->linker_error[0]=0;rt->dlerror_pending=false;return 0;}

extern "C" uint32_t agr_aosp_dynamic_find_symbol(agr_aosp_dynamic*rt,const char*name){if(!rt||!name)return 0;for(size_t i=0;i<rt->solist.size();++i){Elf32_Sym s;uint32_t a=0;if(soinfo_elf_lookup(rt,rt->solist[i],elfhash(name),name,STT_NOTYPE,&s,&a))return a;}return 0;}
extern "C" uint32_t agr_aosp_dynamic_dlopen(agr_aosp_dynamic*rt,const char*name,int flags){if(!rt)return 0;if(flags&~0x103){set_dlerror(rt,"dlopen failed","invalid flags");return 0;}if(!name)return rt->somain?AGR_SELF_HANDLE:0;soinfo*si=find_library(rt,name);if(!si){set_dlerror(rt,"dlopen failed",rt->linker_error);return 0;}if(!si->host){rebuild_symbols(rt,si);if(!CallConstructors(rt,si)){set_dlerror(rt,"dlopen failed",rt->linker_error);return 0;}}rt->dlerror_pending=false;return si->load_bias;}
extern "C" uint32_t agr_aosp_dynamic_dlsym(agr_aosp_dynamic*rt,uint32_t handle,const char*name){if(!rt||!name){if(rt)set_dlerror(rt,"dlsym failed","symbol name is null");return 0;}if(handle==0){set_dlerror(rt,"dlsym failed","library handle is null");return 0;}Elf32_Sym s;uint32_t a=0;if(handle==AGR_SELF_HANDLE||handle==0xffffffffu){for(size_t i=0;i<rt->solist.size();++i)if(soinfo_elf_lookup(rt,rt->solist[i],elfhash(name),name,STT_NOTYPE,&s,&a)){rt->dlerror_pending=false;return ELF32_ST_BIND(s.st_info)==STB_GLOBAL?a:0;}}
  else {for(size_t i=0;i<rt->solist.size();++i)if(rt->solist[i]->load_bias==handle&&soinfo_elf_lookup(rt,rt->solist[i],elfhash(name),name,STT_NOTYPE,&s,&a)){if(ELF32_ST_BIND(s.st_info)==STB_GLOBAL){rt->dlerror_pending=false;return a;}set_dlerror(rt,"dlsym failed","symbol found but not global");return 0;}}
  set_dlerror(rt,"dlsym failed","undefined symbol");return 0;}
extern "C" int32_t agr_aosp_dynamic_dlclose(agr_aosp_dynamic*rt,uint32_t handle){if(!rt)return -1;if(handle==AGR_SELF_HANDLE){rt->dlerror_pending=false;return 0;}for(size_t i=0;i<rt->solist.size();++i)if(rt->solist[i]->load_bias==handle){int r=soinfo_unload(rt,rt->solist[i]);if(r)set_dlerror(rt,"dlclose failed",rt->linker_error);else rt->dlerror_pending=false;return r;}set_dlerror(rt,"dlclose failed","invalid library handle");return -1;}
extern "C" const char* agr_aosp_dynamic_dlerror(agr_aosp_dynamic*rt){if(!rt||!rt->dlerror_pending)return NULL;rt->dlerror_pending=false;return rt->dlerror_buffer;}
extern "C" int32_t agr_aosp_dynamic_dladdr(agr_aosp_dynamic*rt,uint32_t address,char*object_name,uint32_t object_name_size,uint32_t*object_base,char*symbol_name,uint32_t symbol_name_size,uint32_t*symbol_address){
  if(!rt)return 0;soinfo*found=NULL;for(size_t i=0;i<rt->solist.size();++i){soinfo*si=rt->solist[i];if(!si->host&&address>=si->image.load_start&&address<si->image.load_start+si->image.load_size){found=si;break;}}if(!found)return 0;
  if(object_name&&object_name_size)snprintf(object_name,object_name_size,"%s",found->name.c_str());if(object_base)*object_base=found->base;uint32_t best=0;const char*best_name=NULL;
  for(uint32_t i=1;i<found->nchain;++i){Elf32_Sym s;if(!symbol_at(found,i,&s)||s.st_shndx==SHN_UNDEF)continue;uint32_t a=found->load_bias+s.st_value;if(a<=address&&a>=best){best=a;best_name=string_at(found,s.st_name);}}
  if(symbol_name&&symbol_name_size)snprintf(symbol_name,symbol_name_size,"%s",best_name?best_name:"");if(symbol_address)*symbol_address=best;return 1;
}

extern "C" uint32_t agr_aosp_dynamic_symbol_count(const agr_aosp_dynamic*rt){return rt?(uint32_t)rt->symbols.size():0;}
extern "C" const char* agr_aosp_dynamic_symbol_name(const agr_aosp_dynamic*rt,uint32_t i){return rt&&i<rt->symbols.size()?rt->symbols[i].name.c_str():NULL;}
extern "C" uint32_t agr_aosp_dynamic_symbol_address(const agr_aosp_dynamic*rt,uint32_t i){return rt&&i<rt->symbols.size()?rt->symbols[i].address:0;}
extern "C" uint32_t agr_aosp_dynamic_needed_count(const agr_aosp_dynamic*rt){return rt?(uint32_t)rt->needed_log.size():0;}
extern "C" const char* agr_aosp_dynamic_needed_name(const agr_aosp_dynamic*rt,uint32_t i){return rt&&i<rt->needed_log.size()?rt->needed_log[i].name.c_str():NULL;}
extern "C" uint32_t agr_aosp_dynamic_constructor_count(const agr_aosp_dynamic*rt){return rt?(uint32_t)rt->constructors.size():0;}
extern "C" uint32_t agr_aosp_dynamic_constructor_address(const agr_aosp_dynamic*rt,uint32_t i){return rt&&i<rt->constructors.size()?rt->constructors[i].address:0;}
extern "C" uint32_t agr_aosp_dynamic_finalizer_count(const agr_aosp_dynamic*rt){return rt?(uint32_t)rt->finalizers.size():0;}
extern "C" uint32_t agr_aosp_dynamic_finalizer_address(const agr_aosp_dynamic*rt,uint32_t i){return rt&&i<rt->finalizers.size()?rt->finalizers[i].address:0;}
extern "C" uint32_t agr_aosp_dynamic_relocation_count(const agr_aosp_dynamic*rt){return rt?(uint32_t)rt->relocations.size():0;}
extern "C" int32_t agr_aosp_dynamic_relocation_at(const agr_aosp_dynamic*rt,uint32_t i,agr_aosp_dynamic_relocation*out){if(!rt||!out||i>=rt->relocations.size())return -1;const RelocRecord&r=rt->relocations[i];out->type=r.type;out->address=r.address;out->symbol=r.symbol.c_str();out->object_name=r.object_name.c_str();return 0;}
extern "C" uint32_t agr_aosp_dynamic_find_exidx(const agr_aosp_dynamic*rt,uint32_t pc,uint32_t*count){if(rt)for(size_t i=0;i<rt->solist.size();++i){soinfo*si=rt->solist[i];if(!si->host&&pc>=si->image.load_start&&pc<si->image.load_start+si->image.load_size){if(count)*count=si->exidx_count;return si->exidx;}}if(count)*count=0;return 0;}
