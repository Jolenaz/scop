#include "scop.h"

void	attribute_val_31(t_face *ret, int val[12])
{
	ret->vertex[0] = val[0] - 1;
	ret->vertex[1] = val[2] - 1;
	ret->vertex[2] = val[4] - 1;
}

void	attribute_val_32(t_face *ret, int val[12])
{
	ret->vertex[0] = val[0] - 1;
	ret->vertex[1] = val[4] - 1;
	ret->vertex[2] = val[6] - 1;
}

t_face	*create_face_3(int attr, int val[12], char is_first)
{
	t_face *ret;

	ret = (t_face*)malloc(sizeof(t_face));
	if (attr == 6 || (attr == 8 && is_first))
		attribute_val(ret, val[0] , val[2] , val[4]);
	else
		attribute_val(ret, val[0] , val[4] , val[6]);
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

	ret = sscanf(line, "f %d//%d %d//%d %d//%d %d//%d",
		&(val[0]), &(val[1]), &(val[2]), &(val[3]), &(val[4]),
		&(val[5]), &(val[6]), &(val[7]));
	if (ret == 6 || ret == 8)
		return (create_face_3(ret, val, 1));
	return (NULL);
}
