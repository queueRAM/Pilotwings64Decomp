#include <uv_geometry.h>

extern uvVertexArray_t D_80290680[];
extern uvVertex_t* D_80296A80;
extern s16 D_80296A84;
extern s16 D_80296A86;
extern s16 D_80296A88;
extern s16 D_80296A8A;
extern s16 D_80296A8C;

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/geometry/func_8021F100.s")

s16 uvVtx(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8) {
    uvVertex_t* vtx;

    vtx = &D_80296A80[D_80296A86];
    if (D_80296A86 >= 0x320) {
        _uvDebugPrintf("uvVtx: out of dynamic vertices\n");
        return D_80296A86;
    }
    D_80296A86 += 1;
    vtx->unk0 = arg0;
    vtx->unk2 = arg1;
    vtx->unk4 = arg2;
    vtx->unk8 = arg3;
    vtx->unkA = arg4;
    vtx->unkC = arg5;
    vtx->unkD = arg6;
    vtx->unkE = arg7;
    vtx->unkF = arg8;
    return (s16)(D_80296A86 - 1);
}

void func_8021F30C(u8 arg0) {
    D_80296A86 = 0;
    if (arg0) {
        D_80296A84 ^= 1;
        D_80296A80 = (uvVertex_t*)&D_80290680[D_80296A84];
    }
}

void uvVtxBeginPoly(void) {
    D_80296A8A = D_80296A86;
}

void uvBeginGrid(void) {
    D_80296A8C = D_80296A86;
}

void uvBeginTmesh(void) {
    D_80296A88 = D_80296A86;
}

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/geometry/uvEndTmesh.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/geometry/func_8021F56C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/geometry/uvEndGrid.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/geometry/func_8022052C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/geometry/uvVtxEndPoly.s")
