#include "common.h"
#include <uv_font.h>
#include <uv_geometry.h>
#include <uv_graphics.h>
#include <uv_level.h>
#include <uv_sprite.h>
#include <uv_string.h>
#include "code_66160.h"
#include "code_72B70.h"
#include "code_9A960.h"
#include "code_B2900.h"
#include "code_CFC40.h"
#include "map3d.h"
#include "snd.h"
#include "text_data.h"

extern s32 D_803509B4;
extern const char* gClassShortName[4]; // gClassShortName
extern char D_8037DC88[];
extern u16 D_8037DC8C;
extern s16 D_8037DC8E;
extern s16* D_8037DC90;
extern s16* D_8037DC94;
extern char D_8037DC98[];
extern u8 D_8037DC9B;

extern u8 D_8034F420[][4];
extern u8 D_8034F43C[];
extern s32 D_80350974;
extern s8 D_80350978;
extern s8 D_8035097C;
extern u8 D_80350984;
extern s32 D_803509B8;
extern f32 D_8037DC60;
extern f32 D_8037DC64;
extern s32 D_8037DC68;
extern s32 D_8037DC6C;

s32 func_80348710(void) {
    Unk80362690_Unk0_UnkC* unkC;

    unkC = &D_80362690->unk0[D_80362690->unk9C].unkC;
    if ((unkC->veh == VEHICLE_HANG_GLIDER) &&
        (((unkC->cls == CLASS_A) && (D_803509B4 == 0)) || ((unkC->cls == CLASS_B) && (D_803509B4 == 1)) || ((unkC->cls == CLASS_PILOT) && (D_803509B4 == 2)))) {
        return TRUE;
    }
    return FALSE;
}

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_CFC40/D_80356F70.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_CFC40/D_80356F74.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_CFC40/D_80356F78.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_CFC40/D_80356F7C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_CFC40/D_80356F80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_CFC40/D_80356F84.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_CFC40/D_80356F88.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_CFC40/D_80356F8C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_CFC40/D_80356F90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_CFC40/D_80356F94.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_CFC40/D_80356F98.s")

void func_803487A4(s32 arg0) {
    Unk80362690_Unk0_UnkC* unkC;
    s32 width;
    s32 temp_v0;
    s32 test;
    s32 var_s1;
    s32 var_s3;
    char sp54[20];
    char sp40[20];

    var_s3 = 0;
    unkC = &D_80362690->unk0[D_80362690->unk9C].unkC;
    if (unkC->veh <= VEHICLE_GYROCOPTER) {
        var_s1 = func_8032BE1C(&D_80364210[D_80362690->unk9C], unkC->cls, arg0, unkC->veh);
    } else {
        var_s1 = 0;
        if (unkC->veh >= VEHICLE_SKY_DIVING) {
            var_s1 = func_8032BE1C(&D_80364210[D_80362690->unk9C], arg0, 0, unkC->veh);
        } else {
            var_s1 = 0;
            for (test = 0; test < levelGetTestCount(unkC->cls, unkC->veh); test++) {
                temp_v0 = func_8032BE1C(&D_80364210[D_80362690->unk9C], unkC->cls, test, unkC->veh);
                if (temp_v0 != 0x7F) {
                    var_s1 += temp_v0;
                    var_s3 = 1;
                }
            }
            if (var_s3 == 0) {
                var_s1 = 0x7F;
            }
        }
    }

    if (var_s1 != 0x7F) {
        uvFontSet(3);
        uvFont_80219550(1.0, 1.0);
        uvSprintf(D_8037DC88, "%d", var_s1);
        D_8037DC8C = uvFontWidth(D_8037DC88);
        uvFont_80219550(0.699999988079071045, 1.0);
        width = uvFontWidth("PTS");
        D_8037DC8E = 258 - (width + D_8037DC8C) / 2;
        D_8037DC9B = 1;
    } else {
        D_8037DC9B = 0;
    }

    if ((unkC->veh == VEHICLE_BIRDMAN) || (unkC->veh <= VEHICLE_GYROCOPTER)) {
        uvSprintf(sp54, "%s_%s_%d_N", gClassShortName[unkC->cls], gVehShortNames[unkC->veh], arg0 + 1);
        uvSprintf(sp40, "%s_%s_%d_H", gClassShortName[unkC->cls], gVehShortNames[unkC->veh], arg0 + 1);
    } else {
        uvSprintf(sp54, "%s_%s_%d_N", gClassShortName[unkC->veh - 2], gVehShortNames[unkC->veh], arg0 + 1);
        uvSprintf(sp40, "%s_%s_%d_H", gClassShortName[unkC->veh - 2], gVehShortNames[unkC->veh], arg0 + 1);
    }
    D_8037DC90 = textGetDataByName(sp54);
    D_8037DC94 = textGetDataByName(sp40);
    if ((unkC->veh <= VEHICLE_GYROCOPTER) || (unkC->veh == VEHICLE_BIRDMAN)) {
        uvSprintf(D_8037DC98, "%d", arg0 + 1);
    } else {
        uvSprintf(D_8037DC98, "%d", 1);
    }
}

