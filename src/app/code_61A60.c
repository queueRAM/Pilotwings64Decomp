#include "common.h"
#include <uv_dobj.h>
#include <uv_event.h>
#include <uv_level.h>
#include <uv_math.h>
#include <uv_vector.h>
#include "code_61A60.h"
#include "code_69BF0.h"
#include "code_72B70.h"
#include "code_9A960.h"
#include "code_B3A70.h"
#include "code_D2B10.h"
#include "hud.h"

s32 D_8034EA40 = 0;
u16 D_8034EA44 = 0xFFFF;
s32 D_8034EA48 = 0;

// This struct should be used for Unk8034EA4C */
typedef struct {
    Vec3F unk0;
    f32 unkC;
    f32 unk10;
    f32 unk14;
} Unk8034EA4C;
Unk8034EA4C D_8034EA4C = {
    { -68.08f, -302.14f, 10.74f },
    -0.0174533f, 0.1f, 0.0f
};

s32 D_8034EA64[] = { 0, 3, 1, 4, 2, 5 };
s32 D_8034EA7C[] = { 0x35, 0x14C, 0x9C, 0x1A7, 0x85, 0x128 };
s32 D_8034EA94[] = { 2, 2, 2, 2, 2, 2 };
Unk803599D0 D_8034EAAC = { 8, 0.36f, 0.0f, 0.412f, 0.1f, 0.465f, 0.25f, 0.517f, 0.475f, 0.568f, 0.5f, 0.62f, 0.475f, 0.673f, 0.25f, 0.725f, 0.0f, 0, 0, 0, 0 };

// .bss
extern f32 D_80359C40;
extern s32 D_80359C44;
extern Mtx4F D_80359C48;
extern f32 D_80359C88;

// forward declarations
void func_802DA6E0(Unk80362690*, s32);
void func_802DA9E0(void);
s32 func_802DAA34(void);
void func_802DAB18(Unk802D3658_Arg0*);
s32 func_802DB38C(Unk802D3658_Unk1228*, Vec3F*, Vec3F*);
s32 func_802DB6D4(Unk802D3658_Unk1228*, Vec3F*, Vec3F*);
s32 func_802DB9B8(Unk802D3658_Unk1228*, Vec3F*, Vec3F*);
s32 func_802DBCB0(Unk802D3658_Unk1228*, Vec3F*, Vec3F*);

s32 func_802DA530(void) {
    return D_8034EA64[D_8034EA40];
}

void func_802DA54C(void) {
    D_8034EA40++;
    if (D_8034EA40 >= 6) {
        D_8034EA40 = 0;
    }
}

s32 func_802DA574(Unk80362690* arg0) {
    s32 sp24;
    Unk80362690_Unk0_UnkC* temp_s0;

    temp_s0 = &arg0->unk0[arg0->unk9C].unkC;
    func_802DA6E0(arg0, D_8034EA64[D_8034EA40]);
    while ((sp24 = func_802DAA34()) == 8) {
        uvGfxBegin();
        func_802DAB18(temp_s0->unk70);
        uvGfxEnd();
    }
    func_8032D51C(0);
    func_802DA9E0();
    return sp24;
}

s32 func_802DA628(u32 arg0) {
    switch (arg0) {
    case 0:
        return 0x55;
    case 1:
        return 0x56;
    case 2:
        return 0x57;
    case 3:
        return 0x58;
    case 4:
        return 0x59;
    case 5:
        return 0x5A;
    default:
        return 0;
    }
}

s32 func_802DA684(u32 arg0) {
    switch (arg0) {
    case 0:
        return 0x15A;
    case 1:
        return 0x15B;
    case 2:
        return 0x15C;
    case 3:
        return 0x15D;
    case 4:
        return 0x15E;
    case 5:
        return 0x15F;
    default:
        return 0;
    }
}

void func_802DA6E0(Unk80362690* arg0, s32 arg1) {
    Unk802D3658_Arg0* temp_s0;

    temp_s0 = arg0->unk0[arg0->unk9C].unkC.unk70;
    D_8034EA48 = 0;
    D_80359C88 = 0.0f;
    func_802E26C0();
    arg0->unk0[0].map = 1;
    arg0->unk0[0].unk6 = 0;
    arg0->unk0[0].unk8 = (u16)D_8034EA94[D_8034EA40];
    levelLoad(1, arg1, 0, 1);
    uvLevelAppend(func_802DA628(arg1));
    func_80204BD4(temp_s0->unk22C, 1, 1.0f);
    func_80204A8C(temp_s0->unk22C, 3);
    uvChanTerra(temp_s0->unk22C, arg0->unk0[0].unk6);
    uvLevelAppend(func_802DA628(arg1));
    uvChanEnv(temp_s0->unk22C, arg0->unk0[0].unk8);
    func_8034B5E0(temp_s0->unk22C, temp_s0);
    func_80204A8C(temp_s0->unk22C, 3);
    uvMat4SetIdentity(&temp_s0->unk108);
    uvMat4RotateAxis(&temp_s0->unk108, D_8034EA4C.unkC, 'z');
    uvMat4RotateAxis(&temp_s0->unk108, D_8034EA4C.unk10, 'x');
    uvMat4RotateAxis(&temp_s0->unk108, D_8034EA4C.unk14, 'y');
    temp_s0->unk108.m[3][0] = D_8034EA4C.unk0.x;
    temp_s0->unk108.m[3][1] = D_8034EA4C.unk0.y;
    temp_s0->unk108.m[3][2] = D_8034EA4C.unk0.z;
    func_80204B34(temp_s0->unk22C, &temp_s0->unk108);
    D_8034EA44 = uvDobjAllocIdx();
    uvDobjModel(D_8034EA44, func_802DA684((u32)arg1));
    uvMat4SetIdentity(&D_80359C48);
    if (arg1 != 3) {
        uvMat4RotateAxis(&D_80359C48, 0.2f, 'z');
    }
    uvMat4RotateAxis(&D_80359C48, 0.2f, 'x');
    uvMat4RotateAxis(&D_80359C48, 0.0f, 'y');
    D_80359C48.m[3][0] = 0.0f;
    D_80359C48.m[3][1] = 5.0f;
    D_80359C48.m[3][2] = -1.2f;
    uvMat4MulBA(&D_80359C48, &temp_s0->unk108, &D_80359C48);
    uvDobjPosm(D_8034EA44, 0, &D_80359C48);
    hudGetState()->renderFlags = 0;
    switch (arg1) {
    case 0:
        D_80359C44 = 0x6D;
        break;
    case 1:
        D_80359C44 = 0x6E;
        break;
    case 2:
        D_80359C44 = 0x6F;
        break;
    case 3:
        D_80359C44 = 0x70;
        break;
    case 4:
        D_80359C44 = 0x71;
        break;
    case 5:
        D_80359C44 = 0x72;
        break;
    default:
        D_80359C44 = 0x6D;
        break;
    }
    D_80359C40 = 0.0f;
}

