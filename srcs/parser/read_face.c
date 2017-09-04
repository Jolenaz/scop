/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_face.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelless <jbelless@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 11:45:30 by jbelless          #+#    #+#             */
/*   Updated: 2017/09/04 11:45:33 by jbelless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	attribute_val(t_face *face, int a, int b, int c)
{
	face->vertex[0] = a - 1;
	face->vertex[1] = b - 1;
	face->vertex[2] = c - 1;
	if (a <= 0 || b <= 0 || c <= 0)
		print_error1("Error : bad face indice");
}

t_face	*read_face(char *line, t_face_type type)
{
	if (type == face_v)
		return (read_face_1(line));
	else if (type == face_v_t)
		return (read_face_2(line));
	else if (type == face_v_n)
		return (read_face_3(line));
	else if (type == face_v_t_n)
		return (read_face_4(line));
	else
		return (NULL);
}
