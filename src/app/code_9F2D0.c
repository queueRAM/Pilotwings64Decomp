#include "common.h"

#include <uv_geometry.h>
#include <uv_graphics.h>
#include <uv_math.h>
#include <uv_sobj.h>
#include <uv_sprite.h>
#include "code_9F2D0.h"
#include "code_C9440.h"
#include "snap.h"

typedef struct {
    s16 unk0;
    s16 unk2;
} Unk8034F93C;

typedef struct {
    f32 unk0;
    f32 unk4;
} Unk8036C520;

extern Unk8034F93C D_8034F93C[3];
extern Unk8034F93C D_8034F95C[4];

extern HUDData D_8036C5A8;

extern u8 D_8036D220;
extern Unk8036C520 D_8036C520[];

// forward declarations
void func_8031E628(f32 arg0, f32* arg1, f32* arg2);
void func_8031EABC(u8 arg0);

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_9F2D0/func_80317DA0.s")

HUDData* getHUDPtr(void) {
    return &D_8036C5A8;
}

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_9F2D0/func_803182A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_9F2D0/func_80318700.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_9F2D0/func_803187C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_9F2D0/func_8031888C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_9F2D0/func_80319C8C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_9F2D0/func_80319E44.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_9F2D0/func_80319EFC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_9F2D0/func_80319FEC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_9F2D0/func_8031A118.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_9F2D0/func_8031A224.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_9F2D0/func_8031A2CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_9F2D0/func_8031A378.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_9F2D0/func_8031A66C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_9F2D0/func_8031A6C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_9F2D0/func_8031A794.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_9F2D0/func_8031A810.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_9F2D0/func_8031A874.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_9F2D0/func_8031A8E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_9F2D0/func_8031A954.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_9F2D0/func_8031AD68.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_9F2D0/func_8031BE88.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_9F2D0/demoShowController.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_9F2D0/func_8031C0B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_9F2D0/func_8031C1E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_9F2D0/func_8031C900.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_9F2D0/func_8031D15C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_9F2D0/func_8031D264.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_9F2D0/func_8031D494.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_9F2D0/func_8031D550.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_9F2D0/func_8031D8E0.s")

void func_8031D9B8(s16 arg0, f32 arg1, f32 arg2) {
    s16* temp_v0;
    s16* var_a0;
    s32 i;
    const u16 END_VALUE = -1;

    if (arg0 == -1) {
        D_8036C5A8.unkB40[0] = -1;
        D_8036C5A8.unkBCE = -1;
        return;
    }

    temp_v0 = func_80342198(arg0);
    D_8036C5A8.unkBCE = arg0;
    if (D_8036C5A8.unkB40[0] != -1) {
        D_8036C5A8.unkBC8 = D_8036C5A8.unk14 + 0.2f;
    }

    for (i = 0; i < ARRAY_COUNT(D_8036C5A8.unkB40); i++) {
        D_8036C5A8.unkB40[i] = temp_v0[i];
        // temp_v0 is s16, so comparing with 0xFFFF is always false.
        // this is a bug that IDO does not warn about, but modern compilers do.
        if (temp_v0[i] == END_VALUE) {
            break;
        }
    }

    D_8036C5A8.unkBCC = 1;
    D_8036C5A8.unkBB8 = arg1;
    D_8036C5A8.unkBBC = D_8036C5A8.unk14;
    D_8036C5A8.unkBC0 = arg2;
}

s16 func_8031DA90(void) {
    return D_8036C5A8.unkC5E;
}

s16 func_8031DA9C(void) {
    return D_8036C5A8.unkBCE;
}

void func_8031DAA8(u8 arg0, f32 arg1) {
    D_8036C5A8.unkC60 = arg0;
    D_8036C5A8.unkC64 = arg1;
    D_8036C5A8.unkC68 = (f32)D_8036C5A8.unk14;
    if (arg0 == 1) {
        func_8031EABC(0);
    }
}

