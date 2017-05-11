
#include "filler.h"

int main()
{
	int fd = open("/nfs/2016/o/orizhiy/ClionProjects/filler/test2", O_RDONLY);

	t_filler *filler;

	filler_init(&filler);
	while (get_next_line(fd, &filler->line))
		valid_and_init(ft_strsplit(filler->line, ' '), &filler);
	place_token(&filler);
	free_filler(&filler);
	return (1);
}
