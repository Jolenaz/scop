/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelless <jbelless@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 11:17:49 by jbelless          #+#    #+#             */
/*   Updated: 2017/09/04 11:17:52 by jbelless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

t_vec3	cross_vect3(const t_vec3 src, const t_vec3 dest)
{
	t_vec3 ret;

	ret.x = dest.x - src.x;
	ret.y = dest.y - src.y;
	ret.z = dest.z - src.z;
	return (normalise_vec3(ret));
}

void	print_mat4(t_mat4 a)
{
	printf("\n| %10.4f %10.4f %10.4f %10.4f |\n", a.m00, a.m01, a.m02, a.m03);
	printf("| %10.4f %10.4f %10.4f %10.4f |\n", a.m10, a.m11, a.m12, a.m13);
	printf("| %10.4f %10.4f %10.4f %10.4f |\n", a.m20, a.m21, a.m22, a.m23);
	printf("| %10.4f %10.4f %10.4f %10.4f |\n", a.m30, a.m31, a.m32, a.m33);
}

t_mat4	mat_rot_inv(t_vec3 rot)
{
	t_mat4	ret;
	t_trigo	tri;

	tri = calc_trigo(rot, -1);
	init_mat4(&ret);
	ret.m00 = tri.cos_y * tri.cos_z;
	ret.m01 = -tri.cos_y * tri.sin_z;
	ret.m02 = -tri.sin_y;
	ret.m10 = tri.sin_z * tri.cos_x - tri.sin_x * tri.cos_z * tri.sin_y;
	ret.m11 = tri.cos_x * tri.cos_z + tri.sin_x * tri.sin_z * tri.sin_y;
	ret.m12 = -tri.sin_x * tri.cos_y;
	ret.m20 = tri.sin_z * tri.sin_x + tri.cos_x * tri.cos_z * tri.sin_y;
	ret.m21 = tri.cos_z * tri.sin_x - tri.cos_x * tri.sin_z * tri.sin_y;
	ret.m22 = tri.cos_x * tri.cos_y;
	ret.m33 = 1;
	return (ret);
}

t_mat4	mat_rot(t_vec3 rot)
{
	t_mat4	ret;
	t_trigo	tri;

	tri = calc_trigo(rot, 1);
	init_mat4(&ret);
	ret.m00 = tri.cos_y * tri.cos_z;
	ret.m01 = -tri.cos_z * tri.sin_y * tri.sin_x - tri.sin_z * tri.cos_x;
	ret.m02 = -tri.cos_z * tri.sin_y * tri.cos_x + tri.sin_x * tri.sin_z;
	ret.m10 = tri.cos_y * tri.sin_z;
	ret.m11 = -tri.sin_z * tri.sin_y * tri.sin_x + tri.cos_x * tri.cos_z;
	ret.m12 = -tri.sin_z * tri.sin_y * tri.cos_x - tri.sin_x * tri.cos_z;
	ret.m20 = tri.sin_y;
	ret.m21 = tri.cos_y * tri.sin_x;
	ret.m22 = tri.cos_x * tri.cos_y;
	ret.m33 = 1;
	return (ret);
}

t_mat4	mat_trans(t_vec3 trans)
{
	t_mat4 res;

	init_mat4(&res);
	res.m00 = 1;
	res.m11 = 1;
	res.m22 = 1;
	res.m33 = 1;
	res.m03 = trans.x;
	res.m13 = trans.y;
	res.m23 = trans.z;
	return (res);
}
