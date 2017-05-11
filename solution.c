
#include "filler.h"

void fill_dist(t_filler **filler, int x, int n, int id)
{
	int i;
	int j;

	i = -1;
	(*filler)->dist[x][n] = id;
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
}

void find_enamy_place_on_plato(t_filler **filler)
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
					fill_dist(filler, x, n, -2);
		}
	}
}

void find_my_place_on_plato(t_filler **filler)
{
	int x;
	int n;

	x = -1;
	while (++x < (*filler)->plato->x)
	{
		n = -1;
		while (++n < (*filler)->plato->n)
		{
			if ((*filler)->plato->map[x][n] == ((*filler)->player->player_id == 1 ? 'O' : 'X'))
				fill_dist(filler, x, n, -1);
		}
	}
}

void place_token(t_filler **filler)
{
	init_dist(filler);
	find_enamy_place_on_plato(filler);
	find_my_place_on_plato(filler);
	print1(filler);
	ft_printf("%s %s\n", (*filler)->place->x, (*filler)->place->n);
}