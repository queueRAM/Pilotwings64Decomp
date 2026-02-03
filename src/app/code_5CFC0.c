#include "common.h"

#include <uv_controller.h>
#include <uv_dobj.h>
#include <uv_math.h>
#include <uv_matrix.h>
#include <uv_memory.h>
#include "cbsound.h"
#include "code_5A6A0.h"
#include "code_60020.h"

// TODO: context things

typedef struct {
    u8 unk0;
    u8 unk1;
    u8 pad2[2];
    u16 unk4;
    u8 unk6;
    u8 pad7;
    f32 unk8;
    u8 padC[0x14 - 0xC];
    f32 unk14;
    u8 pad18[0x40 - 0x18];
    f32 unk40;
    u8 pad44[4];
    f32 unk48;
    f32 unk4C;
    f32 unk50;
    f32 unk54;
    f32 unk58;
    f32 unk5C;
    f32 unk60;
    f32 unk64;
    f32 unk68;
    f32 unk6C;
    f32 unk70;
    f32 unk74;
    f32 unk78;
    f32 unk7C;
    Mtx4F unk80;
    u8 padC0[0x108 - 0xC0];
    Mtx4F unk108;
    u8 pad148[0x204 - 0x148];
    f32 unk204;
    f32 unk208;
    f32 unk20C;
    u8 pad210[0x228 - 0x210];
    f32 unk228;
    s32 pad22C;
    f32 unk230;        // Unk802D3658_Unk230*
} Unk802D5C5C_Arg0_B0; // possibly Unk802D3658_Arg0

typedef struct {
    u16 unk0;
    u8 unk2;
    u8 pad3;
    s32 pad4;
    f32 unk8;
    u16 unkC;
    u16 unkE;
    u16 unk10;
    u16 pad12;
    Mtx4F unk14;
    u16 unk54;
    u8 unk56;
    u8 pad57;
    Mtx4F unk58;
    f32 unk98;
    f32 unk9C;
    f32 unkA0;
    f32 unkA4;
    u8 padA8[0xB0 - 0xA8];
    Unk802D5C5C_Arg0_B0* unkB0;
    u8 unkB4;
    u8 padB5[3];
    f32 unkB8;
    f32 unkBC;
    f32 unkC0;
    u8 unkC4;
    u8 padC5[3];
    f32 unkC8;
    f32 unkCC;
    f32 unkD0;
    u8 unkD4;
    u8 padD5[0x11D - 0xD5];
    s8 unk11D;
    f32 unk120;
    u8 pad124[0x1B8 - 0x124];
    s32 unk1B8;
    u8 pad1BC[0x1C4 - 0x1BC];
    f32 unk1C4;
    f32 unk1C8;
    f32 unk1CC;
    f32 unk1D0;
    u8 pad1D4[0x220 - 0x1D4];
    u16 unk220;
    u8 pad222[0x4A];
    f32 unk26C;
    f32 unk270;
    f32 unk274;
    u8 pad278[0x1B];
    u8 unk293;
} Unk802D5C5C_Arg0;

typedef struct {
    u16 unk0;
    s16 pad2;
    s32 pad4;
    s8 unk8;
    s8 pad9[0xC - 9];
    s32 padC;
    f32 unk10;
    s32 pad14;
    f32 unk18;
    s32 pad1C;
    f32 unk20;
    f32 unk24;
    Mtx4F unk28;
    u8 pad68[0x70 - 0x68];
    f32 unk70;
    u8 pad74[0x80 - 0x74];
    f32 unk80;
    f32 unk84;
    f32 unk88;
    f32 unk8C;
    u8 pad90[0xC6C - 0x90];
    f32 unkC6C;
    f32 unkC70;
    s8 unkC74;
} Unk80318294;

void func_802D45C4(void*, f32); // TODO: arg0 type mismatch with other callers
void db_getstart(Mtx4F*, void*, s32, s32);
void func_802D94EC(void*);
void func_80313570(Mtx4F*, f32*, f32*, f32*, f32*, f32*, f32*);
void uvModelGetProps(u16, s32, void*, s32);

s32 func_802E6B5C(void);
f32 func_803230B0(u16, s32);
s32 func_80323164(u16);
void func_802E65AC(Mtx4F*, s32, f32*, f32*, s32*);
void func_802E682C(f32*, s32, u8);
void func_802E6870(f32*, s32, u8*);
f32 func_80313F08(Unk803599D0*, f32);
void func_802D66C4(Unk802D5C5C_Arg0*);
void func_802D6CC4(Unk802D5C5C_Arg0*);
void func_802D8AF0(Unk802D5C5C_Arg0*);
void func_802D95D8(Unk802D5C5C_Arg0*);
f32 func_80313AF4(f32, f32, f32);
s32 func_803231E0(u16, s32);
void func_8033F758(u8, f32, f32, f32);
void func_802D5884(Unk802D3658_Arg0* arg0, u8 arg1);
Unk80318294* func_80318294(void);
void func_802EAC18(Unk802D3658_Unk230*, f32, Mtx4F*);

