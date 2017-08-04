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

void	create_obj(t_env *e)
{

	// t_color rouge = {254,0,0,254};
	// t_color orange = {254,150,0,254};
	// t_color bleu = {0,10,230,254};
	// t_color vert = {80,200,40,254};
	// t_color blanc = {254,254,254,254};
	// t_color jaune = {254,240,0,254};

	// t_vec3 points[8] = {
	// 	{1,1,1},
	// 	{1,1,-1},
	// 	{1,-1,1},
	// 	{1,-1,-1},
	// 	{-1,1,1},
	// 	{-1,1,-1},
	// 	{-1,-1,1},
	// 	{-1,-1,-1}};
	

	// t_vertex vertices[36] = {
	// 	{points[2], rouge},
	// 	{points[3], rouge},
	// 	{points[1], rouge},
	// 	{points[1], rouge},
	// 	{points[0], rouge},
	// 	{points[2], rouge},
	// 	{points[5], orange},
	// 	{points[7], orange},
	// 	{points[6], orange},
	// 	{points[6], orange},
	// 	{points[4], orange},
	// 	{points[5], orange},
	// 	{points[3], blanc},
	// 	{points[2], blanc},
	// 	{points[6], blanc},
	// 	{points[6], blanc},
	// 	{points[7], blanc},
	// 	{points[3], blanc},
	// 	{points[4], jaune},
	// 	{points[0], jaune},
	// 	{points[1], jaune},
	// 	{points[1], jaune},
	// 	{points[5], jaune},
	// 	{points[4], jaune},
	// 	{points[2], bleu},
	// 	{points[0], bleu},
	// 	{points[4], bleu},
	// 	{points[4], bleu},
	// 	{points[6], bleu},
	// 	{points[2], bleu},
	// 	{points[5], vert},
	// 	{points[1], vert},
	// 	{points[3], vert},
	// 	{points[3], vert},
	// 	{points[7], vert},
	// 	{points[5], vert},
	// };

	t_vertex vertices[e->nb_faces * 3];

	t_obj	*ptr = e->first_obj;
	int		i = 0;
	while (ptr)
	{
		t_face *ptr1 = ptr->first_face;
		while(ptr1)
		{
			vertices[i].pos 	= e->vertex_tab[ptr1->vertex[0]];
			vertices[i + 1].pos = e->vertex_tab[ptr1->vertex[1]];
			vertices[i + 2].pos = e->vertex_tab[ptr1->vertex[2]];
			if (ptr->material != NULL)
			{
				vertices[i].Kd 	  = ptr->material->Kd;
				vertices[i + 1].Kd = ptr->material->Kd;
				vertices[i + 2].Kd = ptr->material->Kd;
			}
			i += 3;
			ptr1 = ptr1->next;
		}
		ptr = ptr->next;
	}

	glGenVertexArrays(NumVAOs, e->vaos);
	glBindVertexArray(e->vaos[Triangles]);
	glGenBuffers(NumBuffers, e->buffers);
	glBindBuffer(GL_ARRAY_BUFFER, e->buffers[ArrayBuffer]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

}
