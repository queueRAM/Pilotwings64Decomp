#ifndef APP_PADS_H
#define APP_PADS_H

#include <uv_matrix.h>
#include <uv_vector.h>

typedef struct {
    u8 unk0[4];
    Vec3F pos;
    f32 landingDistance;
    u8 isUsed;
    u8 unk15;
    u8 unk16;
    u8 type;
} LandingPad; // size = 0x18

typedef struct {
    Vec3F pos0;
    Vec3F pos1;
    Vec3F normal;
    Vec3F midpoint;
    f32 landingDistance;
    f32 landingAlignment;
    u8 canLand;
    u8 unk39;
    u8 pad3A[2];
} LandingStrip; // size = 0x3C

extern u8 gLandingPadCount;
extern u8 gLandingStripCount;
extern LandingPad gLandingPads[14]; // parsed landing pad data, also copied to HUD
extern LandingStrip gLandingStrips[2]; // parsed landing strip data, also copied to HUD

void padsInit(void);
void padsLoad(void);
void padsFrameUpdate(Mtx4F* pose);
void padsDeinit(void);

// get the index to the landing pad or strip which pilot landed on
// returns distance to the pad or strip if landed, else 1000000.0f
f32 padsLandedPadStrip(f32 x, f32 y, f32 z, u8* outIdx);

#endif // APP_PADS_H
