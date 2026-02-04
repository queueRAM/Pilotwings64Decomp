#include <macros.h>
#include <uv_audio.h>
#include <uv_math.h>

extern ALSndPlayer* gSndPlayer;
extern ALSndId* gSndVoiceTable;
extern uvaEmitter_t gSndEmitterTable[];

void uvEmitterPrintf(const char* fmt, ...) {
}

void uvEmitterInitTable(void) {
    s32 i;
    for (i = 0; i < 0xFF; i++) {
        uvEmitterInit(&gSndEmitterTable[i]);
    }
    uvEmitterInit(&gSndEmitterTable[0xFF]);
}

void uvEmitterInit(uvaEmitter_t* obj) {
    Mtx4F temp;

    uvMat4SetIdentity(&temp);
    obj->playVoice = 0x11;
    obj->playState = 0;
    obj->playVolume = 0x7FFF;
    obj->playPan = 0x40;
    obj->playMix = 0;
    obj->playTimeout = 0;
    obj->playPitch = 1.0f;

    uvMat4Copy(&obj->m1, &temp);
    obj->sound = 0xFF;
    obj->priority = 0;
    obj->unk98 = 0;
    obj->state = 0;

    obj->unk40.x = 0.0f;
    obj->unk40.y = 0.0f;
    obj->unk40.z = 0.0f;

    obj->unk4C.x = 0.0f;
    obj->unk4C.y = 0.0f;
    obj->unk4C.z = 0.0f;

    obj->unk70.x = 1.0f;
    obj->unk70.y = 1.0f;
    obj->unk70.z = 0.0f;
    obj->unk70.w = 0.0f;

    obj->unk80 = 0.0f;
    obj->unk84 = 0.0f;
    obj->near = 0.0f;
    obj->far = 1000.0f;
}

u8 uvEmitterLookup(void) {
    u8 var_v1;

    uvEmitterPrintf("looking for emitter\n");
    for (var_v1 = 0; var_v1 < 0xFF; var_v1++) {
        if (gSndEmitterTable[var_v1].sound == 0xFF) {
            uvEmitterPrintf("Returning emitter %d\n", var_v1);
            return var_v1;
        }
    }
    _uvDebugPrintf("no free emitters\n");
    return 0xFF;
}

void uvEmitterFromModel(u8 obj_id, u8 mdl_id) {
    uvEmitterPrintf("assigning model %d to emitter %d\n", mdl_id, obj_id);
    if (obj_id < 0xFF) {
        if (gSndEmitterTable[obj_id].playState != 0x11) {
            _uvaStopVoice(gSndEmitterTable[obj_id].playVoice);
            gSndEmitterTable[obj_id].playState = 0;
            gSndEmitterTable[obj_id].playVoice = 0x11U;
            gSndEmitterTable[obj_id].playTimeout = 0;
        }
        uvEmitterInit(&gSndEmitterTable[obj_id]);
        gSndEmitterTable[obj_id].sound = mdl_id;
    }
}

void uvEmitterSetMatrix(u8 obj_id, Mtx4F* src) {
    if (obj_id < 0xFF) {
        uvMat4Copy(&gSndEmitterTable[obj_id].m1, src);
    }
}

void uvEmitterGetMatrix(u8 obj_id, Mtx4F* dst) {
    if (obj_id < 0xFF) {
        uvMat4Copy(dst, &gSndEmitterTable[obj_id].m1);
    }
}

void uvEmitter_80201494(u8 obj_id, Vec3F arg1, Vec3F arg4) {
    Vec3F sp44;
    f32 temp_fv0;
    uvaEmitter_t* temp_s0;

    if (obj_id >= 0xFF) {
        return;
    }

    temp_s0 = &gSndEmitterTable[obj_id];
    uvVec3Copy(&temp_s0->unk40, &arg1);
    uvVec3Copy(&temp_s0->unk4C, &arg4);
    temp_s0->unk64.x = (temp_s0->unk4C.x + temp_s0->unk40.x) * 0.5f;
    temp_s0->unk64.y = (temp_s0->unk4C.y + temp_s0->unk40.y) * 0.5f;
    temp_s0->unk64.z = (temp_s0->unk4C.z + temp_s0->unk40.z) * 0.5f;
    sp44.z = temp_s0->unk4C.x - temp_s0->unk40.x;
    sp44.y = temp_s0->unk4C.y - temp_s0->unk40.y;
    sp44.x = temp_s0->unk4C.z - temp_s0->unk40.z;
    temp_fv0 = uvSqrtF(SQ(sp44.z) + SQ(sp44.y) + SQ(sp44.x));
    if (temp_fv0 != 0.0f) {
        temp_s0->unk58.x = sp44.z / temp_fv0;
        temp_s0->unk58.y = sp44.y / temp_fv0;
        temp_s0->unk58.z = sp44.x / temp_fv0;
    }
}

