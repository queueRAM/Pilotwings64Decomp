#include "common.h"

#include <PR/ultratypes.h>

typedef struct {
    u8 pad0[0x220];
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
} Unk802D6F38;

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_5CFC0/func_802D5A90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_5CFC0/func_802D5B50.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_5CFC0/func_802D5C5C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_5CFC0/func_802D5E98.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_5CFC0/func_802D5F00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_5CFC0/func_802D66C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_5CFC0/func_802D6B7C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_5CFC0/func_802D6CC4.s")

void func_802D6F38(u8 arg0, Unk802D6F38* arg1) {
    switch (arg0) {
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
