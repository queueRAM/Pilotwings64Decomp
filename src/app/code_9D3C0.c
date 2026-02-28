#include "common.h"
#include <uv_graphics.h>
#include <uv_level.h>
#include "code_99D40.h"
#include "credits.h"
#include "menu.h"
#include "save.h"

// TODO: usage of [unk9C+1].debugFlag are likely incorrect way to get to 0x96 offset

f32 D_8034F8D0[] = { 0.0f, 0.2f, 0.4f, 0.6f, 1.0f };
s32 D_8034F8E4 = 0;
s32 D_8034F8E8 = 0;
s32 D_8034F8EC = 4;
s32 D_8034F8F0 = 4;
s32 D_8034F8F4 = 0;

extern s16 D_8036C120;
extern s32 D_8036C124;
extern u8 D_8036C128;     // flag to determine if game is complete
extern s32 D_8036C130[5]; // menu items, at least 5

// forward declarations
void func_80315F0C(void);
void func_8031631C(void);
s32 func_8031633C(void);
void func_80316A28(void);
void func_80316B08(void);
void func_803160B0(void);
void func_803161A8(void);
void func_80316238(void);
s32 func_803163B8(void);
s32 func_80316528(void);
s32 func_80316634(void);
void func_80316B80(void);
void func_80316BEC(s32, s32);
void func_80316D34(s32, s32);

s32 func_80315E90(void) {
    s32 temp_v0;

    D_8036C120 = 3;
    func_80315F0C();
    while ((temp_v0 = func_8031633C()) == -1) {
        uvGfxBegin();
        func_80316B08();
        func_80316A28();
        uvGfxEnd();
    }
    func_8031631C();
    return temp_v0;
}

void func_80315F0C(void) {
    D_80362690->unk0[D_80362690->unk9C + 1].debugFlag = 0;
    saveFileLoad(D_80362690->unk0[D_80362690->unk9C + 1].debugFlag);
    D_8036C128 = func_8030CC48();

    D_80362690->unk0[D_80362690->unk9C + 1].debugFlag = 1;
    saveFileLoad(D_80362690->unk0[D_80362690->unk9C + 1].debugFlag);

    if (D_8036C128 < func_8030CC48()) {
        D_8036C128 = func_8030CC48();
    } else {
        D_80362690->unk0[D_80362690->unk9C + 1].debugFlag = 0;
        saveFileLoad(D_80362690->unk0[D_80362690->unk9C + 1].debugFlag);
    }
    if (D_8036C120 == 3) {
        func_80316B80();
        D_8036C120 = 0;
    }
    switch (D_8036C120) {
    case 0:
        func_803160B0();
        break;
    case 1:
        func_803161A8();
        break;
    case 2:
        func_80316238();
        break;
    }
    D_8036C124 = 0;
}

void func_803160B0(void) {
    s32 menuY;
    s32 count;

    saveFileLoad((s32)D_80362690->unk0[D_80362690->unk9C + 1].debugFlag);
    if (D_8036C128 != 0) {
        D_8036C130[0] = 0xC2;  // "Check album"
        D_8036C130[1] = 0xBE;  // "Sound"
        D_8036C130[2] = 0x13;  // "Congratulations!"
        D_8036C130[3] = 0x11C; // "Return"
        count = 4;
        menuY = 80;
    } else {
        D_8036C130[0] = 0xC2;  // "Check album"
        D_8036C130[1] = 0xBE;  // "Sound"
        D_8036C130[2] = 0x11C; // "Return"
        count = 3;
        menuY = 100;
    }
    menuCreateItems(0x50, menuY, 6, 1.0f, 1.0f, D_8036C130, count);
    func_80312F5C(1, 0xFF, 0xFF, 0xFF);
    func_80312F5C(0, 0xFF, 0xFF, 0x00);
}

void func_803161A8(void) {
    D_8036C130[0] = 0xBD;  // "File 1"
    D_8036C130[1] = 0x51;  // "File 2"
    D_8036C130[2] = 0x11C; // "Return"
    menuCreateItems(80, 100, 6, 1.0f, 1.0f, D_8036C130, 3);
    func_80312F5C(1, 0xFF, 0xFF, 0xFF);
    func_80312F5C(0, 0xFF, 0xFF, 0x00);
    D_8034F8F4 = 0;
}

void func_80316238(void) {
    D_8036C130[0] = 0x4B;  // "Stereo"
    D_8036C130[1] = 0xCE;  // "Sound Track"
    D_8036C130[2] = 0x133; // "Vol. 1" (Sound Track)
    D_8036C130[3] = 0x64;  // "Vol. 1" (Sound Effects)
    D_8036C130[4] = 0x11C; // "Return"
    menuCreateItems(40, 70, 6, 1.0f, 1.0f, D_8036C130, 5);
    func_80312F5C(1, 0xFF, 0xFF, 0xFF);
    func_80312F5C(0, 0xFF, 0xFF, 0);
    func_80316BEC(0, D_8034F8E4);
    func_80316D34(1, D_8034F8E8);
    func_80316BEC(2, D_8034F8EC);
    func_80316BEC(3, D_8034F8F0);
    func_80312FF8(6);
}

void func_8031631C(void) {
    menuSetProps();
}

s32 func_8031633C(void) {
    switch (D_8036C120) {
    case 0:
        return func_803163B8();
    case 1:
        return func_80316528();
    case 2:
        return func_80316634();
    default:
        _uvDebugPrintf("option_update : unknown panel!\n");
        return 0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_9D3C0/func_803163B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_9D3C0/func_80316528.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_9D3C0/func_80316634.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_9D3C0/func_80316A28.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_9D3C0/func_80316A90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_9D3C0/func_80316AB8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_9D3C0/func_80316AE0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_9D3C0/func_80316B08.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_9D3C0/func_80316B80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_9D3C0/func_80316BEC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_9D3C0/func_80316D34.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_9D3C0/func_80316D88.s")
