#include "scop.h"

void	init_mtl(t_material *mat)
{
	char	*ptr;
	size_t	i;

	i = 0;
	ptr = (char *)mat;
	while(i < sizeof(t_material))
	{
		ptr[i] = 0;
		++i;
	}
}

int		mtl_lib_value(char *line, t_env *e, int i)
{
	float res[3];

	if (sscanf(line, "Kd %f %f %f", res, res + 1, res + 2) == 3)
	{
		e->mat_tab[i].Kd.r = (GLubyte)(res[0] * 255);
		e->mat_tab[i].Kd.g = (GLubyte)(res[1] * 255);
		e->mat_tab[i].Kd.b = (GLubyte)(res[2] * 255);
		return (1);
	}
	else if (sscanf(line, "Ks %f %f %f", res, res + 1, res + 2) == 3)
	{
		e->mat_tab[i].Ks.r = (GLubyte)(res[0] * 255);
		e->mat_tab[i].Ks.g = (GLubyte)(res[1] * 255);
		e->mat_tab[i].Ks.b = (GLubyte)(res[2] * 255);
		return (1);
	}
	else if (sscanf(line, "Ka %f %f %f", res, res + 1, res + 2) == 3)
	{
		e->mat_tab[i].Ka.r = (GLubyte)(res[0] * 255);
		e->mat_tab[i].Ka.g = (GLubyte)(res[1] * 255);
		e->mat_tab[i].Ka.b = (GLubyte)(res[2] * 255);
		return (1);
	}
	return (0);
}

int	mtl_lib_texture_ns(char *line, t_env *env, int i)
{
	if (strcmp(line, "map_Kd") == ' ')
	{
		env->mat_tab[i].map_Kd = strdup(line + 6);
		return (1);
	}
	else if (strcmp(line, "Ns") == ' ')
	{
		if (sscanf(line, "Ns %f", &(env->mat_tab[i].Ns)) == 1)
			return (1);
	}
	return (0);
}

int analyse_line (char *line, t_env *env)
{
	static int i = 0;
	int ret;

	ret = 0;
	if (strcmp(line, "newmtl") == ' ')
	{
		init_mtl(&(env->mat_tab[i]));
		env->mat_tab[i].name = clear_bn(line);
		++i;
	}
	else if (strcmp(line, "Kd") == ' ' ||  strcmp(line, "Ks") == ' ' ||
			strcmp(line, "Ka") == ' ')
		ret = mtl_lib_value(line, env, i);
	else if (strcmp(line, "map_Kd") == ' ' || strcmp(line, "Ns") == ' ')
		ret = mtl_lib_texture_ns(line, env, i);
	if (ret < 0)
		return (print_error0("error in parsing mtl :", ret));
	else
		return (1);
}

int	second_parse_mtl(FILE *mtl_file, t_env *env)
{
	char	*line;
	size_t	linecap;
	ssize_t	linelen;
	int		lnum;

	linecap = 10000;
	lnum = 0;
	while ((linelen = getline(&line, &linecap, mtl_file)) > 0)
	{
		lnum++;
		if (analyse_line(line , env) == 0)
			return (print_error0("Error: fail read .mtl :", lnum));	
	}
	return (1);
}