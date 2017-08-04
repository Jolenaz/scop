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

int read_v(char *line, int lnum, t_env* env)
{
	static int v_num = 0;
	static int vt_num = 0;
	static int vn_num = 0;

	if (line == NULL)
		return (create_vertex_tab(v_num, vt_num, vn_num, env));
	else if(line[1] == ' ')
		v_num++;
	else if (line[1] == 'n')
		vn_num++;
	else if (line[1] == 't')
		vt_num++;
	else
	{
		fprintf(stderr, "error: wrong fomrat wt line %d\n", lnum);
		return (0);
	}
	return (1);
}

int first_parse_obj(FILE *obj_file, t_env* env)
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
		if (line[0] == 'v' && read_v(line, lnum, env) == 0)
			return (0);
	}
	return (read_v(NULL, 0, env));
}

int second_parse_obj(FILE *obj_file, t_env* env)
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
		if (line[0] == 'v' && stock_v(line, env) == 0)
			return (print_error0("impossible to parse line",lnum));
		else if ((line[0] == 'f' || line[0] == 'g' ) && parse_face(line, env) == 0)
			return (print_error0("impossible to parse line",lnum));
		else if (strcmp(line, "usemtl") == ' ' && stock_mtl(line, env, lnum) == 0)
			return (print_error0("impossible to parse line",lnum));
		else if (strcmp(line, "mtllib") == ' ' && read_mtl_lib(line, env) == 0)
			return (print_error0("impossible to parse line",lnum));
		else
			continue;
	}
	parse_face(NULL, env);
	return (1);
}
