#include "common.h"
#include <uv_level.h>
#include <uv_util.h>
#include "code_9A960.h"
#include "hover_pads.h"
#include "hud.h"

s32 D_8034F3F0[4] = { 0xFC, 0xFB, 0, 0 };

extern LevelHPAD* gRefHPAD;
extern u8 gHoverPadCount;

// forward declarations
void func_803099A8(HoverPad*);

#pragma GLOBAL_ASM("asm/nonmatchings/app/hover_pads/func_803097E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/hover_pads/func_80309868.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/hover_pads/func_803099A8.s")

void hoverPadLoad(void) {
    HoverPad* hover;
    LevelHPAD* hpad;
    s32 i;
    s32 j;

    if (D_80362690->unkA0 == 0) {
        return;
    }

    gHoverPadCount = levelDataGetHPAD(&gRefHPAD);
    if (gHoverPadCount > ARRAY_COUNT(gHoverPads)) {
        _uvDebugPrintf("hpads : too many hpads defined in level [%d]\n", gHoverPadCount);
        gHoverPadCount = 0;
        return;
    }

    if (gHoverPadCount != 0) {
        uvLevelAppend(0x13);
        for (i = 0; i < gHoverPadCount; i++) {
            hover = &gHoverPads[i];
            hpad = &gRefHPAD[i];
            if (hover->unk68 == 0) {
                if (hover->unk69 == 0) {
                    hover->unk44 = hpad->unk1C;
                    hover->unk6B = hpad->unk3C;
                    hover->unk4C = hpad->unk24;
                    hover->unk45 = hpad->unk1D;
                    hover->unk48 = hpad->unk20;

                    for (j = 0; j < hover->unk4C; j++) {
                        hover->unk50[j] = hpad->unk28[j];
                    }

                    if ((hover->unk6B != 0) && (hover->unk4C > 0)) {
                        hover->unk6C = 1;
                    }
                    func_80313640(hpad->unk0.x, hpad->unk0.y, hpad->unk0.z, hpad->unkC.x * 0.0174533f, hpad->unkC.y * 0.0174533f, hpad->unkC.z * 0.0174533f,
                                  &hover->unk4);
                    hover->unk69 = 1;
                    if (hover->unk6B != 0) {
                        hover->unk6D = hud_8031A6C8(hpad->unk0.x, hpad->unk0.y, hpad->unk0.z);
                    }
                }
                func_803099A8(hover);
            }
        }
        func_80309868();
    }
}

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
    for (i = 0; i < gHoverPadCount; i++) {
        ret += (gHoverPads[i].unk68 != 0) ? 1 : 0;
    }
    return ret;
}

#pragma GLOBAL_ASM("asm/nonmatchings/app/hover_pads/func_8030A0DC.s")