void func_802DA9E0(void) {
    uvEventPost(0xD, 0);
    uvDobjModel(D_8034EA44, 0xFFFF);
    D_8034EA44 = 0xFFFF;
    level_8030BA60();
    uvLevelInit();
    func_802EBBB8();
}

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_61A60/func_802DAA34.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_61A60/func_802DAB18.s")

s32 func_802DB050(Unk802D3658_Unk111C* arg0, Unk802D3658_Unk1224* arg1, u16 arg2, u8 arg3, Mtx4F* arg4) {
    Unk802D3658_Unk1120* var_s5;
    Vec3F* var_s4;
    s32 i;
    Unk802D3658_Unk1228* temp_s0;

    if ((arg2 != 0xFFFF) && (arg3 & 1)) {
        uvDobjState(arg2, arg3 - 1);
    }
    arg1->unk0 = 0;
    for (i = 0; i < arg0->unk0; i++) {
        var_s5 = &arg0->unk4[i];
        if (var_s5->unk0 != 0) {
            uvMat4LocalToWorld(arg4, &var_s5->unk4, &var_s5->unk1C);
            uvMat4LocalToWorld(arg4, &var_s5->unk10, &var_s5->unk28);
        }
        var_s4 = &var_s5->unk4;
        temp_s0 = &arg1->unk4[arg1->unk0];
        if (func_802DB6D4(temp_s0, &var_s5->unk10, var_s4) != 0) {
            temp_s0->unk0 = i;
            arg1->unk0++;
        } else if (func_802DB9B8(temp_s0, &var_s5->unk10, var_s4) != 0) {
            temp_s0->unk0 = i;
            arg1->unk0++;
        } else if (func_802DB38C(temp_s0, &var_s5->unk10, var_s4) != 0) {
            temp_s0->unk0 = i;
            arg1->unk0++;
        } else if (func_802DBCB0(temp_s0, &var_s5->unk10, var_s4) != 0) {
            temp_s0->unk0 = i;
            arg1->unk0++;
        }
    }
    if (arg2 != 0xFFFF) {
        uvDobjState(arg2, (s32)arg3);
    }
    return arg1->unk0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_61A60/func_802DB224.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_61A60/func_802DB38C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_61A60/func_802DB6D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_61A60/func_802DB9B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_61A60/func_802DBCB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_61A60/func_802DBE10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_61A60/func_802DBE64.s")

s32 func_802DBF10(Unk802D3658_Unk111C* arg0, Unk802D3658_Unk1224* arg1, Vec3F* arg2, Vec3F* arg3) {
    s32 pad[8];
    s32 ret;
    Unk802D3658_Unk1228* unk4;
    Vec3F* temp_v0;
    Vec3F* temp_v1;
    f32 temp_fa1;
    f32 temp_fs0;
    f32 temp_fs1;
    f32 temp_fs2;
    f32 temp_ft4;
    f32 temp_fv0;
    f32 curLen;
    f32 emp_fv1;
    f32 minLen;
    s32 i;

    minLen = 1000000.0f;

    for (i = 0; i < arg1->unk0; i++) {
        unk4 = &arg1->unk4[i];
        temp_fv0 = unk4->unk18;
        temp_v0 = &arg0->unk4[unk4->unk0].unk10;
        temp_v1 = &arg0->unk4[unk4->unk0].unk4;
        temp_fs0 = temp_v0->x + ((temp_v1->x - temp_v0->x) * temp_fv0);
        temp_fs1 = temp_v0->y + ((temp_v1->y - temp_v0->y) * temp_fv0);
        temp_fs2 = temp_v0->z + ((temp_v1->z - temp_v0->z) * temp_fv0);
        curLen = uvSqrtF(SQ(temp_fs0) + SQ(temp_fs1) + SQ(temp_fs2));
        if (curLen < minLen) {
            ret = i;
            arg2->x = temp_fs0;
            arg2->y = temp_fs1;
            arg2->z = temp_fs2;
            minLen = curLen;
            arg3->x = unk4->unk1C.x;
            arg3->y = unk4->unk1C.y;
            arg3->z = unk4->unk1C.z;
        }
    }
    return ret;
}

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_61A60/func_802DC074.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_61A60/func_802DC1DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_61A60/func_802DC380.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_61A60/func_802DC784.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_61A60/func_802DC814.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_61A60/func_802DC8E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_61A60/func_802DC930.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_61A60/func_802DC97C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_61A60/func_802DCA00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_61A60/func_802DCA5C.s")
