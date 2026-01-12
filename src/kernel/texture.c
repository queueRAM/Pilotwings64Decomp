#include "common.h"
#include <uv_graphics.h>
#include <uv_memory.h>

// forward declarations
void* _uvExpandTexture(void*);
void* _uvExpandTextureCpy(void*);
void* _uvExpandTextureImg(void*);
void* func_80219270(s32);
void* func_80225470(void*);
void* func_802254B0(void*);
void* func_802255A0(void*);
void* func_802256B8(void*);
void* func_80225FBC(void*);
void* func_80226FD0(void*);
void* func_802270BC(void*);
void* func_80227260(void*);
void* func_80227804(s32);
void* func_802278C0(s32);
void* func_80227938(s32);
void* func_802279B0(s32);
void* func_80227A28(s32);
void* func_80227AA0(s32);
void* func_80227B5C(s32);
void* func_80227BD4(s32);
void* func_80227C84(s32);
void* func_80227D34(s32);
void* func_80227DE4(s32);
void* uvJanimLoad(s32);

extern u32 D_802B53F4[];
extern u32 D_802B5A34[];
extern u32 D_802B5C34[];
extern u32 D_802B6404;
extern u32 D_802B6484;
extern u32 D_802B6494;
extern u32 D_802B64BC;
extern u32 D_802B64E4;
extern u32 D_802B6A34[];
extern u32 D_802B6E2C;
extern u32 D_802B892C;

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/texture/func_802246A0.s")

//#pragma GLOBAL_ASM("asm/nonmatchings/kernel/texture/func_80224A90.s")
void* func_80224A90(u32 arg0, s32 arg1) {
    void* ret;

    ret = NULL;
    _uvJumpHeap(&D_802B892C);
    do {
        if (1) {} // fakematch
        switch (arg0) {
            case 'UVSQ': // 0x55565351
                ret = func_80227DE4(arg1);
                break;
            case 'UVEN': // 0x5556454E
                ret = func_802278C0(arg1);
                break;
            case 'UVTR': // 0x55565452
                ret = func_80227B5C(arg1);
                break;
            case 'UVCT': // 0x55564354
                ret = func_80227804(arg1);
                break;
            case 'UVLV': // 0x55564C56
                ret = func_80227938(arg1);
                break;
            case 'UVMD': // 0x55564D44
                ret = func_80227AA0(arg1);
                break;
            case 'UVTX': // 0x55565458
                ret = func_80227BD4(arg1);
                break;
            case 'UVTI': // 0x55565449
                ret = func_80227C84(arg1);
                break;
            case 'UVLT': // 0x55564C54
                ret = func_80227A28(arg1);
                break;
            case 'UVAN': // 0x5556414E
                ret = uvJanimLoad(arg1);
                break;
            case 'UVFT': // 0x55564654
                ret = func_80219270(arg1);
                break;
            case 'UVBT': // 0x55564254
                ret = func_80227D34(arg1);
                break;
            case 'UVTP': // 0x55565450
                ret = func_802279B0(arg1);
                break;
        }
    } while (_uvJumpHeap(&D_802B892C) == 0);
    return ret;
}

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/texture/uvMemLoadPal.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/texture/uvMemLoadDS.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/texture/func_80225394.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/texture/func_80225470.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/texture/func_802254B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/texture/func_802255A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/texture/func_802256B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/texture/func_80225FBC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/texture/_uvExpandTexture.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/texture/_uvExpandTextureImg.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/texture/_uvExpandTextureCpy.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/texture/func_80226FD0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/texture/func_802270BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/texture/func_80227260.s")

//#pragma GLOBAL_ASM("asm/nonmatchings/kernel/texture/func_80227804.s")
void* func_80227804(s32 arg0) {
    s32 idx;
    s32 tag;
    u32 sp3C;
    void* sp38;
    void* ret;

    ret = NULL;
    idx = func_80223E80(D_802B5A34[arg0]);
    while ((tag = func_80223F7C(idx, &sp3C, &sp38, 1)) != 0) {
        if (tag == 'COMM') { // 0x434F4D4D
            if (1) {} // fakematch
            ret = func_80225FBC(sp38);
        }
    }
    func_80223F30(idx);
    return ret;
}

//#pragma GLOBAL_ASM("asm/nonmatchings/kernel/texture/func_802278C0.s")
void* func_802278C0(s32 arg0) {
    s32 sp2C;
    s32 sp28;
    void* sp24;
    void* ret;

    ret = NULL;
    sp2C = func_80223E80(D_802B6404);
    if (func_80224170(sp2C, &sp28, &sp24, 'COMM', arg0, 1) != 0) { // 0x434F4D4D
        ret = func_802254B0(sp24);
    }
    func_80223F30(sp2C);
    return ret;
}

