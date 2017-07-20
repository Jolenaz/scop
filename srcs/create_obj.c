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
	VertexData vertices[6] = {
		{{ 255, 0, 0, 255 }, { -0.90, -0.90 }}, // Triangle 1
		{{ 0, 255, 0, 255 }, { 0.85, -0.90 }},
		{{ 0, 0, 255, 255 }, { -0.90, 0.85 }},
		{{ 10, 10, 10, 255 }, { 0.90, -0.85 }}, // Triangle 2
		{{ 100, 100, 100, 255 }, { 0.90, 0.90 }},
		{{ 255, 255, 255, 255 }, { -0.85, 0.90 }}
	};


	glGenVertexArrays(NumVAOs, e->vaos);
	glBindVertexArray(e->vaos[Triangles]);
	glGenBuffers(NumBuffers, e->buffers);
	glBindBuffer(GL_ARRAY_BUFFER, e->buffers[ArrayBuffer]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
}