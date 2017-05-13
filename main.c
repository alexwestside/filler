
#include "filler.h"

void free_filler(t_filler **filler)
{
	free((*filler)->line);
	free_dist(filler);
//	free_player(filler);
	free_plato(filler);
	free_token(filler);
	free_place(filler);
//	free(*filler);
//	*filler = NULL;
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
//	int fd = open("/nfs/2016/o/orizhiy/ClionProjects/filler/test2", O_RDONLY);

	t_filler *filler;
	char **s;
	int i = 0;

	filler = (t_filler *) malloc(sizeof(t_filler));
	filler->line = NULL;
	filler->player = (t_player *) malloc(sizeof(t_player));
	filler->player->player_id = 0;
	filler->player->player1 = NULL;
	filler->player->player2 = NULL;
	filler->player->p1 = 'O';
	filler->player->p2 = 'X';

	while (get_next_line(0, &filler->line))
	{
		if (!i)
			filler_init(&filler);
		i++;
		s = ft_strsplit(filler->line, ' ');
		valid_and_init(s, &filler);
		free(s);
//		valid_and_init(ft_strsplit(filler->line, ' '), &filler);
		if (read_finish(filler))
		{
			place_token(&filler);
			free_filler(&filler);
			i = 0;
		}
	}
	free(filler);
	filler = NULL;
//	sleep(500);
	return (1);
}
