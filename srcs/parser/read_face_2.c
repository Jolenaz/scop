#include "scop.h"

void	attribute_val_21(t_face *ret, int val[12])
{
	ret->vertex[0] = val[0] - 1;
	ret->vertex[1] = val[2] - 1;
	ret->vertex[2] = val[4] - 1;
	ret->texture[0] = val[1] - 1;
	ret->texture[1] = val[3] - 1;
	ret->texture[2] = val[5] - 1;
}

void	attribute_val_22(t_face *ret, int val[12])
{
	ret->vertex[0] = val[0] - 1;
	ret->vertex[1] = val[4] - 1;
	ret->vertex[2] = val[6] - 1;
	ret->texture[0] = val[1] - 1;
	ret->texture[1] = val[5] - 1;
	ret->texture[2] = val[7] - 1;
}

t_face	*create_face_2(int attr, int val[12], char is_first)
{
	t_face *ret;

	ret = (t_face*)malloc(sizeof(t_face));
	if (attr == 6 || (attr == 8 && is_first))
		attribute_val_21(ret, val);
	else
		attribute_val_22(ret, val);
	ret->next = NULL;
	ret->prev = NULL;
	if (attr == 6 && is_first)
	{
		ret->next = create_face_2(attr, val, 0);
		ret->next->prev = ret;
	}
	return (ret);
}

t_face	*read_face_2(char *line)
{
	int		val[12];
	int		ret;

	ret = scanf(line, "f %d/%d %d/%d %d/%d %d/%d",
		&(val[0]), &(val[1]), &(val[2]), &(val[3]), &(val[4]),
		&(val[5]), &(val[6]), &(val[7]));
	if (ret == 6 || ret == 8)
		return (create_face_2(ret, val, 1));
	return (NULL);
}
