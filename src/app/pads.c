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
} Unk8036C168; // size = 0x18

typedef struct {
    u16 objId;
    u8 radarIdx;
    u8 pad3[1];
    Mtx4F pose;
    f32 deltaZ;
} CannonTarget; // size = 0x48

typedef struct {
    Vec3F pos;
} TakeoffPad; // size = 0xC

extern TaskLPAD* gRefLPAD;
extern TaskLSTP* gRefLSTP;
extern TaskTPAD* gRefTPAD;
extern TaskCNTG* gRefCNTG;
extern LevelLPAD* gRefPotLPAD;

extern Unk8036C168 D_8036C168[]; // written to, but unused
extern u8 gPotLandPadCount;
extern u8 gTakeoffPadCount;
extern u8 gCannonTargetCount;

extern TakeoffPad gTakeoffPads[3];
extern CannonTarget gCannonTargets[1];
extern u16 gLandingPadObjIds[/* count likely 14, but 0x28 byte are allocated */];

s8 gPadsInitialized = FALSE;
u16 gLandingPadModels[] = { MODEL_LANDING_PAD_1, MODEL_LANDING_PAD_2, MODEL_LANDING_PAD_3, 0x0000, 0x0000, 0x0000 };

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
    LandingPad* landPad;
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
    f32 width;
    f32 length;
    f32 height;
    TaskCNTG* cntg;
    CannonTarget* cannonTarg;
    s32 pad0;
    Mtx4F pose;
    f32 diag;

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
        landPad = &gLandingPads[i];
        uvVec3Copy(&landPad->pos, &lpad->pos);
        landPad->type = lpad->type;
    }

    for (i = 0; i < gLandingPadCount; i++) {
        landPad = &gLandingPads[i];
        minVal = 100.0f;
        minIdx = -1;
        for (j = 0; j < gPotLandPadCount; j++) {
            width = landPad->pos.x - gRefPotLPAD[j].pos.x;
            length = landPad->pos.y - gRefPotLPAD[j].pos.y;
            height = landPad->pos.z - gRefPotLPAD[j].pos.z;
            diag = uvLength3D(width, length, height);
            if ((diag < minVal) && (gRefPotLPAD[j].unk10 == 0)) {
                minVal = diag;
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
            gRefPotLPAD[minIdx].type = gLandingPads[i].type;
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
        uvVec3Copy(&landstrip->pos0, &lstp->pos);
        uvVec3Copy(&landstrip->pos1, &lstp->unkC);
        landstrip->midpoint.x = (landstrip->pos0.x + landstrip->pos1.x) * 0.5f;
        landstrip->midpoint.y = (landstrip->pos0.y + landstrip->pos1.y) * 0.5f;
        landstrip->midpoint.z = (landstrip->pos0.z + landstrip->pos1.z) * 0.5f;
        width = landstrip->pos1.x - landstrip->pos0.x;
        length = landstrip->pos1.y - landstrip->pos0.y;
        height = landstrip->pos1.z - landstrip->pos0.z;
        diag = uvSqrtF(SQ(width) + SQ(length) + SQ(height));
        landstrip->normal.x = width / diag;
        landstrip->normal.y = length / diag;
        landstrip->normal.z = height / diag;
        landstrip->unk30 = 0.5f * diag;
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
        uvMat4SetIdentity(&pose);
        gLandingPadObjIds[i] = uvDobjAllocIdx();
        if (gRefPotLPAD[i].unk10 != 0) {
            uvDobjModel(gLandingPadObjIds[i], gLandingPadModels[gRefPotLPAD[i].type]);
        } else {
            uvDobjModel(gLandingPadObjIds[i], MODEL_LANDING_PAD_NOTARGET);
        }
        func_80313640(gRefPotLPAD[i].pos.x, gRefPotLPAD[i].pos.y, gRefPotLPAD[i].pos.z, gRefPotLPAD[i].angle, 0.0f, 0.0f, &pose);
        uvDobjPosm(gLandingPadObjIds[i], 0, &pose);
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
            cannonTarg = &gCannonTargets[i];
            cannonTarg->objId = uvDobjAllocIdx();
            cannonTarg->radarIdx = hudAddWaypoint(cntg->pos.x, cntg->pos.y, cntg->pos.z);
            switch (cntg->type) {
            case 0:
                uvDobjModel(cannonTarg->objId, MODEL_CANNONB_TARGET_2);
                cannonTarg->deltaZ = 35.0f;
                break;
            case 1:
                uvDobjModel(cannonTarg->objId, MODEL_CANNONB_TARGET_3);
                cannonTarg->deltaZ = 42.5f;
                break;
            case 2:
                uvDobjModel(cannonTarg->objId, MODEL_CANNONB_TARGET_4);
                cannonTarg->deltaZ = 50.0f;
                break;
            default:
                _uvDebugPrintf("pads : unknown cannon target type [%d]\n", cntg->type);
                uvDobjModel(cannonTarg->objId, MODEL_CANNONB_TARGET_4);
                cannonTarg->deltaZ = 50.0f;
                break;
            }
            func_80313640(cntg->pos.x, cntg->pos.y, cntg->pos.z, cntg->angle.x * 0.01745329f, cntg->angle.y * 0.01745329f, cntg->angle.z * 0.01745329f,
                          &cannonTarg->pose);
            uvDobjPosm(cannonTarg->objId, 0, &cannonTarg->pose);
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
    CannonTarget* cannonTarg;
    s32 i;

    for (i = 0; i < gPotLandPadCount; i++) {
        if (gLandingPadObjIds[i] != 0xFFFF) {
            uvDobjModel(gLandingPadObjIds[i], 0xFFFF);
            gLandingPadObjIds[i] = 0xFFFF;
        }
    }

    gPadsInitialized = FALSE;
    for (i = 0; i < gCannonTargetCount; i++) {
        cannonTarg = &gCannonTargets[i];
        if (cannonTarg->objId != 0xFFFF) {
            hud_8031A8E0(cannonTarg->radarIdx);
            uvDobjModel(cannonTarg->objId, 0xFFFF);
            cannonTarg->objId = 0xFFFF;
        }
    }
}

void func_80317854(void) {
    s32 i;
    Mtx4F sp5C;

    for (i = 0; i < gPotLandPadCount; i++) {
        if (gRefPotLPAD[i].unk10 != 0) {
            uvDobjModel(gLandingPadObjIds[i], MODEL_LANDING_PAD_NOTARGET);
        }
        uvMat4SetIdentity(&sp5C);
        func_80313640(gRefPotLPAD[i].pos.x, gRefPotLPAD[i].pos.y, gRefPotLPAD[i].pos.z, gRefPotLPAD[i].angle, 0.0f, 0.0f, &sp5C);
        uvDobjPosm(gLandingPadObjIds[i], 0, &sp5C);
        gRefPotLPAD[i].unk10 = 0;
        gPadsInitialized = TRUE;
    }
}

f32 func_80317978(f32 x, f32 y, f32 arg2, u8* arg3) {
    LandingPad* landPad;
    LandingStrip* lstrip;
    f32 dx;
    f32 dist;
    f32 dy;
    f32 minDist;
    s32 i;

    minDist = 1000000.0f;

    for (i = 0; i < gLandingPadCount; i++) {
        landPad = &gLandingPads[i];
        if (landPad->unk14 != 0) {
            dx = landPad->pos.x - x;
            dy = landPad->pos.y - y;
            dist = uvSqrtF(SQ(dx) + SQ(dy));
            if (dist < minDist) {
                minDist = dist;
            }
            if (dist < landPad->unk10) {
                *arg3 = i + 1;
            }
        }
    }

    for (i = 0; i < gLandingStripCount; i++) {
        lstrip = &gLandingStrips[i];
        if (lstrip->unk38 != 0) {
            dx = lstrip->midpoint.x - x;
            dy = lstrip->midpoint.y - y;
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

f32 func_80317B50(f32 x, f32 y, f32 z, u16 targetObjId) {
    Mtx4F sp48;
    Vec3F sp3C;
    Vec3F sp30;
    s32 i;
    s32 pad;

    for (i = 0; i < gCannonTargetCount; i++) {
        if (targetObjId == gCannonTargets[i].objId) {
            break;
        }
    }
    if (i == gCannonTargetCount) {
        return 1000.0f;
    }

    sp30.x = x;
    sp30.y = y;
    sp30.z = z;
    uvMat4InvertTranslationRotation(&sp48, &gCannonTargets[i].pose);
    uvMat4LocalToWorld(&sp48, &sp3C, &sp30);
    sp3C.y = 0.0f;
    sp3C.z -= gCannonTargets[i].deltaZ;
    return uvVec3Len(&sp3C);
}

f32 func_80317C2C(f32 x, f32 y, f32 z, LandingStrip* lstrip) {
    f32 nx, ny, nz;
    f32 dx, dy, dz;
    f32 tx, ty, tz;
    f32 sum;
    f32 ret;

    nx = lstrip->normal.x;
    ny = lstrip->normal.y;
    nz = lstrip->normal.z;
    dx = (x - lstrip->pos0.x);
    dy = (y - lstrip->pos0.y);
    dz = (z - lstrip->pos0.z);
    sum = nx * dx + ny * dy + nz * dz;
    if (sum < 0.0f) {
        return 1000000.0f;
    }

    nx = -nx;
    ny = -ny;
    nz = -nz;
    dx = (x - lstrip->pos1.x);
    dy = (y - lstrip->pos1.y);
    dz = (z - lstrip->pos1.z);
    sum = nx * dx + ny * dy + nz * dz;
    if (sum < 0.0f) {
        return 1000000.0f;
    }

    tx = (lstrip->pos1.x + (nx * sum)) - x;
    ty = (lstrip->pos1.y + (ny * sum)) - y;
    tz = (lstrip->pos1.z + (nz * sum)) - z;
    ret = uvSqrtF(SQ(tx) + SQ(ty) + SQ(tz));
    return ret;
}
