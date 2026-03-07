#ifndef APP_BMSOUND_H
#define APP_BMSOUND_H

#include <PR/ultratypes.h>
#include <uv_vector.h>

// is actually Unk80367704?
typedef struct {
    u8 pad0[0x104];
    u8 unk104; // in
    u8 pad105[1];
    u8 unk106; // in
    u8 unk107; // add u8
    u8 unk108[1]; // add u8[] (how many?)
    u8 pad109[0x140 - 0x109];
    f32 unk140[1]; // -> add f32[] (how many?)
    u8 pad144[0x15C - 0x144];
    u8 unk15C; // in
    u8 pad15D[0x274 - 0x15D];
    Vec3F unk274; // --> convert 3x f32
    u8 pad280[0x2BC - 0x280];
    f32 unk2BC; // in
    u8 pad2C0[0x2CC - 0x2C0];
    u8 unk2CC; // in
    u8 pad2CD[3];
    f32 unk2D0; // in
    u8 pad2D4[0x410 - 0x2D4];
    s32 unk410; // append
    u8 unk414; // append
    u8 unk415; // append
    u8 pad416[0x41C - 0x416];
    f32 unk41C; // append
    f32 unk420; // append
} Unk802D1534_Arg0;

void func_802D0BF0(Unk802D1534_Arg0*);

#endif // APP_BMSOUND_H
