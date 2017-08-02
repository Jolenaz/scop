#include "scop.h"

int		create_vertex_tab(int v_num, int vt_num, int vn_num, t_env *env)
{
	env->nb_vertex = v_num;
	env->nb_texture= vt_num;
	env->nb_normal = vn_num;
	if (
		(env->vertex_tab = (t_vec3*)malloc(sizeof(t_vec3) * v_num)) == NULL ||
		(env->normal_tab = (t_vec3*)malloc(sizeof(t_vec3) * vn_num)) == NULL ||
		(env->texture_tab = (t_vec2*)malloc(sizeof(t_vec2) * vt_num)) == NULL
	)
	{
		fprintf(stderr, "error: malloc failded");
		return (0);
	}
	return (1);
}
