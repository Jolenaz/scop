/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_obj.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelless <jbelless@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 11:33:45 by jbelless          #+#    #+#             */
/*   Updated: 2017/07/19 11:33:47 by jbelless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

t_color		rand_color(t_color col)
{
	t_color res;

	res.r = (col.r + 80) % 255;
	res.g = (col.g + 80) % 255;
	res.b = (col.b + 80) % 255;
	return (res);
}

t_color		init_color(void)
{
	t_color res;

	res.r = 110;
	res.g = 110;
	res.b = 110;
	return (res);
}

void		check_vert_index(t_face *face, t_env *env)
{
	if (face->vertex[0] >= env->nb_vertex ||
		face->vertex[1] >= env->nb_vertex ||
		face->vertex[2] >= env->nb_vertex)
		print_error1("Error : bad face indice");
}

t_vertex	fill_vertice(t_env *e, t_face *face, int ind, t_color stand)
{
	t_vertex ret;

	ret.kd = stand;
	ret.pos = e->vertex_tab[face->vertex[ind]];
	return (ret);
}

void		create_obj(t_env *e)
{
	t_vertex	vertices[e->obj->nb_faces * 3];
	t_color		stand;
	int			i;
	t_face		*ptr;

	stand = init_color();
	i = 0;
	ptr = e->obj->first_face;
	while (ptr)
	{
		check_vert_index(ptr, e);
		vertices[i] = fill_vertice(e, ptr, 0, stand);
		vertices[i + 1] = fill_vertice(e, ptr, 1, stand);
		vertices[i + 2] = fill_vertice(e, ptr, 2, stand);
		stand = rand_color(stand);
		i += 3;
		ptr = ptr->next;
	}
	glGenVertexArrays(NumVAOs, e->vaos);
	glBindVertexArray(e->vaos[Triangles]);
	glGenBuffers(NumBuffers, e->buffers);
	glBindBuffer(GL_ARRAY_BUFFER, e->buffers[ArrayBuffer]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
}
