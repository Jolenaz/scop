#include "scop.h"

t_face	*read_face(char *line, t_face_type type)
{
	if (type == face_v)
		return (read_face_1(line));
	else if (type == face_v_n)
		return (read_face_2(line));
	else if (type == face_v_t)
		return (read_face_3(line));
	else if (type == face_v_t_n)
		return (read_face_4(line));
	else
		return (NULL);
}