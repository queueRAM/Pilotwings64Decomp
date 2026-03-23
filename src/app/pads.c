#include "common.h"
#include <uv_dobj.h>
#include <uv_math.h>
#include <uv_matrix.h>
#include <uv_texture.h>
#include <uv_vector.h>
#include "code_9A960.h"
#include "code_B2900.h"
#include "hud.h"
#include "level.h"
#include "macros.h"
#include "pads.h"
#include "task.h"

typedef struct {
    u8 pad0[0x10];
    s32 unk10;
    u8 pad14[4];
} Unk8036C168;

typedef struct {
    u16 objId;
    u8 unk2;
    u8 pad3[1];
    Mtx4F unk4;
    f32 unk44;
} CannonTarget; // size = 0x48

typedef struct {
    Vec3F pos;
} TakeoffPad; // size = 0xC

extern TaskLPAD* gRefLPAD;
extern TaskLSTP* gRefLSTP;
extern TaskTPAD* gRefTPAD;
extern TaskCNTG* gRefCNTG;
extern LevelLPAD* gRefPotLPAD;

extern Unk8036C168 D_8036C168[];
extern u8 gPotLandPadCount;
extern u8 gTakeoffPadCount;
extern u8 gCannonTargetCount;

extern TakeoffPad gTakeoffPads[3];
extern CannonTarget gCannonTargets[1];
extern u16 D_8036C4F8[];

s8 D_8034F900 = 0;
u16 D_8034F904[] = { 0x0102, 0x0103, 0x0104, 0x0000, 0x0000, 0x0000 };

// forward declarations
f32 func_80317C2C(f32, f32, f32, LandingStrip*);

void padsInit(void) {
    Unk8036C168* var_a0;
    LandingPad* pad;
    LandingStrip* strip;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(gLandingPads); i++) {
        gLandingPads[i].unk15 = 0;
        gLandingPads[i].unk14 = 0;
        D_8036C168[i].unk10 = 0;
    }
    for (i = 0; i < ARRAY_COUNT(gLandingStrips); i++) {
        gLandingStrips[i].unk39 = 0;
        gLandingStrips[i].unk38 = 0;
    }
    gLandingStripCount = 0;
    gLandingPadCount = 0;
    gPotLandPadCount = 0;
    gTakeoffPadCount = 0;
    gCannonTargetCount = 0;
}

