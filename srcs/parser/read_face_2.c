/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_face_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelless <jbelless@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 11:50:43 by jbelless          #+#    #+#             */
/*   Updated: 2017/09/04 11:50:45 by jbelless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

t_face	*create_face_2(int attr, int val[12], char is_first)
{
	t_face *ret;

	ret = (t_face*)malloc(sizeof(t_face));
	if (attr == 6 || (attr == 8 && is_first))
		attribute_val(ret, val[0], val[2], val[4]);
	else
		attribute_val(ret, val[0], val[4], val[6]);
	ret->next = NULL;
	ret->prev = NULL;
	if (attr == 6 && is_first)
	{
		ret->next = create_face_2(attr, val, 0);
		ret->next->prev = ret;
	}
	return (ret);
}

t_face	*read_face_2(char *line)
{
	int		val[12];
	int		ret;

	ret = sscanf(line, "f %d/%d %d/%d %d/%d %d/%d",
		&(val[0]), &(val[1]), &(val[2]), &(val[3]), &(val[4]),
		&(val[5]), &(val[6]), &(val[7]));
	if (ret == 6 || ret == 8)
		return (create_face_2(ret, val, 1));
	return (NULL);
}
