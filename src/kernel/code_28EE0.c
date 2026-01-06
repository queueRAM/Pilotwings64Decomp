#include <uv_matrix.h>

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/code_28EE0/func_80227F30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/code_28EE0/func_80227F40.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/code_28EE0/_uvDbMstackPush.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/code_28EE0/_uvDbMstackPop.s")

// #pragma GLOBAL_ASM("asm/nonmatchings/kernel/code_28EE0/Mat4_Copy.s")
void Mat4_Copy(Mtx4F_t m_dst, Mtx4F_t m_src) {
    m_dst[0][0] = m_src[0][0];
    m_dst[0][1] = m_src[0][1];
    m_dst[0][2] = m_src[0][2];
    m_dst[0][3] = m_src[0][3];

    m_dst[1][0] = m_src[1][0];
    m_dst[1][1] = m_src[1][1];
    m_dst[1][2] = m_src[1][2];
    m_dst[1][3] = m_src[1][3];

    m_dst[2][0] = m_src[2][0];
    m_dst[2][1] = m_src[2][1];
    m_dst[2][2] = m_src[2][2];
    m_dst[2][3] = m_src[2][3];

    m_dst[3][0] = m_src[3][0];
    m_dst[3][1] = m_src[3][1];
    m_dst[3][2] = m_src[3][2];
    m_dst[3][3] = m_src[3][3];
}

// #pragma GLOBAL_ASM("asm/nonmatchings/kernel/code_28EE0/Mat3_Copy.s")
void Mat3_Copy(Mtx4F_t m_dst, Mtx4F_t m_src) {
    m_dst[0][0] = m_src[0][0];
    m_dst[0][1] = m_src[0][1];
    m_dst[0][2] = m_src[0][2];

    m_dst[1][0] = m_src[1][0];
    m_dst[1][1] = m_src[1][1];
    m_dst[1][2] = m_src[1][2];

    m_dst[2][0] = m_src[2][0];
    m_dst[2][1] = m_src[2][1];
    m_dst[2][2] = m_src[2][2];
}

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/code_28EE0/Mat4_Init.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/code_28EE0/func_80228180.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/code_28EE0/func_80228440.s")

// #pragma GLOBAL_ASM("asm/nonmatchings/kernel/code_28EE0/Mat4_SetIdentity.s")
void Mat4_SetIdentity(Mtx4F_t arg0) {
    arg0[0][0] = 1.0f;
    arg0[0][1] = 0.0f;
    arg0[0][2] = 0.0f;
    arg0[0][3] = 0.0f;

    arg0[1][0] = 0.0f;
    arg0[1][1] = 1.0f;
    arg0[1][2] = 0.0f;
    arg0[1][3] = 0.0f;

    arg0[2][0] = 0.0f;
    arg0[2][1] = 0.0f;
    arg0[2][2] = 1.0f;
    arg0[2][3] = 0.0f;

    arg0[3][0] = 0.0f;
    arg0[3][1] = 0.0f;
    arg0[3][2] = 0.0f;
    arg0[3][3] = 1.0f;
}

// #pragma GLOBAL_ASM("asm/nonmatchings/kernel/code_28EE0/Mat4_SetUnk1.s")
void Mat4_SetUnk1(Mtx_t mat) {
    mat[0][0] = 0x10000;
    mat[0][1] = 0;
    mat[0][2] = 1;
    mat[0][3] = 0;

    mat[1][1] = 0x10000;
    mat[1][0] = 0;
    mat[1][3] = 1;
    mat[1][2] = 0;

    mat[2][0] = 0;
    mat[2][1] = 0;
    mat[2][2] = 0;
    mat[2][3] = 0;

    mat[3][0] = 0;
    mat[3][1] = 0;
    mat[3][2] = 0;
    mat[3][3] = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/code_28EE0/Mat4_MultOp1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/code_28EE0/Mat4_MultOp2.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/code_28EE0/Mat4_UnkOp1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/code_28EE0/Mat4_UnkOp2.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/code_28EE0/Mat4_UnkOp3.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/code_28EE0/func_80229878.s")

//#pragma GLOBAL_ASM("asm/nonmatchings/kernel/code_28EE0/Mat4_UnkOp4.s")
void Mat4_UnkOp4(Mtx4F_t mtx, Vec3F_t vec1, Vec3F_t vec2) {
    f32 tmp0 = vec2[0];
    f32 tmp1 = vec2[1];
    f32 tmp2 = vec2[2];
    vec1[0] = tmp0 * mtx[0][0] + tmp1 * mtx[1][0] + tmp2 * mtx[2][0] + mtx[3][0];
    vec1[1] = tmp0 * mtx[0][1] + tmp1 * mtx[1][1] + tmp2 * mtx[2][1] + mtx[3][1];
    vec1[2] = tmp0 * mtx[0][2] + tmp1 * mtx[1][2] + tmp2 * mtx[2][2] + mtx[3][2];
}

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/code_28EE0/func_80229AA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/code_28EE0/Mat4_SetUnk2.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/code_28EE0/Mat4_SetUnk3.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/code_28EE0/Mat4_SetUnk4.s")
