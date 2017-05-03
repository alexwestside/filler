
#include "filler.h"

int main()
{
	int fd = open("/Users/alex/ClionProjects/filler/test", O_RDONLY);

	t_filler *filler;

	filler_init(&filler);

	while (get_next_line(fd, &filler->line))
		valid_and_init(ft_strsplit(filler->line, ' '), &filler);
	place_token(filler);
	free_filler(filler);
	return (1);
}
