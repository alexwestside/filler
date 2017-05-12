
#include "filler.h"

void fill_dist(t_filler **filler, int x, int n)
{
	int i;
	int j;

	i = -1;
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
			{
				(*filler)->dist[x][n] = -2;
				fill_dist(filler, x, n);
			}
			if ((*filler)->plato->map[x][n] == ((*filler)->player->player_id == 1 ? 'O' : 'X'))
				(*filler)->dist[x][n] = -1;
		}
	}
}

int check_try_place(t_filler **filler, int x, int n)
{
	while (x < (*filler)->token->x)
	{
		while (n < (*filler)->token->n)
		{



			n++;
		}
		x++;
	}
}

void try_place_on_plato(t_filler **filler)
{
	int i;
	int j;

	i = -1;
	while (++i < (*filler)->plato->x)
	{
		j = -1;
		while (++j < (*filler)->plato->n)
		{
			if (check_try_place(filler, i, j))
				fill_place(filler, i, j);
		}
	}
}

void place_token(t_filler **filler)
{
	init_dist(filler);
	find_place_on_plato(filler);
	try_place_on_plato(filler);
	print1(filler);
	ft_printf("%s %s\n", (*filler)->place->x, (*filler)->place->n);
}