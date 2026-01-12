#ifndef PILOTWINGS64_UV_GRAPHICS
#define PILOTWINGS64_UV_GRAPHICS

#include <ultra64.h>
#include <uv_util.h>

void uvGfxBegin(void);
void uvGfxStateDraw(void *arg0);
void uvGfxEnd(void);
s32 uvGfxGetCnt(u32 arg0);
void uvGfxStatePush(void);
void uvGfxStatePop(void);
void func_8022427C(u32 arg0);

#endif // PILOTWINGS64_UV_GRAPHICS
