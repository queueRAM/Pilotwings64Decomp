#include "common.h"

#include <uv_geometry.h>
#include <uv_graphics.h>
#include <uv_math.h>
#include <uv_sobj.h>
#include <uv_sprite.h>
#include "code_9F2D0.h"
#include "snap.h"

extern HUDData D_8036C5A8;
extern u8 D_8036D220;

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_9F2D0/func_80317DA0.s")

HUDData* getHUDPtr(void) {
    return &D_8036C5A8;
}

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_9F2D0/func_803182A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_9F2D0/func_80318700.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_9F2D0/func_803187C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_9F2D0/func_8031888C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_9F2D0/func_80319C8C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_9F2D0/func_80319E44.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_9F2D0/func_80319EFC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_9F2D0/func_80319FEC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_9F2D0/func_8031A118.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_9F2D0/func_8031A224.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_9F2D0/func_8031A2CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_9F2D0/func_8031A378.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_9F2D0/func_8031A66C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_9F2D0/func_8031A6C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_9F2D0/func_8031A794.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_9F2D0/func_8031A810.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_9F2D0/func_8031A874.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_9F2D0/func_8031A8E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_9F2D0/func_8031A954.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_9F2D0/func_8031AD68.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_9F2D0/func_8031BE88.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_9F2D0/demoShowController.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_9F2D0/func_8031C0B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_9F2D0/func_8031C1E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_9F2D0/func_8031C900.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_9F2D0/func_8031D15C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_9F2D0/func_8031D264.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_9F2D0/func_8031D494.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_9F2D0/func_8031D550.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_9F2D0/func_8031D8E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_9F2D0/func_8031D9B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_9F2D0/func_8031DA90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_9F2D0/func_8031DA9C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_9F2D0/func_8031DAA8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_9F2D0/func_8031DAF4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_9F2D0/func_8031DC00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_9F2D0/func_8031DD0C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_9F2D0/func_8031DF68.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_9F2D0/func_8031DF74.s")

void func_8031E628(f32 arg0, f32* arg1, f32* arg2) {
    f32 a2tmp;
    f32 length;
    f32 a1tmp;
    f32 scale;

    a2tmp = *arg2;
    a1tmp = *arg1;
    length = uvSqrtF(SQ(a2tmp) + SQ(a1tmp));
    if (arg0 < length) {
        scale = arg0 / length;
        *arg1 *= scale;
        *arg2 *= scale;
    }
}

void func_8031E69C(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, u8 arg5, u8 arg6, u8 arg7, u8 arg8) {
    uvVtxBeginPoly();
    uvVtx(arg0, arg1, 0, 0, 0, arg5, arg6, arg7, arg8);
    uvVtx(arg0 + arg2, arg1, 0, 0, 0, arg5, arg6, arg7, arg8);
    uvVtx(arg0 + arg2, arg1 + arg4, 0, 0, 0, arg5, arg6, arg7, arg8);
    uvVtx(arg0, arg1 + arg4, 0, 0, 0, arg5, arg6, arg7, arg8);
    uvVtxEndPoly();

    uvVtxBeginPoly();
    uvVtx(arg0, arg1, 0, 0, 0, arg5, arg6, arg7, arg8);
    uvVtx(arg0 + arg4, arg1, 0, 0, 0, arg5, arg6, arg7, arg8);
    uvVtx(arg0 + arg4, arg1 + arg3, 0, 0, 0, arg5, arg6, arg7, arg8);
    uvVtx(arg0, arg1 + arg3, 0, 0, 0, arg5, arg6, arg7, arg8);
    uvVtxEndPoly();
    
    uvVtxBeginPoly();
    uvVtx(arg0, arg1 + arg3 - arg4, 0, 0, 0, arg5, arg6, arg7, arg8);
    uvVtx(arg0 + arg2, arg1 + arg3 - arg4, 0, 0, 0, arg5, arg6, arg7, arg8);
    uvVtx(arg0 + arg2, arg1 + arg3, 0, 0, 0, arg5, arg6, arg7, arg8);
    uvVtx(arg0, arg1 + arg3, 0, 0, 0, arg5, arg6, arg7, arg8);
    uvVtxEndPoly();
    
    if (1) { // fakematch
        uvVtxBeginPoly();
        uvVtx(arg0 + arg2 - arg4, arg1, 0, 0, 0, arg5, arg6, arg7, arg8);
        uvVtx(arg0 + arg2, arg1, 0, 0, 0, arg5, arg6, arg7, arg8);
        uvVtx(arg0 + arg2, arg1 + arg3, 0, 0, 0, arg5, arg6, arg7, arg8);
        uvVtx(arg0 + arg2 - arg4, arg1 + arg3, 0, 0, 0, arg5, arg6, arg7, arg8);
        uvVtxEndPoly();
    }
}

void func_8031E9F8(void) {
    char buf[12];
    (void)func_8033F618();
    uvFontSet(8);
    uvFont_8021956C(0xFF, 0xFF, 0xFF, 0xFF);
    uvFont_80219550(1.0, 1.0);
    func_8022DA9C(buf, "%d", func_8033F618());
    uvFont_80219ACC(0xA0, 0x1E, buf);
    uvSprtProps(0xA, 2, 0x96, 0x1C, 7, 0xFF, 0xFF, 0xFF, 0xFF, 0);
    uvSprtDraw(0xA);
}

void func_8031EABC(u8 arg0) {
    D_8036D220 = arg0;
}
