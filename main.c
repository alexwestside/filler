
#include "filler.h"

void free_filler(t_filler **filler)
{
	free((*filler)->line);
	free_dist(filler);
	free_plato(filler);
	free_token(filler);
	free_place(filler);
}

void free_two_dem_str(char **s)
{
	int i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
}

int read_finish(t_filler *filler)
{
	if (filler->token)
	{
		if (filler->token->info)
		{
			if (filler->token->map)
			{
				if (filler->token->map[filler->token->x - 1])
					return (1);
			}
		}
	}
	return (0);
}

int main()
{
	t_filler *filler;
	char **s;
	int i;

	i = 0;
	filler_init_0(&filler);
	while (get_next_line(0, &filler->line))
	{
		if (!i)
			filler_init_1(&filler);
		i++;
		s = ft_strsplit(filler->line, ' ');
		valid_and_init(s, &filler);
		free(s);
		if (read_finish(filler))
		{
			place_token(&filler);
			free_filler(&filler);
			i = 0;
		}
	}
	free_player(&filler);
	free(filler);
	filler = NULL;
//	sleep(500);
	return (1);
}