void func_8031D8E0(s32, s32, f32);
s32 func_803231A0(s32, s32);
void uvModelGetPosm(s32 model, s32 part, Mtx4F*);

extern f32 D_8034E9F0;
extern u8 D_8034E9F4;
extern s32 D_8034E9F8;
extern f32 D_8034F854; // = 0.1f in .data
extern s32 D_80362690;
extern f32 D_8034F850;
extern u8 D_80359A84;

typedef struct {
    u16 unk0;
    u8 unk2;
    u8 pad3;
    u16 unk4;
    u8 pad6[0xA];
    u16 unk10;
    u8 pad12[2];
    s32 unk14;
    u8 pad18[0x3C];
    u16 unk54;
    u8 unk56;
    u8 pad57;
    s32 unk58;
    u8 pad5C[0x48];
    f32 unkA4;
    u8 padA8[8];
    Unk802D5C5C_Arg0_B0* unkB0;
    u8 padB4[0x16C];
    s16 unk220;
    u8 pad222[2];
    f32 unk224;
    f32 unk228;
    f32 unk22C;
    f32 unk230;
    f32 unk234;
    f32 unk238;
    f32 unk23C;
    f32 unk240;
    f32 unk244;
    f32 unk248;
    f32 unk24C;
    f32 unk250;
    f32 unk254;
    f32 unk258;
    f32 unk25C;
    f32 unk260;
    f32 unk264;
    f32 unk268;
    f32 unk26C;
    f32 unk270;
    f32 unk274;
    f32 unk278;
    f32 unk27C;
    f32 unk280;
    u8 unk284;
    u8 unk285;
    u8 unk286;
    u8 unk287;
    u8 unk288;
    u8 unk289;
    u8 unk28A;
    u8 unk28B;
    u8 unk28C;
    u8 unk28D;
    u8 unk28E;
    u8 pad28F[2];
    u8 unk291;
    u8 unk292;
    u8 unk293;
    u8 pad294[0x2BC - 0x294];
} Unk802D5B50_Arg2;

typedef struct {
    u8 pad0[0x40];
    f32 unk40;
} Unk802D5B50_Arg3;

// .bss likely owned by this file
extern Unk803599D0 D_80359A30;

// forward declarations
void func_802D6F38(u8, Unk802D5B50_Arg2*);
void func_802D5A90(void);
void func_802D6B7C(Unk802D5C5C_Arg0*);

void func_802D5A90(void) {
    D_80359A30.unk0 = 8;
    D_80359A30.unk4 = 0.0f;
    D_80359A30.unk8 = 0.0f;
    D_80359A30.unkC = 0.2f;
    D_80359A30.unk10 = 0.04f;
    D_80359A30.unk14 = 0.4f;
    D_80359A30.unk18 = 0.16f;
    D_80359A30.unk1C = 0.6f;
    D_80359A30.unk20 = 0.36f;
    D_80359A30.unk24 = 0.7f;
    D_80359A30.unk28 = 0.49f;
    D_80359A30.unk2C = 0.8f;
    D_80359A30.unk30 = 0.64f;
    D_80359A30.unk34 = 0.9f;
    D_80359A30.unk38 = 0.81f;
    D_80359A30.unk40 = 1.0f;
    D_80359A30.unk3C = 1.0f;
}

// func_802D5B50 is invoked when loading cannonball level
void func_802D5B50(u8 arg0, u8 pilot, Unk802D5B50_Arg2* arg2, Unk802D5C5C_Arg0_B0* arg3) {
    uvMemSet(arg2, 0, sizeof(*arg2));
    func_802D6F38(pilot, arg2);
    arg2->unk0 = func_8021731C();
    arg2->unk2 = 2;
    uvDobjModel(arg2->unk0, arg2->unk220);
    uvDobjPosm(arg2->unk0, 0, &arg2->unk14);
    uvDobjState(arg2->unk0, arg2->unk2);
    arg2->unk54 = func_8021731C();
    arg2->unk56 = 2;
    uvDobjModel(arg2->unk54, 0x105);
    uvDobjPosm(arg2->unk54, 0, &arg2->unk58);
    uvDobjState(arg2->unk54, arg2->unk56);
    arg2->unkB0 = arg3;
    arg3->unk40 += 100.0f;
    arg2->unk10 = arg0;
    arg2->unkA4 = 0.0f;
    arg2->unk293 = 0;
    arg2->unk4 = 2;
    func_802D9430(arg2);
    func_802D9CB0(arg2);
}

