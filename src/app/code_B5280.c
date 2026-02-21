#include "common.h"
#include <uv_graphics.h>
#include <uv_level.h>
#include "code_B5280.h"
#include "menu.h"

void func_80312FF8(s32);
s32 func_8033F62C(void);
void func_803405E4(void);
extern s32 D_8034FFA0[]; // gResultsMenu

// forward declarations
u8 func_8032DE14(void);
u8 func_8032DE74(void);
void func_8032E060(void);
void func_8032E698(void);
s32 func_8032E6B8(s32);
void func_8032E940(s32);

s32 func_8032DD50(s32 arg0) {
    Unk80362690_Unk0_UnkC* temp_s1;
    s32 var_v1;

    temp_s1 = &D_80362690->unk0[D_80362690->unk9C].unkC;
    func_8032E060();

    while ((var_v1 = func_8032E6B8(arg0)) == 0) {
        uvGfxBegin();
        func_80204FC4((s32)temp_s1->unk70->unk22C);
        func_8032E940(arg0);
        uvGfxEnd();
    }

    func_8032E698();

    // FIXME: Unk80362690_Unk0_UnkC is wrong, indexing 15 in 4-byte buffer to match
    if ((temp_s1->unk2 == 3) && (temp_s1->pad7C[15] != 0)) {
        temp_s1->pad7C[15] = 0;
    }
    return var_v1;
}

u8 func_8032DE14(void) {
    Unk80362690_Unk0_UnkC* temp_a0;

    temp_a0 = &D_80362690->unk0[D_80362690->unk9C].unkC;
    if (D_80362690->unk0[D_80362690->unk9C].unkC.unk7B != 0) {
        return 0;
    }
    return (temp_a0->unk2 == 0 || temp_a0->unk2 == 6);
}

u8 func_8032DE74(void) {
    Unk80362690_Unk0_UnkC* temp_s1;
    s32 var_v1;

    temp_s1 = &D_80362690->unk0[D_80362690->unk9C].unkC;
    var_v1 = (temp_s1->unk2 == 0 || temp_s1->unk2 == 1 || temp_s1->unk2 == 2 || temp_s1->unk2 == 6);
    if (levelDataGetFALC(NULL) != 0) {
        var_v1 = 0;
    }
    return var_v1;
}

// populates menu at results screen, showing Check Photo/Replay/Next
void func_8032DF08(void) {
    s32 idx;
    u8* ptr;
    u8 val = 0xE; // fakematch?

    idx = 0;
    if (func_8032DE14() != 0) {
        ptr = levelGet_80345CB0();
        if (ptr[1] == 1) {
            func_803405E4();
        }
        D_8034FFA0[0] = val; // Check Photo
        idx = 1;
    }
    if (func_8032DE74()) {
        D_8034FFA0[idx++] = 0x60; // Replay
    }
    D_8034FFA0[idx++] = 0x5B; // Next
    menuCreateItems(170, 2, 6, 1.0f, 1.0f, D_8034FFA0, idx);
    if (func_8032DE14() && !func_8033F62C()) {
        menu_8030B69C(1);
    }
    func_80312FF8(5);
}

s32 func_8032E000(s32 arg0) {
    if (arg0 < 0) {
        return arg0;
    }
    switch (D_8034FFA0[arg0]) {
    case 0xE: // Check Photo
        return 0;
    case 0x60: // Replay
        return 1;
    case 0x5B: // Next
        return 2;
    default:
        return -1;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_B5280/D_803556B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_B5280/D_803556B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_B5280/D_803556C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_B5280/D_803556D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_B5280/D_803556DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_B5280/D_803556E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_B5280/D_803556F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_B5280/D_80355700.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_B5280/D_8035570C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_B5280/D_80355718.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_B5280/D_80355720.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_B5280/D_8035572C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_B5280/D_80355738.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_B5280/D_80355744.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_B5280/D_80355750.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_B5280/D_8035575C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_B5280/D_80355768.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_B5280/D_80355774.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_B5280/D_80355780.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_B5280/D_80355788.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_B5280/D_80355794.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_B5280/D_803557A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_B5280/D_803557AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_B5280/D_803557B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_B5280/D_803557C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_B5280/D_803557D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_B5280/D_803557DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_B5280/D_803557E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_B5280/D_803557F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_B5280/D_80355800.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_B5280/D_8035580C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_B5280/D_80355818.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_B5280/D_80355824.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_B5280/D_80355830.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_B5280/D_8035583C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_B5280/D_80355848.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_B5280/D_80355854.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_B5280/D_80355860.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_B5280/D_8035586C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_B5280/D_80355878.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_B5280/D_80355884.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_B5280/D_80355890.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_B5280/D_8035589C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_B5280/D_803558A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_B5280/D_803558B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_B5280/D_803558C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_B5280/D_803558CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_B5280/D_803558D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_B5280/D_803558E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_B5280/D_803558F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_B5280/D_803558FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_B5280/D_80355908.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_B5280/D_80355914.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_B5280/D_80355920.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_B5280/D_8035592C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_B5280/D_80355938.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_B5280/D_80355944.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_B5280/D_80355950.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_B5280/D_8035595C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_B5280/D_80355968.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_B5280/D_80355974.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_B5280/D_80355980.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_B5280/D_8035598C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_B5280/D_80355998.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_B5280/D_803559A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_B5280/D_803559AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_B5280/D_803559B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_B5280/D_803559C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_B5280/D_803559D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_B5280/D_803559DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_B5280/D_803559E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_B5280/D_803559F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_B5280/D_80355A00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_B5280/D_80355A08.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_B5280/D_80355A14.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_B5280/D_80355A20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_B5280/D_80355A2C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_B5280/D_80355A38.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_B5280/D_80355A44.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_B5280/D_80355A50.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_B5280/D_80355A5C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_B5280/D_80355A68.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_B5280/D_80355A70.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_B5280/D_80355A7C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_B5280/D_80355A88.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_B5280/D_80355A94.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_B5280/D_80355AA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_B5280/D_80355AAC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_B5280/D_80355AB8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_B5280/D_80355AC4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_B5280/D_80355AD0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_B5280/D_80355ADC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_B5280/D_80355AE8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_B5280/D_80355AF4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_B5280/D_80355B00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_B5280/D_80355B0C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_B5280/D_80355B18.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_B5280/D_80355B24.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_B5280/D_80355B30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_B5280/D_80355B3C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_B5280/D_80355B48.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_B5280/D_80355B54.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_B5280/D_80355B60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_B5280/D_80355B6C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_B5280/D_80355B78.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_B5280/D_80355B84.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_B5280/D_80355B90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_B5280/D_80355B9C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_B5280/D_80355BA8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_B5280/D_80355BB4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_B5280/D_80355BC0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_B5280/D_80355BCC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_B5280/D_80355BD8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_B5280/D_80355BE4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_B5280/D_80355BF0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_B5280/D_80355BFC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_B5280/D_80355C08.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_B5280/D_80355C14.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_B5280/D_80355C20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_B5280/D_80355C2C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_B5280/func_8032E060.s")

void func_8032E698(void) {
    func_80312FF8(7);
}

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_B5280/func_8032E6B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_B5280/func_8032E940.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_B5280/func_8032EF10.s")
