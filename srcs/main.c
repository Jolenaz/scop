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

void init_SDL(t_env *env)
{
	if (SDL_Init(SDL_INIT_VIDEO) == -1)
	{
		fprintf(stderr,"Error: chargement de SDL");
		return;
	}

	env->mainWindow = SDL_CreateWindow("une fenetre",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		640,
		480,
		SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);

	

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE); // use new opengl

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);

	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);


	env->mainContext = SDL_GL_CreateContext(env->mainWindow);
}

int main(){



	t_env   *env;
	const t_shader_info shaders[] = {
		{ GL_VERTEX_SHADER, "shaders/empty.vert" },
		{ GL_FRAGMENT_SHADER, "shaders/empty.frag" },
		{ GL_NONE, NULL }
	};
	int terminer = 0;

	env = init_world();
	init_SDL(env);
	create_obj(env);
	
	load_shader(env, shaders);

	glUseProgram(env->program);

	VertexData test;

	glVertexAttribPointer(vPosition, 2, GL_FLOAT, GL_FALSE, sizeof(VertexData), BUFFER_OFFSET(sizeof(test.color)));
	glEnableVertexAttribArray(vPosition);

	glVertexAttribPointer(vColor, 4, GL_UNSIGNED_BYTE, GL_TRUE, sizeof(VertexData), BUFFER_OFFSET(0));
	glEnableVertexAttribArray(vColor);

    glClear(GL_COLOR_BUFFER_BIT);

	glDrawArrays(GL_TRIANGLES, 0, 6);

    glDisableVertexAttribArray(vPosition);

    SDL_GL_SwapWindow(env->mainWindow);

	while(!terminer)
	{
		SDL_WaitEvent(&(env->evenements));
		if((env->evenements).key.keysym.sym == SDLK_c)
			terminer = 1;
	}

	SDL_Quit();
	return (0);
}
