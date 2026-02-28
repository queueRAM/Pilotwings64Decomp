#include "common.h"
#include <uv_font.h>
#include <uv_geometry.h>
#include <uv_graphics.h>
#include <uv_level.h>
#include <uv_sprite.h>
#include "kernel/code_1050.h"
#include "code_99D40.h"
#include "code_B3A70.h"
#include "credits.h"
#include "demo.h"
#include "menu.h"
#include "save.h"
#include "snap.h"
#include "snd.h"
#include "text_data.h"

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
extern u8 D_8036C129;
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
s32 func_80316D88(f32, s32, s32);
void func_80316A90(void);
void func_80316AB8(void);
void func_80316AE0(void);

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

s32 func_803163B8(void) {
    s32 temp_v0;
    u32 temp_t7;

    temp_v0 = menu_8030B50C();
    temp_t7 = temp_v0 + 1;
    if (D_8036C128) {
        switch (temp_t7) {
        case 1:
            D_8036C120 = 1;
            func_8032D51C(0);
            func_80315F0C();
            return -1;
        case 2:
            D_8036C120 = 2;
            func_8032D51C(0);
            func_80315F0C();
            return -1;
        case 3:
            func_8033FB14();
            func_8033F964(1);
            func_8032D51C(0);
            func_8030CCFC();
            func_80316B80();
            func_803160B0();
            return -1;
        case 0:
        case 4:
            func_8032D51C(0);
            return 0;
        default:
            return -1;
        }
    } else {
        switch (temp_v0) {
        case 0:
            D_8036C120 = 1;
            func_8032D51C(0);
            func_80315F0C();
            return -1;
        case 1:
            D_8036C120 = 2;
            func_8032D51C(0);
            func_80315F0C();
            return -1;
        case -1:
        case 2:
            func_8032D51C(0);
            return 0;
        default:
            return -1;
        }
    }
}

s32 func_80316528(void) {
    s32 temp_v0;

    temp_v0 = menu_8030B50C();
    switch (temp_v0) {
    case 0:
        D_8036C129 = 0;
        saveFileLoad(D_8036C129);
        if (func_8033E3A8(0) != 0) {
            saveFileWrite(D_8036C129);
        }
        func_80316B80();
        func_803161A8();
        return -1;
    case 1:
        D_8036C129 = 1;
        saveFileLoad(D_8036C129);
        if (func_8033E3A8(0) != 0) {
            saveFileWrite(D_8036C129);
        }
        func_80316B80();
        func_803161A8();
        menu_8030B69C(1);
        return -1;
    case 2:
        func_8032D51C(0);
        return 0;
    case -1:
        D_8036C120 = 0;
        func_8032D51C(0);
        func_80315F0C();
        return -1;
    default:
        return -1;
    }
}

#ifndef NON_MATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/app/code_9D3C0/func_80316634.s")
#else
s32 func_80316634(void) {
    s32 sp24;
    s32 temp_v1;
    s32 sp1C;
    f32 stickX;

    sp24 = menu_8030B50C();
    temp_v1 = menu_8030B668();
    if (sp24 == -1) {
        if (temp_v1 != 1) {
            D_8036C120 = 0;
            func_8032D51C(0);
            func_80315F0C();
            return -1;
        } else {
            D_8034F8F4 = 0;
            func_8033F964(1);
        }
    }
    sp1C = 0;
    stickX = demoGetInputs(0, 0);
    if (ABS_NOEQ(stickX) < 0.75f) {
        D_8036C124 = FALSE;
    } else if (!D_8036C124) {
        if (stickX > 0.75f) {
            sp1C = 1;
            D_8036C124 = TRUE;
        }
        if (stickX < -0.75f) {
            sp1C = -1;
            D_8036C124 = TRUE;
        }
    }

    switch (temp_v1) {
    case 0:
        D_8034F8E4 += sp1C;
        D_8034F8E4 = func_80316D88(0.75f, 0, 1);
        if (D_8034F8E4 == 0) {
            func_80200180(0, 8, 2, 0);
        } else {
            func_80200180(0, 8, 1, 0);
        }
        if (sp1C != 0) {
            func_8033F7F8(0x54);
        }
        func_80316BEC(0, D_8034F8E4);
        return -1;
    case 1:
        D_8034F8E8 += sp1C;
        D_8034F8E8 = func_80316D88(0.75f, 0, 0x1E);
        if (sp24 == temp_v1) {
            func_8033F748(D_8034F8E8);
            func_8033F964(0);
            func_8033FCD0(0xFF);
        }
        if (sp1C != 0) {
            func_8033F7F8(0x54);
        }
        func_80316D34(1, D_8034F8E8);
        return -1;
    case 2:
        D_8034F8EC += sp1C;
        if (D_8034F8EC < 0) {
            D_8034F8EC = 0;
        } else if (D_8034F8EC >= 5) {
            D_8034F8EC = 4;
        }
        func_80316BEC(2, D_8034F8EC);
        func_8033FA88(D_8034F8D0[D_8034F8EC]);
        func_8033FD94(0xFF, D_8034F8D0[D_8034F8F0], D_8034F8D0[D_8034F8EC]);
        return -1;
    case 3:
        D_8034F8F0 += sp1C;
        if (sp1C != 0) {
            func_8033F7F8(0x6E);
        }
        if (D_8034F8F0 < 0) {
            D_8034F8F0 = 0;
        } else if (D_8034F8F0 >= 5) {
            D_8034F8F0 = 4;
        }
        func_80316BEC(3, D_8034F8F0);
        func_8033FAD4(D_8034F8D0[D_8034F8F0]);
        func_8033FD94(0xFF, D_8034F8D0[D_8034F8F0], D_8034F8D0[D_8034F8EC]);
        return -1;
    case 4:
        if (sp24 == temp_v1) {
            func_8033F7F8(0x6E);
            func_8032D51C(0);
            return 0;
        }
        return -1;
    default:
        return -1;
    }
}
#endif

