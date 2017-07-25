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

void calc_shader(t_env* env)
{
	t_mat4	View;
	t_mat4	Proj;
	t_mat4	VP;
	GLint	VP_index;

	View = mat_mult44(mat_rot_inv(env->camera->rot), mat_trans_inv(env->camera->pos));
	env->camera->view_matrice = View;
	Proj = mat_proj(env->camera);
	VP = mat_mult44(Proj, View);
	VP_index = glGetUniformLocation(env->program, "VP");
	glUniformMatrix4fv(VP_index, 1, GL_FALSE,(const GLfloat *)&VP);
}
