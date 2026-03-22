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
s32 func_80323FFC(s32 ringIdx);

void ringsInit(void) {
    Ring* var_v1;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(gRings); i++) {
        var_v1 = &gRings[i];
        var_v1->unk0 = 0xFFFF;
        var_v1->unk1B4 = 0;
        var_v1->unk1B7 = 0;
        var_v1->unk1B5 = 0;
        var_v1->unk180 = 0.0f;
        var_v1->unk1B8 = 0;
        var_v1->unk1B9 = 0;
        var_v1->unk1CA = 0xFF;
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
            if (gRings[i].unk0 != 0xFFFF) {
                uvDobjSetState(gRings[i].unk0, 2);
            }
            if (gRings[i].unk1CA != 0xFF) {
                hud_8031A874(gRings[i].unk1CA);
            }
        } else {
            gRings[i].unk1B6 = 0;
            if (gRings[i].unk0 != 0xFFFF) {
                uvDobjClearState(gRings[i].unk0, 2);
            }
            if (gRings[i].unk1CA != 0xFF) {
                hud_8031A810(gRings[i].unk1CA);
            }
        }
    }
}

// load models, set props
void rings_803234A4(Ring* ring) {
    s32 state;
    s32 modelId;

    ring->unk0 = uvDobjAllocIdx();
    if (ring->unk1B7 != 0) {
        if (ring->type >= 2) {
            _uvDebugPrintf("rings : Bad ring rtype %d\n", ring->type);
            ring->type = 0;
        }
        if (ring->unk147 >= 4) {
            ring->unk147 = 1;
        }
        if (ring->size >= 5) {
            _uvDebugPrintf("rings : Bad ring size %d\n", ring->size);
            ring->size = 2;
        }
        if (ring->unk147 < 2) {
            modelId = gRingModelIdLookup[ring->type][ring->unk147][ring->size];
            uvDobjModel(ring->unk0, modelId);
            if (ring->unk144 == 0) {
                uvDobjProps(ring->unk0, 5, 4, 0);
            } else {
                uvDobjProps(ring->unk0, 5, 1, 0);
            }
            uvModelGetPosm(modelId, (ring->unk144 == 0) ? 2 : 5, &ring->unkC4);
            uvModelGetPosm(modelId, (ring->unk144 == 0) ? 3 : 6, &ring->unk104);
            uvDobjProps(ring->unk0, 5, 2, 0);
            uvDobjProps(ring->unk0, 5, 3, 0);
            uvDobjProps(ring->unk0, 5, 5, 0);
            uvDobjProps(ring->unk0, 5, 6, 0);
        } else if (ring->unk147 == 3) {
            uvDobjModel(ring->unk0, 0xF1);
        } else {
            ring->unk0 = 0xFFFF;
        }
    } else {
        switch (ring->unk147) {
        case 0:
            uvDobjModel(ring->unk0, 0xEF);
            break;
        case 1:
        case 3:
            uvDobjModel(ring->unk0, 0xF0);
            break;
        default:
            ring->unk0 = 0xFFFF;
        }
    }
    state = (ring->unk1B6 != 0) ? 2 : 0;
    if (ring->unk0 != 0xFFFF) {
        uvDobjState(ring->unk0, state);
        uvDobjPosm(ring->unk0, 0, &ring->unk4);
    }
}

void rings_80323720(Ring* ring) {
    f32 sp6C;
    f32 sp68;
    Mtx4F sp28;

    if ((ring->unk180 != 0) && (ring->unk1B7 != 0)) {
        sp68 = ring->unk180 * 0.31415927f; // DEG_TO_RAD(18)
        sp6C = 0.0f;
        if (sp68 < 0.0f) {
            sp68 = 0.0f;
        } else if (sp68 > 6.2831855f) {
            sp68 = 6.2831855f;
        }
        if (ring->unk1A0 == 0x79) {
            sp6C = 0.0f - ring->unk1A8;
            sp68 -= ring->unk1A8;
        }
        uvMat4Copy(&sp28, &ring->unkC4);
        uvMat4RotateAxis(&sp28, sp6C, 'y');
        uvDobjPosm(ring->unk0, (ring->unk144 == 0) ? 2 : 5, &sp28);
        uvMat4Copy(&sp28, &ring->unk104);
        uvMat4RotateAxis(&sp28, sp68, 'y');
        uvDobjPosm(ring->unk0, (ring->unk144 == 0) ? 3 : 6, &sp28);
    }
}

