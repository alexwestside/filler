
#include "filler.h"

void init_plato(t_filler **filler, int x, int n)
{
	x++;
	(*filler)->plato = (char **)malloc(sizeof(char*) * x);
	(*filler)->plato[x] = NULL;
	while (x--)
		(*filler)->plato[x] = (char *)malloc(sizeof(char));
	(*filler)->plato_info = (*filler)->line;
}