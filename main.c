
#include "filler.h"




int main()
{
	int fd = open("/Users/alex/ClionProjects/filler/test", O_RDONLY);

	t_filler *filler;

	filler = (t_filler *)malloc(sizeof(t_filler));
	while (get_next_line(fd, &filler->line))
		valid_and_init(ft_strsplit(filler->line, ' '), &filler);







	return (1);
}