void rings_80323864(Ring* ring) {
    ring->unk147 = 1;
    ring->unk180 = ring->unk17C;
    uvDobjModel(ring->unk0, 0xFFFF);
    rings_803234A4(ring);
    if (ring->unk1B7 != 0) {
        uvDobjProps(ring->unk0, 4, (ring->unk144 == 0) ? 2 : 5, 0);
        uvDobjProps(ring->unk0, 4, (ring->unk144 == 0) ? 3 : 6, 0);
    }
    rings_80323720(ring);
}

void rings_8032390C(Ring* ring) {
    ring->unk1B8 = 1;
    ring->unk180 = 0.0f;
    ring->unk147 = ring->unk146;
    uvDobjModel(ring->unk0, 0xFFFF);
    rings_803234A4(ring);
    if (ring->unk1B7 != 0) {
        uvDobjProps(ring->unk0, 5, (ring->unk144 == 0) ? 2 : 5, 0);
        uvDobjProps(ring->unk0, 5, (ring->unk144 == 0) ? 3 : 6, 0);
    }
}

void ringsLoad(void) {
    Ring* ring;
    TaskRNGS* rngs;
    s32 var_a0;
    s32 i;
    s32 j;
    u8 unk72;

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
        if (ring->unk1B4 != 0) {
            continue;
        }

        if (ring->unk1B5 == 0) {
            ring->unk144 = rngs->unk71;
            if (rngs->unk72 > 3) {
                rngs->unk72 = 3;
            }
            unk72 = rngs->unk72;
            ring->unk147 = ring->unk146 = unk72;
            ring->size = rngs->size;
            ring->unk1B7 = rngs->unk55;
            ring->unk149 = rngs->unk1D;
            if (ring->unk1B7 && (ring->unk149 > 0)) {
                ring->unk1B9 = 1;
            }
            ring->unk160 = (u8)rngs->unk34;
            for (j = 0; j < ring->unk149; j++) {
                ring->unk14C[j] = rngs->unk20[j];
            }

            for (j = 0; j < ring->unk160; j++) {
                ring->unk164[j] = rngs->unk38[j];
            }
            if ((ring->unk1B7 == 0) || (ring->unk149 != 0)) {
                ring->type = 1;
            } else {
                ring->type = 0;
            }
            ring->unk178 = rngs->unk4D;
            ring->unk17C = rngs->unk50;
            ring->unk180 = 0.0f;
            ring->unk148 = rngs->unk4C;
            ring->unk1AC = 1000000.0f;
            ring->unk1B0 = 1000000.0f;
            ring->unk1A8 = 0.0f;
            ring->unk1A4 = 0.0f;
            ring->unk188 = rngs->unk58;
            ring->unk18C = rngs->unk5C;
            ring->unk190 = rngs->unk60;
            ring->unk194 = rngs->unk64;
            ring->unk198 = rngs->unk68;
            ring->unk19C = rngs->unk6C;
            ring->unk1A0 = rngs->axis; // unk70
            ring->unk1BA = rngs->unk73;
            uvSprintf(ring->unk1BB, "%s", rngs->unk74);
            func_80313640(rngs->pos.x, rngs->pos.y, rngs->pos.z, rngs->angle.x * 0.0174533f, rngs->angle.y * 0.0174533f, rngs->angle.z * 0.0174533f,
                          &ring->unk4);
            uvMat4Copy(&ring->unk44, &ring->unk4);
            ring->unk44.m[3][0] = 0.0f;
            ring->unk44.m[3][1] = 0.0f;
            ring->unk44.m[3][2] = 0.0f;
            uvMat4Copy(&ring->unk84, &ring->unk4);
            ring->unk1B5 = 1;
        }
        if ((ring->unk1B7 != 0) && (ring->unk147 != 2)) {
            ring->unk1CA = hudAddWaypoint(rngs->pos.x, rngs->pos.y, rngs->pos.z);
        }
        rings_803234A4(ring);
        if ((ring->unk180 != 0) && (ring->unk1B7 != 0)) {
            uvDobjProps(ring->unk0, 4, (ring->unk144 == 0) ? 2 : 5, 0);
            uvDobjProps(ring->unk0, 4, (ring->unk144 == 0) ? 3 : 6, 0);
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

    ring->unk1B9 = 0;
    for (i = 0; i < ring->unk149; i++) {
        childIdx = ring->unk14C[i];
        D_80371060[i] = childIdx;
        childRing = &gRings[childIdx];
        if (childRing->unk1B7 != 0) {
            _uvDebugPrintf("rings : Ring %d already active\n");
        } else if (childRing->unk1B4 != 0) {
            _uvDebugPrintf("rings : Activating consumed ring %d\n");
        } else {
            childRing->unk1B7 = 1;
            childRing->unk1B9 = 1;
            if (childRing->unk0 != 0xFFFF) {
                uvDobjModel(childRing->unk0, 0xFFFF);
            }
            rings_803234A4(childRing);
            if (childRing->unk147 != 2) {
                childRing->unk1CA = hudAddWaypoint(childRing->unk4.m[3][0], childRing->unk4.m[3][1], childRing->unk4.m[3][2]);
            }
            if (childRing->unk180 != 0.0f) {
                uvDobjProps(childRing->unk0, 4, (childRing->unk144 == 0) ? 2 : 5, 0);
                uvDobjProps(childRing->unk0, 4, (childRing->unk144 == 0) ? 3 : 6, 0);
                rings_80323720(childRing);
            }
        }
    }

    for (i = 0; i < ring->unk160; i++) {
        timeRingIdx = ring->unk164[i];
        childRing = &gRings[timeRingIdx];
        if (childRing->unk1B4 == 0) {
            if (childRing->unk178 == 0) {
                _uvDebugPrintf("rings: Untimed ring index %d in ring %d's timechild list\n", timeRingIdx, i);
            } else {
                hudWarningText(0x3D, 3.0f, 8.0f); // "Time ring start"
                rings_80323864(childRing);
            }
        }
    }
}

s32 func_80323FFC(s32 ringIdx) {
    Unk80364210* temp_s0;
    s32 i;
    s32 var_a0;
    s16* textStr;
    s32 sp54;
    s32 pad3;
    Ring* ring; // sp3C
    Ring* childRing;
    s32 var_s0;

    temp_s0 = func_8032BE10();
    temp_s0->unk24 = func_80324AF4();
    func_8032C080(&sp54);
    ring = &gRings[ringIdx];
    ring->unk1B4 = (ring->unk180 > 0.0f) ? 2 : 1;
    if (ring->unk147 != 2) {
        func_8033F758(0xF, 1.0f, (ring->unk146 * 0.05f) + 0.95f, 0.0f);
    }

    var_a0 = 0;
    for (i = 0; i < ARRAY_COUNT(D_80371060); i++) {
        if ((D_80371060[i] != 0xFF) && (ringIdx == D_80371060[i])) {
            if ((ring->unk147 != 3) && (ring->unk147 != 2)) {
                if (ring->unk147 == 1) {
                    hudText_8031D8E0(0x69, 3.0f, 8.0f); // "Bonus ring cleared"
                } else {
                    hudText_8031D8E0(0x108, 3.0f, 8.0f); // "Ring cleared"
                }
                if (sp54 >= 2) {
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
            if ((D_80371060[i] != 0xFF) && (ringIdx != D_80371060[i])) {
                childRing = &gRings[D_80371060[i]];
                D_80371060[i] = 0xFF;
                childRing->unk1B4 = 3;
                if (childRing->unk0 != 0xFFFF) {
                    uvDobjModel(childRing->unk0, 0xFFFF);
                    childRing->unk0 = 0xFFFF;
                }
                if (childRing->unk1CA != 0xFF) {
                    hud_8031A8E0(childRing->unk1CA);
                    childRing->unk1CA = 0xFF;
                }
            }
            D_80371060[i] = 0xFF;
        }
    } else if (ring->unk180 > 0.0f) {
        hudText_8031D8E0(0x17E, 3.0f, 8.0f); // "Time ring cleared"
        if (sp54 > 1) {
            textStr = textGetDataByIdx(0x29);
            textFmtIntAt(textStr, sp54 - 1, 2, 0);
            hudWarningText(0x29, 3.0f, 8.0f);
        }
    } else {
        var_s0 = ring->unk147;
        switch (var_s0) {
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
        // fakematch
        if (var_s0) { }
    }
    rings_80323DCC(ring);
    if (ring->unk147 == 3) {
        return 1;
    }
    return 0;
}

s32 func_803243D8(Mtx4F* arg0) {
    f32 spFC;
    f32 sp108;
    f32 sp104;
    f32 sp100;
    f32 dx;
    f32 dy;
    f32 dz;
    Ring* ring;
    s32 i;
    f32 var_fv0;
    Mtx4F spA8;
    s32 ret;
    Mtx4F sp64;

    ret = 0;
    if (D_80362690->unkA0 == 0) {
        return 0;
    }
    for (i = 0; i < gRingsCount; i++) {
        ring = &gRings[i];

        if (ring->unk1B4 != 0 || ring->unk0 == 0xFFFF) {
            continue;
        }
        if (ring->unk1B6 == 0) {
            continue;
        }

        if (ring->unk1B8 == 1) {
            ring->unk1A8 += ring->unk19C * D_8034F854;
        } else {
            if (ring->unk180 > 0.0f) {
                var_fv0 = ring->unk198;
            } else {
                var_fv0 = ring->unk194;
            }
            ring->unk1A8 += var_fv0 * D_8034F854;
        }
        if (ring->unk180 != 0.0f) {
            ring->unk180 = ring->unk180 - D_8034F854;
            if (ring->unk180 <= 0.0f) {
                rings_8032390C(ring);
            }
            rings_80323720(ring);
            if (ring->unk1CA != 0xFF) {
                hud_8031A66C(ring->unk1CA, 1);
            }
        } else {
            if (ring->unk1CA != 0xFF) {
                hud_8031A66C(ring->unk1CA, 0);
            }
        }
        uvMat4SetIdentity(&spA8);
        ring->unk1A4 += ring->unk188 * D_8034F854;
        switch (ring->unk190) {
        case 'x':
            uvMat4RotateAxis(&spA8, ring->unk1A4 * 0.5f, 'x');
            uvMat4LocalTranslate(&spA8, 0.0f, 0.0f, ring->unk18C);
            break;
        case 'y':
            uvMat4RotateAxis(&spA8, ring->unk1A4 * 0.5f, 'y');
            uvMat4LocalTranslate(&spA8, ring->unk18C, 0.0f, 0.0f);
            break;
        case 'z':
            uvMat4RotateAxis(&spA8, ring->unk1A4 * 0.5f, 'z');
            uvMat4LocalTranslate(&spA8, ring->unk18C, 0.0f, 0.0f);
            break;
        }
        switch (ring->unk1A0) {
        case 'y':
            uvMat4RotateAxis(&spA8, ring->unk1A8, 'y');
            if ((ring->unk1B7 != 0) && (ring->unk147 == 3)) {
                uvMat4SetIdentity(&sp64);
                uvMat4RotateAxis(&sp64, -ring->unk1A8, 'y');
                uvDobjPosm(ring->unk0, 1, &sp64);
            }
            break;
        case 'x':
            uvMat4RotateAxis(&spA8, ring->unk1A8, 'x');
            break;
        case 'z':
            uvMat4RotateAxis(&spA8, ring->unk1A8, 'z');
            break;
        }
        uvMat4MulBA(&ring->unk84, &ring->unk4, &spA8);
        uvDobjPosm(ring->unk0, 0, &ring->unk84);
    }

    sp108 = arg0->m[3][0];
    sp104 = arg0->m[3][1];
    sp100 = arg0->m[3][2];
    for (i = 0; i < gRingsCount; i++) {
        ring = &gRings[i];
        if ((ring->unk1B4 != 0) || (ring->unk1B6 == 0)) {
            continue;
        }
        if ((ring->type == 1) && (ring->unk1B7 == 0)) {
            continue;
        }
        dx = ring->unk84.m[3][0] - sp108;
        dy = ring->unk84.m[3][1] - sp104;
        dz = ring->unk84.m[3][2] - sp100;
        if (uvLength3D(dx, dy, dz) < D_8034FAE0[ring->size]) {
            var_fv0 = (dx * ring->unk84.m[1][0]) + (dy * ring->unk84.m[1][1]) + (ring->unk84.m[1][2] * dz);
            if (var_fv0 > 0.0f) {
                ring->unk1AC = D_8034F850;
            } else {
                ring->unk1B0 = D_8034F850;
            }
            switch (ring->unk144) {
            case 0:
                if (ring->unk1AC < ring->unk1B0) {
                    ret = func_80323FFC(i);
                } else if ((D_8034F850 == ring->unk1B0) && (ring->unk146 != 2)) {
                    func_8033F758(0x31, 1.0f, 1.0f, 0.0f);
                }
                break;
            case 1:
                if ((ring->unk1AC != 1000000.0f) && (ring->unk1B0 != 1000000.0f)) {
                    ret = func_80323FFC(i);
                }
                break;
            }
            if (ring->unk1B4 != 0) {
                if (ring->unk0 != 0xFFFF) {
                    uvDobjModel(ring->unk0, 0xFFFF);
                    ring->unk0 = 0xFFFF;
                }
                if (ring->unk1CA != 0xFF) {
                    hud_8031A8E0(ring->unk1CA);
                    ring->unk1CA = 0xFF;
                }
            }
        } else {
            ring->unk1B0 = 1000000.0f;
            ring->unk1AC = 1000000.0f;
        }
    }
    return ret;
}

void ringsDeinit(void) {
    Ring* ring;
    s32 i;

    for (i = 0; i < gRingsCount; i++) {
        ring = &gRings[i];
        if (ring->unk0 != 0xFFFF) {
            uvDobjModel(ring->unk0, 0xFFFF);
            ring->unk0 = 0xFFFF;
            if (ring->unk1CA != 0xFF) {
                hud_8031A8E0(ring->unk1CA);
                ring->unk1CA = 0xFF;
            }
        }
    }
}

u8 func_80324AF4(void) {
    u8 ret;
    s32 i;

    ret = 0;
    for (i = 0; i < gRingsCount; i++) {
        ret += (gRings[i].unk1B4 != 0) ? 1 : 0;
    }
    return ret;
}

s16 func_80324B60(f32* arg0) {
    Unk80345C80* temp_v0;
    s16 ret;
    s32 idx;
    s32 i;

    ret = 0;
    temp_v0 = taskGet_80345C80();

    for (i = 0; i < gRingsCount; i++) {
        switch (gRings[i].unk1B4) {
        case 1:
            idx = gRings[i].unk146;
            ret += temp_v0->unk39C[idx];
            *arg0 += temp_v0->unk3A4[idx];
            break;
        case 2:
            ret += gRings[i].unk148;
            break;
        }
    }
    return ret;
}
