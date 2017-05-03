
#include "filler.h"

void filler_init(t_filler **filler)
{
	(*filler) = (t_filler *) malloc(sizeof(t_filler));
	(*filler)->plato = NULL;
	(*filler)->line = NULL;
	(*filler)->plato_info = NULL;
	(*filler)->p1 = NULL;
	(*filler)->p2 = NULL;
	(*filler)->token = NULL;
	(*filler)->token_info = NULL;
}

void init_plato(t_filler **filler, int x, int n)
{
	if (!((*filler)->plato))
	{
		x++;
		(*filler)->plato = (char **) malloc(sizeof(char *) * x);
		(*filler)->plato[x] = NULL;
	}
}

void fill_plato(char *line, t_filler **filler)
{
	int i;

	i = 0;
	while((*filler)->plato[i])
		i++;
	(*filler)->plato[i] = line;
}

void init_token(t_filler **filler, int x, int n)
{
	if (!((*filler)->token))
	{
		x++;
		(*filler)->token = (char **) malloc(sizeof(char *) * x);
		(*filler)->token[x] = NULL;
	}
}

void fill_token(char *line, t_filler **filler)
{
	int i;

	i = 0;
	while ((*filler)->token[i])
		i++;
	(*filler)->token[i] = line;
}