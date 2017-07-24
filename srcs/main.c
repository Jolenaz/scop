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
	//create_obj(env);

	static const GLfloat g_vertex_buffer_data[] = {
		-1.0f, -1.0f, 0.0f,
		1.0f, -1.0f, 0.0f,
		0.0f,  1.0f, 0.0f,
	};
	GLuint VertexArrayID;
	glGenVertexArrays(1, &VertexArrayID);
	glBindVertexArray(VertexArrayID);
	GLuint vertexbuffer;
	glGenBuffers(1, &vertexbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);
	
	load_shader(env, shaders);

	glUseProgram(env->program);




	//VertexData test;


	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	glVertexAttribPointer(
	0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
	3,                  // size
	GL_FLOAT,           // type
	GL_FALSE,           // normalized?
	0,                  // stride
	(void*)0            // array buffer offset
	);



	while(!terminer)
	{
	t_mat4	View;
	t_mat4	Proj;
	t_mat4	VP;
	GLint	VP_index;

	View = matMult44(matRotInv(env->camera->rot), matTransInv(env->camera->pos));
	Proj = matProj(env->camera);
	VP = matMult44(Proj, View);

	//printMat4(VP);

	VP_index = glGetUniformLocation(env->program, "VP");
	glUniformMatrix4fv(VP_index, 1, GL_FALSE,(const GLfloat *)&VP);

	glEnableVertexAttribArray(0);
	glClear(GL_COLOR_BUFFER_BIT);
	glDrawArrays(GL_TRIANGLES, 0, 3); // Starting from vertex 0; 3 vertices total -> 1 triangle
	glDisableVertexAttribArray(0);
	SDL_GL_SwapWindow(env->mainWindow);

		SDL_WaitEvent(&(env->evenements));
		if((env->evenements).key.keysym.sym == SDLK_c)
			terminer = 1;
		if ((env->evenements).key.keysym.sym == SDLK_s)
			env->camera->pos.z += 0.1f;
		if ((env->evenements).key.keysym.sym == SDLK_w)
			env->camera->pos.z -= 0.1f;
		if ((env->evenements).key.keysym.sym == SDLK_a)
			env->camera->pos.x -= 0.1f;
		if ((env->evenements).key.keysym.sym == SDLK_d)
			env->camera->pos.x += 0.1f;
		if ((env->evenements).key.keysym.sym == SDLK_q)
			env->camera->pos.y -= 0.1f;
		if ((env->evenements).key.keysym.sym == SDLK_e)
			env->camera->pos.y += 0.1f;
		if ((env->evenements).key.keysym.sym == SDLK_k)
			env->camera->rot.x += 2;
		if ((env->evenements).key.keysym.sym == SDLK_i)
			env->camera->rot.x -= 2;
		if ((env->evenements).key.keysym.sym == SDLK_u)
			env->camera->rot.z -= 2;
		if ((env->evenements).key.keysym.sym == SDLK_o)
			env->camera->rot.z += 2;
		if ((env->evenements).key.keysym.sym == SDLK_j)
			env->camera->rot.y -= 2;
		if ((env->evenements).key.keysym.sym == SDLK_l)
			env->camera->rot.y += 2;
	}

	SDL_Quit();
	return (0);
}
