
#include "filler.h"

void free_place(t_filler **filler)
{
	free((*filler)->place);
	(*filler)->place = NULL;
}

void free_token(t_filler **filler)
{
	int i;

	i = 0;
	while ((*filler)->token->map[i])
	{
		free((*filler)->token->map[i]);
		i++;
	}
	free((*filler)->token->map);
	(*filler)->token->map = NULL;
	free((*filler)->token->info);
	(*filler)->token->info = NULL;
	free((*filler)->token);
	(*filler)->token = NULL;
}

void free_plato(t_filler **filler)
{
	int i;

	i = 0;
	while ((*filler)->plato->map[i])
	{
		free((*filler)->plato->map[i]);
		i++;
	}
	free((*filler)->plato->map);
	(*filler)->plato->map = NULL;
	free((*filler)->plato->info);
	(*filler)->plato->info = NULL;
	free((*filler)->plato);
	(*filler)->plato = NULL;
}

void free_player(t_filler **filler)
{
	free((*filler)->player->player1);
	free((*filler)->player->player2);
	free((*filler)->player);
	(*filler)->player = NULL;
}

void free_dist(t_filler **filler)
{
	int i;

	i = 0;
	while ((*filler)->dist[i])
	{
		free((*filler)->dist[i]);
		i++;
	}
	free((*filler)->dist);
	(*filler)->dist = NULL;
}

