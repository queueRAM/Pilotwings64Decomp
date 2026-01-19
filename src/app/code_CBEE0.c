#include "common.h"
#include <uv_memory.h>

typedef struct {
    u8 unk0[0x3];
    u8 unk3;
    u8 unk4[0x4];
    s32 unk8;
    u8 unkC[4];
    s32 unk10;
    u8 unk14[0x18];
    s32 unk2C;
    u8 unk30[0x14];
    f32 unk44;
    s32 unk48;
    u8 unk4C[0x3B8];
    f32 unk404;
    f32 unk408;
    u8 unk40C[0x10];
    u8 unk41C;
    u8 unk41D;
    u8 unk41E;
    u8 unk41F;
    u8 unk420;
    u8 unk421;
    u8 unk422;
    u8 unk423;
    u8 unk424;
    u8 unk425;
    u8 unk426;
    u8 unk427;
    u8 unk428;
    u8 unk429;
    u8 unk42A;
    u8 unk42B;
    s32 unk42C;
    s32 unk430;
    s32 unk434;
    s32 unk438;
    s32 unk43C;
    s32 unk440;
    s32 unk444;
    s32 unk448;
    s32 unk44C;
    s32 unk450;
    s32 unk454;
    s32 unk458;
    s32 unk45C;
    s32 unk460;
    s32 unk464;
    s32 unk468;
    s32 unk46C;
    s32 unk470;
    s32 unk474;
} Unk8035078C;

typedef struct {
    void* unk0;
    u16 unk4;
    u8 unk6[0x8];
    u16 unkE;
    s32 unk10;
    u16 unk14;
    u8 unk16[0x62];
    s32 unk78;
    u8 unk7C[0x10];
} Unk80362690_Unk0;

typedef struct {
    Unk80362690_Unk0 unk0[1];
    s32 unk8C;
    s32 unk90;
    s32 unk94;
    s32 unk98;
    s32 unk9C;
    u8 unkA0;
} Unk80362690;

typedef struct {
    s32 unk0;
    s32 unk4;
    u8 unk8;
    u8 pad9[0x3];
} Unk803798E0;

typedef struct {
    u8 unk0[0x30];
} Unk8037AA88;

extern Unk8035078C* D_8035078C;
extern u8 D_80350790;
extern u8 D_80350794;
extern u8 D_80350798;
extern u8 D_8035079C;
extern u8 D_803507A0;
extern u8 D_803507A4;
extern u8 D_803507A8[];

extern Unk80362690* D_80362690;

extern Unk803798E0 D_803798E0[][5][7];
extern u8 D_8037A604; // part of some struct?
extern s32 D_8037AA78;
extern s32 D_8037AA7C;
extern s32 D_8037AA80;
extern Unk8037AA88 D_8037AA88[];

void func_802CAD00(void);
void func_802CAF50(void);
void func_802CB094(void);
void func_802CB35C(void);
void func_802CB3F8(void);
void func_802D20F0(void);
void func_802D22B0(void);
void func_802D22D8(void);
void func_802D23EC(void);
void func_802D25AC(s32);
void func_802D27CC(void);
void func_802D2850(void);
void func_802D28D8(void);
void func_802D2ACC(void);
s32 func_802D2E48(void);
void func_802D3030(void);
void func_802E1278(void);
u16 func_802E12B4(void);
void func_802E15F0(void);
void func_802E344C(s32);
void func_802E37B0(void);
void func_802E3A5C(void);
void func_802E3E6C(void);
void func_802E3F7C(void);
void func_802EB424(s32, s32);
void func_802E79D8(void);
void func_802EB0BC(void);
void func_802EB3E0(void);
void func_802EB598(void);
void func_802EB5E4(void);
void func_802EDDEC(s32);
void func_802F1FA0(void);
void func_802FAF80(void);
void func_802FAFF0(void);
void func_802FB22C(void);
s32 func_802FB308(s32);
void func_802FB518(void);
void func_803097E0(void);
void func_80309868(void);
void func_80309A64(void);
void func_80309D64(s32);
void func_80309FFC(void);
void func_80315474(void);
void func_80315550(void);
void func_80316DC0(void);
void func_80316E40(void);
void func_80317634(s32);
void func_8031776C(void);
void func_80320810(void);
void func_803232F0(void);
void func_80323364(void);
void func_803239B4(void);
s32 func_803243D8(s32);
void func_80324A34(void);
s32 func_8032C080(s32);
void func_8032FAB0(void);
void func_80335B94(void);
void func_80337DB8(void);
void func_803383FC(void);
void func_8033F748(s32);
void func_8033F964(s32);
void func_8033FCD0(u16);
void func_80344290(void);
void func_803442F8(void);
void func_8034450C(s32);
void func_8034467C(void);
void func_803453AC(void);
s32 func_803456D8(s32);
void func_80345A24(void);
Unk8035078C* func_80345CE4(u32);
u8 func_80346364(void);
void func_803465F0(void);
void func_8034662C(void);
void func_8034695C(void);
void func_80346B84(void);
void func_8034C224(void);
void func_8034C848(void);
void func_8034CD60(void);
void func_8034D4AC(void);
void func_8034D548(void);
void wind_render(void);

