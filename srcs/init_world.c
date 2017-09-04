/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_world.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelless <jbelless@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 15:04:53 by jbelless          #+#    #+#             */
/*   Updated: 2017/07/18 15:04:56 by jbelless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

t_obj	*new_obj(void)
{
	t_obj	*ret;

	if ((ret = (t_obj*)malloc(sizeof(t_obj))) == NULL)
		print_error1("malloc failded");
	memset(ret, 0, sizeof(t_obj));
	return (ret);
}

t_cam	*init_cam(void)
{
	t_cam *ret;

	if ((ret = (t_cam*)malloc(sizeof(t_cam))) == NULL)
		print_error1("malloc failded");
	ret->pos = init_vec3(0, 0, 2);
	ret->rot = init_vec3(0.0, 0.0, 0.0);
	ret->width = WIDTH;
	ret->height = HEIGHT;
	ret->fov = 45.0f / 180.0f * M_PI;
	ret->ratio = ret->width / ret->height;
	ret->near = 0.1;
	ret->far = 1000.0;
	return (ret);
}

t_env	*init_world(void)
{
	t_env *ret;

	if ((ret = (t_env*)malloc(sizeof(t_env))) == NULL)
		print_error1("malloc failded");
	ret->camera = init_cam();
	ret->obj = new_obj();
	ret->nb_faces = 0;
	ret->nb_vertex = 0;
	ret->vertex_tab = NULL;
	ret->delta = 0.05;
	return (ret);
}