void func_80348B84(Unk80367710* arg0, s32 arg1) {
    Unk80362690_Unk0_UnkC* temp_v1;

    temp_v1 = &D_80362690->unk0[D_80362690->unk9C].unkC;
    if (arg1 != 2) {
        uvLevelInit();
        uvLevelAppend((s32)D_8034F43C[D_8034F420[temp_v1->veh][temp_v1->cls]]);
        uvLevelAppend(0xB);
        uvLevelAppend(0x5B);
        uvLevelAppend(0x87);
        uvLevelAppend(0x53);
        textLoadBlock(0x42);
    }

    D_803509B8 = 0;
    if (arg1 == 0) {
        if (D_80362690->unkA3 == 0) {
            D_803509B4 = 0;
            D_80362690->unkA3 = 1;
        } else {
            D_803509B4++;
            if (D_803509B4 >= arg0->unk0) {
                D_803509B4 = 0;
            }
        }
        if ((temp_v1->veh != 6) && (temp_v1->veh >= 3)) {
            D_803509B4 = temp_v1->cls;
        }
        if ((temp_v1->veh != 6) && (temp_v1->veh >= 3)) {
            temp_v1->cls = D_803509B4;
            temp_v1->test = 0;
        } else {
            temp_v1->test = D_803509B4;
        }
    }
    level_80344FC8(temp_v1->cls, temp_v1->veh, temp_v1->test, &D_80362690->unk0[0].map, &D_80362690->unk0[0].unk6, &D_80362690->unk0[0].unk8);
    map3d(D_80362690, 0);
    if (arg1 == 0) {
        D_80350974 = 0;
    }
    uvSprtProps(0, 3, 1, 1, 0x40, 0x12, 9, 0xF, 7, 0xFF, 0xFF, 0xFF, 0xFF, 2, 0x32, 0x2E, 0);
    uvSprtProps(1, 3, 1, 1, 0x40, 0x12, 2, 0x32, 0x47, 7, 0xFF, 0xFF, 0xFF, 0xFF, 9, 0xE, 0);
    uvSprtProps(2, 3, 1, 1, 0x40, 0x12, 2, 0x80, 0x2E, 7, 0xFF, 0xFF, 0xFF, 0xFF, 9, 0x11, 0);
    uvSprtProps(3, 3, 1, 1, 0x40, 0x12, 2, 0x80, 0x47, 7, 0xFF, 0xFF, 0xFF, 0xFF, 9, 0x10, 0);
    uvSprtProps(4, 3, 1, 1, 0x40, 0x12, 7, 0xFF, 0xFF, 0xFF, 0xFF, 2, 0xCE, 0x2E, 9, 0x13, 0);
    uvSprtProps(5, 3, 1, 1, 0x40, 0x12, 2, 0xCE, 0x47, 7, 0xFF, 0xFF, 0xFF, 0xFF, 9, 0x12, 0);
    uvSprtProps(6, 3, 1, 2, 0x2B, 0xD4, 7, 0xFF, 0xFF, 0xFF, 0xFF, 9, 0x15, 0);
    uvSprtProps(7, 3, 1, 2, 0xEF, 0xD7, 7, 0xFF, 0xFF, 0xFF, 0xFF, 9, 0xD, 0);
    uvSprtProps(8, 3, 1, 1, 0x40, 0x12, 2, 0xCE, 0x47, 7, 0xFF, 0xFF, 0xFF, 0xFF, 9, 0x14, 0);
    uvSprtProps(9, 3, 1, 1, 0x40, 0x12, 2, 0x80, 0x47, 7, 0xFF, 0xFF, 0xFF, 0xFF, 9, 0x3C, 0);
    if (arg1 == 0) {
        D_80350978 = 0;
        D_8035097C = 1;
        D_8037DC60 = (f32)((D_80350978 * 78) + 47);
        D_8037DC64 = (f32)((D_8035097C * 25) + 26);
        D_8037DC68 = D_8037DC6C = 0;
        D_80350984 = 0xFF;
    }
    D_8037DC9B = 0;
    func_803487A4(D_803509B4);
}

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_CFC40/func_8034926C.s")

