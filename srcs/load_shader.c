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

const GLchar	*load_shader_source(const char *filename, GLint *size_source)
{
	FILE	*file;
	size_t	size;
	GLchar	*shader_source;

	if ((file = fopen(filename, "r")) == NULL)
		return (NULL);
	fseek(file, 0L, SEEK_END);
	size = ftell(file);
	shader_source = (GLchar*)malloc(sizeof(GLchar) * size);
	rewind(file);
	fread(shader_source, size, sizeof(char), file);
	fclose(file);
	*size_source = (GLint)size;
	return (shader_source);
}

void			print_error_shader(GLint current_shader,
					GLint compilation_return)
{
	GLchar buf[10000];

	glGetShaderiv(current_shader, GL_INFO_LOG_LENGTH, &compilation_return);
	glGetShaderInfoLog(current_shader, 10000, &compilation_return, buf);
	printf("%s\n", buf);
}

void			load_shader(t_env *e, const t_shader_info *si)
{
	const GLchar	*current_shaders_code;
	GLint			size_source;
	GLint			current_shader;
	GLint			compilation_return;
	int				i;

	i = 0;
	e->program = glCreateProgram();
	while (i < NB_SHADERS)
	{
		current_shader = glCreateShader(si[i].flag);
		current_shaders_code = load_shader_source(si[i].addr, &size_source);
		glShaderSource(current_shader, 1, &current_shaders_code, &size_source);
		glCompileShader(current_shader);
		glGetShaderiv(current_shader, GL_COMPILE_STATUS, &compilation_return);
		if (compilation_return == 0)
			print_error_shader(current_shader, compilation_return);
		glAttachShader(e->program, current_shader);
		++i;
		free((void*)current_shaders_code);
	}
	glLinkProgram(e->program);
}
