#include "common.h"

typedef struct uvaObject {
/* 00 */ u8 pad[0x88];
/* 88 */ s32 priority;
/* 8C */ u8 sound;
/* 8D */ u8 unk8D;
/* 8E */ u8 unk8E;
/* 8F */ u8 unk8F;
/* 90 */ float near;
/* 94 */ float far;
/* 98 */ s32 unk98;
/* 9C */ float playPitch;
/* A0 */ s32 playState;
/* A4 */ s32 playVolume;
/* A8 */ s32 state;
/* AC */ u8 playVoice;
/* AD */ u8 playPan;
/* AE */ u8 playMix;
/* AF */ u8 playTimeout;
} uvaObject;

extern ALSndPlayer* D_80248C94;
extern ALSndId* D_80261218;
extern uvaObject D_80250EF8[];


#pragma GLOBAL_ASM("asm/nonmatchings/kernel/code_2130/osSyncPrintf.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/code_2130/func_8020119C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/code_2130/func_802011F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/code_2130/uvEmitterLookup.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/code_2130/uvEmitterFromModel.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/code_2130/func_802013F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/code_2130/func_80201444.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/code_2130/func_80201494.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/code_2130/func_802015D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/code_2130/func_80201614.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/code_2130/func_8020165C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/code_2130/func_80201698.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/code_2130/func_802016D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/code_2130/uvEmitterProp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/code_2130/uvEmitterTrigger.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/code_2130/uvEmitterRelease.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/code_2130/uvEmitterStatus.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/code_2130/_uvaSoundBegin.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/code_2130/_uvaSoundEnd.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/code_2130/uvEmitterFlush.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/code_2130/func_80201D08.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/code_2130/_uvaUpdatePlayList.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/code_2130/_uvaPlaylistRemove.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/code_2130/_uvaPlay.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/code_2130/_uvaStartVoice.s")

// #pragma GLOBAL_ASM("asm/nonmatchings/kernel/code_2130/_uvaUpdateVoice.s")
void _uvaUpdateVoice(u8 arg0) {
    uvaObject* temp_s0;

    temp_s0 = &D_80250EF8[arg0];
    osSyncPrintf("\n  updating voice %d on object %d\n", temp_s0->playVoice, arg0);
    alSndpSetSound(D_80248C94, D_80261218[temp_s0->playVoice]);
    alSndpSetVol(D_80248C94, temp_s0->playVolume);
    alSndpSetPitch(D_80248C94, temp_s0->playPitch);
    alSndpSetFXMix(D_80248C94, temp_s0->playMix);
    alSndpSetPan(D_80248C94, temp_s0->playPan);
}

// #pragma GLOBAL_ASM("asm/nonmatchings/kernel/code_2130/_uvaStopVoice.s")
void _uvaStopVoice(u8 arg0) {
    if (arg0 < 0x10) {
        osSyncPrintf("stopping voice%d\n", arg0);
        alSndpSetSound(D_80248C94, D_80261218[arg0]);
        if (alSndpGetState(D_80248C94) == 1) {
            alSndpSetVol(D_80248C94, 0);
        }
        alSndpStop(D_80248C94);
        return;
    }
    osSyncPrintf("%d is not a valid voice\n", arg0);
}

//#pragma GLOBAL_ASM("asm/nonmatchings/kernel/code_2130/_uvaStatus.s")
void _uvaStatus(u8 obj_id) {
    uvaObject* pObj;

    osSyncPrintf("-----object %d------\n", obj_id);
    pObj = &D_80250EF8[obj_id];
    osSyncPrintf("playVoice  = %d\n", pObj->playVoice);
    osSyncPrintf("playState  = %d\n", pObj->playState);
    osSyncPrintf("playTimeout= %d\n", pObj->playTimeout);
    osSyncPrintf("playVolume = %d\n", pObj->playVolume);
    osSyncPrintf("playPitch  = %f\n", pObj->playPitch);
    osSyncPrintf("playPan    = %d\n", pObj->playPan);
    osSyncPrintf("near       = %f\n", pObj->near);
    osSyncPrintf("far        = %f\n", pObj->far);
    osSyncPrintf("sound      = %d\n", pObj->sound);
    osSyncPrintf("priority   = %d\n", pObj->priority);
    osSyncPrintf("state      = %d\n", pObj->state);
}

