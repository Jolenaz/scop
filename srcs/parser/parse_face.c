#include "scop.h"

void	push_face(t_face *face, t_obj *cur_obj)
{
	cur_obj->nb_faces++;
	if (cur_obj->first_face == NULL)
		cur_obj->first_face = face;
	else
	{
		cur_obj->last_face->next = face;
		face->prev = cur_obj->last_face;
	}
	if (face->next == NULL)
		cur_obj->last_face = face;
	else
	{
		cur_obj->nb_faces++;
		cur_obj->last_face = face->next;
	}
}

int		push_obj(t_obj *cur_obj, t_env *env)
{

	if (env->first_obj == NULL)
		env->first_obj = cur_obj;
	else
	{
		env->last_obj->next = cur_obj;
		cur_obj->prev = env->last_obj;
	}
	if (cur_obj->next == NULL)
		env->last_obj = cur_obj;
	else
		env->last_obj = cur_obj->next;
	env->nb_faces += cur_obj->nb_faces;
	return (1);
}

t_obj	*new_obj(void)
{
	t_obj	*ret;

	ret = (t_obj*)malloc(sizeof(t_obj));
	ret->next = NULL;
	ret->prev = NULL;
	ret->f_type = face_undefine;
	ret->nb_faces = 0;
	return (ret);
}

t_face_type	read_face_format(char *line)
{
	int		val[12];
	int		ret;

	ret = sscanf(line, "f %d %d %d %d", &(val[0]), &(val[1]),
					&(val[2]), &(val[3]));
	if (ret == 3 || ret == 4)
		return (face_v);
	ret = scanf(line, "f %d/%d %d/%d %d/%d %d/%d",
		&(val[0]), &(val[1]), &(val[2]), &(val[3]), &(val[4]),
		&(val[5]), &(val[6]), &(val[7]));
	if (ret == 6 || ret == 8)
		return (face_v_t);
	ret = scanf(line, "f %d//%d %d//%d %d//%d %d//%d",
		&(val[0]), &(val[1]), &(val[2]), &(val[3]), &(val[4]),
		&(val[5]), &(val[6]), &(val[7]));
	if (ret == 6 || ret == 8)
		return (face_v_n);
	ret = scanf(line, "f %d/%d/%d %d/%d/%d %d/%d/%d %d/%d/%d",
		&(val[0]), &(val[1]), &(val[2]), &(val[3]), &(val[4]),
		&(val[5]), &(val[6]), &(val[7]), &(val[8]), &(val[9]),
		&(val[10]), &(val[11]));
	if (ret == 9 || ret == 12)
		return (face_v_t_n);
	return (face_undefine);
}

int		parse_face(char *line, t_env *env)
{
	static t_obj	*cur_obj = NULL;
	t_face			*face;

	if (line == NULL)
		return (push_obj(cur_obj, env));
	else if (line[0] == 'g')
	{
		if (cur_obj != NULL)
			push_obj(cur_obj, env);
		cur_obj = new_obj();
	}
	else if (line[0] == 'f' && cur_obj == NULL)
		cur_obj = new_obj();
	else if (line[0] == 'f')
	{
		if (cur_obj->f_type == face_undefine && (cur_obj->f_type = read_face_format(line)) == face_undefine)
			return (0);
		if ((face = read_face(line, cur_obj->f_type)) == NULL)
			return (0);
		else 
			push_face(face, cur_obj);
	}
	return (1);
}