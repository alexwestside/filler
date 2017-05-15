
#include "filler.h"

void	ft_error(int error)
{
	if (error == 1)
		ft_printf("Incorrect PLAYER inicialization!\n");
	else if (error == 2)
		ft_printf("Incorrect PLATO inicialization!\n");
	else if (error == 3)
		ft_printf("Incorrect TOKEN inicialization!\n");
	else if (error == 4)
		ft_printf("No DATA input!\n");
	exit(0);
}

int		isdigit_str(char *s, int id)
{
	char	*p;
	char	*p1;

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

int		isprint_str(char *s)
{
	char	*p;

	p = s;
	while (*p)
	{
		if (!ft_isprint(*p))
			return (0);
		p++;
	}
	return (1);
}

int		read_finish(t_filler *filler)
{
	if (filler->token)
	{
		if (filler->token->info)
		{
			if (filler->token->map)
			{
				if (filler->token->map[filler->token->x - 1])
					return (1);
			}
		}
	}
	return (0);
}

int		ft_abs(int i, int j)
{
	return ((i - j) < 0 ? (i - j) * -1 : (i - j));
}
