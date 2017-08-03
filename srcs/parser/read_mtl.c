#include "scop.h"

int stock_mtl(char *line, t_env *env)
{
	return (1);
	line = NULL;
	env = NULL;
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

int	stock_mtl_lib(char *line, t_env * env)
{
	FILE	*mtl_file;

	if (env->mat_list != NULL)
		return (print_error1("error can use only one .mtl file"));
	while(*line != ' ')
		line++;
	line++;
	if ((mtl_file = check_mtl_file(line)) == NULL)
		return (0);
	// if (first_parse_mtl(mtl_file, env) == 0)
	// 	return(0);
	// if (second_parse_mtl(mtl_file, env) == 0)
	// 	return(0);
	fclose(mtl_file);
	return (1);
}