#ifndef APP_HOVER_PADS_H
#define APP_HOVER_PADS_H

#include <PR/ultratypes.h>
#include <uv_matrix.h>

typedef struct {
    u8 pad0[4];
    Mtx4F unk4;
    u8 unk44;
    u8 unk45;
    u8 pad46[2];
    f32 unk48;
    u8 unk4C;
    u8 pad4D[3];
    s32 unk50[5]; // TODO: size
    u8 pad60[4];
    u8 unk68;
    u8 unk69;
    u8 pad6A[1];
    u8 unk6B;
    u8 unk6C;
    u8 unk6D;
    u8 pad6E[2];
} HoverPad; // size = 0x70

extern u8 gHoverPadCount;
extern HoverPad gHoverPads[20];

void func_803097E0(void);
void func_80309868(void);
void hoverPadLoad(void);
void func_80309D64(Mtx4F*);
void func_80309FFC(void);
u8 func_8030A080(void);

#endif // APP_HOVER_PADS_H
