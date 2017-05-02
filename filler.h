
#ifndef FILLER_FILLER_H
#define FILLER_FILLER_H

#include "libft/libft.h"
#include "libft/ft_printf.h"
#include "libft/get_next_line.h"

typedef struct	s_filler
{
	char		*line;
	char		*p1;
	char		*p2;
	char		*plato_info;
	char		**plato;
	char		**pice;
}				t_filler;

void valid_and_init(char **line, t_filler **filler);
void valid_init_player(char **s, t_filler **filler);
void valid_init_plato(char **s, t_filler **filler);

void init_plato(t_filler **filler, int x, int n);

void ft_error(int error, int id);
int isdigit_str(char *s, int id);
int isprint_str(char *s);

#endif //FILLER_FILLER_H