void padsLoad(void) {
    LandingPad* landpad;
    LandingStrip* landstrip;
    TaskLSTP* lstp;
    s32 pad1;
    LevelLPAD* plpad;
    TaskLPAD* lpad;
    f32 minVal;
    s32 var_s0;
    s32 j;
    s32 minIdx;
    s32 i;
    f32 dx;
    f32 dy;
    f32 dz;
    TaskCNTG* cntg;
    CannonTarget* cannontgt;
    s32 pad0;
    Mtx4F spA4;
    f32 temp_fv0;

    gPotLandPadCount = levelGetLPAD(&gRefPotLPAD);
    if (gPotLandPadCount > ARRAY_COUNT(gLandingPads)) {
        _uvDebugPrintf("pads : too many potential landing pads defined in level [%d]\n", gPotLandPadCount);
        gPotLandPadCount = 0;
        return;
    }

    gLandingPadCount = taskGetLPAD(&gRefLPAD);
    if (gLandingPadCount > ARRAY_COUNT(gLandingPads)) {
        _uvDebugPrintf("pads : too many landing pads defined in level [%d]\n", gLandingPadCount);
        gLandingPadCount = 0;
        return;
    }

    for (i = 0; i < gLandingPadCount; i++) {
        lpad = &gRefLPAD[i];
        landpad = &gLandingPads[i];
        uvVec3Copy(&landpad->pos, &lpad->pos);
        landpad->unk17 = lpad->unk2C;
    }

    for (i = 0; i < gLandingPadCount; i++) {
        landpad = &gLandingPads[i];
        minVal = 100.0f;
        minIdx = -1;
        for (j = 0; j < gPotLandPadCount; j++) {
            dx = landpad->pos.x - gRefPotLPAD[j].pos.x;
            dy = landpad->pos.y - gRefPotLPAD[j].pos.y;
            dz = landpad->pos.z - gRefPotLPAD[j].pos.z;
            temp_fv0 = uvLength3D(dx, dy, dz);
            if ((temp_fv0 < minVal) && (gRefPotLPAD[j].unk10 == 0)) {
                minVal = temp_fv0;
                minIdx = j;
            }
        }
        if ((minIdx != -1) && (D_80362690->unkC[D_80362690->unk9C].unk7B == 0)) {
            gLandingPads[i].pos.x = gRefPotLPAD[minIdx].pos.x;
            gLandingPads[i].pos.y = gRefPotLPAD[minIdx].pos.y;
            gLandingPads[i].pos.z = gRefPotLPAD[minIdx].pos.z;
            gRefPotLPAD[minIdx].unk10 = 1;
            gLandingPads[i].unk14 = gRefPotLPAD[minIdx].unk10;
            gLandingPads[i].unk10 = 30.0f;
            gLandingPads[i].unk16 = minIdx;
            gRefPotLPAD[minIdx].unk14 = gLandingPads[i].unk17;
        }
    }

    gLandingStripCount = taskGetLSTP(&gRefLSTP);
    if (gLandingStripCount > ARRAY_COUNT(gLandingStrips)) {
        _uvDebugPrintf("pads : too many landing strips defined in level [%d]\n", gLandingStripCount);
        gLandingStripCount = 0;
        return;
    }

    for (i = 0; i < gLandingStripCount; i++) {
        lstp = &gRefLSTP[i];
        landstrip = &gLandingStrips[i];
        landstrip->unk38 = lstp->unk1C;
        uvVec3Copy(&landstrip->pos, &lstp->pos);
        uvVec3Copy(&landstrip->unkC, &lstp->unkC);
        landstrip->dx = (landstrip->pos.x + landstrip->unkC.x) * 0.5f;
        landstrip->dy = (landstrip->pos.y + landstrip->unkC.y) * 0.5f;
        landstrip->dz = (landstrip->pos.z + landstrip->unkC.z) * 0.5f;
        dx = landstrip->unkC.x - landstrip->pos.x;
        dy = landstrip->unkC.y - landstrip->pos.y;
        dz = landstrip->unkC.z - landstrip->pos.z;
        temp_fv0 = uvSqrtF(SQ(dx) + SQ(dy) + SQ(dz));
        landstrip->unk18 = dx / temp_fv0;
        landstrip->unk1C = dy / temp_fv0;
        landstrip->unk20 = dz / temp_fv0;
        landstrip->unk30 = 0.5f * temp_fv0;
        landstrip->unk34 = lstp->unk20;
        landstrip->unk39 = 1;
    }

    gTakeoffPadCount = taskGetTPAD(&gRefTPAD);
    if (gTakeoffPadCount > 3) {
        _uvDebugPrintf("pads : too many takeoff pads defined in level [%d]\n", gTakeoffPadCount);
        gTakeoffPadCount = 0;
        return;
    }

    for (i = 0; i < gTakeoffPadCount; i++) {
        uvVec3Copy(&gTakeoffPads[i].pos, &gRefTPAD[i].pos);
    }

    for (i = 0; i < gPotLandPadCount; i++) {
        plpad = &gRefPotLPAD[i];
        if (plpad->unk10) {
            uvLevelAppend(0x17);
            break;
        }
    }

    for (i = 0; i < gPotLandPadCount; i++) {
        uvMat4SetIdentity(&spA4);
        D_8036C4F8[i] = uvDobjAllocIdx();
        if (gRefPotLPAD[i].unk10 != 0) {
            uvDobjModel(D_8036C4F8[i], D_8034F904[gRefPotLPAD[i].unk14]);
        } else {
            uvDobjModel(D_8036C4F8[i], 0xD4); // no-target landing pad
        }
        func_80313640(gRefPotLPAD[i].pos.x, gRefPotLPAD[i].pos.y, gRefPotLPAD[i].pos.z, gRefPotLPAD[i].unkC, 0.0f, 0.0f, &spA4);
        uvDobjPosm(D_8036C4F8[i], 0, &spA4);
    }

    for (i = 0; i < gLandingPadCount; i++) {
        gLandingPads[i].unk15 = 1;
    }

    for (i = 0; i < gLandingStripCount; i++) {
        gLandingStrips[i].unk39 = 1;
    }

    if (D_80362690->unkC[D_80362690->unk9C].unk7B == 0) {
        gCannonTargetCount = taskGetCNTG(&gRefCNTG);
        if (gCannonTargetCount > 1) {
            _uvDebugPrintf("pads : too many cannon targets defined in level [%d]\n", gCannonTargetCount);
            gCannonTargetCount = 0;
            return;
        }

        if (gCannonTargetCount) {
            uvLevelAppend(0x18);
        }

        for (i = 0; i < gCannonTargetCount; i++) {
            cntg = &gRefCNTG[i];
            cannontgt = &gCannonTargets[i];
            cannontgt->objId = uvDobjAllocIdx();
            cannontgt->unk2 = hudAddWaypoint(cntg->pos.x, cntg->pos.y, cntg->pos.z);
            switch (cntg->unk18) {
            case 0:
                uvDobjModel(cannontgt->objId, MODEL_CANNONB_TARGET_2);
                cannontgt->unk44 = 35.0f;
                break;
            case 1:
                uvDobjModel(cannontgt->objId, MODEL_CANNONB_TARGET_3);
                cannontgt->unk44 = 42.5f;
                break;
            case 2:
                uvDobjModel(cannontgt->objId, MODEL_CANNONB_TARGET_4);
                cannontgt->unk44 = 50.0f;
                break;
            default:
                _uvDebugPrintf("pads : unknown cannon target type [%d]\n", cntg->unk18);
                uvDobjModel(cannontgt->objId, MODEL_CANNONB_TARGET_4);
                cannontgt->unk44 = 50.0f;
                break;
            }
            func_80313640(cntg->pos.x, cntg->pos.y, cntg->pos.z, cntg->unkC * 0.01745329f, cntg->unk10 * 0.01745329f, cntg->unk14 * 0.01745329f,
                          &cannontgt->unk4);
            uvDobjPosm(cannontgt->objId, 0, &cannontgt->unk4);
        }
    }
}

