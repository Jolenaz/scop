#include "scop.h"

void	attribute_val_11(t_face *ret, int val[12])
{
	ret->vertex[0] = val[0];
	ret->vertex[1] = val[1];
	ret->vertex[2] = val[2];
}

void	attribute_val_12(t_face *ret, int val[12])
{
	ret->vertex[0] = val[0];
	ret->vertex[1] = val[2];
	ret->vertex[2] = val[3];
}

t_face	*create_face_1(int attr, int val[12], char is_first)
{
	t_face *ret;

	ret = (t_face*)malloc(sizeof(t_face));
	ret->next = NULL;
	ret->prev = NULL;
	if (attr == 3 || (attr == 4 && is_first))
		attribute_val_11(ret, val);
	else
		attribute_val_12(ret, val);
	if (attr == 4 && is_first)
	{
		ret->next = create_face_1(attr, val, 0);
		ret->next->prev = ret;
	}
	return (ret);
}

t_face	*read_face_1(char *line)
{
	int		val[12];
	int		ret;

	ret = sscanf(line, "f %d %d %d %d", &(val[0]), &(val[1]),
					&(val[2]), &(val[3]));
	if (ret == 3 || ret == 4)
		return (create_face_1(ret, val, 1));
	return (NULL);
}
