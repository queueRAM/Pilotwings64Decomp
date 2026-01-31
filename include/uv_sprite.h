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

void uvSprt_80230130(void);
void uvSprt_802301A4(void);
void _uvTxtDraw(s32 arg0);
void uvSprtFromBitmap(void *arg0, void *arg1);
void uvSprt_80230750(void *arg0, void *arg1);
s32  uvSprt_80230898(void);
void uvSprtInit(void);
void uvSprtDisplayList(uvSprite_t* sprite);
void uvSprtDrawAll(void);
void uvSprtDraw(s32 sprite_id);
void uvSprtSetBlit(uvSprite_t* sprite, s32 arg1);
s16  uvSprtGetUnk0(s32 sprite_id);
s16  uvSprtGetUnk1(s32 sprite_id);
// void uvSprtProps(s32 arg0, ? arg1, ? arg2, ? arg3);
void uvSprtUpdateUnk(uvSprite_t* sprite);
void uvSprtResetUnk(void);

#endif // PILOTWINGS64_UV_SPRITE

