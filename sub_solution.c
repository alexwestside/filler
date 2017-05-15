
#include "filler.h"

int		check_try_place_test(t_filler **filler, int i, int j)
{
	if ((*filler)->token->map[i][j] == '*' &&
	(*filler)->plato->map[(*filler)->x_][(*filler)->n_] ==
	((*filler)->player->player_id == 1 ? (*filler)->player->p1 :
	(*filler)->player->p2))
		return (1);
	if ((*filler)->token->map[i][j] == '*' &&
	(*filler)->plato->map[(*filler)->x_][(*filler)->n_] ==
	((*filler)->player->player_id == 1 ? (*filler)->player->p2 :
	(*filler)->player->p1))
		return (2);
	else
		return (0);
}

void	free_filler(t_filler **filler)
{
	free((*filler)->line);
	free_dist(filler);
	free_plato_or_token(&((*filler)->plato));
	free_plato_or_token(&((*filler)->token));
	free_place(filler);
}

void	place_token(t_filler **filler)
{
	init_dist(filler);
	find_place_on_plato(filler);
	try_place_on_plato(filler);
	ft_printf("%d %d\n", (*filler)->place->x, (*filler)->place->n);
}

void	fill_in_place(t_filler **filler, int averege, int n, int x)
{
	(*filler)->place->averege = averege;
	(*filler)->place->n = n;
	(*filler)->place->x = x;
}
