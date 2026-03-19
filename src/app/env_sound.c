#include "app/task.h"
#include "common.h"
#include <uv_audio.h>
#include <uv_event.h>
#include <uv_math.h>
#include "kernel/code_1050.h"
#include "code_58B00.h"
#include "code_5A6A0.h"
#include "code_61A60.h"
#include "code_6ECD0.h"
#include "code_72B70.h"
#include "code_A7460.h"
#include "demo.h"
#include "env_sound.h"
#include "environment.h"
#include "shadow.h"
#include "snd.h"

typedef struct {
    f32 unk0;
    u8 unk4;
    u8 unk5;
    u8 unk6;
    u8 pad7[1];
} Unk80359DC8_Unk0;

typedef struct {
    Unk80359DC8_Unk0 unk0[255];
    s32 unk7F8;
    s32 unk7FC;
    s32 unk800;
} Unk80359DC8; // size = 0x804

typedef struct {
    Mtx4F unk0;
    Vec3F unk40;
    Vec3F unk4C;
    u8 unk58;
    u8 pad59[3];
    f32 unk5C;
    f32 unk60;
    s32 unk64;
    f32 unk68;
    f32 unk6C;
    u8 unk70;
    u8 pad71[3];
    s32 unk74;
} Unk802E27A8_Arg0; // size = 0x78

extern s32 D_8034EF20;
extern s32 D_8034EF24;
extern s32 D_8034EF28;
extern s32 D_8034EF2C;
extern s32 D_8034EF30[28];
extern f32 D_8034F850;

extern EventCallbackInfo D_80359DC0;
extern Unk80359DC8 D_80359DC8;

extern s32 D_8035A5C8;
extern f32 D_8035A5CC;
extern u8 D_8035A5D0[20];

// forward declarations
void envSound_802E2904(Unk80359DC8*);
void envSound_802E2A00(s32 eventType, void* arg1, s32 eventData);
void envSound_802E3250(Unk80359DC8*);
void envSound_802E3310(Unk80359DC8*);
void envSound_802E3398(Unk80359DC8*);

void envSoundInit(void) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(D_8035A5D0); i++) {
        D_8035A5D0[i] = 0;
    }

    D_8035A5CC = 0.0f;
    D_8034EF2C = 1;
    envSound_802E2904(&D_80359DC8);
    D_80359DC0.cb = &envSound_802E2A00;
    D_80359DC0.arg = &D_80359DC8;
    uvEventMaxCb(D_80359DC0, 1, 0xD, 0x12, 0x13, 0xB, 0x17, 0x18, 0x19, 0xC, 0xE, 0x24);
}

void envSoundLoad(LevelESND* arg0) {
    s32 idx;
    u8 objId;
    Unk80359DC8* ptr = &D_80359DC8;

    idx = ptr->unk7FC;

    if (D_8034EF2C == 0) {
        return;
    }

    ptr->unk7FC++;
    ptr->unk0[idx].unk0 = arg0->unk60;
    ptr->unk0[idx].unk5 = arg0->unk58;
    ptr->unk0[idx].unk6 = arg0->unk70;
    ptr->unk0[idx].unk4 = uvEmitterLookup();
    objId = ptr->unk0[idx].unk4;
    uvEmitterFromModel(objId, D_8034EF30[arg0->unk58]);
    uvEmitterSetMatrix(objId, &arg0->unk0);
    if (arg0->unk74 & 0x2) {
        uvEmitter_80201494(objId, arg0->unk40, arg0->unk4C);
    }
    uvEmitterSetUnk70(objId, arg0->unk60);
    uvEmitterSetUnk74(objId, arg0->unk5C);
    uvEmitterSetPri(objId, arg0->unk64);
    uvEmitterProp(objId, 5, arg0->unk74, 1, arg0->unk68, 2, arg0->unk6C, 0);
}

