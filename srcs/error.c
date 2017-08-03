#include "scop.h"

int	print_error0(char *str, int i)
{
	fprintf(stderr, "%s : %d\n", str, i);
	return (0);
}

int	print_error1(char *str)
{
	fprintf(stderr, "%s\n", str);
	return (0);
}