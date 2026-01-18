#include "common.h"
#include <uv_memory.h>

typedef struct {
    u8 unk0[0x10];
    s32 unk10;
    u8 unk14[0x408];
    u8 unk41C;
    u8 unk41D;
    u8 unk41E;
    u8 unk41F[0xA];
    u8 unk429;
    u8 unk42A[0xE];
    s32 unk438;
    s32 unk43C;
    s32 unk440;
    u8 unk444[0x28];
    s32 unk46C;
} Unk8035078C;

typedef struct {
    void *unk0;
    u8 unk4[0xA];
    u16 unkE;
    s32 unk10;
    u8 unk14[0x78];
} Unk80362690;

typedef struct {
    s32 unk0;
    s32 unk4;
    u8 unk8;
} Unk803798E0;

extern Unk8035078C *D_8035078C;
extern Unk80362690 *D_80362690;

extern Unk803798E0 D_803798E0[12][5][7];

void func_80323364(void);
void func_802D22D8(void);
void func_802CAF50(void);
void func_80309868(void);
void func_802D28D8(void);
void func_802FAFF0(void);

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_CBEE0/func_803449B0.s")

s32 func_80344CD0(s32 arg0, s32 arg1, s32 arg2) {
    if (D_803798E0[arg0][arg1][arg2].unk8 == 0xFF) {
        return 0;
    }
    return 1;
}

// performs toupper() on an array of characters
void strToUpper(char* str, s32 length) {
    int i;

    for (i = 0; i < length; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - ('a' - 'A');
        }
    }
}

s32 func_80344E0C(s32 arg0, s32 arg1, s32 arg2, char* arg3, char* arg4) {
    u8 sp48[0x28];
    u8 sp20[0x28];
    Unk803798E0* sp18;

    sp18 = &D_803798E0[arg0][arg1][arg2];
    if (sp18->unk8 == 0xFF) {
        return 0;
    }
    _uvMediaCopy(&sp48, (void*)sp18->unk0, 0x28);
    _uvMediaCopy(arg3, arg3, 0x28);
    _uvMediaCopy(&sp20, (void*)sp18->unk4, 0x28);
    _uvMediaCopy(arg4, &sp20, 0x28);
    strToUpper(arg3, 0x28);
    strToUpper(arg4, 0x28);
    return 1;
}

s32 func_80344EF0(s32 arg0, s32 arg1) {
    s32 count;
    s32 i;

    count = 0;
    if (arg0 >= 9) {
        return 0;
    }
    if (arg1 >= 8) {
        return 0;
    }

    for (i = 0; i < 5; i++) {
        if (D_803798E0[arg0][i][arg1].unk8 != 0xFF) {
            count++;
        }
    }
    return count;
}

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_CBEE0/func_80344FC8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_CBEE0/func_8034528C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_CBEE0/func_8034536C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_CBEE0/func_803453AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_CBEE0/func_80345464.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_CBEE0/func_803456D8.s")

void func_80345A24(void) {
    u16 sp1E;

    sp1E = D_80362690[D_80362690[1].unk10].unkE;
    func_80323364();
    if ((sp1E != 3) && (sp1E != 4)) {
        func_802D22D8();
    }
    func_802CAF50();
    func_80309868();
    func_802D28D8();
    func_802FAFF0();
}

// likely getting a pointer to data and returning count
u8 func_80345AAC(s32* arg0) {
    *arg0 = D_8035078C->unk438;
    return D_8035078C->unk41C;
}

u8 func_80345ACC(s32* arg0) {
    *arg0 = D_8035078C->unk43C;
    return D_8035078C->unk41D;
}

s32* func_80345AEC(void) {
    return &D_8035078C->unk10;
}

u8 func_80345AFC(s32* arg0) {
    *arg0 = D_8035078C->unk440;
    return D_8035078C->unk41E;
}

u8 func_80345B1C(s32* arg0) {
    *arg0 = D_8035078C->unk46C;
    return D_8035078C->unk429;
}

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_CBEE0/func_80345B3C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_CBEE0/func_80345B5C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_CBEE0/func_80345B7C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_CBEE0/func_80345B9C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_CBEE0/func_80345BBC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_CBEE0/func_80345BDC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_CBEE0/func_80345BFC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_CBEE0/func_80345C1C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_CBEE0/func_80345C3C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_CBEE0/func_80345C5C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_CBEE0/func_80345C80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_CBEE0/func_80345C90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_CBEE0/func_80345CA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_CBEE0/func_80345CB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_CBEE0/func_80345CC0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_CBEE0/func_80345CE4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_CBEE0/func_803462D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_CBEE0/func_8034633C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_CBEE0/func_80346364.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_CBEE0/func_80346370.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_CBEE0/func_80346468.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_CBEE0/func_80346474.s")