void envSound_802E2904(Unk80359DC8* arg0) {
    s32 i;

    for (i = 0; i < arg0->unk7FC; i++) {
        uvEmitterSetUnk70(arg0->unk0[i].unk4, 0.0f);
        func_8033F8CC(arg0->unk0[i].unk4);
    }

    for (i = 0; i < ARRAY_COUNT(arg0->unk0); i++) {
        arg0->unk0[i].unk4 = 0xFF;
        arg0->unk0[i].unk5 = 0xFF;
        arg0->unk0[i].unk6 = 0xFF;
    }
    arg0->unk7F8 = 0xFF;
    arg0->unk7FC = 0;
    arg0->unk800 = -0x40;
}

#ifndef NON_MATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/app/env_sound/envSound_802E2A00.s")
#else
void envSound_802E2A00(s32 eventType, void* arg1, s32 eventData) {
    s32 i;
    Unk80359DC8* sp270;
    s32 sp26C;
    Mtx4F sp22C;
    Vec3F sp220;
    Unk80359DC8_Unk0* var_s0;
    f32 temp_fs0;
    f32 temp_fs1;
    Vec3F sp208;
    Mtx4F sp1C8;
    Vec3F sp1BC;
    Mtx4F sp17C;
    Vec3F sp170;
    Mtx4F sp130;
    Mtx4F spF0;
    u32 temp_v0_3;
    Mtx4F spAC;
    Unk80362690* ptr;
    Vec3F sp9C;
    Mtx4F sp5C;

    sp270 = arg1;
    switch (eventType) {
    case 14:
        if (D_8034EF24 == 0) {
            D_8034EF24 = 1;
            D_8034EF20 = 0;
        }
        break;
    default:
        break;
    case 12:
        if (D_8034EF20 == 0) {
            D_8034EF20 = 1;
            D_8034EF24 = 0;
        }
        break;
    case 23:
        func_802E2904(sp270);
        break;
    case 24:
        sp270->unk7F8 = 0xFF;
        func_802E3310(sp270);
        break;
    case 13:
        if (eventData == 0) {
            func_802E3398(sp270);
        }
        break;
    case 25:
        func_802E3398(sp270);
        break;
    case 19:
        if (D_8034EF24 == 0) {
            D_8034EF24 = 1;
            D_8034EF20 = 0;
            D_8034EF28 = 0;
            sp270->unk7F8 = 0xFF;
        }
        break;
    case 18:
        if (D_8034EF20 == 0) {
            D_8034EF20 = 1;
            D_8034EF24 = 0;
        }
        break;
    case 1:
        if (sp270->unk800 & 1) {
            return;
        }

        if (D_8034EF24 != 0) {
            D_8034EF28++;
        }

        //---------------------------------------------------------------------------------
        // using this pointer fixes branch likely above, but then regalloc and instr. order
        //---------------------------------------------------------------------------------
        // ptr = D_80362690;
        if (D_80362690->terraId == 9) {
            D_8034EF28 = 0;
            return;
        }

        if (D_8034EF28 >= 2) {
            if (D_8034EF28 == 2) {
                func_802E3310(sp270);
            }
            if (D_80362690->map == MAP_CRESCENT_ISLAND) {
                sp26C = D_80362690->unkC[D_80362690->unk9C].unk8;
                if (sp26C != sp270->unk7F8) {
                    func_802E3250(sp270);
                }
            }

            for (i = 0; i < sp270->unk7FC; i++) {
                var_s0 = &sp270->unk0[i];
                if (D_8034EF20 != 0) {
                    uvEmitterSetUnk70(var_s0->unk4, uvEmitterGetUnk70(var_s0->unk4) * 0.95f);
                } else {
                    if ((sp26C == var_s0->unk6) || (var_s0->unk6 == 0xA)) {
                        switch (var_s0->unk5) { // sound id
                        case 0:
                            temp_fs1 = ((demoRandF() - 0.5f) * 0.1f) + 0.8f;
                            temp_fs0 = ((demoRandF() - 0.5f) * 0.2f) + 0.9f;
                            uvEmitterSetUnk74(var_s0->unk4, temp_fs1);
                            uvEmitterSetUnk70(var_s0->unk4, temp_fs0);
                            break;
                        case 1:
                            temp_fs1 = ((demoRandF() - 0.5f) * 0.1f) + 0.8f;
                            temp_fs0 = ((demoRandF() - 0.5f) * 0.1f) + 0.95f;
                            uvEmitterSetUnk74(var_s0->unk4, temp_fs1);
                            uvEmitterSetUnk70(var_s0->unk4, temp_fs0);
                            break;
                        case 2:
                            temp_fs1 = ((demoRandF() - 0.5f) * 0.1f) + 0.8f;
                            uvEmitterSetUnk74(var_s0->unk4, temp_fs1);
                            break;
                        case 3:
                            temp_fs1 = 1.0f;
                            temp_fs0 = ((demoRandF() - 0.5f) * 0.2f) + 0.9f;
                            uvEmitterSetUnk74(var_s0->unk4, temp_fs1);
                            uvEmitterSetUnk70(var_s0->unk4, temp_fs0);
                            break;
                        case 4:
                            temp_fs1 = ((demoRandF() - 0.5f) * 0.1f) + 0.8f;
                            temp_fs0 = ((demoRandF() - 0.5f) * 0.2f) + 0.9f;
                            uvEmitterSetUnk74(var_s0->unk4, temp_fs1);
                            uvEmitterSetUnk70(var_s0->unk4, temp_fs0);
                            break;
                        case 5:
                            temp_fs1 = ((demoRandF() - 0.5f) * 0.1f) + 1.8f;
                            temp_fs0 = ((demoRandF() - 0.5f) * 0.2f) + 0.7f;
                            uvEmitterSetUnk74(var_s0->unk4, temp_fs1);
                            uvEmitterSetUnk70(var_s0->unk4, temp_fs0);
                            break;
                        case 9:
                            temp_fs1 = ((demoRandF() - 0.5f) * 0.1f) + 1.00f; // + 1.0f
                            temp_fs0 = ((demoRandF() - 0.5f) * 0.1f) + 0.95f;
                            uvEmitterSetUnk74(var_s0->unk4, temp_fs1);
                            uvEmitterSetUnk70(var_s0->unk4, temp_fs0);
                            break;
                        case 11:
                            temp_fs1 = ((demoRandF() - 0.5f) * 0.1f) + 0.4f;
                            uvEmitterSetUnk74(var_s0->unk4, temp_fs1);
                            break;
                        case 26:
                            func_802E7CB8(&sp208);
                            sp1C8.m[3][0] = sp208.x;
                            sp1C8.m[3][1] = sp208.y;
                            sp1C8.m[3][2] = sp208.z;
                            uvEmitterSetMatrix(var_s0->unk4, &sp1C8);
                            break;
                        case 23:
                            func_803203D0(0, &sp1BC);
                            sp17C.m[3][0] = sp1BC.x;
                            sp17C.m[3][1] = sp1BC.y;
                            sp17C.m[3][2] = sp1BC.z;
                            uvEmitterSetMatrix(var_s0->unk4, &sp17C);
                            break;
                        case 24:
                            func_803203D0(1, &sp170);
                            sp130.m[3][0] = sp170.x;
                            sp130.m[3][1] = sp170.y;
                            sp130.m[3][2] = sp170.z;
                            uvEmitterSetMatrix(var_s0->unk4, &sp130);
                            break;
                        case 21:
                            if (func_802D2018(0, &spF0) != 0) {
                                uvEmitterSetMatrix(var_s0->unk4, &spF0);
                            } else {
                                uvEmitterRelease(var_s0->unk4);
                            }
                            break;
                        case 22:
                            if (func_802D2018(1, &spAC) != 0) {
                                uvEmitterSetMatrix(var_s0->unk4, &spAC);
                            } else {
                                uvEmitterRelease(var_s0->unk4);
                            }
                            break;
                        case 17:
                            uvEmitterGetMatrix(var_s0->unk4, &sp22C);
                            func_802E1754(sp22C.m[3][0], sp22C.m[3][1], sp22C.m[3][2], &sp220);

                            //---------------------------------------------------------------
                            // f32 regalloc
                            //---------------------------------------------------------------
                            temp_fs1 = (sp220.y * 0.1f) + 0.25f;
                            temp_fs0 = sp220.y;
                            if (temp_fs0 < 0.0f) {
                                temp_fs0 = 0.0f;
                            } else if (temp_fs0 > 1.0f) {
                                temp_fs0 = 1.0f;
                            }
                            //---------------------------------------------------------------

                            uvEmitterSetUnk74(var_s0->unk4, temp_fs1);
                            uvEmitterSetUnk70(var_s0->unk4, temp_fs0);
                            break;
                        case 20:
                            temp_v0_3 = func_80335F84(); // shuttle state
                            switch (temp_v0_3) {
                            case 0:
                                uvEmitterSetUnk74(var_s0->unk4, 1.0f);
                                uvEmitterSetUnk70(var_s0->unk4, 0.0f);
                                break;
                            case 1:
                                uvEmitterSetUnk74(var_s0->unk4, 0.20f); // 0.2f
                                uvEmitterSetUnk70(var_s0->unk4, 1.0f);
                                break;
                            case 2:
                                uvEmitterSetUnk74(var_s0->unk4, 0.33f);
                                uvEmitterSetUnk70(var_s0->unk4, 1.0f);
                                func_80335F24(&sp9C);
                                uvMat4SetIdentity(&sp5C);
                                sp5C.m[3][0] = sp9C.x;
                                sp5C.m[3][1] = sp9C.y;
                                sp5C.m[3][2] = sp9C.z;
                                uvEmitterSetMatrix(var_s0->unk4, &sp5C);
                                break;
                            case 3:
                                uvEmitterSetUnk74(var_s0->unk4, 1.0f);
                                uvEmitterSetUnk70(var_s0->unk4, 0.5f);
                                func_80335F24(&sp9C);
                                uvMat4SetIdentity(&sp5C);
                                sp5C.m[3][0] = sp9C.x;
                                sp5C.m[3][1] = sp9C.y;
                                sp5C.m[3][2] = sp9C.z;
                                uvEmitterSetMatrix(var_s0->unk4, &sp5C);
                                break;
                            case 4:
                                uvEmitterSetUnk74(var_s0->unk4, 1.0f);
                                uvEmitterSetUnk70(var_s0->unk4, 0.0f);
                                break;
                            default:
                                _uvDebugPrintf("got unkown shuttle state\n");
                                break;
                            }
                            break;
                        default:
                            _uvDebugPrintf("Got unknown sndId\n");
                            break;
                        }
                    }
                }
            }
        }
        break;
    }
}
#endif

