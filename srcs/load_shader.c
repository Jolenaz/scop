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

const GLchar *load_shader_source(const char *filename, GLint *size_source) {
	FILE *file;

	if ((file = fopen(filename, "r")) == NULL)
		return NULL;
	fseek(file, 0L, SEEK_END);
	size_t size = ftell(file);
	GLchar *shaderSource = (GLchar*)malloc(sizeof(GLchar) * size);
	rewind(file);
	fread(shaderSource, size, sizeof(char), file);
	fclose(file);
	*size_source = (GLint)size;
	return shaderSource;
}

void load_shader(t_env *e, const t_shader_info *si)
{
	const GLchar	*current_shaders_code; 
	GLint			size_source;
	GLint			current_shader;
	GLint			compilation_return;
	int				i;

	i = 0;
	e->program = glCreateProgram();
	while(i < NB_SHADERS)
	{
		current_shader = glCreateShader(si[i].flag);
		current_shaders_code = load_shader_source(si[i].addr, &size_source);
		glShaderSource(current_shader, 1, &current_shaders_code, &size_source);
		glCompileShader(current_shader);
		glGetShaderiv(current_shader, GL_COMPILE_STATUS, &compilation_return);
		if (compilation_return == 0)
		{
			GLchar buf[10000];
			glGetShaderiv(current_shader, GL_INFO_LOG_LENGTH, &compilation_return);
			glGetShaderInfoLog(current_shader,10000, &compilation_return, buf);
			printf("%s\n",buf);
		}
		glAttachShader(e->program, current_shader);
		++i;
	}
	glLinkProgram(e->program);	
}
