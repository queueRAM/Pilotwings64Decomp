#include "common.h"
#include <uv_dobj.h>
#include <uv_math.h>
#include "code_9A960.h"
#include "env_sound.h"
#include "planes.h"
#include "proxanim.h"
#include "spath.h"

typedef struct {
    s32 objId;
    s32 spathId;
    s32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
    f32 unk18;
    f32 unk1C;
    f32 unk20;
    Vec3F pos;
    f32 unk30;
} Plane; // size = 0x34

static Plane sPlanes[2];
static s32 sPlaneInitialized[2];

STATIC_FUNC void planesUpdate(s32 idx) {
    Mtx4F pose;
    f32 time;
    f32 var_fa1;
    f32 sp6C;
    f32 sp68;
    f32 sp64;
    f32 temp_ft0;
    f32 sp5C;
    f32 temp_fv0;
    Vec3F sp4C;
    Vec3F sp40;

    if (!sPlaneInitialized[idx]) {
        sPlanes[idx].unkC = 0;
        if (sPlanes[idx].unk10 < sPlanes[idx].unkC) {
            sPlanes[idx].unkC -= sPlanes[idx].unk10;
        } else if (sPlanes[idx].unkC < 0.0f) {
            sPlanes[idx].unkC += sPlanes[idx].unk10;
        }
        time = (100.0f * sPlanes[idx].unkC) / sPlanes[idx].unk10;
        spathInterpolate(&sPlanes[idx].pos, &sPlanes[idx].unk18, &sPlanes[idx].unk1C, sPlanes[idx].spathId, time);
        temp_fv0 = sPlanes[idx].unk14;
        sPlanes[idx].pos.z = temp_fv0;
        sPlanes[idx].unk20 = 0.0f;
        sPlaneInitialized[idx] = TRUE;
    }

    //! @fakematch
    if (1) { }

    sPlanes[idx].unkC = sPlanes[idx].unkC + D_8034F854;
    if (sPlanes[idx].unk10 < sPlanes[idx].unkC) {
        sPlanes[idx].unkC -= sPlanes[idx].unk10;
    } else if (sPlanes[idx].unkC < 0.0f) {
        sPlanes[idx].unkC += sPlanes[idx].unk10;
    }

    time = (100.0f * sPlanes[idx].unkC) / sPlanes[idx].unk10;
    spathInterpolate(&sp40, &sp6C, &sp68, sPlanes[idx].spathId, time);

    if ((FABS(sp68 - sPlanes[idx].unk1C) / D_8034F854) > 0.1f) {
        if (sPlanes[idx].unk1C < sp68) {
            sp68 = sPlanes[idx].unk1C + (0.1f * D_8034F854);
        } else {
            sp68 = sPlanes[idx].unk1C - (0.1f * D_8034F854);
        }
    }

    if (sp40.z < sPlanes[idx].unk14) {
        sp40.z = sPlanes[idx].unk14;
    }
    sp4C.x = (sp40.x - sPlanes[idx].pos.x) / D_8034F854;
    sp4C.y = (sp40.y - sPlanes[idx].pos.y) / D_8034F854;
    sp4C.z = (sp40.z - sPlanes[idx].pos.z) / D_8034F854;
    temp_fv0 = uvVec3Len(&sp4C);
    temp_ft0 = (sp6C - sPlanes[idx].unk18) / D_8034F854;
    sp5C = (-sPlanes[idx].unk30 * temp_ft0) / temp_fv0;

    if (ABS_NOEQ(sp5C) > 0.00001f) {
        if (sp5C > 1.0f) {
            var_fa1 = 0.0f;
            sp5C = 1.0f;
        } else if (sp5C < -1.0f) {
            var_fa1 = 0.0f;
            sp5C = -1.0f;
        } else {
            var_fa1 = uvSqrtF(1.0f - SQ(sp5C));
        }
        sp64 = uvAtan2F(sp5C, var_fa1);
        if ((FABS(sp64 - sPlanes[idx].unk20) / D_8034F854) > 0.1f) {
            if (sPlanes[idx].unk20 < sp64) {
                sp64 = sPlanes[idx].unk20 + (0.1f * D_8034F854);
            } else {
                sp64 = sPlanes[idx].unk20 - (0.1f * D_8034F854);
            }
        }
        func_80313640(sp40.x, sp40.y, sp40.z, sp6C, sp68, sp64, &pose);
    } else {
        sp64 = 0.0f;
    }
    func_80313640(sp40.x, sp40.y, sp40.z, sp6C, sp68, sp64, &pose);
    uvDobjPosm(sPlanes[idx].objId, 0, &pose);
    sPlanes[idx].pos.x = sp40.x;
    sPlanes[idx].pos.y = sp40.y;
    sPlanes[idx].pos.z = sp40.z;
    sPlanes[idx].unk20 = sp64;
    sPlanes[idx].unk1C = sp68;
    sPlanes[idx].unk18 = sp6C;
}

// get x,y,z at index idx
void planesGetPos(s32 planeIdx, Vec3F* vec) {
    vec->x = sPlanes[planeIdx].pos.x;
    vec->y = sPlanes[planeIdx].pos.y;
    vec->z = sPlanes[planeIdx].pos.z;
}

