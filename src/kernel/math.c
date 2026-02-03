#include "common.h"

void uvSqrtF(f32 value) {
    sqrtf(value);
}

#ifndef NON_MATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/kernel/math/func_80229EC0.s")
#else
f32 func_80229EC0(f32 x) {
    f64 dx;   // sp20
    f64 xsq;  // sp18
    f64 poly; // sp10
    f64 temp_fa1;
    s32 number; // sp8
    s32 ix;     // sp4

    ix = *(s32*)&x;

    if (((ix >> 22) & 0x1FF) < 0xFF) {
        dx = x;
        if (((ix >> 22) & 0x1FF) >= 0xE6) {
            xsq = SQ(dx);

            temp_fa1 = ((((D_8024E3A0[4] * xsq) + D_8024E3A0[3]) * xsq + D_8024E3A0[2]) * xsq + D_8024E3A0[1]);

            return (dx * xsq) * temp_fa1 + dx;
        }
        return x;
    }

    if (((ix >> 22) & 0x1FF) < 310) {
        dx = x;

        number = ROUNDF(dx * 0.318309886183790691);

        dx -= ((poly = number) * 3.14159262180328369);
        dx -= (poly * 3.17865095470563921e-08);
        xsq = dx * dx;

        temp_fa1 = ((((D_8024E3A0[4] * xsq) + D_8024E3A0[3]) * xsq + D_8024E3A0[2]) * xsq + D_8024E3A0[1]);

        if (!(number & 1)) {
            return (f32)((dx * xsq) * temp_fa1 + dx);
        } else {
            return -(f32)((dx * xsq) * temp_fa1 + dx);
        }
    }
    if (x != x) {
        return 2.1401436e9f;
    }
    return 0.0f;
}
#endif

#ifndef NON_MATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/kernel/math/func_8022A080.s")
#else
// https://decomp.me/scratch/1HzdU
f32 func_8022A080(f32 x) {
    s32 ix = *(s32*)&x;
    f32 var_fv0;
    f64 fabsA0; // temp_fa0;
    f64 temp_fa1;
    f64 temp_ft4;
    f64 temp_fv0;
    f64 temp_fv1;
    s32 number;
    f32 temp;
    f64 poly;
    f64 dx;
    f64 xsq;

    // mask off exponent + mantissa MSbit of f32
    if (((ix >> 22) & 0x1FF) < 310) {
        dx = (f32)FABS(x);

        number = ROUNDF(dx * 0.318309886183790691 + 0.5);

        poly = number - 0.5;
        dx -= poly * 3.14159262180328369;
        dx -= poly * 3.17865095470563921e-08;
        xsq = dx * dx;

        temp_fa1 = ((((D_8024E3A0[4] * xsq) + D_8024E3A0[3]) * xsq + D_8024E3A0[2]) * xsq + D_8024E3A0[1]);

        if (!(number & 1)) {
            return (f32)((dx * xsq) * temp_fa1 + dx);
        } else {
            return -(f32)((dx * xsq) * temp_fa1 + dx);
        }
    }
    // NaN check
    if (x != x) {
        return 2.1401436e9f;
    }
    return 0.0f;
}
#endif

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
