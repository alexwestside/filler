
#include "filler.h"

int		main(void)
{
	t_filler	*filler;
	char		**s;
	int			i;

	i = 0;
	filler_init_0(&filler);
	while (get_next_line(0, &filler->line))
	{
		(!i) ? filler_init_1(&filler) : 0;
		i++;
		s = ft_strsplit(filler->line, ' ');
		valid_and_init(s, &filler);
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
	return (1);
}
