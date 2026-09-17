use crate::{Cpu, CpuError, CpuState, Mem};
use crate::mem::{GuestMem, Ptr};
use std::ffi::c_void;

struct Handle {
    cpu: Box<Cpu>,
    mem: Mem,
}

#[no_mangle]
pub extern "C" fn arm_interp_create() -> *mut c_void {
    let handle = Handle { cpu: Cpu::new(1), mem: Mem::new() };
    Box::into_raw(Box::new(handle)).cast()
}

#[no_mangle]
pub unsafe extern "C" fn arm_interp_destroy(ptr: *mut c_void) {
    if !ptr.is_null() { drop(Box::from_raw(ptr.cast::<Handle>())); }
}

#[no_mangle]
pub unsafe extern "C" fn arm_interp_write(ptr: *mut c_void, addr: u32,
                                            data: *const u8, len: u32) -> i32 {
    if ptr.is_null() || data.is_null() { return -1; }
    let h = &mut *ptr.cast::<Handle>();
    let Some(destination) = h.mem.get_bytes_fallible_mut(Ptr::from_bits(addr), len) else {
        return -1;
    };
    destination.copy_from_slice(std::slice::from_raw_parts(data, len as usize));
    0
}

#[no_mangle]
pub unsafe extern "C" fn arm_interp_load(ptr: *mut c_void, addr: u32,
                                           data: *const u8, len: u32) -> i32 {
    if ptr.is_null() || data.is_null() { return -1; }
    let h = &mut *ptr.cast::<Handle>();
    h.mem.write_bytes(addr, std::slice::from_raw_parts(data, len as usize));
    0
}

#[no_mangle]
pub unsafe extern "C" fn arm_interp_read(ptr: *mut c_void, addr: u32,
                                           data: *mut u8, len: u32) -> i32 {
    if ptr.is_null() || data.is_null() { return -1; }
    let h = &mut *ptr.cast::<Handle>();
    let Some(bytes) = h.mem.get_bytes_fallible(Ptr::from_bits(addr), len) else {
        return -1;
    };
    std::ptr::copy_nonoverlapping(bytes.as_ptr(), data, len as usize);
    0
}

#[no_mangle]
pub unsafe extern "C" fn arm_interp_set_reg(ptr: *mut c_void, reg: u32, value: u32) -> i32 {
    if ptr.is_null() || reg >= 16 { return -1; }
    (*ptr.cast::<Handle>()).cpu.regs_mut()[reg as usize] = value;
    0
}

#[no_mangle]
pub unsafe extern "C" fn arm_interp_get_reg(ptr: *mut c_void, reg: u32) -> u32 {
    if ptr.is_null() || reg >= 16 { return 0; }
    (*ptr.cast::<Handle>()).cpu.regs()[reg as usize]
}

#[no_mangle]
pub unsafe extern "C" fn arm_interp_set_page_permissions(ptr: *mut c_void,
    addr: u32, len: u32, protection: u32) -> i32 {
    if ptr.is_null() || protection & !7 != 0 { return -1; }
    if (*ptr.cast::<Handle>()).mem.set_page_permissions(addr, len, protection as u8) { 0 } else { -1 }
}

#[no_mangle]
pub unsafe extern "C" fn arm_interp_set_watch_pc(ptr: *mut c_void, pc: u32) {
    if !ptr.is_null() { (*ptr.cast::<Handle>()).cpu.set_watch_pc(pc); }
}

#[no_mangle]
pub unsafe extern "C" fn arm_interp_watch_hits(ptr: *mut c_void) -> u32 {
    if ptr.is_null() { 0 } else { (*ptr.cast::<Handle>()).cpu.watch_hits() }
}

#[no_mangle]
pub unsafe extern "C" fn arm_interp_watch_reg(ptr: *mut c_void, reg: u32) -> u32 {
    if ptr.is_null() { 0 } else { (*ptr.cast::<Handle>()).cpu.watch_reg(reg as usize) }
}

#[no_mangle]
pub unsafe extern "C" fn arm_interp_watch_cpsr(ptr: *mut c_void) -> u32 {
    if ptr.is_null() { 0 } else { (*ptr.cast::<Handle>()).cpu.watch_cpsr() }
}

#[no_mangle]
pub unsafe extern "C" fn arm_interp_set_thread_tag(ptr: *mut c_void, thread_tag: u32) {
    if !ptr.is_null() { (*ptr.cast::<Handle>()).cpu.set_thread_tag(thread_tag); }
}

#[no_mangle]
pub unsafe extern "C" fn arm_interp_watch_thread_tag(ptr: *mut c_void) -> u32 {
    if ptr.is_null() { 0 } else { (*ptr.cast::<Handle>()).cpu.watch_thread_tag() }
}

