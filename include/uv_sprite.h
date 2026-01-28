#ifndef PILOTWINGS64_UV_SPRITE
#define PILOTWINGS64_UV_SPRITE

#include <PR/sp.h>
#include <uv_util.h>

typedef struct {
    u16 unk0;
    u16 unk2;
    u16 unk4;
    u16 unk6;
    u16 unk8;
    u16 unkA;
    u16 unkC;
    u16 unkE;
    u32 unk10;
    u32 unk14;
    u32 unk18;
    u32 unk1C;
    u8 pad[0x40];
} uvSprite_t;

void func_80230B98(uvSprite_t* sprite);
void uvSprtDraw(s32 sprite_id);
void uvSprtSetBlit(uvSprite_t* sprite, s32 arg1);
s16 uvSprtGetUnk0(s32 sprite_id);
s16 uvSprtGetUnk1(s32 sprite_id);
void uvSprtResetUnk(void);

#endif // PILOTWINGS64_UV_SPRITE