void func_802D5C5C(Unk802D5C5C_Arg0* arg0) {
    f32 sp54;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
    f32 sp44;
    f32 sp40;

    if (arg0->unkE == 0) {
        db_getstart(&arg0->unk58, &arg0->unk1B8, 0, 0);
        uvDobjPosm(arg0->unk54, 0, &arg0->unk58);
        func_80313570(&arg0->unk58, &sp54, &sp50, &sp4C, &sp48, &sp44, &sp40);
        arg0->unk98 = sp48;
        arg0->unkA0 = 0.52359873f;
        arg0->unk9C = 0.0f;
    }
    uvMat4Copy(&arg0->unk14, &arg0->unk58);
    uvDobjPosm(arg0->unk0, 0, &arg0->unk14);
    func_802D94EC(arg0);
    arg0->unkCC = 0.0f;
    arg0->unkD0 = 0.0f;
    arg0->unkD4 = 0;
    arg0->unkC4 = 0;
    arg0->unkC8 = 0.0f;
    arg0->unk293 = 0;
    arg0->unk8 = 0.0f;
    arg0->unk2 = 2;
    arg0->unk56 = 2;
    uvDobjState(arg0->unk0, 2 & 0xFF);
    uvDobjState(arg0->unk54, arg0->unk56);
    arg0->unkB4 = 5;
    arg0->unkB8 = 1.0f;
    arg0->unkB0->unk1 = arg0->unkB4;
    arg0->unkB0->unk4 = arg0->unk54;
    arg0->unkB0->unk6 = arg0->unk56;
    arg0->unkB0->unk0 = 0x20;
    arg0->unkB0->unk68 = arg0->unk26C;
    arg0->unkB0->unk6C = arg0->unk270;
    arg0->unkB0->unk70 = arg0->unk274;
    arg0->unkB0->unk74 = 0.0f;
    arg0->unkB0->unk5C = 0;
    arg0->unkB0->unk60 = -1.0f;
    arg0->unkB0->unk64 = -2.0f;
    arg0->unkB0->unk54 = 2.0f;
    arg0->unkB0->unk58 = 6.0f;
    arg0->unkB0->unk48 = 0.06f;
    arg0->unkB0->unk4C = 1;
    arg0->unkB0->unk50 = 0.0f;
    arg0->unkB0->unk228 = 0.0f;
    uvModelGetProps(arg0->unk220, 1, &arg0->unkB0->unk8, 0);
    func_802D45C4(arg0->unkB0, arg0->unkB8);
    D_8034E9F0 = 4.712389f;
    D_8034E9F4 = 0;
    D_8034E9F8 = 0;
}

void func_802D5E98(Unk802D5B50_Arg2* arg0) {
    uvDobjModel(arg0->unk0, 0xFFFF);
    uvDobjModel(arg0->unk54, 0xFFFF);
    arg0->unk10 = 0xFFFF;
    arg0->unk0 = 0xFFFF;
    arg0->unk54 = 0xFFFF;
    arg0->unkB0->unk40 -= 100.0f;
}