void envSound_802E3250(Unk80359DC8* arg0) {
    Unk80359DC8_Unk0* var_s0;
    s32 i;
    s32 temp_s4;

    temp_s4 = D_80362690->unkC[D_80362690->unk9C].unk8;
    for (i = 0; i < arg0->unk7FC; i++) {
        var_s0 = &arg0->unk0[i];
        if (temp_s4 == var_s0->unk6) {
            uvEmitterTrigger(var_s0->unk4);
        } else if (var_s0->unk6 != 0xA) {
            uvEmitterRelease(var_s0->unk4);
        }
    }
    arg0->unk7F8 = temp_s4;
}

void envSound_802E3310(Unk80359DC8* arg0) {
    Unk80359DC8_Unk0* var_s0;
    s32 i;

    D_8034EF24 = 1;
    D_8034EF20 = 0;
    arg0->unk800 = -0x40;
    for (i = 0; i < arg0->unk7FC; i++) {
        var_s0 = &arg0->unk0[i];
        uvEmitterSetUnk70(var_s0->unk4, var_s0->unk0);
        uvEmitterTrigger(var_s0->unk4);
    }
}

void envSound_802E3398(Unk80359DC8* arg0) {
    D_8034EF20 = 0;
    D_8034EF24 = 0;
    D_8034EF28 = 0;
    D_8034EF2C = 0;
    D_8035A5CC = 0.0f;
    envSound_802E2904(arg0);
    uvEventRemoveCb(D_80359DC0, 1, 0xD, 0x12, 0x13, 0xB, 0x17, 0x18, 0x19, 0xC, 0xE, 0x24);
}

