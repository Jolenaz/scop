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

t_color rand_color(t_color col)
{
	t_color res;

	res.r = (col.r + 80) % 255;
	res.g = (col.g + 80) % 255;
	res.b = (col.b + 80) % 255;
	return (res);
}

void	create_obj(t_env *e)
{
	t_vertex vertices[e->obj->nb_faces * 3];
	t_color stand;
	
	stand.r = 110;
	stand.g = 110;
	stand.b = 110;
	int		i = 0;
	t_face *ptr;
	ptr = e->obj->first_face;
	while(ptr)
	{
		vertices[i].pos 	= e->vertex_tab[ptr->vertex[0]];
		vertices[i + 1].pos = e->vertex_tab[ptr->vertex[1]];
		vertices[i + 2].pos = e->vertex_tab[ptr->vertex[2]];
		vertices[i].Kd = stand;
		vertices[i + 1].Kd = stand;
		vertices[i + 2].Kd = stand;
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
