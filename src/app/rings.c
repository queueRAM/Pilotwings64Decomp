#include "common.h"
#include <uv_dobj.h>
#include <uv_math.h>
#include <uv_matrix.h>
#include <uv_model.h>
#include <uv_string.h>
#include <uv_texture.h>
#include "code_9A960.h"
#include "code_B2900.h"
#include "hud.h"
#include "rings.h"
#include "snd.h"
#include "task.h"
#include "text_data.h"

extern TaskRNGS* gRefRNGS;
extern u8 gRingsCount; // count of rings stored in gRings
// extern Ring gRings[30]; // stored here, exported in header
extern u8 D_80371060[5];

// .data
extern f32 D_8034FAE0[];
extern s32 gRingModelIdLookup[/* likely 2 */][4][5];

// forward declarations
void rings_803234A4(Ring* ring);
void rings_80323720(Ring* ring);
s32 rings_80323FFC(s32 ringIdx);

void ringsInit(void) {
    Ring* var_v1;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(gRings); i++) {
        var_v1 = &gRings[i];
        var_v1->objId = 0xFFFF;
        var_v1->consumedType = 0;
        var_v1->isActive = FALSE;
        var_v1->initialized = FALSE;
        var_v1->timeRemaining = 0.0f;
        var_v1->rotationType1 = 0;
        var_v1->unk1B9 = FALSE;
        var_v1->radarIdx = 0xFF;
    }

    for (i = 0; i < ARRAY_COUNT(D_80371060); i++) {
        D_80371060[i] = 0xFF;
    }
}

void rings_80323364(void) {
    s32 i;

    for (i = 0; i < gRingsCount; i++) {
        if (D_80362690->unkC[D_80362690->unk9C].unk8 == gRefRNGS[i].unk18) {
            gRings[i].unk1B6 = 1;
            if (gRings[i].objId != 0xFFFF) {
                uvDobjSetState(gRings[i].objId, 2);
            }
            if (gRings[i].radarIdx != 0xFF) {
                hud_8031A874(gRings[i].radarIdx);
            }
        } else {
            gRings[i].unk1B6 = 0;
            if (gRings[i].objId != 0xFFFF) {
                uvDobjClearState(gRings[i].objId, 2);
            }
            if (gRings[i].radarIdx != 0xFF) {
                hud_8031A810(gRings[i].radarIdx);
            }
        }
    }
}

// load models, set props
void rings_803234A4(Ring* ring) {
    s32 state;
    s32 modelId;

    ring->objId = uvDobjAllocIdx();
    if (ring->isActive) {
        if (ring->type >= 2) {
            _uvDebugPrintf("rings : Bad ring rtype %d\n", ring->type);
            ring->type = 0;
        }
        if (ring->ringType >= 4) {
            ring->ringType = 1;
        }
        if (ring->size >= 5) {
            _uvDebugPrintf("rings : Bad ring size %d\n", ring->size);
            ring->size = 2;
        }
        if (ring->ringType < 2) {
            modelId = gRingModelIdLookup[ring->type][ring->ringType][ring->size];
            uvDobjModel(ring->objId, modelId);
            if (ring->type2 == 0) {
                uvDobjProps(ring->objId, 5, 4, 0);
            } else {
                uvDobjProps(ring->objId, 5, 1, 0);
            }
            uvModelGetPosm(modelId, (ring->type2 == 0) ? 2 : 5, &ring->posMtx0);
            uvModelGetPosm(modelId, (ring->type2 == 0) ? 3 : 6, &ring->posMtx1);
            uvDobjProps(ring->objId, 5, 2, 0);
            uvDobjProps(ring->objId, 5, 3, 0);
            uvDobjProps(ring->objId, 5, 5, 0);
            uvDobjProps(ring->objId, 5, 6, 0);
        } else if (ring->ringType == 3) {
            uvDobjModel(ring->objId, 0xF1);
        } else {
            ring->objId = 0xFFFF;
        }
    } else {
        switch (ring->ringType) {
        case 0:
            uvDobjModel(ring->objId, 0xEF);
            break;
        case 1:
        case 3:
            uvDobjModel(ring->objId, 0xF0);
            break;
        default:
            ring->objId = 0xFFFF;
        }
    }
    state = (ring->unk1B6 != 0) ? 2 : 0;
    if (ring->objId != 0xFFFF) {
        uvDobjState(ring->objId, state);
        uvDobjPosm(ring->objId, 0, &ring->pose);
    }
}

