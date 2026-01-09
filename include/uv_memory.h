#ifndef PILOTWINGS64_UV_MEMORY
#define PILOTWINGS64_UV_MEMORY

#include <ultra64.h>
#include <uv_util.h>

void _uvMediaCopy(void* vAddr, void* devAddr, u32 nbytes);
void _uvDMA(void* vAddr, u32 devAddr, u32 nbytes);

void uvSysInit(void);

s32 _uvJumpHeap(u32* arg0);

u64 uvMemRead(void* vAddr, u32 nbytes);
void uvMemSet(void* vAddr, u8 value, u32 nbytes);

void _uvMemFreeScratch(void *addr);
void *_uvMemGetScratch(u32 size);

#endif // PILOTWINGS64_UV_MEMORY
