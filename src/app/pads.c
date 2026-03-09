#include "common.h"
#include "pads.h"

typedef struct {
    u8 pad0[0x10];
    s32 unk10;
    u8 pad14[4];
} Unk8036C168;

extern Unk8036C168 D_8036C168[];
extern s8 D_8036C2B8;
extern s8 D_8036C2BB;
extern s8 D_8036C2BC;

s8 D_8034F900 = 0;
u16 D_8034F904[] = { 0x0102, 0x0103, 0x0104, 0x0000, 0x0000, 0x0000 };

void padsInit(void) {
    Unk8036C168* var_a0;
    LandingPad* pad;
    LandingStrip* strip;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(gLandingPads); i++) {
        gLandingPads[i].unk15 = 0;
        gLandingPads[i].unk14 = 0;
        D_8036C168[i].unk10 = 0;
    }
    for (i = 0; i < ARRAY_COUNT(gLandingStrips); i++) {
        gLandingStrips[i].unk39 = 0;
        gLandingStrips[i].unk38 = 0;
    }
    gLandingStripCount = 0;
    gLandingPadCount = 0;
    D_8036C2B8 = 0;
    D_8036C2BB = 0;
    D_8036C2BC = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/app/pads/padsLoad.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/pads/padsFrameUpdate.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/pads/func_80317764.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/pads/padsDeinit.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/pads/func_80317854.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/pads/func_80317978.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/pads/func_80317B50.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/pads/func_80317C2C.s")
