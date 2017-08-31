/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelless <jbelless@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 15:04:33 by jbelless          #+#    #+#             */
/*   Updated: 2017/07/18 15:04:42 by jbelless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	create_vap(void)
{
	glVertexAttribPointer(
		vPosition,
		3,
		GL_FLOAT,
		GL_FALSE,
		sizeof(t_vertex),
		BUFFER_OFFSET(0));
	glVertexAttribPointer(
		vColor,
		4,
		GL_UNSIGNED_BYTE,
		GL_TRUE,
		sizeof(t_vertex),
		BUFFER_OFFSET(sizeof(t_vec3)));
}

void	draw(t_env *env)
{
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glDrawArrays(GL_TRIANGLES, 0, env->obj->nb_faces * 3);
	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
	SDL_GL_SwapWindow(env->mainWindow);
}

int		main_loop(t_env *env)
{
	SDL_PumpEvents();
	calc_shader(env);
	draw(env);
	if (SDL_PollEvent(&(env->evenements)))
	{
		if (env->evenements.key.keysym.sym == SDLK_c)
			return (0);
		else
			filter_key_input(env);
	}
	return (1);
}

int		main(int ac, char **av)
{
	t_env				*env;
	const t_shader_info	shaders[] = {
		{ GL_VERTEX_SHADER, "shaders/empty.vert" },
		{ GL_FRAGMENT_SHADER, "shaders/empty.frag" },
		{ GL_NONE, NULL }
	};

	env = init_world();
	open_scene(ac, av, env);
	init_sdl(env);
	create_obj(env);
	load_shader(env, shaders);
	glUseProgram(env->program);
	create_vap();

	while (main_loop(env))
	{
	}
	SDL_Quit();
	return (0);
}
