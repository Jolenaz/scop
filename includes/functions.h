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

/* Functions */

void	print_error0(char *str, int i);
void	print_error1(char *str);
void print_vert(t_env *e);
void print_face(t_env *e);

t_env   *init_world();
void	load_texture();
void    load_shader(t_env *e, const t_shader_info *s);
void	create_obj(t_env *e);
void	calc_shader(t_env* env);
void	filter_key_input(t_env *env);
void	init_sdl(t_env *env);

/* Parser */


void	open_scene(int ac, char **av, t_env *env);
void	first_parse_scene(FILE *obj_file, t_env* env);
void	second_parse_scene(FILE *obj_file, t_env* env);
int		parse_face(char *line, t_env *env);
int		second_parse_mtl(FILE *mtl_file, t_env *env);
t_face	*read_face(char *line, t_face_type type);
t_face	*read_face_1(char *line);
t_face	*read_face_2(char *line);
t_face	*read_face_3(char *line);
t_face	*read_face_4(char *line);
void	attribute_val(t_face *ret, int a, int b, int c);

char	*clear_bn(char *line);

/* Operations matricielles */
t_vec4	mat_mult41(t_mat4 A, t_vec4 p);
t_mat4	mat_mult44(t_mat4 A, t_mat4 B);
void	init_mat4(t_mat4 *A);
void	printMat4(t_mat4 A);
t_mat4	mat_rot_inv(t_vec3 rot);
t_mat4	mat_rot(t_vec3 rot);
t_mat4	mat_trans_inv(t_vec3 rot);
t_mat4	mat_trans(t_vec3 rot);
t_mat4	mat_scale_inv(t_vec3 rot);
t_mat4	mat_scale(t_vec3 rot);
t_mat4	mat_proj(t_cam *cam);
t_vec3	init_vec3(float x, float y, float z);
void	translate_vec3(t_vec3 *o, const t_vec3 t, float r);
t_vec3	normalise_vec3(t_vec3 src);


#endif
