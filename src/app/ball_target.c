#include "common.h"
#include <uv_dobj.h>
#include <uv_level.h>
#include "ball_target.h"

typedef struct {
    u16 objId;
    u8 pad2[0x5A - 0x2];
    u8 unk5A;
    u8 unk5B;
    u8 unk5C;
    u8 unk5D;
    u8 pad5E[0x60 - 0x5E];
} BallTarget;

extern LevelBTGT* D_803597E0;
extern u8 D_803597E4;
extern BallTarget D_803597E8[];

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

void func_802D28D8(void) {
    BallTarget* var_s0;
    s32 i;

    for (i = 0; i < D_803597E4; i++) {
        var_s0 = &D_803597E8[i];
        if (D_80362690->unk0[D_80362690->unk9C].unkC.unk8 == D_803597E0[i].unkC) {
            var_s0->unk5D = 1;
            if (var_s0->objId != 0xFFFF) {
                uvDobjSetState(var_s0->objId, 2);
            }
        } else {
            _uvDebugPrintf("btgts_terra : %d btgt not in terra\n", i);
            var_s0->unk5D = 0;
            if (var_s0->objId != 0xFFFF) {
                uvDobjClearState(var_s0->objId, 2);
            }
        }
    }
}

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
