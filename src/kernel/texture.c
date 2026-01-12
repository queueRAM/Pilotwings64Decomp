#include "common.h"
#include <uv_graphics.h>

void* func_80225470(void*);
void* func_802254B0(void*);
void* func_802255A0(void*);
void* func_802256B8(void*);
void* func_80225FBC(void*);
void* func_80227260(void*);
void* _uvExpandTextureCpy(void*);
void* _uvExpandTextureImg(void*);

extern u32 D_802B53F4[];
extern u32 D_802B5A34[];
extern u32 D_802B5C34[];
extern u32 D_802B6404;
extern u32 D_802B6484;
extern u32 D_802B64BC;
extern u32 D_802B64E4;
extern u32 D_802B6A34[];

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/texture/func_802246A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/texture/func_80224A90.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/texture/func_802279B0.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/texture/func_80227B5C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/texture/func_80227BD4.s")

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
