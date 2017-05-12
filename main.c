
#include "filler.h"

void free_filler(t_filler **filler)
{
	free((*filler)->line);
	free_dist(filler);
	free_player(filler);
	free_plato(filler);
	free_token(filler);
	free_place(filler);
	free(*filler);
	*filler = NULL;
}

int main()
{
	int fd = open("/nfs/2016/o/orizhiy/ClionProjects/filler/test2", O_RDONLY);

	t_filler *filler;

	filler = NULL;
	filler_init(&filler);
	while (get_next_line(fd, &filler->line))
	{
//		valid_and_init(ft_strsplit(filler->line, ' '), &filler);
	}
	place_token(&filler);
	free_filler(&filler);
	free(filler);
	filler = NULL;
	sleep(500);
	return (1);
}
