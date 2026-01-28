#include "common.h"
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

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/code_32A70/func_80233590.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/code_32A70/func_80233810.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/code_32A70/func_80233878.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/code_32A70/func_802338A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/code_32A70/func_802339B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/code_32A70/func_80233A40.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/code_32A70/func_80233D04.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/code_32A70/func_80233DB8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/code_32A70/func_80233FC8.s")
