#include "common.h"
#include <uv_event.h>
#include "bmsound.h"
#include "code_5A6A0.h"
#include "code_9A960.h"
#include "snd.h"

typedef struct {
    u8 pad0[0x104];
    u8 unk104;
    u8 pad105[1];
    u8 unk106;
    u8 unk107;
    u8 unk108[1];
    u8 pad109[0x140 - 0x109];
    f32 unk140[1];
    u8 pad144[0x15C - 0x144];
    u8 unk15C;
    u8 pad15D[0x410 - 0x15D];
    s32 unk410;
    u8 unk414;
    u8 unk415;
    u8 pad416[0x41C - 0x416];
    f32 unk41C;
} Unk802D1534_Arg0;

extern EventCallbackInfo D_80359640;
extern Unk803599D0 D_80359648;

// forward declarations
void func_802D12C4(Unk802D1534_Arg0*);
void func_802D1334(Unk802D1534_Arg0*);

#pragma GLOBAL_ASM("asm/nonmatchings/app/bmsound/func_802D0BF0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/bmsound/func_802D0D04.s")

void func_802D112C(Unk802D1534_Arg0* arg0) {
    Unk80362690_Unk0_UnkC* sp34;
    s32 sp30;
    f32 sp2C;

    sp34 = &D_80362690->unk0[D_80362690->unk9C].unkC;
    if (arg0->unk104 == 2) {
        if (!(arg0->unk410 & 0x02)) {
            arg0->unk410 |= 0x02;
            snd_play_sfx(0x36);
            if (!(arg0->unk410 & 0x10)) {
                func_8033F748(0x1B);
                func_8033F964(0);
                func_8033FCD0(sp34->veh);
            }
            func_802D12C4(arg0);
        }
    } else {
        if (arg0->unk104 == 1) {
            if (!(arg0->unk410 & 0x10)) {
                arg0->unk410 |= 0x10;
                snd_getpilot(&sp30, &sp2C);
                func_8033F758(sp30, 1.0f, sp2C, 0.0f);
                func_8033F748(0x1B);
                func_8033F964(0);
                func_8033FCD0(sp34->veh);
                func_802D12C4(arg0);
            }
        }
        if (arg0->unk104 == 3) {
            if (!(arg0->unk410 & 0x20)) {
                arg0->unk410 |= 0x20;
                func_8033F748(0x1A);
                func_8033F964(0);
                func_8033FCD0(sp34->veh);
                func_802D12C4(arg0);
            }
        }
        if (arg0->unk107 != 0) {
            func_802D1334(arg0);
            return;
        }
        if (!(arg0->unk410 & 0x10)) {
            arg0->unk410 = 0xFFFFFFC0;
        }
    }
}

void func_802D12C4(Unk802D1534_Arg0* arg0) {
    arg0->unk410 |= 1;
    func_8033F904(arg0->unk414, 1.0f, 0.0f, 0.0f);
    func_8033F904(arg0->unk415, 1.0f, 0.0f, 0.0f);
}

void func_802D1320(Unk802D1534_Arg0* arg0) {
    arg0->unk410 &= 0xFFFFFFFE;
}

void func_802D1334(Unk802D1534_Arg0* arg0) {
    f32 temp_fv1;
    s32 i; // var_s3

    if (!(D_8034F850 < (arg0->unk41C + 0.5f))) {
        arg0->unk41C = D_8034F850;
        for (i = 0; i < arg0->unk107; i++) {
            temp_fv1 = func_80313F08(&D_80359648, FABS(arg0->unk140[i]));
            switch (arg0->unk108[i]) {
            case 4:
                if ((arg0->unk15C != 0) && (arg0->unk104 == 2)) {
                    if (!(arg0->unk410 & 4)) {
                        arg0->unk410 = arg0->unk410 | 4;
                        snd_play_sfx(0x1A);
                    }
                }
                break;
            case 1:
                if (arg0->unk106 != 0) {
                    func_8033F758(0x17, temp_fv1, 1, 0);
                }
                break;
            case 2:
                if (arg0->unk106 != 0) {
                    func_8033F758(0x16, temp_fv1, 1, 0);
                }
                break;
            case 8:
                if (arg0->unk106 != 0) {
                    func_8033F758(0x18, temp_fv1, 1, 0);
                }
                break;
            }
        }
    }
}

void func_802D1534(Unk802D1534_Arg0* arg0) {
    arg0->unk414 = func_8033F8CC(arg0->unk414);
    arg0->unk415 = func_8033F8CC(arg0->unk415);
    uvEventRemoveCb(D_80359640, 1, 0xD, 0x12, 0x13, 0x16, 0xC, 0x10, 0x24);
}
