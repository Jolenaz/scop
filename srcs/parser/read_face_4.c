/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_face_4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelless <jbelless@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 11:50:57 by jbelless          #+#    #+#             */
/*   Updated: 2017/09/04 11:50:59 by jbelless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	attribute_val_41(t_face *ret, int val[12])
{
	ret->vertex[0] = val[0] - 1;
	ret->vertex[1] = val[3] - 1;
	ret->vertex[2] = val[6] - 1;
}

void	attribute_val_42(t_face *ret, int val[12])
{
	ret->vertex[0] = val[0] - 1;
	ret->vertex[1] = val[6] - 1;
	ret->vertex[2] = val[9] - 1;
}

t_face	*create_face_4(int attr, int val[12], char is_first)
{
	t_face *ret;

	ret = (t_face*)malloc(sizeof(t_face));
	if (attr == 9 || (attr == 12 && is_first))
		attribute_val(ret, val[0], val[3], val[6]);
	else
		attribute_val(ret, val[0], val[6], val[9]);
	ret->next = NULL;
	ret->prev = NULL;
	if (attr == 9 && is_first)
	{
		ret->next = create_face_4(attr, val, 0);
		ret->next->prev = ret;
	}
	return (ret);
}

t_face	*read_face_4(char *line)
{
	int		val[12];
	int		ret;

	ret = sscanf(line, "f %d/%d/%d %d/%d/%d %d/%d/%d %d/%d/%d",
		&(val[0]), &(val[1]), &(val[2]), &(val[3]), &(val[4]),
		&(val[5]), &(val[6]), &(val[7]), &(val[8]), &(val[9]),
		&(val[10]), &(val[11]));
	if (ret == 9 || ret == 12)
		return (create_face_4(ret, val, 1));
	return (NULL);
}
