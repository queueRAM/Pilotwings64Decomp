#ifndef APP_LEVEL_H
#define APP_LEVEL_H

#include <PR/ultratypes.h>
#include <uv_vector.h>

typedef struct {
    Vec3F pos;
    f32 unkC;
    f32 unk10;
    f32 unk14;
    s32 unk18;
} LevelBNUS; // size = 0x1C

typedef struct {
    Vec3F pos;
    f32 unkC;
    s32 unk10;
    u8 unk14;
    u8 pad15[3];
} PotentialLPAD; // size = 0x18

typedef struct {
    s32 unk0[4];
} LevelTOYS; // size = 0x10

typedef struct {
    u8 unk0;
    u8 unk1[3];
    f32 unk4_X;
    f32 unk8_Y;
    f32 unkC_Z;
    f32 unk10;
    f32 unk14;
    s32 unk18;
    f32 unk1C;
    s32 unk20;
    f32 unk24;
    f32 unk28_X;
    f32 unk2C_Y;
    f32 unk30_Z;
} LevelTPTS; // size = 0x34

typedef struct {
    u8 countESND;
    u8 countWOBJ;
    u8 countLPAD;
    u8 countTOYS;
    u8 countTPTS;
    u8 countAPTS;
    u8 countBNUS;
    u8 pad7;
    void* dataWOBJ;
    PotentialLPAD* dataLPAD;
    LevelTPTS* dataTPTS;
    LevelTOYS* dataTOYS;
    void* dataAPTS;
    LevelBNUS* dataBNUS;
} LevelObjects;

void levelLoad(u8 map, u8 pilot, u8 vehicle, s32 animateToys);
void level_8030B868(void);
void level_8030B964(void);
void level_8030BA60(void);
void levelComputeAppend(u8 pilot, u8 vehicle);
void level_8030BD20(void);
u8 levelGetWOBJ(void** data);
u8 levelGetTPTS(LevelTPTS** data);
u8 levelGetAPTS(void** data);
u8 levelGetLPAD(PotentialLPAD** data);
u8 levelGetBNUS(LevelBNUS** data);
LevelObjects* levelLoadMapObjects(u8 mapIdx);

#endif // APP_LEVEL_H
