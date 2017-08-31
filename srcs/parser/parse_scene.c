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

int stock_vertex(char *line, t_env *env)
{
	static int	v_num = 0;
	int			ret;

	ret = sscanf(
		line,
		"v %f %f %f",
		&(env->vertex_tab[v_num].x),
		&(env->vertex_tab[v_num].y),
		&(env->vertex_tab[v_num].z)
	);
	if (ret < 3)
		return (0);
	v_num++;
	return (1);
}

void	first_parse_scene(FILE *obj_file, t_env *env)
{
	char	*line;
	size_t	linecap;
	ssize_t	linelen;
	int		lnum;

	line = NULL;
	linecap = 10000;
	lnum = 0;
	while ((linelen = getline(&line, &linecap, obj_file)) > 0)
	{
		lnum++;
		while (*line == ' ' || *line == '\t')
			line++;
		if (line[0] == 'v' && line[1] == ' ')
			env->nb_vertex += 1;
	}
	env->vertex_tab = (t_vec3*)malloc(sizeof(t_vec3) * env->nb_vertex);
	if (env->vertex_tab == NULL)
		print_error1("malloc failded");
	free(line);
}

void	second_parse_scene(FILE *obj_file, t_env *env)
{
	char	*line;
	size_t	linecap;
	ssize_t	linelen;
	int		lnum;

	rewind(obj_file);
	line = NULL;
	linecap = 10000;
	lnum = 0;
	while ((linelen = getline(&line, &linecap, obj_file)) > 0)
	{
		lnum++;
		if (line[0] == 'v' && line[1] == ' ' && stock_vertex(line, env) == 0)
			print_error0("impossible to parse line", lnum);
		else if (line[0] == 'v')
			continue;
		else if (parse_face(line, env) == 0)
			print_error0("impossible to parse line", lnum);
		else
			continue;
	}
	free(line);;
}