
#ifndef FILLER_FILLER_H
#define FILLER_FILLER_H

#include "libft/libft.h"
#include "libft/ft_printf.h"
#include "libft/get_next_line.h"

typedef struct		s_map
{
	char			*info;
	char 			**map;
	int 			x;
	int 			n;
}					t_map;

typedef struct		s_player
{
	int				player_id;
	char			*player1;
	char			*player2;
	char			p1;
	char			p2;
}					t_player;

typedef struct		s_filler
{
	char			*line;
	int				**dist;
	struct s_player *player;
	struct s_map 	*plato;
	struct s_map 	*token;
	struct s_map	*place;
}					t_filler;

void valid_and_init(char **line, t_filler **filler);
void valid_init_player(char **s, t_filler **filler);
void valid_init_plato(char **s, t_map **plato, char *line);
void valid_init_token(char **str, t_map **token, char *line);

void filler_init(t_filler **filler);
void init_plato(t_map **plato, int x, int n);
void fill_plato(char *line, t_map **plato);
void init_token(t_map **token, int x, int n);
void fill_token(char *line, t_map **token);
void init_dist(t_filler **filler);

void place_token(t_filler **filler);

void free_filler(t_filler **filler);

void ft_error(int error, int id);
int isdigit_str(char *s, int id);
int isprint_str(char *s);
int ft_abs(int i, int x, int j ,int n);


void print1(t_filler **filler);


#endif //FILLER_FILLER_H
