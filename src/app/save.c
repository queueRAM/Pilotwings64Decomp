#include "common.h"
#include "uv_graphics.h"
#include "uv_memory.h"
#include "uv_util.h"

typedef struct {
    char magic[2];
    u8 unk02[0xFE];
} PilotwingsSaveFile;

extern PilotwingsSaveFile D_803620E0[2];
extern PilotwingsSaveFile D_803622E0[2];

void func_802E81BC(char* arg0);
s32 func_802E8294(s32);

void uvFontSet(s32);
void func_80219550(f64, f64);
void func_8021956C(u8, u8, u8, u8);
s32 func_802197EC(char*);
void func_80219EA8(void);
void func_80219ACC(s32, s32, char*);

void func_802E7FA0(u8* arg0, s32* arg1, s32 arg2, s32 bitCount) {
    u8* bytePtr;
    s32 bitMask;
    s32 shift;
    s32 i;

    bitMask = (0xFF >> (8 - bitCount));
    arg2 = arg2 & bitMask;
    for (i = 0; i < bitCount; i++) {
        bytePtr = &arg0[*arg1 / 8];
        shift = (*arg1 % 8);
        *bytePtr |= ((arg2 & (1 << i)) >> i) << shift;
        *arg1 += 1;
    }
}

void func_802E81BC(char* arg0) {
    s32 temp_s0;

    uvMemLoadDS(0x2E);
    uvFontSet(0);
    func_80219550(1.0, 1.0);
    func_8021956C(0xFF, 0xFF, 0x00, 0xFF);
    temp_s0 = 160 - (func_802197EC(arg0) / 2);
    for (;;) {
        uvGfxBegin();
        func_802228F0(0, 0, 0, 0);
        func_80219ACC(temp_s0, 100, arg0);
        func_80219EA8();
        uvGfxEnd();
    }
}

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

// if returns s32, regalloc issues?
int func_802E899C(s32 fileIdx) {
    return (D_803620E0[fileIdx].magic[0] == 'P') && (D_803620E0[fileIdx].magic[1] == 'W');
}

#pragma GLOBAL_ASM("asm/nonmatchings/app/save/func_802E89D4.s")
