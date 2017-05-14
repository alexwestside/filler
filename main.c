
#include "filler.h"

int		ft_abs(int i, int j)
{
	return ((i - j) < 0 ? (i - j) * -1 : (i - j));
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

int		main(void)
{
	t_filler	*filler;
	char		**s;
	int			i;

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
