#include "common.h"

void uvSqrtF(f32 value) {
    sqrtf(value);
}

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/math/func_80229EC0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/math/func_8022A080.s")

void uvLength2D(f32 x, f32 y) {
    uvSqrtF(SQ(x) + SQ(y));
}

void uvLength3D(f32 x, f32 y, f32 z) {
    uvSqrtF(SQ(x) + SQ(y) + SQ(z));
}

#ifndef NON_MATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/kernel/math/func_8022A27C.s")
#else
#define PW_PI   3.1415927f
#define PW_PI_2 1.5707963f
#define PW_PI_4 0.7853982f

f32 func_8022A27C(f32 arg0, f32 arg1) {
    s32 flag;
    f32 ret;
    f32 pi2;
    f32 fabsA0;
    f32 fabsA1;
    f32 ratio; // sp4;
    f32 absdiff; // sp8;
    f32 temp_ft5;

    if ((arg1 == 0.0f) && (arg0 == 0.0f)) {
        return 0.0f;
    }
    fabsA1 = FABS(arg1);
    fabsA0 = FABS(arg0);
    flag = 0;
    if (fabsA1 < fabsA0) {
        temp_ft5 = fabsA1;
        fabsA1 = fabsA0;
        fabsA0 = temp_ft5;
        flag = 1;
    }
    ratio = (fabsA0 / fabsA1);
    absdiff = FABS(fabsA0 - fabsA1);
    ret = (ratio * PW_PI_4) + (0.309f * absdiff * ratio);
    pi2 = PW_PI_2;
    if (arg1 >= 0.0f) {
        if (flag) {
            ret = pi2 - ret;
        }
    } else if (flag) {
        ret = pi2 + ret;
    } else {
        ret = PW_PI - ret;
    }
    if (arg0 >= 0.0f) {
        return ret;
    }
    return -ret;
}
#endif

