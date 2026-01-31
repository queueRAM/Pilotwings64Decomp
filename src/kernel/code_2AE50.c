#include "common.h"
#include <math.h>

f32 SqrtF(f32 x) {
    return sqrtf(x);
}

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/code_2AE50/func_80229EC0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/code_2AE50/func_8022A080.s")

void Length2D(f32 x, f32 y) {
    SqrtF(SQ(x) + SQ(y));
}

void Length3D(f32 x, f32 y, f32 z) {
    SqrtF(SQ(x) + SQ(y) + SQ(z));
}

f32 func_8022A27C(f32, f32);
#pragma GLOBAL_ASM("asm/nonmatchings/kernel/code_2AE50/func_8022A27C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/code_2AE50/D_8024E3A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/code_2AE50/D_8024E3C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/code_2AE50/D_8024E3D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/code_2AE50/D_8024E3D8.s")
