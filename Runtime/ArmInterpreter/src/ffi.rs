use crate::{Cpu, CpuError, CpuState, Mem};
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
    h.mem.write_bytes(addr, std::slice::from_raw_parts(data, len as usize));
    0
}

#[no_mangle]
pub unsafe extern "C" fn arm_interp_read(ptr: *mut c_void, addr: u32,
                                           data: *mut u8, len: u32) -> i32 {
    if ptr.is_null() || data.is_null() { return -1; }
    let h = &mut *ptr.cast::<Handle>();
    let bytes = h.mem.read_bytes_vec(addr, len as usize);
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
pub unsafe extern "C" fn arm_interp_set_watch_pc(ptr: *mut c_void, pc: u32) {
    if !ptr.is_null() { (*ptr.cast::<Handle>()).cpu.set_watch_pc(pc); }
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
