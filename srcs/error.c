#include "scop.h"

void	print_error0(char *str, int i)
{
	fprintf(stderr, "Error: %s : %d\n", str, i);
	exit(EXIT_FAILURE);
}

void	print_error1(char *str)
{
	fprintf(stderr, "Error: %s\n", str);
	exit(EXIT_FAILURE);
}

void print_vert(t_env *e)
{
	int i = 0;

	while(i < e->nb_vertex)
	{
		printf("vert %d : %f %f %f\n", i, e->vertex_tab[i].x, e->vertex_tab[i].y ,e->vertex_tab[i].z);
		i++;
	}
}

void print_face(t_env *e)
{
	t_face *face;

	face = e->obj->first_face;

	while(face)
	{
		printf("face : %d %d %d\n", face->vertex[0], face->vertex[1], face->vertex[2]);
		face = face->next;
	}
}