#include "scop.h"

char	*clear_bn(char *line)
{

	char *ptr;
	char *name;

	name = strdup(line + 7);
	ptr = name;
	while (*ptr)
	{
		if (*ptr == '\n')
			*ptr = 0;
		ptr++;
	}

	return (name);
}

int stock_mtl(char *line, t_env *env, int lnum)
{
	char *name;
	int i;

	name = clear_bn(line);
	i = 0;
	while (i < env->nb_material)
	{
		if (strcmp(env->mat_tab[i].name, name) == 0)
		{
			env->current_mat = &(env->mat_tab[i]);
			return (1);
		}
		++i;
	}
	fprintf("Warning: le materiau ligne : %d n'est pas reconnu\n", lnum);
	return (1);
}

FILE *check_mtl_file(char *line)
{
	FILE *mtl_file;
	char *path = "scene/";
	char *file;

	file = strdup(path);
	strcat(file, line);
	*(file + strlen(file) -1) = 0;
	if ((mtl_file = fopen(file, "r")) == NULL)
	{
		fprintf(stderr,"Error: le fichier %s est introuvable\n", file);
		return (NULL);
	}
	return (mtl_file);
}

int first_parse_mtl(FILE *obj_file, t_env* env)
{
	char	*line;
	size_t	linecap;
	ssize_t	linelen;

	line = NULL;
	linecap = 10000;
	while ((linelen = getline(&line, &linecap, obj_file)) > 0)
	{	
		if (strcmp(line, "newmtl") == ' ')
			env->nb_material++;
	}
	env->mat_tab = (t_material*)malloc(sizeof(t_material) * env->nb_material);
	if (env->mat_tab == NULL)
		return (print_error1("malloc fail"));
	return (1);
}

int	read_mtl_lib(char *line, t_env * env)
{
	FILE	*mtl_file;

	if (env->mat_tab != NULL)
		return (print_error1("error can use only one .mtl file"));
	while(*line != ' ')
		line++;
	line++;
	if ((mtl_file = check_mtl_file(line)) == NULL)
		return (0);
	if (first_parse_mtl(mtl_file, env) == 0)
		return(0);
	rewind(mtl_file);
	if (second_parse_mtl(mtl_file, env) == 0)
		return(0);
	fclose(mtl_file);
	return (1);
}