void func_803449B0(void) {
    s32 i, j, k;
    Unk8035078C* temp_v0;
    Unk803798E0* temp_s0_2;
    s32 otherI;
    u8 sp88[0x28];
    u8 sp60[0x28];

    func_803465F0();
    func_803232F0();
    func_8034CD60();
    func_802D22B0();
    func_802CAD00();
    func_80316DC0();
    func_80344290();
    func_803097E0();
    func_802D2850();
    func_80337DB8();
    func_802E37B0();
    func_802EB3E0();
    func_8032FAB0();
    func_802FAF80();
    func_80335B94();
    func_802E79D8();
    func_802EB0BC();
    func_80315474();
    func_8034C224();
    func_80315550();
    func_802F1FA0();
    func_802D20F0();
    func_80320810();
    func_8034C848();

    for (i = 0; i < 8; i++) {
        for (j = 0; j < 5; j++) {
            for (k = 0; k < 7; k++) {
                D_803798E0[i][j][k].unk8 = 0xFF;
                D_803798E0[i][j][k].unk0 = 0;
                D_803798E0[i][j][k].unk4 = 0;
            }
        }
    }

    for (otherI = 0; otherI < 0x3D; otherI++) {
        temp_v0 = func_80345CE4(otherI);
        i = temp_v0->unk0[0];
        j = temp_v0->unk0[2];
        k = temp_v0->unk0[1];
        _uvMediaCopy(sp88, (void*)temp_v0->unk42C, 0x28);
        if (i > 7) {
            _uvDebugPrintf("\ntask : level index out of range - current limit %d\n", 7);
        }
        if (j > 4) {
            _uvDebugPrintf("\ntask : stage index out of range - current limit %d\n", 4);
        }
        if (k > 6) {
            _uvDebugPrintf("\ntask : vehicle index out of range - current limit %d\n", 6);
        }
        temp_s0_2 = &D_803798E0[i][j][k];
        if (temp_s0_2->unk8 != 0xFF) {
            _uvMediaCopy(sp60, (void*)temp_s0_2->unk0, 0x28);
            _uvDebugPrintf("task : oops! redefining [%s] idx:%d veh:%d stage:%d lev:%d -> [%s]\n", sp60, temp_s0_2->unk8, k, (s32) j, (s32) i, sp88);
        }
        temp_s0_2->unk8 = otherI;
        temp_s0_2->unk0 = temp_v0->unk42C;
        temp_s0_2->unk4 = temp_v0->unk434;
        if ((k == 6) && (j == 0)) {
            _uvMediaCopy(&D_8037AA88[i], (void*)temp_v0->unk440, 0x30);
        }
    }
}

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

