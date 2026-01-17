#include <uv_graphics.h>
#include <uv_memory.h>

typedef struct UnkStruct_gfx_8b {
    s32 unk0;
    s32 unk4;
} UnkStruct_gfx_8b_t;

typedef struct {
    s32 unk0;
    s16 unk4;
    s16 unk6;
    s32 unk8;
    s32 unkC; // inferred from stack size, but not observed accessed
} Unk802239B4;

extern s32 D_80249230;
extern f32 D_8024921C;
extern s32 D_802491E8;
extern UnkStruct_gfx_8b_t* D_80298AB0;

extern u16 D_8024920C;
extern s16 D_80249218;
extern u8 D_802A9988[0xAF00];
extern u8* D_80299270[2];

extern s32 gGfxStateStackData;
extern u32 gGfxStateStack[];
extern u8 gGfxStateStackIdx;

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/graphics/func_80220960.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/graphics/uvGfxBegin.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/graphics/func_80220CA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/graphics/func_80220E0C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/graphics/func_80220F2C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/graphics/func_80220FF8.s")

void func_802210C4(s32 arg0) {
    UnkStruct_gfx_8b_t* temp_v1;

    temp_v1 = D_80298AB0++;
    temp_v1->unk4 = arg0;
    temp_v1->unk0 = 0x06000000;
}

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/graphics/func_802210E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/graphics/uvGfxStateDraw.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/graphics/func_80221A78.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/graphics/uvClampFunction.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/graphics/uvProcessLooks.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/graphics/func_80222100.s")

void func_80222170(s32 arg0) {
    D_80249230 = arg0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/graphics/uvGfxEnd.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/graphics/func_802228F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/graphics/func_80222A98.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/graphics/func_80222C94.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/graphics/func_80222D78.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/graphics/func_80222E90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/graphics/func_80222EE8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/graphics/func_80223094.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/graphics/func_802230CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/graphics/func_80223114.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/graphics/uvGfxUnkMatrixOp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/graphics/uvGfxUnkMatrixOp2.s")

void* func_802233C4(void) {
    return &D_802A9988[(D_8024920C * 0x5780) + (D_80249218 << 6)];
}

void func_80223408(f32 arg0) {
    D_8024921C = arg0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/graphics/func_80223414.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/graphics/func_8022345C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/graphics/func_802234F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/graphics/func_802235A4.s")

void func_802236A8(void) {
    UnkStruct_gfx_8b_t* temp_v1;

    temp_v1 = D_80298AB0++;
    temp_v1->unk4 = 0;
    temp_v1->unk0 = 0xBD000000;
}

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/graphics/func_802236CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/graphics/uvGfxGetCnt.s")

void uvGfxStatePush(void) {
    if (gGfxStateStackIdx >= 0x1F) {
        _uvDebugPrintf("uvGfxStatePush: stack full\n");
        return;
    }
    gGfxStateStack[gGfxStateStackIdx++] = gGfxStateStackData;
}

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/graphics/uvGfxStatePop.s")

void uvGfxSetFlags(s32 flags) {
    Unk802239B4 sp20;
    s32 newState;

    newState = flags | gGfxStateStackData;
    if (newState != gGfxStateStackData) {
        sp20.unk0 = newState;
        sp20.unk8 = 0;
        uvGfxStateDraw(&sp20);
    }
}

void uvGfxClearFlags(s32 flags) {
    Unk802239B4 sp20;
    s32 newState;

    newState = ~flags & gGfxStateStackData;
    if (newState != gGfxStateStackData) {
        sp20.unk0 = newState;
        sp20.unk8 = 0;
        uvGfxStateDraw(&sp20);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/graphics/func_80223A28.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/graphics/func_80223A64.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/graphics/func_80223B80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/graphics/func_80223BB8.s")

void func_80223BF4(s32 arg0) {
    D_802491E8 = arg0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/graphics/func_80223C00.s")

void uvCopyFrameBuf(s32 fb_id) {
    u8* src;
    u8* dst;

    if (fb_id < 0 || fb_id > 1) {
        _uvDebugPrintf("uvCopyFrameBuf: Buffer %d out of range\n", fb_id);
        return;
    }
    if (fb_id == 1) {
        fb_id = D_8024920C;
    } else {
        fb_id = D_8024920C ^ 1;
    }
    src = D_80299270[fb_id];
    dst = D_80299270[fb_id ^ 1];
    _uvMediaCopy(dst, src, 0x25800U);
}
