#include "common.h"
#include "uv_memory.h"
#include "uv_util.h"

typedef struct {
    char magic[2];
    u8 unk02[0xFE];
} PilotwingsSaveFile;

extern PilotwingsSaveFile D_803620E0[2];
extern PilotwingsSaveFile D_803622E0[2];

void func_802E81BC(void*);
s32 func_802E8294(s32);

#pragma GLOBAL_ASM("asm/nonmatchings/app/save/func_802E7FA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/save/func_802E81BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/save/func_802E8294.s")

void func_802E8304(void) {
    if (uvFileRead(D_803620E0, 0, sizeof(D_803620E0)) != sizeof(D_803620E0)) {
        func_802E81BC("EEPROM CHECK FAILED");
    } else {
        if (((D_803620E0[0].magic[0] != 'P') || (D_803620E0[0].magic[1] != 'W')) && ((D_803620E0[0].magic[0] != 'p') || (D_803620E0[0].magic[1] != 'w'))) {
            _uvDebugPrintf("EEProm file 1 initializing...\n");
            if (func_802E8294(0) != 0) {
                func_802E81BC("FILE 1 WRITE FAILED");
            }
        }
        if (((D_803620E0[1].magic[0] != 'P') || (D_803620E0[01].magic[1] != 'W')) && ((D_803620E0[1].magic[0] != 'p') || (D_803620E0[1].magic[1] != 'w'))) {
            _uvDebugPrintf("EEProm file 2 initializing...\n");
            if (func_802E8294(1) != 0) {
                func_802E81BC("FILE 2 WRITE FAILED");
            }
        }
    }
    _uvMediaCopy(D_803622E0, &D_803620E0, sizeof(D_803620E0));
}

#pragma GLOBAL_ASM("asm/nonmatchings/app/save/func_802E8424.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/save/func_802E86C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/save/func_802E899C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/save/func_802E89D4.s")