//#pragma GLOBAL_ASM("asm/nonmatchings/kernel/texture/func_80227938.s")
void* func_80227938(s32 arg0) {
    s32 idx;
    s32 sp28;
    void* sp24;
    void* ret;

    ret = NULL;
    idx = func_80223E80(D_802B64E4);
    if (func_80224170(idx, &sp28, &sp24, 'COMM', arg0, 1) != 0) { // 0x434F4D4D
        ret = _uvExpandTextureCpy(sp24);
    }
    func_80223F30(idx);
    return ret;
}

//#pragma GLOBAL_ASM("asm/nonmatchings/kernel/texture/func_802279B0.s")
void* func_802279B0(s32 arg0) {
    s32 idx;
    s32 sp28;
    void* sp24;
    void* ret;

    ret = NULL;
    idx = func_80223E80(D_802B6E2C);
    if (func_80224170(idx, &sp28, &sp24, 'COMM', arg0, 1) != 0) { // 0x434F4D4D
        ret = func_80226FD0(sp24);
    }
    func_80223F30(idx);
    return ret;
}

//#pragma GLOBAL_ASM("asm/nonmatchings/kernel/texture/func_80227A28.s")
void* func_80227A28(s32 arg0) {
    s32 idx;
    s32 sp28;
    void* sp24;
    void* ret;

    ret = NULL;
    idx = func_80223E80(D_802B6484);
    if (func_80224170(idx, &sp28, &sp24, 'COMM', arg0, 1) != 0) { // 0x434F4D4D
        ret = func_80225470(sp24);
    }
    func_80223F30(idx);
    return ret;
}

//#pragma GLOBAL_ASM("asm/nonmatchings/kernel/texture/func_80227AA0.s")
void* func_80227AA0(s32 arg0) {
    s32 idx;
    s32 tag;
    u32 sp3C;
    void* sp38;
    void* ret;

    ret = NULL;
    idx = func_80223E80(D_802B53F4[arg0]);
    while ((tag = func_80223F7C(idx, &sp3C, &sp38, 1)) != 0) {
        if (tag == 'COMM') { // 0x434F4D4D
            if (1) {} // fakematch
            ret = func_802256B8(sp38);
        }
    }
    func_80223F30(idx);
    return ret;
}

//#pragma GLOBAL_ASM("asm/nonmatchings/kernel/texture/func_80227B5C.s")
void* func_80227B5C(s32 arg0) {
    s32 idx;
    s32 sp28;
    void* sp24;
    void* ret;

    ret = NULL;
    idx = func_80223E80(D_802B6494);
    if (func_80224170(idx, &sp28, &sp24, 'COMM', arg0, 1) != 0) { // 0x434F4D4D
        ret = func_802270BC(sp24);
    }
    func_80223F30(idx);
    return ret;
}

//#pragma GLOBAL_ASM("asm/nonmatchings/kernel/texture/func_80227BD4.s")
void* func_80227BD4(s32 arg0) {
    s32 idx;
    s32 tag;
    u32 sp34;
    void* sp30;
    void* ret;

    idx = func_80223E80(D_802B5C34[arg0]);
    while ((tag = func_80223F7C(idx, &sp34, &sp30, 1)) != 0) {
        if (tag == 'COMM') { // 0x434F4D4D
            if (1) {} // fakematch
            ret = _uvExpandTexture(sp30);
        }
    }
    func_80223F30(idx);
    return ret;
}

//#pragma GLOBAL_ASM("asm/nonmatchings/kernel/texture/func_80227C84.s")
void* func_80227C84(s32 arg0) {
    s32 idx;
    s32 tag;
    u32 sp34;
    void* sp30;
    void* ret;

    idx = func_80223E80(D_802B5C34[arg0]);

    while ((tag = func_80223F7C(idx, &sp34, &sp30, 1)) != 0) {
        if (tag == 'COMM') { // 0x434F4D4D
            if (1) {} // fakematch
            ret = _uvExpandTextureImg(sp30);
        }
    }
    func_80223F30(idx);
    return ret;
}

//#pragma GLOBAL_ASM("asm/nonmatchings/kernel/texture/func_80227D34.s")
void* func_80227D34(s32 arg0) {
    s32 idx;
    s32 tag;
    u32 sp3C;
    void* sp38;
    void* ret;

    idx = func_80223E80(D_802B6A34[arg0]);
    while ((tag = func_80223F7C(idx, &sp3C, &sp38, 0)) != 0) {
        if (tag == 'COMM') { // 0x434F4D4D
            if (1) {} // fakematch
            ret = func_80227260(sp38);
        }
    }
    func_80223F30(idx);
    return ret;
}

//#pragma GLOBAL_ASM("asm/nonmatchings/kernel/texture/func_80227DE4.s")
void* func_80227DE4(s32 arg0) {
    s32 idx;
    s32 sp28;
    void* sp24;
    void* ret;

    ret = NULL;
    idx = func_80223E80(D_802B64BC);
    if (func_80224170(idx, &sp28, &sp24, 'COMM', arg0, 1) != 0) { // 0x434F4D4D
        ret = func_802255A0(sp24);
    }
    func_80223F30(idx);
    return ret;
}

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/texture/func_80227E5C.s")
