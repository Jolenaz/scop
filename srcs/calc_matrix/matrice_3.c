/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelless <jbelless@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 11:18:00 by jbelless          #+#    #+#             */
/*   Updated: 2017/09/04 11:18:04 by jbelless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

t_trigo	calc_trigo(t_vec3 rot, int sign)
{
	t_trigo	tri;

	tri.cos_x = cos(sign * rot.x * M_PI / 180.0f);
	tri.sin_x = sin(sign * rot.x * M_PI / 180.0f);
	tri.cos_y = cos(sign * rot.y * M_PI / 180.0f);
	tri.sin_y = sin(sign * rot.y * M_PI / 180.0f);
	tri.cos_z = cos(sign * rot.z * M_PI / 180.0f);
	tri.sin_z = sin(sign * rot.z * M_PI / 180.0f);
	return (tri);
}

t_mat4	mat_trans_inv(t_vec3 trans)
{
	t_mat4 res;

	init_mat4(&res);
	res.m00 = 1;
	res.m11 = 1;
	res.m22 = 1;
	res.m33 = 1;
	res.m03 = -trans.x;
	res.m13 = -trans.y;
	res.m23 = -trans.z;
	return (res);
}

t_mat4	mat_scale_inv(t_vec3 scal)
{
	t_mat4 res;

	init_mat4(&res);
	if (scal.x == 0 || scal.y == 0 || scal.z == 0)
		return (res);
	res.m00 = 1 / scal.x;
	res.m11 = 1 / scal.y;
	res.m22 = 1 / scal.z;
	res.m33 = 1;
	return (res);
}

t_mat4	mat_scale(t_vec3 scal)
{
	t_mat4 res;

	init_mat4(&res);
	res.m00 = scal.x;
	res.m11 = scal.y;
	res.m22 = scal.z;
	res.m33 = 1;
	return (res);
}

t_mat4	mat_proj(t_cam *cam)
{
	t_mat4 res;

	init_mat4(&res);
	if (cam->fov == 0 || cam->ratio == 0 || cam->far == cam->near)
		return (res);
	res.m00 = 1 / tan(cam->fov / 2.0f);
	res.m11 = res.m00;
	res.m22 = -(cam->far + cam->near) / (cam->far - cam->near);
	res.m32 = -1;
	res.m23 = -2 * cam->far * cam->near / (cam->far - cam->near);
	return (res);
}
