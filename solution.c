
#include "filler.h"

void fill_dist(t_filler **filler, int x, int n)
{
	int i;
	int j;

	i = -1;
	(*filler)->dist[x][n] = (*filler)->player->player_id == 1 ? -1 : -2;
	while (++i < (*filler)->plato->x)
	{
		j = -1;
		while (++j < (*filler)->plato->n)
		{
			if ((*filler)->dist[i][j] == 0)
				(*filler)->dist[i][j] = ft_abs(i, x, j ,n);
			else if ((*filler)->dist[i][j] > 0)
			{
				if ((*filler)->dist[i][j] > ft_abs(i, x, j, n))
					(*filler)->dist[i][j] = ft_abs(i, x, j, n);
			}
		}
	}
	print1(filler);
}

void find_place_on_plato(t_filler **filler)
{
	int x;
	int n;

	x = -1;
	while (++x < (*filler)->plato->x)
	{
		n = -1;
		while (++n < (*filler)->plato->n)
		{
			if ((*filler)->plato->map[x][n] == ((*filler)->player->player_id == 1 ? 'X' : 'O'))
					fill_dist(filler, x, n);
		}
	}
}

void place_token(t_filler **filler)
{
	init_dist(filler);
	find_place_on_plato(filler);
	ft_printf("%s %s\n", (*filler)->place->x, (*filler)->place->n);
}