void rings_80323720(Ring* ring) {
    f32 sp6C;
    f32 sp68;
    Mtx4F sp28;

    if ((ring->timeRemaining != 0) && ring->isActive) {
        sp68 = ring->timeRemaining * 0.31415927f; // DEG_TO_RAD(18)
        sp6C = 0.0f;
        if (sp68 < 0.0f) {
            sp68 = 0.0f;
        } else if (sp68 > 6.2831855f) {
            sp68 = 6.2831855f;
        }
        if (ring->rotAxis1 == 'y') {
            sp6C = 0.0f - ring->rotation1;
            sp68 -= ring->rotation1;
        }
        uvMat4Copy(&sp28, &ring->posMtx0);
        uvMat4RotateAxis(&sp28, sp6C, 'y');
        uvDobjPosm(ring->objId, (ring->type2 == 0) ? 2 : 5, &sp28);
        uvMat4Copy(&sp28, &ring->posMtx1);
        uvMat4RotateAxis(&sp28, sp68, 'y');
        uvDobjPosm(ring->objId, (ring->type2 == 0) ? 3 : 6, &sp28);
    }
}

void rings_80323864(Ring* ring) {
    ring->ringType = 1;
    ring->timeRemaining = ring->timeRingDuration;
    uvDobjModel(ring->objId, 0xFFFF);
    rings_803234A4(ring);
    if (ring->isActive) {
        uvDobjProps(ring->objId, 4, (ring->type2 == 0) ? 2 : 5, 0);
        uvDobjProps(ring->objId, 4, (ring->type2 == 0) ? 3 : 6, 0);
    }
    rings_80323720(ring);
}

void rings_8032390C(Ring* ring) {
    ring->rotationType1 = 1;
    ring->timeRemaining = 0.0f;
    ring->ringType = ring->scoreType;
    uvDobjModel(ring->objId, 0xFFFF);
    rings_803234A4(ring);
    if (ring->isActive) {
        uvDobjProps(ring->objId, 5, (ring->type2 == 0) ? 2 : 5, 0);
        uvDobjProps(ring->objId, 5, (ring->type2 == 0) ? 3 : 6, 0);
    }
}

void ringsLoad(void) {
    Ring* ring;
    TaskRNGS* rngs;
    s32 var_a0;
    s32 i;
    s32 j;
    u8 ringType;

    if (D_80362690->unkA0 == 0) {
        return;
    }

    gRingsCount = taskGetRNGS(&gRefRNGS);
    if (gRingsCount > ARRAY_COUNT(gRings)) {
        _uvDebugPrintf("rings : too many rings defined in level [%d]\n", gRingsCount);
        gRingsCount = 0;
        return;
    }

    if (gRingsCount == 0) {
        return;
    }

    uvLevelAppend(0xE);
    for (i = 0; i < gRingsCount; i++) {
        rngs = &gRefRNGS[i];
        ring = &gRings[i];
        if (ring->consumedType != 0) {
            continue;
        }

        if (!ring->initialized) {
            ring->type2 = rngs->type2;
            if (rngs->ringType > 3) {
                rngs->ringType = 3;
            }
            ringType = rngs->ringType;
            ring->ringType = ring->scoreType = ringType;
            ring->size = rngs->size;
            ring->isActive = rngs->isActive;
            ring->childCount = rngs->childCount;
            if (ring->isActive && (ring->childCount > 0)) {
                ring->unk1B9 = TRUE;
            }
            ring->timedChildrenCount = rngs->timedChildRingCount;
            for (j = 0; j < ring->childCount; j++) {
                ring->children[j] = rngs->childRings[j];
            }

            for (j = 0; j < ring->timedChildrenCount; j++) {
                ring->timedChildren[j] = rngs->timeChildRings[j];
            }
            if (!ring->isActive || (ring->childCount != 0)) {
                ring->type = 1;
            } else {
                ring->type = 0;
            }
            ring->untimed = rngs->untimed;
            ring->timeRingDuration = rngs->timeRingDuration;
            ring->timeRemaining = 0.0f;
            ring->points = rngs->points;
            ring->time1AC = 1000000.0f;
            ring->time1B0 = 1000000.0f;
            ring->rotation1 = 0.0f;
            ring->rotation0 = 0.0f;
            ring->rotationRate0 = rngs->rotationRate0;
            ring->translation = rngs->translation;
            ring->rotAxis0 = rngs->rotAxis0;
            ring->rotationRateTimedOut1 = rngs->rotationRateTimedOut1;
            ring->rotationRateTiming1 = rngs->rotationRateTiming1;
            ring->rotationRate1 = rngs->rotationRate1;
            ring->rotAxis1 = rngs->axis;
            ring->unk1BA = rngs->unk73;
            uvSprintf(ring->name, "%s", rngs->name);
            func_80313640(rngs->pos.x, rngs->pos.y, rngs->pos.z, rngs->angle.x * 0.0174533f, rngs->angle.y * 0.0174533f, rngs->angle.z * 0.0174533f,
                          &ring->pose);
            uvMat4Copy(&ring->unk44, &ring->pose);
            ring->unk44.m[3][0] = 0.0f;
            ring->unk44.m[3][1] = 0.0f;
            ring->unk44.m[3][2] = 0.0f;
            uvMat4Copy(&ring->curPose, &ring->pose);
            ring->initialized = TRUE;
        }
        if (ring->isActive && (ring->ringType != 2)) {
            ring->radarIdx = hudAddWaypoint(rngs->pos.x, rngs->pos.y, rngs->pos.z);
        }
        rings_803234A4(ring);
        if ((ring->timeRemaining != 0) && ring->isActive) {
            uvDobjProps(ring->objId, 4, (ring->type2 == 0) ? 2 : 5, 0);
            uvDobjProps(ring->objId, 4, (ring->type2 == 0) ? 3 : 6, 0);
            rings_80323720(ring);
        }
    }
    rings_80323364();
}