void func_8031DAF4(HUDData* arg0) {
    if ((arg0->unkB40[0] != -1) && !(D_8036C5A8.unk14 < arg0->unkBC8)) {
        if (arg0->unkBB8 < (D_8036C5A8.unk14 - arg0->unkBBC)) {
            arg0->unkBCE = -1;
            arg0->unkB40[0] = -1;
            return;
        }
        uvFontSet(6);
        uvFont_80219550(1.0, 1.0);
        if (arg0->unkBCC != 0) {
            uvFont_8021956C(0xFF, 0xFF, 0xFF, 0xFF);
        } else {
            uvFont_8021956C(0xFF, 0, 0, 0xFF);
        }
        func_80219874(0xA0 - ((s32)(func_802196B0(&arg0->unkB40[0]) - 0x10) / 2), 0x7D, &arg0->unkB40[0], 0x28, 0xFFE);
    }
}

void func_8031DC00(HUDData* arg0) {
    if ((arg0->unkBD0 != -1) && !(D_8036C5A8.unk14 < arg0->unkC58)) {
        if (arg0->unkC48 < (D_8036C5A8.unk14 - arg0->unkC4C)) {
            arg0->unkC5E = -1;
            arg0->unkBD0 = -1;
            return;
        }
        uvFontSet(6);
        uvFont_80219550(1.0, 1.0);
        if (arg0->unkC5C != 0) {
            uvFont_8021956C(0xFF, 0xFF, 0xFF, 0xFF);
        } else {
            uvFont_8021956C(0U, 0x28, 0xFF, 0xFF);
        }
        func_80219874(0xA0 - ((func_802196B0(&arg0->unkBD0) - 0x10) / 2), 0x8C, &arg0->unkBD0, 0x28, 0xFFE);
    }
}

void func_8031DD0C(f32 arg0, f32 arg1, f32 arg2, u8 arg3, u8 arg4, u8 arg5, u8 arg6, f32 arg7) {
    s32 var_s0;
    s32 var_s1;
    s32 var_s2;
    f32 spB8;
    f32 spB4;
    Unk8036C520* temp_v0;
    f32 temp_fs0;
    f32 temp_fs1;
    f32 temp_fv0;
    f32 temp_fv1;

    var_s0 = 0x10;
    var_s1 = 0;
    temp_fs0 = uvSinF(arg7);
    temp_fs1 = uvCosF(arg7);
    uvBeginTmesh();

    var_s2 = 0;
    do {
        if (var_s2 != 0) {
            temp_v0 = &D_8036C520[var_s0];
            temp_fv0 = (temp_v0->unk0 * arg2) + arg0;
            temp_fv1 = (temp_v0->unk4 * arg2) + arg1;
            spB8 = (temp_fv0 * temp_fs1) - (temp_fv1 * temp_fs0);
            spB4 = (temp_fv0 * temp_fs0) + (temp_fv1 * temp_fs1);
            func_8031E628(31.0f, &spB8, &spB4);
            uvVtx((s32)spB8, (s32)spB4, 0, 0, 0, arg3, arg4, arg5, arg6);
            if (var_s0 <= 0) {
                var_s0 = 0x10;
            }
            var_s0 -= 1;
        } else {
            var_s1 += 1;
            if (var_s1 >= 0x10) {
                var_s1 = 0;
            }
            temp_v0 = &D_8036C520[var_s1];
            temp_fv0 = (temp_v0->unk0 * arg2) + arg0;
            temp_fv1 = (temp_v0->unk4 * arg2) + arg1;
            spB8 = (temp_fv0 * temp_fs1) - (temp_fv1 * temp_fs0);
            spB4 = (temp_fv0 * temp_fs0) + (temp_fv1 * temp_fs1);
            func_8031E628(31.0f, &spB8, &spB4);
            uvVtx((s32)spB8, (s32)spB4, 0, 0, 0, arg3, arg4, arg5, arg6);
        }
        var_s2 = var_s2 == 0;
    } while (var_s0 >= var_s1);
    uvEndTmesh();
}

void func_8031DF68(s32 arg0) {
    D_8036C5A8.unk4 = arg0;
}

