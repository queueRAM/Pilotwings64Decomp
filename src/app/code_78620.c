#include "common.h"
#include <uv_dobj.h>
#include "code_78620.h"

typedef struct {
    s32 unk0;
    f32 unk4;
    u8 pad4[0x1C];
} Unk80368010; // size = 0x24

extern Unk80368010 D_80368010[];

void func_802F10F0(s32);
#pragma GLOBAL_ASM("asm/nonmatchings/app/code_78620/func_802F10F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_78620/func_802F11F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_78620/func_802F12BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_78620/func_802F13C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_78620/func_802F15C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_78620/func_802F182C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_78620/func_802F1AE8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_78620/func_802F1D3C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_78620/func_802F1FA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_78620/func_802F1FF0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_78620/func_802F205C.s")

void func_802F2110(s32 idx, f32 interval) {
    if (D_80368010[idx].unk0 != 0xFFFF) {
        uvDobjState(D_80368010[idx].unk0, 2);
        D_80368010[idx].unk4 = interval * 360.0f;
        func_802F10F0(idx);
    }
}
