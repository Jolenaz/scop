#include "scop.h"

t_mat2 *matrixMult22(t_mat2 A, t_mat2 B)
{
    t_mat2 *ret;

    ret = (t_mat2*)malloc(sizeof(t_mat2));
    ret->_00 = A._00 * B._00 + A._01 * B._10;
    ret->_01 = A._00 * B._01 + A._01 * B._11;
    ret->_10 = A._10 * B._00 + A._11 * B._10;
    ret->_11 = A._10 * B._01 + A._11 * B._11;
    return (ret);
}

t_mat2 *matrixAdd22(t_mat2 A, t_mat2 B)
{
    t_mat2 *ret;

    ret = (t_mat2*)malloc(sizeof(t_mat2));
    ret->_00 = A._00 + B._00;
    ret->_01 = A._01 + B._01;
    ret->_10 = A._10 + B._10;
    ret->_11 = A._11 + B._11;
    return (ret);
}


t_vec2 *matrixMult21(t_mat2 A, t_vec2 B)
{
    t_vec2 *ret;

    ret = (t_vec2*)malloc(sizeof(t_vec2));
    ret->x = A._00 * B.x + A._01 * B.y;
    ret->y = A._10 * B.x + A._11 * B.y;
    return (ret);
}

t_mat3 *matrixMult33(t_mat3 A, t_mat3 B)
{
    t_mat3 *ret;

    ret = (t_mat3*)malloc(sizeof(t_mat3));
    ret->_00 = A._00 * B._00 + A._01 * B._10 + A._02 * B._20;
    ret->_01 = A._00 * B._01 + A._01 * B._11 + A._02 * B._21;
    ret->_02 = A._00 * B._02 + A._01 * B._12 + A._02 * B._22;
    ret->_10 = A._10 * B._00 + A._11 * B._10 + A._12 * B._20;
    ret->_11 = A._10 * B._01 + A._11 * B._11 + A._12 * B._21;
    ret->_12 = A._10 * B._02 + A._11 * B._12 + A._12 * B._22;
    ret->_20 = A._20 * B._00 + A._21 * B._10 + A._22 * B._20;
    ret->_21 = A._20 * B._01 + A._21 * B._11 + A._22 * B._21;
    ret->_22 = A._20 * B._02 + A._21 * B._12 + A._22 * B._22;
    return (ret);
}

t_vec3 *matrixMult31(t_mat3 A, t_vec3 B)
{
    t_vec3 *ret;

    ret = (t_mat3*)malloc(sizeof(t_mat3));
    ret->x = A._00 * B.x + A._01 * B.y + A._02 * B.z;
    ret->y = A._10 * B.x + A._11 * B.y + A._12 * B.z;
    ret->z = A._20 * B.x + A._21 * B.y + A._22 * B.z;
    return (ret);
}

