#include "scop.h"

t_vec4 matMult41 (t_mat4 A, t_vec4 p)
{
	t_vec4 ret;

	ret.x = A._00 * p.x + A._01 * p.y + A._02 * p.z + A._03 * p.w;
	ret.y = A._10 * p.x + A._11 * p.y + A._12 * p.z + A._13 * p.w;
	ret.z = A._20 * p.x + A._21 * p.y + A._22 * p.z + A._23 * p.w;
	ret.w = A._30 * p.x + A._31 * p.y + A._32 * p.z + A._33 * p.w;
	return (ret);
}

t_mat4 matMult44(t_mat4 A, t_mat4 B)
{
	t_mat4 ret;

	ret._00 = A._00 * B._00 + A._01 * B._10 + A._02 * B._20 + A._03 * B._30;
	ret._10 = A._10 * B._00 + A._11 * B._10 + A._12 * B._20 + A._13 * B._30;
	ret._20 = A._20 * B._00 + A._21 * B._10 + A._22 * B._20 + A._23 * B._30;
	ret._30 = A._30 * B._00 + A._31 * B._10 + A._32 * B._20 + A._33 * B._30;
	ret._01 = A._00 * B._01 + A._01 * B._11 + A._02 * B._21 + A._03 * B._31;
	ret._11 = A._10 * B._01 + A._11 * B._11 + A._12 * B._21 + A._13 * B._31;
	ret._21 = A._20 * B._01 + A._21 * B._11 + A._22 * B._21 + A._23 * B._31;
	ret._31 = A._30 * B._01 + A._31 * B._11 + A._32 * B._21 + A._33 * B._31;
	ret._02 = A._00 * B._02 + A._01 * B._12 + A._02 * B._22 + A._03 * B._32;
	ret._12 = A._10 * B._02 + A._11 * B._12 + A._12 * B._22 + A._13 * B._32;
	ret._22 = A._20 * B._02 + A._21 * B._12 + A._22 * B._22 + A._23 * B._32;
	ret._32 = A._30 * B._02 + A._31 * B._12 + A._32 * B._22 + A._33 * B._32;
	ret._03 = A._00 * B._03 + A._01 * B._13 + A._02 * B._23 + A._03 * B._33;
	ret._13 = A._10 * B._03 + A._11 * B._13 + A._12 * B._23 + A._13 * B._33;
	ret._23 = A._20 * B._03 + A._21 * B._13 + A._22 * B._23 + A._23 * B._33;
	ret._33 = A._30 * B._03 + A._31 * B._13 + A._32 * B._23 + A._33 * B._33;
	return (ret);
}

void	initMat4(t_mat4 *A)
{
	char	*ptr;
	size_t	i;

	i = 0;
	ptr = (char*)A;
	while (i < sizeof(t_mat4))
	{
		ptr[i] = 0;
		++i;
	}
}

void printMat4(t_mat4 A)
{
	printf("\n| %10.4f %10.4f %10.4f %10.4f |\n",A._00,A._01,A._02,A._03);
	printf("| %10.4f %10.4f %10.4f %10.4f |\n",A._10,A._11,A._12,A._13);
	printf("| %10.4f %10.4f %10.4f %10.4f |\n",A._20,A._21,A._22,A._23);
	printf("| %10.4f %10.4f %10.4f %10.4f |\n",A._30,A._31,A._32,A._33);
}

t_mat4	matRotInv(t_vec3 rot)
{
	t_mat4 ret;
	const float coX = cos(-rot.x * M_PI / 180.0f);
	const float siX = sin(-rot.x * M_PI / 180.0f);
	const float coY = cos(-rot.y * M_PI / 180.0f);
	const float siY = sin(-rot.y * M_PI / 180.0f);
	const float coZ = cos(-rot.z * M_PI / 180.0f);
	const float siZ = sin(-rot.z * M_PI / 180.0f);
	
	initMat4(&ret);
	ret._00 = coY * coZ;
	ret._01 = -coY * siZ;
	ret._02 = -siY;
	ret._10 = siZ * coX - siX * coZ * siY;
	ret._11 = coX * coZ + siX * siZ * siY;
	ret._12 = -siX * coY;
	ret._20 = siZ * siX + coX * coZ * siY;
	ret._21 = coZ * siX - coX * siZ * siY;
	ret._22 = coX * coY;
	ret._33 = 1;
	return (ret);
}

t_mat4	matRot(t_vec3 rot)
{
	t_mat4 ret;
	const float coX = cos(rot.x * M_PI / 180.0f);
	const float siX = sin(rot.x * M_PI / 180.0f);
	const float coY = cos(rot.y * M_PI / 180.0f);
	const float siY = sin(rot.y * M_PI / 180.0f);
	const float coZ = cos(rot.z * M_PI / 180.0f);
	const float siZ = sin(rot.z * M_PI / 180.0f);
	
	initMat4(&ret);
	ret._00 = coY * coZ;
	ret._01 = -coZ * siY * siX - siZ * coX;
	ret._02 = -coZ * siY * coX + siX * siZ;
	ret._10 = coY * siZ;
	ret._11 = -siZ * siY * siX + coX * coZ;
	ret._12 = -siZ * siY * coX-siX * coZ;
	ret._20 = siY;
	ret._21 = coY * siX;
	ret._22 = coX * coY;
	ret._33 = 1;
	return (ret);
}

t_mat4 matTrans(t_vec3 trans)
{
	t_mat4 res;

	initMat4(&res);
	res._00 = 1;
	res._11 = 1;
	res._22 = 1;
	res._33 = 1;
	res._03 = trans.x;
	res._13 = trans.y;
	res._23 = trans.z;
	return (res);
}

t_mat4 matTransInv(t_vec3 trans)
{
	t_mat4 res;

	initMat4(&res);
	res._00 = 1;
	res._11 = 1;
	res._22 = 1;
	res._33 = 1;
	res._03 = -trans.x;
	res._13 = -trans.y;
	res._23 = -trans.z;
	return (res);
}

t_mat4 matScaleInv(t_vec3 scal)
{
	t_mat4 res;

	initMat4(&res);
	if (scal.x == 0 || scal.y == 0 ||scal.z == 0)
		return (res);
	res._00 = 1 / scal.x;
	res._11 = 1 / scal.y;
	res._22 = 1 / scal.z;
	res._33 = 1;
	return (res);
}

t_mat4 matScale(t_vec3 scal)
{
	t_mat4 res;

	initMat4(&res);
	res._00 = scal.x;
	res._11 = scal.y;
	res._22 = scal.z;
	res._33 = 1;
	return (res);
}

t_mat4 matProj(t_cam *cam)
{
	t_mat4 res;

	initMat4(&res);
	if (cam->fov == 0 || cam->ratio == 0 || cam->far == cam->near)
		return(res);
	res._00 = 1 / tan(cam->fov / 2.0f);
	res._11 = res._00;
	res._22 = -(cam->far + cam->near) / (cam->far - cam->near);
	res._32 = -1;
	res._23 = -2 * cam->far * cam->near / (cam->far - cam->near);
	return (res);
}

// t_mat4 matProj(t_cam *cam)
// {
// 	t_mat4 res;

// 	initMat4(&res);
// 	if (cam->width == 0 || cam->height == 0 || cam->far == cam->near)
// 		return (res);
// 	res._00 =  cam->near / cam->width;
// 	res._11 =  cam->near / cam->height;
// 	res._22 = -(cam->far + cam->near) / (cam->far - cam->near);
// 	res._32 = -1;
// 	res._23 = 2 * cam->far * cam->near / (cam->far - cam->near);
// 	return (res);
// }