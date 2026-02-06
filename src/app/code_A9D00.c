#include "common.h"
#include <uv_controller.h>
#include <uv_memory.h>
#include <uv_util.h>
#include "code_9A960.h"
#include "code_A7F20.h"
#include "code_A9D00.h"

typedef struct {
    f32 unk0;
    u32 unk4;
} Unk8036DA30_Unk4;

typedef struct Unk8036DA30 {
    struct Unk8036DA30* unk0;
    Unk8036DA30_Unk4 unk4[0x708];
} Unk8036DA30;

extern f32 D_8036DA34;
extern s32 D_8034FAD0;
extern Unk8036DA30* D_8036DA30;
extern f32 D_8036DA34;
extern f32 D_8036DA38;
extern s32 D_8036DA3C;
extern s32 D_8036DA40;
extern s32 D_8036DA44;
extern s32 D_8036DA48;
extern s32 D_8036DA50;
extern s32 D_8036DA58;
extern s32 D_8036DA5C;
extern s32 D_8036DA60;


f32 func_803227D0(Unk8036DA30_Unk4* arg0) {
    return (f32) (((f32)((arg0->unk4 & 0xFF000000) >> 24) / 127.0) - 1.0);
}

f32 func_80322828(Unk8036DA30_Unk4* arg0) {
    return (f32) (((f32)((arg0->unk4 & 0x00FF0000) >> 16) / 127.0) - 1.0);
}

u32 func_80322880(Unk8036DA30_Unk4* arg0) {
    return arg0->unk4 & 0x0000FFFF;
}

void func_80322890(Unk8036DA30_Unk4* arg0, f32 arg1, f32 arg2, u32 arg3) {
    arg0->unk4 = (u32) (((u32) ((arg1 + 1.0) * 127.0) << 0x18) | ((u32) ((1.0 + arg2) * 127.0) << 0x10) | arg3);
}

s32 func_803229EC(s32, s32);
#pragma GLOBAL_ASM("asm/nonmatchings/app/code_A9D00/func_803229EC.s")

s32 func_80322B60(void) {
    return D_8036DA58;
}

s32 func_80322B6C(void) {
    return D_8036DA5C;
}

s32 func_80322B78(void) {
    return D_8036DA60;
}

s32 func_80322B84(void) {
    return D_8036DA50;
}

void func_80322B90(void) {
    Unk8036DA30* temp_v0;

    if ((D_8036DA30 == NULL) || (D_8036DA30 != D_8036DA30->unk0)) {
        temp_v0 = (Unk8036DA30*)_uvMemAllocAlign8(sizeof(Unk8036DA30));
        D_8036DA30 = temp_v0;
        D_8036DA30->unk0 = D_8036DA30;
    }
}

void func_80322BE0(void);
#pragma GLOBAL_ASM("asm/nonmatchings/app/code_A9D00/func_80322BE0.s")

void func_80322D60(s32 arg0, s32 arg1) {
    D_8036DA44 = arg0;
    D_8036DA48 = arg1;
    func_80322BE0();
    func_803209F0(func_803229EC(D_8036DA44, D_8036DA48));
}

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_A9D00/func_80322DA8.s")

s32 func_80322EB0(void) {
    return D_8034FAD0;
}

void func_80322EBC(void) {
    if (D_8034FAD0 == 1) {
        _uvDebugPrintf("%.10f(%.10f, %.10f)0x%x\n", D_8034F850 - D_8036DA34, uvControllerGetStick(0, 0), uvControllerGetStick(0, 1), uvControllerGetButton(0));
    }
    if (D_8036DA38 <= D_8034F850) {
        func_80322DA8(0);
    }
}

s32 func_80322F7C(f32 arg0) {
    f32 temp_fv0;
    s32 var_v1;

    var_v1 = 0;
    temp_fv0 = arg0 - D_8036DA34;

    for (var_v1 = 0; var_v1 < ARRAY_COUNT(D_8036DA30->unk4); var_v1++) {
        if (temp_fv0 <= D_8036DA30->unk4[var_v1].unk0) {
            return var_v1;
        }
    }
    return ARRAY_COUNT(D_8036DA30->unk4) - 1;
}

void func_80323020(void) {
    s32 idx;
    if (D_8034FAD0 == 2) {
        if ((D_8036DA30 == NULL) || (D_8036DA30 != D_8036DA30->unk0)) {
            func_80322BE0();
        }
        D_8036DA3C = D_8036DA40;
        idx = func_80322F7C(D_8034F850);
        D_8036DA40 = func_80322880(&D_8036DA30->unk4[idx]);
    }
    uvIOUpdate();
}

f32 func_803230B0(s32 contIdx, s32 axis) {
    s32 idx;
    if (D_8034FAD0 == 2) {
        if ((D_8036DA30 == NULL) || (D_8036DA30 != D_8036DA30->unk0)) {
            func_80322BE0();
        }
        if (axis == 0) {
            idx = func_80322F7C(D_8034F850);
            return func_803227D0(&D_8036DA30->unk4[idx]);
        } else {
            idx = func_80322F7C(D_8034F850);
            return func_80322828(&D_8036DA30->unk4[idx]);
        }
    } else {
        return uvControllerGetStick(contIdx, axis);
    }
}

s32 func_80323164(s32 arg0) {
    if (D_8034FAD0 == 2) {
        return D_8036DA40;
    }
    return uvControllerGetButton(arg0);
}

s32 func_803231A0(s32 arg0, s32 arg1) {
    if (D_8034FAD0 == 2) {
        return arg1 & D_8036DA40;
    }
    return uvControllerButtonCheck(arg0, arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_A9D00/func_803231E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_A9D00/func_80323240.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_A9D00/func_803232A0.s")
