#include <uv_geometry.h>
#include <uv_graphics.h>
#include <uv_level.h>
#include <uv_matrix.h>
#include <uv_util.h>

#include "code_66160.h"
#include "code_9A960.h"

extern s32 D_80359D70;
extern s32 D_80359D7C;

void func_802DEC30(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9, s32 arg10, s32 arg11, s32 arg12,
                   s32 arg13) {
    uvVtxBeginPoly();
    uvVtx(arg0, arg1, 0, 0, 0, arg8, arg9, arg10, 0xFF);
    uvVtx(arg2, arg3, 0, 0, 0, arg8, arg9, arg10, 0xFF);
    uvVtx(arg4, arg5, 0, 0, 0, arg11, arg12, arg13, 0xFF);
    uvVtx(arg6, arg7, 0, 0, 0, arg11, arg12, arg13, 0xFF);
    uvVtxEndPoly();
}

void screenDrawBox(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8 arg4, u8 arg5, u8 arg6, u8 arg7) {
    uvVtxBeginPoly();
    uvVtx(arg0, arg1, 0, 0, 0, arg4, arg5, arg6, arg7);
    uvVtx(arg2, arg1, 0, 0, 0, arg4, arg5, arg6, arg7);
    uvVtx(arg2, arg3, 0, 0, 0, arg4, arg5, arg6, arg7);
    uvVtx(arg0, arg3, 0, 0, 0, arg4, arg5, arg6, arg7);
    uvVtxEndPoly();
}

void func_802DEE44(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9, s32 arg10) {
    s32 temp_s0 = arg0 + arg2;
    s32 temp_s1 = arg1 + arg3;
    s32 temp_s2 = arg0 + arg4;
    s32 temp_s3 = temp_s1 - arg4;
    s32 temp_s4 = temp_s0 - arg4;
    s32 temp_s5 = arg1 + arg4;

    uvGfxStatePush();
    uvGfxSetFlags(GFX_STATE_800000 | 0xFFF);
    uvGfxClearFlags(GFX_STATE_400000 | GFX_STATE_200000 | GFX_STATE_100000);
    func_802DEC30(temp_s0, temp_s1, arg0, temp_s1, temp_s2, temp_s3, temp_s4, temp_s3, arg5, arg6, arg7, arg8, arg9, arg10);
    func_802DEC30(temp_s4, temp_s3, temp_s4, temp_s5, temp_s0, arg1, temp_s0, temp_s1, arg5, arg6, arg7, arg8, arg9, arg10);
    func_802DEC30(temp_s4, temp_s5, temp_s2, temp_s5, arg0, arg1, temp_s0, arg1, arg5, arg6, arg7, arg8, arg9, arg10);
    func_802DEC30(arg0, temp_s1, arg0, arg1, temp_s2, temp_s5, temp_s2, temp_s3, arg5, arg6, arg7, arg8, arg9, arg10);
    uvGfxStatePop();
}

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_66160/screenDrawBox2.s")

void screenDrawBoxSetup(void) {
    Mtx4F sp60;
    Mtx4F sp20;

    uvGfxStatePush();
    uvGfxSetFlags(GFX_STATE_800000);
    uvGfxClearFlags(GFX_STATE_400000 | GFX_STATE_200000);
    uvGfxSetViewport(0, 0, SCREEN_WIDTH, 0, SCREEN_HEIGHT);
    uvMat4SetOrtho(&sp20, 0.0f, SCREEN_WIDTH - 1, 0.0f, SCREEN_HEIGHT - 1);
    uvGfxMtxProjPushF(&sp20);
    uvMat4SetIdentity(&sp60);
    uvGfxMtxViewLoad(&sp60, 1);
}

void func_802DFA18(void) {
    uvGfxMtxViewPop();
    uvGfxStatePop();
}

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_66160/func_802DFA40.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_66160/func_802DFB48.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_66160/db_getgnd.s")

s32* func_802E02EC(void) {
    return &D_80359D70;
}

s32 func_802E02F8(void) {
    return D_80359D7C;
}

