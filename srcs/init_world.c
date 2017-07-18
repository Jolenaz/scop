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

t_obj *demo_cube()
{
    t_obj *ret;

    ret = (t_obj*)malloc(sizeof(t_obj));
    ret->vert_nb = 8;
    ret->pos.x = 0;
    ret->pos.y = 0;
    ret->pos.x = 0;
    ret->rot.x = 0;
    ret->rot.y = 0;
    ret->rot.x = 0;
    ret->vertexes = (t_vertex*)malloc(sizeof(t_vertex) * 8);
    ret->vertexes[0].pos = init_vec3(1.0,1.0,1.0);
    ret->vertexes[1].pos = init_vec3(1.0,1.0,-1.0);
    ret->vertexes[2].pos = init_vec3(1.0,-1.0,1.0);
    ret->vertexes[3].pos = init_vec3(1.0,-1.0,-1.0);
    ret->vertexes[4].pos = init_vec3(-1.0,1.0,1.0);
    ret->vertexes[5].pos = init_vec3(-1.0,1.0,-1.0);
    ret->vertexes[6].pos = init_vec3(-1.0,-1.0,1.0);
    ret->vertexes[7].pos = init_vec3(-1.0,-1.0,-1.0);
    return (ret);
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

GLuint *init_shader()
{
	GLuint *res;
	int i;

	i = 0;
	res = (GLuint*)malloc(sizeof(GLuint) * NB_SHADERS);
	while(i < NB_SHADERS)
	{
		res[i] = glCreateShader(g_shaders_type[i]);
		++i;
	}
	return res;
}

t_env   *init_world()
{
    t_env *ret;
    
    ret = (t_env*)malloc(sizeof(t_env));
    ret->objets  = demo_cube();
    ret->camera = init_cam();
	ret->shaders = init_shader();

    return (ret);
}
