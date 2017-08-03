/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_obj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelless <jbelless@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 15:00:39 by jbelless          #+#    #+#             */
/*   Updated: 2017/07/26 15:00:42 by jbelless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

int	check_ac(int ac)
{
	if (ac == 1)
		return (print_error1("Error: Utiliser un fichier .obj en argument\n"));
	else if (ac > 2)
		return (print_error1("Error: Ne peut afficher qu'un seul fichier obj\n"));
	return (1);
}

FILE *check_av(char **av)
{
	FILE *obj_file;

	if ((obj_file = fopen(av[1], "r")) == NULL)
		{
			fprintf(stderr,"Error: le fichier passer en argument est introuvable\n");
			return (NULL);
		}
	if( av[1] + strlen(av[1]) - strstr(av[1], ".obj") != 4)
		{
			fprintf(stderr,"Error: le fichier passer en argument est introuvable\n");
			return (NULL);
		}
	return (obj_file);
}

void print_vertex (t_env *env)
{
	printf("nb de vertex : %d\n", env->nb_vertex);
	printf("nb de normal : %d\n", env->nb_normal);
	printf("nb de texture : %d\n", env->nb_texture);
}

int open_obj(int ac, char **av, t_env *env)
{
	FILE *obj_file;

	if (check_ac(ac) == 0 || (obj_file = check_av(av)) == NULL)
		return (0);
	if (first_parse_obj(obj_file, env) == 0)
		return(0);
	if (second_parse_obj(obj_file, env) == 0)
		return(0);
	return (1);
}
