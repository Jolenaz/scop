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

t_vec3 init_vec3(float x, float y, float z)
{
    t_vec3 res;
    res.x = x;
    res.y = y;
    res.z = z;
    return (res);
}

t_cam *init_cam()
{
    t_cam *ret;

    ret = (t_cam*)malloc(sizeof(t_cam));
    ret->pos = init_vec3(0.0,0.0,10.0);
    ret->rot = init_vec3(0.0,0.0,0.0);
    ret->fov = 60;
    ret->near = 0.0;
    ret->far = 1000.0;
    return ret;
}

t_env   *init_world()
{
    t_env *ret;
    
    ret = (t_env*)malloc(sizeof(t_env));
    ret->camera = init_cam();

    return (ret);
}