typedef struct {
    u16 unk0;
    u16 unk2;
    u16 unk4;
    u16 unk6;
} Unk80225FBC_0x28_UnkC; // size = 0x10

typedef struct {
    s32 unk0;
    u16 unk4;
    u16 unk6;
    Gfx* dlist;
    Unk80225FBC_0x28_UnkC* unkC;
    u16 unk10;
    u16 unk12;
    u16 unk14;
    u16 pad16;
    s32 unk18;
    s32 unk1C;
    s32 unk20;
    s32 unk24;
} Unk80225FBC_0x28;

typedef struct {
    Vtx* vtx;
    u16 vtxCount;
    u16 pad6;
    Unk80225FBC_0x28* unk8;
    u16 unkC;
    u16 padE;
    struct UnkSobjDraw* unk10;
    u16 unk14;
    u16 pad16;
    s32 unk18;
    s32 unk1C;
    s32 unk20;
    s32 unk24;
    f32 unk28;
} ParsedUVCT; // size = 0x28

typedef struct uvUnkTileStruct_Unk0 {
    u8 pad0[0x30];
    f32 unk30;
    f32 unk34;
    f32 unk38;
    u8 pad3C[0x4];
} uvUnkTileStruct_Unk0; // size = 0x40

typedef struct uvUnkTeraStruct {
    f32 unk0;
    f32 unk4;
    u8 pad8[0x4];
    f32 unkC;
    f32 unk10;
    f32 unk14;
} uvUnkTeraStruct; // size = 0x18

typedef struct ParsedUVTR {
    uvUnkTeraStruct unk0;
    u8 unk18;
    u8 unk19;
    f32 unk1C;
    f32 unk20;
    f32 unk24;
    uvUnkTileStruct* unk28;
} ParsedUVTR; // size = 0x2C

ParsedUVTR* uvTerraGetBox(u16);

void db_getstart(Mtx4F* arg0, Vec3F* arg1, u8* arg2, f32* arg3) {
    Vec3F pos;
    Vec3F ang;
    LevelTPAD* sp44;
    LevelTPAD* first;
    ParsedUVTR* sp3C;
    s32 idx;
    u8 temp_v1;

    temp_v1 = levelDataGetTPAD(&sp44);
    if (temp_v1 == 0) {
        _uvDebugPrintf("db_getstart :  no starting pads in task!!!\n");
        sp3C = uvTerraGetBox(D_80362690->unk0[0].unk6);
        uvMat4SetIdentity(arg0);
        arg0->m[3][0] = (sp3C->unk0.unk0 + sp3C->unk0.unkC) * 0.5f;
        arg0->m[3][1] = (sp3C->unk0.unk4 + sp3C->unk0.unk10) * 0.5f;
        arg0->m[3][2] = sp3C->unk0.unk14;
        if (arg2 != NULL) {
            *arg2 = 1;
        }
        if (arg3 != NULL) {
            *arg3 = 0.0f;
        }
    } else {
        if (temp_v1 > 1) {
            _uvDebugPrintf("db_getstart : too many starting pad! picking first\n");
        }
        first = &sp44[0];
        pos.x = first->pos.x;
        pos.y = first->pos.y;
        pos.z = first->pos.z;
        ang.x = first->angle.x;
        ang.y = first->angle.y;
        ang.z = first->angle.z;
        func_80313640(pos.x, pos.y, pos.z, ang.x * 0.0174533f, ang.y * 0.0174533f, ang.z * 0.0174533f, arg0); // DEG_TO_RAD(1)
        arg1->x = first->unk1C.x;
        arg1->y = first->unk1C.y;
        arg1->z = first->unk1C.z;
        if (arg2 != NULL) {
            *arg2 = first->unk28;
        }
        if (arg3 != NULL) {
            *arg3 = first->unk2C;
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_66160/func_802E0484.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_66160/func_802E05CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_66160/func_802E06AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_66160/func_802E07D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_66160/func_802E08F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_66160/func_802E0C30.s")
