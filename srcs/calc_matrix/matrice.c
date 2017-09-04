/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelless <jbelless@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 11:02:38 by jbelless          #+#    #+#             */
/*   Updated: 2017/09/04 11:02:42 by jbelless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

t_vec4	mat_mult41(t_mat4 a, t_vec4 p)
{
	t_vec4 ret;

	ret.x = a.m00 * p.x + a.m01 * p.y + a.m02 * p.z + a.m03 * p.w;
	ret.y = a.m10 * p.x + a.m11 * p.y + a.m12 * p.z + a.m13 * p.w;
	ret.z = a.m20 * p.x + a.m21 * p.y + a.m22 * p.z + a.m23 * p.w;
	ret.w = a.m30 * p.x + a.m31 * p.y + a.m32 * p.z + a.m33 * p.w;
	return (ret);
}

t_mat4	mat_mult44(t_mat4 a, t_mat4 b)
{
	t_mat4 ret;

	ret.m00 = a.m00 * b.m00 + a.m01 * b.m10 + a.m02 * b.m20 + a.m03 * b.m30;
	ret.m10 = a.m10 * b.m00 + a.m11 * b.m10 + a.m12 * b.m20 + a.m13 * b.m30;
	ret.m20 = a.m20 * b.m00 + a.m21 * b.m10 + a.m22 * b.m20 + a.m23 * b.m30;
	ret.m30 = a.m30 * b.m00 + a.m31 * b.m10 + a.m32 * b.m20 + a.m33 * b.m30;
	ret.m01 = a.m00 * b.m01 + a.m01 * b.m11 + a.m02 * b.m21 + a.m03 * b.m31;
	ret.m11 = a.m10 * b.m01 + a.m11 * b.m11 + a.m12 * b.m21 + a.m13 * b.m31;
	ret.m21 = a.m20 * b.m01 + a.m21 * b.m11 + a.m22 * b.m21 + a.m23 * b.m31;
	ret.m31 = a.m30 * b.m01 + a.m31 * b.m11 + a.m32 * b.m21 + a.m33 * b.m31;
	ret.m02 = a.m00 * b.m02 + a.m01 * b.m12 + a.m02 * b.m22 + a.m03 * b.m32;
	ret.m12 = a.m10 * b.m02 + a.m11 * b.m12 + a.m12 * b.m22 + a.m13 * b.m32;
	ret.m22 = a.m20 * b.m02 + a.m21 * b.m12 + a.m22 * b.m22 + a.m23 * b.m32;
	ret.m32 = a.m30 * b.m02 + a.m31 * b.m12 + a.m32 * b.m22 + a.m33 * b.m32;
	ret.m03 = a.m00 * b.m03 + a.m01 * b.m13 + a.m02 * b.m23 + a.m03 * b.m33;
	ret.m13 = a.m10 * b.m03 + a.m11 * b.m13 + a.m12 * b.m23 + a.m13 * b.m33;
	ret.m23 = a.m20 * b.m03 + a.m21 * b.m13 + a.m22 * b.m23 + a.m23 * b.m33;
	ret.m33 = a.m30 * b.m03 + a.m31 * b.m13 + a.m32 * b.m23 + a.m33 * b.m33;
	return (ret);
}

void	init_mat4(t_mat4 *a)
{
	char	*ptr;
	size_t	i;

	i = 0;
	ptr = (char*)a;
	while (i < sizeof(t_mat4))
	{
		ptr[i] = 0;
		++i;
	}
}
