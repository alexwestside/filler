
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
//	print1(filler);
}

void find_place_on_plato(t_filler **filler)
{
	int x;
	int n;

	x = -1;
//	print1(filler);
//	print2(filler);
	while (++x < (*filler)->plato->x)
	{
		n = -1;
		while (++n < (*filler)->plato->n)
		{
			if ((*filler)->plato->map[x][n] == ((*filler)->player->player_id == 1 ? (*filler)->player->p2 : (*filler)->player->p1))
			{
				(*filler)->dist[x][n] = -2;
				fill_dist(filler, x, n);
			}
			if ((*filler)->plato->map[x][n] == ((*filler)->player->player_id == 1 ? (*filler)->player->p1 : (*filler)->player->p2))
				(*filler)->dist[x][n] = -1;
		}
	}
}

void fill_place(t_filler **filler, int x, int n)
{
	int i;
	int j;
	int _x;
	int _n;
	int averege;

	averege = 0;
	_x = x;
	i = -1;
	while (++i < (*filler)->token->x)
	{
		_n = n;
		j = -1;
		while (++j < (*filler)->token->n)
		{
			if ((*filler)->dist[_x][_n] > 0 && (*filler)->token->map[i][j] == '*')
				averege += (*filler)->dist[_x][_n];
			_n++;
		}
		_x++;
	}
	if (averege < (*filler)->place->averege || !(*filler)->place->averege)
	{
		(*filler)->place->averege = averege;
		(*filler)->place->n = n;
		(*filler)->place->x = x;
	}
}

int check_try_place(t_filler **filler, int x, int n)
{
	int i;
	int j;
	int place;
	int _x;
	int _n;

	_x = x;
	place = 0;
	i = -1;
	while (++i < (*filler)->token->x)
	{
		j = -1;
		_n = n;
		while (++j < (*filler)->token->n)
		{
			if ((*filler)->token->map[i][j] == '*' && (*filler)->plato->map[_x][_n] == ((*filler)->player->player_id == 1 ? (*filler)->player->p1 : (*filler)->player->p2))
				place++;
			if ((*filler)->token->map[i][j] == '*' && (*filler)->plato->map[_x][_n] == ((*filler)->player->player_id == 1 ? (*filler)->player->p2 : (*filler)->player->p1))
				return (0);
			_n++;
		}
		_x++;
	}
	if (place != 1)
		return (0);
	else
		return (1);
}

void try_place_on_plato(t_filler **filler)
{
	int i;
	int j;

	i = -1;
	while (++i < (*filler)->plato->x - (*filler)->token->x)
	{
		j = -1;
		while (++j < (*filler)->plato->n - (*filler)->token->n)
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
	print2(filler);

	ft_printf("%d %d\n", (*filler)->place->x, (*filler)->place->n);
}