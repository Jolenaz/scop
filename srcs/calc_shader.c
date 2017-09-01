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

void	calc_shader(t_env* env)
{
	t_mat4	View;
	t_mat4	Proj;
	t_mat4	WVP;
	GLint	WVP_index;
	t_mat4	World;
	GLint	coef_index;
	static float	coef = 1.0;

	coef += env->delta;
	if 	(coef < 0)
		coef = 0;
	if (coef > 1)
		coef = 1;
	env->obj->pos.x = env->obj->xmin + (env->obj->xmax - env->obj->xmin) / 2.0;
	env->obj->pos.y = env->obj->ymin + (env->obj->ymax - env->obj->ymin) / 2.0;
	env->obj->pos.z = env->obj->zmin + (env->obj->zmax - env->obj->zmin) / 2.0;
	World = mat_mult44(mat_rot_inv(env->obj->rot), mat_trans_inv(env->obj->pos));
	View = mat_mult44(mat_rot_inv(env->camera->rot), mat_trans_inv(env->camera->pos));
	env->camera->view_matrice = View;
	Proj = mat_proj(env->camera);
	WVP = mat_mult44(Proj, mat_mult44(View, World));
	WVP_index = glGetUniformLocation(env->program, "WVP");
	coef_index = glGetUniformLocation(env->program, "coef");
	//glUniform transfererer l'uniform //
	glUniformMatrix4fv(WVP_index, 1, GL_FALSE,(const GLfloat *)&WVP);
}
