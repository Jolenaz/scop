/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelless <jbelless@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 15:05:48 by jbelless          #+#    #+#             */
/*   Updated: 2017/07/18 15:05:50 by jbelless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

t_env   *init_world();
void    load_shader(t_env *e, const t_shader_info *s);
void	create_obj(t_env *e);

#endif