// a0: class/level (Beginner/A/B/Pilot | Level | birdman time of day)
// a1: vehicle (0: hang glider, 1: rocket belt, 2: gyro, 3: cannon ball, 4: sky diving, 5: jumble hopper, 6: birdman)
// a2: test number (OR birdman time of day)
s32 func_80344FC8(s32 classIdx, s32 vehicle, s32 testIdx, u16* arg3, u16* arg4, u16* arg5) {
    u8 tmp8;

    D_8037AA78 = classIdx;
    D_8037AA80 = vehicle;
    D_8037AA7C = testIdx;

    if (classIdx > 8) {
        return 0;
    }
    if (vehicle > 7) {
        return 0;
    }
    if (testIdx > 5) {
        return 0;
    }

    tmp8 = D_803798E0[classIdx][testIdx][vehicle].unk8;
    if (tmp8 == 0xFF) {
        return 0;
    }
    D_8035078C = func_80345CE4(tmp8);
    D_80350790 = (u8)classIdx;
    D_80350794 = (u8)vehicle;
    D_80350798 = (u8)testIdx;

    *arg3 = D_803507A8[D_8035078C->unk3];
    switch (*arg3) {
    case 3:
        *arg4 = 1;
        break;
    case 5:
        *arg4 = 3;
        break;
    case 1:
        *arg4 = 0;
        break;
    case 10:
        *arg4 = 7;
        break;
    default:
        _uvDebugPrintf("task load : unknown db level [%d]\n", *arg3);
        *arg3 = 3;
        *arg4 = 1;
        break;
    }

    func_803465F0();
    func_803232F0();
    func_8034CD60();
    func_802D22B0();
    func_802CAD00();
    func_80316DC0();
    func_80344290();
    func_803097E0();
    func_802D2850();
    func_80337DB8();
    func_802E37B0();
    func_8032FAB0();
    func_802EB3E0();
    func_802FAF80();
    func_802E79D8();
    func_802EB0BC();
    func_80335B94();
    func_80315474();
    func_80315550();
    func_8034C224();
    func_802F1FA0();
    func_802D20F0();
    func_80320810();
    func_8034C848();
    D_8035079C = 1;
    D_803507A0 = 0;
    D_80362690->unk0[D_80362690->unk9C].unk14 = 0;
    *arg5 = func_802E12B4();
    return 1;
}

void func_8034528C(void) {
    u16 sp1E;

    sp1E = D_80362690->unk0[D_80362690->unk9C].unkE;
    D_8035079C = 1;
    wind_render();
    func_8034662C();
    func_80316E40();
    func_802E1278();
    func_802EB598();
    if (D_803507A0 == 0) {
        func_803239B4();
        func_802CB094();
        func_803442F8();
        func_80309A64();
        func_802D2ACC();
        func_802E3A5C();
        func_802FB22C();
        if ((sp1E != 3) && (sp1E != 4)) {
            func_802D23EC();
        }
    }
    D_803507A4 = 0;
}

void func_8034536C(void) {
    func_803453AC();
    func_80346B84();
    func_8034D4AC();
    func_8031776C();
    func_802EB5E4();
}

void func_803453AC(void) {
    u16 sp1E;

    sp1E = D_80362690->unk0[D_80362690->unk9C].unkE;
    if (D_8035079C != 0) {
        func_80324A34();
        func_802CB35C();
        func_8034467C();
        func_80309FFC();
        func_802D3030();
        func_803383FC();
        func_802E3E6C();
        func_802FB518();
        if ((sp1E != 3) && (sp1E != 4)) {
            func_802D27CC();
        }
        D_8035079C = 0;
    }
}

s32 func_80345464(s32 arg0, s32 arg1) {
    u16 sp1E;
    s32 sp18;
    s32 temp_v0;

    sp1E = D_80362690->unk0[D_80362690->unk9C].unkE;
    sp18 = 0;
    func_8034695C();
    func_8034D548();
    func_802E15F0();
    func_802CB3F8();
    func_802E3F7C();
    func_80317634(arg0);
    func_8034450C(arg0);
    func_80309D64(arg0);
    if ((sp1E != 3) && (sp1E != 4)) {
        func_802D25AC(arg0);
    }
    func_802EB424(arg0, arg1);
    func_802E344C(arg0);
    if (func_802D2E48() == 1) {
        D_803507A4 = 1;
        sp18 = 1;
        D_80362690->unk0[0].unkE = 1;
        if (D_80362690->unk0[0].unkE != 0) {
            func_8033F748(9);
            func_8033F964(0);
            func_8033FCD0(D_80362690->unk0[0].unkE);
        }
    }
    if (func_803243D8(arg0) == 1) {
        D_803507A4 = 1;
        sp18 = 1;
        D_80362690->unk0[0].unkE = 1;
        if (D_80362690->unk0[0].unkE != 0) {
            func_8033F748(9);
            func_8033F964(0);
            func_8033FCD0(D_80362690->unk0[0].unkE);
        }
    }
    if ((D_80362690->unk0[D_80362690->unk9C].unkE == 5) && (func_802FB308(D_80362690->unk0[D_80362690->unk9C].unk78) == 1)) {
        sp18 = 1;
    }
    temp_v0 = func_803456D8(arg0);
    switch (temp_v0) {
    case 1:
        func_80345A24();
        func_802EDDEC(arg0);
        break;
    case 2:
        func_802EDDEC(arg0);
        break;
    }
    if ((D_80362690->unkA0 != 0) && (func_80346364() == 3) && (func_8032C080(0) != 0)) {
        D_803507A0 = 1;
        func_803453AC();
        D_80362690->unkA0 = 0;
    }
    return sp18;
}

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_CBEE0/func_803456D8.s")