void func_802D5F00(Unk802D5C5C_Arg0* arg0, u8 arg1) {
    f32 spEC;
    f32 spE8;
    s32 spE4;
    Unk802D5C5C_Arg0_B0* temp_v0;
    f32 var_fa0;
    f32 var_fa0_2;
    f32 var_fv0;
    f32 var_fv0_2;
    f32 spC8[2];
    u8 spC7;
    Unk80318294* spC0;
    s32 temp_t2;
    Mtx4F sp7C;
    Mtx4F sp3C;
    Mtx4F* sp2C;
    u16 temp_v0_3;
    u8 temp_t3;

    if (func_802E6B5C() != 4) {
        arg0->unk8 += D_8034F854;
        arg0->unk11D = 0;
        if (arg1 != 6) {
            spEC = func_803230B0(arg0->unk10, 0);
            spE8 = func_803230B0(arg0->unk10, 1);
            spE4 = func_80323164(arg0->unk10);
        }
        sp2C = &arg0->unk14;
        func_802E65AC(&arg0->unk14, D_80362690 + 6, &spEC, &spE8, &spE4);
        if (arg1 != 6) {
            spC8[0] = arg0->unk9C;
            spC8[1] = arg0->unkA0;
            spC7 = (arg0->unkD4 * 2) | (arg0->unkC4 & 1);
            func_802E682C(spC8, 2, spC7);
        } else {
            func_802E6870(spC8, 2, &spC7);
            arg0->unk9C = spC8[0];
            arg0->unkA0 = spC8[1];
            arg0->unkD4 = (u8)((s32)spC7 >> 1);
            arg0->unkC4 = spC7 & 1;
        }
        if (spEC > 0.0f) {
            var_fv0 = spEC;
        } else {
            var_fv0 = -spEC;
        }
        arg0->unkBC = func_80313F08(&D_80359A30, var_fv0);
        if (spEC < 0 /*.0f*/) {
            arg0->unkBC = (f32)-arg0->unkBC;
        }
        if (spE8 > 0.0f) {
            var_fv0_2 = spE8;
        } else {
            var_fv0_2 = -spE8;
        }
        arg0->unkC0 = func_80313F08(&D_80359A30, var_fv0_2);
        if (spE8 < 0.0f) {
            arg0->unkC0 = (f32)-arg0->unkC0;
        }
        if ((spE4 & 0x8000) && (D_8034F850 >= 2.0f)) {
            arg0->unkC4 = 1;
        }
        if ((arg0->unkC4 != 0) && (arg0->unkC8 == 0.0f)) {
            arg0->unkC8 = D_8034F850;
        }
        if (arg0->unkD4 == 0) {
            func_802D66C4(arg0);
        }
        if ((arg1 != 6) && (arg0->unkD4 == 1)) {
            func_802D95D8(arg0);
        }
        if (arg0->unkD4 == 2) {
            func_802D6CC4(arg0);
        }
        func_802D8AF0(arg0);
        uvDobjPosm(arg0->unk0, 0, sp2C);
        if (D_8034E9F4 != 0) {
            arg0->unkCC = 0.0f;
        } else {
            if (spE4 & 2) {
                var_fa0 = 1.5707963f;
            } else if (spE4 & 1) {
                var_fa0 = -1.5707963f;
            } else {
                var_fa0 = 0.0f;
            }
            arg0->unkCC = func_80313AF4(var_fa0, arg0->unkCC, 2.0f);
        }
        if (D_8034E9F4 != 0) {
            arg0->unkD0 = 0.0f;
        } else {
            if (spE4 & 4) {
                var_fa0_2 = 1.5707963f;
            } else if (spE4 & 8) {
                var_fa0_2 = -1.5707963f;
            } else {
                var_fa0_2 = 0.0f;
            }
            arg0->unkD0 = func_80313AF4(var_fa0_2, arg0->unkD0, 2.0f);
        }
        if (arg1 != 6) {
            if ((arg0->unkD4 == 0) || ((D_8034F850 - arg0->unkC8) < 0.5f)) {
                arg0->unkB4 = 5;
                arg0->unkB8 = 1.0f;
                if (func_803231E0(arg0->unk10, 0x10) != 0) {
                    func_8033F758(0x6A, 1.0f, 0.5f, 0);
                    // @fake
                    if (D_8034E9F4) { }
                    D_8034E9F4 = D_8034E9F4 == 0;
                }
                if (D_8034E9F4 == 0) {
                    uvMat4Copy(&sp7C, &arg0->unk58);
                    uvMat4RotateAxis(&sp7C, arg0->unk9C - arg0->unkCC, 'z');
                    uvMat4UnkOp2(&sp7C, 0.0f, -12.0f, 2.0f);
                    uvMat4RotateAxis(&sp7C, arg0->unkA0 * 0.3f, 'x');
                    uvMat4Copy(&arg0->unkB0->unk108, &sp7C);
                } else {
                    uvMat4Copy(&sp7C, &arg0->unk58);
                    uvMat4RotateAxis(&sp7C, arg0->unk9C, 'z');
                    uvMat4RotateAxis(&sp7C, arg0->unkA0, 'x');
                    uvMat4UnkOp2(&sp7C, 0.0f, 3.6000001f, 0.0f);
                    uvMat4Copy(&arg0->unkB0->unk108, &sp7C);
                }
                uvMat4Copy(&sp3C, sp2C);
                uvMat4UnkOp2(&sp3C, 0.0f, -4.0f, -1.0f);
                temp_v0 = arg0->unkB0;
                func_802EAC18((Unk802D3658_Unk230*)&temp_v0->unk230, temp_v0->unk14, &sp3C);
            } else {
                D_8034E9F4 = 0;
                if ((arg0->unkB4 == 5) && (arg0->unkD4 != 2)) {
                    arg0->unkB0->padC[1] = 0;
                    D_8034E9F8++;
                    if (D_8034E9F8 == 3) {
                        arg0->unkB4 = 0;
                    }
                }
                if (func_803231E0(arg0->unk10, 0x10) != 0) {
                    func_8033F758(0x6A, 1.0f, 0.5f, 0);
                    if (arg0->unkB4 == 0) {
                        arg0->unkB4 = 8;
                    } else {
                        arg0->unkB4 = 0;
                        arg0->unkB8 = 1.0f;
                    }
                }
            }
            arg0->unkB0->unk4 = arg0->unk0;
            arg0->unkB0->unk6 = arg0->unk2;
            arg0->unkB0->unk78 = arg0->unkCC;
            arg0->unkB0->unk7C = arg0->unkD0;
            arg0->unkB0->unk204 = arg0->unk1C4;
            arg0->unkB0->unk208 = arg0->unk1C8;
            arg0->unkB0->unk20C = arg0->unk1CC;
            arg0->unkB0->unk228 = arg0->unk120;
            uvMat4Copy(&arg0->unkB0->unk80, sp2C);
            func_802D5884((Unk802D3658_Arg0*)arg0->unkB0, arg0->unkB4);
            func_802D45C4((Unk802D3658_Arg0*)arg0->unkB0, arg0->unkB8);
        }
        if (arg1 != 6) {
            spC0 = func_80318294();
            if (arg0->unkD4 == 0) {
                uvMat4Copy(&spC0->unk28, &arg0->unk58);
                uvMat4RotateAxis(&spC0->unk28, arg0->unk9C, 'z');
            } else {
                uvMat4Copy(&spC0->unk28, sp2C);
            }
            if ((arg0->unkB4 != 8) && (arg0->unkD4 != 2)) {
                spC0->unk0 = 0x10;
            } else {
                spC0->unk0 = 0;
            }
            spC0->unk70 = arg0->unk14.m[3][2];
            spC0->unk10 = arg0->unk8;
            spC0->unk18 = arg0->unkA4;
            spC0->unk8C = (arg0->unk1CC * 4.0f * 0.7f);
            spC0->unk80 = (arg0->unk120 * 0.7f);
            spC0->unk84 = (arg0->unk14.m[3][2] * 0.7f);
            spC0->unk88 = (arg0->unk1D0 * 3.6f * 0.7f);
            spC0->unk20 = (arg0->unk98 + arg0->unk9C);
            spC0->unk24 = arg0->unkA0;
            spC0->unk8 = (s8)(3 - arg0->unkE);
            if (D_8034E9F4 != 0) {
                spC0->unk0 = (u16)(spC0->unk0 | 0x200);
            } else {
                temp_v0_3 = spC0->unk0;
                if (temp_v0_3 & 0x200) {
                    spC0->unk0 = (u16)(temp_v0_3 & 0xFDFF);
                }
            }
            spC0->unkC70 = 0.0f;
            spC0->unkC6C = 0.0f;
            spC0->unkC74 = 0;
        }
    }
}

