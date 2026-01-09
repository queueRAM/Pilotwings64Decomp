#include <uv_memory.h>

typedef struct {
    u32 start;
    u32 end;
} Struct802B8830;

extern s32 D_802B8820;
extern Struct802B8830 D_802B8830[];

// flags to determine if any of 3 scratch regions are in use
extern s32 D_802B8920[3];
extern s32 D_802B8934;


#pragma GLOBAL_ASM("asm/nonmatchings/kernel/memory/func_8022A3C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/memory/func_8022A47C.s")

//#pragma GLOBAL_ASM("asm/nonmatchings/kernel/memory/uvSysInit.s")
void uvSysInit(void) {
    s32 j;
    s32 i;

    for (i = 0; i < D_802B8820; i++) {
        for (j = 0; j < D_802B8820; j++) {
            if (i != j) {
                if ((D_802B8830[j].start < D_802B8830[i].end) && (D_802B8830[i].start < D_802B8830[j].end)) {
                    if (1) { // fakematch
                        _uvDebugPrintf("uvSysInit: memory overlap with blocks %d and %d\n", i, j);
                        _uvDebugPrintf("           [ 0x%x , 0x%x ] and [ 0x%x , 0x%x ]\n", D_802B8830[i].start, D_802B8830[i].end, D_802B8830[j].start, D_802B8830[j].end);
                    }
                    break;
                }
            }
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/memory/func_8022A5F4.s")

//#pragma GLOBAL_ASM("asm/nonmatchings/kernel/memory/_uvJumpHeap.s")
s32 _uvJumpHeap(u32* arg0) {
    s32 iter;
    s32 retVal;
    Struct802B8830* block;

    retVal = TRUE;
    for (iter = 0; iter < D_802B8820; iter++) {
        block = &D_802B8830[iter];
        if ((*arg0 >= block->start) && (*arg0 < block->end)) {
            iter = 0;
            retVal = FALSE;
            *arg0 = block->end;
            if (D_802B8934 != 0) {
                _uvDebugPrintf("_uvJumpHeap: jumping to txt img data 0x%x\n", *arg0);
            }
        }
    }
    return retVal;
}

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/memory/_uvMediaCopy.s")

// #pragma GLOBAL_ASM("asm/nonmatchings/kernel/memory/uvMemRead.s")
u64 uvMemRead(void* vAddr, u32 nbytes) {
    u64 out;
    u64 temp1;
    s64 temp2;
    u8* src;

    src = vAddr;
    if ((nbytes != 1) && (nbytes != 2) && (nbytes != 4) && (nbytes != 8)) {
        _uvDebugPrintf("uvMemRead was called with an invalid size\n");
        out = 0;
    } else if ((u32)src & 0x80000000) {
        out = src[0];
        if (nbytes >= 2U) {
            temp1 = out << 8;
            out = temp1 | src[1];
        }
        if (nbytes >= 3U) {
            temp1 = out << 16;
            out = temp1 | (src[2] << 8) | src[3];
        }
        if (nbytes >= 5U) {
            temp1 = out << 32;
            out = temp1 | (src[4] << 0x18) | (src[5] << 0x10) | (src[6] << 8) | src[7];
        }
    } else {
        _uvMediaCopy(&temp2, src, nbytes);
        out = uvMemRead((u8*)&temp2, nbytes);
    }
    return out;
}

// #pragma GLOBAL_ASM("asm/nonmatchings/kernel/memory/uvMemSet.s")
void uvMemSet(void* vAddr, u8 value, u32 nbytes) {
    u32 count;
    u8* dest;

    count = 0;
    if (nbytes != 0) {
        dest = vAddr;
        do {
            count += 1;
            *dest++ = value;
        } while (count < nbytes);
    }
}


#pragma GLOBAL_ASM("asm/nonmatchings/kernel/memory/func_8022AAB4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/memory/_uvMemOverAlloc.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/memory/_uvMemAlloc.s")

//#pragma GLOBAL_ASM("asm/nonmatchings/kernel/memory/_uvMemFreeScratch.s")
void _uvMemFreeScratch(void *addr) {
    switch ((u32)addr) {
        case 0x803DA800:
            D_802B8920[0] = 0;
            break;
        case 0x800DA800:
            D_802B8920[1] = 0;
            break;
        case 0x80100000:
            D_802B8920[2] = 0;
            break;
        default:
            _uvDebugPrintf("_uvMemFreeScratch: 0x%x not a scratch area\n", addr);
            break;
    }
}

//#pragma GLOBAL_ASM("asm/nonmatchings/kernel/memory/_uvMemGetScratch.s")
void *_uvMemGetScratch(u32 size) {
    if (size >= 0x25800) {
        _uvDebugPrintf("_uvMemGetScratch: size too big ( %d bytes )\n", size);
    } else {
        // returns need to be on same line to match reordering
        if (D_802B8920[0] == 0) {
            D_802B8920[0] = 1; return 0x803DA800;
        } else if (D_802B8920[1] == 0) {
            D_802B8920[1] = 1; return 0x800DA800;
        } else if (D_802B8920[2] == 0) {
            D_802B8920[2] = 1; return 0x80100000;
        } else {
            _uvDebugPrintf("_uvMemGetScratch: all scratch areas are full\n", size);
        }
    }
    return NULL;
}

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/memory/_uvMemGetBlocks.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/memory/uvLevelInit.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/memory/func_8022B078.s")