void rings_80323DCC(Ring* ring) {
    Ring* childRing;
    s32 timeRingIdx;
    s32 childIdx;
    s32 i;

    ring->unk1B9 = FALSE;
    for (i = 0; i < ring->childCount; i++) {
        childIdx = ring->children[i];
        D_80371060[i] = childIdx;
        childRing = &gRings[childIdx];
        if (childRing->isActive) {
            _uvDebugPrintf("rings : Ring %d already active\n");
        } else if (childRing->consumedType != 0) {
            _uvDebugPrintf("rings : Activating consumed ring %d\n");
        } else {
            childRing->isActive = TRUE;
            childRing->unk1B9 = TRUE;
            if (childRing->objId != 0xFFFF) {
                uvDobjModel(childRing->objId, 0xFFFF);
            }
            rings_803234A4(childRing);
            if (childRing->ringType != 2) {
                childRing->radarIdx = hudAddWaypoint(childRing->pose.m[3][0], childRing->pose.m[3][1], childRing->pose.m[3][2]);
            }
            if (childRing->timeRemaining != 0.0f) {
                uvDobjProps(childRing->objId, 4, (childRing->type2 == 0) ? 2 : 5, 0);
                uvDobjProps(childRing->objId, 4, (childRing->type2 == 0) ? 3 : 6, 0);
                rings_80323720(childRing);
            }
        }
    }

    for (i = 0; i < ring->timedChildrenCount; i++) {
        timeRingIdx = ring->timedChildren[i];
        childRing = &gRings[timeRingIdx];
        if (childRing->consumedType == 0) {
            if (!childRing->untimed) {
                _uvDebugPrintf("rings: Untimed ring index %d in ring %d's timechild list\n", timeRingIdx, i);
            } else {
                hudWarningText(0x3D, 3.0f, 8.0f); // "Time ring start"
                rings_80323864(childRing);
            }
        }
    }
}

