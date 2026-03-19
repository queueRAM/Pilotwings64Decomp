#include "common.h"
#include <uv_sobj.h>
#include "proxanim.h"
#include "toys.h"

typedef struct {
    s32 unk0;
    s32 unk4;
    u8 pad8[0x24C - 0x8];
    f32 unk24C;
    f32 unk250;
    f32 unk254;
} Toy; // size = 0x258

extern u8 gToyCount;
extern Toy gToys[20];

// forward declarations
s32 toy_8034819C(s32, s32, s32);
s32 toy_80348214(s32, s32, s32);

void toyInit(void) {
    s32 i;

    gToyCount = 0;
    for (i = 0; i < ARRAY_COUNT(gToys); i++) {
        gToys[i].unk24C = 0.0f;
        gToys[i].unk250 = 0.0f;
        gToys[i].unk254 = 0.0f;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/app/toys/toy_80347C2C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/toys/toyAnimate.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/toys/toy_8034819C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/toys/toy_80348214.s")

void toyLoad(LevelTOYS* lvlToy) {
    Toy* toy;

    if (gToyCount >= ARRAY_COUNT(gToys)) {
        _uvDebugPrintf("Too many toys on level, only %d will be created\n", ARRAY_COUNT(gToys));
        return;
    }

    toy = &gToys[gToyCount];
    gToys[gToyCount].unk0 = func_80321210(toy_80348214, toy_8034819C, lvlToy->pos, 100.0f, 0.0f, (s32)toy);
    if (gToys[gToyCount].unk250 == 1.0f) {
        uvSobjModel(toy->unk4, 0x55);
    }
    gToyCount++;
}

#pragma GLOBAL_ASM("asm/nonmatchings/app/toys/toy_803483AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/toys/toy_80348418.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/toys/toy_803485F0.s")
