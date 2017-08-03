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

t_cam *init_cam()
{
    t_cam *ret;

    ret = (t_cam*)malloc(sizeof(t_cam));
    ret->pos = init_vec3(0,0,2);
    ret->rot = init_vec3(0.0,0.0,0.0);
    ret->width = WIDTH;
	ret->height = HEIGHT;
	ret->fov = 45.0f / 180.0f * M_PI;
	ret->ratio = ret->width / ret->height;
    ret->near = 0.1;
    ret->far = 100.0;
    return ret;
}

t_env   *init_world()
{
    t_env *ret;
    
    ret = (t_env*)malloc(sizeof(t_env));
    ret->camera = init_cam();
	ret->first_obj = NULL;
	ret->last_obj = NULL;
	ret->nb_faces = 0;
	ret->mat_list = NULL;

    return (ret);
}
