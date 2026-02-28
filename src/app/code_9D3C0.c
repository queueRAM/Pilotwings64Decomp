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
extern u8 D_8036C128; // flag to determine if game is complete
extern s32 D_8036C130[4]; // menu items, at least 4

// forward declarations
void func_80315F0C(void);
void func_8031631C(void);
s32 func_8031633C(void);
void func_80316A28(void);
void func_80316B08(void);
void func_803160B0(void);
void func_803161A8(void);
void func_80316238(void);
void func_80316B80(void);

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
    D_80362690->unk0[D_80362690->unk9C+1].debugFlag = 0;
    saveFileLoad(D_80362690->unk0[D_80362690->unk9C+1].debugFlag);
    D_8036C128 = func_8030CC48();
    
    D_80362690->unk0[D_80362690->unk9C+1].debugFlag = 1;
    saveFileLoad(D_80362690->unk0[D_80362690->unk9C+1].debugFlag);
    
    if (D_8036C128 < func_8030CC48()) {
        D_8036C128 = func_8030CC48();
    } else {
        D_80362690->unk0[D_80362690->unk9C+1].debugFlag = 0;
        saveFileLoad(D_80362690->unk0[D_80362690->unk9C+1].debugFlag);
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

    saveFileLoad((s32) D_80362690->unk0[D_80362690->unk9C+1].debugFlag);
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
    func_80312F5C(0, 0xFF, 0xFF, 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_9D3C0/func_803161A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_9D3C0/func_80316238.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_9D3C0/func_8031631C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_9D3C0/func_8031633C.s")

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
