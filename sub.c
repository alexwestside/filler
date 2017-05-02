
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
		ft_printf("Incorrect 1st line of PLATO inicialization!");
	exit(0);
}

int isdigit_str(char *s, int id)
{
	char *p;
	char *p1;

	p = s;
	if (id == 2)
		p1 = ft_strchr(s, ':');
	while (id == 2 ? *p : p != p1)
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