#ifndef NON_MATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/app/code_5CFC0/func_802D66C4.s")
#else
// func_802D66C4 does not initialize sp34
#if defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wsometimes-uninitialized"
#elif defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmaybe-uninitialized"
#endif
// func_802D66C4 called every frame while inside cannon
// controls the rate of rotation and Z-button presses
void func_802D66C4(Unk802D5C5C_Arg0* arg0) {
    Mtx4F sp38;
    f32 sp34;
    f32 var_fa0;

    if (D_8034F850 >= 2.0f) {
        D_8034E9F0 += 1.2f * D_8034F854;
    }
    if (D_8034E9F0 > 6.2831855f) { // little more than 2*PI or DEG_TO_RAD(360)
        D_8034E9F0 -= 6.2831855f;
    }
    if (D_8034E9F0 <= 1.5707964f) {                             // DEG_TO_RAD(90)
        sp34 = D_8034E9F0 / 1.5707964f;                         // DEG_TO_RAD(90)
    } else if (D_8034E9F0 <= 3.1415927f) {                      // PI or DEG_TO_RAD(180)
        sp34 = 1.0f - ((D_8034E9F0 - 1.5707964f) / 1.5707964f); // - DEG_TO_RAD(90) / DEG_TO_RAD(90)
    } else if (D_8034E9F0 <= 4.712389f) {                       // DEG_TO_RAD(270)
        sp34 = -(D_8034E9F0 - 3.1415927f) / 1.5707964f;         // - DEG_TO_RAD(180) / DEG_TO_RAD(90)
    } else if (D_8034E9F0 <= 6.2831855f) {                      // DEG_TO_RAD(360)
        // this block should just be `else` since `D_8034E9F0 > 6.2831855f` above
        sp34 = ((D_8034E9F0 - 4.712389f) / 1.5707964f) + -1.0f; // - DEG_TO_RAD(270) / DEG_TO_RAD(90)
    }
    arg0->unkA4 = (((1.5f * sp34) - (uvSinF(D_8034E9F0) * 0.5f)) * 0.5f) + 0.5f;
    if (func_803231A0(0, Z_TRIG) == 0) {
        arg0->unk9C -= 0.25f * arg0->unkBC * D_8034F854;
        arg0->unkA0 -= 0.25f * arg0->unkC0 * D_8034F854;

        sp34 = FABS(arg0->unkBC);
        if (sp34 > 0 || FABS(arg0->unkC0) > 0) {
            arg0->unk11D = 1;
        }
    } else {
        // square, but maintain +/-
        var_fa0 = SQ(arg0->unkBC);
        if (arg0->unkBC < 0.0f) {
            var_fa0 = -var_fa0;
        }
        arg0->unk9C -= (1.0f / 2.0f) * var_fa0 * D_8034F854; // if 0.5f, tries to reuse reg
        if (var_fa0 > 0.0f) {
            arg0->unk11D = 1;
        }

        // square, but maintain +/-
        var_fa0 = SQ(arg0->unkC0);
        if (arg0->unkC0 < 0.0f) {
            var_fa0 = -var_fa0;
        }
        arg0->unkA0 -= (1.0f / 2.0f) * var_fa0 * D_8034F854; // if 0.5f, tries to reuse reg
        if (var_fa0 > 0.0f) {
            arg0->unk11D = 1;
        }
    }

    if (arg0->unkA0 < -0.1745329f) { // almost DEG_TO_RAD(-10.0)
        arg0->unkA0 = -0.1745329f;
    } else if (arg0->unkA0 > 1.0471975f) { // almost DEG_TO_RAD(60.0)
        arg0->unkA0 = 1.0471975f;
    }
    uvModelGetPosm(0x105, 1, &sp38);
    uvMat4RotateAxis(&sp38, arg0->unk9C, 'z');
    uvMat4RotateAxis(&sp38, arg0->unkA0, 'x');
    uvDobjPosm(arg0->unk54, 1, &sp38);
    uvModelGetPosm(0x105, 2, &sp38);
    uvMat4RotateAxis(&sp38, (1.44f * arg0->unk9C) - arg0->unkA0, 'x');
    uvDobjPosm(arg0->unk54, 2, &sp38);
    uvModelGetPosm(0x105, 3, &sp38);
    uvMat4RotateAxis(&sp38, -arg0->unkA0 - (1.44f * arg0->unk9C), 'x');
    uvDobjPosm(arg0->unk54, 3, &sp38);
    if (D_80359A84 == 0) {
        switch (arg0->unkC) {
        case 0:
            func_8031D8E0(0x111, 0x40000000, 0);
            break;
        case 1:
            func_8031D8E0(0x10, 0x40000000, 0);
            break;
        case 2:
            func_8031D8E0(0xD5, 0x40000000, 0);
            break;
        case 3:
            func_8031D8E0(0x1A2, 0x40000000, 0);
            break;
        default:
            func_8031D8E0(0x1A2, 0x40000000, 0);
            break;
        }
        D_80359A84 = 1;
    }
    if (arg0->unkC4 != 0) {
        func_802D6B7C(arg0);
    } else {
        uvDobjState(arg0->unk0, 0);
    }
}
#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic pop
#endif
#endif

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_5CFC0/func_802D6B7C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_5CFC0/func_802D6CC4.s")

