#include "scop.h"

void	attribute_val_31(t_face *ret, int val[12])
{
	ret->vertex[0] = val[0];
	ret->vertex[1] = val[2];
	ret->vertex[2] = val[4];
	ret->normal[0] = val[1];
	ret->normal[1] = val[3];
	ret->normal[2] = val[5];
}

void	attribute_val_32(t_face *ret, int val[12])
{
	ret->vertex[0] = val[0];
	ret->vertex[1] = val[4];
	ret->vertex[2] = val[6];
	ret->normal[0] = val[1];
	ret->normal[1] = val[5];
	ret->normal[2] = val[7];
}

t_face	*create_face_3(int attr, int val[12], char is_first)
{
	t_face *ret;

	ret = (t_face*)malloc(sizeof(t_face));
	if (attr == 6 || (attr == 8 && is_first))
		attribute_val_31(ret, val);
	else
		attribute_val_32(ret, val);
	ret->next = NULL;
	ret->prev = NULL;
	if (attr == 6 && is_first)
	{
		ret->next = create_face_3(attr, val, 0);
		ret->next->prev = ret;
	}
	return (ret);
}

t_face	*read_face_3(char *line)
{
	int		val[12];
	int		ret;

	ret = scanf(line, "f %d//%d %d//%d %d//%d %d//%d",
		&(val[0]), &(val[1]), &(val[2]), &(val[3]), &(val[4]),
		&(val[5]), &(val[6]), &(val[7]));
	if (ret == 6 || ret == 8)
		return (create_face_3(ret, val, 1));
	return (NULL);
}
