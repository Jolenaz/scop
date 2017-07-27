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
# define BUFFER_OFFSET(i) ((char *)NULL + (i))

#define NB_INPUT 11

# define WIDTH 640
# define HEIGHT 480

# define VIEW env->camera->view_matrice

int		(*g_tab_state[10])(char *ptr);
int		g_nb_points;
t_vtype	g_current_v;

#endif
