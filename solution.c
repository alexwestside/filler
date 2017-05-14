
#include "filler.h"

void	fill_dist(t_filler **filler, int x, int n)
{
	int	i;
	int	j;

	i = -1;
	while (++i < (*filler)->plato->x)
	{
		j = -1;
		while (++j < (*filler)->plato->n)
		{
			if ((*filler)->dist[i][j] == 0)
				(*filler)->dist[i][j] = ft_abs(i, x) + ft_abs(j, n);
			else if ((*filler)->dist[i][j] > 0)
			{
				if ((*filler)->dist[i][j] >= ft_abs(i, x) + ft_abs(j, n))
					(*filler)->dist[i][j] = ft_abs(i, x) + ft_abs(j, n);
			}
		}
	}
}

void	find_place_on_plato(t_filler **filler)
{
	int	x;
	int	n;

	x = -1;
	while (++x < (*filler)->plato->x)
	{
		n = -1;
		while (++n < (*filler)->plato->n)
		{
			if ((*filler)->plato->map[x][n] ==
			((*filler)->player->player_id == 1 ?
			(*filler)->player->p2 : (*filler)->player->p1))
			{
				(*filler)->dist[x][n] = -2;
				fill_dist(filler, x, n);
			}
			if ((*filler)->plato->map[x][n] ==
			((*filler)->player->player_id == 1 ?
			(*filler)->player->p1 : (*filler)->player->p2))
				(*filler)->dist[x][n] = -1;
		}
	}
}

void	fill_place(t_filler **filler, int x, int n)
{
	int	i;
	int	j;
	int	x_;
	int	n_;
	int	averege;

	averege = 0;
	x_ = x;
	i = -1;
	while (++i < (*filler)->token->x)
	{
		n_ = n;
		j = -1;
		while (++j < (*filler)->token->n)
		{
			if ((*filler)->dist[x_][n_] > 0 &&
					(*filler)->token->map[i][j] == '*')
				averege += (*filler)->dist[x_][n_];
			n_++;
		}
		x_++;
	}
	if (averege < (*filler)->place->averege || !(*filler)->place->averege)
		fill_in_place(filler, averege, n, x);
}

int		check_try_place(t_filler **filler, int x, int n)
{
	int	i;
	int	j;
	int	place;
	int	x_;
	int	n_;

	x_ = x;
	place = 0;
	i = -1;
	while (++i < (*filler)->token->x)
	{
		j = -1;
		n_ = n;
		while (++j < (*filler)->token->n)
		{
			if (x_ < (*filler)->plato->x && n_ < (*filler)->plato->n)
			{
				if ((*filler)->token->map[i][j] == '*' &&
		(*filler)->plato->map[x_][n_] == ((*filler)->player->player_id == 1 ?
		(*filler)->player->p1 : (*filler)->player->p2))
					place++;
				if ((*filler)->token->map[i][j] == '*' &&
		(*filler)->plato->map[x_][n_] == ((*filler)->player->player_id == 1 ?
		(*filler)->player->p2 : (*filler)->player->p1))
					return (0);
				n_++;
			}
			else
				return (0);
		}
		x_++;
	}
	return (place != 1 ? 0 : 1);
}

void	try_place_on_plato(t_filler **filler)
{
	int	i;
	int	j;

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
