#include "common.h"
#include <uv_event.h>
#include "bmsound.h"
#include "snd.h"

typedef struct {
    u8 pad[0x414];
    u8 unk414;
    u8 unk415;
} Unk802D1534_Arg0;

extern EventCallbackInfo D_80359640;

#pragma GLOBAL_ASM("asm/nonmatchings/app/bmsound/func_802D0BF0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/bmsound/func_802D0D04.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/bmsound/func_802D112C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/bmsound/func_802D12C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/bmsound/func_802D1320.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/bmsound/func_802D1334.s")

void func_802D1534(Unk802D1534_Arg0* arg0) {
    arg0->unk414 = func_8033F8CC(arg0->unk414);
    arg0->unk415 = func_8033F8CC(arg0->unk415);
    uvEventRemoveCb(D_80359640, 1, 0xD, 0x12, 0x13, 0x16, 0xC, 0x10, 0x24);
}
