#include "common.h"
#include <uv_dobj.h>
#include <uv_model.h>
#include <uv_string.h>
#include <uv_texture.h>
#include "code_9A960.h"
#include "hud.h"
#include "rings.h"
#include "task.h"

void rings_803234A4(Ring*);
void rings_80323720(Ring*);

extern TaskRNGS* gRefRNGS;
extern u8 gRingsCount; // count of rings stored in gRings
// extern Ring gRings[30]; // stored here, exported in header
extern u8 D_80371060[5];

// .data
extern s32 gRingModelIdLookup[/* likely 2 */][4][5];

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

#pragma GLOBAL_ASM("asm/nonmatchings/app/rings/func_80323864.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/rings/func_8032390C.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/app/rings/func_80323DCC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/rings/func_80323FFC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/rings/func_803243D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/rings/ringsDeinit.s")

u8 func_80324AF4(void) {
    u8 ret;
    s32 i;

    ret = 0;
    for (i = 0; i < gRingsCount; i++) {
        ret += (gRings[i].unk1B4 != 0) ? 1 : 0;
    }
    return ret;
}

#pragma GLOBAL_ASM("asm/nonmatchings/app/rings/func_80324B60.s")
