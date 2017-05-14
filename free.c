
#include "filler.h"

void	free_place(t_filler **filler)
{
	free((*filler)->place);
	(*filler)->place = NULL;
}

void free_plato_or_token(t_map **plato_or_token)
{
	int	i;

	i = 0;
	while ((*plato_or_token)->map[i])
	{
		free((*plato_or_token)->map[i]);
		i++;
	}
	free((*plato_or_token)->map);
	(*plato_or_token)->map = NULL;
	free((*plato_or_token)->info);
	(*plato_or_token)->info = NULL;
	free(*plato_or_token);
	(*plato_or_token)= NULL;

}

void	free_player(t_filler **filler)
{
	free((*filler)->player->player1);
	free((*filler)->player->player2);
	free((*filler)->player);
	(*filler)->player = NULL;
}

void	free_dist(t_filler **filler)
{
	int	i;

	i = 0;
	while ((*filler)->dist[i])
	{
		free((*filler)->dist[i]);
		i++;
	}
	free((*filler)->dist);
	(*filler)->dist = NULL;
}

void	free_two_dem_str(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
}

void	free_filler(t_filler **filler)
{
	free((*filler)->line);
	free_dist(filler);
	free_plato_or_token(&((*filler)->plato));
	free_plato_or_token(&((*filler)->token));
	free_place(filler);
}
