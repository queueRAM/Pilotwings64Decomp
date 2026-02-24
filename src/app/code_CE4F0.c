#include "common.h"
#include <uv_geometry.h>
#include <uv_graphics.h>
#include "code_99D40.h"
#include "code_9A960.h"
#include "code_B2900.h"
#include "code_CE4F0.h"
#include "menu.h"
#include "save.h"
#include "text_data.h"

typedef struct {
    char* unk0[5];
} Unk803508E0;

extern Unk803508E0 D_803508E0[];
extern char* D_80350930[];
extern s32 D_80350944;
extern s32 D_80350948[];
extern s32 D_80350954;
extern s16* D_80350958[4];
extern u16 D_80359AAA;
extern u16 D_80359AAE;

extern s16* D_8037AD1C;
extern s32 D_8037AD20;
extern s16 D_8037AD28[];
extern s16* D_8037AD34;
extern s16 D_8037AD38[];
extern u8 D_8037AD42;
extern s16* D_8037AD48[];
extern char D_8037AD58[];

// forward declarations
void func_80347270(void);
void func_8034754C(void);
void func_80347694(void);
s32 func_8034769C(void);
void func_80347780(void);

u8 func_80346FC0(Unk80362690_Unk0_UnkC* arg0) {
    s32 sp2C;
    s32 sp28;
    s32 sp24;
    s32 temp_v0;
    u16 veh;

    veh = arg0->veh;
    if (veh == 3) {
        sp28 = func_8032C174(&sp2C, D_80359AAE, 4);
        temp_v0 = func_8032C174(&sp24, D_80359AAA, 4);
        if ((sp28 < temp_v0) || ((sp28 == 3) && (temp_v0 == 3) && (sp24 == 0))) {
            return TRUE;
        }
        return FALSE;
    }
    return D_80364210[D_80362690->unk9C].unk0[arg0->cls].unk0[arg0->test][veh + 1].result.unk0 == 4;
}

s32 func_803470EC(void) {
    s32 sp1C;

    func_80347270();
    while (!(sp1C = func_8034769C())) {
        uvGfxBegin();
        func_80347780();
        uvGfxEnd();
    }
    func_80347694();
    return sp1C;
}

s32 func_80347150(s32 arg0) {
    Unk80362690_Unk0_UnkC* unkC;

    unkC = &D_80362690->unk0[D_80362690->unk9C].unkC;
    if (arg0 < 0) {
        return arg0;
    }
    if (func_80346FC0(&D_80362690->unk0[D_80362690->unk9C].unkC)) {
        return 6;
    }
    if (unkC->veh < 3) {      // HG/RP/GC
        if (unkC->cls == 0) { // Beginner
            switch (arg0) {
            case 0:
                return 3;
            case 1:
                return 5;
            }
        } else {
            switch (arg0) {
            case 0:
                return 3;
            case 1:
                return 4;
            case 2:
                return 5;
            }
        }
    } else { // bonus veh: CB/SD/JH/BD
        switch (arg0) {
        case 0:
            return 3;
        case 1:
            return 5;
        }
    }
    return -1;
}

void func_80347270(void) {
    Unk80362690_Unk0_UnkC* temp_s4;
    s32 temp_v0;
    s32 var_a0;
    s32 var_s5;
    char* var_a1;
    char* var_v0_2;
    s32 var_v1;
    s32 sp50;
    Unk80364210* sp4C;
    u8 temp_t5;
    u8* var_v1_3;
    s32 i;

    temp_s4 = &D_80362690->unk0[D_80362690->unk9C].unkC;
    var_s5 = 0;
    sp4C = &D_80364210[D_80362690->unk9C];
    D_8037AD20 = 0;

    for (i = 0; i < ARRAY_COUNT(D_80350958); i++) {
        D_80350958[i][0] = D_80350958[i][1] = D_80350958[i][2] = -3;
        D_80350958[i][3] = 0xFFE;
        D_80350958[i][4] = -1;
    }

    for (i = 0; i < levelGetTestCount(temp_s4->cls, temp_s4->veh); i++) {
        temp_v0 = func_8032BE1C(sp4C, temp_s4->cls, i, temp_s4->veh); // was unk5, , unk3
        if (temp_v0 != 127) {
            var_s5 += temp_v0;
            textFmtInt(D_80350958[i], temp_v0, 3);
        }
        var_a0 = (temp_v0 == 1) ? 0x8A : 0x131; // "pt." : "pts."
        D_8037AD48[i] = textGetDataByIdx(var_a0);
    }

    if (temp_s4->veh < 3) {
        var_v1 = temp_s4->cls;
    } else {
        var_v1 = temp_s4->veh + 1;
    }
    D_8037AD42 = func_8032C174(&sp50, var_s5, var_v1);
    textFmtInt(D_8037AD28, var_s5, 3);
    var_a0 = (var_s5 == 1) ? 0x8A : 0x131; // "pt." : "pts."
    D_8037AD34 = textGetDataByIdx(var_a0);
    textFmtInt(D_8037AD38, sp50, 3);
    var_v1 = D_8037AD42;
    if ((var_v1 == 3) && (sp50 == 0)) {
        var_v1 = D_8037AD42 = 4;
    }
    if (temp_s4->veh < 3) {
        var_a1 = D_803508E0[temp_s4->cls].unk0[var_v1];
    } else {
        var_a1 = D_80350930[var_v1];
    }
    if (var_a1 != NULL) {
        for (i = 0; var_a1[i] != '\0'; i++) {
            D_8037AD58[i] = var_a1[i];
        }
    }
    D_8037AD1C = textGetDataByName(var_a1);
    func_8034754C();
}

