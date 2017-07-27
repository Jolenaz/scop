/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_obj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelless <jbelless@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 15:00:30 by jbelless          #+#    #+#             */
/*   Updated: 2017/07/26 15:00:33 by jbelless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

int	read_v_line(char *line, t_env* env)
{
	if (state_start(line) == 0)
		return (0);
	if (g_current_v == text)
		env->obj_carac.nb_texture++;
	else if (g_current_v == norm)
		env->obj_carac.nb_normal++;
	else if (g_current_v == vert)
		env->obj_carac.nb_vertex++;
	else
	{
		fprintf(stderr, "probleme dans le typage de la v line");
		return (0);
	}
	return (1);
}

int read_line(char *line, int lnum, t_env* env)
{
	if (line[0] == 'v' && read_v_line(line, env) == 0)
	{
		fprintf(stderr, "Error: impossible to parse vertex on ligne %d\n", lnum);
		return (0);
	}
	return (1);
}

int parse_obj(FILE *obj_file, t_env* env)
{
	char	*line;
	size_t	linecap;
	ssize_t	linelen;
	int		lnum;

	line = NULL;
	linecap = 1000000;
	lnum = 0;
	while ((linelen = getline(&line, &linecap, obj_file)) > 0)
	{	
		++lnum;
		if (line[0] == '#')
			continue;
		if (read_line(line, lnum, env) == 0)
			return (0);
	}
	return (1);
}
