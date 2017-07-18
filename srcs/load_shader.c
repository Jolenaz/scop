/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_shader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelless <jbelless@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 15:05:02 by jbelless          #+#    #+#             */
/*   Updated: 2017/07/18 15:05:05 by jbelless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

const GLchar *load_shader_source(char *filename) {
	FILE *file;
	if (FILE *file = fopen(filename, "r") == -1)
		return NULL;
	fseek(file, 0L, SEEK_END);
	size_t size = ftell(file);
	GLchar *shaderSource = (GLchar*)malloc(sizeof(GLchar) * size);
	rewind(file);
	fread(shaderSource, size, sizeof(char), file);
	fclose(file);
	return shaderSource;
}

void load_shader(t_env *e)
{
	GLchar **shaders_code;
	int i;

	i = 0;
	shaders_code = (GLchar **)malloc(sizeof(GLchar *) * NB_SHADERS);
	while(i < NB_SHADERS)
	{
		shaders_code[i] = load_shader_source(g_shaders[i]);
		glShaderSource(e->shaders[i], 1, &shaders_code[i], strlen(shaders_code[i]));
		++i;
	}

	

	

}
