#include "common.h"
#include "ball_target.h"

typedef struct {
    u16 unk0;
    u8 pad2[0x5A - 0x2];
    u8 unk5A;
    u8 unk5B;
    s8 unk5C;
    u8 pad5D[0x60 - 0x5D];
} Unk803597E8;

extern u8 D_803597E4;
extern Unk803597E8 D_803597E8[5];

#ifndef NON_MATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/app/ball_target/func_802D2850.s")
#else
// needs some refinement on loop unrolling
void func_802D2850(void) {
    s32 i;
    for (i = 0; i < ARRAY_COUNT(D_803597E8); i++) {
        D_803597E8[i].unk0 = 0xFFFF;
        D_803597E8[i].unk5B = 0x00;
        D_803597E8[i].unk5C = 0x00;
        D_803597E8[i].unk5A = 0xFF;
    }
}
#endif

#pragma GLOBAL_ASM("asm/nonmatchings/app/ball_target/func_802D28D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/ball_target/func_802D29FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/ball_target/func_802D2ACC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/ball_target/func_802D2C20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/ball_target/func_802D2E48.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/ball_target/func_802D3030.s")

u8 func_802D30B4(void) {
    s32 i;
    u8 ret;

    ret = 0;
    for (i = 0; i < D_803597E4; i++) {
        ret += (D_803597E8[i].unk5B != 0) ? 1 : 0;
    }
    return ret;
}

#pragma GLOBAL_ASM("asm/nonmatchings/app/ball_target/func_802D3110.s")
