#include "common.h"
#include "hover_pads.h"

s32 D_8034F3F0[4] = { 0xFC, 0xFB, 0, 0 };

#pragma GLOBAL_ASM("asm/nonmatchings/app/hover_pads/func_803097E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/hover_pads/func_80309868.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/hover_pads/func_803099A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/hover_pads/func_80309A64.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/hover_pads/func_80309C48.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/hover_pads/func_80309D64.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/hover_pads/func_80309D6C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/hover_pads/func_80309E68.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/hover_pads/func_80309EA8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/hover_pads/func_80309F04.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/hover_pads/func_80309FFC.s")

u8 func_8030A080(void) {
    u8 ret;
    s32 i;

    ret = 0;
    for (i = 0; i < D_80369584; i++) {
        ret += (D_80369588[i].unk68 != 0) ? 1 : 0;
    }
    return ret;
}

#pragma GLOBAL_ASM("asm/nonmatchings/app/hover_pads/func_8030A0DC.s")