void func_8031DF74(f32 arg0, f32 arg1, s32 arg2, s32 arg3, f32 arg4, u8 arg5) {
    Mtx4F sp70;
    u8 sp6F;
    u8 sp6E;
    s16 tmp5;
    s16 pad1;
    s16 sp68;
    s16 sp66;
    s32 i;

    tmp5 = arg5;
    switch (arg2) {
    case 0:
        if (arg3 != 0) {
            sp6F = 0, sp6E = 0xFF;
        } else {
            sp6F = 0xFF, sp6E = 0xFF;
        }
        break;
    case 1:
    case 2:
        sp6F = 0xFF, sp6E = 0;
        break;
    default:
        return;
    }
    if (arg0 > 800.0f) {
        uvMat4SetIdentity(&sp70);
        uvMat4RotateAxis(&sp70, arg1, 'z');
        uvMat4UnkOp2(&sp70, 0.0f, 30.0f, 0.0f);
        uvGfxMtxViewMul(&sp70, 1);
        if (arg0 >= 1000.0f) {
            uvVtxBeginPoly();
            for (i = 0; i < 3; i++) {
                uvVtx(D_8034F95C[i].unk0 * 3, (D_8034F95C[i].unk2 * 3) + 1, 0, 0, 0, 0, 0, 0, tmp5);
            }
            uvVtxEndPoly();

            uvVtxBeginPoly();
            for (i = 0; i < 3; i++) {
                uvVtx(D_8034F95C[i].unk0 * 2, (D_8034F95C[i].unk2 * 2) + 2, 0, 0, 0, sp6F, sp6E, 0, tmp5);
            }
            uvVtxEndPoly();
        }
        if (arg0 >= 900.0f) {
            uvVtxBeginPoly();
            for (i = 0; i < 3; i++) {
                uvVtx(D_8034F95C[i].unk0 * 3, (D_8034F95C[i].unk2 * 3) - 1, 0, 0, 0, 0, 0, 0, tmp5);
            }
            uvVtxEndPoly();

            uvVtxBeginPoly();
            for (i = 0; i < 3; i++) {
                uvVtx(D_8034F95C[i].unk0 * 2, D_8034F95C[i].unk2 * 2, 0, 0, 0, sp6F, sp6E, 0, tmp5);
            }
            uvVtxEndPoly();
        }
        uvVtxBeginPoly();
        for (i = 0; i < 3; i++) {
            uvVtx(D_8034F95C[i].unk0 * 5, (D_8034F95C[i].unk2 * 5) - 5, 0, 0, 0, 0, 0, 0, tmp5);
        }
        uvVtxEndPoly();

        uvVtxBeginPoly();
        for (i = 0; i < 3; i++) {
            uvVtx(D_8034F95C[i].unk0 * 4, (D_8034F95C[i].unk2 * 4) - 4, 0, 0, 0, sp6F, sp6E, 0, tmp5);
        }
        uvVtxEndPoly();
        uvGfxMtxViewPop();
    } else {
        arg0 *= 0.0375f;
        sp68 = (s16)(s32)(uvSinF(arg1) * -arg0);
        sp66 = (s16)(s32)(uvCosF(arg1) * arg0);
        if (arg2 != 2) {
            if (arg5 > 150) {
                uvVtxBeginPoly();
                for (i = 0; i < 4; i++) {
                    uvVtx(D_8034F93C[i].unk0 * 3 + sp68, (D_8034F93C[i].unk2 * 3) + sp66, 0, 0, 0, 0, 0, 0, arg5);
                }
                uvVtxEndPoly();

                uvVtxBeginPoly();
                for (i = 0; i < 4; i++) {
                    uvVtx(D_8034F93C[i].unk0 * 2 + sp68, (D_8034F93C[i].unk2 * 2) + sp66, 0, 0, 0, sp6F, sp6E, 0, arg5);
                }
                uvVtxEndPoly();
            }
        } else {
            uvMat4SetIdentity(&sp70);
            uvMat4UnkOp2(&sp70, (f32)sp68, (f32)sp66, 0.0f);
            uvMat4RotateAxis(&sp70, arg4, 'z');
            uvGfxMtxViewMul(&sp70, 1);

            uvVtxBeginPoly();
            for (i = 0; i < 4; i++) {
                uvVtx(D_8034F93C[i].unk0 * 3, D_8034F93C[i].unk2 * 6, 0, 0, 0, 0, 0, 0, tmp5);
            }
            uvVtxEndPoly();

            uvVtxBeginPoly();
            for (i = 0; i < 4; i++) {
                uvVtx(D_8034F93C[i].unk0 * 2, D_8034F93C[i].unk2 * 5, 0, 0, 0, sp6F, sp6E, 0, tmp5);
            }
            uvVtxEndPoly();
            uvGfxMtxViewPop();
        }
    }
}