void func_80316A28(void) {
    switch (D_8036C120) {
    case 0:
        func_80316A90();
        break;
    case 1:
        func_80316AB8();
        break;
    case 2:
        func_80316AE0();
        break;
    }
}

void func_80316A90(void) {
    menuInit();
    uvFont_80219EA8();
}

void func_80316AB8(void) {
    menuInit();
    uvFont_80219EA8();
}

void func_80316AE0(void) {
    menuInit();
    uvFont_80219EA8();
}

void func_80316B08(void) {
    uvSprtDraw(0);
    uvGfx_80223A28(0xFFF);
    uvVtxRect(0, 18, 319, 0);
    uvVtxRect(0, 239, 319, 232);
    uvVtxRect(0, 232, 10, 18);
    uvVtxRect(310, 232, 319, 18);
}

void func_80316B80(void) {
    uvLevelInit();
    uvLevelAppend(0x70);
    uvLevelAppend(0x2E);
    uvSprtProps(0, 3, 1, 2, 0, 240, 9, 0x43, 0);
    textLoadBlock(0x42);
}

void func_80316BEC(s32 menuIdx, s32 setting) {
    s32 menuStr;

    switch (menuIdx) {
    case 0:
        switch (setting) {
        case 0:
            menuStr = 0x4B; // "Stereo"
            break;
        case 1:
            menuStr = 0x100; // "Mono"
            break;
        }
        break;
    case 2:
        switch (setting) {
        case 0:
            menuStr = 0x133; // "Vol 1."
            break;
        case 1:
            menuStr = 0xD6; // "Vol. >2"
            break;
        case 2:
            menuStr = 0x6E; // "Vol. >>3"
            break;
        case 3:
            menuStr = 0x1F; // "Vol. >>>4"
            break;
        case 4:
            menuStr = 0x183; // "Vol. >>>>5"
            break;
        }
        break;
    case 3:
        switch (setting) {
        case 0:
            menuStr = 0x64; // "Vol 1."
            break;
        case 1:
            menuStr = 0x1B; // "Vol. >2"
            break;
        case 2:
            menuStr = 0x179; // "Vol. >>3"
            break;
        case 3:
            menuStr = 0x12C; // "Vol. >>>4"
            break;
        case 4:
            menuStr = 0xD2; // "Vol. >>>>5"
            break;
        }
        break;
    }
    D_8036C130[menuIdx] = menuStr;
    menuSetItem(menuIdx, textGetDataByIdx(menuStr));
}

void func_80316D34(s32 arg0, s32 arg1) {
    s16* str;

    if (arg0 == 1) {
        str = textGetDataByIdx(0xCE); // "Sound Track"
        textFmtIntAt(str, arg1 + 1, 2, 13);
        menuSetItem(1, str);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_9D3C0/func_80316D88.s")
