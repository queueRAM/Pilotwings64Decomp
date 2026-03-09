#ifndef APP_PADS_H
#define APP_PADS_H

#include <uv_level.h>
#include <uv_matrix.h>

typedef struct {
    u8 unk0[4];
    f32 x;
    f32 y;
    s32 unkC;
    u8 unk10[4];
    u8 unk14;
    u8 unk15;
    u8 pad16[2];
} LandingPad; // size = 0x18

typedef struct {
    f32 unk0;
    f32 unk4;
    u8 pad8[4];
    f32 unkC;
    f32 unk10;
    u8 pad14[0x10];
    f32 x;
    f32 y;
    u8 unk2C[0x38 - 0x2C];
    u8 unk38;
    u8 unk39;
    u8 pad3A[2];
} LandingStrip; // size = 0x3C

extern u8 gLandingPadCount; // count of gLandingPads
extern u8 gLandingStripCount; // count of gLandingStrips
extern LandingPad gLandingPads[14]; // parsed landing pad data, also copied to HUD
extern LandingStrip gLandingStrips[2]; // parsed landing strip data, also copied to HUD

void padsInit(void);
void padsLoad(void);
void padsFrameUpdate(Mtx4F*);
void padsDeinit(void);

#endif // APP_PADS_H