#[no_mangle]
pub unsafe extern "C" fn arm_interp_watch_trace(ptr: *mut c_void, index: u32,
                                                   pc: *mut u32, insn: *mut u32) -> i32 {
    if ptr.is_null() || pc.is_null() || insn.is_null() || index >= 64 { return -1; }
    let entry = (*ptr.cast::<Handle>()).cpu.watch_trace_entry(index as usize);
    *pc = entry.0;
    *insn = entry.1;
    0
}

#[no_mangle]
pub unsafe extern "C" fn arm_interp_set_cpsr(ptr: *mut c_void, value: u32) -> i32 {
    if ptr.is_null() { return -1; }
    (*ptr.cast::<Handle>()).cpu.set_cpsr(value);
    0
}

#[no_mangle]
pub unsafe extern "C" fn arm_interp_get_cpsr(ptr: *mut c_void) -> u32 {
    if ptr.is_null() { return 0; }
    (*ptr.cast::<Handle>()).cpu.cpsr()
}

#[no_mangle]
pub unsafe extern "C" fn arm_interp_run(ptr: *mut c_void, budget: *mut u64,
                                         svc_out: *mut u32) -> i32 {
    if ptr.is_null() || budget.is_null() || svc_out.is_null() { return -1; }
    let h = &mut *ptr.cast::<Handle>();
    match h.cpu.run_or_step(&mut h.mem, Some(&mut *budget)) {
        CpuState::Normal => 0,
        CpuState::Svc(n) => { *svc_out = n; 1 },
        CpuState::Error(CpuError::MemoryError) => -2,
        CpuState::Error(CpuError::UndefinedInstruction) => -3,
        CpuState::Error(CpuError::Breakpoint) => -4,
    }
}

#[cfg(test)]
mod permission_tests {
    use super::*;

    #[test]
    fn guest_read_write_execute_and_unmap_fault() {
        let mut mem = Mem::new();
        // LDR r0,[r1]; STR r0,[r2]. Host load bypasses guest protection.
        mem.write_bytes(0x1000, &[0x00,0x00,0x91,0xe5,0x00,0x00,0x82,0xe5]);
        mem.write_bytes(0x2000, &42u32.to_le_bytes());
        let mut cpu = Cpu::new(1);
        cpu.regs_mut()[15] = 0x1000;
        cpu.regs_mut()[1] = 0x2000;
        cpu.regs_mut()[2] = 0x3000;
        assert!(mem.set_page_permissions(0x1000, 0x1000, 1));
        assert!(matches!(cpu.run_or_step(&mut mem, None), CpuState::Error(CpuError::MemoryError)));
        assert!(mem.set_page_permissions(0x1000, 0x1000, 5));
        assert!(mem.set_page_permissions(0x2000, 0x1000, 0));
        assert!(matches!(cpu.run_or_step(&mut mem, None), CpuState::Error(CpuError::MemoryError)));
        cpu.regs_mut()[15] = 0x1000;
        assert!(mem.set_page_permissions(0x2000, 0x1000, 1));
        assert!(matches!(cpu.run_or_step(&mut mem, None), CpuState::Normal));
        assert_eq!(cpu.regs()[0], 42);
        assert!(mem.set_page_permissions(0x3000, 0x1000, 1));
        assert!(matches!(cpu.run_or_step(&mut mem, None), CpuState::Error(CpuError::MemoryError)));
        cpu.regs_mut()[15] = 0x1004;
        assert!(mem.set_page_permissions(0x3000, 0x1000, 3));
        assert!(matches!(cpu.run_or_step(&mut mem, None), CpuState::Normal));
        assert_eq!(mem.get_bytes_fallible(Ptr::from_bits(0x3000), 4).unwrap(), &42u32.to_le_bytes());
        assert!(mem.set_page_permissions(0x1000, 0x3000, 0));
        assert!(matches!(cpu.run_or_step(&mut mem, None), CpuState::Error(CpuError::MemoryError)));
    }

    #[test]
    fn ffi_reports_guest_permission_fault() {
        unsafe {
            let handle = arm_interp_create();
            assert!(!handle.is_null());
            let code = [0x00, 0x00, 0xa0, 0xe3]; // MOV r0, #0
            assert_eq!(arm_interp_write(handle, 0x1000, code.as_ptr(), 4), 0);
            assert_eq!(arm_interp_set_reg(handle, 15, 0x1000), 0);
            assert_eq!(arm_interp_set_page_permissions(handle, 0x1000, 4096, 1), 0);
            assert_eq!(arm_interp_write(handle, 0x1000, code.as_ptr(), 4), -1);
            assert_eq!(arm_interp_load(handle, 0x1000, code.as_ptr(), 4), 0);
            let mut budget = 1;
            let mut svc = 0;
            assert_eq!(arm_interp_run(handle, &mut budget, &mut svc), -2);
            arm_interp_destroy(handle);
        }
    }
}
