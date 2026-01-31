#ifndef PILOTWINGS64_UV_GRAPHICS
#define PILOTWINGS64_UV_GRAPHICS

#include <PR/ultratypes.h>
#include <PR/gbi.h>
#include <uv_util.h>
#include <uv_matrix.h>

typedef struct {
    s32 unk0;
    s16 unk4;
    s16 unk6;
    s32 unk8;
} uvGfxState_t;

typedef struct {
    s32 unk0;
    s32 unk4;
    s16 unk8;
    s16 unkA;
    s16 unkC;
    s16 unkE;
    u8 pad[0x10];
} UnkStruct_80222EE8_t;

void uvGfxInit(void);
void uvGfxBegin(void);
void uvGfx_80220CA0(f32 arg0);
void uvGfx_80220E0C(void);
void uvGfxPushMtxView(Mtx src);
void uvGfxPushMtxProj(Mtx src);
void uvGfxDisplayList(Gfx* dl);
void uvGfx_802210E8(void *arg0);
void uvGfxStateDraw(uvGfxState_t* arg0);
void uvGfxPushMtxUnk(Mtx4F*);
void uvGfxClampLook(LookAt*, f32, f32, f32, f32, f32, f32, f32, f32, f32);
void uvGfxLookAt(Mtx4F* arg0);
void uvGfx_80222100(Mtx4F*);
void uvGfx_80222170(s32 arg0);
void uvGfxEnd(void);
void uvGfxClearScreen(u8 r, u8 g, u8 b, u8 a);
void uvGfx_80222A98(void);
void uvGfx_80222C94(s32 arg0);
void uvGfx_80222D78(s32 arg0, s32 arg1);
void uvGfx_80222E90(s32 arg0);
void uvGfx_80222EE8(UnkStruct_80222EE8_t *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
void uvGfx_80223094(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
void uvGfx_802230CC(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
void uvGfx_80223114(s32 arg0);
void uvGfxMstackPushUnk(Mtx4F* src);
void uvGfxMstackPush(Mtx src);
Mtx* uvGfxMstackTop(void);
void uvGfx_80223408(f32 arg0);
f32  uvGfx_80223414(void);
void uvGfx_8022345C(Mtx4F*, s32);
void uvGfx_802234F4(Mtx4F *arg0, s32 arg1);
void uvGfx_802235A4(s32 arg0, Mtx mat);
void uvGfx_802236A8(void);
void uvGfx_802236CC(Mtx4F *arg0);
s32  uvGfxGetCnt(u32 arg0);
void uvGfxStatePush(void);
void uvGfxStatePop(void);
void uvGfxSetFlags(s32 flags);
void uvGfxClearFlags(s32 flags);
void uvGfx_80223A28(s32 flags);
void uvGfx_80223A64(s32 arg0, s32 arg1);
void uvGfx_80223B80(void);
void uvGfx_80223BB8(s32 arg0);
void uvGfx_80223BF4(s32 arg0);
void uvGfx_80223C00(void);
void uvCopyFrameBuf(s32 fb_id);

#endif // PILOTWINGS64_UV_GRAPHICS
