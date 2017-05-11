
#include "filler.h"

void filler_init(t_filler **filler)
{
	(*filler) = (t_filler *)malloc(sizeof(t_filler));
	(*filler)->line = NULL;
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
	(*filler)->place = (t_map *)malloc(sizeof(t_map));
	(*filler)->place->info = NULL;
	(*filler)->place->map = NULL;
	(*filler)->place->x = 0;
	(*filler)->place->n = 0;
	(*filler)->player = (t_player *)malloc(sizeof(t_player));
	(*filler)->player->player_id = 0;
	(*filler)->player->player1 = NULL;
	(*filler)->player->player2 = NULL;
	(*filler)->player->p1 = 'O';
	(*filler)->player->p2 = 'X';
}

void init_plato(t_map **plato, int x, int n)
{
	if (!((*plato)->x) || !((*plato)->n))
	{
		(*plato)->x = x;
		(*plato)->n = n;
	}
	if (!((*plato)->map))
	{
		x++;
		(*plato)->map = (char **) malloc(sizeof(char *) * x);
		(*plato)->map[x] = NULL;
	}
}

void fill_plato(char *line, t_map **plato)
{
	int i;

	i = 0;
	while((*plato)->map[i])
		i++;
	(*plato)->map[i] = line;
}

void init_token(t_map **token, int x, int n)
{
	if (!((*token)->x) || !((*token)->n))
	{
		(*token)->x = x;
		(*token)->n = n;
	}
	if (!((*token)->map))
	{
		x++;
		(*token)->map = (char **) malloc(sizeof(char *) * x);
		(*token)->map[x] = NULL;
	}
}

void fill_token(char *line, t_map **token)
{
	int i;

	i = 0;
	while ((*token)->map[i])
		i++;
	(*token)->map[i] = line;
}