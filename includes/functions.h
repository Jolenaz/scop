/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelless <jbelless@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 15:05:48 by jbelless          #+#    #+#             */
/*   Updated: 2017/07/18 15:05:50 by jbelless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

t_env   *init_world();
void    load_shader(t_env *e, const t_shader_info *s);
void	create_obj(t_env *e);
/* Operations matricielles */
t_vec4	matMult41(t_mat4 A, t_vec4 p);
t_mat4	matMult44(t_mat4 A, t_mat4 B);
void	initMat4(t_mat4 *A);
void	printMat4(t_mat4 A);
t_mat4	matRotInv(t_vec3 rot);
t_mat4	matRot(t_vec3 rot);
t_mat4	matTransInv(t_vec3 rot);
t_mat4	matTrans(t_vec3 rot);
t_mat4	matScaleInv(t_vec3 rot);
t_mat4	matScale(t_vec3 rot);
t_mat4 matProj(t_cam *cam);

#endif