void func_8034754C(void) {
    Unk80362690_Unk0_UnkC* temp_a0;

    if (func_80346FC0(&D_80362690->unk0[D_80362690->unk9C].unkC)) {
        menuCreateItems(170, 2, 6, 1.0f, 1.0f, &D_80350944, 1);
        return;
    }
    temp_a0 = &D_80362690->unk0[D_80362690->unk9C].unkC;

    D_80350954 = 0;
    D_80350948[D_80350954++] = 0x189; // Retry
    if ((temp_a0->veh < 3) && (temp_a0->cls != 0)) {
        D_80350948[D_80350954++] = 0x166; // Another test
    }
    D_80350948[D_80350954++] = 0x1D; // Quit
    menuCreateItems(170, 2, 6, 1.0f, 1.0f, D_80350948, D_80350954);
}

void func_80347694(void) {
}

s32 func_8034769C(void) {
    Unk80362690_Unk0_UnkC* sp1C;
    s32 temp_v0;

    sp1C = &D_80362690->unk0[D_80362690->unk9C].unkC;
    if (func_80347150(menu_8030B668()) == 3) {
        func_80312FF8(4);
    } else {
        func_80312FF8(5);
    }
    temp_v0 = func_80347150(menu_8030B50C());
    switch (temp_v0) {
    case 3:
        return 4;
    case 4:
        return 2;
    case 5:
        return 0xB;
    case 6:
        if (func_80346FC0(sp1C)) {
            return 0xE;
        }
    default:
        return 0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_CE4F0/D_80356D20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_CE4F0/D_80356D2C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_CE4F0/D_80356D38.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_CE4F0/D_80356D44.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_CE4F0/D_80356D54.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_CE4F0/D_80356D60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_CE4F0/D_80356D6C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_CE4F0/D_80356D78.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_CE4F0/D_80356D84.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_CE4F0/D_80356D94.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_CE4F0/D_80356DA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_CE4F0/D_80356DAC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_CE4F0/D_80356DB8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_CE4F0/D_80356DC4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_CE4F0/D_80356DD4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_CE4F0/D_80356DE0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_CE4F0/D_80356DEC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_CE4F0/D_80356DF8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_CE4F0/D_80356E04.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_CE4F0/D_80356E14.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_CE4F0/D_80356E20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_CE4F0/D_80356E30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_CE4F0/D_80356E40.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_CE4F0/D_80356E50.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_CE4F0/D_80356E64.s")

#ifndef NON_MATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/app/code_CE4F0/func_80347780.s")
#else
// draws overall test summary screen after objectives breakdown. e.g.:
// Test 1     100 pts
// Test 2     100 pts
// ------------------
// Total      200 pts
void func_80347780(void) {
    Unk80362690_Unk0_UnkC* sp6C;
    s32 pad;
    s32 pad2;
    s32 y;
    s32 var_s2;
    s32 i;
    s32 temp_v0;

    var_s2 = 0;
    sp6C = &D_80362690->unk0[D_80362690->unk9C].unkC;
    func_80204FC4(sp6C->unk70->unk22C);
    func_80314154();

    uvVtxBeginPoly();
    uvVtx(0, 240, 0, 0, 0, 0x00, 0x00, 0x00, 0x78);
    uvVtx(0, 0, 0, 0, 0, 0x00, 0x00, 0x00, 0x78);
    uvVtx(320, 0, 0, 0, 0, 0x00, 0x00, 0x00, 0x78);
    uvVtx(320, 240, 0, 0, 0, 0x00, 0x00, 0x00, 0x78);
    uvVtxEndPoly();

    uvGfxClearFlags(0x400000);
    uvVtxBeginPoly();
    uvVtx(34, 120, 0, 0, 0, 0xD2, 0xD2, 0xD2, 0xFF);
    uvVtx(34, 119, 0, 0, 0, 0xD2, 0xD2, 0xD2, 0xFF);
    uvVtx(272, 119, 0, 0, 0, 0xD2, 0xD2, 0xD2, 0xFF);
    uvVtx(272, 120, 0, 0, 0, 0xD2, 0xD2, 0xD2, 0xFF);
    uvVtxEndPoly();

    func_803141E4();
    uvFontSet(6);
    uvFont_8021956C(0xD2, 0xD2, 0xD2, 0xFF);
    uvFont_80219550(1.0, 1.0);

    y = 180;
    if (D_8037AD1C != NULL) {
        do {
            var_s2 += func_80219874(28, y, &D_8037AD1C[var_s2], 0xFF, 0xFFE);
            y -= 16;
        } while (D_8037AD1C[var_s2] != -1);
    } else {
        _uvDebugPrintf("Missing or bad kanji string in level total, %s\n", D_8037AD58);
    }

    if (sp6C->veh == 3) { // cannonball
        func_80219874(202, 116, D_8037AD28, 3, 0xFFE);
        func_80219874(236, 116, D_8037AD34, 4, 0xFFE);
    } else {
        temp_v0 = levelGetTestCount(sp6C->cls, sp6C->veh);

        for (i = 0; i < temp_v0; i++) {
            y = (temp_v0 * 16) + 100 - 16 * i;
            func_80219874(202, y, D_80350958[i], 3, 0xFFE);
            func_80219874(236, y, D_8037AD48[i], 4, 0xFFE);
        }
    }

    if ((temp_v0 != 1) && (sp6C->veh != 3)) {
        func_80219874(202, 100, D_8037AD28, 3, 0xFFE);
        func_80219874(236, 100, D_8037AD34, 4, 0xFFE);
    }
    if (D_8037AD42 != 4) {
        func_80219874(128, 68, D_8037AD38, 3, 0xFFE);
    }
    menuInit();
    uvFont_80219EA8();
}
#endif
