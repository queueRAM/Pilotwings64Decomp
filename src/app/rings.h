#ifndef APP_RINGS_H
#define APP_RINGS_H

#include <PR/ultratypes.h>
#include <uv_matrix.h>

typedef struct {
    u16 unk0;
    u8 pad2[2];
    Mtx4F unk4;
    Mtx4F unk44;
    Mtx4F unk84;
    Mtx4F unkC4;
    Mtx4F unk104;
    u8 unk144;
    u8 type;
    u8 unk146;
    u8 unk147;
    u8 unk148;
    u8 unk149;
    u8 pad14A[2];
    s32 unk14C[5]; // TODO: size
    u8 unk160;
    u8 pad161[3];
    s32 unk164[5]; // TODO: size
    u8 unk178; // is timed ring?
    u8 pad179[3];
    f32 unk17C;
    f32 unk180;
    u8 size;
    u8 pad185[3];
    f32 unk188;
    f32 unk18C;
    u8 unk190;
    u8 pad191[3];
    f32 unk194;
    f32 unk198;
    f32 unk19C;
    u8 axis;
    u8 pad1A1[3];
    f32 unk1A4;
    f32 unk1A8;
    f32 unk1AC;
    f32 unk1B0;
    u8 unk1B4;
    u8 unk1B5;
    u8 unk1B6;
    u8 unk1B7;
    u8 unk1B8;
    u8 unk1B9;
    u8 unk1BA;
    char unk1BB[0xF]; // TODO: size?
    u8 unk1CA;
    u8 pad1CB[1];
} Ring; // size = 0x1CC

extern Ring gRings[30];

void ringsInit(void);
void rings_80323364(void);
void ringsLoad(void);
s32 rings_803243D8(Mtx4F*);
void ringsDeinit(void);
u8 ringsGetCleared(void);
s16 ringsGetPoints(f32*);

#endif // APP_RINGS_H
