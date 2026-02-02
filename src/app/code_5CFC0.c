#include "common.h"

#include <uv_dobj.h>
#include <uv_memory.h>
#include "cbsound.h"
#include "code_5A6A0.h"
#include "code_60020.h"

// TODO: context things
#include <uv_matrix.h>

void uvDobjPosm(u16, s32, void*);
void uvDobjState(u16, u8);
void func_802D45C4(void*, f32); // TODO: arg0 type mismatch with other callers
void db_getstart(Mtx4F*, void*, s32, s32);
void func_802D94EC(void*);
void func_80313570(Mtx4F*, f32*, f32*, f32*, f32*, f32*, f32*);
void uvModelGetProps(u16, s32, void*, s32);
extern f32 D_8034E9F0;
extern s8 D_8034E9F4;
extern s32 D_8034E9F8;

typedef struct {
    u16 unk0;
    u8 unk2;
    u8 pad3;
    u16 unk4;
    u8 pad6[0xA];
    s16 unk10;
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
    void* unkB0;
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

typedef struct {
    u8 unk0;
    u8 unk1;
    u8 pad2[2];
    u16 unk4;
    u8 unk6;
    u8 pad7;
    f32 unk8;
    u8 padC[0x3C];
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
    u8 pad78[0x1B0];
    f32 unk228;
} Unk802D5C5C_Arg0_B0;

typedef struct {
    u16 unk0;
    u8 unk2;
    u8 pad3;
    s32 pad4;
    f32 unk8;
    u8 padC[2];
    u16 unkE;
    u8 pad10[4];
    Mtx4F unk14;
    u16 unk54;
    u8 unk56;
    u8 pad57;
    Mtx4F unk58;
    f32 unk98;
    f32 unk9C;
    f32 unkA0;
    u8 padA4[12];
    Unk802D5C5C_Arg0_B0* unkB0;
    u8 unkB4;
    u8 padB5[3];
    f32 unkB8;
    u8 padBC[8];
    u8 unkC4;
    u8 padC5[3];
    f32 unkC8;
    f32 unkCC;
    f32 unkD0;
    u8 unkD4;
    u8 padD5[0xE3];
    s32 unk1B8;
    u8 pad1BC[0x64];
    u16 unk220;
    u8 pad222[0x4A];
    f32 unk26C;
    f32 unk270;
    f32 unk274;
    u8 pad278[0x1B];
    u8 unk293;
} Unk802D5C5C_Arg0;

extern Unk803599D0 D_80359A30;

// forward declarations
void func_802D6F38(u8, Unk802D5B50_Arg2*);
void func_802D5A90(void);

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
void func_802D5B50(u8 arg0, u8 pilot, Unk802D5B50_Arg2* arg2, Unk802D5B50_Arg3* arg3) {
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

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_5CFC0/func_802D5E98.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_5CFC0/func_802D5F00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_5CFC0/func_802D66C4.s")

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
