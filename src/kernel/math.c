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

f32 func_8022A27C(f32 arg0, f32 arg1) {
    s32 flag;
    f32 ret;
    f32 fabsA0;
    f32 fabsA1;
    f32 temp_ft5;
    f32 absdiff;

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
    temp_ft5 = (fabsA0 / fabsA1);
    absdiff = FABS(fabsA0 - fabsA1);
    ret = (PW_PI_4 * (fabsA0 / fabsA1)) + (0.309f * absdiff * temp_ft5);

    temp_ft5 = 0; // fake store to prevent emitting additional mov instr.
    if (arg1 >= 0.0f) {
        if (flag) {
            ret = PW_PI_2 - ret;
        }
    } else if (flag) {
        ret = PW_PI_2 + ret;
    } else {
        ret = PW_PI - ret;
    }

    if (arg0 >= 0.0f) {
        return ret;
    } else {
        return -ret;
    }
}