void padsFrameUpdate(Mtx4F* arg0) {
    TakeoffPad* var_s0;
    Unk80364210* temp_v0;
    f32 x;
    f32 y;
    f32 z;
    f32 dist;
    f32 minDist;
    f32 dx, dy, dz;
    s32 i;

    minDist = 1000000.0f;
    x = arg0->m[3][0];
    y = arg0->m[3][1];
    z = arg0->m[3][2];
    temp_v0 = func_8032BE10();
    temp_v0->unk3D = 0;
    if ((gLandingPadCount > 0) || (gLandingStripCount > 0)) {
        temp_v0->unk8 = func_80317978(x, y, z, &temp_v0->unk3D);
    }

    for (i = 0; i < gTakeoffPadCount; i++) {
        var_s0 = &gTakeoffPads[i];
        dx = var_s0->pos.x - x;
        dy = var_s0->pos.y - y;
        dz = var_s0->pos.z - z;
        dist = uvLength3D(dx, dy, dz);
        if (dist < minDist) {
            minDist = dist;
        }
    }
    if (func_8032BE10()->unk4 < minDist) {
        func_8032BE10()->unk4 = minDist;
    }
}

s32 func_80317764(void) {
    return 1;
}

void padsDeinit(void) {
    CannonTarget* canTarg;
    s32 i;

    for (i = 0; i < gPotLandPadCount; i++) {
        if (D_8036C4F8[i] != 0xFFFF) {
            uvDobjModel(D_8036C4F8[i], 0xFFFF);
            D_8036C4F8[i] = 0xFFFF;
        }
    }

    D_8034F900 = 0;
    for (i = 0; i < gCannonTargetCount; i++) {
        canTarg = &gCannonTargets[i];
        if (canTarg->objId != 0xFFFF) {
            hud_8031A8E0(canTarg->unk2);
            uvDobjModel(canTarg->objId, 0xFFFF);
            canTarg->objId = 0xFFFF;
        }
    }
}

