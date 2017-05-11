
#include "filler.h"

void ft_error(int error, int id)
{
	if (error == 1)
	{
		if (id == 4)
			ft_printf("Incorrect PLAYER #1 inicialization!");
		else
			ft_printf("Incorrect PLAYER #2 inicialization!");
	}
	else if (error == 2)
		ft_printf("Incorrect PLATO inicialization!");
	else if (error == 3 )
		ft_printf("Incorrect TOKEN inicialization!");
	else if (error == 4)
		ft_printf("Line == NULL!");
	exit(0);
}

int isdigit_str(char *s, int id)
{
	char *p;
	char *p1;

	p1 = NULL;
	p = s;
	if (id == 2)
		p1 = ft_strchr(s, ':');
	while (id != 2 ? *p : p != p1)
	{
		if (!ft_isdigit(*p))
			return (0);
		p++;
	}
	return (1);
}

int isprint_str(char *s)
{
	char *p;

	p = s;
	while (*p)
	{
		if (!ft_isprint(*p))
			return (0);
		p++;
	}
	return (1);
}

int ft_abs(int i, int x, int j ,int n)
{
	int res;

	res = (i - x) + (j - n);
	return (res < 0 ? res * -1 : res);
}


void print1(t_filler **filler)
{
	int i;
	int j;

	i = -1;
	while (++i < (*filler)->plato->x)
	{
		j = -1;
		while (++j < (*filler)->plato->n)
		{
			ft_printf("%3d", (*filler)->dist[i][j]);
		}
		ft_printf("\n");
	}
}