/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelless <jbelless@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 11:02:54 by jbelless          #+#    #+#             */
/*   Updated: 2017/09/04 11:02:56 by jbelless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	translate_vec3(t_vec3 *origin, const t_vec3 translation, float rate)
{
	origin->x += translation.x * rate;
	origin->y += translation.y * rate;
	origin->z += translation.z * rate;
}

t_vec3	new_vect3_0(float a, float b, float c)
{
	t_vec3 ret;

	ret.x = a;
	ret.y = b;
	ret.z = c;
	return (ret);
}

t_vec3	new_vect3_1(const t_vec3 src, const t_vec3 dest)
{
	t_vec3 ret;

	ret.x = dest.x - src.x;
	ret.y = dest.y - src.y;
	ret.z = dest.z - src.z;
	return (ret);
}

float	magnitude_vec3(t_vec3 src)
{
	return (sqrt(src.x * src.x + src.y * src.y + src.z * src.z));
}

t_vec3	normalise_vec3(t_vec3 src)
{
	t_vec3	ret;
	float	mg;

	ret = init_vec3(0, 0, 0);
	mg = magnitude_vec3(src);
	if (mg == 0)
		return (ret);
	ret.x = src.x / mg;
	ret.y = src.y / mg;
	ret.z = src.z / mg;
	return (ret);
}