s32 rings_80323FFC(s32 ringIdx) {
    s32 pad0;
    s32 i;
    s32 var_a0;
    s16* textStr;
    s32 sp54;
    s32 pad3;
    Ring* ring;
    Ring* childRing;
    s32 pad1;

    func_8032BE10()->unk24 = ringsGetCleared();
    func_8032C080(&sp54);
    ring = &gRings[ringIdx];
    ring->consumedType = (ring->timeRemaining > 0.0f) ? 2 : 1;
    if (ring->ringType != 2) {
        func_8033F758(0xF, 1.0f, (ring->scoreType * 0.05f) + 0.95f, 0.0f);
    }

    var_a0 = 0;
    for (i = 0; i < ARRAY_COUNT(D_80371060); i++) {
        if ((D_80371060[i] != 0xFF) && (ringIdx == D_80371060[i])) {
            if ((ring->ringType != 3) && (ring->ringType != 2)) {
                if (ring->ringType == 1) {
                    hudText_8031D8E0(0x69, 3.0f, 8.0f); // "Bonus ring cleared"
                } else {
                    hudText_8031D8E0(0x108, 3.0f, 8.0f); // "Ring cleared"
                }
                if (sp54 > 1) {
                    textStr = textGetDataByIdx(0x29);
                    textFmtIntAt(textStr, sp54 - 1, 2, 0);
                    hudWarningText(0x29, 3.0f, 8.0f); // "to go"
                }
            }
            var_a0 = 1;
            break;
        }
    }

    if (var_a0 != 0) {
        for (i = 0; i < ARRAY_COUNT(D_80371060); i++) {
            if ((D_80371060[i] != 0xFF) && (D_80371060[i] != ringIdx)) {
                childRing = &gRings[D_80371060[i]];
                D_80371060[i] = 0xFF;
                childRing->consumedType = 3;
                if (childRing->objId != 0xFFFF) {
                    uvDobjModel(childRing->objId, 0xFFFF);
                    childRing->objId = 0xFFFF;
                }
                if (childRing->radarIdx != 0xFF) {
                    hud_8031A8E0(childRing->radarIdx);
                    childRing->radarIdx = 0xFF;
                }
            }
            D_80371060[i] = 0xFF;
        }
    } else if (ring->timeRemaining > 0.0f) {
        hudText_8031D8E0(0x17E, 3.0f, 8.0f); // "Time ring cleared"
        if (sp54 > 1) {
            textStr = textGetDataByIdx(0x29);
            textFmtIntAt(textStr, sp54 - 1, 2, 0);
            hudWarningText(0x29, 3.0f, 8.0f);
        }
    } else {
        switch (ring->ringType) {
        case 0:
            hudText_8031D8E0(0xF6, 3.0f, 8.0f); // "Ring cleared"
            if (sp54 > 1) {
                textStr = textGetDataByIdx(0x29);
                textFmtIntAt(textStr, sp54 - 1, 2, 0);
                hudWarningText(0x29, 3.0f, 8.0f); // "to go"
            }
            break;
        case 1:
            hudText_8031D8E0(0x69, 3.0f, 8.0f); // "Bonus ring cleared"
            if (sp54 > 0) {
                textStr = textGetDataByIdx(0x29);
                textFmtIntAt(textStr, sp54 - 1, 2, 0);
                hudWarningText(0x29, 3.0f, 8.0f); // "to go"
            }
            break;
        }
    }
    rings_80323DCC(ring);
    if (ring->ringType == 3) {
        return 1;
    }
    return 0;
}

