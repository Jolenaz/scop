/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_shader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelless <jbelless@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 11:50:31 by jbelless          #+#    #+#             */
/*   Updated: 2017/07/25 11:50:34 by jbelless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	calc_shader(t_env *env)
{
	t_mat4			wvp[4];
	GLint			wvp_index;
	GLint			coef_index;
	static float	coef = 1.0;

	coef += env->delta;
	if (coef < 0)
		coef = 0;
	if (coef > 1)
		coef = 1;
	env->obj->pos.x = env->obj->xmin + (env->obj->xmax - env->obj->xmin) / 2.0;
	env->obj->pos.y = env->obj->ymin + (env->obj->ymax - env->obj->ymin) / 2.0;
	env->obj->pos.z = env->obj->zmin + (env->obj->zmax - env->obj->zmin) / 2.0;
	wvp[1] = mat_mult44(mat_rot_inv(env->obj->rot),
							mat_trans_inv(env->obj->pos));
	wvp[2] = mat_mult44(mat_rot_inv(env->camera->rot),
								mat_trans_inv(env->camera->pos));
	env->camera->view_matrice = wvp[2];
	wvp[3] = mat_proj(env->camera);
	wvp[0] = mat_mult44(wvp[3], mat_mult44(wvp[2], wvp[1]));
	wvp_index = glGetUniformLocation(env->program, "WVP");
	coef_index = glGetUniformLocation(env->program, "fcoef");
	glUniform1f(coef_index, coef);
	glUniformMatrix4fv(wvp_index, 1, GL_FALSE, (const GLfloat *)&(wvp[0]));
}