void func_802D6F38(u8 pilot, Unk802D5B50_Arg2* arg1) {
    switch (pilot) {
    case 0:
        arg1->unk224 = -0.025f;
        arg1->unk228 = 0.097f;
        arg1->unk22C = 0.675f;
        arg1->unk234 = 0.0f;
        arg1->unk230 = 0.0f;
        arg1->unk238 = -0.745f;
        arg1->unk23C = -0.027f;
        arg1->unk240 = 0.442f;
        arg1->unk244 = 0.012f;
        arg1->unk248 = -0.024f;
        arg1->unk24C = -0.27f;
        arg1->unk250 = 0.101f;
        arg1->unk254 = -0.54f;
        arg1->unk258 = -0.156f;
        arg1->unk25C = 0.105f;
        arg1->unk260 = 0.486f;
        arg1->unk264 = -0.156f;
        arg1->unk268 = 0.105f;
        arg1->unk26C = -0.025f;
        arg1->unk270 = 0.307f;
        arg1->unk274 = 0.478f;
        arg1->unk278 = 0.96f;
        arg1->unk280 = 0.8f;
        arg1->unk27C = 5.88f;
        arg1->unk220 = 0x135;
        arg1->unk292 = 1;
        arg1->unk285 = 0xA;
        arg1->unk286 = 0xB;
        arg1->unk287 = 8;
        arg1->unk288 = 9;
        arg1->unk289 = 2;
        arg1->unk28A = 3;
        arg1->unk28B = 4;
        arg1->unk28C = 5;
        arg1->unk28D = 6;
        arg1->unk28E = 7;
        arg1->unk291 = 0xC;
        arg1->unk284 = 0x3E;
        break;
    case 1:
        arg1->unk224 = -0.001f;
        arg1->unk228 = 0.172f;
        arg1->unk22C = 0.782f;
        arg1->unk234 = 0.0f;
        arg1->unk230 = 0.0f;
        arg1->unk238 = -1.336f;
        arg1->unk23C = 0.001f;
        arg1->unk240 = 0.647f;
        arg1->unk244 = -0.002f;
        arg1->unk248 = -0.001f;
        arg1->unk24C = -0.341f;
        arg1->unk250 = 0.19f;
        arg1->unk254 = -0.722f;
        arg1->unk258 = -0.178f;
        arg1->unk25C = 0.148f;
        arg1->unk260 = 0.73f;
        arg1->unk264 = -0.178f;
        arg1->unk268 = 0.148f;
        arg1->unk26C = 0.0f;
        arg1->unk270 = 0.315f;
        arg1->unk274 = 0.603f;
        arg1->unk278 = 0.8f;
        arg1->unk280 = 1.0f;
        arg1->unk27C = 9.8f;
        arg1->unk220 = 0x136;
        arg1->unk292 = 6;
        arg1->unk285 = 2;
        arg1->unk286 = 3;
        arg1->unk287 = 4;
        arg1->unk288 = 5;
        arg1->unk289 = 0xA;
        arg1->unk28A = 0xB;
        arg1->unk28B = 0xC;
        arg1->unk28C = 7;
        arg1->unk28D = 8;
        arg1->unk28E = 9;
        arg1->unk291 = 1;
        arg1->unk284 = 0x3F;
        break;
    case 2:
        arg1->unk224 = 0.003f;
        arg1->unk228 = 0.187f;
        arg1->unk22C = 0.634f;
        arg1->unk234 = 0.0f;
        arg1->unk230 = 0.0f;
        arg1->unk238 = -1.221f;
        arg1->unk23C = -0.01f;
        arg1->unk240 = 0.698f;
        arg1->unk244 = -0.013f;
        arg1->unk248 = -0.004f;
        arg1->unk24C = -0.43f;
        arg1->unk250 = -0.117f;
        arg1->unk254 = -0.819f;
        arg1->unk258 = -0.245f;
        arg1->unk25C = 0.069f;
        arg1->unk260 = 0.837f;
        arg1->unk264 = -0.245f;
        arg1->unk268 = 0.069f;
        arg1->unk26C = 0.002f;
        arg1->unk270 = 0.325f;
        arg1->unk274 = 0.52f;
        arg1->unk278 = 0.64f;
        arg1->unk280 = 1.2f;
        arg1->unk27C = 13.72f;
        arg1->unk220 = 0x137;
        arg1->unk292 = 6;
        arg1->unk285 = 1;
        arg1->unk286 = 2;
        arg1->unk287 = 3;
        arg1->unk288 = 4;
        arg1->unk289 = 0xA;
        arg1->unk28A = 0xB;
        arg1->unk28B = 0xC;
        arg1->unk28C = 7;
        arg1->unk28D = 8;
        arg1->unk28E = 9;
        arg1->unk291 = 5;
        arg1->unk284 = 0x40;
        break;
    case 3:
        arg1->unk224 = 0.002f;
        arg1->unk228 = 0.084f;
        arg1->unk22C = 0.706f;
        arg1->unk234 = 0.0f;
        arg1->unk230 = 0.0f;
        arg1->unk238 = -0.828f;
        arg1->unk23C = 0.0f;
        arg1->unk240 = 0.426f;
        arg1->unk244 = 0.03f;
        arg1->unk248 = 0.0f;
        arg1->unk24C = -0.261f;
        arg1->unk250 = 0.107f;
        arg1->unk254 = -0.479f;
        arg1->unk258 = -0.153f;
        arg1->unk25C = 0.079f;
        arg1->unk260 = 0.489f;
        arg1->unk264 = -0.153f;
        arg1->unk268 = 0.079f;
        arg1->unk26C = 0.002f;
        arg1->unk270 = 0.308f;
        arg1->unk274 = 0.473f;
        arg1->unk278 = 0.96f;
        arg1->unk280 = 0.8f;
        arg1->unk27C = 5.88f;
        arg1->unk220 = 0x138;
        arg1->unk292 = 8;
        arg1->unk285 = 1;
        arg1->unk286 = 2;
        arg1->unk287 = 3;
        arg1->unk288 = 4;
        arg1->unk289 = 9;
        arg1->unk28A = 0xA;
        arg1->unk28B = 0xB;
        arg1->unk28C = 0xC;
        arg1->unk28D = 0xD;
        arg1->unk28E = 0xE;
        arg1->unk291 = 5;
        arg1->unk284 = 0x41;
        break;
    case 4:
        arg1->unk224 = -0.002f;
        arg1->unk228 = 0.085f;
        arg1->unk22C = 0.799f;
        arg1->unk234 = 0.0f;
        arg1->unk230 = 0; // float, but needs other zero literal to match
        arg1->unk238 = -1.36f;
        arg1->unk23C = 0.0f;
        arg1->unk240 = 0.586f;
        arg1->unk244 = -0.034f;
        arg1->unk248 = 0.0f;
        arg1->unk24C = -0.314f;
        arg1->unk250 = 0.091f;
        arg1->unk254 = -0.666f;
        arg1->unk258 = -0.164f;
        arg1->unk25C = 0.141f;
        arg1->unk260 = 0.678f;
        arg1->unk264 = -0.164f;
        arg1->unk268 = 0.141f;
        arg1->unk26C = 0.0f;
        arg1->unk270 = 0.212f;
        arg1->unk274 = 0.599f;
        arg1->unk278 = 0.8f;
        arg1->unk280 = 1.0f;
        arg1->unk27C = 9.8f;
        arg1->unk220 = 0x139;
        arg1->unk292 = 6;
        arg1->unk285 = 2;
        arg1->unk286 = 3;
        arg1->unk287 = 4;
        arg1->unk288 = 5;
        arg1->unk289 = 0xA;
        arg1->unk28A = 0xB;
        arg1->unk28B = 0xC;
        arg1->unk28C = 7;
        arg1->unk28D = 8;
        arg1->unk28E = 9;
        arg1->unk291 = 1;
        arg1->unk284 = 0x42;
        break;
    case 5:
        arg1->unk224 = -0.001f;
        arg1->unk228 = 0.095f;
        arg1->unk22C = 0.844f;
        arg1->unk234 = 0.0f;
        arg1->unk230 = 0.0f;
        arg1->unk238 = -1.076f;
        arg1->unk23C = 0.0f;
        arg1->unk240 = 0.563f;
        arg1->unk244 = -0.018f;
        arg1->unk248 = 0.0f;
        arg1->unk24C = -0.433f;
        arg1->unk250 = 0.155f;
        arg1->unk254 = -0.737f;
        arg1->unk258 = -0.266f;
        arg1->unk25C = 0.112f;
        arg1->unk260 = 0.751f;
        arg1->unk264 = -0.266f;
        arg1->unk268 = 0.112f;
        arg1->unk26C = 0.0f;
        arg1->unk270 = 0.217f;
        arg1->unk274 = 0.621f;
        arg1->unk278 = 0.64f;
        arg1->unk280 = 1.2f;
        arg1->unk27C = 13.72f;
        arg1->unk220 = 0x13A;
        arg1->unk292 = 6;
        arg1->unk285 = 2;
        arg1->unk286 = 3;
        arg1->unk287 = 4;
        arg1->unk288 = 5;
        arg1->unk289 = 7;
        arg1->unk28A = 8;
        arg1->unk28B = 9;
        arg1->unk28C = 0xA;
        arg1->unk28D = 0xB;
        arg1->unk28E = 0xC;
        arg1->unk291 = 1;
        arg1->unk284 = 0x43;
        break;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_5CFC0/func_802D77D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_5CFC0/func_802D7B7C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_5CFC0/func_802D8098.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_5CFC0/func_802D8494.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_5CFC0/func_802D8730.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_5CFC0/func_802D8A40.s")