void func_8031E628(f32 arg0, f32* arg1, f32* arg2) {
    f32 a2tmp;
    f32 length;
    f32 a1tmp;
    f32 scale;

    a2tmp = *arg2;
    a1tmp = *arg1;
    length = uvSqrtF(SQ(a2tmp) + SQ(a1tmp));
    if (arg0 < length) {
        scale = arg0 / length;
        *arg1 *= scale;
        *arg2 *= scale;
    }
}

void func_8031E69C(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, u8 arg5, u8 arg6, u8 arg7, u8 arg8) {
    uvVtxBeginPoly();
    uvVtx(arg0, arg1, 0, 0, 0, arg5, arg6, arg7, arg8);
    uvVtx(arg0 + arg2, arg1, 0, 0, 0, arg5, arg6, arg7, arg8);
    uvVtx(arg0 + arg2, arg1 + arg4, 0, 0, 0, arg5, arg6, arg7, arg8);
    uvVtx(arg0, arg1 + arg4, 0, 0, 0, arg5, arg6, arg7, arg8);
    uvVtxEndPoly();

    uvVtxBeginPoly();
    uvVtx(arg0, arg1, 0, 0, 0, arg5, arg6, arg7, arg8);
    uvVtx(arg0 + arg4, arg1, 0, 0, 0, arg5, arg6, arg7, arg8);
    uvVtx(arg0 + arg4, arg1 + arg3, 0, 0, 0, arg5, arg6, arg7, arg8);
    uvVtx(arg0, arg1 + arg3, 0, 0, 0, arg5, arg6, arg7, arg8);
    uvVtxEndPoly();

    uvVtxBeginPoly();
    uvVtx(arg0, arg1 + arg3 - arg4, 0, 0, 0, arg5, arg6, arg7, arg8);
    uvVtx(arg0 + arg2, arg1 + arg3 - arg4, 0, 0, 0, arg5, arg6, arg7, arg8);
    uvVtx(arg0 + arg2, arg1 + arg3, 0, 0, 0, arg5, arg6, arg7, arg8);
    uvVtx(arg0, arg1 + arg3, 0, 0, 0, arg5, arg6, arg7, arg8);
    uvVtxEndPoly();

    if (1) { // fakematch
        uvVtxBeginPoly();
        uvVtx(arg0 + arg2 - arg4, arg1, 0, 0, 0, arg5, arg6, arg7, arg8);
        uvVtx(arg0 + arg2, arg1, 0, 0, 0, arg5, arg6, arg7, arg8);
        uvVtx(arg0 + arg2, arg1 + arg3, 0, 0, 0, arg5, arg6, arg7, arg8);
        uvVtx(arg0 + arg2 - arg4, arg1 + arg3, 0, 0, 0, arg5, arg6, arg7, arg8);
        uvVtxEndPoly();
    }
}

void func_8031E9F8(void) {
    char buf[12];
    (void)func_8033F618();
    uvFontSet(8);
    uvFont_8021956C(0xFF, 0xFF, 0xFF, 0xFF);
    uvFont_80219550(1.0, 1.0);
    func_8022DA9C(buf, "%d", func_8033F618());
    uvFont_80219ACC(0xA0, 0x1E, buf);
    uvSprtProps(0xA, 2, 0x96, 0x1C, 7, 0xFF, 0xFF, 0xFF, 0xFF, 0);
    uvSprtDraw(0xA);
}

void func_8031EABC(u8 arg0) {
    D_8036D220 = arg0;
}