s32 rings_803243D8(Mtx4F* arg0) {
    f32 sum;
    f32 vx;
    f32 vy;
    f32 vz;
    f32 dx;
    f32 dy;
    f32 dz;
    Ring* ring;
    s32 i;
    f32 var_fv0;
    Mtx4F poseMtx;
    s32 ret;
    Mtx4F yRotMtx;

    ret = 0;
    if (D_80362690->unkA0 == 0) {
        return 0;
    }
    for (i = 0; i < gRingsCount; i++) {
        ring = &gRings[i];

        if (ring->consumedType != 0 || ring->objId == 0xFFFF) {
            continue;
        }
        if (ring->unk1B6 == 0) {
            continue;
        }

        if (ring->rotationType1 == 1) {
            ring->rotation1 += ring->rotationRate1 * D_8034F854;
        } else {
            if (ring->timeRemaining > 0.0f) {
                var_fv0 = ring->rotationRateTiming1;
            } else {
                var_fv0 = ring->rotationRateTimedOut1;
            }
            ring->rotation1 += var_fv0 * D_8034F854;
        }
        if (ring->timeRemaining != 0.0f) {
            ring->timeRemaining -= D_8034F854;
            if (ring->timeRemaining <= 0.0f) {
                rings_8032390C(ring);
            }
            rings_80323720(ring);
            if (ring->radarIdx != 0xFF) {
                hud_8031A66C(ring->radarIdx, 1);
            }
        } else {
            if (ring->radarIdx != 0xFF) {
                hud_8031A66C(ring->radarIdx, 0);
            }
        }
        uvMat4SetIdentity(&poseMtx);
        ring->rotation0 += ring->rotationRate0 * D_8034F854;
        switch (ring->rotAxis0) {
        case 'x':
            uvMat4RotateAxis(&poseMtx, ring->rotation0 * 0.5f, 'x');
            uvMat4LocalTranslate(&poseMtx, 0.0f, 0.0f, ring->translation);
            break;
        case 'y':
            uvMat4RotateAxis(&poseMtx, ring->rotation0 * 0.5f, 'y');
            uvMat4LocalTranslate(&poseMtx, ring->translation, 0.0f, 0.0f);
            break;
        case 'z':
            uvMat4RotateAxis(&poseMtx, ring->rotation0 * 0.5f, 'z');
            uvMat4LocalTranslate(&poseMtx, ring->translation, 0.0f, 0.0f);
            break;
        }
        switch (ring->rotAxis1) {
        case 'y':
            uvMat4RotateAxis(&poseMtx, ring->rotation1, 'y');
            if (ring->isActive && (ring->ringType == 3)) {
                uvMat4SetIdentity(&yRotMtx);
                uvMat4RotateAxis(&yRotMtx, -ring->rotation1, 'y');
                uvDobjPosm(ring->objId, 1, &yRotMtx);
            }
            break;
        case 'x':
            uvMat4RotateAxis(&poseMtx, ring->rotation1, 'x');
            break;
        case 'z':
            uvMat4RotateAxis(&poseMtx, ring->rotation1, 'z');
            break;
        }
        uvMat4MulBA(&ring->curPose, &ring->pose, &poseMtx);
        uvDobjPosm(ring->objId, 0, &ring->curPose);
    }

    vx = arg0->m[3][0];
    vy = arg0->m[3][1];
    vz = arg0->m[3][2];
    for (i = 0; i < gRingsCount; i++) {
        ring = &gRings[i];
        if ((ring->consumedType != 0) || (ring->unk1B6 == 0)) {
            continue;
        }
        if ((ring->type == 1) && !ring->isActive) {
            continue;
        }
        dx = ring->curPose.m[3][0] - vx;
        dy = ring->curPose.m[3][1] - vy;
        dz = ring->curPose.m[3][2] - vz;
        if (uvLength3D(dx, dy, dz) < D_8034FAE0[ring->size]) {
            sum = (dx * ring->curPose.m[1][0]) + (dy * ring->curPose.m[1][1]) + (ring->curPose.m[1][2] * dz);
            if (sum > 0.0f) {
                ring->time1AC = D_8034F850;
            } else {
                ring->time1B0 = D_8034F850;
            }
            switch (ring->type2) {
            case 0:
                if (ring->time1AC < ring->time1B0) {
                    ret = rings_80323FFC(i);
                } else if ((D_8034F850 == ring->time1B0) && (ring->scoreType != 2)) {
                    func_8033F758(0x31, 1.0f, 1.0f, 0.0f);
                }
                break;
            case 1:
                if ((ring->time1AC != 1000000.0f) && (ring->time1B0 != 1000000.0f)) {
                    ret = rings_80323FFC(i);
                }
                break;
            }
            if (ring->consumedType != 0) {
                if (ring->objId != 0xFFFF) {
                    uvDobjModel(ring->objId, 0xFFFF);
                    ring->objId = 0xFFFF;
                }
                if (ring->radarIdx != 0xFF) {
                    hud_8031A8E0(ring->radarIdx);
                    ring->radarIdx = 0xFF;
                }
            }
        } else {
            ring->time1B0 = 1000000.0f;
            ring->time1AC = 1000000.0f;
        }
    }
    return ret;
}

void ringsDeinit(void) {
    Ring* ring;
    s32 i;

    for (i = 0; i < gRingsCount; i++) {
        ring = &gRings[i];
        if (ring->objId != 0xFFFF) {
            uvDobjModel(ring->objId, 0xFFFF);
            ring->objId = 0xFFFF;
            if (ring->radarIdx != 0xFF) {
                hud_8031A8E0(ring->radarIdx);
                ring->radarIdx = 0xFF;
            }
        }
    }
}

u8 ringsGetCleared(void) {
    u8 ret;
    s32 i;

    ret = 0;
    for (i = 0; i < gRingsCount; i++) {
        ret += (gRings[i].consumedType) ? 1 : 0;
    }
    return ret;
}

s16 ringsGetPoints(f32* arg0) {
    Unk80345C80* temp_v0;
    s16 ret;
    s32 idx;
    s32 i;

    ret = 0;
    temp_v0 = taskGet_80345C80();

    for (i = 0; i < gRingsCount; i++) {
        switch (gRings[i].consumedType) {
        case 1:
            idx = gRings[i].scoreType;
            ret += temp_v0->unk39C[idx];
            *arg0 += temp_v0->unk3A4[idx];
            break;
        case 2:
            ret += gRings[i].points;
            break;
        }
    }
    return ret;
}
