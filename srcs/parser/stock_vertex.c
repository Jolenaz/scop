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

int stock_texture(char *line, t_env *env)
{
	static int	vt_num = 0;
	int			ret;

	ret = sscanf(
		line,
		"vt %f %f",
		&(env->texture_tab[vt_num].x),
		&(env->texture_tab[vt_num].y)
	);
	if (ret < 2)
		return (0);
	vt_num++;
	return (1);
}

int stock_normal(char *line, t_env *env)
{
	static int	vn_num = 0;
	int			ret;

	ret = sscanf(
		line,
		"vn %f %f %f",
		&(env->normal_tab[vn_num].x),
		&(env->normal_tab[vn_num].y),
		&(env->normal_tab[vn_num].z)
	);
	if (ret < 3)
		return (0);
	vn_num++;
	return (1);
}

int	stock_v(char *line, t_env *env)
{
	if (line[1] == ' ' && stock_vertex(line, env) == 0)
		return (0);
	else if (line[1] == 't' && stock_texture(line, env) == 0)
		return (0);	
	else if (line[1] == 'n' && stock_normal(line, env) == 0)
		return (0);
	return (1);
}