void func_80349C38(s32 arg0, u8 arg1, u8 arg2) {
    s32 pad1;
    s32 pad21;
    s32 var_s0;
    s32 idx;
    char* temp_v0_2;
    u32 pad2;
    u32 var_v1;
    s32 pad3;
    char sp8C[108];
    char sp58[52];
    s16* sp54;
    s32 temp_a0;
    s32 temp_v0_3;
    Unk80362690_Unk0_UnkC* sp48;
    s32 var_a1;

    sp48 = &D_80362690->unk0[D_80362690->unk9C].unkC;
    if ((sp48->veh != VEHICLE_BIRDMAN) && (arg2 >= 3)) {
        level_80344E0C(arg1, 0, arg2, sp8C, sp58);
    } else {
        level_80344E0C(arg1, D_803509B4, arg2, sp8C, sp58);
    }
    var_v1 = uvStrlen(sp58);
    if (var_v1 == 0) {
        uvSprintf(sp58, "%s_%s_%d\n", gClassShortName[sp48->cls], gVehShortNames[sp48->veh], D_803509B4 + 1);
        var_v1 = uvStrlen(sp58);
    }
    temp_v0_2 = &sp58[var_v1];
    temp_v0_2[0] = '_';
    temp_v0_2[1] = 'M';
    temp_v0_2[2] = '\0';
    temp_a0 = arg0 + 264;
    func_8033F6F8(temp_a0, temp_a0);
    func_80311C68(D_80362690, 0);
    if (D_80350974 != 1) {
        if (D_80350974 != 2) {
            sp54 = textGetDataByName(sp58);
        } else {
            sp54 = D_8037DC94;
        }
        screenDrawBox2(38, 80, 244, 110, 2, 0, 0xA0, 0);
        screenDrawBox2(38, 195, 191, 25, 2, 0, 0xA0, 0);
        if (sp48->veh != VEHICLE_BIRDMAN) {
            screenDrawBox2(235, 195, 48, 25, 2, 0, 0xA0, 0);
        }
        func_80314154();

        if (D_80350974 == 2) {
            if ((sp48->cls == CLASS_BEGINNER) && (sp48->veh <= VEHICLE_GYROCOPTER)) {
                uvSprtDraw(9);
            }
            uvSprtDraw(6);
            if (sp48->veh != VEHICLE_BIRDMAN) {
                uvSprtDraw(7);
            }
            uvSprtDraw(8);
        } else {
            for (var_s0 = 0; var_s0 < 8; var_s0++) {
                if ((var_s0 == 4) && (func_80348710() != 0)) {
                    uvSprtDraw(4);
                } else if ((var_s0 == 7) && (sp48->veh != VEHICLE_BIRDMAN)) {
                    uvSprtDraw(7);
                } else if ((var_s0 != 4) && (var_s0 != 7)) {
                    uvSprtDraw(var_s0);
                }
            }

            if (((sp48->veh == VEHICLE_BIRDMAN) || (sp48->veh <= VEHICLE_GYROCOPTER)) && (levelGetTestCount(sp48->cls, sp48->veh) >= 2)) {
                uvGfxStatePush();
                uvGfxSetFlags(GFX_STATE_800000);
                uvGfxClearFlags(GFX_STATE_400000 | GFX_STATE_200000);
                uvGfx_80223A28(0x11B);
                uvVtxBeginPoly();
                uvVtx(31, 142, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF);
                uvVtx(31, 127, 0, 0, 0x1E0, 0xFF, 0xFF, 0xFF, 0xFF);
                uvVtx(46, 127, 0, 0x1E0, 0x1E0, 0xFF, 0xFF, 0xFF, 0xFF);
                uvVtx(46, 142, 0, 0x1E0, 0, 0xFF, 0xFF, 0xFF, 0xFF);
                uvVtxEndPoly();
                uvVtxBeginPoly();
                uvVtx(273, 142, 0, 0x1E0, 0, 0xFF, 0xFF, 0xFF, 0xFF);
                uvVtx(273, 127, 0, 0x1E0, 0x1E0, 0xFF, 0xFF, 0xFF, 0xFF);
                uvVtx(288, 127, 0, 0, 0x1E0, 0xFF, 0xFF, 0xFF, 0xFF);
                uvVtx(288, 142, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF);
                uvVtxEndPoly();
                uvGfxStatePop();
            }
        }
        func_802DEE44((s32)((f64)D_8037DC60 + 0.5), (s32)((f64)D_8037DC64 + 0.5), 0x46, 0x18, 3, 0xC8, 0xC8, 0, 0x64, 0x64, 0);
        func_803141E4();
        uvFontSet(0);
        uvFont_80219550(1.0, 0.800000011920929);
        uvFont_8021956C(0xBE, 0xBE, 0xBE, 0xFF);
        uvFont_80219ACC(67, 200, D_8037DC98);
        if (D_8037DC90 != NULL) {
            uvFontSet(6);
            uvFont_8021956C(0xBE, 0xBE, 0xBE, 0xFF);
            uvFont_80219550(1.0, 1.0);
            func_80219874(79, 196, D_8037DC90, 0xFF, 0xFFE);
        }
        if ((D_8037DC9B != 0) && (sp48->veh != VEHICLE_BIRDMAN)) {
            uvFontSet(3);
            uvFont_8021956C(0xBE, 0xBE, 0xBE, 0xFF);
            uvFont_80219550(1.0, 1.0);
            uvFont_80219ACC((s32)(u16)D_8037DC8E, 0xC4, D_8037DC88);
            uvFont_8021956C(0xAA, 0xAA, 0xAA, 0xFF);
            uvFont_80219550(0.699999988079071, 1.0);
            uvFont_80219ACC((u16)D_8037DC8E + D_8037DC8C + 1, 0xC4, "PTS");
        }
        if (sp54 != NULL) {
            uvFontSet(6);
            uvFont_8021956C(0xD2, 0xD2, 0xD2, 0xFF);
            uvFont_80219550(1.0, 1.0);
            idx = 0;
            for (var_a1 = 166; var_a1 > -114; var_a1 -= 14) {
                temp_v0_3 = func_80219874(46, var_a1, &sp54[idx], 0xFF, 0xFFE);
                if (temp_v0_3 == -1) {
                    break;
                }
                idx += temp_v0_3;
            }
        }
        uvFont_80219EA8();
    }
}

void func_8034A428(void) {
    func_803122B4(D_80362690, 0);
}
