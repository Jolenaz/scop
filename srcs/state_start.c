#include "scop.h"

int next_state (t_state_parse state, char *ptr)
{
	return ( (*g_tab_state[state])(ptr) );
}

int state_is_slet(char *ptr)
{
	if (*ptr == 'n')
	{
		g_current_v = norm;
		ptr++;
		if (*ptr == ' ')
			return (next_state(space, ptr));
		else
		{
			printf("error %d\n", 10);
			return (0);
		}
	}
	else
	{
		g_current_v = text;
		ptr++;
		if (*ptr == ' ')
			return (next_state(space, ptr));
		else
		{
			printf("error %d\n", 11);
			return (0);
		}
	}
}

int	state_is_flet(char *ptr)
{
	ptr++;
	if (*ptr == ' ')
	{
		g_current_v = vert;
		return (next_state(space, ptr));
	}
	else if (*ptr == 'n' || *ptr == 't')
		return (next_state(slet, ptr));
	else
		{printf("error %d\n",0); return (0);}
}

int	state_is_space(char *ptr)
{
	ptr++;
	if (*ptr == '+' || *ptr == '-')
		return (next_state(sign, ptr));
	else if (isdigit(*ptr))
		return (next_state(num, ptr));
	else if (*ptr == ' ')
		return (next_state(space, ptr));
	else
		{
			printf("error %d\n", 12);
			return (0);
		}
}

int state_is_sign(char *ptr)
{
	ptr++;
	if (isdigit(*ptr))
		return (next_state(num, ptr));
	else
		{printf("error %d\n",1); return (0);}
}

int state_is_num(char *ptr)
{
	ptr++;
	if (isdigit(*ptr))
		return (next_state(num, ptr));
	else if (*ptr == '.')
		return (next_state(point, ptr));
	else if (*ptr == '\n' || *ptr == ' ')
		return (next_state(new_float, ptr));
	else
		{printf("error %d\n",2); return (0);}
}

int state_is_new_float(char *ptr)
{
	static int nb_float = 0;

	++nb_float;
	if (nb_float < (g_current_v == text ? 2 : 3) )
	{
		if (*ptr == '\n')
			{printf("error %d\n",3); return (0);}
		else if (isdigit(*(ptr + 1)))
			return (next_state(num, ptr + 1));
		else if ( *(ptr + 1) == '-' || *(ptr + 1) == '+' )
			return (next_state(sign, ptr + 1));
		else if (*(ptr + 1) == ' ')
			return (next_state(space, ptr + 1));
		else
			{printf("error %d\n",4); return (0);}
	}
	else
	{
		nb_float = 0;
		g_nb_points = 0;
		if  (*ptr == '\n')
			return (1);
		else if (*ptr == ' ')
			return (next_state(end_space, ptr));
		else
		{
			printf("error %d\n", 15);
			return (0);
		}
 	}
}

int state_is_end_space(char *ptr)
{
	++ptr; 
	if (*ptr == '\n')
		return (1);
	else if (*ptr == ' ')
		return (next_state(end_space, ptr));
	else
	{
		printf("error %d\n", 16);
		return (0);
	}
}

int state_is_point(char *ptr)
{
	g_nb_points++;
	if (g_nb_points > 3)
		{printf("error %d\n",5); return (0);}
	ptr++;
	if (isdigit(*ptr))
		return (next_state(num, ptr));
	else
		{printf("error %d\n",6); return (0);}
}



int state_start(char *line)
{
	t_state_parse state;

	state = flet;
	g_nb_points = 0;
	g_tab_state[num]	= &state_is_num;
	g_tab_state[point]	= &state_is_point;
	g_tab_state[sign]	= &state_is_sign;
	g_tab_state[flet]	= &state_is_flet;
	g_tab_state[slet]	= &state_is_slet;
	g_tab_state[new_float] = &state_is_new_float;
	g_tab_state[space]	= &state_is_space;
	g_tab_state[end_space]	= &state_is_end_space;
	return (next_state(state, line));
}