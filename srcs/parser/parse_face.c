#include "scop.h"

void	push_face(t_face *face, t_obj *obj)
{
	obj->nb_faces += 1;
	if (obj->first_face == NULL)
	{
		obj->first_face = face;
		obj->last_face = face;
	}
	else
	{
		obj->last_face->next = face;
		face->prev = obj->last_face;
	}
	if (face->next == NULL)
	{
		obj->last_face = face;
	}
	else
	{
		obj->nb_faces++;
		obj->last_face = face->next;
	}
}

t_face_type	read_face_format(char *line)
{
	int		val[12];
	int		ret;

	ret = sscanf(line, "f %d %d %d %d", &(val[0]), &(val[1]),
					&(val[2]), &(val[3]));
	if (ret == 3 || ret == 4)
		return (face_v);
	ret = sscanf(line, "f %d/%d %d/%d %d/%d %d/%d",
		&(val[0]), &(val[1]), &(val[2]), &(val[3]), &(val[4]),
		&(val[5]), &(val[6]), &(val[7]));
	if (ret == 6 || ret == 8)
		return (face_v_t);
	ret = sscanf(line, "f %d//%d %d//%d %d//%d %d//%d",
		&(val[0]), &(val[1]), &(val[2]), &(val[3]), &(val[4]),
		&(val[5]), &(val[6]), &(val[7]));
	if (ret == 6 || ret == 8)
		return (face_v_n);
	ret = sscanf(line, "f %d/%d/%d %d/%d/%d %d/%d/%d %d/%d/%d",
		&(val[0]), &(val[1]), &(val[2]), &(val[3]), &(val[4]),
		&(val[5]), &(val[6]), &(val[7]), &(val[8]), &(val[9]),
		&(val[10]), &(val[11]));
	if (ret == 9 || ret == 12)
		return (face_v_t_n);
	return (face_undefine);
}

int		parse_face(char *line, t_env *env)
{
	static t_face_type	cur_face_type = face_undefine;
	t_face			*face;

	if (line[0] == 'g')
		cur_face_type = face_undefine;
	else if (line[0] == 'f')
	{
		if (cur_face_type == face_undefine &&
			(cur_face_type = read_face_format(line)) == face_undefine)
			return (0);
		if ((face = read_face(line, cur_face_type)) == NULL)
			return (0);
		push_face(face, env->obj);
	}
	return (1);
}