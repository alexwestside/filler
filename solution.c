
#include "filler.h"

int check_try_place(t_filler **filler)
{
//	if ()


	return (0);
}

int try_place(t_filler **filler)
{
	int x;
	int n;

	x = -1;
	while (++x <= (*filler)->token->x)
	{
		n = -1;
		while (++n <= (*filler)->token->n)
		{
			if ((*filler)->token->map[x][n] == '*')
			{
				(*filler)->place->x += x;
				(*filler)->place->n += n;
				if (check_try_place(filler))
					return (1);
			}
		}
	}
	return (0);
}

int check_place(t_filler **filler, int x, int n)
{
	if ((*filler)->plato->map[x][n] == 'O')
	{
		(*filler)->place->x = x;
		(*filler)->place->n = n;
		return (1);
	}
	return (0);
}

int find_place_on_plato(t_filler **filler)
{
	int x;
	int n;

	x = -1;
	while (++x <= (*filler)->plato->x)
	{
		n = -1;
		while (++n <= (*filler)->token->n)
		{
			if (check_place(filler, x, n))
			{
				if (try_place(filler))
					return (1);
			}
		}
	}
	return (0);
}

void place_token(t_filler **filler)
{
	if (find_place_on_plato(filler))
		ft_printf("%s %s\n", (*filler)->place->x, (*filler)->place->n);
}