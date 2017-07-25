/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter_key_input.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelless <jbelless@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 14:57:02 by jbelless          #+#    #+#             */
/*   Updated: 2017/07/25 14:57:04 by jbelless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	translate(t_env *env)
{
	const t_vec3 dir= {VIEW._20, VIEW._21,VIEW._22};
	const t_vec3 right= {VIEW._00, VIEW._01,VIEW._02};
	const t_vec3 up = {0.0,1.0,0.0};

	if (env->evenements.key.keysym.sym == SDLK_s)
		translate_vec3(&(env->camera->pos), normalise_vec3(dir), 0.1f);
	else if (env->evenements.key.keysym.sym == SDLK_w)
		translate_vec3(&(env->camera->pos), normalise_vec3(dir), -0.1f);
	else if (env->evenements.key.keysym.sym == SDLK_a)
		translate_vec3(&(env->camera->pos), normalise_vec3(right), -0.1f);
	else if (env->evenements.key.keysym.sym == SDLK_d)
		translate_vec3(&(env->camera->pos), normalise_vec3(right), 0.1f);
	else if (env->evenements.key.keysym.sym == SDLK_q)
		translate_vec3(&(env->camera->pos), normalise_vec3(up), -0.1f);
	else if (env->evenements.key.keysym.sym == SDLK_e)
		translate_vec3(&(env->camera->pos), normalise_vec3(up), 0.1f);
}

void	rotate(t_env *env)
{
	if (env->evenements.key.keysym.sym == SDLK_DOWN)
		env->camera->rot.x += -2;
	else if (env->evenements.key.keysym.sym == SDLK_UP)
		env->camera->rot.x += 2;
	else if (env->evenements.key.keysym.sym == SDLK_LEFT)
		env->camera->rot.y += -2;
	else if (env->evenements.key.keysym.sym == SDLK_RIGHT)
		env->camera->rot.y += 2;
}

void	tamere(t_env *env)
{
	if (env->evenements.key.repeat == 0 && env->evenements.key.type == SDL_KEYDOWN)
		printMat4(VIEW);
}

const	t_key_input g_tab_input[NB_INPUT] = {
	{SDLK_s, &translate },
	{SDLK_w, &translate },
	{SDLK_a, &translate },
	{SDLK_d, &translate },
	{SDLK_q, &translate },
	{SDLK_e, &translate },
	{SDLK_UP, &rotate },
	{SDLK_RIGHT, &rotate },
	{SDLK_DOWN, &rotate },
	{SDLK_LEFT, &rotate },
	{SDLK_t, &tamere}
};

void	filter_key_input(t_env *env)
{
	int i;

	i = 0;
	while (i < NB_INPUT)
	{
		if (g_tab_input[i].keycode == env->evenements.key.keysym.sym)
			(*g_tab_input[i].f)(env);
		++i;
	}
}
