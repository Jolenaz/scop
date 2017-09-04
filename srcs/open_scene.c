/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelless <jbelless@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 12:10:50 by jbelless          #+#    #+#             */
/*   Updated: 2017/09/04 12:10:52 by jbelless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	check_ac(int ac)
{
	if (ac == 1)
		print_error1("Utiliser un fichier .obj en argument\n");
	else if (ac > 2)
		print_error1("Ne peut afficher qu'un seul fichier obj\n");
}

FILE	*check_av(char **av)
{
	FILE *obj_file;

	if ((obj_file = fopen(av[1], "r")) == NULL)
		print_error1("le fichier passer en argument est introuvable\n");
	if (av[1] + strlen(av[1]) - strstr(av[1], ".obj") != 4)
		print_error1("le fichier passer en argument doit être un .obj\n");
	return (obj_file);
}

void	open_scene(int ac, char **av, t_env *env)
{
	FILE *obj_file;

	check_ac(ac);
	obj_file = check_av(av);
	first_parse_scene(obj_file, env);
	second_parse_scene(obj_file, env);
}