void envSoundFrameUpdate(Mtx4F* arg0) {
    LevelAPTS* aptsRef;
    u8 aptCount;
    u8 i;
    LevelAPTS* apt;
    Vec3F sp1E8;
    Vec3F sp1DC;
    f32 temp_fs0;
    f32 temp_fv0;
    f32 var_ft0;
    s32 pad;
    Vec3F sp1C0;
    Vec3F sp1B4;
    Unk802D3658_Unk1224 sp70;

    aptCount = levelGetAPTS(&aptsRef);
    if ((aptCount == 0) || (D_8035A5C8 & 1)) {
        return;
    }

    for (i = 0; i < aptCount; i++) {
        apt = &aptsRef[i];
        sp1E8.x = arg0->m[3][0] - apt->unk0.x;
        sp1E8.y = arg0->m[3][1] - apt->unk0.y;
        sp1E8.z = arg0->m[3][2] - apt->unk0.z;
        temp_fs0 = uvVec3Len(&sp1E8);
        sp1DC.x = uvCosF((apt->unkC + 90.0f) * 0.01745329f);
        sp1DC.y = uvSinF((apt->unkC + 90.0f) * 0.01745329f);
        sp1DC.z = 0.0f;
        temp_fv0 = uvVec3Dot(&sp1DC, &sp1E8);
        if (temp_fs0 <= apt->unk10) {
            switch (apt->unk14) {
            case 0:
                if (temp_fv0 > 0.0f) {
                    D_8035A5D0[0] = 0;
                    var_ft0 = ((apt->unk1C - apt->unk18) * (apt->unk10 - temp_fs0)) / (2.0f * apt->unk10);
                } else {
                    D_8035A5D0[0] = 1;
                    var_ft0 = ((apt->unk1C - apt->unk18) * (apt->unk10 + temp_fs0)) / (2.0f * apt->unk10);
                }
                func_80200180(0, 4, var_ft0, 0);
                break;
            case 1:
                sp1B4.x = sp1C0.x = arg0->m[3][0];
                sp1B4.y = sp1C0.y = arg0->m[3][1];
                sp1B4.z = arg0->m[3][2];
                sp1C0.z = apt->unk10 + sp1B4.z;
                if (func_802DB224(&sp70, 0xB, 0xFFFF, 0, &sp1B4, &sp1C0) != 0) {
                    D_8035A5D0[1]++;
                } else {
                    if ((D_8035A5D0[1] > 0) && (D_80362690->unkC[0].unkA != 4) && (D_80362690->unkC[0].veh != VEHICLE_JUMBLE_HOPPER)) {
                        if (D_8035A5CC < D_8034F850) {
                            D_8035A5CC = D_8034F850 + 4.0f;
                            snd_play_sfx(0x50);
                        }
                    }
                    D_8035A5D0[1] = 0;
                }
                break;
            }
        } else if (apt->unk14 == 0) {
            if (D_8035A5D0[0] == 0) {
                func_80200180(0, 4, apt->unk18, 0);
            } else {
                func_80200180(0, 4, apt->unk1C, 0);
            }
        }
    }
}
