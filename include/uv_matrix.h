#ifndef PILOTWINGS64_UV_MATRIX
#define PILOTWINGS64_UV_MATRIX

#include <ultra64.h>
#include <uv_util.h>

typedef float Mtx4F_t[4][4];
typedef float Vec3F_t[3];

typedef union {
    Mtx4F_t mf;
    struct {
        float xx, yx, zx, wx,
              xy, yy, zy, wy,
              xz, yz, zz, wz,
              xw, yw, zw, ww;
    };
} MtxF;

void Mat4_Copy(Mtx4F_t m_dst, Mtx4F_t m_src);
void Mat3_Copy(Mtx4F_t m_dst, Mtx4F_t m_src);
void Mat4_SetIdentity(Mtx4F_t mat);
void Mat4_SetUnk1(Mtx_t mat);
void Mat4_UnkOp2(Mtx4F_t mat, float arg1, float arg2, float arg3);
void Mat4_UnkOp3(Mtx4F_t mat, float arg1, float arg2, float arg3);
void Mat4_UnkOp4(Mtx4F_t mat, Vec3F_t vec1, Vec3F_t vec2);
void Mat4_SetUnk2(Mtx4F_t mat, float arg1, float arg2, float arg3, float arg4, float arg5, float arg6);
void Mat4_SetUnk3(Mtx4F_t mat, float arg1, float arg2, float arg3, float arg4);
void Mat4_SetUnk4(Mtx4F_t mat, float arg1, float arg2, float arg3, float arg4);

#endif // PILOTWINGS64_UV_MATRIX