void func_80317854(void) {
    s32 i;
    Mtx4F sp5C;

    for (i = 0; i < gPotLandPadCount; i++) {
        if (gRefPotLPAD[i].unk10 != 0) {
            uvDobjModel(D_8036C4F8[i], 0xD4);
        }
        uvMat4SetIdentity(&sp5C);
        func_80313640(gRefPotLPAD[i].pos.x, gRefPotLPAD[i].pos.y, gRefPotLPAD[i].pos.z, gRefPotLPAD[i].unkC, 0.0f, 0.0f, &sp5C);
        uvDobjPosm(D_8036C4F8[i], 0, &sp5C);
        gRefPotLPAD[i].unk10 = 0;
        D_8034F900 = 1;
    }
}

f32 func_80317978(f32 x, f32 y, f32 arg2, u8* arg3) {
    LandingPad* lpad;
    LandingStrip* lstrip;
    f32 dx;
    f32 dist;
    f32 dy;
    f32 minDist;
    s32 i;

    minDist = 1000000.0f;

    for (i = 0; i < gLandingPadCount; i++) {
        lpad = &gLandingPads[i];
        if (lpad->unk14 != 0) {
            dx = lpad->pos.x - x;
            dy = lpad->pos.y - y;
            dist = uvSqrtF(SQ(dx) + SQ(dy));
            if (dist < minDist) {
                minDist = dist;
            }
            if (dist < lpad->unk10) {
                *arg3 = i + 1;
            }
        }
    }

    for (i = 0; i < gLandingStripCount; i++) {
        lstrip = &gLandingStrips[i];
        if (lstrip->unk38 != 0) {
            dx = lstrip->dx - x;
            dy = lstrip->dy - y;
            dist = uvSqrtF((dx * dx) + (dy * dy));
            if (dist <= lstrip->unk30) {
                dist = func_80317C2C(x, y, arg2, lstrip);
                if (dist < (lstrip->unk34 * 0.5f)) {
                    *arg3 = 0xFF;
                }
            }
            if (dist < minDist) {
                minDist = dist;
            }
        }
    }
    return minDist;
}

f32 func_80317B50(f32 arg0, f32 arg1, f32 arg2, u16 arg3) {
    Mtx4F sp48;
    Vec3F sp3C;
    Vec3F sp30;
    s32 i;
    s32 pad;

    for (i = 0; i < gCannonTargetCount; i++) {
        if (arg3 == gCannonTargets[i].objId) {
            break;
        }
    }
    if (i == gCannonTargetCount) {
        return 1000.0f;
    } 

    sp30.x = arg0;
    sp30.y = arg1;
    sp30.z = arg2;
    uvMat4InvertTranslationRotation(&sp48, &gCannonTargets[i].unk4);
    uvMat4LocalToWorld(&sp48, &sp3C, &sp30);
    sp3C.y = 0.0f;
    sp3C.z -= gCannonTargets[i].unk44;
    return uvVec3Len(&sp3C);
}

#pragma GLOBAL_ASM("asm/nonmatchings/app/pads/func_80317C2C.s")
