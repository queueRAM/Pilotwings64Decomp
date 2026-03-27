#include "common.h"
#include <uv_dobj.h>
#include "code_78620.h"
#include "proxanim.h"

typedef struct {
    s32 objId;
    f32 pathAngle;
    f32 unk8;
    Vec3F unkC;
    f32 unk18;
    s32 proxId;
    u8 pad20[4];
} Unk80368010; // size = 0x24

extern Unk80368010 D_80368010[4];

void func_802F10F0(s32);
#pragma GLOBAL_ASM("asm/nonmatchings/app/code_78620/func_802F10F0.s")

s32 func_802F11F8(s32, s32, s32);
#pragma GLOBAL_ASM("asm/nonmatchings/app/code_78620/func_802F11F8.s")

s32 func_802F12BC(s32, s32, s32);
#pragma GLOBAL_ASM("asm/nonmatchings/app/code_78620/func_802F12BC.s")

s32 func_802F13C0(s32);
#pragma GLOBAL_ASM("asm/nonmatchings/app/code_78620/func_802F13C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_78620/func_802F15C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_78620/func_802F182C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_78620/func_802F1AE8.s")

void func_802F1D3C(void) {
    Unk80368010* glider;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(D_80368010); i++) {
        D_80368010[i].objId = 0xFFFF;
    }

    for (i = 0; i < ARRAY_COUNT(D_80368010) - 1; i++) {
        glider = &D_80368010[i];
        glider->objId = uvDobjAllocIdx();
        if (glider->objId != 0xFFFF) {
            switch (i) {
            case 0:
                glider->unk8 = 7.0f;
                uvDobjModel(glider->objId, func_802F13C0(0));
                uvDobjState(glider->objId, 2);
                glider->unk18 = 250.0f;
                glider->unkC.x = 80.03f;
                glider->unkC.y = -162.16f;
                glider->unkC.z = 600.0f;
                break;
            case 1:
                glider->unk8 = 17.0f;
                uvDobjModel(glider->objId, func_802F13C0(1));
                uvDobjState(glider->objId, 2);
                glider->unk18 = 70.0f;
                glider->unkC.x = 745.26f;
                glider->unkC.y = 1107.29f;
                glider->unkC.z = 150.0f;
                break;
            case 2:
                glider->unk8 = 17.0f;
                uvDobjModel(glider->objId, func_802F13C0(2));
                uvDobjState(glider->objId, 2);
                glider->unk18 = 100.0f;
                glider->unkC.x = 800.26f;
                glider->unkC.y = 1107.29f;
                glider->unkC.z = 170.0f;
                break;
            }
            glider->proxId = func_80321210(func_802F12BC, func_802F11F8, glider->unkC, 2500.0f, 0.0f, i);
            func_802F10F0(i);
        }
    }
}

#ifndef NON_MATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/app/code_78620/func_802F1FA0.s")
#else
// works when D_80368010 is mapped in .bss
void func_802F1FA0(void) {
    Unk80368010* glider;
    s32 i;
    for (i = 0; i < ARRAY_COUNT(D_80368010); i++) {
        glider = &D_80368010[i];
        glider->pathAngle = 0.0f;
        glider->objId = 0xFFFF;
    }
}
#endif

void func_802F1FF0(void) {
    Unk80368010* glider;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(D_80368010); i++) {
        glider = &D_80368010[i];
        if (glider->objId != 0xFFFF) {
            uvDobjModel(glider->objId, 0xFFFF);
            glider->objId = 0xFFFF;
            func_803212DC(glider->proxId);
        }
    }
}

void func_802F205C(s32 idx, s32* objId, f32* interval, Vec3F* pos) {
    Mtx4F pose;
    Unk80368010* glider;

    glider = &D_80368010[idx];
    if (glider->objId != 0xFFFF) {
        *objId = glider->objId;
        *interval = glider->pathAngle / 360.0f;
        uvDobjGetPosm(*objId, 0, &pose);
        pos->x = pose.m[3][0];
        pos->y = pose.m[3][1];
        pos->z = pose.m[3][2];
    } else {
        *objId = 0xFFFF;
        *interval = 0.0f;
        pos->x = 0.0f;
        pos->y = 0.0f;
        pos->z = 0.0f;
    }
}

void func_802F2110(s32 idx, f32 interval) {
    if (D_80368010[idx].objId != 0xFFFF) {
        uvDobjState(D_80368010[idx].objId, 2);
        D_80368010[idx].pathAngle = interval * 360.0f;
        func_802F10F0(idx);
    }
}
