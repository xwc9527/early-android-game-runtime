.text
.p2align 2
.globl _agr_game_compiled_00000ce0
_agr_game_compiled_00000ce0:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #0
b.ne L_00000ce0_mode_miss
movz w12, #3296
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #57348
movk w12, #58783, lsl #16
cmp w14, w12
b.ne L_00000ce0_miss
movz w12, #3304
add w12, w15, w12
movz w13, #4
add w12, w12, w13
cmp w12, #0x1000
b.lo L_00000ce0_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w12, w13
b.hi L_00000ce0_fault
add x13, x11, w12, uxtw
ldr w12, [x13]
str w12, [x9, #56]
movz w12, #3300
add w12, w15, w12
str w12, [x9, #60]
L_00000ce0_success:
mov w0, #1
b L_00000ce0_return
L_00000ce0_fault:
mov w0, #-1
b L_00000ce0_return
L_00000ce0_miss:
mov w0, #3
b L_00000ce0_return
L_00000ce0_mode_miss:
mov w0, #4
L_00000ce0_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00000ce8
_agr_game_compiled_00000ce8:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #0
b.ne L_00000ce8_mode_miss
movz w12, #3304
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #61448
movk w12, #58814, lsl #16
cmp w14, w12
b.ne L_00000ce8_miss
ldr w12, [x9, #56]
movz w13, #8
add w12, w12, w13
str w12, [x9, #56]
cmp w12, #0x1000
b.lo L_00000ce8_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w12, w13
b.hi L_00000ce8_fault
add x13, x11, w12, uxtw
ldr w12, [x13]
ldr w13, [x10]
and w14, w12, #1
lsl w14, w14, #5
bic w13, w13, #0x20
orr w13, w13, w14
str w13, [x10]
bic w12, w12, #1
str w12, [x9, #60]
b L_00000ce8_success
L_00000ce8_success:
mov w0, #1
b L_00000ce8_return
L_00000ce8_fault:
mov w0, #-1
b L_00000ce8_return
L_00000ce8_miss:
mov w0, #3
b L_00000ce8_return
L_00000ce8_mode_miss:
mov w0, #4
L_00000ce8_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00000cfc
_agr_game_compiled_00000cfc:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #0
b.ne L_00000cfc_mode_miss
movz w12, #3324
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #50688
movk w12, #57999, lsl #16
cmp w14, w12
b.ne L_00000cfc_miss
movz w12, #3328
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #51714
movk w12, #57996, lsl #16
cmp w14, w12
b.ne L_00000cfc_miss
movz w12, #3332
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #62160
movk w12, #58812, lsl #16
cmp w14, w12
b.ne L_00000cfc_miss
movz w12, #3332
add w12, w15, w12
movz w13, #0
add w12, w12, w13
str w12, [x9, #48]
ldr w12, [x9, #48]
movz w13, #8192
add w12, w12, w13
str w12, [x9, #48]
ldr w12, [x9, #48]
movz w13, #720
add w12, w12, w13
str w12, [x9, #48]
cmp w12, #0x1000
b.lo L_00000cfc_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w12, w13
b.hi L_00000cfc_fault
add x13, x11, w12, uxtw
ldr w12, [x13]
ldr w13, [x10]
and w14, w12, #1
lsl w14, w14, #5
bic w13, w13, #0x20
orr w13, w13, w14
str w13, [x10]
bic w12, w12, #1
str w12, [x9, #60]
b L_00000cfc_success
L_00000cfc_success:
mov w0, #1
b L_00000cfc_return
L_00000cfc_fault:
mov w0, #-1
b L_00000cfc_return
L_00000cfc_miss:
mov w0, #3
b L_00000cfc_return
L_00000cfc_mode_miss:
mov w0, #4
L_00000cfc_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00000d08
_agr_game_compiled_00000d08:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #0
b.ne L_00000d08_mode_miss
movz w12, #3336
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #50688
movk w12, #57999, lsl #16
cmp w14, w12
b.ne L_00000d08_miss
movz w12, #3340
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #51714
movk w12, #57996, lsl #16
cmp w14, w12
b.ne L_00000d08_miss
movz w12, #3344
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #62152
movk w12, #58812, lsl #16
cmp w14, w12
b.ne L_00000d08_miss
movz w12, #3344
add w12, w15, w12
movz w13, #0
add w12, w12, w13
str w12, [x9, #48]
ldr w12, [x9, #48]
movz w13, #8192
add w12, w12, w13
str w12, [x9, #48]
ldr w12, [x9, #48]
movz w13, #712
add w12, w12, w13
str w12, [x9, #48]
cmp w12, #0x1000
b.lo L_00000d08_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w12, w13
b.hi L_00000d08_fault
add x13, x11, w12, uxtw
ldr w12, [x13]
ldr w13, [x10]
and w14, w12, #1
lsl w14, w14, #5
bic w13, w13, #0x20
orr w13, w13, w14
str w13, [x10]
bic w12, w12, #1
str w12, [x9, #60]
b L_00000d08_success
L_00000d08_success:
mov w0, #1
b L_00000d08_return
L_00000d08_fault:
mov w0, #-1
b L_00000d08_return
L_00000d08_miss:
mov w0, #3
b L_00000d08_return
L_00000d08_mode_miss:
mov w0, #4
L_00000d08_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00000d14
_agr_game_compiled_00000d14:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #0
b.ne L_00000d14_mode_miss
movz w12, #3348
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #50688
movk w12, #57999, lsl #16
cmp w14, w12
b.ne L_00000d14_miss
movz w12, #3352
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #51714
movk w12, #57996, lsl #16
cmp w14, w12
b.ne L_00000d14_miss
movz w12, #3356
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #62144
movk w12, #58812, lsl #16
cmp w14, w12
b.ne L_00000d14_miss
movz w12, #3356
add w12, w15, w12
movz w13, #0
add w12, w12, w13
str w12, [x9, #48]
ldr w12, [x9, #48]
movz w13, #8192
add w12, w12, w13
str w12, [x9, #48]
ldr w12, [x9, #48]
movz w13, #704
add w12, w12, w13
str w12, [x9, #48]
cmp w12, #0x1000
b.lo L_00000d14_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w12, w13
b.hi L_00000d14_fault
add x13, x11, w12, uxtw
ldr w12, [x13]
ldr w13, [x10]
and w14, w12, #1
lsl w14, w14, #5
bic w13, w13, #0x20
orr w13, w13, w14
str w13, [x10]
bic w12, w12, #1
str w12, [x9, #60]
b L_00000d14_success
L_00000d14_success:
mov w0, #1
b L_00000d14_return
L_00000d14_fault:
mov w0, #-1
b L_00000d14_return
L_00000d14_miss:
mov w0, #3
b L_00000d14_return
L_00000d14_mode_miss:
mov w0, #4
L_00000d14_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00000d20
_agr_game_compiled_00000d20:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #0
b.ne L_00000d20_mode_miss
movz w12, #3360
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #50688
movk w12, #57999, lsl #16
cmp w14, w12
b.ne L_00000d20_miss
movz w12, #3364
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #51714
movk w12, #57996, lsl #16
cmp w14, w12
b.ne L_00000d20_miss
movz w12, #3368
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #62136
movk w12, #58812, lsl #16
cmp w14, w12
b.ne L_00000d20_miss
movz w12, #3368
add w12, w15, w12
movz w13, #0
add w12, w12, w13
str w12, [x9, #48]
ldr w12, [x9, #48]
movz w13, #8192
add w12, w12, w13
str w12, [x9, #48]
ldr w12, [x9, #48]
movz w13, #696
add w12, w12, w13
str w12, [x9, #48]
cmp w12, #0x1000
b.lo L_00000d20_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w12, w13
b.hi L_00000d20_fault
add x13, x11, w12, uxtw
ldr w12, [x13]
ldr w13, [x10]
and w14, w12, #1
lsl w14, w14, #5
bic w13, w13, #0x20
orr w13, w13, w14
str w13, [x10]
bic w12, w12, #1
str w12, [x9, #60]
b L_00000d20_success
L_00000d20_success:
mov w0, #1
b L_00000d20_return
L_00000d20_fault:
mov w0, #-1
b L_00000d20_return
L_00000d20_miss:
mov w0, #3
b L_00000d20_return
L_00000d20_mode_miss:
mov w0, #4
L_00000d20_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00000d2c
_agr_game_compiled_00000d2c:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #0
b.ne L_00000d2c_mode_miss
movz w12, #3372
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #50688
movk w12, #57999, lsl #16
cmp w14, w12
b.ne L_00000d2c_miss
movz w12, #3376
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #51714
movk w12, #57996, lsl #16
cmp w14, w12
b.ne L_00000d2c_miss
movz w12, #3380
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #62128
movk w12, #58812, lsl #16
cmp w14, w12
b.ne L_00000d2c_miss
movz w12, #3380
add w12, w15, w12
movz w13, #0
add w12, w12, w13
str w12, [x9, #48]
ldr w12, [x9, #48]
movz w13, #8192
add w12, w12, w13
str w12, [x9, #48]
ldr w12, [x9, #48]
movz w13, #688
add w12, w12, w13
str w12, [x9, #48]
cmp w12, #0x1000
b.lo L_00000d2c_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w12, w13
b.hi L_00000d2c_fault
add x13, x11, w12, uxtw
ldr w12, [x13]
ldr w13, [x10]
and w14, w12, #1
lsl w14, w14, #5
bic w13, w13, #0x20
orr w13, w13, w14
str w13, [x10]
bic w12, w12, #1
str w12, [x9, #60]
b L_00000d2c_success
L_00000d2c_success:
mov w0, #1
b L_00000d2c_return
L_00000d2c_fault:
mov w0, #-1
b L_00000d2c_return
L_00000d2c_miss:
mov w0, #3
b L_00000d2c_return
L_00000d2c_mode_miss:
mov w0, #4
L_00000d2c_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00000d38
_agr_game_compiled_00000d38:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #0
b.ne L_00000d38_mode_miss
movz w12, #3384
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #50688
movk w12, #57999, lsl #16
cmp w14, w12
b.ne L_00000d38_miss
movz w12, #3388
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #51714
movk w12, #57996, lsl #16
cmp w14, w12
b.ne L_00000d38_miss
movz w12, #3392
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #62120
movk w12, #58812, lsl #16
cmp w14, w12
b.ne L_00000d38_miss
movz w12, #3392
add w12, w15, w12
movz w13, #0
add w12, w12, w13
str w12, [x9, #48]
ldr w12, [x9, #48]
movz w13, #8192
add w12, w12, w13
str w12, [x9, #48]
ldr w12, [x9, #48]
movz w13, #680
add w12, w12, w13
str w12, [x9, #48]
cmp w12, #0x1000
b.lo L_00000d38_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w12, w13
b.hi L_00000d38_fault
add x13, x11, w12, uxtw
ldr w12, [x13]
ldr w13, [x10]
and w14, w12, #1
lsl w14, w14, #5
bic w13, w13, #0x20
orr w13, w13, w14
str w13, [x10]
bic w12, w12, #1
str w12, [x9, #60]
b L_00000d38_success
L_00000d38_success:
mov w0, #1
b L_00000d38_return
L_00000d38_fault:
mov w0, #-1
b L_00000d38_return
L_00000d38_miss:
mov w0, #3
b L_00000d38_return
L_00000d38_mode_miss:
mov w0, #4
L_00000d38_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00000d44
_agr_game_compiled_00000d44:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #0
b.ne L_00000d44_mode_miss
movz w12, #3396
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #50688
movk w12, #57999, lsl #16
cmp w14, w12
b.ne L_00000d44_miss
movz w12, #3400
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #51714
movk w12, #57996, lsl #16
cmp w14, w12
b.ne L_00000d44_miss
movz w12, #3404
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #62112
movk w12, #58812, lsl #16
cmp w14, w12
b.ne L_00000d44_miss
movz w12, #3404
add w12, w15, w12
movz w13, #0
add w12, w12, w13
str w12, [x9, #48]
ldr w12, [x9, #48]
movz w13, #8192
add w12, w12, w13
str w12, [x9, #48]
ldr w12, [x9, #48]
movz w13, #672
add w12, w12, w13
str w12, [x9, #48]
cmp w12, #0x1000
b.lo L_00000d44_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w12, w13
b.hi L_00000d44_fault
add x13, x11, w12, uxtw
ldr w12, [x13]
ldr w13, [x10]
and w14, w12, #1
lsl w14, w14, #5
bic w13, w13, #0x20
orr w13, w13, w14
str w13, [x10]
bic w12, w12, #1
str w12, [x9, #60]
b L_00000d44_success
L_00000d44_success:
mov w0, #1
b L_00000d44_return
L_00000d44_fault:
mov w0, #-1
b L_00000d44_return
L_00000d44_miss:
mov w0, #3
b L_00000d44_return
L_00000d44_mode_miss:
mov w0, #4
L_00000d44_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00000d50
_agr_game_compiled_00000d50:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #0
b.ne L_00000d50_mode_miss
movz w12, #3408
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #50688
movk w12, #57999, lsl #16
cmp w14, w12
b.ne L_00000d50_miss
movz w12, #3412
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #51714
movk w12, #57996, lsl #16
cmp w14, w12
b.ne L_00000d50_miss
movz w12, #3416
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #62104
movk w12, #58812, lsl #16
cmp w14, w12
b.ne L_00000d50_miss
movz w12, #3416
add w12, w15, w12
movz w13, #0
add w12, w12, w13
str w12, [x9, #48]
ldr w12, [x9, #48]
movz w13, #8192
add w12, w12, w13
str w12, [x9, #48]
ldr w12, [x9, #48]
movz w13, #664
add w12, w12, w13
str w12, [x9, #48]
cmp w12, #0x1000
b.lo L_00000d50_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w12, w13
b.hi L_00000d50_fault
add x13, x11, w12, uxtw
ldr w12, [x13]
ldr w13, [x10]
and w14, w12, #1
lsl w14, w14, #5
bic w13, w13, #0x20
orr w13, w13, w14
str w13, [x10]
bic w12, w12, #1
str w12, [x9, #60]
b L_00000d50_success
L_00000d50_success:
mov w0, #1
b L_00000d50_return
L_00000d50_fault:
mov w0, #-1
b L_00000d50_return
L_00000d50_miss:
mov w0, #3
b L_00000d50_return
L_00000d50_mode_miss:
mov w0, #4
L_00000d50_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00000d80
_agr_game_compiled_00000d80:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #0
b.ne L_00000d80_mode_miss
movz w12, #3456
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #4
movk w12, #58783, lsl #16
cmp w14, w12
b.ne L_00000d80_miss
movz w12, #3464
add w12, w15, w12
movz w13, #4
add w12, w12, w13
cmp w12, #0x1000
b.lo L_00000d80_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w12, w13
b.hi L_00000d80_fault
add x13, x11, w12, uxtw
ldr w12, [x13]
str w12, [x9, #0]
movz w12, #3460
add w12, w15, w12
str w12, [x9, #60]
L_00000d80_success:
mov w0, #1
b L_00000d80_return
L_00000d80_fault:
mov w0, #-1
b L_00000d80_return
L_00000d80_miss:
mov w0, #3
b L_00000d80_return
L_00000d80_mode_miss:
mov w0, #4
L_00000d80_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00000dc4
_agr_game_compiled_00000dc4:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00000dc4_mode_miss
movz w12, #3524
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #59693
movk w12, #20472, lsl #16
cmp w14, w12
b.ne L_00000dc4_miss
movz w12, #3528
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #18074
cmp w14, w12
b.ne L_00000dc4_miss
movz w12, #3530
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #26627
cmp w14, w12
b.ne L_00000dc4_miss
movz w12, #3532
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #17937
cmp w14, w12
b.ne L_00000dc4_miss
movz w12, #3534
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #18064
cmp w14, w12
b.ne L_00000dc4_miss
movz w12, #3536
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #8704
cmp w14, w12
b.ne L_00000dc4_miss
movz w12, #3538
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #17924
cmp w14, w12
b.ne L_00000dc4_miss
movz w12, #3540
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #40458
cmp w14, w12
b.ne L_00000dc4_miss
movz w12, #3542
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #63699
movk w12, #13044, lsl #16
cmp w14, w12
b.ne L_00000dc4_miss
movz w12, #3546
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #18328
cmp w14, w12
b.ne L_00000dc4_miss
ldr w12, [x9, #52]
movz w13, #40
sub w12, w12, w13
cmp w12, #0x1000
b.lo L_00000dc4_fault
add x13, x11, w12, uxtw
ldr w14, [x9, #12]
str w14, [x13, #0]
ldr w14, [x9, #16]
str w14, [x13, #4]
ldr w14, [x9, #20]
str w14, [x13, #8]
ldr w14, [x9, #24]
str w14, [x13, #12]
ldr w14, [x9, #28]
str w14, [x13, #16]
ldr w14, [x9, #32]
str w14, [x13, #20]
ldr w14, [x9, #36]
str w14, [x13, #24]
ldr w14, [x9, #40]
str w14, [x13, #28]
ldr w14, [x9, #44]
str w14, [x13, #32]
ldr w14, [x9, #56]
str w14, [x13, #36]
str w12, [x9, #52]
ldr w12, [x9, #12]
str w12, [x9, #40]
ldr w12, [x9, #0]
movz w13, #0
add w12, w12, w13
cmp w12, #0x1000
b.lo L_00000dc4_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w12, w13
b.hi L_00000dc4_fault
add x13, x11, w12, uxtw
ldr w12, [x13]
str w12, [x9, #12]
ldr w12, [x9, #8]
str w12, [x9, #4]
ldr w12, [x9, #8]
str w12, [x9, #32]
movz w12, #0
str w12, [x9, #8]
cmp w12, #0
mrs x13, nzcv
ldr w14, [x10]
and w13, w13, #0xc0000000
and w14, w14, #0x3fffffff
orr w14, w14, w13
str w14, [x10]
ldr w12, [x9, #0]
str w12, [x9, #16]
ldr w12, [x9, #52]
movz w13, #40
add w12, w12, w13
cmp w12, #0x1000
b.lo L_00000dc4_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w12, w13
b.hi L_00000dc4_fault
add x13, x11, w12, uxtw
ldr w12, [x13]
str w12, [x9, #24]
ldr w12, [x9, #12]
movz w13, #756
add w12, w12, w13
cmp w12, #0x1000
b.lo L_00000dc4_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w12, w13
b.hi L_00000dc4_fault
add x13, x11, w12, uxtw
ldr w12, [x13]
str w12, [x9, #12]
ldr w12, [x9, #12]
movz w13, #3548
add w13, w15, w13
orr w13, w13, #1
str w13, [x9, #56]
ldr w13, [x10]
and w14, w12, #1
lsl w14, w14, #5
bic w13, w13, #0x20
orr w13, w13, w14
str w13, [x10]
bic w12, w12, #1
str w12, [x9, #60]
b L_00000dc4_success
L_00000dc4_success:
mov w0, #1
b L_00000dc4_return
L_00000dc4_fault:
mov w0, #-1
b L_00000dc4_return
L_00000dc4_miss:
mov w0, #3
b L_00000dc4_return
L_00000dc4_mode_miss:
mov w0, #4
L_00000dc4_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00000ddc
_agr_game_compiled_00000ddc:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00000ddc_mode_miss
movz w12, #3548
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #26659
cmp w14, w12
b.ne L_00000ddc_miss
movz w12, #3550
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #18001
cmp w14, w12
b.ne L_00000ddc_miss
movz w12, #3552
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #8704
cmp w14, w12
b.ne L_00000ddc_miss
movz w12, #3554
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #63699
movk w12, #13044, lsl #16
cmp w14, w12
b.ne L_00000ddc_miss
movz w12, #3558
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #17927
cmp w14, w12
b.ne L_00000ddc_miss
movz w12, #3560
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #17952
cmp w14, w12
b.ne L_00000ddc_miss
movz w12, #3562
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #18328
cmp w14, w12
b.ne L_00000ddc_miss
ldr w12, [x9, #16]
movz w13, #0
add w12, w12, w13
cmp w12, #0x1000
b.lo L_00000ddc_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w12, w13
b.hi L_00000ddc_fault
add x13, x11, w12, uxtw
ldr w12, [x13]
str w12, [x9, #12]
ldr w12, [x9, #40]
str w12, [x9, #4]
movz w12, #0
str w12, [x9, #8]
cmp w12, #0
mrs x13, nzcv
ldr w14, [x10]
and w13, w13, #0xc0000000
and w14, w14, #0x3fffffff
orr w14, w14, w13
str w14, [x10]
ldr w12, [x9, #12]
movz w13, #756
add w12, w12, w13
cmp w12, #0x1000
b.lo L_00000ddc_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w12, w13
b.hi L_00000ddc_fault
add x13, x11, w12, uxtw
ldr w12, [x13]
str w12, [x9, #12]
ldr w12, [x9, #0]
str w12, [x9, #28]
ldr w12, [x9, #16]
str w12, [x9, #0]
ldr w12, [x9, #12]
movz w13, #3564
add w13, w15, w13
orr w13, w13, #1
str w13, [x9, #56]
ldr w13, [x10]
and w14, w12, #1
lsl w14, w14, #5
bic w13, w13, #0x20
orr w13, w13, w14
str w13, [x10]
bic w12, w12, #1
str w12, [x9, #60]
b L_00000ddc_success
L_00000ddc_success:
mov w0, #1
b L_00000ddc_return
L_00000ddc_fault:
mov w0, #-1
b L_00000ddc_return
L_00000ddc_miss:
mov w0, #3
b L_00000ddc_return
L_00000ddc_mode_miss:
mov w0, #4
L_00000ddc_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00000dec
_agr_game_compiled_00000dec:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00000dec_mode_miss
movz w12, #3564
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #18049
cmp w14, w12
b.ne L_00000dec_miss
movz w12, #3566
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #45382
cmp w14, w12
b.ne L_00000dec_miss
ldr w12, [x9, #0]
str w12, [x9, #36]
ldr w12, [x9, #24]
cbz w12, L_00000dec_taken_1
movz w12, #3568
add w12, w15, w12
str w12, [x9, #60]
b L_00000dec_success
L_00000dec_taken_1:
movz w12, #3586
add w12, w15, w12
str w12, [x9, #60]
b L_00000dec_success
L_00000dec_success:
mov w0, #1
b L_00000dec_return
L_00000dec_fault:
mov w0, #-1
b L_00000dec_return
L_00000dec_miss:
mov w0, #3
b L_00000dec_return
L_00000dec_mode_miss:
mov w0, #4
L_00000dec_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00000df0
_agr_game_compiled_00000df0:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00000df0_mode_miss
movz w12, #3568
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #26659
cmp w14, w12
b.ne L_00000df0_miss
movz w12, #3570
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #17952
cmp w14, w12
b.ne L_00000df0_miss
movz w12, #3572
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #17969
cmp w14, w12
b.ne L_00000df0_miss
movz w12, #3574
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #8704
cmp w14, w12
b.ne L_00000df0_miss
movz w12, #3576
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #63699
movk w12, #13036, lsl #16
cmp w14, w12
b.ne L_00000df0_miss
movz w12, #3580
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #18328
cmp w14, w12
b.ne L_00000df0_miss
ldr w12, [x9, #16]
movz w13, #0
add w12, w12, w13
cmp w12, #0x1000
b.lo L_00000df0_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w12, w13
b.hi L_00000df0_fault
add x13, x11, w12, uxtw
ldr w12, [x13]
str w12, [x9, #12]
ldr w12, [x9, #16]
str w12, [x9, #0]
ldr w12, [x9, #24]
str w12, [x9, #4]
movz w12, #0
str w12, [x9, #8]
cmp w12, #0
mrs x13, nzcv
ldr w14, [x10]
and w13, w13, #0xc0000000
and w14, w14, #0x3fffffff
orr w14, w14, w13
str w14, [x10]
ldr w12, [x9, #12]
movz w13, #748
add w12, w12, w13
cmp w12, #0x1000
b.lo L_00000df0_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w12, w13
b.hi L_00000df0_fault
add x13, x11, w12, uxtw
ldr w12, [x13]
str w12, [x9, #12]
ldr w12, [x9, #12]
movz w13, #3582
add w13, w15, w13
orr w13, w13, #1
str w13, [x9, #56]
ldr w13, [x10]
and w14, w12, #1
lsl w14, w14, #5
bic w13, w13, #0x20
orr w13, w13, w14
str w13, [x10]
bic w12, w12, #1
str w12, [x9, #60]
b L_00000df0_success
L_00000df0_success:
mov w0, #1
b L_00000df0_return
L_00000df0_fault:
mov w0, #-1
b L_00000df0_return
L_00000df0_miss:
mov w0, #3
b L_00000df0_return
L_00000df0_mode_miss:
mov w0, #4
L_00000df0_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00000dfe
_agr_game_compiled_00000dfe:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00000dfe_mode_miss
movz w12, #3582
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #17925
cmp w14, w12
b.ne L_00000dfe_miss
movz w12, #3584
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #57344
cmp w14, w12
b.ne L_00000dfe_miss
ldr w12, [x9, #0]
str w12, [x9, #20]
movz w12, #3588
add w12, w15, w12
str w12, [x9, #60]
b L_00000dfe_success
L_00000dfe_success:
mov w0, #1
b L_00000dfe_return
L_00000dfe_fault:
mov w0, #-1
b L_00000dfe_return
L_00000dfe_miss:
mov w0, #3
b L_00000dfe_return
L_00000dfe_mode_miss:
mov w0, #4
L_00000dfe_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00000e02
_agr_game_compiled_00000e02:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00000e02_mode_miss
movz w12, #3586
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #17973
cmp w14, w12
b.ne L_00000e02_miss
ldr w12, [x9, #24]
str w12, [x9, #20]
movz w12, #3588
add w12, w15, w12
str w12, [x9, #60]
L_00000e02_success:
mov w0, #1
b L_00000e02_return
L_00000e02_fault:
mov w0, #-1
b L_00000e02_return
L_00000e02_miss:
mov w0, #3
b L_00000e02_return
L_00000e02_mode_miss:
mov w0, #4
L_00000e02_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00000e04
_agr_game_compiled_00000e04:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00000e04_mode_miss
movz w12, #3588
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #26659
cmp w14, w12
b.ne L_00000e04_miss
movz w12, #3590
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #8704
cmp w14, w12
b.ne L_00000e04_miss
movz w12, #3592
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #39179
cmp w14, w12
b.ne L_00000e04_miss
movz w12, #3594
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #17952
cmp w14, w12
b.ne L_00000e04_miss
movz w12, #3596
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #63699
movk w12, #13032, lsl #16
cmp w14, w12
b.ne L_00000e04_miss
movz w12, #3600
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #18328
cmp w14, w12
b.ne L_00000e04_miss
ldr w12, [x9, #16]
movz w13, #0
add w12, w12, w13
cmp w12, #0x1000
b.lo L_00000e04_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w12, w13
b.hi L_00000e04_fault
add x13, x11, w12, uxtw
ldr w12, [x13]
str w12, [x9, #12]
movz w12, #0
str w12, [x9, #8]
cmp w12, #0
mrs x13, nzcv
ldr w14, [x10]
and w13, w13, #0xc0000000
and w14, w14, #0x3fffffff
orr w14, w14, w13
str w14, [x10]
ldr w12, [x9, #52]
movz w13, #44
add w12, w12, w13
cmp w12, #0x1000
b.lo L_00000e04_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w12, w13
b.hi L_00000e04_fault
add x13, x11, w12, uxtw
ldr w12, [x13]
str w12, [x9, #4]
ldr w12, [x9, #16]
str w12, [x9, #0]
ldr w12, [x9, #12]
movz w13, #744
add w12, w12, w13
cmp w12, #0x1000
b.lo L_00000e04_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w12, w13
b.hi L_00000e04_fault
add x13, x11, w12, uxtw
ldr w12, [x13]
str w12, [x9, #12]
ldr w12, [x9, #12]
movz w13, #3602
add w13, w15, w13
orr w13, w13, #1
str w13, [x9, #56]
ldr w13, [x10]
and w14, w12, #1
lsl w14, w14, #5
bic w13, w13, #0x20
orr w13, w13, w14
str w13, [x10]
bic w12, w12, #1
str w12, [x9, #60]
b L_00000e04_success
L_00000e04_success:
mov w0, #1
b L_00000e04_return
L_00000e04_fault:
mov w0, #-1
b L_00000e04_return
L_00000e04_miss:
mov w0, #3
b L_00000e04_return
L_00000e04_mode_miss:
mov w0, #4
L_00000e04_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00000e12
_agr_game_compiled_00000e12:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00000e12_mode_miss
movz w12, #3602
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #62017
movk w12, #16646, lsl #16
cmp w14, w12
b.ne L_00000e12_miss
movz w12, #3606
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #8704
cmp w14, w12
b.ne L_00000e12_miss
movz w12, #3608
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #17979
cmp w14, w12
b.ne L_00000e12_miss
movz w12, #3610
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #18051
cmp w14, w12
b.ne L_00000e12_miss
movz w12, #3612
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #8195
cmp w14, w12
b.ne L_00000e12_miss
movz w12, #3614
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #63487
movk w12, #61300, lsl #16
cmp w14, w12
b.ne L_00000e12_miss
movz w12, #5126
str w12, [x9, #4]
movz w12, #0
str w12, [x9, #8]
cmp w12, #0
mrs x13, nzcv
ldr w14, [x10]
and w13, w13, #0xc0000000
and w14, w14, #0x3fffffff
orr w14, w14, w13
str w14, [x10]
ldr w12, [x9, #28]
str w12, [x9, #12]
ldr w12, [x9, #0]
str w12, [x9, #44]
movz w12, #3
str w12, [x9, #0]
cmp w12, #0
mrs x13, nzcv
ldr w14, [x10]
and w13, w13, #0xc0000000
and w14, w14, #0x3fffffff
orr w14, w14, w13
str w14, [x10]
movz w12, #3336
add w12, w15, w12
movz w13, #3618
add w13, w15, w13
orr w13, w13, #1
str w13, [x9, #56]
ldr w13, [x10]
and w14, w12, #1
lsl w14, w14, #5
bic w13, w13, #0x20
orr w13, w13, w14
str w13, [x10]
bic w12, w12, #1
str w12, [x9, #60]
b L_00000e12_success
L_00000e12_success:
mov w0, #1
b L_00000e12_return
L_00000e12_fault:
mov w0, #-1
b L_00000e12_return
L_00000e12_miss:
mov w0, #3
b L_00000e12_return
L_00000e12_mode_miss:
mov w0, #4
L_00000e12_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00000e22
_agr_game_compiled_00000e22:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00000e22_mode_miss
movz w12, #3618
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #8196
cmp w14, w12
b.ne L_00000e22_miss
movz w12, #3620
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #62017
movk w12, #16646, lsl #16
cmp w14, w12
b.ne L_00000e22_miss
movz w12, #3624
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #8704
cmp w14, w12
b.ne L_00000e22_miss
movz w12, #3626
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #17995
cmp w14, w12
b.ne L_00000e22_miss
movz w12, #3628
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #63487
movk w12, #61298, lsl #16
cmp w14, w12
b.ne L_00000e22_miss
movz w12, #4
str w12, [x9, #0]
cmp w12, #0
mrs x13, nzcv
ldr w14, [x10]
and w13, w13, #0xc0000000
and w14, w14, #0x3fffffff
orr w14, w14, w13
str w14, [x10]
movz w12, #5126
str w12, [x9, #4]
movz w12, #0
str w12, [x9, #8]
cmp w12, #0
mrs x13, nzcv
ldr w14, [x10]
and w13, w13, #0xc0000000
and w14, w14, #0x3fffffff
orr w14, w14, w13
str w14, [x10]
ldr w12, [x9, #36]
str w12, [x9, #12]
movz w12, #3348
add w12, w15, w12
movz w13, #3632
add w13, w15, w13
orr w13, w13, #1
str w13, [x9, #56]
ldr w13, [x10]
and w14, w12, #1
lsl w14, w14, #5
bic w13, w13, #0x20
orr w13, w13, w14
str w13, [x10]
bic w12, w12, #1
str w12, [x9, #60]
b L_00000e22_success
L_00000e22_success:
mov w0, #1
b L_00000e22_return
L_00000e22_fault:
mov w0, #-1
b L_00000e22_return
L_00000e22_miss:
mov w0, #3
b L_00000e22_return
L_00000e22_mode_miss:
mov w0, #4
L_00000e22_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00000e30
_agr_game_compiled_00000e30:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00000e30_mode_miss
movz w12, #3632
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #45365
cmp w14, w12
b.ne L_00000e30_miss
ldr w12, [x9, #20]
cbz w12, L_00000e30_taken_0
movz w12, #3634
add w12, w15, w12
str w12, [x9, #60]
b L_00000e30_success
L_00000e30_taken_0:
movz w12, #3648
add w12, w15, w12
str w12, [x9, #60]
b L_00000e30_success
L_00000e30_success:
mov w0, #1
b L_00000e30_return
L_00000e30_fault:
mov w0, #-1
b L_00000e30_return
L_00000e30_miss:
mov w0, #3
b L_00000e30_return
L_00000e30_mode_miss:
mov w0, #4
L_00000e30_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00000e32
_agr_game_compiled_00000e32:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00000e32_mode_miss
movz w12, #3634
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #8194
cmp w14, w12
b.ne L_00000e32_miss
movz w12, #3636
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #62017
movk w12, #16652, lsl #16
cmp w14, w12
b.ne L_00000e32_miss
movz w12, #3640
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #8704
cmp w14, w12
b.ne L_00000e32_miss
movz w12, #3642
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #17963
cmp w14, w12
b.ne L_00000e32_miss
movz w12, #3644
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #63487
movk w12, #61296, lsl #16
cmp w14, w12
b.ne L_00000e32_miss
movz w12, #2
str w12, [x9, #0]
cmp w12, #0
mrs x13, nzcv
ldr w14, [x10]
and w13, w13, #0xc0000000
and w14, w14, #0x3fffffff
orr w14, w14, w13
str w14, [x10]
movz w12, #5132
str w12, [x9, #4]
movz w12, #0
str w12, [x9, #8]
cmp w12, #0
mrs x13, nzcv
ldr w14, [x10]
and w13, w13, #0xc0000000
and w14, w14, #0x3fffffff
orr w14, w14, w13
str w14, [x10]
ldr w12, [x9, #20]
str w12, [x9, #12]
movz w12, #3360
add w12, w15, w12
movz w13, #3648
add w13, w15, w13
orr w13, w13, #1
str w13, [x9, #56]
ldr w13, [x10]
and w14, w12, #1
lsl w14, w14, #5
bic w13, w13, #0x20
orr w13, w13, w14
str w13, [x10]
bic w12, w12, #1
str w12, [x9, #60]
b L_00000e32_success
L_00000e32_success:
mov w0, #1
b L_00000e32_return
L_00000e32_fault:
mov w0, #-1
b L_00000e32_return
L_00000e32_miss:
mov w0, #3
b L_00000e32_return
L_00000e32_mode_miss:
mov w0, #4
L_00000e32_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00000e40
_agr_game_compiled_00000e40:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00000e40_mode_miss
movz w12, #3648
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #8196
cmp w14, w12
b.ne L_00000e40_miss
movz w12, #3650
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #39180
cmp w14, w12
b.ne L_00000e40_miss
movz w12, #3652
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #62017
movk w12, #16899, lsl #16
cmp w14, w12
b.ne L_00000e40_miss
movz w12, #3656
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #18011
cmp w14, w12
b.ne L_00000e40_miss
movz w12, #3658
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #63487
movk w12, #61296, lsl #16
cmp w14, w12
b.ne L_00000e40_miss
movz w12, #4
str w12, [x9, #0]
cmp w12, #0
mrs x13, nzcv
ldr w14, [x10]
and w13, w13, #0xc0000000
and w14, w14, #0x3fffffff
orr w14, w14, w13
str w14, [x10]
ldr w12, [x9, #52]
movz w13, #48
add w12, w12, w13
cmp w12, #0x1000
b.lo L_00000e40_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w12, w13
b.hi L_00000e40_fault
add x13, x11, w12, uxtw
ldr w12, [x13]
str w12, [x9, #4]
movz w12, #5123
str w12, [x9, #8]
ldr w12, [x9, #44]
str w12, [x9, #12]
movz w12, #3372
add w12, w15, w12
movz w13, #3662
add w13, w15, w13
orr w13, w13, #1
str w13, [x9, #56]
ldr w13, [x10]
and w14, w12, #1
lsl w14, w14, #5
bic w13, w13, #0x20
orr w13, w13, w14
str w13, [x10]
bic w12, w12, #1
str w12, [x9, #60]
b L_00000e40_success
L_00000e40_success:
mov w0, #1
b L_00000e40_return
L_00000e40_fault:
mov w0, #-1
b L_00000e40_return
L_00000e40_miss:
mov w0, #3
b L_00000e40_return
L_00000e40_mode_miss:
mov w0, #4
L_00000e40_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00000e4e
_agr_game_compiled_00000e4e:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00000e4e_mode_miss
movz w12, #3662
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #26659
cmp w14, w12
b.ne L_00000e4e_miss
movz w12, #3664
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #17952
cmp w14, w12
b.ne L_00000e4e_miss
movz w12, #3666
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #39179
cmp w14, w12
b.ne L_00000e4e_miss
movz w12, #3668
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #18010
cmp w14, w12
b.ne L_00000e4e_miss
movz w12, #3670
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #63699
movk w12, #49928, lsl #16
cmp w14, w12
b.ne L_00000e4e_miss
movz w12, #3674
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #8960
cmp w14, w12
b.ne L_00000e4e_miss
movz w12, #3676
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #18400
cmp w14, w12
b.ne L_00000e4e_miss
ldr w12, [x9, #16]
movz w13, #0
add w12, w12, w13
cmp w12, #0x1000
b.lo L_00000e4e_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w12, w13
b.hi L_00000e4e_fault
add x13, x11, w12, uxtw
ldr w12, [x13]
str w12, [x9, #12]
ldr w12, [x9, #16]
str w12, [x9, #0]
ldr w12, [x9, #52]
movz w13, #44
add w12, w12, w13
cmp w12, #0x1000
b.lo L_00000e4e_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w12, w13
b.hi L_00000e4e_fault
add x13, x11, w12, uxtw
ldr w12, [x13]
str w12, [x9, #4]
ldr w12, [x9, #44]
str w12, [x9, #8]
ldr w12, [x9, #12]
movz w13, #776
add w12, w12, w13
cmp w12, #0x1000
b.lo L_00000e4e_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w12, w13
b.hi L_00000e4e_fault
add x13, x11, w12, uxtw
ldr w12, [x13]
str w12, [x9, #48]
movz w12, #0
str w12, [x9, #12]
cmp w12, #0
mrs x13, nzcv
ldr w14, [x10]
and w13, w13, #0xc0000000
and w14, w14, #0x3fffffff
orr w14, w14, w13
str w14, [x10]
ldr w12, [x9, #48]
movz w13, #3678
add w13, w15, w13
orr w13, w13, #1
str w13, [x9, #56]
ldr w13, [x10]
and w14, w12, #1
lsl w14, w14, #5
bic w13, w13, #0x20
orr w13, w13, w14
str w13, [x10]
bic w12, w12, #1
str w12, [x9, #60]
b L_00000e4e_success
L_00000e4e_success:
mov w0, #1
b L_00000e4e_return
L_00000e4e_fault:
mov w0, #-1
b L_00000e4e_return
L_00000e4e_miss:
mov w0, #3
b L_00000e4e_return
L_00000e4e_mode_miss:
mov w0, #4
L_00000e4e_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00000e5e
_agr_game_compiled_00000e5e:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00000e5e_mode_miss
movz w12, #3678
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #45373
cmp w14, w12
b.ne L_00000e5e_miss
ldr w12, [x9, #20]
cbz w12, L_00000e5e_taken_0
movz w12, #3680
add w12, w15, w12
str w12, [x9, #60]
b L_00000e5e_success
L_00000e5e_taken_0:
movz w12, #3696
add w12, w15, w12
str w12, [x9, #60]
b L_00000e5e_success
L_00000e5e_success:
mov w0, #1
b L_00000e5e_return
L_00000e5e_fault:
mov w0, #-1
b L_00000e5e_return
L_00000e5e_miss:
mov w0, #3
b L_00000e5e_return
L_00000e5e_mode_miss:
mov w0, #4
L_00000e5e_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00000e60
_agr_game_compiled_00000e60:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00000e60_mode_miss
movz w12, #3680
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #26659
cmp w14, w12
b.ne L_00000e60_miss
movz w12, #3682
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #17952
cmp w14, w12
b.ne L_00000e60_miss
movz w12, #3684
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #17969
cmp w14, w12
b.ne L_00000e60_miss
movz w12, #3686
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #17962
cmp w14, w12
b.ne L_00000e60_miss
movz w12, #3688
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #63699
movk w12, #49932, lsl #16
cmp w14, w12
b.ne L_00000e60_miss
movz w12, #3692
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #8960
cmp w14, w12
b.ne L_00000e60_miss
movz w12, #3694
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #18400
cmp w14, w12
b.ne L_00000e60_miss
ldr w12, [x9, #16]
movz w13, #0
add w12, w12, w13
cmp w12, #0x1000
b.lo L_00000e60_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w12, w13
b.hi L_00000e60_fault
add x13, x11, w12, uxtw
ldr w12, [x13]
str w12, [x9, #12]
ldr w12, [x9, #16]
str w12, [x9, #0]
ldr w12, [x9, #24]
str w12, [x9, #4]
ldr w12, [x9, #20]
str w12, [x9, #8]
ldr w12, [x9, #12]
movz w13, #780
add w12, w12, w13
cmp w12, #0x1000
b.lo L_00000e60_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w12, w13
b.hi L_00000e60_fault
add x13, x11, w12, uxtw
ldr w12, [x13]
str w12, [x9, #48]
movz w12, #0
str w12, [x9, #12]
cmp w12, #0
mrs x13, nzcv
ldr w14, [x10]
and w13, w13, #0xc0000000
and w14, w14, #0x3fffffff
orr w14, w14, w13
str w14, [x10]
ldr w12, [x9, #48]
movz w13, #3696
add w13, w15, w13
orr w13, w13, #1
str w13, [x9, #56]
ldr w13, [x10]
and w14, w12, #1
lsl w14, w14, #5
bic w13, w13, #0x20
orr w13, w13, w14
str w13, [x10]
bic w12, w12, #1
str w12, [x9, #60]
b L_00000e60_success
L_00000e60_success:
mov w0, #1
b L_00000e60_return
L_00000e60_fault:
mov w0, #-1
b L_00000e60_return
L_00000e60_miss:
mov w0, #3
b L_00000e60_return
L_00000e60_mode_miss:
mov w0, #4
L_00000e60_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00000e70
_agr_game_compiled_00000e70:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00000e70_mode_miss
movz w12, #3696
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #26659
cmp w14, w12
b.ne L_00000e70_miss
movz w12, #3698
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #17952
cmp w14, w12
b.ne L_00000e70_miss
movz w12, #3700
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #18001
cmp w14, w12
b.ne L_00000e70_miss
movz w12, #3702
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #17994
cmp w14, w12
b.ne L_00000e70_miss
movz w12, #3704
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #63699
movk w12, #21268, lsl #16
cmp w14, w12
b.ne L_00000e70_miss
movz w12, #3708
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #8960
cmp w14, w12
b.ne L_00000e70_miss
movz w12, #3710
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #18344
cmp w14, w12
b.ne L_00000e70_miss
ldr w12, [x9, #16]
movz w13, #0
add w12, w12, w13
cmp w12, #0x1000
b.lo L_00000e70_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w12, w13
b.hi L_00000e70_fault
add x13, x11, w12, uxtw
ldr w12, [x13]
str w12, [x9, #12]
ldr w12, [x9, #16]
str w12, [x9, #0]
ldr w12, [x9, #40]
str w12, [x9, #4]
ldr w12, [x9, #36]
str w12, [x9, #8]
ldr w12, [x9, #12]
movz w13, #788
add w12, w12, w13
cmp w12, #0x1000
b.lo L_00000e70_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w12, w13
b.hi L_00000e70_fault
add x13, x11, w12, uxtw
ldr w12, [x13]
str w12, [x9, #20]
movz w12, #0
str w12, [x9, #12]
cmp w12, #0
mrs x13, nzcv
ldr w14, [x10]
and w13, w13, #0xc0000000
and w14, w14, #0x3fffffff
orr w14, w14, w13
str w14, [x10]
ldr w12, [x9, #20]
movz w13, #3712
add w13, w15, w13
orr w13, w13, #1
str w13, [x9, #56]
ldr w13, [x10]
and w14, w12, #1
lsl w14, w14, #5
bic w13, w13, #0x20
orr w13, w13, w14
str w13, [x10]
bic w12, w12, #1
str w12, [x9, #60]
b L_00000e70_success
L_00000e70_success:
mov w0, #1
b L_00000e70_return
L_00000e70_fault:
mov w0, #-1
b L_00000e70_return
L_00000e70_miss:
mov w0, #3
b L_00000e70_return
L_00000e70_mode_miss:
mov w0, #4
L_00000e70_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00000e80
_agr_game_compiled_00000e80:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00000e80_mode_miss
movz w12, #3712
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #26659
cmp w14, w12
b.ne L_00000e80_miss
movz w12, #3714
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #17952
cmp w14, w12
b.ne L_00000e80_miss
movz w12, #3716
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #17985
cmp w14, w12
b.ne L_00000e80_miss
movz w12, #3718
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #17978
cmp w14, w12
b.ne L_00000e80_miss
movz w12, #3720
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #63699
movk w12, #21268, lsl #16
cmp w14, w12
b.ne L_00000e80_miss
movz w12, #3724
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #8960
cmp w14, w12
b.ne L_00000e80_miss
movz w12, #3726
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #18344
cmp w14, w12
b.ne L_00000e80_miss
ldr w12, [x9, #16]
movz w13, #0
add w12, w12, w13
cmp w12, #0x1000
b.lo L_00000e80_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w12, w13
b.hi L_00000e80_fault
add x13, x11, w12, uxtw
ldr w12, [x13]
str w12, [x9, #12]
ldr w12, [x9, #16]
str w12, [x9, #0]
ldr w12, [x9, #32]
str w12, [x9, #4]
ldr w12, [x9, #28]
str w12, [x9, #8]
ldr w12, [x9, #12]
movz w13, #788
add w12, w12, w13
cmp w12, #0x1000
b.lo L_00000e80_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w12, w13
b.hi L_00000e80_fault
add x13, x11, w12, uxtw
ldr w12, [x13]
str w12, [x9, #20]
movz w12, #0
str w12, [x9, #12]
cmp w12, #0
mrs x13, nzcv
ldr w14, [x10]
and w13, w13, #0xc0000000
and w14, w14, #0x3fffffff
orr w14, w14, w13
str w14, [x10]
ldr w12, [x9, #20]
movz w13, #3728
add w13, w15, w13
orr w13, w13, #1
str w13, [x9, #56]
ldr w13, [x10]
and w14, w12, #1
lsl w14, w14, #5
bic w13, w13, #0x20
orr w13, w13, w14
str w13, [x10]
bic w12, w12, #1
str w12, [x9, #60]
b L_00000e80_success
L_00000e80_success:
mov w0, #1
b L_00000e80_return
L_00000e80_fault:
mov w0, #-1
b L_00000e80_return
L_00000e80_miss:
mov w0, #3
b L_00000e80_return
L_00000e80_mode_miss:
mov w0, #4
L_00000e80_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00000e90
_agr_game_compiled_00000e90:
sub sp, sp, #64
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00000e90_mode_miss
movz w12, #3728
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #59581
movk w12, #36856, lsl #16
cmp w14, w12
b.ne L_00000e90_miss
ldr w12, [x9, #52]
movz w13, #0
add w14, w12, w13
cmp w14, #0x1000
b.lo L_00000e90_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w14, w13
b.hi L_00000e90_fault
add x13, x11, w14, uxtw
ldr w14, [x13]
str w14, [sp, #0]
movz w13, #4
add w14, w12, w13
cmp w14, #0x1000
b.lo L_00000e90_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w14, w13
b.hi L_00000e90_fault
add x13, x11, w14, uxtw
ldr w14, [x13]
str w14, [sp, #4]
movz w13, #8
add w14, w12, w13
cmp w14, #0x1000
b.lo L_00000e90_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w14, w13
b.hi L_00000e90_fault
add x13, x11, w14, uxtw
ldr w14, [x13]
str w14, [sp, #8]
movz w13, #12
add w14, w12, w13
cmp w14, #0x1000
b.lo L_00000e90_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w14, w13
b.hi L_00000e90_fault
add x13, x11, w14, uxtw
ldr w14, [x13]
str w14, [sp, #12]
movz w13, #16
add w14, w12, w13
cmp w14, #0x1000
b.lo L_00000e90_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w14, w13
b.hi L_00000e90_fault
add x13, x11, w14, uxtw
ldr w14, [x13]
str w14, [sp, #16]
movz w13, #20
add w14, w12, w13
cmp w14, #0x1000
b.lo L_00000e90_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w14, w13
b.hi L_00000e90_fault
add x13, x11, w14, uxtw
ldr w14, [x13]
str w14, [sp, #20]
movz w13, #24
add w14, w12, w13
cmp w14, #0x1000
b.lo L_00000e90_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w14, w13
b.hi L_00000e90_fault
add x13, x11, w14, uxtw
ldr w14, [x13]
str w14, [sp, #24]
movz w13, #28
add w14, w12, w13
cmp w14, #0x1000
b.lo L_00000e90_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w14, w13
b.hi L_00000e90_fault
add x13, x11, w14, uxtw
ldr w14, [x13]
str w14, [sp, #28]
movz w13, #32
add w14, w12, w13
cmp w14, #0x1000
b.lo L_00000e90_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w14, w13
b.hi L_00000e90_fault
add x13, x11, w14, uxtw
ldr w14, [x13]
str w14, [sp, #32]
movz w13, #36
add w14, w12, w13
cmp w14, #0x1000
b.lo L_00000e90_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w14, w13
b.hi L_00000e90_fault
add x13, x11, w14, uxtw
ldr w14, [x13]
str w14, [sp, #36]
movz w13, #40
add w12, w12, w13
str w12, [x9, #52]
ldr w12, [sp, #0]
str w12, [x9, #12]
ldr w12, [sp, #4]
str w12, [x9, #16]
ldr w12, [sp, #8]
str w12, [x9, #20]
ldr w12, [sp, #12]
str w12, [x9, #24]
ldr w12, [sp, #16]
str w12, [x9, #28]
ldr w12, [sp, #20]
str w12, [x9, #32]
ldr w12, [sp, #24]
str w12, [x9, #36]
ldr w12, [sp, #28]
str w12, [x9, #40]
ldr w12, [sp, #32]
str w12, [x9, #44]
ldr w12, [sp, #36]
str w12, [x9, #60]
ldr w12, [x9, #60]
ldr w13, [x10]
and w14, w12, #1
lsl w14, w14, #5
bic w13, w13, #0x20
orr w13, w13, w14
str w13, [x10]
bic w12, w12, #1
str w12, [x9, #60]
b L_00000e90_success
L_00000e90_success:
mov w0, #1
b L_00000e90_return
L_00000e90_fault:
mov w0, #-1
b L_00000e90_return
L_00000e90_miss:
mov w0, #3
b L_00000e90_return
L_00000e90_mode_miss:
mov w0, #4
L_00000e90_return:
add sp, sp, #64
ret

.text
.p2align 2
.globl _agr_game_compiled_00000e94
_agr_game_compiled_00000e94:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00000e94_mode_miss
movz w12, #3732
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #59693
movk w12, #17400, lsl #16
cmp w14, w12
b.ne L_00000e94_miss
movz w12, #3736
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #17951
cmp w14, w12
b.ne L_00000e94_miss
movz w12, #3738
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #26627
cmp w14, w12
b.ne L_00000e94_miss
movz w12, #3740
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #18064
cmp w14, w12
b.ne L_00000e94_miss
movz w12, #3742
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #17937
cmp w14, w12
b.ne L_00000e94_miss
movz w12, #3744
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #8704
cmp w14, w12
b.ne L_00000e94_miss
movz w12, #3746
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #17924
cmp w14, w12
b.ne L_00000e94_miss
movz w12, #3748
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #62017
movk w12, #18694, lsl #16
cmp w14, w12
b.ne L_00000e94_miss
movz w12, #3752
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #63699
movk w12, #13044, lsl #16
cmp w14, w12
b.ne L_00000e94_miss
movz w12, #3756
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #18328
cmp w14, w12
b.ne L_00000e94_miss
ldr w12, [x9, #52]
movz w13, #32
sub w12, w12, w13
cmp w12, #0x1000
b.lo L_00000e94_fault
add x13, x11, w12, uxtw
ldr w14, [x9, #12]
str w14, [x13, #0]
ldr w14, [x9, #16]
str w14, [x13, #4]
ldr w14, [x9, #20]
str w14, [x13, #8]
ldr w14, [x9, #24]
str w14, [x13, #12]
ldr w14, [x9, #28]
str w14, [x13, #16]
ldr w14, [x9, #32]
str w14, [x13, #20]
ldr w14, [x9, #36]
str w14, [x13, #24]
ldr w14, [x9, #56]
str w14, [x13, #28]
str w12, [x9, #52]
ldr w12, [x9, #12]
str w12, [x9, #28]
ldr w12, [x9, #0]
movz w13, #0
add w12, w12, w13
cmp w12, #0x1000
b.lo L_00000e94_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w12, w13
b.hi L_00000e94_fault
add x13, x11, w12, uxtw
ldr w12, [x13]
str w12, [x9, #12]
ldr w12, [x9, #8]
str w12, [x9, #32]
ldr w12, [x9, #8]
str w12, [x9, #4]
movz w12, #0
str w12, [x9, #8]
cmp w12, #0
mrs x13, nzcv
ldr w14, [x10]
and w13, w13, #0xc0000000
and w14, w14, #0x3fffffff
orr w14, w14, w13
str w14, [x10]
ldr w12, [x9, #0]
str w12, [x9, #16]
movz w12, #5126
str w12, [x9, #36]
ldr w12, [x9, #12]
movz w13, #756
add w12, w12, w13
cmp w12, #0x1000
b.lo L_00000e94_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w12, w13
b.hi L_00000e94_fault
add x13, x11, w12, uxtw
ldr w12, [x13]
str w12, [x9, #12]
ldr w12, [x9, #12]
movz w13, #3758
add w13, w15, w13
orr w13, w13, #1
str w13, [x9, #56]
ldr w13, [x10]
and w14, w12, #1
lsl w14, w14, #5
bic w13, w13, #0x20
orr w13, w13, w14
str w13, [x10]
bic w12, w12, #1
str w12, [x9, #60]
b L_00000e94_success
L_00000e94_success:
mov w0, #1
b L_00000e94_return
L_00000e94_fault:
mov w0, #-1
b L_00000e94_return
L_00000e94_miss:
mov w0, #3
b L_00000e94_return
L_00000e94_mode_miss:
mov w0, #4
L_00000e94_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00000eae
_agr_game_compiled_00000eae:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00000eae_mode_miss
movz w12, #3758
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #26659
cmp w14, w12
b.ne L_00000eae_miss
movz w12, #3760
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #17977
cmp w14, w12
b.ne L_00000eae_miss
movz w12, #3762
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #8704
cmp w14, w12
b.ne L_00000eae_miss
movz w12, #3764
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #63699
movk w12, #13044, lsl #16
cmp w14, w12
b.ne L_00000eae_miss
movz w12, #3768
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #17925
cmp w14, w12
b.ne L_00000eae_miss
movz w12, #3770
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #17952
cmp w14, w12
b.ne L_00000eae_miss
movz w12, #3772
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #18328
cmp w14, w12
b.ne L_00000eae_miss
ldr w12, [x9, #16]
movz w13, #0
add w12, w12, w13
cmp w12, #0x1000
b.lo L_00000eae_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w12, w13
b.hi L_00000eae_fault
add x13, x11, w12, uxtw
ldr w12, [x13]
str w12, [x9, #12]
ldr w12, [x9, #28]
str w12, [x9, #4]
movz w12, #0
str w12, [x9, #8]
cmp w12, #0
mrs x13, nzcv
ldr w14, [x10]
and w13, w13, #0xc0000000
and w14, w14, #0x3fffffff
orr w14, w14, w13
str w14, [x10]
ldr w12, [x9, #12]
movz w13, #756
add w12, w12, w13
cmp w12, #0x1000
b.lo L_00000eae_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w12, w13
b.hi L_00000eae_fault
add x13, x11, w12, uxtw
ldr w12, [x13]
str w12, [x9, #12]
ldr w12, [x9, #0]
str w12, [x9, #20]
ldr w12, [x9, #16]
str w12, [x9, #0]
ldr w12, [x9, #12]
movz w13, #3774
add w13, w15, w13
orr w13, w13, #1
str w13, [x9, #56]
ldr w13, [x10]
and w14, w12, #1
lsl w14, w14, #5
bic w13, w13, #0x20
orr w13, w13, w14
str w13, [x10]
bic w12, w12, #1
str w12, [x9, #60]
b L_00000eae_success
L_00000eae_success:
mov w0, #1
b L_00000eae_return
L_00000eae_fault:
mov w0, #-1
b L_00000eae_return
L_00000eae_miss:
mov w0, #3
b L_00000eae_return
L_00000eae_mode_miss:
mov w0, #4
L_00000eae_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00000ebe
_agr_game_compiled_00000ebe:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00000ebe_mode_miss
movz w12, #3774
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #17993
cmp w14, w12
b.ne L_00000ebe_miss
movz w12, #3776
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #17963
cmp w14, w12
b.ne L_00000ebe_miss
movz w12, #3778
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #8704
cmp w14, w12
b.ne L_00000ebe_miss
movz w12, #3780
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #17926
cmp w14, w12
b.ne L_00000ebe_miss
movz w12, #3782
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #8194
cmp w14, w12
b.ne L_00000ebe_miss
movz w12, #3784
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #63487
movk w12, #61214, lsl #16
cmp w14, w12
b.ne L_00000ebe_miss
ldr w12, [x9, #36]
str w12, [x9, #4]
ldr w12, [x9, #20]
str w12, [x9, #12]
movz w12, #0
str w12, [x9, #8]
cmp w12, #0
mrs x13, nzcv
ldr w14, [x10]
and w13, w13, #0xc0000000
and w14, w14, #0x3fffffff
orr w14, w14, w13
str w14, [x10]
ldr w12, [x9, #0]
str w12, [x9, #24]
movz w12, #2
str w12, [x9, #0]
cmp w12, #0
mrs x13, nzcv
ldr w14, [x10]
and w13, w13, #0xc0000000
and w14, w14, #0x3fffffff
orr w14, w14, w13
str w14, [x10]
movz w12, #3336
add w12, w15, w12
movz w13, #3788
add w13, w15, w13
orr w13, w13, #1
str w13, [x9, #56]
ldr w13, [x10]
and w14, w12, #1
lsl w14, w14, #5
bic w13, w13, #0x20
orr w13, w13, w14
str w13, [x10]
bic w12, w12, #1
str w12, [x9, #60]
b L_00000ebe_success
L_00000ebe_success:
mov w0, #1
b L_00000ebe_return
L_00000ebe_fault:
mov w0, #-1
b L_00000ebe_return
L_00000ebe_miss:
mov w0, #3
b L_00000ebe_return
L_00000ebe_mode_miss:
mov w0, #4
L_00000ebe_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00000ecc
_agr_game_compiled_00000ecc:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00000ecc_mode_miss
movz w12, #3788
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #17971
cmp w14, w12
b.ne L_00000ecc_miss
movz w12, #3790
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #17993
cmp w14, w12
b.ne L_00000ecc_miss
movz w12, #3792
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #8196
cmp w14, w12
b.ne L_00000ecc_miss
movz w12, #3794
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #8704
cmp w14, w12
b.ne L_00000ecc_miss
movz w12, #3796
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #63487
movk w12, #61214, lsl #16
cmp w14, w12
b.ne L_00000ecc_miss
ldr w12, [x9, #24]
str w12, [x9, #12]
ldr w12, [x9, #36]
str w12, [x9, #4]
movz w12, #4
str w12, [x9, #0]
cmp w12, #0
mrs x13, nzcv
ldr w14, [x10]
and w13, w13, #0xc0000000
and w14, w14, #0x3fffffff
orr w14, w14, w13
str w14, [x10]
movz w12, #0
str w12, [x9, #8]
cmp w12, #0
mrs x13, nzcv
ldr w14, [x10]
and w13, w13, #0xc0000000
and w14, w14, #0x3fffffff
orr w14, w14, w13
str w14, [x10]
movz w12, #3348
add w12, w15, w12
movz w13, #3800
add w13, w15, w13
orr w13, w13, #1
str w13, [x9, #56]
ldr w13, [x10]
and w14, w12, #1
lsl w14, w14, #5
bic w13, w13, #0x20
orr w13, w13, w14
str w13, [x10]
bic w12, w12, #1
str w12, [x9, #60]
b L_00000ecc_success
L_00000ecc_success:
mov w0, #1
b L_00000ecc_return
L_00000ecc_fault:
mov w0, #-1
b L_00000ecc_return
L_00000ecc_miss:
mov w0, #3
b L_00000ecc_return
L_00000ecc_mode_miss:
mov w0, #4
L_00000ecc_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00000ed8
_agr_game_compiled_00000ed8:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00000ed8_mode_miss
movz w12, #3800
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #39432
cmp w14, w12
b.ne L_00000ed8_miss
movz w12, #3802
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #8193
cmp w14, w12
b.ne L_00000ed8_miss
movz w12, #3804
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #8448
cmp w14, w12
b.ne L_00000ed8_miss
movz w12, #3806
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #63487
movk w12, #61228, lsl #16
cmp w14, w12
b.ne L_00000ed8_miss
ldr w12, [x9, #52]
movz w13, #32
add w12, w12, w13
cmp w12, #0x1000
b.lo L_00000ed8_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w12, w13
b.hi L_00000ed8_fault
add x13, x11, w12, uxtw
ldr w12, [x13]
str w12, [x9, #8]
movz w12, #1
str w12, [x9, #0]
cmp w12, #0
mrs x13, nzcv
ldr w14, [x10]
and w13, w13, #0xc0000000
and w14, w14, #0x3fffffff
orr w14, w14, w13
str w14, [x10]
movz w12, #0
str w12, [x9, #4]
cmp w12, #0
mrs x13, nzcv
ldr w14, [x10]
and w13, w13, #0xc0000000
and w14, w14, #0x3fffffff
orr w14, w14, w13
str w14, [x10]
movz w12, #3384
add w12, w15, w12
movz w13, #3810
add w13, w15, w13
orr w13, w13, #1
str w13, [x9, #56]
ldr w13, [x10]
and w14, w12, #1
lsl w14, w14, #5
bic w13, w13, #0x20
orr w13, w13, w14
str w13, [x10]
bic w12, w12, #1
str w12, [x9, #60]
b L_00000ed8_success
L_00000ed8_success:
mov w0, #1
b L_00000ed8_return
L_00000ed8_fault:
mov w0, #-1
b L_00000ed8_return
L_00000ed8_miss:
mov w0, #3
b L_00000ed8_return
L_00000ed8_mode_miss:
mov w0, #4
L_00000ed8_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00000ee2
_agr_game_compiled_00000ee2:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00000ee2_mode_miss
movz w12, #3810
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #26659
cmp w14, w12
b.ne L_00000ee2_miss
movz w12, #3812
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #17952
cmp w14, w12
b.ne L_00000ee2_miss
movz w12, #3814
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #17977
cmp w14, w12
b.ne L_00000ee2_miss
movz w12, #3816
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #17970
cmp w14, w12
b.ne L_00000ee2_miss
movz w12, #3818
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #63699
movk w12, #49940, lsl #16
cmp w14, w12
b.ne L_00000ee2_miss
movz w12, #3822
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #8960
cmp w14, w12
b.ne L_00000ee2_miss
movz w12, #3824
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #18400
cmp w14, w12
b.ne L_00000ee2_miss
ldr w12, [x9, #16]
movz w13, #0
add w12, w12, w13
cmp w12, #0x1000
b.lo L_00000ee2_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w12, w13
b.hi L_00000ee2_fault
add x13, x11, w12, uxtw
ldr w12, [x13]
str w12, [x9, #12]
ldr w12, [x9, #16]
str w12, [x9, #0]
ldr w12, [x9, #28]
str w12, [x9, #4]
ldr w12, [x9, #24]
str w12, [x9, #8]
ldr w12, [x9, #12]
movz w13, #788
add w12, w12, w13
cmp w12, #0x1000
b.lo L_00000ee2_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w12, w13
b.hi L_00000ee2_fault
add x13, x11, w12, uxtw
ldr w12, [x13]
str w12, [x9, #48]
movz w12, #0
str w12, [x9, #12]
cmp w12, #0
mrs x13, nzcv
ldr w14, [x10]
and w13, w13, #0xc0000000
and w14, w14, #0x3fffffff
orr w14, w14, w13
str w14, [x10]
ldr w12, [x9, #48]
movz w13, #3826
add w13, w15, w13
orr w13, w13, #1
str w13, [x9, #56]
ldr w13, [x10]
and w14, w12, #1
lsl w14, w14, #5
bic w13, w13, #0x20
orr w13, w13, w14
str w13, [x10]
bic w12, w12, #1
str w12, [x9, #60]
b L_00000ee2_success
L_00000ee2_success:
mov w0, #1
b L_00000ee2_return
L_00000ee2_fault:
mov w0, #-1
b L_00000ee2_return
L_00000ee2_miss:
mov w0, #3
b L_00000ee2_return
L_00000ee2_mode_miss:
mov w0, #4
L_00000ee2_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00000ef2
_agr_game_compiled_00000ef2:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00000ef2_mode_miss
movz w12, #3826
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #26659
cmp w14, w12
b.ne L_00000ef2_miss
movz w12, #3828
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #17952
cmp w14, w12
b.ne L_00000ef2_miss
movz w12, #3830
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #17985
cmp w14, w12
b.ne L_00000ef2_miss
movz w12, #3832
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #17962
cmp w14, w12
b.ne L_00000ef2_miss
movz w12, #3834
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #63699
movk w12, #25364, lsl #16
cmp w14, w12
b.ne L_00000ef2_miss
movz w12, #3838
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #8960
cmp w14, w12
b.ne L_00000ef2_miss
movz w12, #3840
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #18352
cmp w14, w12
b.ne L_00000ef2_miss
ldr w12, [x9, #16]
movz w13, #0
add w12, w12, w13
cmp w12, #0x1000
b.lo L_00000ef2_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w12, w13
b.hi L_00000ef2_fault
add x13, x11, w12, uxtw
ldr w12, [x13]
str w12, [x9, #12]
ldr w12, [x9, #16]
str w12, [x9, #0]
ldr w12, [x9, #32]
str w12, [x9, #4]
ldr w12, [x9, #20]
str w12, [x9, #8]
ldr w12, [x9, #12]
movz w13, #788
add w12, w12, w13
cmp w12, #0x1000
b.lo L_00000ef2_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w12, w13
b.hi L_00000ef2_fault
add x13, x11, w12, uxtw
ldr w12, [x13]
str w12, [x9, #24]
movz w12, #0
str w12, [x9, #12]
cmp w12, #0
mrs x13, nzcv
ldr w14, [x10]
and w13, w13, #0xc0000000
and w14, w14, #0x3fffffff
orr w14, w14, w13
str w14, [x10]
ldr w12, [x9, #24]
movz w13, #3842
add w13, w15, w13
orr w13, w13, #1
str w13, [x9, #56]
ldr w13, [x10]
and w14, w12, #1
lsl w14, w14, #5
bic w13, w13, #0x20
orr w13, w13, w14
str w13, [x10]
bic w12, w12, #1
str w12, [x9, #60]
b L_00000ef2_success
L_00000ef2_success:
mov w0, #1
b L_00000ef2_return
L_00000ef2_fault:
mov w0, #-1
b L_00000ef2_return
L_00000ef2_miss:
mov w0, #3
b L_00000ef2_return
L_00000ef2_mode_miss:
mov w0, #4
L_00000ef2_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00000f02
_agr_game_compiled_00000f02:
sub sp, sp, #64
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00000f02_mode_miss
movz w12, #3842
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #59581
movk w12, #33784, lsl #16
cmp w14, w12
b.ne L_00000f02_miss
ldr w12, [x9, #52]
movz w13, #0
add w14, w12, w13
cmp w14, #0x1000
b.lo L_00000f02_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w14, w13
b.hi L_00000f02_fault
add x13, x11, w14, uxtw
ldr w14, [x13]
str w14, [sp, #0]
movz w13, #4
add w14, w12, w13
cmp w14, #0x1000
b.lo L_00000f02_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w14, w13
b.hi L_00000f02_fault
add x13, x11, w14, uxtw
ldr w14, [x13]
str w14, [sp, #4]
movz w13, #8
add w14, w12, w13
cmp w14, #0x1000
b.lo L_00000f02_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w14, w13
b.hi L_00000f02_fault
add x13, x11, w14, uxtw
ldr w14, [x13]
str w14, [sp, #8]
movz w13, #12
add w14, w12, w13
cmp w14, #0x1000
b.lo L_00000f02_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w14, w13
b.hi L_00000f02_fault
add x13, x11, w14, uxtw
ldr w14, [x13]
str w14, [sp, #12]
movz w13, #16
add w14, w12, w13
cmp w14, #0x1000
b.lo L_00000f02_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w14, w13
b.hi L_00000f02_fault
add x13, x11, w14, uxtw
ldr w14, [x13]
str w14, [sp, #16]
movz w13, #20
add w14, w12, w13
cmp w14, #0x1000
b.lo L_00000f02_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w14, w13
b.hi L_00000f02_fault
add x13, x11, w14, uxtw
ldr w14, [x13]
str w14, [sp, #20]
movz w13, #24
add w14, w12, w13
cmp w14, #0x1000
b.lo L_00000f02_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w14, w13
b.hi L_00000f02_fault
add x13, x11, w14, uxtw
ldr w14, [x13]
str w14, [sp, #24]
movz w13, #28
add w14, w12, w13
cmp w14, #0x1000
b.lo L_00000f02_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w14, w13
b.hi L_00000f02_fault
add x13, x11, w14, uxtw
ldr w14, [x13]
str w14, [sp, #28]
movz w13, #32
add w12, w12, w13
str w12, [x9, #52]
ldr w12, [sp, #0]
str w12, [x9, #12]
ldr w12, [sp, #4]
str w12, [x9, #16]
ldr w12, [sp, #8]
str w12, [x9, #20]
ldr w12, [sp, #12]
str w12, [x9, #24]
ldr w12, [sp, #16]
str w12, [x9, #28]
ldr w12, [sp, #20]
str w12, [x9, #32]
ldr w12, [sp, #24]
str w12, [x9, #36]
ldr w12, [sp, #28]
str w12, [x9, #60]
ldr w12, [x9, #60]
ldr w13, [x10]
and w14, w12, #1
lsl w14, w14, #5
bic w13, w13, #0x20
orr w13, w13, w14
str w13, [x10]
bic w12, w12, #1
str w12, [x9, #60]
b L_00000f02_success
L_00000f02_success:
mov w0, #1
b L_00000f02_return
L_00000f02_fault:
mov w0, #-1
b L_00000f02_return
L_00000f02_miss:
mov w0, #3
b L_00000f02_return
L_00000f02_mode_miss:
mov w0, #4
L_00000f02_return:
add sp, sp, #64
ret

.text
.p2align 2
.globl _agr_game_compiled_00000f08
_agr_game_compiled_00000f08:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00000f08_mode_miss
movz w12, #3848
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #26627
cmp w14, w12
b.ne L_00000f08_miss
ldr w12, [x9, #0]
movz w13, #0
add w12, w12, w13
cmp w12, #0x1000
b.lo L_00000f08_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w12, w13
b.hi L_00000f08_fault
add x13, x11, w12, uxtw
ldr w12, [x13]
str w12, [x9, #12]
movz w12, #3850
add w12, w15, w12
str w12, [x9, #60]
L_00000f08_success:
mov w0, #1
b L_00000f08_return
L_00000f08_fault:
mov w0, #-1
b L_00000f08_return
L_00000f08_miss:
mov w0, #3
b L_00000f08_return
L_00000f08_mode_miss:
mov w0, #4
L_00000f08_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00000f1a
_agr_game_compiled_00000f1a:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00000f1a_mode_miss
movz w12, #3866
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #59693
movk w12, #20471, lsl #16
cmp w14, w12
b.ne L_00000f1a_miss
movz w12, #3870
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #18049
cmp w14, w12
b.ne L_00000f1a_miss
movz w12, #3872
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #17942
cmp w14, w12
b.ne L_00000f1a_miss
movz w12, #3874
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #45857
cmp w14, w12
b.ne L_00000f1a_miss
ldr w12, [x9, #52]
movz w13, #48
sub w12, w12, w13
cmp w12, #0x1000
b.lo L_00000f1a_fault
add x13, x11, w12, uxtw
ldr w14, [x9, #0]
str w14, [x13, #0]
ldr w14, [x9, #4]
str w14, [x13, #4]
ldr w14, [x9, #8]
str w14, [x13, #8]
ldr w14, [x9, #16]
str w14, [x13, #12]
ldr w14, [x9, #20]
str w14, [x13, #16]
ldr w14, [x9, #24]
str w14, [x13, #20]
ldr w14, [x9, #28]
str w14, [x13, #24]
ldr w14, [x9, #32]
str w14, [x13, #28]
ldr w14, [x9, #36]
str w14, [x13, #32]
ldr w14, [x9, #40]
str w14, [x13, #36]
ldr w14, [x9, #44]
str w14, [x13, #40]
ldr w14, [x9, #56]
str w14, [x13, #44]
str w12, [x9, #52]
ldr w12, [x9, #0]
str w12, [x9, #36]
ldr w12, [x9, #8]
str w12, [x9, #24]
ldr w12, [x9, #4]
cbz w12, L_00000f1a_taken_3
movz w12, #3876
add w12, w15, w12
str w12, [x9, #60]
b L_00000f1a_success
L_00000f1a_taken_3:
movz w12, #3950
add w12, w15, w12
str w12, [x9, #60]
b L_00000f1a_success
L_00000f1a_success:
mov w0, #1
b L_00000f1a_return
L_00000f1a_fault:
mov w0, #-1
b L_00000f1a_return
L_00000f1a_miss:
mov w0, #3
b L_00000f1a_return
L_00000f1a_mode_miss:
mov w0, #4
L_00000f1a_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00000f24
_agr_game_compiled_00000f24:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00000f24_mode_miss
movz w12, #3876
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #61697
movk w12, #14591, lsl #16
cmp w14, w12
b.ne L_00000f24_miss
movz w12, #3880
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #9984
cmp w14, w12
b.ne L_00000f24_miss
movz w12, #3882
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #18114
cmp w14, w12
b.ne L_00000f24_miss
ldr w12, [x9, #4]
movz w13, #1023
add w12, w12, w13
str w12, [x9, #32]
movz w12, #0
str w12, [x9, #28]
cmp w12, #0
mrs x13, nzcv
ldr w14, [x10]
and w13, w13, #0xc0000000
and w14, w14, #0x3fffffff
orr w14, w14, w13
str w14, [x10]
ldr w12, [x9, #32]
str w12, [x9, #40]
movz w12, #3884
add w12, w15, w12
str w12, [x9, #60]
L_00000f24_success:
mov w0, #1
b L_00000f24_return
L_00000f24_fault:
mov w0, #-1
b L_00000f24_return
L_00000f24_miss:
mov w0, #3
b L_00000f24_return
L_00000f24_mode_miss:
mov w0, #4
L_00000f24_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00000f3e
_agr_game_compiled_00000f3e:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00000f3e_mode_miss
movz w12, #3902
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #17960
cmp w14, w12
b.ne L_00000f3e_miss
movz w12, #3904
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #63487
movk w12, #65506, lsl #16
cmp w14, w12
b.ne L_00000f3e_miss
ldr w12, [x9, #20]
str w12, [x9, #0]
movz w12, #3848
add w12, w15, w12
orr w12, w12, #1
movz w13, #3908
add w13, w15, w13
orr w13, w13, #1
str w13, [x9, #56]
ldr w13, [x10]
and w14, w12, #1
lsl w14, w14, #5
bic w13, w13, #0x20
orr w13, w13, w14
str w13, [x10]
bic w12, w12, #1
str w12, [x9, #60]
b L_00000f3e_success
L_00000f3e_success:
mov w0, #1
b L_00000f3e_return
L_00000f3e_fault:
mov w0, #-1
b L_00000f3e_return
L_00000f3e_miss:
mov w0, #3
b L_00000f3e_return
L_00000f3e_mode_miss:
mov w0, #4
L_00000f3e_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00000f46
_agr_game_compiled_00000f46:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00000f46_mode_miss
movz w12, #3910
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #39681
cmp w14, w12
b.ne L_00000f46_miss
movz w12, #3912
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #18051
cmp w14, w12
b.ne L_00000f46_miss
ldr w12, [x9, #52]
movz w13, #4
add w12, w12, w13
cmp w12, #0x1000
b.lo L_00000f46_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w12, w13
b.hi L_00000f46_fault
add x13, x11, w12, uxtw
ldr w12, [x13]
str w12, [x9, #12]
ldr w12, [x9, #0]
str w12, [x9, #44]
movz w12, #3914
add w12, w15, w12
str w12, [x9, #60]
L_00000f46_success:
mov w0, #1
b L_00000f46_return
L_00000f46_fault:
mov w0, #-1
b L_00000f46_return
L_00000f46_miss:
mov w0, #3
b L_00000f46_return
L_00000f46_mode_miss:
mov w0, #4
L_00000f46_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00000f4c
_agr_game_compiled_00000f4c:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00000f4c_mode_miss
movz w12, #3916
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #61699
movk w12, #8, lsl #16
cmp w14, w12
b.ne L_00000f4c_miss
ldr w12, [x9, #12]
movz w13, #8
add w12, w12, w13
str w12, [x9, #0]
movz w12, #3920
add w12, w15, w12
str w12, [x9, #60]
L_00000f4c_success:
mov w0, #1
b L_00000f4c_return
L_00000f4c_fault:
mov w0, #-1
b L_00000f4c_return
L_00000f4c_miss:
mov w0, #3
b L_00000f4c_return
L_00000f4c_mode_miss:
mov w0, #4
L_00000f4c_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00000f52
_agr_game_compiled_00000f52:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00000f52_mode_miss
movz w12, #3922
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #63487
movk w12, #65497, lsl #16
cmp w14, w12
b.ne L_00000f52_miss
movz w12, #3848
add w12, w15, w12
orr w12, w12, #1
movz w13, #3926
add w13, w15, w13
orr w13, w13, #1
str w13, [x9, #56]
ldr w13, [x10]
and w14, w12, #1
lsl w14, w14, #5
bic w13, w13, #0x20
orr w13, w13, w14
str w13, [x10]
bic w12, w12, #1
str w12, [x9, #60]
b L_00000f52_success
L_00000f52_success:
mov w0, #1
b L_00000f52_return
L_00000f52_fault:
mov w0, #-1
b L_00000f52_return
L_00000f52_miss:
mov w0, #3
b L_00000f52_return
L_00000f52_mode_miss:
mov w0, #4
L_00000f52_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00000f5e
_agr_game_compiled_00000f5e:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00000f5e_mode_miss
movz w12, #3934
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #61700
movk w12, #15103, lsl #16
cmp w14, w12
b.ne L_00000f5e_miss
movz w12, #3938
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #59363
cmp w14, w12
b.ne L_00000f5e_miss
ldr w12, [x9, #16]
movz w13, #1023
add w12, w12, w13
str w12, [x9, #40]
movz w12, #3884
add w12, w15, w12
str w12, [x9, #60]
b L_00000f5e_success
L_00000f5e_success:
mov w0, #1
b L_00000f5e_return
L_00000f5e_fault:
mov w0, #-1
b L_00000f5e_return
L_00000f5e_miss:
mov w0, #3
b L_00000f5e_return
L_00000f5e_mode_miss:
mov w0, #4
L_00000f5e_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00000f6c
_agr_game_compiled_00000f6c:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00000f6c_mode_miss
movz w12, #3948
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #59358
cmp w14, w12
b.ne L_00000f6c_miss
movz w12, #3884
add w12, w15, w12
str w12, [x9, #60]
b L_00000f6c_success
L_00000f6c_success:
mov w0, #1
b L_00000f6c_return
L_00000f6c_fault:
mov w0, #-1
b L_00000f6c_return
L_00000f6c_miss:
mov w0, #3
b L_00000f6c_return
L_00000f6c_mode_miss:
mov w0, #4
L_00000f6c_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00000f6e
_agr_game_compiled_00000f6e:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00000f6e_mode_miss
movz w12, #3950
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #17933
cmp w14, w12
b.ne L_00000f6e_miss
movz w12, #3952
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #57347
cmp w14, w12
b.ne L_00000f6e_miss
ldr w12, [x9, #4]
str w12, [x9, #20]
movz w12, #3962
add w12, w15, w12
str w12, [x9, #60]
b L_00000f6e_success
L_00000f6e_success:
mov w0, #1
b L_00000f6e_return
L_00000f6e_fault:
mov w0, #-1
b L_00000f6e_return
L_00000f6e_miss:
mov w0, #3
b L_00000f6e_return
L_00000f6e_mode_miss:
mov w0, #4
L_00000f6e_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00000f72
_agr_game_compiled_00000f72:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00000f72_mode_miss
movz w12, #3954
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #9472
cmp w14, w12
b.ne L_00000f72_miss
movz w12, #3956
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #57345
cmp w14, w12
b.ne L_00000f72_miss
movz w12, #0
str w12, [x9, #20]
cmp w12, #0
mrs x13, nzcv
ldr w14, [x10]
and w13, w13, #0xc0000000
and w14, w14, #0x3fffffff
orr w14, w14, w13
str w14, [x10]
movz w12, #3962
add w12, w15, w12
str w12, [x9, #60]
b L_00000f72_success
L_00000f72_success:
mov w0, #1
b L_00000f72_return
L_00000f72_fault:
mov w0, #-1
b L_00000f72_return
L_00000f72_miss:
mov w0, #3
b L_00000f72_return
L_00000f72_mode_miss:
mov w0, #4
L_00000f72_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00000f7a
_agr_game_compiled_00000f7a:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00000f7a_mode_miss
movz w12, #3962
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #17960
cmp w14, w12
b.ne L_00000f7a_miss
ldr w12, [x9, #20]
str w12, [x9, #0]
movz w12, #3964
add w12, w15, w12
str w12, [x9, #60]
L_00000f7a_success:
mov w0, #1
b L_00000f7a_return
L_00000f7a_fault:
mov w0, #-1
b L_00000f7a_return
L_00000f7a_miss:
mov w0, #3
b L_00000f7a_return
L_00000f7a_mode_miss:
mov w0, #4
L_00000f7a_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00000f7e
_agr_game_compiled_00000f7e:
sub sp, sp, #64
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00000f7e_mode_miss
movz w12, #3966
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #59581
movk w12, #36848, lsl #16
cmp w14, w12
b.ne L_00000f7e_miss
ldr w12, [x9, #52]
movz w13, #0
add w14, w12, w13
cmp w14, #0x1000
b.lo L_00000f7e_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w14, w13
b.hi L_00000f7e_fault
add x13, x11, w14, uxtw
ldr w14, [x13]
str w14, [sp, #0]
movz w13, #4
add w14, w12, w13
cmp w14, #0x1000
b.lo L_00000f7e_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w14, w13
b.hi L_00000f7e_fault
add x13, x11, w14, uxtw
ldr w14, [x13]
str w14, [sp, #4]
movz w13, #8
add w14, w12, w13
cmp w14, #0x1000
b.lo L_00000f7e_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w14, w13
b.hi L_00000f7e_fault
add x13, x11, w14, uxtw
ldr w14, [x13]
str w14, [sp, #8]
movz w13, #12
add w14, w12, w13
cmp w14, #0x1000
b.lo L_00000f7e_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w14, w13
b.hi L_00000f7e_fault
add x13, x11, w14, uxtw
ldr w14, [x13]
str w14, [sp, #12]
movz w13, #16
add w14, w12, w13
cmp w14, #0x1000
b.lo L_00000f7e_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w14, w13
b.hi L_00000f7e_fault
add x13, x11, w14, uxtw
ldr w14, [x13]
str w14, [sp, #16]
movz w13, #20
add w14, w12, w13
cmp w14, #0x1000
b.lo L_00000f7e_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w14, w13
b.hi L_00000f7e_fault
add x13, x11, w14, uxtw
ldr w14, [x13]
str w14, [sp, #20]
movz w13, #24
add w14, w12, w13
cmp w14, #0x1000
b.lo L_00000f7e_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w14, w13
b.hi L_00000f7e_fault
add x13, x11, w14, uxtw
ldr w14, [x13]
str w14, [sp, #24]
movz w13, #28
add w14, w12, w13
cmp w14, #0x1000
b.lo L_00000f7e_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w14, w13
b.hi L_00000f7e_fault
add x13, x11, w14, uxtw
ldr w14, [x13]
str w14, [sp, #28]
movz w13, #32
add w14, w12, w13
cmp w14, #0x1000
b.lo L_00000f7e_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w14, w13
b.hi L_00000f7e_fault
add x13, x11, w14, uxtw
ldr w14, [x13]
str w14, [sp, #32]
movz w13, #36
add w12, w12, w13
str w12, [x9, #52]
ldr w12, [sp, #0]
str w12, [x9, #16]
ldr w12, [sp, #4]
str w12, [x9, #20]
ldr w12, [sp, #8]
str w12, [x9, #24]
ldr w12, [sp, #12]
str w12, [x9, #28]
ldr w12, [sp, #16]
str w12, [x9, #32]
ldr w12, [sp, #20]
str w12, [x9, #36]
ldr w12, [sp, #24]
str w12, [x9, #40]
ldr w12, [sp, #28]
str w12, [x9, #44]
ldr w12, [sp, #32]
str w12, [x9, #60]
ldr w12, [x9, #60]
ldr w13, [x10]
and w14, w12, #1
lsl w14, w14, #5
bic w13, w13, #0x20
orr w13, w13, w14
str w13, [x10]
bic w12, w12, #1
str w12, [x9, #60]
b L_00000f7e_success
L_00000f7e_success:
mov w0, #1
b L_00000f7e_return
L_00000f7e_fault:
mov w0, #-1
b L_00000f7e_return
L_00000f7e_miss:
mov w0, #3
b L_00000f7e_return
L_00000f7e_mode_miss:
mov w0, #4
L_00000f7e_return:
add sp, sp, #64
ret

.text
.p2align 2
.globl _agr_game_compiled_00000f8a
_agr_game_compiled_00000f8a:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00000f8a_mode_miss
movz w12, #3978
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #47448
cmp w14, w12
b.ne L_00000f8a_miss
ldr w12, [x9, #0]
cbnz w12, L_00000f8a_taken_0
movz w12, #3980
add w12, w15, w12
str w12, [x9, #60]
b L_00000f8a_success
L_00000f8a_taken_0:
movz w12, #4004
add w12, w15, w12
str w12, [x9, #60]
b L_00000f8a_success
L_00000f8a_success:
mov w0, #1
b L_00000f8a_return
L_00000f8a_fault:
mov w0, #-1
b L_00000f8a_return
L_00000f8a_miss:
mov w0, #3
b L_00000f8a_return
L_00000f8a_mode_miss:
mov w0, #4
L_00000f8a_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00000f8c
_agr_game_compiled_00000f8c:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00000f8c_mode_miss
movz w12, #3980
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #18438
cmp w14, w12
b.ne L_00000f8c_miss
movz w12, #3984
add w12, w15, w12
movz w13, #24
add w12, w12, w13
cmp w12, #0x1000
b.lo L_00000f8c_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w12, w13
b.hi L_00000f8c_fault
add x13, x11, w12, uxtw
ldr w12, [x13]
str w12, [x9, #0]
movz w12, #3982
add w12, w15, w12
str w12, [x9, #60]
L_00000f8c_success:
mov w0, #1
b L_00000f8c_return
L_00000f8c_fault:
mov w0, #-1
b L_00000f8c_return
L_00000f8c_miss:
mov w0, #3
b L_00000f8c_return
L_00000f8c_mode_miss:
mov w0, #4
L_00000f8c_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00000f90
_agr_game_compiled_00000f90:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00000f90_mode_miss
movz w12, #3984
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #26624
cmp w14, w12
b.ne L_00000f90_miss
movz w12, #3986
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #18288
cmp w14, w12
b.ne L_00000f90_miss
ldr w12, [x9, #0]
movz w13, #0
add w12, w12, w13
cmp w12, #0x1000
b.lo L_00000f90_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w12, w13
b.hi L_00000f90_fault
add x13, x11, w12, uxtw
ldr w12, [x13]
str w12, [x9, #0]
ldr w12, [x9, #56]
ldr w13, [x10]
and w14, w12, #1
lsl w14, w14, #5
bic w13, w13, #0x20
orr w13, w13, w14
str w13, [x10]
bic w12, w12, #1
str w12, [x9, #60]
b L_00000f90_success
L_00000f90_success:
mov w0, #1
b L_00000f90_return
L_00000f90_fault:
mov w0, #-1
b L_00000f90_return
L_00000f90_miss:
mov w0, #3
b L_00000f90_return
L_00000f90_mode_miss:
mov w0, #4
L_00000f90_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00000f94
_agr_game_compiled_00000f94:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00000f94_mode_miss
movz w12, #3988
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #18437
cmp w14, w12
b.ne L_00000f94_miss
movz w12, #3992
add w12, w15, w12
movz w13, #20
add w12, w12, w13
cmp w12, #0x1000
b.lo L_00000f94_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w12, w13
b.hi L_00000f94_fault
add x13, x11, w12, uxtw
ldr w12, [x13]
str w12, [x9, #0]
movz w12, #3990
add w12, w15, w12
str w12, [x9, #60]
L_00000f94_success:
mov w0, #1
b L_00000f94_return
L_00000f94_fault:
mov w0, #-1
b L_00000f94_return
L_00000f94_miss:
mov w0, #3
b L_00000f94_return
L_00000f94_mode_miss:
mov w0, #4
L_00000f94_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00000f98
_agr_game_compiled_00000f98:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00000f98_mode_miss
movz w12, #3992
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #26624
cmp w14, w12
b.ne L_00000f98_miss
movz w12, #3994
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #18288
cmp w14, w12
b.ne L_00000f98_miss
ldr w12, [x9, #0]
movz w13, #0
add w12, w12, w13
cmp w12, #0x1000
b.lo L_00000f98_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w12, w13
b.hi L_00000f98_fault
add x13, x11, w12, uxtw
ldr w12, [x13]
str w12, [x9, #0]
ldr w12, [x9, #56]
ldr w13, [x10]
and w14, w12, #1
lsl w14, w14, #5
bic w13, w13, #0x20
orr w13, w13, w14
str w13, [x10]
bic w12, w12, #1
str w12, [x9, #60]
b L_00000f98_success
L_00000f98_success:
mov w0, #1
b L_00000f98_return
L_00000f98_fault:
mov w0, #-1
b L_00000f98_return
L_00000f98_miss:
mov w0, #3
b L_00000f98_return
L_00000f98_mode_miss:
mov w0, #4
L_00000f98_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00000f9c
_agr_game_compiled_00000f9c:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00000f9c_mode_miss
movz w12, #3996
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #18436
cmp w14, w12
b.ne L_00000f9c_miss
movz w12, #4000
add w12, w15, w12
movz w13, #16
add w12, w12, w13
cmp w12, #0x1000
b.lo L_00000f9c_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w12, w13
b.hi L_00000f9c_fault
add x13, x11, w12, uxtw
ldr w12, [x13]
str w12, [x9, #0]
movz w12, #3998
add w12, w15, w12
str w12, [x9, #60]
L_00000f9c_success:
mov w0, #1
b L_00000f9c_return
L_00000f9c_fault:
mov w0, #-1
b L_00000f9c_return
L_00000f9c_miss:
mov w0, #3
b L_00000f9c_return
L_00000f9c_mode_miss:
mov w0, #4
L_00000f9c_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00000fa0
_agr_game_compiled_00000fa0:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00000fa0_mode_miss
movz w12, #4000
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #26624
cmp w14, w12
b.ne L_00000fa0_miss
movz w12, #4002
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #18288
cmp w14, w12
b.ne L_00000fa0_miss
ldr w12, [x9, #0]
movz w13, #0
add w12, w12, w13
cmp w12, #0x1000
b.lo L_00000fa0_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w12, w13
b.hi L_00000fa0_fault
add x13, x11, w12, uxtw
ldr w12, [x13]
str w12, [x9, #0]
ldr w12, [x9, #56]
ldr w13, [x10]
and w14, w12, #1
lsl w14, w14, #5
bic w13, w13, #0x20
orr w13, w13, w14
str w13, [x10]
bic w12, w12, #1
str w12, [x9, #60]
b L_00000fa0_success
L_00000fa0_success:
mov w0, #1
b L_00000fa0_return
L_00000fa0_fault:
mov w0, #-1
b L_00000fa0_return
L_00000fa0_miss:
mov w0, #3
b L_00000fa0_return
L_00000fa0_mode_miss:
mov w0, #4
L_00000fa0_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00000fa4
_agr_game_compiled_00000fa4:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00000fa4_mode_miss
movz w12, #4004
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #8192
cmp w14, w12
b.ne L_00000fa4_miss
movz w12, #4006
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #18288
cmp w14, w12
b.ne L_00000fa4_miss
movz w12, #0
str w12, [x9, #0]
cmp w12, #0
mrs x13, nzcv
ldr w14, [x10]
and w13, w13, #0xc0000000
and w14, w14, #0x3fffffff
orr w14, w14, w13
str w14, [x10]
ldr w12, [x9, #56]
ldr w13, [x10]
and w14, w12, #1
lsl w14, w14, #5
bic w13, w13, #0x20
orr w13, w13, w14
str w13, [x10]
bic w12, w12, #1
str w12, [x9, #60]
b L_00000fa4_success
L_00000fa4_success:
mov w0, #1
b L_00000fa4_return
L_00000fa4_fault:
mov w0, #-1
b L_00000fa4_return
L_00000fa4_miss:
mov w0, #3
b L_00000fa4_return
L_00000fa4_mode_miss:
mov w0, #4
L_00000fa4_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00000fa8
_agr_game_compiled_00000fa8:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00000fa8_mode_miss
movz w12, #4008
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #8214
cmp w14, w12
b.ne L_00000fa8_miss
movz w12, #22
str w12, [x9, #0]
cmp w12, #0
mrs x13, nzcv
ldr w14, [x10]
and w13, w13, #0xc0000000
and w14, w14, #0x3fffffff
orr w14, w14, w13
str w14, [x10]
movz w12, #4010
add w12, w15, w12
str w12, [x9, #60]
L_00000fa8_success:
mov w0, #1
b L_00000fa8_return
L_00000fa8_fault:
mov w0, #-1
b L_00000fa8_return
L_00000fa8_miss:
mov w0, #3
b L_00000fa8_return
L_00000fa8_mode_miss:
mov w0, #4
L_00000fa8_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00000fac
_agr_game_compiled_00000fac:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00000fac_mode_miss
movz w12, #4012
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #8210
cmp w14, w12
b.ne L_00000fac_miss
movz w12, #18
str w12, [x9, #0]
cmp w12, #0
mrs x13, nzcv
ldr w14, [x10]
and w13, w13, #0xc0000000
and w14, w14, #0x3fffffff
orr w14, w14, w13
str w14, [x10]
movz w12, #4014
add w12, w15, w12
str w12, [x9, #60]
L_00000fac_success:
mov w0, #1
b L_00000fac_return
L_00000fac_fault:
mov w0, #-1
b L_00000fac_return
L_00000fac_miss:
mov w0, #3
b L_00000fac_return
L_00000fac_mode_miss:
mov w0, #4
L_00000fac_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00000fb0
_agr_game_compiled_00000fb0:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00000fb0_mode_miss
movz w12, #4016
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #8206
cmp w14, w12
b.ne L_00000fb0_miss
movz w12, #14
str w12, [x9, #0]
cmp w12, #0
mrs x13, nzcv
ldr w14, [x10]
and w13, w13, #0xc0000000
and w14, w14, #0x3fffffff
orr w14, w14, w13
str w14, [x10]
movz w12, #4018
add w12, w15, w12
str w12, [x9, #60]
L_00000fb0_success:
mov w0, #1
b L_00000fb0_return
L_00000fb0_fault:
mov w0, #-1
b L_00000fb0_return
L_00000fb0_miss:
mov w0, #3
b L_00000fb0_return
L_00000fb0_mode_miss:
mov w0, #4
L_00000fb0_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00000fb4
_agr_game_compiled_00000fb4:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00000fb4_mode_miss
movz w12, #4020
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #19237
cmp w14, w12
b.ne L_00000fb4_miss
movz w12, #4022
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #46451
cmp w14, w12
b.ne L_00000fb4_miss
movz w12, #4024
add w12, w15, w12
movz w13, #148
add w12, w12, w13
cmp w12, #0x1000
b.lo L_00000fb4_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w12, w13
b.hi L_00000fb4_fault
add x13, x11, w12, uxtw
ldr w12, [x13]
str w12, [x9, #12]
ldr w12, [x9, #52]
movz w13, #24
sub w12, w12, w13
cmp w12, #0x1000
b.lo L_00000fb4_fault
add x13, x11, w12, uxtw
ldr w14, [x9, #0]
str w14, [x13, #0]
ldr w14, [x9, #4]
str w14, [x13, #4]
ldr w14, [x9, #16]
str w14, [x13, #8]
ldr w14, [x9, #20]
str w14, [x13, #12]
ldr w14, [x9, #24]
str w14, [x13, #16]
ldr w14, [x9, #56]
str w14, [x13, #20]
str w12, [x9, #52]
movz w12, #4024
add w12, w15, w12
str w12, [x9, #60]
L_00000fb4_success:
mov w0, #1
b L_00000fb4_return
L_00000fb4_fault:
mov w0, #-1
b L_00000fb4_return
L_00000fb4_miss:
mov w0, #3
b L_00000fb4_return
L_00000fb4_mode_miss:
mov w0, #4
L_00000fb4_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00000fba
_agr_game_compiled_00000fba:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00000fba_mode_miss
movz w12, #4026
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #26651
cmp w14, w12
b.ne L_00000fba_miss
movz w12, #4028
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #17924
cmp w14, w12
b.ne L_00000fba_miss
ldr w12, [x9, #12]
movz w13, #0
add w12, w12, w13
cmp w12, #0x1000
b.lo L_00000fba_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w12, w13
b.hi L_00000fba_fault
add x13, x11, w12, uxtw
ldr w12, [x13]
str w12, [x9, #12]
ldr w12, [x9, #0]
str w12, [x9, #16]
movz w12, #4030
add w12, w15, w12
str w12, [x9, #60]
L_00000fba_success:
mov w0, #1
b L_00000fba_return
L_00000fba_fault:
mov w0, #-1
b L_00000fba_return
L_00000fba_miss:
mov w0, #3
b L_00000fba_return
L_00000fba_mode_miss:
mov w0, #4
L_00000fba_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00000fc0
_agr_game_compiled_00000fc0:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00000fc0_mode_miss
movz w12, #4032
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #45363
cmp w14, w12
b.ne L_00000fc0_miss
ldr w12, [x9, #12]
cbz w12, L_00000fc0_taken_0
movz w12, #4034
add w12, w15, w12
str w12, [x9, #60]
b L_00000fc0_success
L_00000fc0_taken_0:
movz w12, #4048
add w12, w15, w12
str w12, [x9, #60]
b L_00000fc0_success
L_00000fc0_success:
mov w0, #1
b L_00000fc0_return
L_00000fc0_fault:
mov w0, #-1
b L_00000fc0_return
L_00000fc0_miss:
mov w0, #3
b L_00000fc0_return
L_00000fc0_mode_miss:
mov w0, #4
L_00000fc0_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00000fc2
_agr_game_compiled_00000fc2:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00000fc2_mode_miss
movz w12, #4034
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #17968
cmp w14, w12
b.ne L_00000fc2_miss
movz w12, #4036
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #43265
cmp w14, w12
b.ne L_00000fc2_miss
movz w12, #4038
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #63487
movk w12, #61118, lsl #16
cmp w14, w12
b.ne L_00000fc2_miss
ldr w12, [x9, #24]
str w12, [x9, #0]
ldr w12, [x9, #52]
movz w13, #4
add w12, w12, w13
str w12, [x9, #4]
movz w12, #3396
add w12, w15, w12
movz w13, #4042
add w13, w15, w13
orr w13, w13, #1
str w13, [x9, #56]
ldr w13, [x10]
and w14, w12, #1
lsl w14, w14, #5
bic w13, w13, #0x20
orr w13, w13, w14
str w13, [x10]
bic w12, w12, #1
str w12, [x9, #60]
b L_00000fc2_success
L_00000fc2_success:
mov w0, #1
b L_00000fc2_return
L_00000fc2_fault:
mov w0, #-1
b L_00000fc2_return
L_00000fc2_miss:
mov w0, #3
b L_00000fc2_return
L_00000fc2_mode_miss:
mov w0, #4
L_00000fc2_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00000fca
_agr_game_compiled_00000fca:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00000fca_mode_miss
movz w12, #4042
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #17925
cmp w14, w12
b.ne L_00000fca_miss
movz w12, #4044
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #47445
cmp w14, w12
b.ne L_00000fca_miss
ldr w12, [x9, #0]
str w12, [x9, #20]
ldr w12, [x9, #20]
cbnz w12, L_00000fca_taken_1
movz w12, #4046
add w12, w15, w12
str w12, [x9, #60]
b L_00000fca_success
L_00000fca_taken_1:
movz w12, #4068
add w12, w15, w12
str w12, [x9, #60]
b L_00000fca_success
L_00000fca_success:
mov w0, #1
b L_00000fca_return
L_00000fca_fault:
mov w0, #-1
b L_00000fca_return
L_00000fca_miss:
mov w0, #3
b L_00000fca_return
L_00000fca_mode_miss:
mov w0, #4
L_00000fca_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00000fce
_agr_game_compiled_00000fce:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00000fce_mode_miss
movz w12, #4046
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #57359
cmp w14, w12
b.ne L_00000fce_miss
movz w12, #4080
add w12, w15, w12
str w12, [x9, #60]
b L_00000fce_success
L_00000fce_success:
mov w0, #1
b L_00000fce_return
L_00000fce_fault:
mov w0, #-1
b L_00000fce_return
L_00000fce_miss:
mov w0, #3
b L_00000fce_return
L_00000fce_mode_miss:
mov w0, #4
L_00000fce_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00000fd0
_agr_game_compiled_00000fd0:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00000fd0_mode_miss
movz w12, #4048
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #19743
cmp w14, w12
b.ne L_00000fd0_miss
movz w12, #4050
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #19232
cmp w14, w12
b.ne L_00000fd0_miss
movz w12, #4052
add w12, w15, w12
movz w13, #124
add w12, w12, w13
cmp w12, #0x1000
b.lo L_00000fd0_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w12, w13
b.hi L_00000fd0_fault
add x13, x11, w12, uxtw
ldr w12, [x13]
str w12, [x9, #20]
movz w12, #4052
add w12, w15, w12
movz w13, #128
add w12, w12, w13
cmp w12, #0x1000
b.lo L_00000fd0_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w12, w13
b.hi L_00000fd0_fault
add x13, x11, w12, uxtw
ldr w12, [x13]
str w12, [x9, #12]
movz w12, #4052
add w12, w15, w12
str w12, [x9, #60]
L_00000fd0_success:
mov w0, #1
b L_00000fd0_return
L_00000fd0_fault:
mov w0, #-1
b L_00000fd0_return
L_00000fd0_miss:
mov w0, #3
b L_00000fd0_return
L_00000fd0_mode_miss:
mov w0, #4
L_00000fd0_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00000fd6
_agr_game_compiled_00000fd6:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00000fd6_mode_miss
movz w12, #4054
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #26669
cmp w14, w12
b.ne L_00000fd6_miss
ldr w12, [x9, #20]
movz w13, #0
add w12, w12, w13
cmp w12, #0x1000
b.lo L_00000fd6_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w12, w13
b.hi L_00000fd6_fault
add x13, x11, w12, uxtw
ldr w12, [x13]
str w12, [x9, #20]
movz w12, #4056
add w12, w15, w12
str w12, [x9, #60]
L_00000fd6_success:
mov w0, #1
b L_00000fd6_return
L_00000fd6_fault:
mov w0, #-1
b L_00000fd6_return
L_00000fd6_miss:
mov w0, #3
b L_00000fd6_return
L_00000fd6_mode_miss:
mov w0, #4
L_00000fd6_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00000fda
_agr_game_compiled_00000fda:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00000fda_mode_miss
movz w12, #4058
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #26651
cmp w14, w12
b.ne L_00000fda_miss
ldr w12, [x9, #12]
movz w13, #0
add w12, w12, w13
cmp w12, #0x1000
b.lo L_00000fda_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w12, w13
b.hi L_00000fda_fault
add x13, x11, w12, uxtw
ldr w12, [x13]
str w12, [x9, #12]
movz w12, #4060
add w12, w15, w12
str w12, [x9, #60]
L_00000fda_success:
mov w0, #1
b L_00000fda_return
L_00000fda_fault:
mov w0, #-1
b L_00000fda_return
L_00000fda_miss:
mov w0, #3
b L_00000fda_return
L_00000fda_mode_miss:
mov w0, #4
L_00000fda_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00000fde
_agr_game_compiled_00000fde:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00000fde_mode_miss
movz w12, #4062
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #17944
cmp w14, w12
b.ne L_00000fde_miss
ldr w12, [x9, #12]
str w12, [x9, #0]
movz w12, #4064
add w12, w15, w12
str w12, [x9, #60]
L_00000fde_success:
mov w0, #1
b L_00000fde_return
L_00000fde_fault:
mov w0, #-1
b L_00000fde_return
L_00000fde_miss:
mov w0, #3
b L_00000fde_return
L_00000fde_mode_miss:
mov w0, #4
L_00000fde_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00000fe4
_agr_game_compiled_00000fe4:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00000fe4_mode_miss
movz w12, #4068
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #39169
cmp w14, w12
b.ne L_00000fe4_miss
movz w12, #4070
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #17970
cmp w14, w12
b.ne L_00000fe4_miss
movz w12, #4072
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #63487
movk w12, #65431, lsl #16
cmp w14, w12
b.ne L_00000fe4_miss
ldr w12, [x9, #52]
movz w13, #4
add w12, w12, w13
cmp w12, #0x1000
b.lo L_00000fe4_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w12, w13
b.hi L_00000fe4_fault
add x13, x11, w12, uxtw
ldr w12, [x13]
str w12, [x9, #4]
ldr w12, [x9, #24]
str w12, [x9, #8]
movz w12, #3866
add w12, w15, w12
orr w12, w12, #1
movz w13, #4076
add w13, w15, w13
orr w13, w13, #1
str w13, [x9, #56]
ldr w13, [x10]
and w14, w12, #1
lsl w14, w14, #5
bic w13, w13, #0x20
orr w13, w13, w14
str w13, [x10]
bic w12, w12, #1
str w12, [x9, #60]
b L_00000fe4_success
L_00000fe4_success:
mov w0, #1
b L_00000fe4_return
L_00000fe4_fault:
mov w0, #-1
b L_00000fe4_return
L_00000fe4_miss:
mov w0, #3
b L_00000fe4_return
L_00000fe4_mode_miss:
mov w0, #4
L_00000fe4_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00000fec
_agr_game_compiled_00000fec:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00000fec_mode_miss
movz w12, #4076
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #17925
cmp w14, w12
b.ne L_00000fec_miss
movz w12, #4078
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #47376
cmp w14, w12
b.ne L_00000fec_miss
ldr w12, [x9, #0]
str w12, [x9, #20]
ldr w12, [x9, #0]
cbnz w12, L_00000fec_taken_1
movz w12, #4080
add w12, w15, w12
str w12, [x9, #60]
b L_00000fec_success
L_00000fec_taken_1:
movz w12, #4086
add w12, w15, w12
str w12, [x9, #60]
b L_00000fec_success
L_00000fec_success:
mov w0, #1
b L_00000fec_return
L_00000fec_fault:
mov w0, #-1
b L_00000fec_return
L_00000fec_miss:
mov w0, #3
b L_00000fec_return
L_00000fec_mode_miss:
mov w0, #4
L_00000fec_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00000ff2
_agr_game_compiled_00000ff2:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00000ff2_mode_miss
movz w12, #4082
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #8201
cmp w14, w12
b.ne L_00000ff2_miss
movz w12, #4084
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #57383
cmp w14, w12
b.ne L_00000ff2_miss
movz w12, #9
str w12, [x9, #0]
cmp w12, #0
mrs x13, nzcv
ldr w14, [x10]
and w13, w13, #0xc0000000
and w14, w14, #0x3fffffff
orr w14, w14, w13
str w14, [x10]
movz w12, #4166
add w12, w15, w12
str w12, [x9, #60]
b L_00000ff2_success
L_00000ff2_success:
mov w0, #1
b L_00000ff2_return
L_00000ff2_fault:
mov w0, #-1
b L_00000ff2_return
L_00000ff2_miss:
mov w0, #3
b L_00000ff2_return
L_00000ff2_mode_miss:
mov w0, #4
L_00000ff2_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00000ff6
_agr_game_compiled_00000ff6:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00000ff6_mode_miss
movz w12, #4086
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #63487
movk w12, #65415, lsl #16
cmp w14, w12
b.ne L_00000ff6_miss
movz w12, #3848
add w12, w15, w12
orr w12, w12, #1
movz w13, #4090
add w13, w15, w13
orr w13, w13, #1
str w13, [x9, #56]
ldr w13, [x10]
and w14, w12, #1
lsl w14, w14, #5
bic w13, w13, #0x20
orr w13, w13, w14
str w13, [x10]
bic w12, w12, #1
str w12, [x9, #60]
b L_00000ff6_success
L_00000ff6_success:
mov w0, #1
b L_00000ff6_return
L_00000ff6_fault:
mov w0, #-1
b L_00000ff6_return
L_00000ff6_miss:
mov w0, #3
b L_00000ff6_return
L_00000ff6_mode_miss:
mov w0, #4
L_00000ff6_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00000ffa
_agr_game_compiled_00000ffa:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00000ffa_mode_miss
movz w12, #4090
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #26731
cmp w14, w12
b.ne L_00000ffa_miss
ldr w12, [x9, #20]
movz w13, #4
add w12, w12, w13
cmp w12, #0x1000
b.lo L_00000ffa_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w12, w13
b.hi L_00000ffa_fault
add x13, x11, w12, uxtw
ldr w12, [x13]
str w12, [x9, #12]
movz w12, #4092
add w12, w15, w12
str w12, [x9, #60]
L_00000ffa_success:
mov w0, #1
b L_00000ffa_return
L_00000ffa_fault:
mov w0, #-1
b L_00000ffa_return
L_00000ffa_miss:
mov w0, #3
b L_00000ffa_return
L_00000ffa_mode_miss:
mov w0, #4
L_00000ffa_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00001002
_agr_game_compiled_00001002:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00001002_mode_miss
movz w12, #4098
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #8960
cmp w14, w12
b.ne L_00001002_miss
movz w12, #4100
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #8197
cmp w14, w12
b.ne L_00001002_miss
movz w12, #0
str w12, [x9, #12]
cmp w12, #0
mrs x13, nzcv
ldr w14, [x10]
and w13, w13, #0xc0000000
and w14, w14, #0x3fffffff
orr w14, w14, w13
str w14, [x10]
movz w12, #5
str w12, [x9, #0]
cmp w12, #0
mrs x13, nzcv
ldr w14, [x10]
and w13, w13, #0xc0000000
and w14, w14, #0x3fffffff
orr w14, w14, w13
str w14, [x10]
movz w12, #4102
add w12, w15, w12
str w12, [x9, #60]
L_00001002_success:
mov w0, #1
b L_00001002_return
L_00001002_fault:
mov w0, #-1
b L_00001002_return
L_00001002_miss:
mov w0, #3
b L_00001002_return
L_00001002_mode_miss:
mov w0, #4
L_00001002_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00001008
_agr_game_compiled_00001008:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00001008_mode_miss
movz w12, #4104
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #57373
cmp w14, w12
b.ne L_00001008_miss
movz w12, #4166
add w12, w15, w12
str w12, [x9, #60]
b L_00001008_success
L_00001008_success:
mov w0, #1
b L_00001008_return
L_00001008_fault:
mov w0, #-1
b L_00001008_return
L_00001008_miss:
mov w0, #3
b L_00001008_return
L_00001008_mode_miss:
mov w0, #4
L_00001008_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_0000100c
_agr_game_compiled_0000100c:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_0000100c_mode_miss
movz w12, #4108
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #61701
movk w12, #4, lsl #16
cmp w14, w12
b.ne L_0000100c_miss
ldr w12, [x9, #20]
movz w13, #4
add w12, w12, w13
str w12, [x9, #0]
movz w12, #4112
add w12, w15, w12
str w12, [x9, #60]
L_0000100c_success:
mov w0, #1
b L_0000100c_return
L_0000100c_fault:
mov w0, #-1
b L_0000100c_return
L_0000100c_miss:
mov w0, #3
b L_0000100c_return
L_0000100c_mode_miss:
mov w0, #4
L_0000100c_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00001014
_agr_game_compiled_00001014:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00001014_mode_miss
movz w12, #4116
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #8961
cmp w14, w12
b.ne L_00001014_miss
movz w12, #4118
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #57347
cmp w14, w12
b.ne L_00001014_miss
movz w12, #1
str w12, [x9, #12]
cmp w12, #0
mrs x13, nzcv
ldr w14, [x10]
and w13, w13, #0xc0000000
and w14, w14, #0x3fffffff
orr w14, w14, w13
str w14, [x10]
movz w12, #4128
add w12, w15, w12
str w12, [x9, #60]
b L_00001014_success
L_00001014_success:
mov w0, #1
b L_00001014_return
L_00001014_fault:
mov w0, #-1
b L_00001014_return
L_00001014_miss:
mov w0, #3
b L_00001014_return
L_00001014_mode_miss:
mov w0, #4
L_00001014_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00001018
_agr_game_compiled_00001018:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00001018_mode_miss
movz w12, #4120
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #63487
movk w12, #65398, lsl #16
cmp w14, w12
b.ne L_00001018_miss
movz w12, #3848
add w12, w15, w12
orr w12, w12, #1
movz w13, #4124
add w13, w15, w13
orr w13, w13, #1
str w13, [x9, #56]
ldr w13, [x10]
and w14, w12, #1
lsl w14, w14, #5
bic w13, w13, #0x20
orr w13, w13, w14
str w13, [x10]
bic w12, w12, #1
str w12, [x9, #60]
b L_00001018_success
L_00001018_success:
mov w0, #1
b L_00001018_return
L_00001018_fault:
mov w0, #-1
b L_00001018_return
L_00001018_miss:
mov w0, #3
b L_00001018_return
L_00001018_mode_miss:
mov w0, #4
L_00001018_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_0000101c
_agr_game_compiled_0000101c:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_0000101c_mode_miss
movz w12, #4124
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #8960
cmp w14, w12
b.ne L_0000101c_miss
movz w12, #0
str w12, [x9, #12]
cmp w12, #0
mrs x13, nzcv
ldr w14, [x10]
and w13, w13, #0xc0000000
and w14, w14, #0x3fffffff
orr w14, w14, w13
str w14, [x10]
movz w12, #4126
add w12, w15, w12
str w12, [x9, #60]
L_0000101c_success:
mov w0, #1
b L_0000101c_return
L_0000101c_fault:
mov w0, #-1
b L_0000101c_return
L_0000101c_miss:
mov w0, #3
b L_0000101c_return
L_0000101c_mode_miss:
mov w0, #4
L_0000101c_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00001020
_agr_game_compiled_00001020:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00001020_mode_miss
movz w12, #4128
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #27872
cmp w14, w12
b.ne L_00001020_miss
ldr w12, [x9, #16]
movz w13, #76
add w12, w12, w13
cmp w12, #0x1000
b.lo L_00001020_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w12, w13
b.hi L_00001020_fault
add x13, x11, w12, uxtw
ldr w12, [x13]
str w12, [x9, #0]
movz w12, #4130
add w12, w15, w12
str w12, [x9, #60]
L_00001020_success:
mov w0, #1
b L_00001020_return
L_00001020_fault:
mov w0, #-1
b L_00001020_return
L_00001020_miss:
mov w0, #3
b L_00001020_return
L_00001020_mode_miss:
mov w0, #4
L_00001020_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00001024
_agr_game_compiled_00001024:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00001024_mode_miss
movz w12, #4132
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #26627
cmp w14, w12
b.ne L_00001024_miss
ldr w12, [x9, #0]
movz w13, #0
add w12, w12, w13
cmp w12, #0x1000
b.lo L_00001024_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w12, w13
b.hi L_00001024_fault
add x13, x11, w12, uxtw
ldr w12, [x13]
str w12, [x9, #12]
movz w12, #4134
add w12, w15, w12
str w12, [x9, #60]
L_00001024_success:
mov w0, #1
b L_00001024_return
L_00001024_fault:
mov w0, #-1
b L_00001024_return
L_00001024_miss:
mov w0, #3
b L_00001024_return
L_00001024_mode_miss:
mov w0, #4
L_00001024_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_0000102e
_agr_game_compiled_0000102e:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_0000102e_mode_miss
movz w12, #4142
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #63487
movk w12, #65448, lsl #16
cmp w14, w12
b.ne L_0000102e_miss
movz w12, #3970
add w12, w15, w12
orr w12, w12, #1
movz w13, #4146
add w13, w15, w13
orr w13, w13, #1
str w13, [x9, #56]
ldr w13, [x10]
and w14, w12, #1
lsl w14, w14, #5
bic w13, w13, #0x20
orr w13, w13, w14
str w13, [x10]
bic w12, w12, #1
str w12, [x9, #60]
b L_0000102e_success
L_0000102e_success:
mov w0, #1
b L_0000102e_return
L_0000102e_fault:
mov w0, #-1
b L_0000102e_return
L_0000102e_miss:
mov w0, #3
b L_0000102e_return
L_0000102e_mode_miss:
mov w0, #4
L_0000102e_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_0000103e
_agr_game_compiled_0000103e:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_0000103e_mode_miss
movz w12, #4158
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #63487
movk w12, #65379, lsl #16
cmp w14, w12
b.ne L_0000103e_miss
movz w12, #3848
add w12, w15, w12
orr w12, w12, #1
movz w13, #4162
add w13, w15, w13
orr w13, w13, #1
str w13, [x9, #56]
ldr w13, [x10]
and w14, w12, #1
lsl w14, w14, #5
bic w13, w13, #0x20
orr w13, w13, w14
str w13, [x10]
bic w12, w12, #1
str w12, [x9, #60]
b L_0000103e_success
L_0000103e_success:
mov w0, #1
b L_0000103e_return
L_0000103e_fault:
mov w0, #-1
b L_0000103e_return
L_0000103e_miss:
mov w0, #3
b L_0000103e_return
L_0000103e_mode_miss:
mov w0, #4
L_0000103e_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00001044
_agr_game_compiled_00001044:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00001044_mode_miss
movz w12, #4164
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #8192
cmp w14, w12
b.ne L_00001044_miss
movz w12, #0
str w12, [x9, #0]
cmp w12, #0
mrs x13, nzcv
ldr w14, [x10]
and w13, w13, #0xc0000000
and w14, w14, #0x3fffffff
orr w14, w14, w13
str w14, [x10]
movz w12, #4166
add w12, w15, w12
str w12, [x9, #60]
L_00001044_success:
mov w0, #1
b L_00001044_return
L_00001044_fault:
mov w0, #-1
b L_00001044_return
L_00001044_miss:
mov w0, #3
b L_00001044_return
L_00001044_mode_miss:
mov w0, #4
L_00001044_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00001048
_agr_game_compiled_00001048:
sub sp, sp, #64
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00001048_mode_miss
movz w12, #4168
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #48496
cmp w14, w12
b.ne L_00001048_miss
ldr w12, [x9, #52]
movz w13, #0
add w14, w12, w13
cmp w14, #0x1000
b.lo L_00001048_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w14, w13
b.hi L_00001048_fault
add x13, x11, w14, uxtw
ldr w14, [x13]
str w14, [sp, #0]
movz w13, #4
add w14, w12, w13
cmp w14, #0x1000
b.lo L_00001048_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w14, w13
b.hi L_00001048_fault
add x13, x11, w14, uxtw
ldr w14, [x13]
str w14, [sp, #4]
movz w13, #8
add w14, w12, w13
cmp w14, #0x1000
b.lo L_00001048_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w14, w13
b.hi L_00001048_fault
add x13, x11, w14, uxtw
ldr w14, [x13]
str w14, [sp, #8]
movz w13, #12
add w14, w12, w13
cmp w14, #0x1000
b.lo L_00001048_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w14, w13
b.hi L_00001048_fault
add x13, x11, w14, uxtw
ldr w14, [x13]
str w14, [sp, #12]
movz w13, #16
add w12, w12, w13
str w12, [x9, #52]
ldr w12, [sp, #0]
str w12, [x9, #16]
ldr w12, [sp, #4]
str w12, [x9, #20]
ldr w12, [sp, #8]
str w12, [x9, #24]
ldr w12, [sp, #12]
str w12, [x9, #60]
ldr w12, [x9, #60]
ldr w13, [x10]
and w14, w12, #1
lsl w14, w14, #5
bic w13, w13, #0x20
orr w13, w13, w14
str w13, [x10]
bic w12, w12, #1
str w12, [x9, #60]
b L_00001048_success
L_00001048_success:
mov w0, #1
b L_00001048_return
L_00001048_fault:
mov w0, #-1
b L_00001048_return
L_00001048_miss:
mov w0, #3
b L_00001048_return
L_00001048_mode_miss:
mov w0, #4
L_00001048_return:
add sp, sp, #64
ret

.text
.p2align 2
.globl _agr_game_compiled_00001058
_agr_game_compiled_00001058:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00001058_mode_miss
movz w12, #4184
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #26627
cmp w14, w12
b.ne L_00001058_miss
movz w12, #4186
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #46352
cmp w14, w12
b.ne L_00001058_miss
movz w12, #4188
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #17924
cmp w14, w12
b.ne L_00001058_miss
ldr w12, [x9, #0]
movz w13, #0
add w12, w12, w13
cmp w12, #0x1000
b.lo L_00001058_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w12, w13
b.hi L_00001058_fault
add x13, x11, w12, uxtw
ldr w12, [x13]
str w12, [x9, #12]
ldr w12, [x9, #52]
movz w13, #8
sub w12, w12, w13
cmp w12, #0x1000
b.lo L_00001058_fault
add x13, x11, w12, uxtw
ldr w14, [x9, #16]
str w14, [x13, #0]
ldr w14, [x9, #56]
str w14, [x13, #4]
str w12, [x9, #52]
ldr w12, [x9, #0]
str w12, [x9, #16]
movz w12, #4190
add w12, w15, w12
str w12, [x9, #60]
L_00001058_success:
mov w0, #1
b L_00001058_return
L_00001058_fault:
mov w0, #-1
b L_00001058_return
L_00001058_miss:
mov w0, #3
b L_00001058_return
L_00001058_mode_miss:
mov w0, #4
L_00001058_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00001066
_agr_game_compiled_00001066:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00001066_mode_miss
movz w12, #4198
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #61700
movk w12, #72, lsl #16
cmp w14, w12
b.ne L_00001066_miss
ldr w12, [x9, #16]
movz w13, #72
add w12, w12, w13
str w12, [x9, #0]
movz w12, #4202
add w12, w15, w12
str w12, [x9, #60]
L_00001066_success:
mov w0, #1
b L_00001066_return
L_00001066_fault:
mov w0, #-1
b L_00001066_return
L_00001066_miss:
mov w0, #3
b L_00001066_return
L_00001066_mode_miss:
mov w0, #4
L_00001066_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_0000106c
_agr_game_compiled_0000106c:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_0000106c_mode_miss
movz w12, #4204
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #61440
movk w12, #64514, lsl #16
cmp w14, w12
b.ne L_0000106c_miss
movz w12, #6260
add w12, w15, w12
orr w12, w12, #1
movz w13, #4208
add w13, w15, w13
orr w13, w13, #1
str w13, [x9, #56]
ldr w13, [x10]
and w14, w12, #1
lsl w14, w14, #5
bic w13, w13, #0x20
orr w13, w13, w14
str w13, [x10]
bic w12, w12, #1
str w12, [x9, #60]
b L_0000106c_success
L_0000106c_success:
mov w0, #1
b L_0000106c_return
L_0000106c_fault:
mov w0, #-1
b L_0000106c_return
L_0000106c_miss:
mov w0, #3
b L_0000106c_return
L_0000106c_mode_miss:
mov w0, #4
L_0000106c_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00001070
_agr_game_compiled_00001070:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00001070_mode_miss
movz w12, #4208
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #57345
cmp w14, w12
b.ne L_00001070_miss
movz w12, #4214
add w12, w15, w12
str w12, [x9, #60]
b L_00001070_success
L_00001070_success:
mov w0, #1
b L_00001070_return
L_00001070_fault:
mov w0, #-1
b L_00001070_return
L_00001070_miss:
mov w0, #3
b L_00001070_return
L_00001070_mode_miss:
mov w0, #4
L_00001070_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00001072
_agr_game_compiled_00001072:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00001072_mode_miss
movz w12, #4210
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #61440
movk w12, #64503, lsl #16
cmp w14, w12
b.ne L_00001072_miss
movz w12, #6244
add w12, w15, w12
orr w12, w12, #1
movz w13, #4214
add w13, w15, w13
orr w13, w13, #1
str w13, [x9, #56]
ldr w13, [x10]
and w14, w12, #1
lsl w14, w14, #5
bic w13, w13, #0x20
orr w13, w13, w14
str w13, [x10]
bic w12, w12, #1
str w12, [x9, #60]
b L_00001072_success
L_00001072_success:
mov w0, #1
b L_00001072_return
L_00001072_fault:
mov w0, #-1
b L_00001072_return
L_00001072_miss:
mov w0, #3
b L_00001072_return
L_00001072_mode_miss:
mov w0, #4
L_00001072_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00001076
_agr_game_compiled_00001076:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00001076_mode_miss
movz w12, #4214
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #26659
cmp w14, w12
b.ne L_00001076_miss
ldr w12, [x9, #16]
movz w13, #0
add w12, w12, w13
cmp w12, #0x1000
b.lo L_00001076_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w12, w13
b.hi L_00001076_fault
add x13, x11, w12, uxtw
ldr w12, [x13]
str w12, [x9, #12]
movz w12, #4216
add w12, w15, w12
str w12, [x9, #60]
L_00001076_success:
mov w0, #1
b L_00001076_return
L_00001076_fault:
mov w0, #-1
b L_00001076_return
L_00001076_miss:
mov w0, #3
b L_00001076_return
L_00001076_mode_miss:
mov w0, #4
L_00001076_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_0000107c
_agr_game_compiled_0000107c:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_0000107c_mode_miss
movz w12, #4220
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #61700
movk w12, #208, lsl #16
cmp w14, w12
b.ne L_0000107c_miss
movz w12, #4224
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #61440
movk w12, #64512, lsl #16
cmp w14, w12
b.ne L_0000107c_miss
ldr w12, [x9, #16]
movz w13, #208
add w12, w12, w13
str w12, [x9, #0]
movz w12, #6276
add w12, w15, w12
orr w12, w12, #1
movz w13, #4228
add w13, w15, w13
orr w13, w13, #1
str w13, [x9, #56]
ldr w13, [x10]
and w14, w12, #1
lsl w14, w14, #5
bic w13, w13, #0x20
orr w13, w13, w14
str w13, [x10]
bic w12, w12, #1
str w12, [x9, #60]
b L_0000107c_success
L_0000107c_success:
mov w0, #1
b L_0000107c_return
L_0000107c_fault:
mov w0, #-1
b L_0000107c_return
L_0000107c_miss:
mov w0, #3
b L_0000107c_return
L_0000107c_mode_miss:
mov w0, #4
L_0000107c_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00001084
_agr_game_compiled_00001084:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00001084_mode_miss
movz w12, #4228
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #26659
cmp w14, w12
b.ne L_00001084_miss
ldr w12, [x9, #16]
movz w13, #0
add w12, w12, w13
cmp w12, #0x1000
b.lo L_00001084_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w12, w13
b.hi L_00001084_fault
add x13, x11, w12, uxtw
ldr w12, [x13]
str w12, [x9, #12]
movz w12, #4230
add w12, w15, w12
str w12, [x9, #60]
L_00001084_success:
mov w0, #1
b L_00001084_return
L_00001084_fault:
mov w0, #-1
b L_00001084_return
L_00001084_miss:
mov w0, #3
b L_00001084_return
L_00001084_mode_miss:
mov w0, #4
L_00001084_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_0000108a
_agr_game_compiled_0000108a:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_0000108a_mode_miss
movz w12, #4234
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #62724
movk w12, #28840, lsl #16
cmp w14, w12
b.ne L_0000108a_miss
movz w12, #4238
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #61440
movk w12, #64513, lsl #16
cmp w14, w12
b.ne L_0000108a_miss
ldr w12, [x9, #16]
movz w13, #4008
add w12, w12, w13
str w12, [x9, #0]
movz w12, #6292
add w12, w15, w12
orr w12, w12, #1
movz w13, #4242
add w13, w15, w13
orr w13, w13, #1
str w13, [x9, #56]
ldr w13, [x10]
and w14, w12, #1
lsl w14, w14, #5
bic w13, w13, #0x20
orr w13, w13, w14
str w13, [x10]
bic w12, w12, #1
str w12, [x9, #60]
b L_0000108a_success
L_0000108a_success:
mov w0, #1
b L_0000108a_return
L_0000108a_fault:
mov w0, #-1
b L_0000108a_return
L_0000108a_miss:
mov w0, #3
b L_0000108a_return
L_0000108a_mode_miss:
mov w0, #4
L_0000108a_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00001092
_agr_game_compiled_00001092:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00001092_mode_miss
movz w12, #4242
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #26659
cmp w14, w12
b.ne L_00001092_miss
ldr w12, [x9, #16]
movz w13, #0
add w12, w12, w13
cmp w12, #0x1000
b.lo L_00001092_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w12, w13
b.hi L_00001092_fault
add x13, x11, w12, uxtw
ldr w12, [x13]
str w12, [x9, #12]
movz w12, #4244
add w12, w15, w12
str w12, [x9, #60]
L_00001092_success:
mov w0, #1
b L_00001092_return
L_00001092_fault:
mov w0, #-1
b L_00001092_return
L_00001092_miss:
mov w0, #3
b L_00001092_return
L_00001092_mode_miss:
mov w0, #4
L_00001092_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00001098
_agr_game_compiled_00001098:
sub sp, sp, #64
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00001098_mode_miss
movz w12, #4248
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #62724
movk w12, #28904, lsl #16
cmp w14, w12
b.ne L_00001098_miss
movz w12, #4252
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #59581
movk w12, #16400, lsl #16
cmp w14, w12
b.ne L_00001098_miss
movz w12, #4256
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #61440
movk w12, #48188, lsl #16
cmp w14, w12
b.ne L_00001098_miss
ldr w12, [x9, #16]
movz w13, #4072
add w12, w12, w13
str w12, [x9, #0]
ldr w12, [x9, #52]
movz w13, #0
add w14, w12, w13
cmp w14, #0x1000
b.lo L_00001098_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w14, w13
b.hi L_00001098_fault
add x13, x11, w14, uxtw
ldr w14, [x13]
str w14, [sp, #0]
movz w13, #4
add w14, w12, w13
cmp w14, #0x1000
b.lo L_00001098_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w14, w13
b.hi L_00001098_fault
add x13, x11, w14, uxtw
ldr w14, [x13]
str w14, [sp, #4]
movz w13, #8
add w12, w12, w13
str w12, [x9, #52]
ldr w12, [sp, #0]
str w12, [x9, #16]
ldr w12, [sp, #4]
str w12, [x9, #56]
movz w12, #6428
add w12, w15, w12
str w12, [x9, #60]
b L_00001098_success
L_00001098_success:
mov w0, #1
b L_00001098_return
L_00001098_fault:
mov w0, #-1
b L_00001098_return
L_00001098_miss:
mov w0, #3
b L_00001098_return
L_00001098_mode_miss:
mov w0, #4
L_00001098_return:
add sp, sp, #64
ret

.text
.p2align 2
.globl _agr_game_compiled_000010a4
_agr_game_compiled_000010a4:
sub sp, sp, #64
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_000010a4_mode_miss
movz w12, #4260
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #48400
cmp w14, w12
b.ne L_000010a4_miss
ldr w12, [x9, #52]
movz w13, #0
add w14, w12, w13
cmp w14, #0x1000
b.lo L_000010a4_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w14, w13
b.hi L_000010a4_fault
add x13, x11, w14, uxtw
ldr w14, [x13]
str w14, [sp, #0]
movz w13, #4
add w14, w12, w13
cmp w14, #0x1000
b.lo L_000010a4_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w14, w13
b.hi L_000010a4_fault
add x13, x11, w14, uxtw
ldr w14, [x13]
str w14, [sp, #4]
movz w13, #8
add w12, w12, w13
str w12, [x9, #52]
ldr w12, [sp, #0]
str w12, [x9, #16]
ldr w12, [sp, #4]
str w12, [x9, #60]
ldr w12, [x9, #60]
ldr w13, [x10]
and w14, w12, #1
lsl w14, w14, #5
bic w13, w13, #0x20
orr w13, w13, w14
str w13, [x10]
bic w12, w12, #1
str w12, [x9, #60]
b L_000010a4_success
L_000010a4_success:
mov w0, #1
b L_000010a4_return
L_000010a4_fault:
mov w0, #-1
b L_000010a4_return
L_000010a4_miss:
mov w0, #3
b L_000010a4_return
L_000010a4_mode_miss:
mov w0, #4
L_000010a4_return:
add sp, sp, #64
ret

.text
.p2align 2
.globl _agr_game_compiled_000010a6
_agr_game_compiled_000010a6:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_000010a6_mode_miss
movz w12, #4262
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #26627
cmp w14, w12
b.ne L_000010a6_miss
movz w12, #4264
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #45323
cmp w14, w12
b.ne L_000010a6_miss
ldr w12, [x9, #0]
movz w13, #0
add w12, w12, w13
cmp w12, #0x1000
b.lo L_000010a6_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w12, w13
b.hi L_000010a6_fault
add x13, x11, w12, uxtw
ldr w12, [x13]
str w12, [x9, #12]
ldr w12, [x9, #12]
cbz w12, L_000010a6_taken_1
movz w12, #4266
add w12, w15, w12
str w12, [x9, #60]
b L_000010a6_success
L_000010a6_taken_1:
movz w12, #4270
add w12, w15, w12
str w12, [x9, #60]
b L_000010a6_success
L_000010a6_success:
mov w0, #1
b L_000010a6_return
L_000010a6_fault:
mov w0, #-1
b L_000010a6_return
L_000010a6_miss:
mov w0, #3
b L_000010a6_return
L_000010a6_mode_miss:
mov w0, #4
L_000010a6_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_000010ac
_agr_game_compiled_000010ac:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_000010ac_mode_miss
movz w12, #4268
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #18288
cmp w14, w12
b.ne L_000010ac_miss
ldr w12, [x9, #56]
ldr w13, [x10]
and w14, w12, #1
lsl w14, w14, #5
bic w13, w13, #0x20
orr w13, w13, w14
str w13, [x10]
bic w12, w12, #1
str w12, [x9, #60]
b L_000010ac_success
L_000010ac_success:
mov w0, #1
b L_000010ac_return
L_000010ac_fault:
mov w0, #-1
b L_000010ac_return
L_000010ac_miss:
mov w0, #3
b L_000010ac_return
L_000010ac_mode_miss:
mov w0, #4
L_000010ac_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_000010ae
_agr_game_compiled_000010ae:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_000010ae_mode_miss
movz w12, #4270
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #17944
cmp w14, w12
b.ne L_000010ae_miss
movz w12, #4272
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #18288
cmp w14, w12
b.ne L_000010ae_miss
ldr w12, [x9, #12]
str w12, [x9, #0]
ldr w12, [x9, #56]
ldr w13, [x10]
and w14, w12, #1
lsl w14, w14, #5
bic w13, w13, #0x20
orr w13, w13, w14
str w13, [x10]
bic w12, w12, #1
str w12, [x9, #60]
b L_000010ae_success
L_000010ae_success:
mov w0, #1
b L_000010ae_return
L_000010ae_fault:
mov w0, #-1
b L_000010ae_return
L_000010ae_miss:
mov w0, #3
b L_000010ae_return
L_000010ae_mode_miss:
mov w0, #4
L_000010ae_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_000010b2
_agr_game_compiled_000010b2:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_000010b2_mode_miss
movz w12, #4274
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #8201
cmp w14, w12
b.ne L_000010b2_miss
movz w12, #4276
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #18288
cmp w14, w12
b.ne L_000010b2_miss
movz w12, #9
str w12, [x9, #0]
cmp w12, #0
mrs x13, nzcv
ldr w14, [x10]
and w13, w13, #0xc0000000
and w14, w14, #0x3fffffff
orr w14, w14, w13
str w14, [x10]
ldr w12, [x9, #56]
ldr w13, [x10]
and w14, w12, #1
lsl w14, w14, #5
bic w13, w13, #0x20
orr w13, w13, w14
str w13, [x10]
bic w12, w12, #1
str w12, [x9, #60]
b L_000010b2_success
L_000010b2_success:
mov w0, #1
b L_000010b2_return
L_000010b2_fault:
mov w0, #-1
b L_000010b2_return
L_000010b2_miss:
mov w0, #3
b L_000010b2_return
L_000010b2_mode_miss:
mov w0, #4
L_000010b2_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_000010b6
_agr_game_compiled_000010b6:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_000010b6_mode_miss
movz w12, #4278
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #18288
cmp w14, w12
b.ne L_000010b6_miss
ldr w12, [x9, #56]
ldr w13, [x10]
and w14, w12, #1
lsl w14, w14, #5
bic w13, w13, #0x20
orr w13, w13, w14
str w13, [x10]
bic w12, w12, #1
str w12, [x9, #60]
b L_000010b6_success
L_000010b6_success:
mov w0, #1
b L_000010b6_return
L_000010b6_fault:
mov w0, #-1
b L_000010b6_return
L_000010b6_miss:
mov w0, #3
b L_000010b6_return
L_000010b6_mode_miss:
mov w0, #4
L_000010b6_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_000010b8
_agr_game_compiled_000010b8:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_000010b8_mode_miss
movz w12, #4280
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #46448
cmp w14, w12
b.ne L_000010b8_miss
movz w12, #4282
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #17925
cmp w14, w12
b.ne L_000010b8_miss
movz w12, #4284
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #17932
cmp w14, w12
b.ne L_000010b8_miss
ldr w12, [x9, #52]
movz w13, #16
sub w12, w12, w13
cmp w12, #0x1000
b.lo L_000010b8_fault
add x13, x11, w12, uxtw
ldr w14, [x9, #16]
str w14, [x13, #0]
ldr w14, [x9, #20]
str w14, [x13, #4]
ldr w14, [x9, #24]
str w14, [x13, #8]
ldr w14, [x9, #56]
str w14, [x13, #12]
str w12, [x9, #52]
ldr w12, [x9, #0]
str w12, [x9, #20]
ldr w12, [x9, #4]
str w12, [x9, #16]
movz w12, #4286
add w12, w15, w12
str w12, [x9, #60]
L_000010b8_success:
mov w0, #1
b L_000010b8_return
L_000010b8_fault:
mov w0, #-1
b L_000010b8_return
L_000010b8_miss:
mov w0, #3
b L_000010b8_return
L_000010b8_mode_miss:
mov w0, #4
L_000010b8_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_000010be
_agr_game_compiled_000010be:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_000010be_mode_miss
movz w12, #4286
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #17960
cmp w14, w12
b.ne L_000010be_miss
movz w12, #4288
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #27681
cmp w14, w12
b.ne L_000010be_miss
movz w12, #4290
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #63487
movk w12, #65399, lsl #16
cmp w14, w12
b.ne L_000010be_miss
ldr w12, [x9, #20]
str w12, [x9, #0]
ldr w12, [x9, #16]
movz w13, #64
add w12, w12, w13
cmp w12, #0x1000
b.lo L_000010be_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w12, w13
b.hi L_000010be_fault
add x13, x11, w12, uxtw
ldr w12, [x13]
str w12, [x9, #4]
movz w12, #4020
add w12, w15, w12
orr w12, w12, #1
movz w13, #4294
add w13, w15, w13
orr w13, w13, #1
str w13, [x9, #56]
ldr w13, [x10]
and w14, w12, #1
lsl w14, w14, #5
bic w13, w13, #0x20
orr w13, w13, w14
str w13, [x10]
bic w12, w12, #1
str w12, [x9, #60]
b L_000010be_success
L_000010be_success:
mov w0, #1
b L_000010be_return
L_000010be_fault:
mov w0, #-1
b L_000010be_return
L_000010be_miss:
mov w0, #3
b L_000010be_return
L_000010be_mode_miss:
mov w0, #4
L_000010be_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_000010c6
_agr_game_compiled_000010c6:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_000010c6_mode_miss
movz w12, #4294
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #17926
cmp w14, w12
b.ne L_000010c6_miss
movz w12, #4296
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #45320
cmp w14, w12
b.ne L_000010c6_miss
ldr w12, [x9, #0]
str w12, [x9, #24]
ldr w12, [x9, #0]
cbz w12, L_000010c6_taken_1
movz w12, #4298
add w12, w15, w12
str w12, [x9, #60]
b L_000010c6_success
L_000010c6_taken_1:
movz w12, #4302
add w12, w15, w12
str w12, [x9, #60]
b L_000010c6_success
L_000010c6_success:
mov w0, #1
b L_000010c6_return
L_000010c6_fault:
mov w0, #-1
b L_000010c6_return
L_000010c6_miss:
mov w0, #3
b L_000010c6_return
L_000010c6_mode_miss:
mov w0, #4
L_000010c6_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_000010ca
_agr_game_compiled_000010ca:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_000010ca_mode_miss
movz w12, #4298
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #63487
movk w12, #60994, lsl #16
cmp w14, w12
b.ne L_000010ca_miss
movz w12, #3408
add w12, w15, w12
movz w13, #4302
add w13, w15, w13
orr w13, w13, #1
str w13, [x9, #56]
ldr w13, [x10]
and w14, w12, #1
lsl w14, w14, #5
bic w13, w13, #0x20
orr w13, w13, w14
str w13, [x10]
bic w12, w12, #1
str w12, [x9, #60]
b L_000010ca_success
L_000010ca_success:
mov w0, #1
b L_000010ca_return
L_000010ca_fault:
mov w0, #-1
b L_000010ca_return
L_000010ca_miss:
mov w0, #3
b L_000010ca_return
L_000010ca_mode_miss:
mov w0, #4
L_000010ca_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_000010ce
_agr_game_compiled_000010ce:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_000010ce_mode_miss
movz w12, #4302
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #27683
cmp w14, w12
b.ne L_000010ce_miss
movz w12, #4304
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #8193
cmp w14, w12
b.ne L_000010ce_miss
movz w12, #4306
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #17961
cmp w14, w12
b.ne L_000010ce_miss
movz w12, #4308
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #17954
cmp w14, w12
b.ne L_000010ce_miss
ldr w12, [x9, #16]
movz w13, #64
add w12, w12, w13
cmp w12, #0x1000
b.lo L_000010ce_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w12, w13
b.hi L_000010ce_fault
add x13, x11, w12, uxtw
ldr w12, [x13]
str w12, [x9, #12]
movz w12, #1
str w12, [x9, #0]
cmp w12, #0
mrs x13, nzcv
ldr w14, [x10]
and w13, w13, #0xc0000000
and w14, w14, #0x3fffffff
orr w14, w14, w13
str w14, [x10]
ldr w12, [x9, #20]
str w12, [x9, #4]
ldr w12, [x9, #16]
str w12, [x9, #8]
movz w12, #4310
add w12, w15, w12
str w12, [x9, #60]
L_000010ce_success:
mov w0, #1
b L_000010ce_return
L_000010ce_fault:
mov w0, #-1
b L_000010ce_return
L_000010ce_miss:
mov w0, #3
b L_000010ce_return
L_000010ce_mode_miss:
mov w0, #4
L_000010ce_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_000010d8
_agr_game_compiled_000010d8:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_000010d8_mode_miss
movz w12, #4312
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #26923
cmp w14, w12
b.ne L_000010d8_miss
movz w12, #4314
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #18328
cmp w14, w12
b.ne L_000010d8_miss
ldr w12, [x9, #20]
movz w13, #16
add w12, w12, w13
cmp w12, #0x1000
b.lo L_000010d8_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w12, w13
b.hi L_000010d8_fault
add x13, x11, w12, uxtw
ldr w12, [x13]
str w12, [x9, #12]
ldr w12, [x9, #12]
movz w13, #4316
add w13, w15, w13
orr w13, w13, #1
str w13, [x9, #56]
ldr w13, [x10]
and w14, w12, #1
lsl w14, w14, #5
bic w13, w13, #0x20
orr w13, w13, w14
str w13, [x10]
bic w12, w12, #1
str w12, [x9, #60]
b L_000010d8_success
L_000010d8_success:
mov w0, #1
b L_000010d8_return
L_000010d8_fault:
mov w0, #-1
b L_000010d8_return
L_000010d8_miss:
mov w0, #3
b L_000010d8_return
L_000010d8_mode_miss:
mov w0, #4
L_000010d8_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_000010e4
_agr_game_compiled_000010e4:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_000010e4_mode_miss
movz w12, #4324
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #17968
cmp w14, w12
b.ne L_000010e4_miss
movz w12, #4326
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #27681
cmp w14, w12
b.ne L_000010e4_miss
movz w12, #4328
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #63487
movk w12, #65509, lsl #16
cmp w14, w12
b.ne L_000010e4_miss
ldr w12, [x9, #24]
str w12, [x9, #0]
ldr w12, [x9, #16]
movz w13, #64
add w12, w12, w13
cmp w12, #0x1000
b.lo L_000010e4_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w12, w13
b.hi L_000010e4_fault
add x13, x11, w12, uxtw
ldr w12, [x13]
str w12, [x9, #4]
movz w12, #4278
add w12, w15, w12
orr w12, w12, #1
movz w13, #4332
add w13, w15, w13
orr w13, w13, #1
str w13, [x9, #56]
ldr w13, [x10]
and w14, w12, #1
lsl w14, w14, #5
bic w13, w13, #0x20
orr w13, w13, w14
str w13, [x10]
bic w12, w12, #1
str w12, [x9, #60]
b L_000010e4_success
L_000010e4_success:
mov w0, #1
b L_000010e4_return
L_000010e4_fault:
mov w0, #-1
b L_000010e4_return
L_000010e4_miss:
mov w0, #3
b L_000010e4_return
L_000010e4_mode_miss:
mov w0, #4
L_000010e4_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_000010ee
_agr_game_compiled_000010ee:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_000010ee_mode_miss
movz w12, #4334
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #61440
movk w12, #64429, lsl #16
cmp w14, w12
b.ne L_000010ee_miss
movz w12, #6220
add w12, w15, w12
orr w12, w12, #1
movz w13, #4338
add w13, w15, w13
orr w13, w13, #1
str w13, [x9, #56]
ldr w13, [x10]
and w14, w12, #1
lsl w14, w14, #5
bic w13, w13, #0x20
orr w13, w13, w14
str w13, [x10]
bic w12, w12, #1
str w12, [x9, #60]
b L_000010ee_success
L_000010ee_success:
mov w0, #1
b L_000010ee_return
L_000010ee_fault:
mov w0, #-1
b L_000010ee_return
L_000010ee_miss:
mov w0, #3
b L_000010ee_return
L_000010ee_mode_miss:
mov w0, #4
L_000010ee_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_000010f2
_agr_game_compiled_000010f2:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_000010f2_mode_miss
movz w12, #4338
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #59693
movk w12, #20464, lsl #16
cmp w14, w12
b.ne L_000010f2_miss
ldr w12, [x9, #52]
movz w13, #36
sub w12, w12, w13
cmp w12, #0x1000
b.lo L_000010f2_fault
add x13, x11, w12, uxtw
ldr w14, [x9, #16]
str w14, [x13, #0]
ldr w14, [x9, #20]
str w14, [x13, #4]
ldr w14, [x9, #24]
str w14, [x13, #8]
ldr w14, [x9, #28]
str w14, [x13, #12]
ldr w14, [x9, #32]
str w14, [x13, #16]
ldr w14, [x9, #36]
str w14, [x13, #20]
ldr w14, [x9, #40]
str w14, [x13, #24]
ldr w14, [x9, #44]
str w14, [x13, #28]
ldr w14, [x9, #56]
str w14, [x13, #32]
str w12, [x9, #52]
movz w12, #4342
add w12, w15, w12
str w12, [x9, #60]
L_000010f2_success:
mov w0, #1
b L_000010f2_return
L_000010f2_fault:
mov w0, #-1
b L_000010f2_return
L_000010f2_miss:
mov w0, #3
b L_000010f2_return
L_000010f2_mode_miss:
mov w0, #4
L_000010f2_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_000010f8
_agr_game_compiled_000010f8:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_000010f8_mode_miss
movz w12, #4344
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #63696
movk w12, #32780, lsl #16
cmp w14, w12
b.ne L_000010f8_miss
movz w12, #4348
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #17927
cmp w14, w12
b.ne L_000010f8_miss
movz w12, #4350
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #63696
movk w12, #36888, lsl #16
cmp w14, w12
b.ne L_000010f8_miss
movz w12, #4354
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #18066
cmp w14, w12
b.ne L_000010f8_miss
ldr w12, [x9, #0]
movz w13, #12
add w12, w12, w13
cmp w12, #0x1000
b.lo L_000010f8_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w12, w13
b.hi L_000010f8_fault
add x13, x11, w12, uxtw
ldr w12, [x13]
str w12, [x9, #32]
ldr w12, [x9, #0]
str w12, [x9, #28]
ldr w12, [x9, #0]
movz w13, #24
add w12, w12, w13
cmp w12, #0x1000
b.lo L_000010f8_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w12, w13
b.hi L_000010f8_fault
add x13, x11, w12, uxtw
ldr w12, [x13]
str w12, [x9, #36]
ldr w12, [x9, #8]
str w12, [x9, #40]
movz w12, #4356
add w12, w15, w12
str w12, [x9, #60]
L_000010f8_success:
mov w0, #1
b L_000010f8_return
L_000010f8_fault:
mov w0, #-1
b L_000010f8_return
L_000010f8_miss:
mov w0, #3
b L_000010f8_return
L_000010f8_mode_miss:
mov w0, #4
L_000010f8_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_0000110a
_agr_game_compiled_0000110a:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_0000110a_mode_miss
movz w12, #4362
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #44035
cmp w14, w12
b.ne L_0000110a_miss
movz w12, #4364
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #44546
cmp w14, w12
b.ne L_0000110a_miss
ldr w12, [x9, #52]
movz w13, #12
add w12, w12, w13
str w12, [x9, #16]
ldr w12, [x9, #52]
movz w13, #8
add w12, w12, w13
str w12, [x9, #24]
movz w12, #4366
add w12, w15, w12
str w12, [x9, #60]
L_0000110a_success:
mov w0, #1
b L_0000110a_return
L_0000110a_fault:
mov w0, #-1
b L_0000110a_return
L_0000110a_miss:
mov w0, #3
b L_0000110a_return
L_0000110a_mode_miss:
mov w0, #4
L_0000110a_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_0000111c
_agr_game_compiled_0000111c:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_0000111c_mode_miss
movz w12, #4380
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #44410
cmp w14, w12
b.ne L_0000111c_miss
ldr w12, [x9, #52]
movz w13, #488
add w12, w12, w13
str w12, [x9, #20]
movz w12, #4382
add w12, w15, w12
str w12, [x9, #60]
L_0000111c_success:
mov w0, #1
b L_0000111c_return
L_0000111c_fault:
mov w0, #-1
b L_0000111c_return
L_0000111c_miss:
mov w0, #3
b L_0000111c_return
L_0000111c_mode_miss:
mov w0, #4
L_0000111c_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00001122
_agr_game_compiled_00001122:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00001122_mode_miss
movz w12, #4386
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #8960
cmp w14, w12
b.ne L_00001122_miss
movz w12, #4388
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #18075
cmp w14, w12
b.ne L_00001122_miss
movz w12, #0
str w12, [x9, #12]
cmp w12, #0
mrs x13, nzcv
ldr w14, [x10]
and w13, w13, #0xc0000000
and w14, w14, #0x3fffffff
orr w14, w14, w13
str w14, [x10]
ldr w12, [x9, #12]
str w12, [x9, #44]
movz w12, #4390
add w12, w15, w12
str w12, [x9, #60]
L_00001122_success:
mov w0, #1
b L_00001122_return
L_00001122_fault:
mov w0, #-1
b L_00001122_return
L_00001122_miss:
mov w0, #3
b L_00001122_return
L_00001122_mode_miss:
mov w0, #4
L_00001122_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00001128
_agr_game_compiled_00001128:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00001128_mode_miss
movz w12, #4392
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #17976
cmp w14, w12
b.ne L_00001128_miss
movz w12, #4394
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #27697
cmp w14, w12
b.ne L_00001128_miss
movz w12, #4396
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #63487
movk w12, #65346, lsl #16
cmp w14, w12
b.ne L_00001128_miss
ldr w12, [x9, #28]
str w12, [x9, #0]
ldr w12, [x9, #24]
movz w13, #64
add w12, w12, w13
cmp w12, #0x1000
b.lo L_00001128_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w12, w13
b.hi L_00001128_fault
add x13, x11, w12, uxtw
ldr w12, [x13]
str w12, [x9, #4]
movz w12, #4020
add w12, w15, w12
orr w12, w12, #1
movz w13, #4400
add w13, w15, w13
orr w13, w13, #1
str w13, [x9, #56]
ldr w13, [x10]
and w14, w12, #1
lsl w14, w14, #5
bic w13, w13, #0x20
orr w13, w13, w14
str w13, [x10]
bic w12, w12, #1
str w12, [x9, #60]
b L_00001128_success
L_00001128_success:
mov w0, #1
b L_00001128_return
L_00001128_fault:
mov w0, #-1
b L_00001128_return
L_00001128_miss:
mov w0, #3
b L_00001128_return
L_00001128_mode_miss:
mov w0, #4
L_00001128_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_000011b4
_agr_game_compiled_000011b4:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_000011b4_mode_miss
movz w12, #4532
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #27712
cmp w14, w12
b.ne L_000011b4_miss
movz w12, #4534
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #18288
cmp w14, w12
b.ne L_000011b4_miss
ldr w12, [x9, #0]
movz w13, #68
add w12, w12, w13
cmp w12, #0x1000
b.lo L_000011b4_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w12, w13
b.hi L_000011b4_fault
add x13, x11, w12, uxtw
ldr w12, [x13]
str w12, [x9, #0]
ldr w12, [x9, #56]
ldr w13, [x10]
and w14, w12, #1
lsl w14, w14, #5
bic w13, w13, #0x20
orr w13, w13, w14
str w13, [x10]
bic w12, w12, #1
str w12, [x9, #60]
b L_000011b4_success
L_000011b4_success:
mov w0, #1
b L_000011b4_return
L_000011b4_fault:
mov w0, #-1
b L_000011b4_return
L_000011b4_miss:
mov w0, #3
b L_000011b4_return
L_000011b4_mode_miss:
mov w0, #4
L_000011b4_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_000011b8
_agr_game_compiled_000011b8:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_000011b8_mode_miss
movz w12, #4536
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #27595
cmp w14, w12
b.ne L_000011b8_miss
movz w12, #4538
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #59693
movk w12, #16880, lsl #16
cmp w14, w12
b.ne L_000011b8_miss
ldr w12, [x9, #4]
movz w13, #60
add w12, w12, w13
cmp w12, #0x1000
b.lo L_000011b8_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w12, w13
b.hi L_000011b8_fault
add x13, x11, w12, uxtw
ldr w12, [x13]
str w12, [x9, #12]
ldr w12, [x9, #52]
movz w13, #24
sub w12, w12, w13
cmp w12, #0x1000
b.lo L_000011b8_fault
add x13, x11, w12, uxtw
ldr w14, [x9, #16]
str w14, [x13, #0]
ldr w14, [x9, #20]
str w14, [x13, #4]
ldr w14, [x9, #24]
str w14, [x13, #8]
ldr w14, [x9, #28]
str w14, [x13, #12]
ldr w14, [x9, #32]
str w14, [x13, #16]
ldr w14, [x9, #56]
str w14, [x13, #20]
str w12, [x9, #52]
movz w12, #4542
add w12, w15, w12
str w12, [x9, #60]
L_000011b8_success:
mov w0, #1
b L_000011b8_return
L_000011b8_fault:
mov w0, #-1
b L_000011b8_return
L_000011b8_miss:
mov w0, #3
b L_000011b8_return
L_000011b8_mode_miss:
mov w0, #4
L_000011b8_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_000011c2
_agr_game_compiled_000011c2:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_000011c2_mode_miss
movz w12, #4546
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #17927
cmp w14, w12
b.ne L_000011c2_miss
movz w12, #4548
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #17934
cmp w14, w12
b.ne L_000011c2_miss
ldr w12, [x9, #0]
str w12, [x9, #28]
ldr w12, [x9, #4]
str w12, [x9, #24]
movz w12, #4550
add w12, w15, w12
str w12, [x9, #60]
L_000011c2_success:
mov w0, #1
b L_000011c2_return
L_000011c2_fault:
mov w0, #-1
b L_000011c2_return
L_000011c2_miss:
mov w0, #3
b L_000011c2_return
L_000011c2_mode_miss:
mov w0, #4
L_000011c2_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_000011ca
_agr_game_compiled_000011ca:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_000011ca_mode_miss
movz w12, #4554
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #44033
cmp w14, w12
b.ne L_000011ca_miss
movz w12, #4556
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #18152
cmp w14, w12
b.ne L_000011ca_miss
ldr w12, [x9, #52]
movz w13, #4
add w12, w12, w13
str w12, [x9, #16]
ldr w12, [x9, #52]
str w12, [x9, #32]
movz w12, #4558
add w12, w15, w12
str w12, [x9, #60]
L_000011ca_success:
mov w0, #1
b L_000011ca_return
L_000011ca_fault:
mov w0, #-1
b L_000011ca_return
L_000011ca_miss:
mov w0, #3
b L_000011ca_return
L_000011ca_mode_miss:
mov w0, #4
L_000011ca_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_000011e0
_agr_game_compiled_000011e0:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_000011e0_mode_miss
movz w12, #4576
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #61519
movk w12, #13311, lsl #16
cmp w14, w12
b.ne L_000011e0_miss
movz w12, #65535
movk w12, #65535, lsl #16
str w12, [x9, #12]
movz w12, #4580
add w12, w15, w12
str w12, [x9, #60]
L_000011e0_success:
mov w0, #1
b L_000011e0_return
L_000011e0_fault:
mov w0, #-1
b L_000011e0_return
L_000011e0_miss:
mov w0, #3
b L_000011e0_return
L_000011e0_mode_miss:
mov w0, #4
L_000011e0_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_000011e6
_agr_game_compiled_000011e6:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_000011e6_mode_miss
movz w12, #4582
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #17976
cmp w14, w12
b.ne L_000011e6_miss
movz w12, #4584
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #63704
movk w12, #4160, lsl #16
cmp w14, w12
b.ne L_000011e6_miss
movz w12, #4588
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #63487
movk w12, #65250, lsl #16
cmp w14, w12
b.ne L_000011e6_miss
ldr w12, [x9, #28]
str w12, [x9, #0]
ldr w12, [x9, #32]
movz w13, #64
add w12, w12, w13
cmp w12, #0x1000
b.lo L_000011e6_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w12, w13
b.hi L_000011e6_fault
add x13, x11, w12, uxtw
ldr w12, [x13]
str w12, [x9, #4]
movz w12, #4020
add w12, w15, w12
orr w12, w12, #1
movz w13, #4592
add w13, w15, w13
orr w13, w13, #1
str w13, [x9, #56]
ldr w13, [x10]
and w14, w12, #1
lsl w14, w14, #5
bic w13, w13, #0x20
orr w13, w13, w14
str w13, [x10]
bic w12, w12, #1
str w12, [x9, #60]
b L_000011e6_success
L_000011e6_success:
mov w0, #1
b L_000011e6_return
L_000011e6_fault:
mov w0, #-1
b L_000011e6_return
L_000011e6_miss:
mov w0, #3
b L_000011e6_return
L_000011e6_mode_miss:
mov w0, #4
L_000011e6_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_000011f0
_agr_game_compiled_000011f0:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_000011f0_mode_miss
movz w12, #4592
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #47480
cmp w14, w12
b.ne L_000011f0_miss
ldr w12, [x9, #0]
cbnz w12, L_000011f0_taken_0
movz w12, #4594
add w12, w15, w12
str w12, [x9, #60]
b L_000011f0_success
L_000011f0_taken_0:
movz w12, #4626
add w12, w15, w12
str w12, [x9, #60]
b L_000011f0_success
L_000011f0_success:
mov w0, #1
b L_000011f0_return
L_000011f0_fault:
mov w0, #-1
b L_000011f0_return
L_000011f0_miss:
mov w0, #3
b L_000011f0_return
L_000011f0_mode_miss:
mov w0, #4
L_000011f0_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_000011f2
_agr_game_compiled_000011f2:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_000011f2_mode_miss
movz w12, #4594
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #26939
cmp w14, w12
b.ne L_000011f2_miss
movz w12, #4596
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #17977
cmp w14, w12
b.ne L_000011f2_miss
movz w12, #4598
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #18026
cmp w14, w12
b.ne L_000011f2_miss
movz w12, #4600
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #18328
cmp w14, w12
b.ne L_000011f2_miss
ldr w12, [x9, #28]
movz w13, #16
add w12, w12, w13
cmp w12, #0x1000
b.lo L_000011f2_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w12, w13
b.hi L_000011f2_fault
add x13, x11, w12, uxtw
ldr w12, [x13]
str w12, [x9, #12]
ldr w12, [x9, #28]
str w12, [x9, #4]
ldr w12, [x9, #52]
str w12, [x9, #8]
ldr w12, [x9, #12]
movz w13, #4602
add w13, w15, w13
orr w13, w13, #1
str w13, [x9, #56]
ldr w13, [x10]
and w14, w12, #1
lsl w14, w14, #5
bic w13, w13, #0x20
orr w13, w13, w14
str w13, [x10]
bic w12, w12, #1
str w12, [x9, #60]
b L_000011f2_success
L_000011f2_success:
mov w0, #1
b L_000011f2_return
L_000011f2_fault:
mov w0, #-1
b L_000011f2_return
L_000011f2_miss:
mov w0, #3
b L_000011f2_return
L_000011f2_mode_miss:
mov w0, #4
L_000011f2_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_000011fc
_agr_game_compiled_000011fc:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_000011fc_mode_miss
movz w12, #4604
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #17924
cmp w14, w12
b.ne L_000011fc_miss
ldr w12, [x9, #0]
str w12, [x9, #16]
movz w12, #4606
add w12, w15, w12
str w12, [x9, #60]
L_000011fc_success:
mov w0, #1
b L_000011fc_return
L_000011fc_fault:
mov w0, #-1
b L_000011fc_return
L_000011fc_miss:
mov w0, #3
b L_000011fc_return
L_000011fc_mode_miss:
mov w0, #4
L_000011fc_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00001200
_agr_game_compiled_00001200:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00001200_mode_miss
movz w12, #4608
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #18024
cmp w14, w12
b.ne L_00001200_miss
movz w12, #4610
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #63487
movk w12, #65321, lsl #16
cmp w14, w12
b.ne L_00001200_miss
ldr w12, [x9, #52]
str w12, [x9, #0]
movz w12, #4184
add w12, w15, w12
orr w12, w12, #1
movz w13, #4614
add w13, w15, w13
orr w13, w13, #1
str w13, [x9, #56]
ldr w13, [x10]
and w14, w12, #1
lsl w14, w14, #5
bic w13, w13, #0x20
orr w13, w13, w14
str w13, [x10]
bic w12, w12, #1
str w12, [x9, #60]
b L_00001200_success
L_00001200_success:
mov w0, #1
b L_00001200_return
L_00001200_fault:
mov w0, #-1
b L_00001200_return
L_00001200_miss:
mov w0, #3
b L_00001200_return
L_00001200_mode_miss:
mov w0, #4
L_00001200_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_0000120a
_agr_game_compiled_0000120a:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_0000120a_mode_miss
movz w12, #4618
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #17976
cmp w14, w12
b.ne L_0000120a_miss
movz w12, #4620
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #17969
cmp w14, w12
b.ne L_0000120a_miss
movz w12, #4622
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #63487
movk w12, #65363, lsl #16
cmp w14, w12
b.ne L_0000120a_miss
ldr w12, [x9, #28]
str w12, [x9, #0]
ldr w12, [x9, #24]
str w12, [x9, #4]
movz w12, #4280
add w12, w15, w12
orr w12, w12, #1
movz w13, #4626
add w13, w15, w13
orr w13, w13, #1
str w13, [x9, #56]
ldr w13, [x10]
and w14, w12, #1
lsl w14, w14, #5
bic w13, w13, #0x20
orr w13, w13, w14
str w13, [x10]
bic w12, w12, #1
str w12, [x9, #60]
b L_0000120a_success
L_0000120a_success:
mov w0, #1
b L_0000120a_return
L_0000120a_fault:
mov w0, #-1
b L_0000120a_return
L_0000120a_miss:
mov w0, #3
b L_0000120a_return
L_0000120a_mode_miss:
mov w0, #4
L_0000120a_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00001212
_agr_game_compiled_00001212:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00001212_mode_miss
movz w12, #4626
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #8201
cmp w14, w12
b.ne L_00001212_miss
movz w12, #9
str w12, [x9, #0]
cmp w12, #0
mrs x13, nzcv
ldr w14, [x10]
and w13, w13, #0xc0000000
and w14, w14, #0x3fffffff
orr w14, w14, w13
str w14, [x10]
movz w12, #4628
add w12, w15, w12
str w12, [x9, #60]
L_00001212_success:
mov w0, #1
b L_00001212_return
L_00001212_fault:
mov w0, #-1
b L_00001212_return
L_00001212_miss:
mov w0, #3
b L_00001212_return
L_00001212_mode_miss:
mov w0, #4
L_00001212_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00001216
_agr_game_compiled_00001216:
sub sp, sp, #64
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00001216_mode_miss
movz w12, #4630
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #59581
movk w12, #33264, lsl #16
cmp w14, w12
b.ne L_00001216_miss
ldr w12, [x9, #52]
movz w13, #0
add w14, w12, w13
cmp w14, #0x1000
b.lo L_00001216_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w14, w13
b.hi L_00001216_fault
add x13, x11, w14, uxtw
ldr w14, [x13]
str w14, [sp, #0]
movz w13, #4
add w14, w12, w13
cmp w14, #0x1000
b.lo L_00001216_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w14, w13
b.hi L_00001216_fault
add x13, x11, w14, uxtw
ldr w14, [x13]
str w14, [sp, #4]
movz w13, #8
add w14, w12, w13
cmp w14, #0x1000
b.lo L_00001216_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w14, w13
b.hi L_00001216_fault
add x13, x11, w14, uxtw
ldr w14, [x13]
str w14, [sp, #8]
movz w13, #12
add w14, w12, w13
cmp w14, #0x1000
b.lo L_00001216_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w14, w13
b.hi L_00001216_fault
add x13, x11, w14, uxtw
ldr w14, [x13]
str w14, [sp, #12]
movz w13, #16
add w14, w12, w13
cmp w14, #0x1000
b.lo L_00001216_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w14, w13
b.hi L_00001216_fault
add x13, x11, w14, uxtw
ldr w14, [x13]
str w14, [sp, #16]
movz w13, #20
add w14, w12, w13
cmp w14, #0x1000
b.lo L_00001216_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w14, w13
b.hi L_00001216_fault
add x13, x11, w14, uxtw
ldr w14, [x13]
str w14, [sp, #20]
movz w13, #24
add w12, w12, w13
str w12, [x9, #52]
ldr w12, [sp, #0]
str w12, [x9, #16]
ldr w12, [sp, #4]
str w12, [x9, #20]
ldr w12, [sp, #8]
str w12, [x9, #24]
ldr w12, [sp, #12]
str w12, [x9, #28]
ldr w12, [sp, #16]
str w12, [x9, #32]
ldr w12, [sp, #20]
str w12, [x9, #60]
ldr w12, [x9, #60]
ldr w13, [x10]
and w14, w12, #1
lsl w14, w14, #5
bic w13, w13, #0x20
orr w13, w13, w14
str w13, [x10]
bic w12, w12, #1
str w12, [x9, #60]
b L_00001216_success
L_00001216_success:
mov w0, #1
b L_00001216_return
L_00001216_fault:
mov w0, #-1
b L_00001216_return
L_00001216_miss:
mov w0, #3
b L_00001216_return
L_00001216_mode_miss:
mov w0, #4
L_00001216_return:
add sp, sp, #64
ret

.text
.p2align 2
.globl _agr_game_compiled_0000121a
_agr_game_compiled_0000121a:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_0000121a_mode_miss
movz w12, #4634
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #46352
cmp w14, w12
b.ne L_0000121a_miss
ldr w12, [x9, #52]
movz w13, #8
sub w12, w12, w13
cmp w12, #0x1000
b.lo L_0000121a_fault
add x13, x11, w12, uxtw
ldr w14, [x9, #16]
str w14, [x13, #0]
ldr w14, [x9, #56]
str w14, [x13, #4]
str w12, [x9, #52]
movz w12, #4636
add w12, w15, w12
str w12, [x9, #60]
L_0000121a_success:
mov w0, #1
b L_0000121a_return
L_0000121a_fault:
mov w0, #-1
b L_0000121a_return
L_0000121a_miss:
mov w0, #3
b L_0000121a_return
L_0000121a_mode_miss:
mov w0, #4
L_0000121a_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_0000121e
_agr_game_compiled_0000121e:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_0000121e_mode_miss
movz w12, #4638
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #27610
cmp w14, w12
b.ne L_0000121e_miss
ldr w12, [x9, #12]
movz w13, #60
add w12, w12, w13
cmp w12, #0x1000
b.lo L_0000121e_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w12, w13
b.hi L_0000121e_fault
add x13, x11, w12, uxtw
ldr w12, [x13]
str w12, [x9, #8]
movz w12, #4640
add w12, w15, w12
str w12, [x9, #60]
L_0000121e_success:
mov w0, #1
b L_0000121e_return
L_0000121e_fault:
mov w0, #-1
b L_0000121e_return
L_0000121e_miss:
mov w0, #3
b L_0000121e_return
L_0000121e_mode_miss:
mov w0, #4
L_0000121e_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00001222
_agr_game_compiled_00001222:
sub sp, sp, #64
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00001222_mode_miss
movz w12, #4642
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #17945
cmp w14, w12
b.ne L_00001222_miss
movz w12, #4644
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #59581
movk w12, #16400, lsl #16
cmp w14, w12
b.ne L_00001222_miss
ldr w12, [x9, #12]
str w12, [x9, #4]
ldr w12, [x9, #52]
movz w13, #0
add w14, w12, w13
cmp w14, #0x1000
b.lo L_00001222_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w14, w13
b.hi L_00001222_fault
add x13, x11, w14, uxtw
ldr w14, [x13]
str w14, [sp, #0]
movz w13, #4
add w14, w12, w13
cmp w14, #0x1000
b.lo L_00001222_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w14, w13
b.hi L_00001222_fault
add x13, x11, w14, uxtw
ldr w14, [x13]
str w14, [sp, #4]
movz w13, #8
add w12, w12, w13
str w12, [x9, #52]
ldr w12, [sp, #0]
str w12, [x9, #16]
ldr w12, [sp, #4]
str w12, [x9, #56]
movz w12, #4648
add w12, w15, w12
str w12, [x9, #60]
L_00001222_success:
mov w0, #1
b L_00001222_return
L_00001222_fault:
mov w0, #-1
b L_00001222_return
L_00001222_miss:
mov w0, #3
b L_00001222_return
L_00001222_mode_miss:
mov w0, #4
L_00001222_return:
add sp, sp, #64
ret

.text
.p2align 2
.globl _agr_game_compiled_0000122a
_agr_game_compiled_0000122a:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_0000122a_mode_miss
movz w12, #4650
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #8704
cmp w14, w12
b.ne L_0000122a_miss
movz w12, #4652
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #59233
cmp w14, w12
b.ne L_0000122a_miss
movz w12, #0
str w12, [x9, #8]
cmp w12, #0
mrs x13, nzcv
ldr w14, [x10]
and w13, w13, #0xc0000000
and w14, w14, #0x3fffffff
orr w14, w14, w13
str w14, [x10]
movz w12, #4338
add w12, w15, w12
str w12, [x9, #60]
b L_0000122a_success
L_0000122a_success:
mov w0, #1
b L_0000122a_return
L_0000122a_fault:
mov w0, #-1
b L_0000122a_return
L_0000122a_miss:
mov w0, #3
b L_0000122a_return
L_0000122a_mode_miss:
mov w0, #4
L_0000122a_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_0000122e
_agr_game_compiled_0000122e:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_0000122e_mode_miss
movz w12, #4654
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #26947
cmp w14, w12
b.ne L_0000122e_miss
movz w12, #4656
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #46448
cmp w14, w12
b.ne L_0000122e_miss
movz w12, #4658
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #17925
cmp w14, w12
b.ne L_0000122e_miss
movz w12, #4660
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #26822
cmp w14, w12
b.ne L_0000122e_miss
movz w12, #4662
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #17932
cmp w14, w12
b.ne L_0000122e_miss
ldr w12, [x9, #0]
movz w13, #20
add w12, w12, w13
cmp w12, #0x1000
b.lo L_0000122e_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w12, w13
b.hi L_0000122e_fault
add x13, x11, w12, uxtw
ldr w12, [x13]
str w12, [x9, #12]
ldr w12, [x9, #52]
movz w13, #16
sub w12, w12, w13
cmp w12, #0x1000
b.lo L_0000122e_fault
add x13, x11, w12, uxtw
ldr w14, [x9, #16]
str w14, [x13, #0]
ldr w14, [x9, #20]
str w14, [x13, #4]
ldr w14, [x9, #24]
str w14, [x13, #8]
ldr w14, [x9, #56]
str w14, [x13, #12]
str w12, [x9, #52]
ldr w12, [x9, #0]
str w12, [x9, #20]
ldr w12, [x9, #0]
movz w13, #12
add w12, w12, w13
cmp w12, #0x1000
b.lo L_0000122e_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w12, w13
b.hi L_0000122e_fault
add x13, x11, w12, uxtw
ldr w12, [x13]
str w12, [x9, #24]
ldr w12, [x9, #4]
str w12, [x9, #16]
movz w12, #4664
add w12, w15, w12
str w12, [x9, #60]
L_0000122e_success:
mov w0, #1
b L_0000122e_return
L_0000122e_fault:
mov w0, #-1
b L_0000122e_return
L_0000122e_miss:
mov w0, #3
b L_0000122e_return
L_0000122e_mode_miss:
mov w0, #4
L_0000122e_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_0000123a
_agr_game_compiled_0000123a:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_0000123a_mode_miss
movz w12, #4666
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #45342
cmp w14, w12
b.ne L_0000123a_miss
ldr w12, [x9, #24]
cbz w12, L_0000123a_taken_0
movz w12, #4668
add w12, w15, w12
str w12, [x9, #60]
b L_0000123a_success
L_0000123a_taken_0:
movz w12, #4676
add w12, w15, w12
str w12, [x9, #60]
b L_0000123a_success
L_0000123a_success:
mov w0, #1
b L_0000123a_return
L_0000123a_fault:
mov w0, #-1
b L_0000123a_return
L_0000123a_miss:
mov w0, #3
b L_0000123a_return
L_0000123a_mode_miss:
mov w0, #4
L_0000123a_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_0000123c
_agr_game_compiled_0000123c:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_0000123c_mode_miss
movz w12, #4668
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #8705
cmp w14, w12
b.ne L_0000123c_miss
movz w12, #4670
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #63487
movk w12, #65368, lsl #16
cmp w14, w12
b.ne L_0000123c_miss
movz w12, #1
str w12, [x9, #8]
cmp w12, #0
mrs x13, nzcv
ldr w14, [x10]
and w13, w13, #0xc0000000
and w14, w14, #0x3fffffff
orr w14, w14, w13
str w14, [x10]
movz w12, #4338
add w12, w15, w12
orr w12, w12, #1
movz w13, #4674
add w13, w15, w13
orr w13, w13, #1
str w13, [x9, #56]
ldr w13, [x10]
and w14, w12, #1
lsl w14, w14, #5
bic w13, w13, #0x20
orr w13, w13, w14
str w13, [x10]
bic w12, w12, #1
str w12, [x9, #60]
b L_0000123c_success
L_0000123c_success:
mov w0, #1
b L_0000123c_return
L_0000123c_fault:
mov w0, #-1
b L_0000123c_return
L_0000123c_miss:
mov w0, #3
b L_0000123c_return
L_0000123c_mode_miss:
mov w0, #4
L_0000123c_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00001242
_agr_game_compiled_00001242:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00001242_mode_miss
movz w12, #4674
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #57363
cmp w14, w12
b.ne L_00001242_miss
movz w12, #4716
add w12, w15, w12
str w12, [x9, #60]
b L_00001242_success
L_00001242_success:
mov w0, #1
b L_00001242_return
L_00001242_fault:
mov w0, #-1
b L_00001242_return
L_00001242_miss:
mov w0, #3
b L_00001242_return
L_00001242_mode_miss:
mov w0, #4
L_00001242_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00001244
_agr_game_compiled_00001244:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00001244_mode_miss
movz w12, #4676
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #26883
cmp w14, w12
b.ne L_00001244_miss
movz w12, #4678
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #17961
cmp w14, w12
b.ne L_00001244_miss
movz w12, #4680
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #8194
cmp w14, w12
b.ne L_00001244_miss
movz w12, #4682
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #17954
cmp w14, w12
b.ne L_00001244_miss
movz w12, #4684
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #18328
cmp w14, w12
b.ne L_00001244_miss
ldr w12, [x9, #0]
movz w13, #16
add w12, w12, w13
cmp w12, #0x1000
b.lo L_00001244_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w12, w13
b.hi L_00001244_fault
add x13, x11, w12, uxtw
ldr w12, [x13]
str w12, [x9, #12]
ldr w12, [x9, #20]
str w12, [x9, #4]
movz w12, #2
str w12, [x9, #0]
cmp w12, #0
mrs x13, nzcv
ldr w14, [x10]
and w13, w13, #0xc0000000
and w14, w14, #0x3fffffff
orr w14, w14, w13
str w14, [x10]
ldr w12, [x9, #16]
str w12, [x9, #8]
ldr w12, [x9, #12]
movz w13, #4686
add w13, w15, w13
orr w13, w13, #1
str w13, [x9, #56]
ldr w13, [x10]
and w14, w12, #1
lsl w14, w14, #5
bic w13, w13, #0x20
orr w13, w13, w14
str w13, [x10]
bic w12, w12, #1
str w12, [x9, #60]
b L_00001244_success
L_00001244_success:
mov w0, #1
b L_00001244_return
L_00001244_fault:
mov w0, #-1
b L_00001244_return
L_00001244_miss:
mov w0, #3
b L_00001244_return
L_00001244_mode_miss:
mov w0, #4
L_00001244_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00001256
_agr_game_compiled_00001256:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00001256_mode_miss
movz w12, #4694
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #17960
cmp w14, w12
b.ne L_00001256_miss
movz w12, #4696
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #17953
cmp w14, w12
b.ne L_00001256_miss
movz w12, #4698
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #63487
movk w12, #65325, lsl #16
cmp w14, w12
b.ne L_00001256_miss
ldr w12, [x9, #20]
str w12, [x9, #0]
ldr w12, [x9, #16]
str w12, [x9, #4]
movz w12, #4280
add w12, w15, w12
orr w12, w12, #1
movz w13, #4702
add w13, w15, w13
orr w13, w13, #1
str w13, [x9, #56]
ldr w13, [x10]
and w14, w12, #1
lsl w14, w14, #5
bic w13, w13, #0x20
orr w13, w13, w14
str w13, [x10]
bic w12, w12, #1
str w12, [x9, #60]
b L_00001256_success
L_00001256_success:
mov w0, #1
b L_00001256_return
L_00001256_fault:
mov w0, #-1
b L_00001256_return
L_00001256_miss:
mov w0, #3
b L_00001256_return
L_00001256_mode_miss:
mov w0, #4
L_00001256_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_0000125e
_agr_game_compiled_0000125e:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_0000125e_mode_miss
movz w12, #4702
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #17968
cmp w14, w12
b.ne L_0000125e_miss
movz w12, #4704
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #27681
cmp w14, w12
b.ne L_0000125e_miss
movz w12, #4706
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #63487
movk w12, #65320, lsl #16
cmp w14, w12
b.ne L_0000125e_miss
ldr w12, [x9, #24]
str w12, [x9, #0]
ldr w12, [x9, #16]
movz w13, #64
add w12, w12, w13
cmp w12, #0x1000
b.lo L_0000125e_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w12, w13
b.hi L_0000125e_fault
add x13, x11, w12, uxtw
ldr w12, [x13]
str w12, [x9, #4]
movz w12, #4278
add w12, w15, w12
orr w12, w12, #1
movz w13, #4710
add w13, w15, w13
orr w13, w13, #1
str w13, [x9, #56]
ldr w13, [x10]
and w14, w12, #1
lsl w14, w14, #5
bic w13, w13, #0x20
orr w13, w13, w14
str w13, [x10]
bic w12, w12, #1
str w12, [x9, #60]
b L_0000125e_success
L_0000125e_success:
mov w0, #1
b L_0000125e_return
L_0000125e_fault:
mov w0, #-1
b L_0000125e_return
L_0000125e_miss:
mov w0, #3
b L_0000125e_return
L_0000125e_mode_miss:
mov w0, #4
L_0000125e_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00001268
_agr_game_compiled_00001268:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00001268_mode_miss
movz w12, #4712
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #61440
movk w12, #64240, lsl #16
cmp w14, w12
b.ne L_00001268_miss
movz w12, #6220
add w12, w15, w12
orr w12, w12, #1
movz w13, #4716
add w13, w15, w13
orr w13, w13, #1
str w13, [x9, #56]
ldr w13, [x10]
and w14, w12, #1
lsl w14, w14, #5
bic w13, w13, #0x20
orr w13, w13, w14
str w13, [x10]
bic w12, w12, #1
str w12, [x9, #60]
b L_00001268_success
L_00001268_success:
mov w0, #1
b L_00001268_return
L_00001268_fault:
mov w0, #-1
b L_00001268_return
L_00001268_miss:
mov w0, #3
b L_00001268_return
L_00001268_mode_miss:
mov w0, #4
L_00001268_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_0000126c
_agr_game_compiled_0000126c:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_0000126c_mode_miss
movz w12, #4716
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #63487
movk w12, #60784, lsl #16
cmp w14, w12
b.ne L_0000126c_miss
movz w12, #3408
add w12, w15, w12
movz w13, #4720
add w13, w15, w13
orr w13, w13, #1
str w13, [x9, #56]
ldr w13, [x10]
and w14, w12, #1
lsl w14, w14, #5
bic w13, w13, #0x20
orr w13, w13, w14
str w13, [x10]
bic w12, w12, #1
str w12, [x9, #60]
b L_0000126c_success
L_0000126c_success:
mov w0, #1
b L_0000126c_return
L_0000126c_fault:
mov w0, #-1
b L_0000126c_return
L_0000126c_miss:
mov w0, #3
b L_0000126c_return
L_0000126c_mode_miss:
mov w0, #4
L_0000126c_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00001270
_agr_game_compiled_00001270:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00001270_mode_miss
movz w12, #4720
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #26818
cmp w14, w12
b.ne L_00001270_miss
movz w12, #4722
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #47370
cmp w14, w12
b.ne L_00001270_miss
ldr w12, [x9, #0]
movz w13, #12
add w12, w12, w13
cmp w12, #0x1000
b.lo L_00001270_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w12, w13
b.hi L_00001270_fault
add x13, x11, w12, uxtw
ldr w12, [x13]
str w12, [x9, #8]
ldr w12, [x9, #8]
cbnz w12, L_00001270_taken_1
movz w12, #4724
add w12, w15, w12
str w12, [x9, #60]
b L_00001270_success
L_00001270_taken_1:
movz w12, #4728
add w12, w15, w12
str w12, [x9, #60]
b L_00001270_success
L_00001270_success:
mov w0, #1
b L_00001270_return
L_00001270_fault:
mov w0, #-1
b L_00001270_return
L_00001270_miss:
mov w0, #3
b L_00001270_return
L_00001270_mode_miss:
mov w0, #4
L_00001270_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00001274
_agr_game_compiled_00001274:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00001274_mode_miss
movz w12, #4724
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #63487
movk w12, #49056, lsl #16
cmp w14, w12
b.ne L_00001274_miss
movz w12, #4536
add w12, w15, w12
str w12, [x9, #60]
b L_00001274_success
L_00001274_success:
mov w0, #1
b L_00001274_return
L_00001274_fault:
mov w0, #-1
b L_00001274_return
L_00001274_miss:
mov w0, #3
b L_00001274_return
L_00001274_mode_miss:
mov w0, #4
L_00001274_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00001278
_agr_game_compiled_00001278:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00001278_mode_miss
movz w12, #4728
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #27594
cmp w14, w12
b.ne L_00001278_miss
ldr w12, [x9, #4]
movz w13, #60
add w12, w12, w13
cmp w12, #0x1000
b.lo L_00001278_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w12, w13
b.hi L_00001278_fault
add x13, x11, w12, uxtw
ldr w12, [x13]
str w12, [x9, #8]
movz w12, #4730
add w12, w15, w12
str w12, [x9, #60]
L_00001278_success:
mov w0, #1
b L_00001278_return
L_00001278_fault:
mov w0, #-1
b L_00001278_return
L_00001278_miss:
mov w0, #3
b L_00001278_return
L_00001278_mode_miss:
mov w0, #4
L_00001278_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_0000127c
_agr_game_compiled_0000127c:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_0000127c_mode_miss
movz w12, #4732
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #8704
cmp w14, w12
b.ne L_0000127c_miss
movz w12, #4734
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #59192
cmp w14, w12
b.ne L_0000127c_miss
movz w12, #0
str w12, [x9, #8]
cmp w12, #0
mrs x13, nzcv
ldr w14, [x10]
and w13, w13, #0xc0000000
and w14, w14, #0x3fffffff
orr w14, w14, w13
str w14, [x10]
movz w12, #4338
add w12, w15, w12
str w12, [x9, #60]
b L_0000127c_success
L_0000127c_success:
mov w0, #1
b L_0000127c_return
L_0000127c_fault:
mov w0, #-1
b L_0000127c_return
L_0000127c_miss:
mov w0, #3
b L_0000127c_return
L_0000127c_mode_miss:
mov w0, #4
L_0000127c_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00001280
_agr_game_compiled_00001280:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00001280_mode_miss
movz w12, #4736
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #18288
cmp w14, w12
b.ne L_00001280_miss
ldr w12, [x9, #56]
ldr w13, [x10]
and w14, w12, #1
lsl w14, w14, #5
bic w13, w13, #0x20
orr w13, w13, w14
str w13, [x10]
bic w12, w12, #1
str w12, [x9, #60]
b L_00001280_success
L_00001280_success:
mov w0, #1
b L_00001280_return
L_00001280_fault:
mov w0, #-1
b L_00001280_return
L_00001280_miss:
mov w0, #3
b L_00001280_return
L_00001280_mode_miss:
mov w0, #4
L_00001280_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00001282
_agr_game_compiled_00001282:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00001282_mode_miss
movz w12, #4738
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #46344
cmp w14, w12
b.ne L_00001282_miss
movz w12, #4740
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #17921
cmp w14, w12
b.ne L_00001282_miss
movz w12, #4742
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #26755
cmp w14, w12
b.ne L_00001282_miss
movz w12, #4744
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #45323
cmp w14, w12
b.ne L_00001282_miss
ldr w12, [x9, #52]
movz w13, #8
sub w12, w12, w13
cmp w12, #0x1000
b.lo L_00001282_fault
add x13, x11, w12, uxtw
ldr w14, [x9, #12]
str w14, [x13, #0]
ldr w14, [x9, #56]
str w14, [x13, #4]
str w12, [x9, #52]
ldr w12, [x9, #0]
str w12, [x9, #4]
ldr w12, [x9, #0]
movz w13, #8
add w12, w12, w13
cmp w12, #0x1000
b.lo L_00001282_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w12, w13
b.hi L_00001282_fault
add x13, x11, w12, uxtw
ldr w12, [x13]
str w12, [x9, #12]
ldr w12, [x9, #12]
cbz w12, L_00001282_taken_3
movz w12, #4746
add w12, w15, w12
str w12, [x9, #60]
b L_00001282_success
L_00001282_taken_3:
movz w12, #4750
add w12, w15, w12
str w12, [x9, #60]
b L_00001282_success
L_00001282_success:
mov w0, #1
b L_00001282_return
L_00001282_fault:
mov w0, #-1
b L_00001282_return
L_00001282_miss:
mov w0, #3
b L_00001282_return
L_00001282_mode_miss:
mov w0, #4
L_00001282_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_0000128a
_agr_game_compiled_0000128a:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_0000128a_mode_miss
movz w12, #4746
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #8193
cmp w14, w12
b.ne L_0000128a_miss
movz w12, #4748
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #18328
cmp w14, w12
b.ne L_0000128a_miss
movz w12, #1
str w12, [x9, #0]
cmp w12, #0
mrs x13, nzcv
ldr w14, [x10]
and w13, w13, #0xc0000000
and w14, w14, #0x3fffffff
orr w14, w14, w13
str w14, [x10]
ldr w12, [x9, #12]
movz w13, #4750
add w13, w15, w13
orr w13, w13, #1
str w13, [x9, #56]
ldr w13, [x10]
and w14, w12, #1
lsl w14, w14, #5
bic w13, w13, #0x20
orr w13, w13, w14
str w13, [x10]
bic w12, w12, #1
str w12, [x9, #60]
b L_0000128a_success
L_0000128a_success:
mov w0, #1
b L_0000128a_return
L_0000128a_fault:
mov w0, #-1
b L_0000128a_return
L_0000128a_miss:
mov w0, #3
b L_0000128a_return
L_0000128a_mode_miss:
mov w0, #4
L_0000128a_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_0000128e
_agr_game_compiled_0000128e:
sub sp, sp, #64
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_0000128e_mode_miss
movz w12, #4750
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #48392
cmp w14, w12
b.ne L_0000128e_miss
ldr w12, [x9, #52]
movz w13, #0
add w14, w12, w13
cmp w14, #0x1000
b.lo L_0000128e_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w14, w13
b.hi L_0000128e_fault
add x13, x11, w14, uxtw
ldr w14, [x13]
str w14, [sp, #0]
movz w13, #4
add w14, w12, w13
cmp w14, #0x1000
b.lo L_0000128e_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w14, w13
b.hi L_0000128e_fault
add x13, x11, w14, uxtw
ldr w14, [x13]
str w14, [sp, #4]
movz w13, #8
add w12, w12, w13
str w12, [x9, #52]
ldr w12, [sp, #0]
str w12, [x9, #12]
ldr w12, [sp, #4]
str w12, [x9, #60]
ldr w12, [x9, #60]
ldr w13, [x10]
and w14, w12, #1
lsl w14, w14, #5
bic w13, w13, #0x20
orr w13, w13, w14
str w13, [x10]
bic w12, w12, #1
str w12, [x9, #60]
b L_0000128e_success
L_0000128e_success:
mov w0, #1
b L_0000128e_return
L_0000128e_fault:
mov w0, #-1
b L_0000128e_return
L_0000128e_miss:
mov w0, #3
b L_0000128e_return
L_0000128e_mode_miss:
mov w0, #4
L_0000128e_return:
add sp, sp, #64
ret

.text
.p2align 2
.globl _agr_game_compiled_00001290
_agr_game_compiled_00001290:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00001290_mode_miss
movz w12, #4752
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #46384
cmp w14, w12
b.ne L_00001290_miss
ldr w12, [x9, #52]
movz w13, #12
sub w12, w12, w13
cmp w12, #0x1000
b.lo L_00001290_fault
add x13, x11, w12, uxtw
ldr w14, [x9, #16]
str w14, [x13, #0]
ldr w14, [x9, #20]
str w14, [x13, #4]
ldr w14, [x9, #56]
str w14, [x13, #8]
str w12, [x9, #52]
movz w12, #4754
add w12, w15, w12
str w12, [x9, #60]
L_00001290_success:
mov w0, #1
b L_00001290_return
L_00001290_fault:
mov w0, #-1
b L_00001290_return
L_00001290_miss:
mov w0, #3
b L_00001290_return
L_00001290_mode_miss:
mov w0, #4
L_00001290_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_000012a0
_agr_game_compiled_000012a0:
sub sp, sp, #64
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_000012a0_mode_miss
movz w12, #4768
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #8193
cmp w14, w12
b.ne L_000012a0_miss
movz w12, #4770
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #48432
cmp w14, w12
b.ne L_000012a0_miss
movz w12, #1
str w12, [x9, #0]
cmp w12, #0
mrs x13, nzcv
ldr w14, [x10]
and w13, w13, #0xc0000000
and w14, w14, #0x3fffffff
orr w14, w14, w13
str w14, [x10]
ldr w12, [x9, #52]
movz w13, #0
add w14, w12, w13
cmp w14, #0x1000
b.lo L_000012a0_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w14, w13
b.hi L_000012a0_fault
add x13, x11, w14, uxtw
ldr w14, [x13]
str w14, [sp, #0]
movz w13, #4
add w14, w12, w13
cmp w14, #0x1000
b.lo L_000012a0_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w14, w13
b.hi L_000012a0_fault
add x13, x11, w14, uxtw
ldr w14, [x13]
str w14, [sp, #4]
movz w13, #8
add w14, w12, w13
cmp w14, #0x1000
b.lo L_000012a0_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w14, w13
b.hi L_000012a0_fault
add x13, x11, w14, uxtw
ldr w14, [x13]
str w14, [sp, #8]
movz w13, #12
add w12, w12, w13
str w12, [x9, #52]
ldr w12, [sp, #0]
str w12, [x9, #16]
ldr w12, [sp, #4]
str w12, [x9, #20]
ldr w12, [sp, #8]
str w12, [x9, #60]
ldr w12, [x9, #60]
ldr w13, [x10]
and w14, w12, #1
lsl w14, w14, #5
bic w13, w13, #0x20
orr w13, w13, w14
str w13, [x10]
bic w12, w12, #1
str w12, [x9, #60]
b L_000012a0_success
L_000012a0_success:
mov w0, #1
b L_000012a0_return
L_000012a0_fault:
mov w0, #-1
b L_000012a0_return
L_000012a0_miss:
mov w0, #3
b L_000012a0_return
L_000012a0_mode_miss:
mov w0, #4
L_000012a0_return:
add sp, sp, #64
ret

.text
.p2align 2
.globl _agr_game_compiled_000012b8
_agr_game_compiled_000012b8:
sub sp, sp, #64
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_000012b8_mode_miss
movz w12, #4792
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #8194
cmp w14, w12
b.ne L_000012b8_miss
movz w12, #4794
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #48432
cmp w14, w12
b.ne L_000012b8_miss
movz w12, #2
str w12, [x9, #0]
cmp w12, #0
mrs x13, nzcv
ldr w14, [x10]
and w13, w13, #0xc0000000
and w14, w14, #0x3fffffff
orr w14, w14, w13
str w14, [x10]
ldr w12, [x9, #52]
movz w13, #0
add w14, w12, w13
cmp w14, #0x1000
b.lo L_000012b8_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w14, w13
b.hi L_000012b8_fault
add x13, x11, w14, uxtw
ldr w14, [x13]
str w14, [sp, #0]
movz w13, #4
add w14, w12, w13
cmp w14, #0x1000
b.lo L_000012b8_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w14, w13
b.hi L_000012b8_fault
add x13, x11, w14, uxtw
ldr w14, [x13]
str w14, [sp, #4]
movz w13, #8
add w14, w12, w13
cmp w14, #0x1000
b.lo L_000012b8_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w14, w13
b.hi L_000012b8_fault
add x13, x11, w14, uxtw
ldr w14, [x13]
str w14, [sp, #8]
movz w13, #12
add w12, w12, w13
str w12, [x9, #52]
ldr w12, [sp, #0]
str w12, [x9, #16]
ldr w12, [sp, #4]
str w12, [x9, #20]
ldr w12, [sp, #8]
str w12, [x9, #60]
ldr w12, [x9, #60]
ldr w13, [x10]
and w14, w12, #1
lsl w14, w14, #5
bic w13, w13, #0x20
orr w13, w13, w14
str w13, [x10]
bic w12, w12, #1
str w12, [x9, #60]
b L_000012b8_success
L_000012b8_success:
mov w0, #1
b L_000012b8_return
L_000012b8_fault:
mov w0, #-1
b L_000012b8_return
L_000012b8_miss:
mov w0, #3
b L_000012b8_return
L_000012b8_mode_miss:
mov w0, #4
L_000012b8_return:
add sp, sp, #64
ret

.text
.p2align 2
.globl _agr_game_compiled_000012bc
_agr_game_compiled_000012bc:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_000012bc_mode_miss
movz w12, #4796
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #46367
cmp w14, w12
b.ne L_000012bc_miss
movz w12, #4798
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #17930
cmp w14, w12
b.ne L_000012bc_miss
movz w12, #4800
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #8448
cmp w14, w12
b.ne L_000012bc_miss
movz w12, #4802
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #43779
cmp w14, w12
b.ne L_000012bc_miss
ldr w12, [x9, #52]
movz w13, #24
sub w12, w12, w13
cmp w12, #0x1000
b.lo L_000012bc_fault
add x13, x11, w12, uxtw
ldr w14, [x9, #0]
str w14, [x13, #0]
ldr w14, [x9, #4]
str w14, [x13, #4]
ldr w14, [x9, #8]
str w14, [x13, #8]
ldr w14, [x9, #12]
str w14, [x13, #12]
ldr w14, [x9, #16]
str w14, [x13, #16]
ldr w14, [x9, #56]
str w14, [x13, #20]
str w12, [x9, #52]
ldr w12, [x9, #4]
str w12, [x9, #8]
movz w12, #0
str w12, [x9, #4]
cmp w12, #0
mrs x13, nzcv
ldr w14, [x10]
and w13, w13, #0xc0000000
and w14, w14, #0x3fffffff
orr w14, w14, w13
str w14, [x10]
ldr w12, [x9, #52]
movz w13, #12
add w12, w12, w13
str w12, [x9, #12]
movz w12, #4804
add w12, w15, w12
str w12, [x9, #60]
L_000012bc_success:
mov w0, #1
b L_000012bc_return
L_000012bc_fault:
mov w0, #-1
b L_000012bc_return
L_000012bc_miss:
mov w0, #3
b L_000012bc_return
L_000012bc_mode_miss:
mov w0, #4
L_000012bc_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_000012c6
_agr_game_compiled_000012c6:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_000012c6_mode_miss
movz w12, #4806
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #17931
cmp w14, w12
b.ne L_000012c6_miss
movz w12, #4808
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #63487
movk w12, #65506, lsl #16
cmp w14, w12
b.ne L_000012c6_miss
ldr w12, [x9, #4]
str w12, [x9, #12]
movz w12, #4752
add w12, w15, w12
orr w12, w12, #1
movz w13, #4812
add w13, w15, w13
orr w13, w13, #1
str w13, [x9, #56]
ldr w13, [x10]
and w14, w12, #1
lsl w14, w14, #5
bic w13, w13, #0x20
orr w13, w13, w14
str w13, [x10]
bic w12, w12, #1
str w12, [x9, #60]
b L_000012c6_success
L_000012c6_success:
mov w0, #1
b L_000012c6_return
L_000012c6_fault:
mov w0, #-1
b L_000012c6_return
L_000012c6_miss:
mov w0, #3
b L_000012c6_return
L_000012c6_mode_miss:
mov w0, #4
L_000012c6_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_000012cc
_agr_game_compiled_000012cc:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_000012cc_mode_miss
movz w12, #4812
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #38915
cmp w14, w12
b.ne L_000012cc_miss
ldr w12, [x9, #52]
movz w13, #12
add w12, w12, w13
cmp w12, #0x1000
b.lo L_000012cc_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w12, w13
b.hi L_000012cc_fault
add x13, x11, w12, uxtw
ldr w12, [x13]
str w12, [x9, #0]
movz w12, #4814
add w12, w15, w12
str w12, [x9, #60]
L_000012cc_success:
mov w0, #1
b L_000012cc_return
L_000012cc_fault:
mov w0, #-1
b L_000012cc_return
L_000012cc_miss:
mov w0, #3
b L_000012cc_return
L_000012cc_mode_miss:
mov w0, #4
L_000012cc_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_000012d4
_agr_game_compiled_000012d4:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_000012d4_mode_miss
movz w12, #4820
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #46384
cmp w14, w12
b.ne L_000012d4_miss
ldr w12, [x9, #52]
movz w13, #12
sub w12, w12, w13
cmp w12, #0x1000
b.lo L_000012d4_fault
add x13, x11, w12, uxtw
ldr w14, [x9, #16]
str w14, [x13, #0]
ldr w14, [x9, #20]
str w14, [x13, #4]
ldr w14, [x9, #56]
str w14, [x13, #8]
str w12, [x9, #52]
movz w12, #4822
add w12, w15, w12
str w12, [x9, #60]
L_000012d4_success:
mov w0, #1
b L_000012d4_return
L_000012d4_fault:
mov w0, #-1
b L_000012d4_return
L_000012d4_miss:
mov w0, #3
b L_000012d4_return
L_000012d4_mode_miss:
mov w0, #4
L_000012d4_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_000012e4
_agr_game_compiled_000012e4:
sub sp, sp, #64
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_000012e4_mode_miss
movz w12, #4836
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #8193
cmp w14, w12
b.ne L_000012e4_miss
movz w12, #4838
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #48432
cmp w14, w12
b.ne L_000012e4_miss
movz w12, #1
str w12, [x9, #0]
cmp w12, #0
mrs x13, nzcv
ldr w14, [x10]
and w13, w13, #0xc0000000
and w14, w14, #0x3fffffff
orr w14, w14, w13
str w14, [x10]
ldr w12, [x9, #52]
movz w13, #0
add w14, w12, w13
cmp w14, #0x1000
b.lo L_000012e4_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w14, w13
b.hi L_000012e4_fault
add x13, x11, w14, uxtw
ldr w14, [x13]
str w14, [sp, #0]
movz w13, #4
add w14, w12, w13
cmp w14, #0x1000
b.lo L_000012e4_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w14, w13
b.hi L_000012e4_fault
add x13, x11, w14, uxtw
ldr w14, [x13]
str w14, [sp, #4]
movz w13, #8
add w14, w12, w13
cmp w14, #0x1000
b.lo L_000012e4_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w14, w13
b.hi L_000012e4_fault
add x13, x11, w14, uxtw
ldr w14, [x13]
str w14, [sp, #8]
movz w13, #12
add w12, w12, w13
str w12, [x9, #52]
ldr w12, [sp, #0]
str w12, [x9, #16]
ldr w12, [sp, #4]
str w12, [x9, #20]
ldr w12, [sp, #8]
str w12, [x9, #60]
ldr w12, [x9, #60]
ldr w13, [x10]
and w14, w12, #1
lsl w14, w14, #5
bic w13, w13, #0x20
orr w13, w13, w14
str w13, [x10]
bic w12, w12, #1
str w12, [x9, #60]
b L_000012e4_success
L_000012e4_success:
mov w0, #1
b L_000012e4_return
L_000012e4_fault:
mov w0, #-1
b L_000012e4_return
L_000012e4_miss:
mov w0, #3
b L_000012e4_return
L_000012e4_mode_miss:
mov w0, #4
L_000012e4_return:
add sp, sp, #64
ret

.text
.p2align 2
.globl _agr_game_compiled_000012fc
_agr_game_compiled_000012fc:
sub sp, sp, #64
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_000012fc_mode_miss
movz w12, #4860
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #8194
cmp w14, w12
b.ne L_000012fc_miss
movz w12, #4862
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #48432
cmp w14, w12
b.ne L_000012fc_miss
movz w12, #2
str w12, [x9, #0]
cmp w12, #0
mrs x13, nzcv
ldr w14, [x10]
and w13, w13, #0xc0000000
and w14, w14, #0x3fffffff
orr w14, w14, w13
str w14, [x10]
ldr w12, [x9, #52]
movz w13, #0
add w14, w12, w13
cmp w14, #0x1000
b.lo L_000012fc_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w14, w13
b.hi L_000012fc_fault
add x13, x11, w14, uxtw
ldr w14, [x13]
str w14, [sp, #0]
movz w13, #4
add w14, w12, w13
cmp w14, #0x1000
b.lo L_000012fc_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w14, w13
b.hi L_000012fc_fault
add x13, x11, w14, uxtw
ldr w14, [x13]
str w14, [sp, #4]
movz w13, #8
add w14, w12, w13
cmp w14, #0x1000
b.lo L_000012fc_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w14, w13
b.hi L_000012fc_fault
add x13, x11, w14, uxtw
ldr w14, [x13]
str w14, [sp, #8]
movz w13, #12
add w12, w12, w13
str w12, [x9, #52]
ldr w12, [sp, #0]
str w12, [x9, #16]
ldr w12, [sp, #4]
str w12, [x9, #20]
ldr w12, [sp, #8]
str w12, [x9, #60]
ldr w12, [x9, #60]
ldr w13, [x10]
and w14, w12, #1
lsl w14, w14, #5
bic w13, w13, #0x20
orr w13, w13, w14
str w13, [x10]
bic w12, w12, #1
str w12, [x9, #60]
b L_000012fc_success
L_000012fc_success:
mov w0, #1
b L_000012fc_return
L_000012fc_fault:
mov w0, #-1
b L_000012fc_return
L_000012fc_miss:
mov w0, #3
b L_000012fc_return
L_000012fc_mode_miss:
mov w0, #4
L_000012fc_return:
add sp, sp, #64
ret

.text
.p2align 2
.globl _agr_game_compiled_00001300
_agr_game_compiled_00001300:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00001300_mode_miss
movz w12, #4864
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #46367
cmp w14, w12
b.ne L_00001300_miss
movz w12, #4866
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #43780
cmp w14, w12
b.ne L_00001300_miss
movz w12, #4868
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #17932
cmp w14, w12
b.ne L_00001300_miss
movz w12, #4870
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #8448
cmp w14, w12
b.ne L_00001300_miss
ldr w12, [x9, #52]
movz w13, #24
sub w12, w12, w13
cmp w12, #0x1000
b.lo L_00001300_fault
add x13, x11, w12, uxtw
ldr w14, [x9, #0]
str w14, [x13, #0]
ldr w14, [x9, #4]
str w14, [x13, #4]
ldr w14, [x9, #8]
str w14, [x13, #8]
ldr w14, [x9, #12]
str w14, [x13, #12]
ldr w14, [x9, #16]
str w14, [x13, #16]
ldr w14, [x9, #56]
str w14, [x13, #20]
str w12, [x9, #52]
ldr w12, [x9, #52]
movz w13, #16
add w12, w12, w13
str w12, [x9, #12]
ldr w12, [x9, #4]
str w12, [x9, #16]
movz w12, #0
str w12, [x9, #4]
cmp w12, #0
mrs x13, nzcv
ldr w14, [x10]
and w13, w13, #0xc0000000
and w14, w14, #0x3fffffff
orr w14, w14, w13
str w14, [x10]
movz w12, #4872
add w12, w15, w12
str w12, [x9, #60]
L_00001300_success:
mov w0, #1
b L_00001300_return
L_00001300_fault:
mov w0, #-1
b L_00001300_return
L_00001300_miss:
mov w0, #3
b L_00001300_return
L_00001300_mode_miss:
mov w0, #4
L_00001300_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_0000130c
_agr_game_compiled_0000130c:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_0000130c_mode_miss
movz w12, #4876
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #17954
cmp w14, w12
b.ne L_0000130c_miss
ldr w12, [x9, #16]
str w12, [x9, #8]
movz w12, #4878
add w12, w15, w12
str w12, [x9, #60]
L_0000130c_success:
mov w0, #1
b L_0000130c_return
L_0000130c_fault:
mov w0, #-1
b L_0000130c_return
L_0000130c_miss:
mov w0, #3
b L_0000130c_return
L_0000130c_mode_miss:
mov w0, #4
L_0000130c_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00001310
_agr_game_compiled_00001310:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00001310_mode_miss
movz w12, #4880
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #17931
cmp w14, w12
b.ne L_00001310_miss
movz w12, #4882
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #63487
movk w12, #65503, lsl #16
cmp w14, w12
b.ne L_00001310_miss
ldr w12, [x9, #4]
str w12, [x9, #12]
movz w12, #4820
add w12, w15, w12
orr w12, w12, #1
movz w13, #4886
add w13, w15, w13
orr w13, w13, #1
str w13, [x9, #56]
ldr w13, [x10]
and w14, w12, #1
lsl w14, w14, #5
bic w13, w13, #0x20
orr w13, w13, w14
str w13, [x10]
bic w12, w12, #1
str w12, [x9, #60]
b L_00001310_success
L_00001310_success:
mov w0, #1
b L_00001310_return
L_00001310_fault:
mov w0, #-1
b L_00001310_return
L_00001310_miss:
mov w0, #3
b L_00001310_return
L_00001310_mode_miss:
mov w0, #4
L_00001310_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00001318
_agr_game_compiled_00001318:
sub sp, sp, #64
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00001318_mode_miss
movz w12, #4888
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #48400
cmp w14, w12
b.ne L_00001318_miss
ldr w12, [x9, #52]
movz w13, #0
add w14, w12, w13
cmp w14, #0x1000
b.lo L_00001318_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w14, w13
b.hi L_00001318_fault
add x13, x11, w14, uxtw
ldr w14, [x13]
str w14, [sp, #0]
movz w13, #4
add w14, w12, w13
cmp w14, #0x1000
b.lo L_00001318_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w14, w13
b.hi L_00001318_fault
add x13, x11, w14, uxtw
ldr w14, [x13]
str w14, [sp, #4]
movz w13, #8
add w12, w12, w13
str w12, [x9, #52]
ldr w12, [sp, #0]
str w12, [x9, #16]
ldr w12, [sp, #4]
str w12, [x9, #60]
ldr w12, [x9, #60]
ldr w13, [x10]
and w14, w12, #1
lsl w14, w14, #5
bic w13, w13, #0x20
orr w13, w13, w14
str w13, [x10]
bic w12, w12, #1
str w12, [x9, #60]
b L_00001318_success
L_00001318_success:
mov w0, #1
b L_00001318_return
L_00001318_fault:
mov w0, #-1
b L_00001318_return
L_00001318_miss:
mov w0, #3
b L_00001318_return
L_00001318_mode_miss:
mov w0, #4
L_00001318_return:
add sp, sp, #64
ret

.text
.p2align 2
.globl _agr_game_compiled_0000131a
_agr_game_compiled_0000131a:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_0000131a_mode_miss
movz w12, #4890
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #27603
cmp w14, w12
b.ne L_0000131a_miss
movz w12, #4892
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #59693
movk w12, #16880, lsl #16
cmp w14, w12
b.ne L_0000131a_miss
ldr w12, [x9, #8]
movz w13, #60
add w12, w12, w13
cmp w12, #0x1000
b.lo L_0000131a_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w12, w13
b.hi L_0000131a_fault
add x13, x11, w12, uxtw
ldr w12, [x13]
str w12, [x9, #12]
ldr w12, [x9, #52]
movz w13, #24
sub w12, w12, w13
cmp w12, #0x1000
b.lo L_0000131a_fault
add x13, x11, w12, uxtw
ldr w14, [x9, #16]
str w14, [x13, #0]
ldr w14, [x9, #20]
str w14, [x13, #4]
ldr w14, [x9, #24]
str w14, [x13, #8]
ldr w14, [x9, #28]
str w14, [x13, #12]
ldr w14, [x9, #32]
str w14, [x13, #16]
ldr w14, [x9, #56]
str w14, [x13, #20]
str w12, [x9, #52]
movz w12, #4896
add w12, w15, w12
str w12, [x9, #60]
L_0000131a_success:
mov w0, #1
b L_0000131a_return
L_0000131a_fault:
mov w0, #-1
b L_0000131a_return
L_0000131a_miss:
mov w0, #3
b L_0000131a_return
L_0000131a_mode_miss:
mov w0, #4
L_0000131a_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00001324
_agr_game_compiled_00001324:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00001324_mode_miss
movz w12, #4900
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #17927
cmp w14, w12
b.ne L_00001324_miss
movz w12, #4902
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #18056
cmp w14, w12
b.ne L_00001324_miss
ldr w12, [x9, #0]
str w12, [x9, #28]
ldr w12, [x9, #4]
str w12, [x9, #32]
movz w12, #4904
add w12, w15, w12
str w12, [x9, #60]
L_00001324_success:
mov w0, #1
b L_00001324_return
L_00001324_fault:
mov w0, #-1
b L_00001324_return
L_00001324_miss:
mov w0, #3
b L_00001324_return
L_00001324_mode_miss:
mov w0, #4
L_00001324_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_0000132e
_agr_game_compiled_0000132e:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_0000132e_mode_miss
movz w12, #4910
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #44055
cmp w14, w12
b.ne L_0000132e_miss
movz w12, #4912
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #44566
cmp w14, w12
b.ne L_0000132e_miss
ldr w12, [x9, #52]
movz w13, #92
add w12, w12, w13
str w12, [x9, #16]
ldr w12, [x9, #52]
movz w13, #88
add w12, w12, w13
str w12, [x9, #24]
movz w12, #4914
add w12, w15, w12
str w12, [x9, #60]
L_0000132e_success:
mov w0, #1
b L_0000132e_return
L_0000132e_fault:
mov w0, #-1
b L_0000132e_return
L_0000132e_miss:
mov w0, #3
b L_0000132e_return
L_0000132e_mode_miss:
mov w0, #4
L_0000132e_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00001344
_agr_game_compiled_00001344:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00001344_mode_miss
movz w12, #4932
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #18028
cmp w14, w12
b.ne L_00001344_miss
movz w12, #4934
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #61519
movk w12, #13311, lsl #16
cmp w14, w12
b.ne L_00001344_miss
ldr w12, [x9, #52]
str w12, [x9, #16]
movz w12, #65535
movk w12, #65535, lsl #16
str w12, [x9, #12]
movz w12, #4938
add w12, w15, w12
str w12, [x9, #60]
L_00001344_success:
mov w0, #1
b L_00001344_return
L_00001344_fault:
mov w0, #-1
b L_00001344_return
L_00001344_miss:
mov w0, #3
b L_00001344_return
L_00001344_mode_miss:
mov w0, #4
L_00001344_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_0000134c
_agr_game_compiled_0000134c:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_0000134c_mode_miss
movz w12, #4940
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #18024
cmp w14, w12
b.ne L_0000134c_miss
movz w12, #4942
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #27697
cmp w14, w12
b.ne L_0000134c_miss
movz w12, #4944
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #63487
movk w12, #65072, lsl #16
cmp w14, w12
b.ne L_0000134c_miss
ldr w12, [x9, #52]
str w12, [x9, #0]
ldr w12, [x9, #24]
movz w13, #64
add w12, w12, w13
cmp w12, #0x1000
b.lo L_0000134c_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w12, w13
b.hi L_0000134c_fault
add x13, x11, w12, uxtw
ldr w12, [x13]
str w12, [x9, #4]
movz w12, #4020
add w12, w15, w12
orr w12, w12, #1
movz w13, #4948
add w13, w15, w13
orr w13, w13, #1
str w13, [x9, #56]
ldr w13, [x10]
and w14, w12, #1
lsl w14, w14, #5
bic w13, w13, #0x20
orr w13, w13, w14
str w13, [x10]
bic w12, w12, #1
str w12, [x9, #60]
b L_0000134c_success
L_0000134c_success:
mov w0, #1
b L_0000134c_return
L_0000134c_fault:
mov w0, #-1
b L_0000134c_return
L_0000134c_miss:
mov w0, #3
b L_0000134c_return
L_0000134c_mode_miss:
mov w0, #4
L_0000134c_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00001354
_agr_game_compiled_00001354:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00001354_mode_miss
movz w12, #4948
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #45320
cmp w14, w12
b.ne L_00001354_miss
ldr w12, [x9, #0]
cbz w12, L_00001354_taken_0
movz w12, #4950
add w12, w15, w12
str w12, [x9, #60]
b L_00001354_success
L_00001354_taken_0:
movz w12, #4954
add w12, w15, w12
str w12, [x9, #60]
b L_00001354_success
L_00001354_success:
mov w0, #1
b L_00001354_return
L_00001354_fault:
mov w0, #-1
b L_00001354_return
L_00001354_miss:
mov w0, #3
b L_00001354_return
L_00001354_mode_miss:
mov w0, #4
L_00001354_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00001356
_agr_game_compiled_00001356:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00001356_mode_miss
movz w12, #4950
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #9481
cmp w14, w12
b.ne L_00001356_miss
movz w12, #4952
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #57364
cmp w14, w12
b.ne L_00001356_miss
movz w12, #9
str w12, [x9, #20]
cmp w12, #0
mrs x13, nzcv
ldr w14, [x10]
and w13, w13, #0xc0000000
and w14, w14, #0x3fffffff
orr w14, w14, w13
str w14, [x10]
movz w12, #4996
add w12, w15, w12
str w12, [x9, #60]
b L_00001356_success
L_00001356_success:
mov w0, #1
b L_00001356_return
L_00001356_fault:
mov w0, #-1
b L_00001356_return
L_00001356_miss:
mov w0, #3
b L_00001356_return
L_00001356_mode_miss:
mov w0, #4
L_00001356_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_0000135a
_agr_game_compiled_0000135a:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_0000135a_mode_miss
movz w12, #4954
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #17968
cmp w14, w12
b.ne L_0000135a_miss
movz w12, #4956
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #8460
cmp w14, w12
b.ne L_0000135a_miss
movz w12, #4958
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #18026
cmp w14, w12
b.ne L_0000135a_miss
movz w12, #4960
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #63487
movk w12, #65486, lsl #16
cmp w14, w12
b.ne L_0000135a_miss
ldr w12, [x9, #24]
str w12, [x9, #0]
movz w12, #12
str w12, [x9, #4]
cmp w12, #0
mrs x13, nzcv
ldr w14, [x10]
and w13, w13, #0xc0000000
and w14, w14, #0x3fffffff
orr w14, w14, w13
str w14, [x10]
ldr w12, [x9, #52]
str w12, [x9, #8]
movz w12, #4864
add w12, w15, w12
orr w12, w12, #1
movz w13, #4964
add w13, w15, w13
orr w13, w13, #1
str w13, [x9, #56]
ldr w13, [x10]
and w14, w12, #1
lsl w14, w14, #5
bic w13, w13, #0x20
orr w13, w13, w14
str w13, [x10]
bic w12, w12, #1
str w12, [x9, #60]
b L_0000135a_success
L_0000135a_success:
mov w0, #1
b L_0000135a_return
L_0000135a_fault:
mov w0, #-1
b L_0000135a_return
L_0000135a_miss:
mov w0, #3
b L_0000135a_return
L_0000135a_mode_miss:
mov w0, #4
L_0000135a_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00001364
_agr_game_compiled_00001364:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00001364_mode_miss
movz w12, #4964
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #17968
cmp w14, w12
b.ne L_00001364_miss
movz w12, #4966
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #17985
cmp w14, w12
b.ne L_00001364_miss
movz w12, #4968
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #18360
cmp w14, w12
b.ne L_00001364_miss
ldr w12, [x9, #24]
str w12, [x9, #0]
ldr w12, [x9, #32]
str w12, [x9, #4]
ldr w12, [x9, #28]
movz w13, #4970
add w13, w15, w13
orr w13, w13, #1
str w13, [x9, #56]
ldr w13, [x10]
and w14, w12, #1
lsl w14, w14, #5
bic w13, w13, #0x20
orr w13, w13, w14
str w13, [x10]
bic w12, w12, #1
str w12, [x9, #60]
b L_00001364_success
L_00001364_success:
mov w0, #1
b L_00001364_return
L_00001364_fault:
mov w0, #-1
b L_00001364_return
L_00001364_miss:
mov w0, #3
b L_00001364_return
L_00001364_mode_miss:
mov w0, #4
L_00001364_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_0000136e
_agr_game_compiled_0000136e:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_0000136e_mode_miss
movz w12, #4974
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #26915
cmp w14, w12
b.ne L_0000136e_miss
movz w12, #4976
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #8200
cmp w14, w12
b.ne L_0000136e_miss
movz w12, #4978
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #18025
cmp w14, w12
b.ne L_0000136e_miss
movz w12, #4980
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #17970
cmp w14, w12
b.ne L_0000136e_miss
movz w12, #4982
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #18328
cmp w14, w12
b.ne L_0000136e_miss
ldr w12, [x9, #16]
movz w13, #16
add w12, w12, w13
cmp w12, #0x1000
b.lo L_0000136e_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w12, w13
b.hi L_0000136e_fault
add x13, x11, w12, uxtw
ldr w12, [x13]
str w12, [x9, #12]
movz w12, #8
str w12, [x9, #0]
cmp w12, #0
mrs x13, nzcv
ldr w14, [x10]
and w13, w13, #0xc0000000
and w14, w14, #0x3fffffff
orr w14, w14, w13
str w14, [x10]
ldr w12, [x9, #52]
str w12, [x9, #4]
ldr w12, [x9, #24]
str w12, [x9, #8]
ldr w12, [x9, #12]
movz w13, #4984
add w13, w15, w13
orr w13, w13, #1
str w13, [x9, #56]
ldr w13, [x10]
and w14, w12, #1
lsl w14, w14, #5
bic w13, w13, #0x20
orr w13, w13, w14
str w13, [x10]
bic w12, w12, #1
str w12, [x9, #60]
b L_0000136e_success
L_0000136e_success:
mov w0, #1
b L_0000136e_return
L_0000136e_fault:
mov w0, #-1
b L_0000136e_return
L_0000136e_miss:
mov w0, #3
b L_0000136e_return
L_0000136e_mode_miss:
mov w0, #4
L_0000136e_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_0000137a
_agr_game_compiled_0000137a:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_0000137a_mode_miss
movz w12, #4986
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #17925
cmp w14, w12
b.ne L_0000137a_miss
ldr w12, [x9, #0]
str w12, [x9, #20]
movz w12, #4988
add w12, w15, w12
str w12, [x9, #60]
L_0000137a_success:
mov w0, #1
b L_0000137a_return
L_0000137a_fault:
mov w0, #-1
b L_0000137a_return
L_0000137a_miss:
mov w0, #3
b L_0000137a_return
L_0000137a_mode_miss:
mov w0, #4
L_0000137a_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00001382
_agr_game_compiled_00001382:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00001382_mode_miss
movz w12, #4994
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #59368
cmp w14, w12
b.ne L_00001382_miss
movz w12, #4950
add w12, w15, w12
str w12, [x9, #60]
b L_00001382_success
L_00001382_success:
mov w0, #1
b L_00001382_return
L_00001382_fault:
mov w0, #-1
b L_00001382_return
L_00001382_miss:
mov w0, #3
b L_00001382_return
L_00001382_mode_miss:
mov w0, #4
L_00001382_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00001384
_agr_game_compiled_00001384:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00001384_mode_miss
movz w12, #4996
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #17968
cmp w14, w12
b.ne L_00001384_miss
movz w12, #4998
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #63487
movk w12, #65127, lsl #16
cmp w14, w12
b.ne L_00001384_miss
ldr w12, [x9, #24]
str w12, [x9, #0]
movz w12, #4184
add w12, w15, w12
orr w12, w12, #1
movz w13, #5002
add w13, w15, w13
orr w13, w13, #1
str w13, [x9, #56]
ldr w13, [x10]
and w14, w12, #1
lsl w14, w14, #5
bic w13, w13, #0x20
orr w13, w13, w14
str w13, [x10]
bic w12, w12, #1
str w12, [x9, #60]
b L_00001384_success
L_00001384_success:
mov w0, #1
b L_00001384_return
L_00001384_fault:
mov w0, #-1
b L_00001384_return
L_00001384_miss:
mov w0, #3
b L_00001384_return
L_00001384_mode_miss:
mov w0, #4
L_00001384_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_0000138a
_agr_game_compiled_0000138a:
sub sp, sp, #64
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_0000138a_mode_miss
movz w12, #5002
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #17960
cmp w14, w12
b.ne L_0000138a_miss
movz w12, #5004
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #62733
movk w12, #32014, lsl #16
cmp w14, w12
b.ne L_0000138a_miss
movz w12, #5008
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #59581
movk w12, #33264, lsl #16
cmp w14, w12
b.ne L_0000138a_miss
ldr w12, [x9, #20]
str w12, [x9, #0]
ldr w12, [x9, #52]
movz w13, #3854
add w12, w12, w13
str w12, [x9, #52]
ldr w12, [x9, #52]
movz w13, #0
add w14, w12, w13
cmp w14, #0x1000
b.lo L_0000138a_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w14, w13
b.hi L_0000138a_fault
add x13, x11, w14, uxtw
ldr w14, [x13]
str w14, [sp, #0]
movz w13, #4
add w14, w12, w13
cmp w14, #0x1000
b.lo L_0000138a_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w14, w13
b.hi L_0000138a_fault
add x13, x11, w14, uxtw
ldr w14, [x13]
str w14, [sp, #4]
movz w13, #8
add w14, w12, w13
cmp w14, #0x1000
b.lo L_0000138a_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w14, w13
b.hi L_0000138a_fault
add x13, x11, w14, uxtw
ldr w14, [x13]
str w14, [sp, #8]
movz w13, #12
add w14, w12, w13
cmp w14, #0x1000
b.lo L_0000138a_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w14, w13
b.hi L_0000138a_fault
add x13, x11, w14, uxtw
ldr w14, [x13]
str w14, [sp, #12]
movz w13, #16
add w14, w12, w13
cmp w14, #0x1000
b.lo L_0000138a_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w14, w13
b.hi L_0000138a_fault
add x13, x11, w14, uxtw
ldr w14, [x13]
str w14, [sp, #16]
movz w13, #20
add w14, w12, w13
cmp w14, #0x1000
b.lo L_0000138a_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w14, w13
b.hi L_0000138a_fault
add x13, x11, w14, uxtw
ldr w14, [x13]
str w14, [sp, #20]
movz w13, #24
add w12, w12, w13
str w12, [x9, #52]
ldr w12, [sp, #0]
str w12, [x9, #16]
ldr w12, [sp, #4]
str w12, [x9, #20]
ldr w12, [sp, #8]
str w12, [x9, #24]
ldr w12, [sp, #12]
str w12, [x9, #28]
ldr w12, [sp, #16]
str w12, [x9, #32]
ldr w12, [sp, #20]
str w12, [x9, #60]
ldr w12, [x9, #60]
ldr w13, [x10]
and w14, w12, #1
lsl w14, w14, #5
bic w13, w13, #0x20
orr w13, w13, w14
str w13, [x10]
bic w12, w12, #1
str w12, [x9, #60]
b L_0000138a_success
L_0000138a_success:
mov w0, #1
b L_0000138a_return
L_0000138a_fault:
mov w0, #-1
b L_0000138a_return
L_0000138a_miss:
mov w0, #3
b L_0000138a_return
L_0000138a_mode_miss:
mov w0, #4
L_0000138a_return:
add sp, sp, #64
ret

.text
.p2align 2
.globl _agr_game_compiled_00001394
_agr_game_compiled_00001394:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00001394_mode_miss
movz w12, #5012
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #59693
movk w12, #20464, lsl #16
cmp w14, w12
b.ne L_00001394_miss
movz w12, #5016
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #17942
cmp w14, w12
b.ne L_00001394_miss
movz w12, #5018
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #27850
cmp w14, w12
b.ne L_00001394_miss
ldr w12, [x9, #52]
movz w13, #36
sub w12, w12, w13
cmp w12, #0x1000
b.lo L_00001394_fault
add x13, x11, w12, uxtw
ldr w14, [x9, #16]
str w14, [x13, #0]
ldr w14, [x9, #20]
str w14, [x13, #4]
ldr w14, [x9, #24]
str w14, [x13, #8]
ldr w14, [x9, #28]
str w14, [x13, #12]
ldr w14, [x9, #32]
str w14, [x13, #16]
ldr w14, [x9, #36]
str w14, [x13, #20]
ldr w14, [x9, #40]
str w14, [x13, #24]
ldr w14, [x9, #44]
str w14, [x13, #28]
ldr w14, [x9, #56]
str w14, [x13, #32]
str w12, [x9, #52]
ldr w12, [x9, #8]
str w12, [x9, #24]
ldr w12, [x9, #4]
movz w13, #76
add w12, w12, w13
cmp w12, #0x1000
b.lo L_00001394_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w12, w13
b.hi L_00001394_fault
add x13, x11, w12, uxtw
ldr w12, [x13]
str w12, [x9, #8]
movz w12, #5020
add w12, w15, w12
str w12, [x9, #60]
L_00001394_success:
mov w0, #1
b L_00001394_return
L_00001394_fault:
mov w0, #-1
b L_00001394_return
L_00001394_miss:
mov w0, #3
b L_00001394_return
L_00001394_mode_miss:
mov w0, #4
L_00001394_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_0000139e
_agr_game_compiled_0000139e:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_0000139e_mode_miss
movz w12, #5022
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #18051
cmp w14, w12
b.ne L_0000139e_miss
movz w12, #5024
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #17932
cmp w14, w12
b.ne L_0000139e_miss
ldr w12, [x9, #0]
str w12, [x9, #44]
ldr w12, [x9, #4]
str w12, [x9, #16]
movz w12, #5026
add w12, w15, w12
str w12, [x9, #60]
L_0000139e_success:
mov w0, #1
b L_0000139e_return
L_0000139e_fault:
mov w0, #-1
b L_0000139e_return
L_0000139e_miss:
mov w0, #3
b L_0000139e_return
L_0000139e_mode_miss:
mov w0, #4
L_0000139e_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_000013a8
_agr_game_compiled_000013a8:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_000013a8_mode_miss
movz w12, #5032
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #26642
cmp w14, w12
b.ne L_000013a8_miss
movz w12, #5034
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #17951
cmp w14, w12
b.ne L_000013a8_miss
ldr w12, [x9, #8]
movz w13, #0
add w12, w12, w13
cmp w12, #0x1000
b.lo L_000013a8_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w12, w13
b.hi L_000013a8_fault
add x13, x11, w12, uxtw
ldr w12, [x13]
str w12, [x9, #8]
ldr w12, [x9, #12]
str w12, [x9, #28]
movz w12, #5036
add w12, w15, w12
str w12, [x9, #60]
L_000013a8_success:
mov w0, #1
b L_000013a8_return
L_000013a8_fault:
mov w0, #-1
b L_000013a8_return
L_000013a8_miss:
mov w0, #3
b L_000013a8_return
L_000013a8_mode_miss:
mov w0, #4
L_000013a8_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_000013b0
_agr_game_compiled_000013b0:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_000013b0_mode_miss
movz w12, #5040
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #47419
cmp w14, w12
b.ne L_000013b0_miss
ldr w12, [x9, #12]
cbnz w12, L_000013b0_taken_0
movz w12, #5042
add w12, w15, w12
str w12, [x9, #60]
b L_000013b0_success
L_000013b0_taken_0:
movz w12, #5058
add w12, w15, w12
str w12, [x9, #60]
b L_000013b0_success
L_000013b0_success:
mov w0, #1
b L_000013b0_return
L_000013b0_fault:
mov w0, #-1
b L_000013b0_return
L_000013b0_miss:
mov w0, #3
b L_000013b0_return
L_000013b0_mode_miss:
mov w0, #4
L_000013b0_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_000013ba
_agr_game_compiled_000013ba:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_000013ba_mode_miss
movz w12, #5050
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #8963
cmp w14, w12
b.ne L_000013ba_miss
movz w12, #3
str w12, [x9, #12]
cmp w12, #0
mrs x13, nzcv
ldr w14, [x10]
and w13, w13, #0xc0000000
and w14, w14, #0x3fffffff
orr w14, w14, w13
str w14, [x10]
movz w12, #5052
add w12, w15, w12
str w12, [x9, #60]
L_000013ba_success:
mov w0, #1
b L_000013ba_return
L_000013ba_fault:
mov w0, #-1
b L_000013ba_return
L_000013ba_miss:
mov w0, #3
b L_000013ba_return
L_000013ba_mode_miss:
mov w0, #4
L_000013ba_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_000013c0
_agr_game_compiled_000013c0:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_000013c0_mode_miss
movz w12, #5056
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #57356
cmp w14, w12
b.ne L_000013c0_miss
movz w12, #5084
add w12, w15, w12
str w12, [x9, #60]
b L_000013c0_success
L_000013c0_success:
mov w0, #1
b L_000013c0_return
L_000013c0_fault:
mov w0, #-1
b L_000013c0_return
L_000013c0_miss:
mov w0, #3
b L_000013c0_return
L_000013c0_mode_miss:
mov w0, #4
L_000013c0_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_000013d2
_agr_game_compiled_000013d2:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_000013d2_mode_miss
movz w12, #5074
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #8706
cmp w14, w12
b.ne L_000013d2_miss
movz w12, #2
str w12, [x9, #8]
cmp w12, #0
mrs x13, nzcv
ldr w14, [x10]
and w13, w13, #0xc0000000
and w14, w14, #0x3fffffff
orr w14, w14, w13
str w14, [x10]
movz w12, #5076
add w12, w15, w12
str w12, [x9, #60]
L_000013d2_success:
mov w0, #1
b L_000013d2_return
L_000013d2_fault:
mov w0, #-1
b L_000013d2_return
L_000013d2_miss:
mov w0, #3
b L_000013d2_return
L_000013d2_mode_miss:
mov w0, #4
L_000013d2_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_000013e0
_agr_game_compiled_000013e0:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_000013e0_mode_miss
movz w12, #5088
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #27939
cmp w14, w12
b.ne L_000013e0_miss
ldr w12, [x9, #16]
movz w13, #80
add w12, w12, w13
cmp w12, #0x1000
b.lo L_000013e0_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w12, w13
b.hi L_000013e0_fault
add x13, x11, w12, uxtw
ldr w12, [x13]
str w12, [x9, #12]
movz w12, #5090
add w12, w15, w12
str w12, [x9, #60]
L_000013e0_success:
mov w0, #1
b L_000013e0_return
L_000013e0_fault:
mov w0, #-1
b L_000013e0_return
L_000013e0_miss:
mov w0, #3
b L_000013e0_return
L_000013e0_mode_miss:
mov w0, #4
L_000013e0_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_0000161c
_agr_game_compiled_0000161c:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_0000161c_mode_miss
movz w12, #5660
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #8960
cmp w14, w12
b.ne L_0000161c_miss
movz w12, #5662
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #59065
cmp w14, w12
b.ne L_0000161c_miss
movz w12, #0
str w12, [x9, #12]
cmp w12, #0
mrs x13, nzcv
ldr w14, [x10]
and w13, w13, #0xc0000000
and w14, w14, #0x3fffffff
orr w14, w14, w13
str w14, [x10]
movz w12, #5012
add w12, w15, w12
str w12, [x9, #60]
b L_0000161c_success
L_0000161c_success:
mov w0, #1
b L_0000161c_return
L_0000161c_fault:
mov w0, #-1
b L_0000161c_return
L_0000161c_miss:
mov w0, #3
b L_0000161c_return
L_0000161c_mode_miss:
mov w0, #4
L_0000161c_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00001620
_agr_game_compiled_00001620:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00001620_mode_miss
movz w12, #5664
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #8961
cmp w14, w12
b.ne L_00001620_miss
movz w12, #5666
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #59063
cmp w14, w12
b.ne L_00001620_miss
movz w12, #1
str w12, [x9, #12]
cmp w12, #0
mrs x13, nzcv
ldr w14, [x10]
and w13, w13, #0xc0000000
and w14, w14, #0x3fffffff
orr w14, w14, w13
str w14, [x10]
movz w12, #5012
add w12, w15, w12
str w12, [x9, #60]
b L_00001620_success
L_00001620_success:
mov w0, #1
b L_00001620_return
L_00001620_fault:
mov w0, #-1
b L_00001620_return
L_00001620_miss:
mov w0, #3
b L_00001620_return
L_00001620_mode_miss:
mov w0, #4
L_00001620_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00001624
_agr_game_compiled_00001624:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00001624_mode_miss
movz w12, #5668
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #8962
cmp w14, w12
b.ne L_00001624_miss
movz w12, #5670
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #59061
cmp w14, w12
b.ne L_00001624_miss
movz w12, #2
str w12, [x9, #12]
cmp w12, #0
mrs x13, nzcv
ldr w14, [x10]
and w13, w13, #0xc0000000
and w14, w14, #0x3fffffff
orr w14, w14, w13
str w14, [x10]
movz w12, #5012
add w12, w15, w12
str w12, [x9, #60]
b L_00001624_success
L_00001624_success:
mov w0, #1
b L_00001624_return
L_00001624_fault:
mov w0, #-1
b L_00001624_return
L_00001624_miss:
mov w0, #3
b L_00001624_return
L_00001624_mode_miss:
mov w0, #4
L_00001624_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00001628
_agr_game_compiled_00001628:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00001628_mode_miss
movz w12, #5672
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #59693
movk w12, #16880, lsl #16
cmp w14, w12
b.ne L_00001628_miss
movz w12, #5676
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #17924
cmp w14, w12
b.ne L_00001628_miss
ldr w12, [x9, #52]
movz w13, #24
sub w12, w12, w13
cmp w12, #0x1000
b.lo L_00001628_fault
add x13, x11, w12, uxtw
ldr w14, [x9, #16]
str w14, [x13, #0]
ldr w14, [x9, #20]
str w14, [x13, #4]
ldr w14, [x9, #24]
str w14, [x13, #8]
ldr w14, [x9, #28]
str w14, [x13, #12]
ldr w14, [x9, #32]
str w14, [x13, #16]
ldr w14, [x9, #56]
str w14, [x13, #20]
str w12, [x9, #52]
ldr w12, [x9, #0]
str w12, [x9, #16]
movz w12, #5678
add w12, w15, w12
str w12, [x9, #60]
L_00001628_success:
mov w0, #1
b L_00001628_return
L_00001628_fault:
mov w0, #-1
b L_00001628_return
L_00001628_miss:
mov w0, #3
b L_00001628_return
L_00001628_mode_miss:
mov w0, #4
L_00001628_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00001630
_agr_game_compiled_00001630:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00001630_mode_miss
movz w12, #5680
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #17943
cmp w14, w12
b.ne L_00001630_miss
movz w12, #5682
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #17949
cmp w14, w12
b.ne L_00001630_miss
ldr w12, [x9, #8]
str w12, [x9, #28]
ldr w12, [x9, #12]
str w12, [x9, #20]
movz w12, #5684
add w12, w15, w12
str w12, [x9, #60]
L_00001630_success:
mov w0, #1
b L_00001630_return
L_00001630_fault:
mov w0, #-1
b L_00001630_return
L_00001630_miss:
mov w0, #3
b L_00001630_return
L_00001630_mode_miss:
mov w0, #4
L_00001630_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00001646
_agr_game_compiled_00001646:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00001646_mode_miss
movz w12, #5702
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #27523
cmp w14, w12
b.ne L_00001646_miss
ldr w12, [x9, #0]
movz w13, #56
add w12, w12, w13
cmp w12, #0x1000
b.lo L_00001646_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w12, w13
b.hi L_00001646_fault
add x13, x11, w12, uxtw
ldr w12, [x13]
str w12, [x9, #12]
movz w12, #5704
add w12, w15, w12
str w12, [x9, #60]
L_00001646_success:
mov w0, #1
b L_00001646_return
L_00001646_fault:
mov w0, #-1
b L_00001646_return
L_00001646_miss:
mov w0, #3
b L_00001646_return
L_00001646_mode_miss:
mov w0, #4
L_00001646_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_0000164a
_agr_game_compiled_0000164a:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_0000164a_mode_miss
movz w12, #5706
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #8193
cmp w14, w12
b.ne L_0000164a_miss
movz w12, #1
str w12, [x9, #0]
cmp w12, #0
mrs x13, nzcv
ldr w14, [x10]
and w13, w13, #0xc0000000
and w14, w14, #0x3fffffff
orr w14, w14, w13
str w14, [x10]
movz w12, #5708
add w12, w15, w12
str w12, [x9, #60]
L_0000164a_success:
mov w0, #1
b L_0000164a_return
L_0000164a_fault:
mov w0, #-1
b L_0000164a_return
L_0000164a_miss:
mov w0, #3
b L_0000164a_return
L_0000164a_mode_miss:
mov w0, #4
L_0000164a_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00001654
_agr_game_compiled_00001654:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00001654_mode_miss
movz w12, #5716
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #26650
cmp w14, w12
b.ne L_00001654_miss
ldr w12, [x9, #12]
movz w13, #0
add w12, w12, w13
cmp w12, #0x1000
b.lo L_00001654_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w12, w13
b.hi L_00001654_fault
add x13, x11, w12, uxtw
ldr w12, [x13]
str w12, [x9, #8]
movz w12, #5718
add w12, w15, w12
str w12, [x9, #60]
L_00001654_success:
mov w0, #1
b L_00001654_return
L_00001654_fault:
mov w0, #-1
b L_00001654_return
L_00001654_miss:
mov w0, #3
b L_00001654_return
L_00001654_mode_miss:
mov w0, #4
L_00001654_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_0000166e
_agr_game_compiled_0000166e:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_0000166e_mode_miss
movz w12, #5742
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #57577
cmp w14, w12
b.ne L_0000166e_miss
movz w12, #6212
add w12, w15, w12
str w12, [x9, #60]
b L_0000166e_success
L_0000166e_success:
mov w0, #1
b L_0000166e_return
L_0000166e_fault:
mov w0, #-1
b L_0000166e_return
L_0000166e_miss:
mov w0, #3
b L_0000166e_return
L_0000166e_mode_miss:
mov w0, #4
L_0000166e_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00001730
_agr_game_compiled_00001730:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00001730_mode_miss
movz w12, #5936
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #8194
cmp w14, w12
b.ne L_00001730_miss
movz w12, #5938
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #57479
cmp w14, w12
b.ne L_00001730_miss
movz w12, #2
str w12, [x9, #0]
cmp w12, #0
mrs x13, nzcv
ldr w14, [x10]
and w13, w13, #0xc0000000
and w14, w14, #0x3fffffff
orr w14, w14, w13
str w14, [x10]
movz w12, #6212
add w12, w15, w12
str w12, [x9, #60]
b L_00001730_success
L_00001730_success:
mov w0, #1
b L_00001730_return
L_00001730_fault:
mov w0, #-1
b L_00001730_return
L_00001730_miss:
mov w0, #3
b L_00001730_return
L_00001730_mode_miss:
mov w0, #4
L_00001730_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00001776
_agr_game_compiled_00001776:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00001776_mode_miss
movz w12, #6006
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #8192
cmp w14, w12
b.ne L_00001776_miss
movz w12, #6008
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #57444
cmp w14, w12
b.ne L_00001776_miss
movz w12, #0
str w12, [x9, #0]
cmp w12, #0
mrs x13, nzcv
ldr w14, [x10]
and w13, w13, #0xc0000000
and w14, w14, #0x3fffffff
orr w14, w14, w13
str w14, [x10]
movz w12, #6212
add w12, w15, w12
str w12, [x9, #60]
b L_00001776_success
L_00001776_success:
mov w0, #1
b L_00001776_return
L_00001776_fault:
mov w0, #-1
b L_00001776_return
L_00001776_miss:
mov w0, #3
b L_00001776_return
L_00001776_mode_miss:
mov w0, #4
L_00001776_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00001846
_agr_game_compiled_00001846:
sub sp, sp, #64
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00001846_mode_miss
movz w12, #6214
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #59581
movk w12, #33264, lsl #16
cmp w14, w12
b.ne L_00001846_miss
ldr w12, [x9, #52]
movz w13, #0
add w14, w12, w13
cmp w14, #0x1000
b.lo L_00001846_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w14, w13
b.hi L_00001846_fault
add x13, x11, w14, uxtw
ldr w14, [x13]
str w14, [sp, #0]
movz w13, #4
add w14, w12, w13
cmp w14, #0x1000
b.lo L_00001846_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w14, w13
b.hi L_00001846_fault
add x13, x11, w14, uxtw
ldr w14, [x13]
str w14, [sp, #4]
movz w13, #8
add w14, w12, w13
cmp w14, #0x1000
b.lo L_00001846_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w14, w13
b.hi L_00001846_fault
add x13, x11, w14, uxtw
ldr w14, [x13]
str w14, [sp, #8]
movz w13, #12
add w14, w12, w13
cmp w14, #0x1000
b.lo L_00001846_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w14, w13
b.hi L_00001846_fault
add x13, x11, w14, uxtw
ldr w14, [x13]
str w14, [sp, #12]
movz w13, #16
add w14, w12, w13
cmp w14, #0x1000
b.lo L_00001846_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w14, w13
b.hi L_00001846_fault
add x13, x11, w14, uxtw
ldr w14, [x13]
str w14, [sp, #16]
movz w13, #20
add w14, w12, w13
cmp w14, #0x1000
b.lo L_00001846_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w14, w13
b.hi L_00001846_fault
add x13, x11, w14, uxtw
ldr w14, [x13]
str w14, [sp, #20]
movz w13, #24
add w12, w12, w13
str w12, [x9, #52]
ldr w12, [sp, #0]
str w12, [x9, #16]
ldr w12, [sp, #4]
str w12, [x9, #20]
ldr w12, [sp, #8]
str w12, [x9, #24]
ldr w12, [sp, #12]
str w12, [x9, #28]
ldr w12, [sp, #16]
str w12, [x9, #32]
ldr w12, [sp, #20]
str w12, [x9, #60]
ldr w12, [x9, #60]
ldr w13, [x10]
and w14, w12, #1
lsl w14, w14, #5
bic w13, w13, #0x20
orr w13, w13, w14
str w13, [x10]
bic w12, w12, #1
str w12, [x9, #60]
b L_00001846_success
L_00001846_success:
mov w0, #1
b L_00001846_return
L_00001846_fault:
mov w0, #-1
b L_00001846_return
L_00001846_miss:
mov w0, #3
b L_00001846_return
L_00001846_mode_miss:
mov w0, #4
L_00001846_return:
add sp, sp, #64
ret

.text
.p2align 2
.globl _agr_game_compiled_0000184c
_agr_game_compiled_0000184c:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_0000184c_mode_miss
movz w12, #6220
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #61696
movk w12, #308, lsl #16
cmp w14, w12
b.ne L_0000184c_miss
ldr w12, [x9, #0]
movz w13, #52
add w12, w12, w13
str w12, [x9, #4]
movz w12, #6224
add w12, w15, w12
str w12, [x9, #60]
L_0000184c_success:
mov w0, #1
b L_0000184c_return
L_0000184c_fault:
mov w0, #-1
b L_0000184c_return
L_0000184c_miss:
mov w0, #3
b L_0000184c_return
L_0000184c_mode_miss:
mov w0, #4
L_0000184c_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00001854
_agr_game_compiled_00001854:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00001854_mode_miss
movz w12, #6228
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #18076
cmp w14, w12
b.ne L_00001854_miss
movz w12, #6230
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #18086
cmp w14, w12
b.ne L_00001854_miss
ldr w12, [x9, #12]
str w12, [x9, #48]
ldr w12, [x9, #16]
str w12, [x9, #56]
movz w12, #6232
add w12, w15, w12
str w12, [x9, #60]
L_00001854_success:
mov w0, #1
b L_00001854_return
L_00001854_fault:
mov w0, #-1
b L_00001854_return
L_00001854_miss:
mov w0, #3
b L_00001854_return
L_00001854_mode_miss:
mov w0, #4
L_00001854_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00001860
_agr_game_compiled_00001860:
sub sp, sp, #64
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00001860_mode_miss
movz w12, #6240
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #18149
cmp w14, w12
b.ne L_00001860_miss
movz w12, #6242
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #48384
cmp w14, w12
b.ne L_00001860_miss
ldr w12, [x9, #48]
str w12, [x9, #52]
ldr w12, [x9, #52]
movz w13, #0
add w14, w12, w13
cmp w14, #0x1000
b.lo L_00001860_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w14, w13
b.hi L_00001860_fault
add x13, x11, w14, uxtw
ldr w14, [x13]
str w14, [sp, #0]
movz w13, #4
add w12, w12, w13
str w12, [x9, #52]
ldr w12, [sp, #0]
str w12, [x9, #60]
ldr w12, [x9, #60]
ldr w13, [x10]
and w14, w12, #1
lsl w14, w14, #5
bic w13, w13, #0x20
orr w13, w13, w14
str w13, [x10]
bic w12, w12, #1
str w12, [x9, #60]
b L_00001860_success
L_00001860_success:
mov w0, #1
b L_00001860_return
L_00001860_fault:
mov w0, #-1
b L_00001860_return
L_00001860_miss:
mov w0, #3
b L_00001860_return
L_00001860_mode_miss:
mov w0, #4
L_00001860_return:
add sp, sp, #64
ret

.text
.p2align 2
.globl _agr_game_compiled_00001868
_agr_game_compiled_00001868:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00001868_mode_miss
movz w12, #6248
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #18288
cmp w14, w12
b.ne L_00001868_miss
ldr w12, [x9, #56]
ldr w13, [x10]
and w14, w12, #1
lsl w14, w14, #5
bic w13, w13, #0x20
orr w13, w13, w14
str w13, [x10]
bic w12, w12, #1
str w12, [x9, #60]
b L_00001868_success
L_00001868_success:
mov w0, #1
b L_00001868_return
L_00001868_fault:
mov w0, #-1
b L_00001868_return
L_00001868_miss:
mov w0, #3
b L_00001868_return
L_00001868_mode_miss:
mov w0, #4
L_00001868_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00001870
_agr_game_compiled_00001870:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00001870_mode_miss
movz w12, #6256
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #18288
cmp w14, w12
b.ne L_00001870_miss
ldr w12, [x9, #56]
ldr w13, [x10]
and w14, w12, #1
lsl w14, w14, #5
bic w13, w13, #0x20
orr w13, w13, w14
str w13, [x10]
bic w12, w12, #1
str w12, [x9, #60]
b L_00001870_success
L_00001870_success:
mov w0, #1
b L_00001870_return
L_00001870_fault:
mov w0, #-1
b L_00001870_return
L_00001870_miss:
mov w0, #3
b L_00001870_return
L_00001870_mode_miss:
mov w0, #4
L_00001870_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00001878
_agr_game_compiled_00001878:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00001878_mode_miss
movz w12, #6264
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #18288
cmp w14, w12
b.ne L_00001878_miss
ldr w12, [x9, #56]
ldr w13, [x10]
and w14, w12, #1
lsl w14, w14, #5
bic w13, w13, #0x20
orr w13, w13, w14
str w13, [x10]
bic w12, w12, #1
str w12, [x9, #60]
b L_00001878_success
L_00001878_success:
mov w0, #1
b L_00001878_return
L_00001878_fault:
mov w0, #-1
b L_00001878_return
L_00001878_miss:
mov w0, #3
b L_00001878_return
L_00001878_mode_miss:
mov w0, #4
L_00001878_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00001880
_agr_game_compiled_00001880:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00001880_mode_miss
movz w12, #6272
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #18288
cmp w14, w12
b.ne L_00001880_miss
ldr w12, [x9, #56]
ldr w13, [x10]
and w14, w12, #1
lsl w14, w14, #5
bic w13, w13, #0x20
orr w13, w13, w14
str w13, [x10]
bic w12, w12, #1
str w12, [x9, #60]
b L_00001880_success
L_00001880_success:
mov w0, #1
b L_00001880_return
L_00001880_fault:
mov w0, #-1
b L_00001880_return
L_00001880_miss:
mov w0, #3
b L_00001880_return
L_00001880_mode_miss:
mov w0, #4
L_00001880_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00001888
_agr_game_compiled_00001888:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00001888_mode_miss
movz w12, #6280
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #18288
cmp w14, w12
b.ne L_00001888_miss
ldr w12, [x9, #56]
ldr w13, [x10]
and w14, w12, #1
lsl w14, w14, #5
bic w13, w13, #0x20
orr w13, w13, w14
str w13, [x10]
bic w12, w12, #1
str w12, [x9, #60]
b L_00001888_success
L_00001888_success:
mov w0, #1
b L_00001888_return
L_00001888_fault:
mov w0, #-1
b L_00001888_return
L_00001888_miss:
mov w0, #3
b L_00001888_return
L_00001888_mode_miss:
mov w0, #4
L_00001888_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00001890
_agr_game_compiled_00001890:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00001890_mode_miss
movz w12, #6288
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #18288
cmp w14, w12
b.ne L_00001890_miss
ldr w12, [x9, #56]
ldr w13, [x10]
and w14, w12, #1
lsl w14, w14, #5
bic w13, w13, #0x20
orr w13, w13, w14
str w13, [x10]
bic w12, w12, #1
str w12, [x9, #60]
b L_00001890_success
L_00001890_success:
mov w0, #1
b L_00001890_return
L_00001890_fault:
mov w0, #-1
b L_00001890_return
L_00001890_miss:
mov w0, #3
b L_00001890_return
L_00001890_mode_miss:
mov w0, #4
L_00001890_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_000018d4
_agr_game_compiled_000018d4:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_000018d4_mode_miss
movz w12, #6356
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #18288
cmp w14, w12
b.ne L_000018d4_miss
ldr w12, [x9, #56]
ldr w13, [x10]
and w14, w12, #1
lsl w14, w14, #5
bic w13, w13, #0x20
orr w13, w13, w14
str w13, [x10]
bic w12, w12, #1
str w12, [x9, #60]
b L_000018d4_success
L_000018d4_success:
mov w0, #1
b L_000018d4_return
L_000018d4_fault:
mov w0, #-1
b L_000018d4_return
L_000018d4_miss:
mov w0, #3
b L_000018d4_return
L_000018d4_mode_miss:
mov w0, #4
L_000018d4_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00001918
_agr_game_compiled_00001918:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00001918_mode_miss
movz w12, #6424
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #18288
cmp w14, w12
b.ne L_00001918_miss
ldr w12, [x9, #56]
ldr w13, [x10]
and w14, w12, #1
lsl w14, w14, #5
bic w13, w13, #0x20
orr w13, w13, w14
str w13, [x10]
bic w12, w12, #1
str w12, [x9, #60]
b L_00001918_success
L_00001918_success:
mov w0, #1
b L_00001918_return
L_00001918_fault:
mov w0, #-1
b L_00001918_return
L_00001918_miss:
mov w0, #3
b L_00001918_return
L_00001918_mode_miss:
mov w0, #4
L_00001918_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_0000192c
_agr_game_compiled_0000192c:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_0000192c_mode_miss
movz w12, #6444
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #18288
cmp w14, w12
b.ne L_0000192c_miss
ldr w12, [x9, #56]
ldr w13, [x10]
and w14, w12, #1
lsl w14, w14, #5
bic w13, w13, #0x20
orr w13, w13, w14
str w13, [x10]
bic w12, w12, #1
str w12, [x9, #60]
b L_0000192c_success
L_0000192c_success:
mov w0, #1
b L_0000192c_return
L_0000192c_fault:
mov w0, #-1
b L_0000192c_return
L_0000192c_miss:
mov w0, #3
b L_0000192c_return
L_0000192c_mode_miss:
mov w0, #4
L_0000192c_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00001940
_agr_game_compiled_00001940:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00001940_mode_miss
movz w12, #6464
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #18288
cmp w14, w12
b.ne L_00001940_miss
ldr w12, [x9, #56]
ldr w13, [x10]
and w14, w12, #1
lsl w14, w14, #5
bic w13, w13, #0x20
orr w13, w13, w14
str w13, [x10]
bic w12, w12, #1
str w12, [x9, #60]
b L_00001940_success
L_00001940_success:
mov w0, #1
b L_00001940_return
L_00001940_fault:
mov w0, #-1
b L_00001940_return
L_00001940_miss:
mov w0, #3
b L_00001940_return
L_00001940_mode_miss:
mov w0, #4
L_00001940_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00001944
_agr_game_compiled_00001944:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00001944_mode_miss
movz w12, #6468
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #18156
cmp w14, w12
b.ne L_00001944_miss
movz w12, #6470
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #46336
cmp w14, w12
b.ne L_00001944_miss
movz w12, #6472
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #59693
movk w12, #20480, lsl #16
cmp w14, w12
b.ne L_00001944_miss
movz w12, #6476
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #59693
movk w12, #8191, lsl #16
cmp w14, w12
b.ne L_00001944_miss
movz w12, #6480
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #61519
movk w12, #768, lsl #16
cmp w14, w12
b.ne L_00001944_miss
movz w12, #6484
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #59693
movk w12, #12, lsl #16
cmp w14, w12
b.ne L_00001944_miss
movz w12, #6488
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #43265
cmp w14, w12
b.ne L_00001944_miss
movz w12, #6490
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #63487
movk w12, #64557, lsl #16
cmp w14, w12
b.ne L_00001944_miss
ldr w12, [x9, #52]
str w12, [x9, #48]
ldr w12, [x9, #52]
movz w13, #4
sub w12, w12, w13
cmp w12, #0x1000
b.lo L_00001944_fault
add x13, x11, w12, uxtw
ldr w14, [x9, #56]
str w14, [x13, #0]
str w12, [x9, #52]
ldr w12, [x9, #52]
movz w13, #8
sub w12, w12, w13
cmp w12, #0x1000
b.lo L_00001944_fault
add x13, x11, w12, uxtw
ldr w14, [x9, #48]
str w14, [x13, #0]
ldr w14, [x9, #56]
str w14, [x13, #4]
str w12, [x9, #52]
ldr w12, [x9, #52]
movz w13, #52
sub w12, w12, w13
cmp w12, #0x1000
b.lo L_00001944_fault
add x13, x11, w12, uxtw
ldr w14, [x9, #0]
str w14, [x13, #0]
ldr w14, [x9, #4]
str w14, [x13, #4]
ldr w14, [x9, #8]
str w14, [x13, #8]
ldr w14, [x9, #12]
str w14, [x13, #12]
ldr w14, [x9, #16]
str w14, [x13, #16]
ldr w14, [x9, #20]
str w14, [x13, #20]
ldr w14, [x9, #24]
str w14, [x13, #24]
ldr w14, [x9, #28]
str w14, [x13, #28]
ldr w14, [x9, #32]
str w14, [x13, #32]
ldr w14, [x9, #36]
str w14, [x13, #36]
ldr w14, [x9, #40]
str w14, [x13, #40]
ldr w14, [x9, #44]
str w14, [x13, #44]
ldr w14, [x9, #48]
str w14, [x13, #48]
str w12, [x9, #52]
movz w12, #0
str w12, [x9, #12]
ldr w12, [x9, #52]
movz w13, #8
sub w12, w12, w13
cmp w12, #0x1000
b.lo L_00001944_fault
add x13, x11, w12, uxtw
ldr w14, [x9, #8]
str w14, [x13, #0]
ldr w14, [x9, #12]
str w14, [x13, #4]
str w12, [x9, #52]
ldr w12, [x9, #52]
movz w13, #4
add w12, w12, w13
str w12, [x9, #4]
movz w12, #4536
add w12, w15, w12
orr w12, w12, #1
movz w13, #6494
add w13, w15, w13
orr w13, w13, #1
str w13, [x9, #56]
ldr w13, [x10]
and w14, w12, #1
lsl w14, w14, #5
bic w13, w13, #0x20
orr w13, w13, w14
str w13, [x10]
bic w12, w12, #1
str w12, [x9, #60]
b L_00001944_success
L_00001944_success:
mov w0, #1
b L_00001944_return
L_00001944_fault:
mov w0, #-1
b L_00001944_return
L_00001944_miss:
mov w0, #3
b L_00001944_return
L_00001944_mode_miss:
mov w0, #4
L_00001944_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_0000195e
_agr_game_compiled_0000195e:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_0000195e_mode_miss
movz w12, #6494
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #63709
movk w12, #57408, lsl #16
cmp w14, w12
b.ne L_0000195e_miss
ldr w12, [x9, #52]
movz w13, #64
add w12, w12, w13
cmp w12, #0x1000
b.lo L_0000195e_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w12, w13
b.hi L_0000195e_fault
add x13, x11, w12, uxtw
ldr w12, [x13]
str w12, [x9, #56]
movz w12, #6498
add w12, w15, w12
str w12, [x9, #60]
L_0000195e_success:
mov w0, #1
b L_0000195e_return
L_0000195e_fault:
mov w0, #-1
b L_0000195e_return
L_0000195e_miss:
mov w0, #3
b L_0000195e_return
L_0000195e_mode_miss:
mov w0, #4
L_0000195e_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00001964
_agr_game_compiled_00001964:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00001964_mode_miss
movz w12, #6500
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #18288
cmp w14, w12
b.ne L_00001964_miss
ldr w12, [x9, #56]
ldr w13, [x10]
and w14, w12, #1
lsl w14, w14, #5
bic w13, w13, #0x20
orr w13, w13, w14
str w13, [x10]
bic w12, w12, #1
str w12, [x9, #60]
b L_00001964_success
L_00001964_success:
mov w0, #1
b L_00001964_return
L_00001964_fault:
mov w0, #-1
b L_00001964_return
L_00001964_miss:
mov w0, #3
b L_00001964_return
L_00001964_mode_miss:
mov w0, #4
L_00001964_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00001968
_agr_game_compiled_00001968:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00001968_mode_miss
movz w12, #6504
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #18156
cmp w14, w12
b.ne L_00001968_miss
movz w12, #6506
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #46336
cmp w14, w12
b.ne L_00001968_miss
movz w12, #6508
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #59693
movk w12, #20480, lsl #16
cmp w14, w12
b.ne L_00001968_miss
movz w12, #6512
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #59693
movk w12, #8191, lsl #16
cmp w14, w12
b.ne L_00001968_miss
movz w12, #6516
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #61519
movk w12, #768, lsl #16
cmp w14, w12
b.ne L_00001968_miss
movz w12, #6520
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #59693
movk w12, #12, lsl #16
cmp w14, w12
b.ne L_00001968_miss
movz w12, #6524
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #43265
cmp w14, w12
b.ne L_00001968_miss
movz w12, #6526
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #63487
movk w12, #64598, lsl #16
cmp w14, w12
b.ne L_00001968_miss
ldr w12, [x9, #52]
str w12, [x9, #48]
ldr w12, [x9, #52]
movz w13, #4
sub w12, w12, w13
cmp w12, #0x1000
b.lo L_00001968_fault
add x13, x11, w12, uxtw
ldr w14, [x9, #56]
str w14, [x13, #0]
str w12, [x9, #52]
ldr w12, [x9, #52]
movz w13, #8
sub w12, w12, w13
cmp w12, #0x1000
b.lo L_00001968_fault
add x13, x11, w12, uxtw
ldr w14, [x9, #48]
str w14, [x13, #0]
ldr w14, [x9, #56]
str w14, [x13, #4]
str w12, [x9, #52]
ldr w12, [x9, #52]
movz w13, #52
sub w12, w12, w13
cmp w12, #0x1000
b.lo L_00001968_fault
add x13, x11, w12, uxtw
ldr w14, [x9, #0]
str w14, [x13, #0]
ldr w14, [x9, #4]
str w14, [x13, #4]
ldr w14, [x9, #8]
str w14, [x13, #8]
ldr w14, [x9, #12]
str w14, [x13, #12]
ldr w14, [x9, #16]
str w14, [x13, #16]
ldr w14, [x9, #20]
str w14, [x13, #20]
ldr w14, [x9, #24]
str w14, [x13, #24]
ldr w14, [x9, #28]
str w14, [x13, #28]
ldr w14, [x9, #32]
str w14, [x13, #32]
ldr w14, [x9, #36]
str w14, [x13, #36]
ldr w14, [x9, #40]
str w14, [x13, #40]
ldr w14, [x9, #44]
str w14, [x13, #44]
ldr w14, [x9, #48]
str w14, [x13, #48]
str w12, [x9, #52]
movz w12, #0
str w12, [x9, #12]
ldr w12, [x9, #52]
movz w13, #8
sub w12, w12, w13
cmp w12, #0x1000
b.lo L_00001968_fault
add x13, x11, w12, uxtw
ldr w14, [x9, #8]
str w14, [x13, #0]
ldr w14, [x9, #12]
str w14, [x13, #4]
str w12, [x9, #52]
ldr w12, [x9, #52]
movz w13, #4
add w12, w12, w13
str w12, [x9, #4]
movz w12, #4654
add w12, w15, w12
orr w12, w12, #1
movz w13, #6530
add w13, w15, w13
orr w13, w13, #1
str w13, [x9, #56]
ldr w13, [x10]
and w14, w12, #1
lsl w14, w14, #5
bic w13, w13, #0x20
orr w13, w13, w14
str w13, [x10]
bic w12, w12, #1
str w12, [x9, #60]
b L_00001968_success
L_00001968_success:
mov w0, #1
b L_00001968_return
L_00001968_fault:
mov w0, #-1
b L_00001968_return
L_00001968_miss:
mov w0, #3
b L_00001968_return
L_00001968_mode_miss:
mov w0, #4
L_00001968_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00001982
_agr_game_compiled_00001982:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00001982_mode_miss
movz w12, #6530
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #63709
movk w12, #57408, lsl #16
cmp w14, w12
b.ne L_00001982_miss
ldr w12, [x9, #52]
movz w13, #64
add w12, w12, w13
cmp w12, #0x1000
b.lo L_00001982_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w12, w13
b.hi L_00001982_fault
add x13, x11, w12, uxtw
ldr w12, [x13]
str w12, [x9, #56]
movz w12, #6534
add w12, w15, w12
str w12, [x9, #60]
L_00001982_success:
mov w0, #1
b L_00001982_return
L_00001982_fault:
mov w0, #-1
b L_00001982_return
L_00001982_miss:
mov w0, #3
b L_00001982_return
L_00001982_mode_miss:
mov w0, #4
L_00001982_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00001988
_agr_game_compiled_00001988:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00001988_mode_miss
movz w12, #6536
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #18288
cmp w14, w12
b.ne L_00001988_miss
ldr w12, [x9, #56]
ldr w13, [x10]
and w14, w12, #1
lsl w14, w14, #5
bic w13, w13, #0x20
orr w13, w13, w14
str w13, [x10]
bic w12, w12, #1
str w12, [x9, #60]
b L_00001988_success
L_00001988_success:
mov w0, #1
b L_00001988_return
L_00001988_fault:
mov w0, #-1
b L_00001988_return
L_00001988_miss:
mov w0, #3
b L_00001988_return
L_00001988_mode_miss:
mov w0, #4
L_00001988_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_0000198c
_agr_game_compiled_0000198c:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_0000198c_mode_miss
movz w12, #6540
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #18156
cmp w14, w12
b.ne L_0000198c_miss
movz w12, #6542
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #46336
cmp w14, w12
b.ne L_0000198c_miss
movz w12, #6544
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #59693
movk w12, #20480, lsl #16
cmp w14, w12
b.ne L_0000198c_miss
movz w12, #6548
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #59693
movk w12, #8191, lsl #16
cmp w14, w12
b.ne L_0000198c_miss
movz w12, #6552
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #61519
movk w12, #768, lsl #16
cmp w14, w12
b.ne L_0000198c_miss
movz w12, #6556
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #59693
movk w12, #12, lsl #16
cmp w14, w12
b.ne L_0000198c_miss
movz w12, #6560
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #43265
cmp w14, w12
b.ne L_0000198c_miss
movz w12, #6562
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #63487
movk w12, #64613, lsl #16
cmp w14, w12
b.ne L_0000198c_miss
ldr w12, [x9, #52]
str w12, [x9, #48]
ldr w12, [x9, #52]
movz w13, #4
sub w12, w12, w13
cmp w12, #0x1000
b.lo L_0000198c_fault
add x13, x11, w12, uxtw
ldr w14, [x9, #56]
str w14, [x13, #0]
str w12, [x9, #52]
ldr w12, [x9, #52]
movz w13, #8
sub w12, w12, w13
cmp w12, #0x1000
b.lo L_0000198c_fault
add x13, x11, w12, uxtw
ldr w14, [x9, #48]
str w14, [x13, #0]
ldr w14, [x9, #56]
str w14, [x13, #4]
str w12, [x9, #52]
ldr w12, [x9, #52]
movz w13, #52
sub w12, w12, w13
cmp w12, #0x1000
b.lo L_0000198c_fault
add x13, x11, w12, uxtw
ldr w14, [x9, #0]
str w14, [x13, #0]
ldr w14, [x9, #4]
str w14, [x13, #4]
ldr w14, [x9, #8]
str w14, [x13, #8]
ldr w14, [x9, #12]
str w14, [x13, #12]
ldr w14, [x9, #16]
str w14, [x13, #16]
ldr w14, [x9, #20]
str w14, [x13, #20]
ldr w14, [x9, #24]
str w14, [x13, #24]
ldr w14, [x9, #28]
str w14, [x13, #28]
ldr w14, [x9, #32]
str w14, [x13, #32]
ldr w14, [x9, #36]
str w14, [x13, #36]
ldr w14, [x9, #40]
str w14, [x13, #40]
ldr w14, [x9, #44]
str w14, [x13, #44]
ldr w14, [x9, #48]
str w14, [x13, #48]
str w12, [x9, #52]
movz w12, #0
str w12, [x9, #12]
ldr w12, [x9, #52]
movz w13, #8
sub w12, w12, w13
cmp w12, #0x1000
b.lo L_0000198c_fault
add x13, x11, w12, uxtw
ldr w14, [x9, #8]
str w14, [x13, #0]
ldr w14, [x9, #12]
str w14, [x13, #4]
str w12, [x9, #52]
ldr w12, [x9, #52]
movz w13, #4
add w12, w12, w13
str w12, [x9, #4]
movz w12, #4720
add w12, w15, w12
orr w12, w12, #1
movz w13, #6566
add w13, w15, w13
orr w13, w13, #1
str w13, [x9, #56]
ldr w13, [x10]
and w14, w12, #1
lsl w14, w14, #5
bic w13, w13, #0x20
orr w13, w13, w14
str w13, [x10]
bic w12, w12, #1
str w12, [x9, #60]
b L_0000198c_success
L_0000198c_success:
mov w0, #1
b L_0000198c_return
L_0000198c_fault:
mov w0, #-1
b L_0000198c_return
L_0000198c_miss:
mov w0, #3
b L_0000198c_return
L_0000198c_mode_miss:
mov w0, #4
L_0000198c_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_000019a6
_agr_game_compiled_000019a6:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_000019a6_mode_miss
movz w12, #6566
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #63709
movk w12, #57408, lsl #16
cmp w14, w12
b.ne L_000019a6_miss
ldr w12, [x9, #52]
movz w13, #64
add w12, w12, w13
cmp w12, #0x1000
b.lo L_000019a6_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w12, w13
b.hi L_000019a6_fault
add x13, x11, w12, uxtw
ldr w12, [x13]
str w12, [x9, #56]
movz w12, #6570
add w12, w15, w12
str w12, [x9, #60]
L_000019a6_success:
mov w0, #1
b L_000019a6_return
L_000019a6_fault:
mov w0, #-1
b L_000019a6_return
L_000019a6_miss:
mov w0, #3
b L_000019a6_return
L_000019a6_mode_miss:
mov w0, #4
L_000019a6_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_000019ac
_agr_game_compiled_000019ac:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_000019ac_mode_miss
movz w12, #6572
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #18288
cmp w14, w12
b.ne L_000019ac_miss
ldr w12, [x9, #56]
ldr w13, [x10]
and w14, w12, #1
lsl w14, w14, #5
bic w13, w13, #0x20
orr w13, w13, w14
str w13, [x10]
bic w12, w12, #1
str w12, [x9, #60]
b L_000019ac_success
L_000019ac_success:
mov w0, #1
b L_000019ac_return
L_000019ac_fault:
mov w0, #-1
b L_000019ac_return
L_000019ac_miss:
mov w0, #3
b L_000019ac_return
L_000019ac_mode_miss:
mov w0, #4
L_000019ac_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_000019b0
_agr_game_compiled_000019b0:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_000019b0_mode_miss
movz w12, #6576
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #18156
cmp w14, w12
b.ne L_000019b0_miss
movz w12, #6578
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #46336
cmp w14, w12
b.ne L_000019b0_miss
movz w12, #6580
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #59693
movk w12, #20480, lsl #16
cmp w14, w12
b.ne L_000019b0_miss
movz w12, #6584
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #59693
movk w12, #8191, lsl #16
cmp w14, w12
b.ne L_000019b0_miss
movz w12, #6588
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #61519
movk w12, #768, lsl #16
cmp w14, w12
b.ne L_000019b0_miss
movz w12, #6592
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #59693
movk w12, #12, lsl #16
cmp w14, w12
b.ne L_000019b0_miss
movz w12, #6596
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #43777
cmp w14, w12
b.ne L_000019b0_miss
movz w12, #6598
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #63487
movk w12, #64552, lsl #16
cmp w14, w12
b.ne L_000019b0_miss
ldr w12, [x9, #52]
str w12, [x9, #48]
ldr w12, [x9, #52]
movz w13, #4
sub w12, w12, w13
cmp w12, #0x1000
b.lo L_000019b0_fault
add x13, x11, w12, uxtw
ldr w14, [x9, #56]
str w14, [x13, #0]
str w12, [x9, #52]
ldr w12, [x9, #52]
movz w13, #8
sub w12, w12, w13
cmp w12, #0x1000
b.lo L_000019b0_fault
add x13, x11, w12, uxtw
ldr w14, [x9, #48]
str w14, [x13, #0]
ldr w14, [x9, #56]
str w14, [x13, #4]
str w12, [x9, #52]
ldr w12, [x9, #52]
movz w13, #52
sub w12, w12, w13
cmp w12, #0x1000
b.lo L_000019b0_fault
add x13, x11, w12, uxtw
ldr w14, [x9, #0]
str w14, [x13, #0]
ldr w14, [x9, #4]
str w14, [x13, #4]
ldr w14, [x9, #8]
str w14, [x13, #8]
ldr w14, [x9, #12]
str w14, [x13, #12]
ldr w14, [x9, #16]
str w14, [x13, #16]
ldr w14, [x9, #20]
str w14, [x13, #20]
ldr w14, [x9, #24]
str w14, [x13, #24]
ldr w14, [x9, #28]
str w14, [x13, #28]
ldr w14, [x9, #32]
str w14, [x13, #32]
ldr w14, [x9, #36]
str w14, [x13, #36]
ldr w14, [x9, #40]
str w14, [x13, #40]
ldr w14, [x9, #44]
str w14, [x13, #44]
ldr w14, [x9, #48]
str w14, [x13, #48]
str w12, [x9, #52]
movz w12, #0
str w12, [x9, #12]
ldr w12, [x9, #52]
movz w13, #8
sub w12, w12, w13
cmp w12, #0x1000
b.lo L_000019b0_fault
add x13, x11, w12, uxtw
ldr w14, [x9, #8]
str w14, [x13, #0]
ldr w14, [x9, #12]
str w14, [x13, #4]
str w12, [x9, #52]
ldr w12, [x9, #52]
movz w13, #4
add w12, w12, w13
str w12, [x9, #12]
movz w12, #4634
add w12, w15, w12
orr w12, w12, #1
movz w13, #6602
add w13, w15, w13
orr w13, w13, #1
str w13, [x9, #56]
ldr w13, [x10]
and w14, w12, #1
lsl w14, w14, #5
bic w13, w13, #0x20
orr w13, w13, w14
str w13, [x10]
bic w12, w12, #1
str w12, [x9, #60]
b L_000019b0_success
L_000019b0_success:
mov w0, #1
b L_000019b0_return
L_000019b0_fault:
mov w0, #-1
b L_000019b0_return
L_000019b0_miss:
mov w0, #3
b L_000019b0_return
L_000019b0_mode_miss:
mov w0, #4
L_000019b0_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_000019ca
_agr_game_compiled_000019ca:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_000019ca_mode_miss
movz w12, #6602
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #63709
movk w12, #57408, lsl #16
cmp w14, w12
b.ne L_000019ca_miss
ldr w12, [x9, #52]
movz w13, #64
add w12, w12, w13
cmp w12, #0x1000
b.lo L_000019ca_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w12, w13
b.hi L_000019ca_fault
add x13, x11, w12, uxtw
ldr w12, [x13]
str w12, [x9, #56]
movz w12, #6606
add w12, w15, w12
str w12, [x9, #60]
L_000019ca_success:
mov w0, #1
b L_000019ca_return
L_000019ca_fault:
mov w0, #-1
b L_000019ca_return
L_000019ca_miss:
mov w0, #3
b L_000019ca_return
L_000019ca_mode_miss:
mov w0, #4
L_000019ca_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_000019d0
_agr_game_compiled_000019d0:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_000019d0_mode_miss
movz w12, #6608
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #18288
cmp w14, w12
b.ne L_000019d0_miss
ldr w12, [x9, #56]
ldr w13, [x10]
and w14, w12, #1
lsl w14, w14, #5
bic w13, w13, #0x20
orr w13, w13, w14
str w13, [x10]
bic w12, w12, #1
str w12, [x9, #60]
b L_000019d0_success
L_000019d0_success:
mov w0, #1
b L_000019d0_return
L_000019d0_fault:
mov w0, #-1
b L_000019d0_return
L_000019d0_miss:
mov w0, #3
b L_000019d0_return
L_000019d0_mode_miss:
mov w0, #4
L_000019d0_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_000019d4
_agr_game_compiled_000019d4:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_000019d4_mode_miss
movz w12, #6612
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #18156
cmp w14, w12
b.ne L_000019d4_miss
movz w12, #6614
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #46336
cmp w14, w12
b.ne L_000019d4_miss
movz w12, #6616
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #59693
movk w12, #20480, lsl #16
cmp w14, w12
b.ne L_000019d4_miss
movz w12, #6620
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #59693
movk w12, #8191, lsl #16
cmp w14, w12
b.ne L_000019d4_miss
movz w12, #6624
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #61519
movk w12, #768, lsl #16
cmp w14, w12
b.ne L_000019d4_miss
movz w12, #6628
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #59693
movk w12, #12, lsl #16
cmp w14, w12
b.ne L_000019d4_miss
movz w12, #6632
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #43521
cmp w14, w12
b.ne L_000019d4_miss
movz w12, #6634
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #63487
movk w12, #64662, lsl #16
cmp w14, w12
b.ne L_000019d4_miss
ldr w12, [x9, #52]
str w12, [x9, #48]
ldr w12, [x9, #52]
movz w13, #4
sub w12, w12, w13
cmp w12, #0x1000
b.lo L_000019d4_fault
add x13, x11, w12, uxtw
ldr w14, [x9, #56]
str w14, [x13, #0]
str w12, [x9, #52]
ldr w12, [x9, #52]
movz w13, #8
sub w12, w12, w13
cmp w12, #0x1000
b.lo L_000019d4_fault
add x13, x11, w12, uxtw
ldr w14, [x9, #48]
str w14, [x13, #0]
ldr w14, [x9, #56]
str w14, [x13, #4]
str w12, [x9, #52]
ldr w12, [x9, #52]
movz w13, #52
sub w12, w12, w13
cmp w12, #0x1000
b.lo L_000019d4_fault
add x13, x11, w12, uxtw
ldr w14, [x9, #0]
str w14, [x13, #0]
ldr w14, [x9, #4]
str w14, [x13, #4]
ldr w14, [x9, #8]
str w14, [x13, #8]
ldr w14, [x9, #12]
str w14, [x13, #12]
ldr w14, [x9, #16]
str w14, [x13, #16]
ldr w14, [x9, #20]
str w14, [x13, #20]
ldr w14, [x9, #24]
str w14, [x13, #24]
ldr w14, [x9, #28]
str w14, [x13, #28]
ldr w14, [x9, #32]
str w14, [x13, #32]
ldr w14, [x9, #36]
str w14, [x13, #36]
ldr w14, [x9, #40]
str w14, [x13, #40]
ldr w14, [x9, #44]
str w14, [x13, #44]
ldr w14, [x9, #48]
str w14, [x13, #48]
str w12, [x9, #52]
movz w12, #0
str w12, [x9, #12]
ldr w12, [x9, #52]
movz w13, #8
sub w12, w12, w13
cmp w12, #0x1000
b.lo L_000019d4_fault
add x13, x11, w12, uxtw
ldr w14, [x9, #8]
str w14, [x13, #0]
ldr w14, [x9, #12]
str w14, [x13, #4]
str w12, [x9, #52]
ldr w12, [x9, #52]
movz w13, #4
add w12, w12, w13
str w12, [x9, #8]
movz w12, #4890
add w12, w15, w12
orr w12, w12, #1
movz w13, #6638
add w13, w15, w13
orr w13, w13, #1
str w13, [x9, #56]
ldr w13, [x10]
and w14, w12, #1
lsl w14, w14, #5
bic w13, w13, #0x20
orr w13, w13, w14
str w13, [x10]
bic w12, w12, #1
str w12, [x9, #60]
b L_000019d4_success
L_000019d4_success:
mov w0, #1
b L_000019d4_return
L_000019d4_fault:
mov w0, #-1
b L_000019d4_return
L_000019d4_miss:
mov w0, #3
b L_000019d4_return
L_000019d4_mode_miss:
mov w0, #4
L_000019d4_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_000019ee
_agr_game_compiled_000019ee:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_000019ee_mode_miss
movz w12, #6638
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #63709
movk w12, #57408, lsl #16
cmp w14, w12
b.ne L_000019ee_miss
ldr w12, [x9, #52]
movz w13, #64
add w12, w12, w13
cmp w12, #0x1000
b.lo L_000019ee_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w12, w13
b.hi L_000019ee_fault
add x13, x11, w12, uxtw
ldr w12, [x13]
str w12, [x9, #56]
movz w12, #6642
add w12, w15, w12
str w12, [x9, #60]
L_000019ee_success:
mov w0, #1
b L_000019ee_return
L_000019ee_fault:
mov w0, #-1
b L_000019ee_return
L_000019ee_miss:
mov w0, #3
b L_000019ee_return
L_000019ee_mode_miss:
mov w0, #4
L_000019ee_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_000019f4
_agr_game_compiled_000019f4:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_000019f4_mode_miss
movz w12, #6644
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #18288
cmp w14, w12
b.ne L_000019f4_miss
ldr w12, [x9, #56]
ldr w13, [x10]
and w14, w12, #1
lsl w14, w14, #5
bic w13, w13, #0x20
orr w13, w13, w14
str w13, [x10]
bic w12, w12, #1
str w12, [x9, #60]
b L_000019f4_success
L_000019f4_success:
mov w0, #1
b L_000019f4_return
L_000019f4_fault:
mov w0, #-1
b L_000019f4_return
L_000019f4_miss:
mov w0, #3
b L_000019f4_return
L_000019f4_mode_miss:
mov w0, #4
L_000019f4_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_000019fa
_agr_game_compiled_000019fa:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_000019fa_mode_miss
movz w12, #6650
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #47443
cmp w14, w12
b.ne L_000019fa_miss
ldr w12, [x9, #12]
cbnz w12, L_000019fa_taken_0
movz w12, #6652
add w12, w15, w12
str w12, [x9, #60]
b L_000019fa_success
L_000019fa_taken_0:
movz w12, #6674
add w12, w15, w12
str w12, [x9, #60]
b L_000019fa_success
L_000019fa_success:
mov w0, #1
b L_000019fa_return
L_000019fa_fault:
mov w0, #-1
b L_000019fa_return
L_000019fa_miss:
mov w0, #3
b L_000019fa_return
L_000019fa_mode_miss:
mov w0, #4
L_000019fa_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_000019fe
_agr_game_compiled_000019fe:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_000019fe_mode_miss
movz w12, #6654
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #45435
cmp w14, w12
b.ne L_000019fe_miss
ldr w12, [x9, #12]
cbz w12, L_000019fe_taken_0
movz w12, #6656
add w12, w15, w12
str w12, [x9, #60]
b L_000019fe_success
L_000019fe_taken_0:
movz w12, #6688
add w12, w15, w12
str w12, [x9, #60]
b L_000019fe_success
L_000019fe_success:
mov w0, #1
b L_000019fe_return
L_000019fe_fault:
mov w0, #-1
b L_000019fe_return
L_000019fe_miss:
mov w0, #3
b L_000019fe_return
L_000019fe_mode_miss:
mov w0, #4
L_000019fe_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00001a04
_agr_game_compiled_00001a04:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00001a04_mode_miss
movz w12, #6660
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #26691
cmp w14, w12
b.ne L_00001a04_miss
ldr w12, [x9, #0]
movz w13, #4
add w12, w12, w13
cmp w12, #0x1000
b.lo L_00001a04_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w12, w13
b.hi L_00001a04_fault
add x13, x11, w12, uxtw
ldr w12, [x13]
str w12, [x9, #12]
movz w12, #6662
add w12, w15, w12
str w12, [x9, #60]
L_00001a04_success:
mov w0, #1
b L_00001a04_return
L_00001a04_fault:
mov w0, #-1
b L_00001a04_return
L_00001a04_miss:
mov w0, #3
b L_00001a04_return
L_00001a04_mode_miss:
mov w0, #4
L_00001a04_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00001a0a
_agr_game_compiled_00001a0a:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00001a0a_mode_miss
movz w12, #6666
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #26651
cmp w14, w12
b.ne L_00001a0a_miss
ldr w12, [x9, #12]
movz w13, #0
add w12, w12, w13
cmp w12, #0x1000
b.lo L_00001a0a_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w12, w13
b.hi L_00001a0a_fault
add x13, x11, w12, uxtw
ldr w12, [x13]
str w12, [x9, #12]
movz w12, #6668
add w12, w15, w12
str w12, [x9, #60]
L_00001a0a_success:
mov w0, #1
b L_00001a0a_return
L_00001a0a_fault:
mov w0, #-1
b L_00001a0a_return
L_00001a0a_miss:
mov w0, #3
b L_00001a0a_return
L_00001a0a_mode_miss:
mov w0, #4
L_00001a0a_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00001a0e
_agr_game_compiled_00001a0e:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00001a0e_mode_miss
movz w12, #6670
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #8963
cmp w14, w12
b.ne L_00001a0e_miss
movz w12, #6672
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #57344
cmp w14, w12
b.ne L_00001a0e_miss
movz w12, #3
str w12, [x9, #12]
cmp w12, #0
mrs x13, nzcv
ldr w14, [x10]
and w13, w13, #0xc0000000
and w14, w14, #0x3fffffff
orr w14, w14, w13
str w14, [x10]
movz w12, #6676
add w12, w15, w12
str w12, [x9, #60]
b L_00001a0e_success
L_00001a0e_success:
mov w0, #1
b L_00001a0e_return
L_00001a0e_fault:
mov w0, #-1
b L_00001a0e_return
L_00001a0e_miss:
mov w0, #3
b L_00001a0e_return
L_00001a0e_mode_miss:
mov w0, #4
L_00001a0e_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00001a16
_agr_game_compiled_00001a16:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00001a16_mode_miss
movz w12, #6678
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #26627
cmp w14, w12
b.ne L_00001a16_miss
ldr w12, [x9, #0]
movz w13, #0
add w12, w12, w13
cmp w12, #0x1000
b.lo L_00001a16_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w12, w13
b.hi L_00001a16_fault
add x13, x11, w12, uxtw
ldr w12, [x13]
str w12, [x9, #12]
movz w12, #6680
add w12, w15, w12
str w12, [x9, #60]
L_00001a16_success:
mov w0, #1
b L_00001a16_return
L_00001a16_fault:
mov w0, #-1
b L_00001a16_return
L_00001a16_miss:
mov w0, #3
b L_00001a16_return
L_00001a16_mode_miss:
mov w0, #4
L_00001a16_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00001a1e
_agr_game_compiled_00001a1e:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00001a1e_mode_miss
movz w12, #6686
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #18288
cmp w14, w12
b.ne L_00001a1e_miss
ldr w12, [x9, #56]
ldr w13, [x10]
and w14, w12, #1
lsl w14, w14, #5
bic w13, w13, #0x20
orr w13, w13, w14
str w13, [x10]
bic w12, w12, #1
str w12, [x9, #60]
b L_00001a1e_success
L_00001a1e_success:
mov w0, #1
b L_00001a1e_return
L_00001a1e_fault:
mov w0, #-1
b L_00001a1e_return
L_00001a1e_miss:
mov w0, #3
b L_00001a1e_return
L_00001a1e_mode_miss:
mov w0, #4
L_00001a1e_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00001a20
_agr_game_compiled_00001a20:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00001a20_mode_miss
movz w12, #6688
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #8368
cmp w14, w12
b.ne L_00001a20_miss
movz w12, #6690
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #18288
cmp w14, w12
b.ne L_00001a20_miss
movz w12, #176
str w12, [x9, #0]
cmp w12, #0
mrs x13, nzcv
ldr w14, [x10]
and w13, w13, #0xc0000000
and w14, w14, #0x3fffffff
orr w14, w14, w13
str w14, [x10]
ldr w12, [x9, #56]
ldr w13, [x10]
and w14, w12, #1
lsl w14, w14, #5
bic w13, w13, #0x20
orr w13, w13, w14
str w13, [x10]
bic w12, w12, #1
str w12, [x9, #60]
b L_00001a20_success
L_00001a20_success:
mov w0, #1
b L_00001a20_return
L_00001a20_fault:
mov w0, #-1
b L_00001a20_return
L_00001a20_miss:
mov w0, #3
b L_00001a20_return
L_00001a20_mode_miss:
mov w0, #4
L_00001a20_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00001a24
_agr_game_compiled_00001a24:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00001a24_mode_miss
movz w12, #6692
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #46367
cmp w14, w12
b.ne L_00001a24_miss
movz w12, #6694
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #8448
cmp w14, w12
b.ne L_00001a24_miss
movz w12, #6696
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #43779
cmp w14, w12
b.ne L_00001a24_miss
movz w12, #6698
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #8716
cmp w14, w12
b.ne L_00001a24_miss
ldr w12, [x9, #52]
movz w13, #24
sub w12, w12, w13
cmp w12, #0x1000
b.lo L_00001a24_fault
add x13, x11, w12, uxtw
ldr w14, [x9, #0]
str w14, [x13, #0]
ldr w14, [x9, #4]
str w14, [x13, #4]
ldr w14, [x9, #8]
str w14, [x13, #8]
ldr w14, [x9, #12]
str w14, [x13, #12]
ldr w14, [x9, #16]
str w14, [x13, #16]
ldr w14, [x9, #56]
str w14, [x13, #20]
str w12, [x9, #52]
movz w12, #0
str w12, [x9, #4]
cmp w12, #0
mrs x13, nzcv
ldr w14, [x10]
and w13, w13, #0xc0000000
and w14, w14, #0x3fffffff
orr w14, w14, w13
str w14, [x10]
ldr w12, [x9, #52]
movz w13, #12
add w12, w12, w13
str w12, [x9, #12]
movz w12, #12
str w12, [x9, #8]
cmp w12, #0
mrs x13, nzcv
ldr w14, [x10]
and w13, w13, #0xc0000000
and w14, w14, #0x3fffffff
orr w14, w14, w13
str w14, [x10]
movz w12, #6700
add w12, w15, w12
str w12, [x9, #60]
L_00001a24_success:
mov w0, #1
b L_00001a24_return
L_00001a24_fault:
mov w0, #-1
b L_00001a24_return
L_00001a24_miss:
mov w0, #3
b L_00001a24_return
L_00001a24_mode_miss:
mov w0, #4
L_00001a24_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00001a2e
_agr_game_compiled_00001a2e:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00001a2e_mode_miss
movz w12, #6702
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #17931
cmp w14, w12
b.ne L_00001a2e_miss
movz w12, #6704
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #63487
movk w12, #64558, lsl #16
cmp w14, w12
b.ne L_00001a2e_miss
ldr w12, [x9, #4]
str w12, [x9, #12]
movz w12, #4752
add w12, w15, w12
orr w12, w12, #1
movz w13, #6708
add w13, w15, w13
orr w13, w13, #1
str w13, [x9, #56]
ldr w13, [x10]
and w14, w12, #1
lsl w14, w14, #5
bic w13, w13, #0x20
orr w13, w13, w14
str w13, [x10]
bic w12, w12, #1
str w12, [x9, #60]
b L_00001a2e_success
L_00001a2e_success:
mov w0, #1
b L_00001a2e_return
L_00001a2e_fault:
mov w0, #-1
b L_00001a2e_return
L_00001a2e_miss:
mov w0, #3
b L_00001a2e_return
L_00001a2e_mode_miss:
mov w0, #4
L_00001a2e_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00001a34
_agr_game_compiled_00001a34:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00001a34_mode_miss
movz w12, #6708
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #38915
cmp w14, w12
b.ne L_00001a34_miss
ldr w12, [x9, #52]
movz w13, #12
add w12, w12, w13
cmp w12, #0x1000
b.lo L_00001a34_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w12, w13
b.hi L_00001a34_fault
add x13, x11, w12, uxtw
ldr w12, [x13]
str w12, [x9, #0]
movz w12, #6710
add w12, w15, w12
str w12, [x9, #60]
L_00001a34_success:
mov w0, #1
b L_00001a34_return
L_00001a34_fault:
mov w0, #-1
b L_00001a34_return
L_00001a34_miss:
mov w0, #3
b L_00001a34_return
L_00001a34_mode_miss:
mov w0, #4
L_00001a34_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00001a3c
_agr_game_compiled_00001a3c:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00001a3c_mode_miss
movz w12, #6716
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #59378
cmp w14, w12
b.ne L_00001a3c_miss
movz w12, #6692
add w12, w15, w12
str w12, [x9, #60]
b L_00001a3c_success
L_00001a3c_success:
mov w0, #1
b L_00001a3c_return
L_00001a3c_fault:
mov w0, #-1
b L_00001a3c_return
L_00001a3c_miss:
mov w0, #3
b L_00001a3c_return
L_00001a3c_mode_miss:
mov w0, #4
L_00001a3c_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00001a3e
_agr_game_compiled_00001a3e:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00001a3e_mode_miss
movz w12, #6718
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #59693
movk w12, #18431, lsl #16
cmp w14, w12
b.ne L_00001a3e_miss
movz w12, #6722
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #17925
cmp w14, w12
b.ne L_00001a3e_miss
movz w12, #6724
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #17934
cmp w14, w12
b.ne L_00001a3e_miss
movz w12, #6726
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #9984
cmp w14, w12
b.ne L_00001a3e_miss
movz w12, #6728
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #61709
movk w12, #2060, lsl #16
cmp w14, w12
b.ne L_00001a3e_miss
movz w12, #6732
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #62543
movk w12, #27007, lsl #16
cmp w14, w12
b.ne L_00001a3e_miss
ldr w12, [x9, #52]
movz w13, #48
sub w12, w12, w13
cmp w12, #0x1000
b.lo L_00001a3e_fault
add x13, x11, w12, uxtw
ldr w14, [x9, #0]
str w14, [x13, #0]
ldr w14, [x9, #4]
str w14, [x13, #4]
ldr w14, [x9, #8]
str w14, [x13, #8]
ldr w14, [x9, #12]
str w14, [x13, #12]
ldr w14, [x9, #16]
str w14, [x13, #16]
ldr w14, [x9, #20]
str w14, [x13, #20]
ldr w14, [x9, #24]
str w14, [x13, #24]
ldr w14, [x9, #28]
str w14, [x13, #28]
ldr w14, [x9, #32]
str w14, [x13, #32]
ldr w14, [x9, #36]
str w14, [x13, #36]
ldr w14, [x9, #40]
str w14, [x13, #40]
ldr w14, [x9, #56]
str w14, [x13, #44]
str w12, [x9, #52]
ldr w12, [x9, #0]
str w12, [x9, #20]
ldr w12, [x9, #4]
str w12, [x9, #24]
movz w12, #0
str w12, [x9, #28]
cmp w12, #0
mrs x13, nzcv
ldr w14, [x10]
and w13, w13, #0xc0000000
and w14, w14, #0x3fffffff
orr w14, w14, w13
str w14, [x10]
ldr w12, [x9, #52]
movz w13, #12
add w12, w12, w13
str w12, [x9, #32]
movz w12, #4080
str w12, [x9, #36]
movz w12, #6736
add w12, w15, w12
str w12, [x9, #60]
L_00001a3e_success:
mov w0, #1
b L_00001a3e_return
L_00001a3e_fault:
mov w0, #-1
b L_00001a3e_return
L_00001a3e_miss:
mov w0, #3
b L_00001a3e_return
L_00001a3e_mode_miss:
mov w0, #4
L_00001a3e_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00001a50
_agr_game_compiled_00001a50:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00001a50_mode_miss
movz w12, #6736
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #17968
cmp w14, w12
b.ne L_00001a50_miss
movz w12, #6738
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #63487
movk w12, #65489, lsl #16
cmp w14, w12
b.ne L_00001a50_miss
ldr w12, [x9, #24]
str w12, [x9, #0]
movz w12, #6648
add w12, w15, w12
orr w12, w12, #1
movz w13, #6742
add w13, w15, w13
orr w13, w13, #1
str w13, [x9, #56]
ldr w13, [x10]
and w14, w12, #1
lsl w14, w14, #5
bic w13, w13, #0x20
orr w13, w13, w14
str w13, [x10]
bic w12, w12, #1
str w12, [x9, #60]
b L_00001a50_success
L_00001a50_success:
mov w0, #1
b L_00001a50_return
L_00001a50_fault:
mov w0, #-1
b L_00001a50_return
L_00001a50_miss:
mov w0, #3
b L_00001a50_return
L_00001a50_mode_miss:
mov w0, #4
L_00001a50_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00001a58
_agr_game_compiled_00001a58:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00001a58_mode_miss
movz w12, #6744
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #17924
cmp w14, w12
b.ne L_00001a58_miss
ldr w12, [x9, #0]
str w12, [x9, #16]
movz w12, #6746
add w12, w15, w12
str w12, [x9, #60]
L_00001a58_success:
mov w0, #1
b L_00001a58_return
L_00001a58_fault:
mov w0, #-1
b L_00001a58_return
L_00001a58_miss:
mov w0, #3
b L_00001a58_return
L_00001a58_mode_miss:
mov w0, #4
L_00001a58_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00001a62
_agr_game_compiled_00001a62:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00001a62_mode_miss
movz w12, #6754
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #44035
cmp w14, w12
b.ne L_00001a62_miss
movz w12, #6756
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #17977
cmp w14, w12
b.ne L_00001a62_miss
movz w12, #6758
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #17979
cmp w14, w12
b.ne L_00001a62_miss
ldr w12, [x9, #52]
movz w13, #12
add w12, w12, w13
str w12, [x9, #16]
ldr w12, [x9, #28]
str w12, [x9, #4]
ldr w12, [x9, #28]
str w12, [x9, #12]
movz w12, #6760
add w12, w15, w12
str w12, [x9, #60]
L_00001a62_success:
mov w0, #1
b L_00001a62_return
L_00001a62_fault:
mov w0, #-1
b L_00001a62_return
L_00001a62_miss:
mov w0, #3
b L_00001a62_return
L_00001a62_mode_miss:
mov w0, #4
L_00001a62_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00001a6a
_agr_game_compiled_00001a6a:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00001a6a_mode_miss
movz w12, #6762
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #17960
cmp w14, w12
b.ne L_00001a6a_miss
movz w12, #6764
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #8718
cmp w14, w12
b.ne L_00001a6a_miss
movz w12, #6766
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #63487
movk w12, #64527, lsl #16
cmp w14, w12
b.ne L_00001a6a_miss
ldr w12, [x9, #20]
str w12, [x9, #0]
movz w12, #14
str w12, [x9, #8]
cmp w12, #0
mrs x13, nzcv
ldr w14, [x10]
and w13, w13, #0xc0000000
and w14, w14, #0x3fffffff
orr w14, w14, w13
str w14, [x10]
movz w12, #4752
add w12, w15, w12
orr w12, w12, #1
movz w13, #6770
add w13, w15, w13
orr w13, w13, #1
str w13, [x9, #56]
ldr w13, [x10]
and w14, w12, #1
lsl w14, w14, #5
bic w13, w13, #0x20
orr w13, w13, w14
str w13, [x10]
bic w12, w12, #1
str w12, [x9, #60]
b L_00001a6a_success
L_00001a6a_success:
mov w0, #1
b L_00001a6a_return
L_00001a6a_fault:
mov w0, #-1
b L_00001a6a_return
L_00001a6a_miss:
mov w0, #3
b L_00001a6a_return
L_00001a6a_mode_miss:
mov w0, #4
L_00001a6a_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00001a74
_agr_game_compiled_00001a74:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00001a74_mode_miss
movz w12, #6772
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #17960
cmp w14, w12
b.ne L_00001a74_miss
movz w12, #6774
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #17977
cmp w14, w12
b.ne L_00001a74_miss
movz w12, #6776
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #8719
cmp w14, w12
b.ne L_00001a74_miss
movz w12, #6778
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #17979
cmp w14, w12
b.ne L_00001a74_miss
movz w12, #6780
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #63487
movk w12, #64554, lsl #16
cmp w14, w12
b.ne L_00001a74_miss
ldr w12, [x9, #20]
str w12, [x9, #0]
ldr w12, [x9, #28]
str w12, [x9, #4]
movz w12, #15
str w12, [x9, #8]
cmp w12, #0
mrs x13, nzcv
ldr w14, [x10]
and w13, w13, #0xc0000000
and w14, w14, #0x3fffffff
orr w14, w14, w13
str w14, [x10]
ldr w12, [x9, #28]
str w12, [x9, #12]
movz w12, #4820
add w12, w15, w12
orr w12, w12, #1
movz w13, #6784
add w13, w15, w13
orr w13, w13, #1
str w13, [x9, #56]
ldr w13, [x10]
and w14, w12, #1
lsl w14, w14, #5
bic w13, w13, #0x20
orr w13, w13, w14
str w13, [x10]
bic w12, w12, #1
str w12, [x9, #60]
b L_00001a74_success
L_00001a74_success:
mov w0, #1
b L_00001a74_return
L_00001a74_fault:
mov w0, #-1
b L_00001a74_return
L_00001a74_miss:
mov w0, #3
b L_00001a74_return
L_00001a74_mode_miss:
mov w0, #4
L_00001a74_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00001a80
_agr_game_compiled_00001a80:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00001a80_mode_miss
movz w12, #6784
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #57608
cmp w14, w12
b.ne L_00001a80_miss
movz w12, #7316
add w12, w15, w12
str w12, [x9, #60]
b L_00001a80_success
L_00001a80_success:
mov w0, #1
b L_00001a80_return
L_00001a80_fault:
mov w0, #-1
b L_00001a80_return
L_00001a80_miss:
mov w0, #3
b L_00001a80_return
L_00001a80_mode_miss:
mov w0, #4
L_00001a80_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00001a90
_agr_game_compiled_00001a90:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00001a90_mode_miss
movz w12, #6800
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #17931
cmp w14, w12
b.ne L_00001a90_miss
ldr w12, [x9, #4]
str w12, [x9, #12]
movz w12, #6802
add w12, w15, w12
str w12, [x9, #60]
L_00001a90_success:
mov w0, #1
b L_00001a90_return
L_00001a90_fault:
mov w0, #-1
b L_00001a90_return
L_00001a90_miss:
mov w0, #3
b L_00001a90_return
L_00001a90_mode_miss:
mov w0, #4
L_00001a90_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00001a96
_agr_game_compiled_00001a96:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00001a96_mode_miss
movz w12, #6806
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #17960
cmp w14, w12
b.ne L_00001a96_miss
movz w12, #6808
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #8717
cmp w14, w12
b.ne L_00001a96_miss
ldr w12, [x9, #20]
str w12, [x9, #0]
movz w12, #13
str w12, [x9, #8]
cmp w12, #0
mrs x13, nzcv
ldr w14, [x10]
and w13, w13, #0xc0000000
and w14, w14, #0x3fffffff
orr w14, w14, w13
str w14, [x10]
movz w12, #6810
add w12, w15, w12
str w12, [x9, #60]
L_00001a96_success:
mov w0, #1
b L_00001a96_return
L_00001a96_fault:
mov w0, #-1
b L_00001a96_return
L_00001a96_miss:
mov w0, #3
b L_00001a96_return
L_00001a96_mode_miss:
mov w0, #4
L_00001a96_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00001a9e
_agr_game_compiled_00001a9e:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00001a9e_mode_miss
movz w12, #6814
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #63487
movk w12, #64503, lsl #16
cmp w14, w12
b.ne L_00001a9e_miss
movz w12, #4752
add w12, w15, w12
orr w12, w12, #1
movz w13, #6818
add w13, w15, w13
orr w13, w13, #1
str w13, [x9, #56]
ldr w13, [x10]
and w14, w12, #1
lsl w14, w14, #5
bic w13, w13, #0x20
orr w13, w13, w14
str w13, [x10]
bic w12, w12, #1
str w12, [x9, #60]
b L_00001a9e_success
L_00001a9e_success:
mov w0, #1
b L_00001a9e_return
L_00001a9e_fault:
mov w0, #-1
b L_00001a9e_return
L_00001a9e_miss:
mov w0, #3
b L_00001a9e_return
L_00001a9e_mode_miss:
mov w0, #4
L_00001a9e_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00001aa2
_agr_game_compiled_00001aa2:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00001aa2_mode_miss
movz w12, #6818
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #39683
cmp w14, w12
b.ne L_00001aa2_miss
movz w12, #6820
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #61706
movk w12, #2564, lsl #16
cmp w14, w12
b.ne L_00001aa2_miss
ldr w12, [x9, #52]
movz w13, #12
add w12, w12, w13
cmp w12, #0x1000
b.lo L_00001aa2_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w12, w13
b.hi L_00001aa2_fault
add x13, x11, w12, uxtw
ldr w12, [x13]
str w12, [x9, #12]
ldr w12, [x9, #40]
movz w13, #4
add w12, w12, w13
str w12, [x9, #40]
movz w12, #6824
add w12, w15, w12
str w12, [x9, #60]
L_00001aa2_success:
mov w0, #1
b L_00001aa2_return
L_00001aa2_fault:
mov w0, #-1
b L_00001aa2_return
L_00001aa2_miss:
mov w0, #3
b L_00001aa2_return
L_00001aa2_mode_miss:
mov w0, #4
L_00001aa2_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00001ac2
_agr_game_compiled_00001ac2:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00001ac2_mode_miss
movz w12, #6850
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #17968
cmp w14, w12
b.ne L_00001ac2_miss
movz w12, #6852
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #63487
movk w12, #65432, lsl #16
cmp w14, w12
b.ne L_00001ac2_miss
ldr w12, [x9, #24]
str w12, [x9, #0]
movz w12, #6648
add w12, w15, w12
orr w12, w12, #1
movz w13, #6856
add w13, w15, w13
orr w13, w13, #1
str w13, [x9, #56]
ldr w13, [x10]
and w14, w12, #1
lsl w14, w14, #5
bic w13, w13, #0x20
orr w13, w13, w14
str w13, [x10]
bic w12, w12, #1
str w12, [x9, #60]
b L_00001ac2_success
L_00001ac2_success:
mov w0, #1
b L_00001ac2_return
L_00001ac2_fault:
mov w0, #-1
b L_00001ac2_return
L_00001ac2_miss:
mov w0, #3
b L_00001ac2_return
L_00001ac2_mode_miss:
mov w0, #4
L_00001ac2_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00001ad0
_agr_game_compiled_00001ad0:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00001ad0_mode_miss
movz w12, #6864
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #8201
cmp w14, w12
b.ne L_00001ad0_miss
movz w12, #6866
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #57568
cmp w14, w12
b.ne L_00001ad0_miss
movz w12, #9
str w12, [x9, #0]
cmp w12, #0
mrs x13, nzcv
ldr w14, [x10]
and w13, w13, #0xc0000000
and w14, w14, #0x3fffffff
orr w14, w14, w13
str w14, [x10]
movz w12, #7318
add w12, w15, w12
str w12, [x9, #60]
b L_00001ad0_success
L_00001ad0_success:
mov w0, #1
b L_00001ad0_return
L_00001ad0_fault:
mov w0, #-1
b L_00001ad0_return
L_00001ad0_miss:
mov w0, #3
b L_00001ad0_return
L_00001ad0_mode_miss:
mov w0, #4
L_00001ad0_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00001ad6
_agr_game_compiled_00001ad6:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00001ad6_mode_miss
movz w12, #6870
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #8448
cmp w14, w12
b.ne L_00001ad6_miss
movz w12, #6872
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #17960
cmp w14, w12
b.ne L_00001ad6_miss
movz w12, #6874
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #17931
cmp w14, w12
b.ne L_00001ad6_miss
movz w12, #0
str w12, [x9, #4]
cmp w12, #0
mrs x13, nzcv
ldr w14, [x10]
and w13, w13, #0xc0000000
and w14, w14, #0x3fffffff
orr w14, w14, w13
str w14, [x10]
ldr w12, [x9, #20]
str w12, [x9, #0]
ldr w12, [x9, #4]
str w12, [x9, #12]
movz w12, #6876
add w12, w15, w12
str w12, [x9, #60]
L_00001ad6_success:
mov w0, #1
b L_00001ad6_return
L_00001ad6_fault:
mov w0, #-1
b L_00001ad6_return
L_00001ad6_miss:
mov w0, #3
b L_00001ad6_return
L_00001ad6_mode_miss:
mov w0, #4
L_00001ad6_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00001ade
_agr_game_compiled_00001ade:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00001ade_mode_miss
movz w12, #6878
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #63487
movk w12, #64931, lsl #16
cmp w14, w12
b.ne L_00001ade_miss
movz w12, #5672
add w12, w15, w12
orr w12, w12, #1
movz w13, #6882
add w13, w15, w13
orr w13, w13, #1
str w13, [x9, #56]
ldr w13, [x10]
and w14, w12, #1
lsl w14, w14, #5
bic w13, w13, #0x20
orr w13, w13, w14
str w13, [x10]
bic w12, w12, #1
str w12, [x9, #60]
b L_00001ade_success
L_00001ade_success:
mov w0, #1
b L_00001ade_return
L_00001ade_fault:
mov w0, #-1
b L_00001ade_return
L_00001ade_miss:
mov w0, #3
b L_00001ade_return
L_00001ade_mode_miss:
mov w0, #4
L_00001ade_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00001afc
_agr_game_compiled_00001afc:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00001afc_mode_miss
movz w12, #6908
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #8448
cmp w14, w12
b.ne L_00001afc_miss
movz w12, #0
str w12, [x9, #4]
cmp w12, #0
mrs x13, nzcv
ldr w14, [x10]
and w13, w13, #0xc0000000
and w14, w14, #0x3fffffff
orr w14, w14, w13
str w14, [x10]
movz w12, #6910
add w12, w15, w12
str w12, [x9, #60]
L_00001afc_success:
mov w0, #1
b L_00001afc_return
L_00001afc_fault:
mov w0, #-1
b L_00001afc_return
L_00001afc_miss:
mov w0, #3
b L_00001afc_return
L_00001afc_mode_miss:
mov w0, #4
L_00001afc_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00001b02
_agr_game_compiled_00001b02:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00001b02_mode_miss
movz w12, #6914
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #17960
cmp w14, w12
b.ne L_00001b02_miss
ldr w12, [x9, #20]
str w12, [x9, #0]
movz w12, #6916
add w12, w15, w12
str w12, [x9, #60]
L_00001b02_success:
mov w0, #1
b L_00001b02_return
L_00001b02_fault:
mov w0, #-1
b L_00001b02_return
L_00001b02_miss:
mov w0, #3
b L_00001b02_return
L_00001b02_mode_miss:
mov w0, #4
L_00001b02_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00001b08
_agr_game_compiled_00001b08:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00001b08_mode_miss
movz w12, #6920
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #17931
cmp w14, w12
b.ne L_00001b08_miss
movz w12, #6922
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #63487
movk w12, #64449, lsl #16
cmp w14, w12
b.ne L_00001b08_miss
ldr w12, [x9, #4]
str w12, [x9, #12]
movz w12, #4752
add w12, w15, w12
orr w12, w12, #1
movz w13, #6926
add w13, w15, w13
orr w13, w13, #1
str w13, [x9, #56]
ldr w13, [x10]
and w14, w12, #1
lsl w14, w14, #5
bic w13, w13, #0x20
orr w13, w13, w14
str w13, [x10]
bic w12, w12, #1
str w12, [x9, #60]
b L_00001b08_success
L_00001b08_success:
mov w0, #1
b L_00001b08_return
L_00001b08_fault:
mov w0, #-1
b L_00001b08_return
L_00001b08_miss:
mov w0, #3
b L_00001b08_return
L_00001b08_mode_miss:
mov w0, #4
L_00001b08_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00001b0e
_agr_game_compiled_00001b0e:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00001b0e_mode_miss
movz w12, #6926
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #17960
cmp w14, w12
b.ne L_00001b0e_miss
movz w12, #6928
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #8448
cmp w14, w12
b.ne L_00001b0e_miss
ldr w12, [x9, #20]
str w12, [x9, #0]
movz w12, #0
str w12, [x9, #4]
cmp w12, #0
mrs x13, nzcv
ldr w14, [x10]
and w13, w13, #0xc0000000
and w14, w14, #0x3fffffff
orr w14, w14, w13
str w14, [x10]
movz w12, #6930
add w12, w15, w12
str w12, [x9, #60]
L_00001b0e_success:
mov w0, #1
b L_00001b0e_return
L_00001b0e_fault:
mov w0, #-1
b L_00001b0e_return
L_00001b0e_miss:
mov w0, #3
b L_00001b0e_return
L_00001b0e_mode_miss:
mov w0, #4
L_00001b0e_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00001b16
_agr_game_compiled_00001b16:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00001b16_mode_miss
movz w12, #6934
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #8717
cmp w14, w12
b.ne L_00001b16_miss
movz w12, #6936
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #17931
cmp w14, w12
b.ne L_00001b16_miss
movz w12, #6938
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #63487
movk w12, #64475, lsl #16
cmp w14, w12
b.ne L_00001b16_miss
movz w12, #13
str w12, [x9, #8]
cmp w12, #0
mrs x13, nzcv
ldr w14, [x10]
and w13, w13, #0xc0000000
and w14, w14, #0x3fffffff
orr w14, w14, w13
str w14, [x10]
ldr w12, [x9, #4]
str w12, [x9, #12]
movz w12, #4820
add w12, w15, w12
orr w12, w12, #1
movz w13, #6942
add w13, w15, w13
orr w13, w13, #1
str w13, [x9, #56]
ldr w13, [x10]
and w14, w12, #1
lsl w14, w14, #5
bic w13, w13, #0x20
orr w13, w13, w14
str w13, [x10]
bic w12, w12, #1
str w12, [x9, #60]
b L_00001b16_success
L_00001b16_success:
mov w0, #1
b L_00001b16_return
L_00001b16_fault:
mov w0, #-1
b L_00001b16_return
L_00001b16_miss:
mov w0, #3
b L_00001b16_return
L_00001b16_mode_miss:
mov w0, #4
L_00001b16_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00001b1e
_agr_game_compiled_00001b1e:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00001b1e_mode_miss
movz w12, #6942
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #59287
cmp w14, w12
b.ne L_00001b1e_miss
movz w12, #6736
add w12, w15, w12
str w12, [x9, #60]
b L_00001b1e_success
L_00001b1e_success:
mov w0, #1
b L_00001b1e_return
L_00001b1e_fault:
mov w0, #-1
b L_00001b1e_return
L_00001b1e_miss:
mov w0, #3
b L_00001b1e_return
L_00001b1e_mode_miss:
mov w0, #4
L_00001b1e_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00001b34
_agr_game_compiled_00001b34:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00001b34_mode_miss
movz w12, #6964
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #17960
cmp w14, w12
b.ne L_00001b34_miss
ldr w12, [x9, #20]
str w12, [x9, #0]
movz w12, #6966
add w12, w15, w12
str w12, [x9, #60]
L_00001b34_success:
mov w0, #1
b L_00001b34_return
L_00001b34_fault:
mov w0, #-1
b L_00001b34_return
L_00001b34_miss:
mov w0, #3
b L_00001b34_return
L_00001b34_mode_miss:
mov w0, #4
L_00001b34_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00001b48
_agr_game_compiled_00001b48:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00001b48_mode_miss
movz w12, #6984
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #17968
cmp w14, w12
b.ne L_00001b48_miss
movz w12, #6986
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #63487
movk w12, #65365, lsl #16
cmp w14, w12
b.ne L_00001b48_miss
ldr w12, [x9, #24]
str w12, [x9, #0]
movz w12, #6648
add w12, w15, w12
orr w12, w12, #1
movz w13, #6990
add w13, w15, w13
orr w13, w13, #1
str w13, [x9, #56]
ldr w13, [x10]
and w14, w12, #1
lsl w14, w14, #5
bic w13, w13, #0x20
orr w13, w13, w14
str w13, [x10]
bic w12, w12, #1
str w12, [x9, #60]
b L_00001b48_success
L_00001b48_success:
mov w0, #1
b L_00001b48_return
L_00001b48_fault:
mov w0, #-1
b L_00001b48_return
L_00001b48_miss:
mov w0, #3
b L_00001b48_return
L_00001b48_mode_miss:
mov w0, #4
L_00001b48_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00001b4e
_agr_game_compiled_00001b4e:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00001b4e_mode_miss
movz w12, #6990
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #17922
cmp w14, w12
b.ne L_00001b4e_miss
ldr w12, [x9, #0]
str w12, [x9, #8]
movz w12, #6992
add w12, w15, w12
str w12, [x9, #60]
L_00001b4e_success:
mov w0, #1
b L_00001b4e_return
L_00001b4e_fault:
mov w0, #-1
b L_00001b4e_return
L_00001b4e_miss:
mov w0, #3
b L_00001b4e_return
L_00001b4e_mode_miss:
mov w0, #4
L_00001b4e_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00001b5a
_agr_game_compiled_00001b5a:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00001b5a_mode_miss
movz w12, #7002
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #17960
cmp w14, w12
b.ne L_00001b5a_miss
ldr w12, [x9, #20]
str w12, [x9, #0]
movz w12, #7004
add w12, w15, w12
str w12, [x9, #60]
L_00001b5a_success:
mov w0, #1
b L_00001b5a_return
L_00001b5a_fault:
mov w0, #-1
b L_00001b5a_return
L_00001b5a_miss:
mov w0, #3
b L_00001b5a_return
L_00001b5a_mode_miss:
mov w0, #4
L_00001b5a_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00001b5c
_agr_game_compiled_00001b5c:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00001b5c_mode_miss
movz w12, #7004
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #17931
cmp w14, w12
b.ne L_00001b5c_miss
movz w12, #7006
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #57491
cmp w14, w12
b.ne L_00001b5c_miss
ldr w12, [x9, #4]
str w12, [x9, #12]
movz w12, #7304
add w12, w15, w12
str w12, [x9, #60]
b L_00001b5c_success
L_00001b5c_success:
mov w0, #1
b L_00001b5c_return
L_00001b5c_fault:
mov w0, #-1
b L_00001b5c_return
L_00001b5c_miss:
mov w0, #3
b L_00001b5c_return
L_00001b5c_mode_miss:
mov w0, #4
L_00001b5c_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00001b64
_agr_game_compiled_00001b64:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00001b64_mode_miss
movz w12, #7012
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #8448
cmp w14, w12
b.ne L_00001b64_miss
movz w12, #7014
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #8717
cmp w14, w12
b.ne L_00001b64_miss
movz w12, #7016
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #17931
cmp w14, w12
b.ne L_00001b64_miss
movz w12, #0
str w12, [x9, #4]
cmp w12, #0
mrs x13, nzcv
ldr w14, [x10]
and w13, w13, #0xc0000000
and w14, w14, #0x3fffffff
orr w14, w14, w13
str w14, [x10]
movz w12, #13
str w12, [x9, #8]
cmp w12, #0
mrs x13, nzcv
ldr w14, [x10]
and w13, w13, #0xc0000000
and w14, w14, #0x3fffffff
orr w14, w14, w13
str w14, [x10]
ldr w12, [x9, #4]
str w12, [x9, #12]
movz w12, #7018
add w12, w15, w12
str w12, [x9, #60]
L_00001b64_success:
mov w0, #1
b L_00001b64_return
L_00001b64_fault:
mov w0, #-1
b L_00001b64_return
L_00001b64_miss:
mov w0, #3
b L_00001b64_return
L_00001b64_mode_miss:
mov w0, #4
L_00001b64_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00001b6e
_agr_game_compiled_00001b6e:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00001b6e_mode_miss
movz w12, #7022
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #17960
cmp w14, w12
b.ne L_00001b6e_miss
movz w12, #7024
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #9218
cmp w14, w12
b.ne L_00001b6e_miss
movz w12, #7026
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #63487
movk w12, #64397, lsl #16
cmp w14, w12
b.ne L_00001b6e_miss
ldr w12, [x9, #20]
str w12, [x9, #0]
movz w12, #2
str w12, [x9, #16]
cmp w12, #0
mrs x13, nzcv
ldr w14, [x10]
and w13, w13, #0xc0000000
and w14, w14, #0x3fffffff
orr w14, w14, w13
str w14, [x10]
movz w12, #4752
add w12, w15, w12
orr w12, w12, #1
movz w13, #7030
add w13, w15, w13
orr w13, w13, #1
str w13, [x9, #56]
ldr w13, [x10]
and w14, w12, #1
lsl w14, w14, #5
bic w13, w13, #0x20
orr w13, w13, w14
str w13, [x10]
bic w12, w12, #1
str w12, [x9, #60]
b L_00001b6e_success
L_00001b6e_success:
mov w0, #1
b L_00001b6e_return
L_00001b6e_fault:
mov w0, #-1
b L_00001b6e_return
L_00001b6e_miss:
mov w0, #3
b L_00001b6e_return
L_00001b6e_mode_miss:
mov w0, #4
L_00001b6e_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00001b76
_agr_game_compiled_00001b76:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00001b76_mode_miss
movz w12, #7030
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #17968
cmp w14, w12
b.ne L_00001b76_miss
movz w12, #7032
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #63487
movk w12, #65342, lsl #16
cmp w14, w12
b.ne L_00001b76_miss
ldr w12, [x9, #24]
str w12, [x9, #0]
movz w12, #6648
add w12, w15, w12
orr w12, w12, #1
movz w13, #7036
add w13, w15, w13
orr w13, w13, #1
str w13, [x9, #56]
ldr w13, [x10]
and w14, w12, #1
lsl w14, w14, #5
bic w13, w13, #0x20
orr w13, w13, w14
str w13, [x10]
bic w12, w12, #1
str w12, [x9, #60]
b L_00001b76_success
L_00001b76_success:
mov w0, #1
b L_00001b76_return
L_00001b76_fault:
mov w0, #-1
b L_00001b76_return
L_00001b76_miss:
mov w0, #3
b L_00001b76_return
L_00001b76_mode_miss:
mov w0, #4
L_00001b76_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00001b80
_agr_game_compiled_00001b80:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00001b80_mode_miss
movz w12, #7040
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #39683
cmp w14, w12
b.ne L_00001b80_miss
ldr w12, [x9, #52]
movz w13, #12
add w12, w12, w13
cmp w12, #0x1000
b.lo L_00001b80_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w12, w13
b.hi L_00001b80_fault
add x13, x11, w12, uxtw
ldr w12, [x13]
str w12, [x9, #12]
movz w12, #7042
add w12, w15, w12
str w12, [x9, #60]
L_00001b80_success:
mov w0, #1
b L_00001b80_return
L_00001b80_fault:
mov w0, #-1
b L_00001b80_return
L_00001b80_miss:
mov w0, #3
b L_00001b80_return
L_00001b80_mode_miss:
mov w0, #4
L_00001b80_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00001b8e
_agr_game_compiled_00001b8e:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00001b8e_mode_miss
movz w12, #7054
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #17968
cmp w14, w12
b.ne L_00001b8e_miss
ldr w12, [x9, #24]
str w12, [x9, #0]
movz w12, #7056
add w12, w15, w12
str w12, [x9, #60]
L_00001b8e_success:
mov w0, #1
b L_00001b8e_return
L_00001b8e_fault:
mov w0, #-1
b L_00001b8e_return
L_00001b8e_miss:
mov w0, #3
b L_00001b8e_return
L_00001b8e_mode_miss:
mov w0, #4
L_00001b8e_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00001b92
_agr_game_compiled_00001b92:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00001b92_mode_miss
movz w12, #7058
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #63487
movk w12, #65329, lsl #16
cmp w14, w12
b.ne L_00001b92_miss
movz w12, #6648
add w12, w15, w12
orr w12, w12, #1
movz w13, #7062
add w13, w15, w13
orr w13, w13, #1
str w13, [x9, #56]
ldr w13, [x10]
and w14, w12, #1
lsl w14, w14, #5
bic w13, w13, #0x20
orr w13, w13, w14
str w13, [x10]
bic w12, w12, #1
str w12, [x9, #60]
b L_00001b92_success
L_00001b92_success:
mov w0, #1
b L_00001b92_return
L_00001b92_fault:
mov w0, #-1
b L_00001b92_return
L_00001b92_miss:
mov w0, #3
b L_00001b92_return
L_00001b92_mode_miss:
mov w0, #4
L_00001b92_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00001b96
_agr_game_compiled_00001b96:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00001b96_mode_miss
movz w12, #7062
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #59377
cmp w14, w12
b.ne L_00001b96_miss
movz w12, #7036
add w12, w15, w12
str w12, [x9, #60]
b L_00001b96_success
L_00001b96_success:
mov w0, #1
b L_00001b96_return
L_00001b96_fault:
mov w0, #-1
b L_00001b96_return
L_00001b96_miss:
mov w0, #3
b L_00001b96_return
L_00001b96_mode_miss:
mov w0, #4
L_00001b96_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00001b98
_agr_game_compiled_00001b98:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00001b98_mode_miss
movz w12, #7064
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #62723
movk w12, #29441, lsl #16
cmp w14, w12
b.ne L_00001b98_miss
ldr w12, [x9, #12]
movz w13, #3841
add w12, w12, w13
str w12, [x9, #12]
movz w12, #7068
add w12, w15, w12
str w12, [x9, #60]
L_00001b98_success:
mov w0, #1
b L_00001b98_return
L_00001b98_fault:
mov w0, #-1
b L_00001b98_return
L_00001b98_miss:
mov w0, #3
b L_00001b98_return
L_00001b98_mode_miss:
mov w0, #4
L_00001b98_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00001ba6
_agr_game_compiled_00001ba6:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00001ba6_mode_miss
movz w12, #7078
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #17960
cmp w14, w12
b.ne L_00001ba6_miss
movz w12, #7080
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #59317
cmp w14, w12
b.ne L_00001ba6_miss
ldr w12, [x9, #20]
str w12, [x9, #0]
movz w12, #6934
add w12, w15, w12
str w12, [x9, #60]
b L_00001ba6_success
L_00001ba6_success:
mov w0, #1
b L_00001ba6_return
L_00001ba6_fault:
mov w0, #-1
b L_00001ba6_return
L_00001ba6_miss:
mov w0, #3
b L_00001ba6_return
L_00001ba6_mode_miss:
mov w0, #4
L_00001ba6_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00001bae
_agr_game_compiled_00001bae:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00001bae_mode_miss
movz w12, #7086
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #17968
cmp w14, w12
b.ne L_00001bae_miss
movz w12, #7088
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #63487
movk w12, #65314, lsl #16
cmp w14, w12
b.ne L_00001bae_miss
ldr w12, [x9, #24]
str w12, [x9, #0]
movz w12, #6648
add w12, w15, w12
orr w12, w12, #1
movz w13, #7092
add w13, w15, w13
orr w13, w13, #1
str w13, [x9, #56]
ldr w13, [x10]
and w14, w12, #1
lsl w14, w14, #5
bic w13, w13, #0x20
orr w13, w13, w14
str w13, [x10]
bic w12, w12, #1
str w12, [x9, #60]
b L_00001bae_success
L_00001bae_success:
mov w0, #1
b L_00001bae_return
L_00001bae_fault:
mov w0, #-1
b L_00001bae_return
L_00001bae_miss:
mov w0, #3
b L_00001bae_return
L_00001bae_mode_miss:
mov w0, #4
L_00001bae_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00001bb4
_agr_game_compiled_00001bb4:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00001bb4_mode_miss
movz w12, #7092
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #8449
cmp w14, w12
b.ne L_00001bb4_miss
movz w12, #1
str w12, [x9, #4]
cmp w12, #0
mrs x13, nzcv
ldr w14, [x10]
and w13, w13, #0xc0000000
and w14, w14, #0x3fffffff
orr w14, w14, w13
str w14, [x10]
movz w12, #7094
add w12, w15, w12
str w12, [x9, #60]
L_00001bb4_success:
mov w0, #1
b L_00001bb4_return
L_00001bb4_fault:
mov w0, #-1
b L_00001bb4_return
L_00001bb4_miss:
mov w0, #3
b L_00001bb4_return
L_00001bb4_mode_miss:
mov w0, #4
L_00001bb4_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00001bc0
_agr_game_compiled_00001bc0:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00001bc0_mode_miss
movz w12, #7104
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #17960
cmp w14, w12
b.ne L_00001bc0_miss
movz w12, #7106
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #57369
cmp w14, w12
b.ne L_00001bc0_miss
ldr w12, [x9, #20]
str w12, [x9, #0]
movz w12, #7160
add w12, w15, w12
str w12, [x9, #60]
b L_00001bc0_success
L_00001bc0_success:
mov w0, #1
b L_00001bc0_return
L_00001bc0_fault:
mov w0, #-1
b L_00001bc0_return
L_00001bc0_miss:
mov w0, #3
b L_00001bc0_return
L_00001bc0_mode_miss:
mov w0, #4
L_00001bc0_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00001bd0
_agr_game_compiled_00001bd0:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00001bd0_mode_miss
movz w12, #7120
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #8449
cmp w14, w12
b.ne L_00001bd0_miss
movz w12, #1
str w12, [x9, #4]
cmp w12, #0
mrs x13, nzcv
ldr w14, [x10]
and w13, w13, #0xc0000000
and w14, w14, #0x3fffffff
orr w14, w14, w13
str w14, [x10]
movz w12, #7122
add w12, w15, w12
str w12, [x9, #60]
L_00001bd0_success:
mov w0, #1
b L_00001bd0_return
L_00001bd0_fault:
mov w0, #-1
b L_00001bd0_return
L_00001bd0_miss:
mov w0, #3
b L_00001bd0_return
L_00001bd0_mode_miss:
mov w0, #4
L_00001bd0_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00001bd4
_agr_game_compiled_00001bd4:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00001bd4_mode_miss
movz w12, #7124
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #17960
cmp w14, w12
b.ne L_00001bd4_miss
ldr w12, [x9, #20]
str w12, [x9, #0]
movz w12, #7126
add w12, w15, w12
str w12, [x9, #60]
L_00001bd4_success:
mov w0, #1
b L_00001bd4_return
L_00001bd4_fault:
mov w0, #-1
b L_00001bd4_return
L_00001bd4_miss:
mov w0, #3
b L_00001bd4_return
L_00001bd4_mode_miss:
mov w0, #4
L_00001bd4_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00001bda
_agr_game_compiled_00001bda:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00001bda_mode_miss
movz w12, #7130
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #59327
cmp w14, w12
b.ne L_00001bda_miss
movz w12, #7004
add w12, w15, w12
str w12, [x9, #60]
b L_00001bda_success
L_00001bda_success:
mov w0, #1
b L_00001bda_return
L_00001bda_fault:
mov w0, #-1
b L_00001bda_return
L_00001bda_miss:
mov w0, #3
b L_00001bda_return
L_00001bda_mode_miss:
mov w0, #4
L_00001bda_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00001be4
_agr_game_compiled_00001be4:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00001be4_mode_miss
movz w12, #7140
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #17968
cmp w14, w12
b.ne L_00001be4_miss
movz w12, #7142
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #63487
movk w12, #65287, lsl #16
cmp w14, w12
b.ne L_00001be4_miss
ldr w12, [x9, #24]
str w12, [x9, #0]
movz w12, #6648
add w12, w15, w12
orr w12, w12, #1
movz w13, #7146
add w13, w15, w13
orr w13, w13, #1
str w13, [x9, #56]
ldr w13, [x10]
and w14, w12, #1
lsl w14, w14, #5
bic w13, w13, #0x20
orr w13, w13, w14
str w13, [x10]
bic w12, w12, #1
str w12, [x9, #60]
b L_00001be4_success
L_00001be4_success:
mov w0, #1
b L_00001be4_return
L_00001be4_fault:
mov w0, #-1
b L_00001be4_return
L_00001be4_miss:
mov w0, #3
b L_00001be4_return
L_00001be4_mode_miss:
mov w0, #4
L_00001be4_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00001bea
_agr_game_compiled_00001bea:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00001bea_mode_miss
movz w12, #7146
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #8451
cmp w14, w12
b.ne L_00001bea_miss
movz w12, #3
str w12, [x9, #4]
cmp w12, #0
mrs x13, nzcv
ldr w14, [x10]
and w13, w13, #0xc0000000
and w14, w14, #0x3fffffff
orr w14, w14, w13
str w14, [x10]
movz w12, #7148
add w12, w15, w12
str w12, [x9, #60]
L_00001bea_success:
mov w0, #1
b L_00001bea_return
L_00001bea_fault:
mov w0, #-1
b L_00001bea_return
L_00001bea_miss:
mov w0, #3
b L_00001bea_return
L_00001bea_mode_miss:
mov w0, #4
L_00001bea_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00001bf6
_agr_game_compiled_00001bf6:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00001bf6_mode_miss
movz w12, #7158
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #17960
cmp w14, w12
b.ne L_00001bf6_miss
ldr w12, [x9, #20]
str w12, [x9, #0]
movz w12, #7160
add w12, w15, w12
str w12, [x9, #60]
L_00001bf6_success:
mov w0, #1
b L_00001bf6_return
L_00001bf6_fault:
mov w0, #-1
b L_00001bf6_return
L_00001bf6_miss:
mov w0, #3
b L_00001bf6_return
L_00001bf6_mode_miss:
mov w0, #4
L_00001bf6_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00001bfc
_agr_game_compiled_00001bfc:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00001bfc_mode_miss
movz w12, #7164
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #59310
cmp w14, w12
b.ne L_00001bfc_miss
movz w12, #7004
add w12, w15, w12
str w12, [x9, #60]
b L_00001bfc_success
L_00001bfc_success:
mov w0, #1
b L_00001bfc_return
L_00001bfc_fault:
mov w0, #-1
b L_00001bfc_return
L_00001bfc_miss:
mov w0, #3
b L_00001bfc_return
L_00001bfc_mode_miss:
mov w0, #4
L_00001bfc_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00001c02
_agr_game_compiled_00001c02:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00001c02_mode_miss
movz w12, #7170
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #17968
cmp w14, w12
b.ne L_00001c02_miss
movz w12, #7172
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #63487
movk w12, #65272, lsl #16
cmp w14, w12
b.ne L_00001c02_miss
ldr w12, [x9, #24]
str w12, [x9, #0]
movz w12, #6648
add w12, w15, w12
orr w12, w12, #1
movz w13, #7176
add w13, w15, w13
orr w13, w13, #1
str w13, [x9, #56]
ldr w13, [x10]
and w14, w12, #1
lsl w14, w14, #5
bic w13, w13, #0x20
orr w13, w13, w14
str w13, [x10]
bic w12, w12, #1
str w12, [x9, #60]
b L_00001c02_success
L_00001c02_success:
mov w0, #1
b L_00001c02_return
L_00001c02_fault:
mov w0, #-1
b L_00001c02_return
L_00001c02_miss:
mov w0, #3
b L_00001c02_return
L_00001c02_mode_miss:
mov w0, #4
L_00001c02_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00001c08
_agr_game_compiled_00001c08:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00001c08_mode_miss
movz w12, #7176
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #17922
cmp w14, w12
b.ne L_00001c08_miss
ldr w12, [x9, #0]
str w12, [x9, #8]
movz w12, #7178
add w12, w15, w12
str w12, [x9, #60]
L_00001c08_success:
mov w0, #1
b L_00001c08_return
L_00001c08_fault:
mov w0, #-1
b L_00001c08_return
L_00001c08_miss:
mov w0, #3
b L_00001c08_return
L_00001c08_mode_miss:
mov w0, #4
L_00001c08_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00001c18
_agr_game_compiled_00001c18:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00001c18_mode_miss
movz w12, #7192
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #17960
cmp w14, w12
b.ne L_00001c18_miss
movz w12, #7194
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #8452
cmp w14, w12
b.ne L_00001c18_miss
movz w12, #7196
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #57396
cmp w14, w12
b.ne L_00001c18_miss
ldr w12, [x9, #20]
str w12, [x9, #0]
movz w12, #4
str w12, [x9, #4]
cmp w12, #0
mrs x13, nzcv
ldr w14, [x10]
and w13, w13, #0xc0000000
and w14, w14, #0x3fffffff
orr w14, w14, w13
str w14, [x10]
movz w12, #7304
add w12, w15, w12
str w12, [x9, #60]
b L_00001c18_success
L_00001c18_success:
mov w0, #1
b L_00001c18_return
L_00001c18_fault:
mov w0, #-1
b L_00001c18_return
L_00001c18_miss:
mov w0, #3
b L_00001c18_return
L_00001c18_mode_miss:
mov w0, #4
L_00001c18_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00001c2a
_agr_game_compiled_00001c2a:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00001c2a_mode_miss
movz w12, #7210
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #8451
cmp w14, w12
b.ne L_00001c2a_miss
movz w12, #3
str w12, [x9, #4]
cmp w12, #0
mrs x13, nzcv
ldr w14, [x10]
and w13, w13, #0xc0000000
and w14, w14, #0x3fffffff
orr w14, w14, w13
str w14, [x10]
movz w12, #7212
add w12, w15, w12
str w12, [x9, #60]
L_00001c2a_success:
mov w0, #1
b L_00001c2a_return
L_00001c2a_fault:
mov w0, #-1
b L_00001c2a_return
L_00001c2a_miss:
mov w0, #3
b L_00001c2a_return
L_00001c2a_mode_miss:
mov w0, #4
L_00001c2a_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00001c2e
_agr_game_compiled_00001c2e:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00001c2e_mode_miss
movz w12, #7214
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #17960
cmp w14, w12
b.ne L_00001c2e_miss
ldr w12, [x9, #20]
str w12, [x9, #0]
movz w12, #7216
add w12, w15, w12
str w12, [x9, #60]
L_00001c2e_success:
mov w0, #1
b L_00001c2e_return
L_00001c2e_fault:
mov w0, #-1
b L_00001c2e_return
L_00001c2e_miss:
mov w0, #3
b L_00001c2e_return
L_00001c2e_mode_miss:
mov w0, #4
L_00001c2e_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00001c34
_agr_game_compiled_00001c34:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00001c34_mode_miss
movz w12, #7220
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #59282
cmp w14, w12
b.ne L_00001c34_miss
movz w12, #7004
add w12, w15, w12
str w12, [x9, #60]
b L_00001c34_success
L_00001c34_success:
mov w0, #1
b L_00001c34_return
L_00001c34_fault:
mov w0, #-1
b L_00001c34_return
L_00001c34_miss:
mov w0, #3
b L_00001c34_return
L_00001c34_mode_miss:
mov w0, #4
L_00001c34_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00001c3a
_agr_game_compiled_00001c3a:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00001c3a_mode_miss
movz w12, #7226
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #17968
cmp w14, w12
b.ne L_00001c3a_miss
movz w12, #7228
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #63487
movk w12, #65244, lsl #16
cmp w14, w12
b.ne L_00001c3a_miss
ldr w12, [x9, #24]
str w12, [x9, #0]
movz w12, #6648
add w12, w15, w12
orr w12, w12, #1
movz w13, #7232
add w13, w15, w13
orr w13, w13, #1
str w13, [x9, #56]
ldr w13, [x10]
and w14, w12, #1
lsl w14, w14, #5
bic w13, w13, #0x20
orr w13, w13, w14
str w13, [x10]
bic w12, w12, #1
str w12, [x9, #60]
b L_00001c3a_success
L_00001c3a_success:
mov w0, #1
b L_00001c3a_return
L_00001c3a_fault:
mov w0, #-1
b L_00001c3a_return
L_00001c3a_miss:
mov w0, #3
b L_00001c3a_return
L_00001c3a_mode_miss:
mov w0, #4
L_00001c3a_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00001c4c
_agr_game_compiled_00001c4c:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00001c4c_mode_miss
movz w12, #7244
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #57354
cmp w14, w12
b.ne L_00001c4c_miss
movz w12, #7268
add w12, w15, w12
str w12, [x9, #60]
b L_00001c4c_success
L_00001c4c_success:
mov w0, #1
b L_00001c4c_return
L_00001c4c_fault:
mov w0, #-1
b L_00001c4c_return
L_00001c4c_miss:
mov w0, #3
b L_00001c4c_return
L_00001c4c_mode_miss:
mov w0, #4
L_00001c4c_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00001c54
_agr_game_compiled_00001c54:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00001c54_mode_miss
movz w12, #7252
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #17968
cmp w14, w12
b.ne L_00001c54_miss
movz w12, #7254
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #63487
movk w12, #65231, lsl #16
cmp w14, w12
b.ne L_00001c54_miss
ldr w12, [x9, #24]
str w12, [x9, #0]
movz w12, #6648
add w12, w15, w12
orr w12, w12, #1
movz w13, #7258
add w13, w15, w13
orr w13, w13, #1
str w13, [x9, #56]
ldr w13, [x10]
and w14, w12, #1
lsl w14, w14, #5
bic w13, w13, #0x20
orr w13, w13, w14
str w13, [x10]
bic w12, w12, #1
str w12, [x9, #60]
b L_00001c54_success
L_00001c54_success:
mov w0, #1
b L_00001c54_return
L_00001c54_fault:
mov w0, #-1
b L_00001c54_return
L_00001c54_miss:
mov w0, #3
b L_00001c54_return
L_00001c54_mode_miss:
mov w0, #4
L_00001c54_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00001c64
_agr_game_compiled_00001c64:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00001c64_mode_miss
movz w12, #7268
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #17960
cmp w14, w12
b.ne L_00001c64_miss
movz w12, #7270
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #8449
cmp w14, w12
b.ne L_00001c64_miss
ldr w12, [x9, #20]
str w12, [x9, #0]
movz w12, #1
str w12, [x9, #4]
cmp w12, #0
mrs x13, nzcv
ldr w14, [x10]
and w13, w13, #0xc0000000
and w14, w14, #0x3fffffff
orr w14, w14, w13
str w14, [x10]
movz w12, #7272
add w12, w15, w12
str w12, [x9, #60]
L_00001c64_success:
mov w0, #1
b L_00001c64_return
L_00001c64_fault:
mov w0, #-1
b L_00001c64_return
L_00001c64_miss:
mov w0, #3
b L_00001c64_return
L_00001c64_mode_miss:
mov w0, #4
L_00001c64_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00001c6c
_agr_game_compiled_00001c6c:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00001c6c_mode_miss
movz w12, #7276
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #57355
cmp w14, w12
b.ne L_00001c6c_miss
movz w12, #7302
add w12, w15, w12
str w12, [x9, #60]
b L_00001c6c_success
L_00001c6c_success:
mov w0, #1
b L_00001c6c_return
L_00001c6c_fault:
mov w0, #-1
b L_00001c6c_return
L_00001c6c_miss:
mov w0, #3
b L_00001c6c_return
L_00001c6c_mode_miss:
mov w0, #4
L_00001c6c_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00001c7c
_agr_game_compiled_00001c7c:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00001c7c_mode_miss
movz w12, #7292
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #8449
cmp w14, w12
b.ne L_00001c7c_miss
movz w12, #1
str w12, [x9, #4]
cmp w12, #0
mrs x13, nzcv
ldr w14, [x10]
and w13, w13, #0xc0000000
and w14, w14, #0x3fffffff
orr w14, w14, w13
str w14, [x10]
movz w12, #7294
add w12, w15, w12
str w12, [x9, #60]
L_00001c7c_success:
mov w0, #1
b L_00001c7c_return
L_00001c7c_fault:
mov w0, #-1
b L_00001c7c_return
L_00001c7c_miss:
mov w0, #3
b L_00001c7c_return
L_00001c7c_mode_miss:
mov w0, #4
L_00001c7c_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00001c80
_agr_game_compiled_00001c80:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00001c80_mode_miss
movz w12, #7296
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #17960
cmp w14, w12
b.ne L_00001c80_miss
ldr w12, [x9, #20]
str w12, [x9, #0]
movz w12, #7298
add w12, w15, w12
str w12, [x9, #60]
L_00001c80_success:
mov w0, #1
b L_00001c80_return
L_00001c80_fault:
mov w0, #-1
b L_00001c80_return
L_00001c80_miss:
mov w0, #3
b L_00001c80_return
L_00001c80_mode_miss:
mov w0, #4
L_00001c80_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00001c86
_agr_game_compiled_00001c86:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00001c86_mode_miss
movz w12, #7302
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #8965
cmp w14, w12
b.ne L_00001c86_miss
movz w12, #5
str w12, [x9, #12]
cmp w12, #0
mrs x13, nzcv
ldr w14, [x10]
and w13, w13, #0xc0000000
and w14, w14, #0x3fffffff
orr w14, w14, w13
str w14, [x10]
movz w12, #7304
add w12, w15, w12
str w12, [x9, #60]
L_00001c86_success:
mov w0, #1
b L_00001c86_return
L_00001c86_fault:
mov w0, #-1
b L_00001c86_return
L_00001c86_miss:
mov w0, #3
b L_00001c86_return
L_00001c86_mode_miss:
mov w0, #4
L_00001c86_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00001c88
_agr_game_compiled_00001c88:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00001c88_mode_miss
movz w12, #7304
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #63487
movk w12, #64718, lsl #16
cmp w14, w12
b.ne L_00001c88_miss
movz w12, #5672
add w12, w15, w12
orr w12, w12, #1
movz w13, #7308
add w13, w15, w13
orr w13, w13, #1
str w13, [x9, #56]
ldr w13, [x10]
and w14, w12, #1
lsl w14, w14, #5
bic w13, w13, #0x20
orr w13, w13, w14
str w13, [x10]
bic w12, w12, #1
str w12, [x9, #60]
b L_00001c88_success
L_00001c88_success:
mov w0, #1
b L_00001c88_return
L_00001c88_fault:
mov w0, #-1
b L_00001c88_return
L_00001c88_miss:
mov w0, #3
b L_00001c88_return
L_00001c88_mode_miss:
mov w0, #4
L_00001c88_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00001c92
_agr_game_compiled_00001c92:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00001c92_mode_miss
movz w12, #7314
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #59101
cmp w14, w12
b.ne L_00001c92_miss
movz w12, #6736
add w12, w15, w12
str w12, [x9, #60]
b L_00001c92_success
L_00001c92_success:
mov w0, #1
b L_00001c92_return
L_00001c92_fault:
mov w0, #-1
b L_00001c92_return
L_00001c92_miss:
mov w0, #3
b L_00001c92_return
L_00001c92_mode_miss:
mov w0, #4
L_00001c92_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00001c94
_agr_game_compiled_00001c94:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00001c94_mode_miss
movz w12, #7316
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #8192
cmp w14, w12
b.ne L_00001c94_miss
movz w12, #0
str w12, [x9, #0]
cmp w12, #0
mrs x13, nzcv
ldr w14, [x10]
and w13, w13, #0xc0000000
and w14, w14, #0x3fffffff
orr w14, w14, w13
str w14, [x10]
movz w12, #7318
add w12, w15, w12
str w12, [x9, #60]
L_00001c94_success:
mov w0, #1
b L_00001c94_return
L_00001c94_fault:
mov w0, #-1
b L_00001c94_return
L_00001c94_miss:
mov w0, #3
b L_00001c94_return
L_00001c94_mode_miss:
mov w0, #4
L_00001c94_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00001c98
_agr_game_compiled_00001c98:
sub sp, sp, #64
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00001c98_mode_miss
movz w12, #7320
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #59581
movk w12, #34800, lsl #16
cmp w14, w12
b.ne L_00001c98_miss
ldr w12, [x9, #52]
movz w13, #0
add w14, w12, w13
cmp w14, #0x1000
b.lo L_00001c98_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w14, w13
b.hi L_00001c98_fault
add x13, x11, w14, uxtw
ldr w14, [x13]
str w14, [sp, #0]
movz w13, #4
add w14, w12, w13
cmp w14, #0x1000
b.lo L_00001c98_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w14, w13
b.hi L_00001c98_fault
add x13, x11, w14, uxtw
ldr w14, [x13]
str w14, [sp, #4]
movz w13, #8
add w14, w12, w13
cmp w14, #0x1000
b.lo L_00001c98_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w14, w13
b.hi L_00001c98_fault
add x13, x11, w14, uxtw
ldr w14, [x13]
str w14, [sp, #8]
movz w13, #12
add w14, w12, w13
cmp w14, #0x1000
b.lo L_00001c98_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w14, w13
b.hi L_00001c98_fault
add x13, x11, w14, uxtw
ldr w14, [x13]
str w14, [sp, #12]
movz w13, #16
add w14, w12, w13
cmp w14, #0x1000
b.lo L_00001c98_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w14, w13
b.hi L_00001c98_fault
add x13, x11, w14, uxtw
ldr w14, [x13]
str w14, [sp, #16]
movz w13, #20
add w14, w12, w13
cmp w14, #0x1000
b.lo L_00001c98_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w14, w13
b.hi L_00001c98_fault
add x13, x11, w14, uxtw
ldr w14, [x13]
str w14, [sp, #20]
movz w13, #24
add w14, w12, w13
cmp w14, #0x1000
b.lo L_00001c98_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w14, w13
b.hi L_00001c98_fault
add x13, x11, w14, uxtw
ldr w14, [x13]
str w14, [sp, #24]
movz w13, #28
add w14, w12, w13
cmp w14, #0x1000
b.lo L_00001c98_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w14, w13
b.hi L_00001c98_fault
add x13, x11, w14, uxtw
ldr w14, [x13]
str w14, [sp, #28]
movz w13, #32
add w12, w12, w13
str w12, [x9, #52]
ldr w12, [sp, #0]
str w12, [x9, #16]
ldr w12, [sp, #4]
str w12, [x9, #20]
ldr w12, [sp, #8]
str w12, [x9, #24]
ldr w12, [sp, #12]
str w12, [x9, #28]
ldr w12, [sp, #16]
str w12, [x9, #32]
ldr w12, [sp, #20]
str w12, [x9, #36]
ldr w12, [sp, #24]
str w12, [x9, #40]
ldr w12, [sp, #28]
str w12, [x9, #60]
ldr w12, [x9, #60]
ldr w13, [x10]
and w14, w12, #1
lsl w14, w14, #5
bic w13, w13, #0x20
orr w13, w13, w14
str w13, [x10]
bic w12, w12, #1
str w12, [x9, #60]
b L_00001c98_success
L_00001c98_success:
mov w0, #1
b L_00001c98_return
L_00001c98_fault:
mov w0, #-1
b L_00001c98_return
L_00001c98_miss:
mov w0, #3
b L_00001c98_return
L_00001c98_mode_miss:
mov w0, #4
L_00001c98_return:
add sp, sp, #64
ret

.text
.p2align 2
.globl _agr_game_compiled_00001c9c
_agr_game_compiled_00001c9c:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00001c9c_mode_miss
movz w12, #7324
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #46367
cmp w14, w12
b.ne L_00001c9c_miss
movz w12, #7326
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #27843
cmp w14, w12
b.ne L_00001c9c_miss
movz w12, #7328
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #17928
cmp w14, w12
b.ne L_00001c9c_miss
movz w12, #7330
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #43265
cmp w14, w12
b.ne L_00001c9c_miss
movz w12, #7332
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #26714
cmp w14, w12
b.ne L_00001c9c_miss
ldr w12, [x9, #52]
movz w13, #24
sub w12, w12, w13
cmp w12, #0x1000
b.lo L_00001c9c_fault
add x13, x11, w12, uxtw
ldr w14, [x9, #0]
str w14, [x13, #0]
ldr w14, [x9, #4]
str w14, [x13, #4]
ldr w14, [x9, #8]
str w14, [x13, #8]
ldr w14, [x9, #12]
str w14, [x13, #12]
ldr w14, [x9, #16]
str w14, [x13, #16]
ldr w14, [x9, #56]
str w14, [x13, #20]
str w12, [x9, #52]
ldr w12, [x9, #0]
movz w13, #76
add w12, w12, w13
cmp w12, #0x1000
b.lo L_00001c9c_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w12, w13
b.hi L_00001c9c_fault
add x13, x11, w12, uxtw
ldr w12, [x13]
str w12, [x9, #12]
ldr w12, [x9, #4]
str w12, [x9, #0]
ldr w12, [x9, #52]
movz w13, #4
add w12, w12, w13
str w12, [x9, #4]
ldr w12, [x9, #12]
movz w13, #4
add w12, w12, w13
cmp w12, #0x1000
b.lo L_00001c9c_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w12, w13
b.hi L_00001c9c_fault
add x13, x11, w12, uxtw
ldr w12, [x13]
str w12, [x9, #8]
movz w12, #7334
add w12, w15, w12
str w12, [x9, #60]
L_00001c9c_success:
mov w0, #1
b L_00001c9c_return
L_00001c9c_fault:
mov w0, #-1
b L_00001c9c_return
L_00001c9c_miss:
mov w0, #3
b L_00001c9c_return
L_00001c9c_mode_miss:
mov w0, #4
L_00001c9c_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00001caa
_agr_game_compiled_00001caa:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00001caa_mode_miss
movz w12, #7338
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #61699
movk w12, #520, lsl #16
cmp w14, w12
b.ne L_00001caa_miss
ldr w12, [x9, #12]
movz w13, #8
add w12, w12, w13
str w12, [x9, #8]
movz w12, #7342
add w12, w15, w12
str w12, [x9, #60]
L_00001caa_success:
mov w0, #1
b L_00001caa_return
L_00001caa_fault:
mov w0, #-1
b L_00001caa_return
L_00001caa_miss:
mov w0, #3
b L_00001caa_return
L_00001caa_mode_miss:
mov w0, #4
L_00001caa_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00001cb0
_agr_game_compiled_00001cb0:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00001cb0_mode_miss
movz w12, #7344
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #8707
cmp w14, w12
b.ne L_00001cb0_miss
movz w12, #3
str w12, [x9, #8]
cmp w12, #0
mrs x13, nzcv
ldr w14, [x10]
and w13, w13, #0xc0000000
and w14, w14, #0x3fffffff
orr w14, w14, w13
str w14, [x10]
movz w12, #7346
add w12, w15, w12
str w12, [x9, #60]
L_00001cb0_success:
mov w0, #1
b L_00001cb0_return
L_00001cb0_fault:
mov w0, #-1
b L_00001cb0_return
L_00001cb0_miss:
mov w0, #3
b L_00001cb0_return
L_00001cb0_mode_miss:
mov w0, #4
L_00001cb0_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00001cbc
_agr_game_compiled_00001cbc:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00001cbc_mode_miss
movz w12, #7356
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #63487
movk w12, #65215, lsl #16
cmp w14, w12
b.ne L_00001cbc_miss
movz w12, #6718
add w12, w15, w12
orr w12, w12, #1
movz w13, #7360
add w13, w15, w13
orr w13, w13, #1
str w13, [x9, #56]
ldr w13, [x10]
and w14, w12, #1
lsl w14, w14, #5
bic w13, w13, #0x20
orr w13, w13, w14
str w13, [x10]
bic w12, w12, #1
str w12, [x9, #60]
b L_00001cbc_success
L_00001cbc_success:
mov w0, #1
b L_00001cbc_return
L_00001cbc_fault:
mov w0, #-1
b L_00001cbc_return
L_00001cbc_miss:
mov w0, #3
b L_00001cbc_return
L_00001cbc_mode_miss:
mov w0, #4
L_00001cbc_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00001cc6
_agr_game_compiled_00001cc6:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00001cc6_mode_miss
movz w12, #7366
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #46344
cmp w14, w12
b.ne L_00001cc6_miss
movz w12, #7368
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #63487
movk w12, #65208, lsl #16
cmp w14, w12
b.ne L_00001cc6_miss
ldr w12, [x9, #52]
movz w13, #8
sub w12, w12, w13
cmp w12, #0x1000
b.lo L_00001cc6_fault
add x13, x11, w12, uxtw
ldr w14, [x9, #12]
str w14, [x13, #0]
ldr w14, [x9, #56]
str w14, [x13, #4]
str w12, [x9, #52]
movz w12, #6716
add w12, w15, w12
orr w12, w12, #1
movz w13, #7372
add w13, w15, w13
orr w13, w13, #1
str w13, [x9, #56]
ldr w13, [x10]
and w14, w12, #1
lsl w14, w14, #5
bic w13, w13, #0x20
orr w13, w13, w14
str w13, [x10]
bic w12, w12, #1
str w12, [x9, #60]
b L_00001cc6_success
L_00001cc6_success:
mov w0, #1
b L_00001cc6_return
L_00001cc6_fault:
mov w0, #-1
b L_00001cc6_return
L_00001cc6_miss:
mov w0, #3
b L_00001cc6_return
L_00001cc6_mode_miss:
mov w0, #4
L_00001cc6_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00001ccc
_agr_game_compiled_00001ccc:
sub sp, sp, #64
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00001ccc_mode_miss
movz w12, #7372
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #27776
cmp w14, w12
b.ne L_00001ccc_miss
movz w12, #7374
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #48392
cmp w14, w12
b.ne L_00001ccc_miss
ldr w12, [x9, #0]
movz w13, #72
add w12, w12, w13
cmp w12, #0x1000
b.lo L_00001ccc_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w12, w13
b.hi L_00001ccc_fault
add x13, x11, w12, uxtw
ldr w12, [x13]
str w12, [x9, #0]
ldr w12, [x9, #52]
movz w13, #0
add w14, w12, w13
cmp w14, #0x1000
b.lo L_00001ccc_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w14, w13
b.hi L_00001ccc_fault
add x13, x11, w14, uxtw
ldr w14, [x13]
str w14, [sp, #0]
movz w13, #4
add w14, w12, w13
cmp w14, #0x1000
b.lo L_00001ccc_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w14, w13
b.hi L_00001ccc_fault
add x13, x11, w14, uxtw
ldr w14, [x13]
str w14, [sp, #4]
movz w13, #8
add w12, w12, w13
str w12, [x9, #52]
ldr w12, [sp, #0]
str w12, [x9, #12]
ldr w12, [sp, #4]
str w12, [x9, #60]
ldr w12, [x9, #60]
ldr w13, [x10]
and w14, w12, #1
lsl w14, w14, #5
bic w13, w13, #0x20
orr w13, w13, w14
str w13, [x10]
bic w12, w12, #1
str w12, [x9, #60]
b L_00001ccc_success
L_00001ccc_success:
mov w0, #1
b L_00001ccc_return
L_00001ccc_fault:
mov w0, #-1
b L_00001ccc_return
L_00001ccc_miss:
mov w0, #3
b L_00001ccc_return
L_00001ccc_mode_miss:
mov w0, #4
L_00001ccc_return:
add sp, sp, #64
ret

.text
.p2align 2
.globl _agr_game_compiled_00001cd0
_agr_game_compiled_00001cd0:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00001cd0_mode_miss
movz w12, #7376
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #46344
cmp w14, w12
b.ne L_00001cd0_miss
movz w12, #7378
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #63487
movk w12, #65203, lsl #16
cmp w14, w12
b.ne L_00001cd0_miss
ldr w12, [x9, #52]
movz w13, #8
sub w12, w12, w13
cmp w12, #0x1000
b.lo L_00001cd0_fault
add x13, x11, w12, uxtw
ldr w14, [x9, #12]
str w14, [x13, #0]
ldr w14, [x9, #56]
str w14, [x13, #4]
str w12, [x9, #52]
movz w12, #6716
add w12, w15, w12
orr w12, w12, #1
movz w13, #7382
add w13, w15, w13
orr w13, w13, #1
str w13, [x9, #56]
ldr w13, [x10]
and w14, w12, #1
lsl w14, w14, #5
bic w13, w13, #0x20
orr w13, w13, w14
str w13, [x10]
bic w12, w12, #1
str w12, [x9, #60]
b L_00001cd0_success
L_00001cd0_success:
mov w0, #1
b L_00001cd0_return
L_00001cd0_fault:
mov w0, #-1
b L_00001cd0_return
L_00001cd0_miss:
mov w0, #3
b L_00001cd0_return
L_00001cd0_mode_miss:
mov w0, #4
L_00001cd0_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00001cd6
_agr_game_compiled_00001cd6:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00001cd6_mode_miss
movz w12, #7382
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #27843
cmp w14, w12
b.ne L_00001cd6_miss
ldr w12, [x9, #0]
movz w13, #76
add w12, w12, w13
cmp w12, #0x1000
b.lo L_00001cd6_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w12, w13
b.hi L_00001cd6_fault
add x13, x11, w12, uxtw
ldr w12, [x13]
str w12, [x9, #12]
movz w12, #7384
add w12, w15, w12
str w12, [x9, #60]
L_00001cd6_success:
mov w0, #1
b L_00001cd6_return
L_00001cd6_fault:
mov w0, #-1
b L_00001cd6_return
L_00001cd6_miss:
mov w0, #3
b L_00001cd6_return
L_00001cd6_mode_miss:
mov w0, #4
L_00001cd6_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00001ce0
_agr_game_compiled_00001ce0:
sub sp, sp, #64
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00001ce0_mode_miss
movz w12, #7392
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #48392
cmp w14, w12
b.ne L_00001ce0_miss
ldr w12, [x9, #52]
movz w13, #0
add w14, w12, w13
cmp w14, #0x1000
b.lo L_00001ce0_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w14, w13
b.hi L_00001ce0_fault
add x13, x11, w14, uxtw
ldr w14, [x13]
str w14, [sp, #0]
movz w13, #4
add w14, w12, w13
cmp w14, #0x1000
b.lo L_00001ce0_fault
movz w13, #65532
movk w13, #65535, lsl #16
cmp w14, w13
b.hi L_00001ce0_fault
add x13, x11, w14, uxtw
ldr w14, [x13]
str w14, [sp, #4]
movz w13, #8
add w12, w12, w13
str w12, [x9, #52]
ldr w12, [sp, #0]
str w12, [x9, #12]
ldr w12, [sp, #4]
str w12, [x9, #60]
ldr w12, [x9, #60]
ldr w13, [x10]
and w14, w12, #1
lsl w14, w14, #5
bic w13, w13, #0x20
orr w13, w13, w14
str w13, [x10]
bic w12, w12, #1
str w12, [x9, #60]
b L_00001ce0_success
L_00001ce0_success:
mov w0, #1
b L_00001ce0_return
L_00001ce0_fault:
mov w0, #-1
b L_00001ce0_return
L_00001ce0_miss:
mov w0, #3
b L_00001ce0_return
L_00001ce0_mode_miss:
mov w0, #4
L_00001ce0_return:
add sp, sp, #64
ret

.text
.p2align 2
.globl _agr_game_compiled_00001ce2
_agr_game_compiled_00001ce2:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00001ce2_mode_miss
movz w12, #7394
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #46344
cmp w14, w12
b.ne L_00001ce2_miss
movz w12, #7396
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #63487
movk w12, #59444, lsl #16
cmp w14, w12
b.ne L_00001ce2_miss
ldr w12, [x9, #52]
movz w13, #8
sub w12, w12, w13
cmp w12, #0x1000
b.lo L_00001ce2_fault
add x13, x11, w12, uxtw
ldr w14, [x9, #12]
str w14, [x13, #0]
ldr w14, [x9, #56]
str w14, [x13, #4]
str w12, [x9, #52]
movz w12, #3408
add w12, w15, w12
movz w13, #7400
add w13, w15, w13
orr w13, w13, #1
str w13, [x9, #56]
ldr w13, [x10]
and w14, w12, #1
lsl w14, w14, #5
bic w13, w13, #0x20
orr w13, w13, w14
str w13, [x10]
bic w12, w12, #1
str w12, [x9, #60]
b L_00001ce2_success
L_00001ce2_success:
mov w0, #1
b L_00001ce2_return
L_00001ce2_fault:
mov w0, #-1
b L_00001ce2_return
L_00001ce2_miss:
mov w0, #3
b L_00001ce2_return
L_00001ce2_mode_miss:
mov w0, #4
L_00001ce2_return:
ret

.text
.p2align 2
.globl _agr_game_compiled_00001ce8
_agr_game_compiled_00001ce8:
ldr x9, [x0]
ldr x10, [x0, #8]
ldr x11, [x0, #16]
ldr w15, [x0, #24]
ldr w12, [x10]
and w12, w12, #0x20
cmp w12, #32
b.ne L_00001ce8_mode_miss
movz w12, #7400
add w12, w15, w12
add x13, x11, w12, uxtw
ldrh w14, [x13]
movz w12, #46344
cmp w14, w12
b.ne L_00001ce8_miss
movz w12, #7402
add w12, w15, w12
add x13, x11, w12, uxtw
ldr w14, [x13]
movz w12, #63487
movk w12, #59442, lsl #16
cmp w14, w12
b.ne L_00001ce8_miss
ldr w12, [x9, #52]
movz w13, #8
sub w12, w12, w13
cmp w12, #0x1000
b.lo L_00001ce8_fault
add x13, x11, w12, uxtw
ldr w14, [x9, #12]
str w14, [x13, #0]
ldr w14, [x9, #56]
str w14, [x13, #4]
str w12, [x9, #52]
movz w12, #3408
add w12, w15, w12
movz w13, #7406
add w13, w15, w13
orr w13, w13, #1
str w13, [x9, #56]
ldr w13, [x10]
and w14, w12, #1
lsl w14, w14, #5
bic w13, w13, #0x20
orr w13, w13, w14
str w13, [x10]
bic w12, w12, #1
str w12, [x9, #60]
b L_00001ce8_success
L_00001ce8_success:
mov w0, #1
b L_00001ce8_return
L_00001ce8_fault:
mov w0, #-1
b L_00001ce8_return
L_00001ce8_miss:
mov w0, #3
b L_00001ce8_return
L_00001ce8_mode_miss:
mov w0, #4
L_00001ce8_return:
ret