STATIC_FUNC s32 planes_8032040C(s32 arg0, s32 arg1, s32 arg2) {
    s32 i;

    switch (arg1) {
    case 0:
        break;
    case 2:
        for (i = 0; i < ARRAY_COUNT(sPlanes); i++) {
            uvDobjState(sPlanes[i].objId, 0);
        }
        break;
    case 3:
        for (i = 0; i < ARRAY_COUNT(sPlanes); i++) {
            uvDobjState(sPlanes[i].objId, 2);
        }
        break;
    }
    return 0;
}

STATIC_FUNC s32 planes_803204B0(s32 arg0, s32 arg1, s32 arg2) {
    s32 idx;
    Unk803216A4* temp_v0;
    s32 ret;
    f32 tmp;

    ret = 0;
    temp_v0 = func_803216A4();
    if (temp_v0 != NULL) {
        idx = temp_v0->unk14;
        if (temp_v0->unk8 != 0) {
            tmp = func_80321420(arg0);
            if (tmp > 4000.0f) {
                ret = 2;
            } else {
                planesUpdate(idx);
            }
        }
    }
    return ret;
}

void planesLoad(void) {
    s32 i;
    Vec3F sp108;
    LevelESND sp90;

    for (i = 0; i < ARRAY_COUNT(sPlanes); i++) {
        sPlanes[i].objId = uvDobjAllocIdx();
        if (sPlanes[i].objId != 0xFFFF) {
            switch (i) {
            case 0:
                sp90.sndId = 0x17;
                uvDobjModel(sPlanes[i].objId, MODEL_BIG_WHITE_RED_PLANE);
                uvDobjState(sPlanes[i].objId, 2);
                sPlanes[i].spathId = spathLoadFile(0x6D);
                sPlanes[i].unk10 = 120.0f;
                sPlanes[i].unk30 = 150.0f;
                sPlanes[i].unk14 = 42.43231f;
                sp108.x = -1225.0f;
                sp108.y = 454.0f;
                sp108.z = 161.4f;
                break;
            case 1:
                sp90.sndId = 0x18;
                uvDobjModel(sPlanes[i].objId, MODEL_YELLOW_WHITE_PLANE);
                uvDobjState(sPlanes[i].objId, 2);
                sPlanes[i].spathId = spathLoadFile(0x6E);
                sPlanes[i].unk10 = 120.0f;
                sPlanes[i].unk30 = 150.0f;
                sPlanes[i].unk14 = 33.757683f;
                sp108.x = -211.85f;
                sp108.y = 884.5f;
                sp108.z = 224.3f;
                break;
            }
            uvMat4SetIdentity(&sp90.unk0);
            sp90.unk5C = 1.0f;
            sp90.unk60 = 1.0f;
            sp90.unk64 = 0;
            sp90.unk68 = 0.0f;
            sp90.unk6C = 200.0f;
            sp90.unk74 = 8;
            sp90.unk70 = 0;
            sp90.unk0.m[3][0] = sp108.x;
            sp90.unk0.m[3][1] = sp108.y;
            sp90.unk0.m[3][2] = sp108.z;
            envSoundLoad(&sp90);
            sPlanes[i].unk8 = func_80321210(planes_803204B0, planes_8032040C, sp108, 4000.0f, 0.0f, i);
            planesUpdate(i);
        }
    }
}

void planesDeinit(void) {
    Plane* var_s0;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(sPlanes); i++) {
        var_s0 = &sPlanes[i];
        if (var_s0->objId != 0xFFFF) {
            uvDobjModel(var_s0->objId, 0xFFFF);
            var_s0->objId = 0xFFFF;
            func_803212DC(var_s0->unk8);
            spathFree(var_s0->spathId);
        }
    }
}

void planesInit(void) {
    s32 i;
    for (i = 0; i < ARRAY_COUNT(sPlanes); i++) {
        sPlanes[i].objId = 0xFFFF;
        sPlaneInitialized[i] = FALSE;
    }
}

void planesGetObjData(s32 planeIdx, s32* objId, f32* arg2, Vec3F* vec) {
    Mtx4F pose;
    Plane* temp_v0;

    temp_v0 = &sPlanes[planeIdx];
    if (temp_v0->objId != 0xFFFF) {
        *objId = temp_v0->objId;
        *arg2 = temp_v0->unkC / temp_v0->unk10;
        uvDobjGetPosm(*objId, 0, &pose);
        vec->x = pose.m[3][0];
        vec->y = pose.m[3][1];
        vec->z = pose.m[3][2];
    } else {
        *objId = 0xFFFF;
        *arg2 = 0.0f;
        vec->x = 0.0f;
        vec->y = 0.0f;
        vec->z = 0.0f;
    }
}

void planesUpdateInterval(s32 planeIdx, f32 interval) {
    Plane* temp_s0;
    f32 temp_fs1;

    temp_s0 = &sPlanes[planeIdx];
    if (temp_s0->objId != 0xFFFF) {
        uvDobjState(temp_s0->objId, 2);
        temp_fs1 = temp_s0->unk10 * interval;

        // this looks like for loop pattern with f32, but doesn't match
        temp_s0->unkC = 0.0f;
        sPlaneInitialized[planeIdx] = FALSE;
        if (temp_fs1 > 0.0f) {
            do {
                planesUpdate(planeIdx);
                temp_s0->unkC += 1.0f;
            } while (temp_s0->unkC < temp_fs1);
        }

        temp_s0->unkC = temp_fs1;
        planesUpdate(planeIdx);
    }
}
