/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelless <jbelless@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 15:05:18 by jbelless          #+#    #+#             */
/*   Updated: 2017/07/18 15:05:32 by jbelless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H
# define NB_SHADERS 2

const char *g_shaders[] = {
	"../shaders/empty.vert",
	"../shaders/empty.frag"
};

const GLenum g_shaders_type[] = {
	GL_VERTEX_SHADER,
	GL_FRAGMENT_SHADER
};

#endif