void func_80345A24(void) {
    u16 sp1E;

    sp1E = D_80362690->unk0[D_80362690->unk9C].unkE;
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

u8 func_80345B3C(s32* arg0) {
    *arg0 = D_8035078C->unk474;
    return D_8035078C->unk42B;
}

u8 func_80345B5C(s32* arg0) {
    *arg0 = D_8035078C->unk444;
    return D_8035078C->unk41F;
}

u8 func_80345B7C(s32* arg0) {
    *arg0 = D_8035078C->unk448;
    return D_8035078C->unk420;
}

u8 func_80345B9C(s32* arg0) {
    *arg0 = D_8035078C->unk44C;
    return D_8035078C->unk421;
}

u8 func_80345BBC(s32* arg0) {
    *arg0 = D_8035078C->unk450;
    return D_8035078C->unk422;
}

u8 func_80345BDC(s32* arg0) {
    *arg0 = D_8035078C->unk454;
    return D_8035078C->unk423;
}

u8 func_80345BFC(s32* arg0) {
    *arg0 = D_8035078C->unk458;
    return D_8035078C->unk424;
}

u8 func_80345C1C(s32* arg0) {
    *arg0 = D_8035078C->unk45C;
    return D_8035078C->unk425;
}

u8 func_80345C3C(s32* arg0) {
    *arg0 = D_8035078C->unk460;
    return D_8035078C->unk426;
}

u8 func_80345C5C(s32* arg0) {
    if (arg0 != NULL) {
        *arg0 = D_8035078C->unk464;
    }
    return D_8035078C->unk427;
}

s32* func_80345C80(void) {
    return &D_8035078C->unk48;
}

s32* func_80345C90(void) {
    return &D_8035078C->unk2C;
}

f32 func_80345CA0(void) {
    return D_8035078C->unk44;
}

s32* func_80345CB0(void) {
    return &D_8035078C->unk8;
}

void func_80345CC0(f32* arg0, f32* arg1) {
    *arg0 = D_8035078C->unk404;
    *arg1 = D_8035078C->unk408;
}

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_CBEE0/func_80345CE4.s")

void func_803462D4(u16 idx) {
    Unk8037AA88* src;
    if (idx > 3) {
        _uvDebugPrintf("task_birdpad : level out of valid range [%d] - set to 0\n", idx);
        idx = 0;
    }
    src = &D_8037AA88[idx];
    _uvMediaCopy((void*)D_8035078C->unk440, src, 0x30);
}

void func_8034633C(s16* arg0, s16* arg1, s16* arg2) {
    *arg0 = (s16)D_8037AA78;
    *arg1 = (s16)D_8037AA80;
    *arg2 = (s16)D_8037AA7C;
}

u8 func_80346364(void) {
    return D_8037A604;
}

// func_80346370 does not initialize the return value `ret`
#if defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wsometimes-uninitialized"
#elif defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmaybe-uninitialized"
#endif
s32 func_80346370(s32 arg0) {
    s32 ret;
    switch (D_80362690->unk0[0].unk4) {
    case 3:
        switch (arg0) {
        case 0:
            ret = 1;
            break;
        case 1:
            ret = 2;
            break;
        case 2:
            ret = 7;
            break;
        default:
            _uvDebugPrintf("task : unknown CISLAND terra selection [%d]\n", arg0);
            break;
        }
        break;
    case 5:
        ret = 3;
        break;
    case 1:
        ret = 0;
        break;
    case 10:
        switch (arg0) {
        case 0:
            ret = 7;
            break;
        case 1:
            ret = 8;
            break;
        default:
            _uvDebugPrintf("task : unknown ARCTIC level terra selection [%d]\n", arg0);
            break;
        }
        break;
    default:
        _uvDebugPrintf("task : unknown level for terra selection [%d]\n", D_80362690->unk0[0].unk4);
        break;
    }
    return ret;
}
#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic pop
#endif

u8 func_80346468(void) {
    return D_803507A4;
}

u8 func_80346474(s32* arg0) {
    *arg0 = D_8035078C->unk470;
    return D_8035078C->unk42A;
}
