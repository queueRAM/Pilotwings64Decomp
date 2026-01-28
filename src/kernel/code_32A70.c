#include "common.h"
#include "uv_controller.h"
#include "uv_graphics.h"
#include "uv_util.h"

void func_80232554(u8);
void func_80232738(u8);

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/code_32A70/func_80231AC0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/code_32A70/func_80231C10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/code_32A70/func_80231C9C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/code_32A70/func_80231F04.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/code_32A70/D_8024F350.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/code_32A70/func_8023217C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/code_32A70/func_802323A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/code_32A70/func_80232554.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/code_32A70/func_80232738.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/code_32A70/func_8023286C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/code_32A70/ptstart.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/code_32A70/func_80232ECC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/code_32A70/func_80233310.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/code_32A70/func_802333AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/code_32A70/func_8023345C.s")

#ifndef NON_MATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/kernel/code_32A70/uvDbgCnt.s")
#else
void uvDbgCnt(u8 arg0, u8 arg1) {
    if (arg0 == 0) {
        return;
    } else {
        if (arg1 == 1) {
            _uvDebugPrintf("uvDbgCnt: bar count not supported\n");
        } else if (arg1 == 2) {
            func_80232554(arg0);
        } else if (arg1 == 3) {
            func_80232738(arg0);
        }
    }
}
#endif

#ifndef NON_MATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/kernel/code_32A70/func_80233590.s")
#else
void func_80233590(void) {
    u8* sp2C;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp1C;

    sp2C = (u8*)0x80200000;
    sp20 = 0.0f;
    sp1C = 0.0f;
    while (uvIOUpdate() != 0) {
        sp28 = uvControllerGetStick(0, 0);
        sp24 = uvControllerGetStick(0, 1);
        sp20 += sp28 * sp28 * sp28 * 8.0f;
        sp1C += sp24 * sp24 * sp24 * 128.0f;
        if (sp20 > 40.0f) {
            sp20 = 0.0f, sp1C += 1.0f;
        }
        if (sp20 < 0.0f) {
            sp20 = 40.0f, sp1C -= 1.0f;
        }
        if (sp1C < 0.0f) {
            sp1C = 0.0f;
        }
        if (sp1C > 6553.6f) {
            sp1C = 6553.6f;
        }
        sp2C = (u8*)((s32)sp20 * 0x10) + ((s32)sp1C * 0x140 * 2) + 0x80000000;
        uvGfxBegin();
        uvGfxEnd();
        osViSwapBuffer(sp2C);
        if (uvControllerButtonPress(0, Z_TRIG) != 0) {
            break;
        }
        if (uvControllerButtonPress(0, START_BUTTON) != 0) {
            break;
        }

        if (uvControllerButtonPress(0, A_BUTTON) != 0) {
            _uvDebugPrintf("Address: 0x%x\n", sp2C);
        }
    }
}
#endif

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/code_32A70/func_80233810.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/code_32A70/func_80233878.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/code_32A70/func_802338A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/code_32A70/func_802339B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/code_32A70/func_80233A40.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/code_32A70/func_80233D04.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/code_32A70/func_80233DB8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/code_32A70/func_80233FC8.s")
