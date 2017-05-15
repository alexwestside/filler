
#include "filler.h"

void	filler_init_0(t_filler **filler)
{
	(*filler) = (t_filler *)malloc(sizeof(t_filler));
	(*filler)->line = NULL;
	(*filler)->player = (t_player *)malloc(sizeof(t_player));
	(*filler)->player->player_id = 0;
	(*filler)->player->player1 = NULL;
	(*filler)->player->player2 = NULL;
	(*filler)->player->p1 = 'O';
	(*filler)->player->p2 = 'X';
}

void	filler_init_1(t_filler **filler)
{
	(*filler)->dist = NULL;
	(*filler)->plato = (t_map *)malloc(sizeof(t_map));
	(*filler)->plato->info = NULL;
	(*filler)->plato->map = NULL;
	(*filler)->plato->x = 0;
	(*filler)->plato->n = 0;
	(*filler)->token = (t_map *)malloc(sizeof(t_map));
	(*filler)->token->info = NULL;
	(*filler)->token->map = NULL;
	(*filler)->token->x = 0;
	(*filler)->token->n = 0;
	(*filler)->place = (t_place *)malloc(sizeof(t_place));
	(*filler)->place->x = 0;
	(*filler)->place->n = 0;
	(*filler)->place->averege = 0;
	(*filler)->x_ = 0;
	(*filler)->n_ = 0;
}

void	fill_plato_or_token(char *line, t_map **plato_or_token)
{
	int	i;

	i = 0;
	if ((*plato_or_token)->map)
	{
		while ((*plato_or_token)->map[i])
			i++;
		(*plato_or_token)->map[i] = line;
	}
	else
		ft_error(4);
}

void	init_plato_or_token(t_map **plato_or_token, int x, int n)
{
	{
		if (!((*plato_or_token)->x) || !((*plato_or_token)->n))
		{
			(*plato_or_token)->x = x;
			(*plato_or_token)->n = n;
		}
		if (!((*plato_or_token)->map))
		{
			x++;
			(*plato_or_token)->map = (char **)malloc(sizeof(char *) * x);
			while (x--)
				(*plato_or_token)->map[x] = NULL;
		}
	}
}

void	init_dist(t_filler **filler)
{
	int	i;

	i = -1;
	(*filler)->dist = (int **)malloc(sizeof(int *) * ((*filler)->plato->x + 1));
	(*filler)->dist[(*filler)->plato->x] = NULL;
	while (++i < (*filler)->plato->x)
	{
		(*filler)->dist[i] = (int *)malloc(sizeof(int) * (*filler)->plato->n);
		ft_bzero((*filler)->dist[i], (size_t)(*filler)->plato->n * sizeof(int));
	}
}