void uvEmitterSetUnk70(u8 obj_id, f32 arg1) {
    if (obj_id < 0xFF) {
        gSndEmitterTable[obj_id].unk70.x = arg1;
    }
}

f32 uvEmitterGetUnk70(u8 obj_id) {
    if (obj_id >= 0xFF) {
        return 0.0f;
    }
    return gSndEmitterTable[obj_id].unk70.x;
}

void uvEmitterSetUnk78(u8 obj_id, f32 arg1) {
    if (obj_id < 0xFF) {
        gSndEmitterTable[obj_id].unk70.z = arg1;
    }
}

void uvEmitterSetUnk74(u8 obj_id, f32 arg1) {
    if (obj_id < 0xFF) {
        gSndEmitterTable[obj_id].unk70.y = arg1;
    }
}

void uvEmitterSetPri(u8 obj_id, s32 pri) {
    if (obj_id < 0xFF) {
        gSndEmitterTable[obj_id].priority = pri;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/emitter/uvEmitterProp.s")

void uvEmitterTrigger(u8 obj_id) {
    if (obj_id < 0xFF) {
        uvEmitterPrintf("\nemitter %d triggered\n", obj_id);
        gSndEmitterTable[obj_id].state = 0x10;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/emitter/uvEmitterRelease.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/emitter/uvEmitterStatus.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/emitter/_uvaSoundBegin.s")

void _uvaSoundEnd(void) {
    uvEmitterPrintf("\nsoundEnd\n");
    _uvaPlay();
}

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/emitter/uvEmitterFlush.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/emitter/uvEmitter_80201D08.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/emitter/_uvaUpdatePlayList.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/emitter/_uvaPlaylistRemove.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/emitter/_uvaPlay.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/emitter/_uvaStartVoice.s")

void _uvaUpdateVoice(u8 obj_id) {
    uvaEmitter_t* obj;

    obj = &gSndEmitterTable[obj_id];
    uvEmitterPrintf("\n  updating voice %d on object %d\n", obj->playVoice, obj_id);

    alSndpSetSound(gSndPlayer, gSndVoiceTable[obj->playVoice]);
    alSndpSetVol(gSndPlayer, obj->playVolume);
    alSndpSetPitch(gSndPlayer, obj->playPitch);
    alSndpSetFXMix(gSndPlayer, obj->playMix);
    alSndpSetPan(gSndPlayer, obj->playPan);
}

void _uvaStopVoice(u8 voice_id) {
    if (voice_id < 0x10) {
        uvEmitterPrintf("stopping voice%d\n", voice_id);
        alSndpSetSound(gSndPlayer, gSndVoiceTable[voice_id]);
        if (alSndpGetState(gSndPlayer) == 1) {
            alSndpSetVol(gSndPlayer, 0);
        }
        alSndpStop(gSndPlayer);
        return;
    }
    uvEmitterPrintf("%d is not a valid voice\n", voice_id);
}

void _uvaStatus(u8 obj_id) {
    uvaEmitter_t* obj;

    obj = &gSndEmitterTable[obj_id];
    uvEmitterPrintf("-----object %d------\n", obj_id);
    uvEmitterPrintf("playVoice  = %d\n", obj->playVoice);
    uvEmitterPrintf("playState  = %d\n", obj->playState);
    uvEmitterPrintf("playTimeout= %d\n", obj->playTimeout);
    uvEmitterPrintf("playVolume = %d\n", obj->playVolume);
    uvEmitterPrintf("playPitch  = %f\n", obj->playPitch);
    uvEmitterPrintf("playPan    = %d\n", obj->playPan);
    uvEmitterPrintf("near       = %f\n", obj->near);
    uvEmitterPrintf("far        = %f\n", obj->far);
    uvEmitterPrintf("sound      = %d\n", obj->sound);
    uvEmitterPrintf("priority   = %d\n", obj->priority);
    uvEmitterPrintf("state      = %d\n", obj->state);
}

