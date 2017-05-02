
#include "filler.h"

void valid_init_plato(char **s, t_filler **filler)
{
	if (!ft_strcmp(s[0], "Plateau"))
		if (isdigit_str(s[1], 0), 1)
			if (isdigit_str(s[2], 0), 2)
				init_plato(filler, ft_atoi(s[1]), ft_atoi(s[2]));
			else
				ft_error(2, 0);
		else
			ft_error(2, 0);
	else
		ft_error(2, 0);
}

void valid_init_player(char **s, t_filler **filler)
{
	static int player = 1;

	if (!ft_strcmp(s[0], "$$$"))
		if (!ft_strcmp(s[1], "exec"))
			if (!ft_strcmp(s[2], "p1") || !ft_strcmp(s[2], "p2"))
				if (!ft_strcmp(s[3], ":"))
					if (isprint_str(s[3]))
						player == 1 ? (*filler)->p1 = (*filler)->line : (*filler)->p2 = (*filler)->line;
					else
						ft_error(1, player);
				else
					ft_error(1, player);
			else
				ft_error(1, player);
		else
			ft_error(1, player);
	else
		ft_error(1, player);
}


void valid_and_init(char **line, t_filler **filler)
{
	if (!ft_strcmp(line[0], "$$$"))
		valid_init_player(line, filler);
	if (!ft_strcmp(line[0], "Plateau"))
		valid_init_plato(line, filler);
	if (isdigit_str(line[0], 0) && !line[1])
		return  ;
	if (isdigit_str(line[0], 0) && line[1])
		fill_plato(line[1]);
	if (!ft_strcmp(line[0], "Piece"))
		valid_init_token(line, filler);
	if (isprint_str(line[0]) && !line[1])
		fill_token(line, filler);
}