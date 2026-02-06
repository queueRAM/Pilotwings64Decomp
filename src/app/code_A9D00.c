#include "common.h"
#include <uv_controller.h>
#include <uv_util.h>
#include "code_9A960.h"
#include "code_A9D00.h"

typedef struct {
    u8 pad0[4];
    u32 unk4;
} Unk803227D0;

extern s32 D_8034FAD0;
extern f32 D_8036DA34;
extern f32 D_8036DA38;
extern s32 D_8036DA40;
extern s32 D_8036DA58;

f32 func_803227D0(Unk803227D0* arg0) {
    return (f32) (((f32)((arg0->unk4 & 0xFF000000) >> 24) / 127.0) - 1.0);
}

f32 func_80322828(Unk803227D0* arg0) {
    return (f32) (((f32)((arg0->unk4 & 0x00FF0000) >> 16) / 127.0) - 1.0);
}

u32 func_80322880(Unk803227D0* arg0) {
    return arg0->unk4 & 0x0000FFFF;
}

void func_80322890(Unk803227D0* arg0, f32 arg1, f32 arg2, u32 arg3) {
    arg0->unk4 = (u32) (((u32) ((arg1 + 1.0) * 127.0) << 0x18) | ((u32) ((1.0 + arg2) * 127.0) << 0x10) | arg3);
}

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_A9D00/func_803229EC.s")

s32 func_80322B60(void) {
    return D_8036DA58;
}

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_A9D00/func_80322B6C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_A9D00/func_80322B78.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_A9D00/func_80322B84.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_A9D00/func_80322B90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_A9D00/func_80322BE0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_A9D00/func_80322D60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_A9D00/func_80322DA8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_A9D00/func_80322EB0.s")

void func_80322EBC(void) {
    if (D_8034FAD0 == 1) {
        _uvDebugPrintf("%.10f(%.10f, %.10f)0x%x\n", D_8034F850 - D_8036DA34, uvControllerGetStick(0, 0), uvControllerGetStick(0, 1), uvControllerGetButton(0));
    }
    if (D_8036DA38 <= D_8034F850) {
        func_80322DA8(0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_A9D00/func_80322F7C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_A9D00/func_80323020.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_A9D00/func_803230B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_A9D00/func_80323164.s")

s32 func_803231A0(s32 arg0, s32 arg1) {
    if (D_8034FAD0 == 2) {
        return arg1 & D_8036DA40;
    }
    return uvControllerButtonCheck(arg0, arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_A9D00/func_803231E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_A9D00/func_80323240.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_A9D00/func_803232A0.s")
