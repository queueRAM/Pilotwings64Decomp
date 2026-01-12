#include "common.h"
#include <uv_graphics.h>

void *func_802256B8(void*);

extern u32 D_802B53F4[];

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/texture/func_802246A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/texture/func_80224A90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/texture/uvMemLoadPal.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/texture/uvMemLoadDS.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/texture/func_80225394.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/texture/func_80225470.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/texture/func_802254B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/texture/func_802255A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/texture/func_802256B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/texture/func_80225FBC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/texture/_uvExpandTexture.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/texture/_uvExpandTextureImg.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/texture/_uvExpandTextureCpy.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/texture/func_80226FD0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/texture/func_802270BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/texture/func_80227260.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/texture/func_80227804.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/texture/func_802278C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/texture/func_80227938.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/texture/func_802279B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/texture/func_80227A28.s")

//#pragma GLOBAL_ASM("asm/nonmatchings/kernel/texture/func_80227AA0.s")
s32 func_80227AA0(s32 arg0) {
    s32 temp_v0;
    s32 tag;
    u32 sp3C;
    void* sp38;
    s32 ret;

    ret = 0;
    temp_v0 = func_80223E80(D_802B53F4[arg0]);
    while ((tag = func_80223F7C(temp_v0, &sp3C, &sp38, 1)) != 0) {
        if (tag == 'COMM') { // 0x434F4D4D
            if (1) {} // fakematch
            ret = func_802256B8(sp38);
        }
    }
    func_80223F30(temp_v0);
    return ret;
}

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/texture/func_80227B5C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/texture/func_80227BD4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/texture/func_80227C84.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/texture/func_80227D34.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/texture/func_80227DE4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/texture/func_80227E5C.s")
