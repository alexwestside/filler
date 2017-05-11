
#include "filler.h"

void valid_init_plato(char **s, t_map **plato, char *line)
{
	if (!ft_strcmp(s[0], "Plateau"))
		if (isdigit_str(s[1], 0), 1)
			if (isdigit_str(s[2], 0), 2)
			{
				init_plato(plato, ft_atoi(s[1]), ft_atoi(s[2]));
				(*plato)->info = line;
			}
			else
				ft_error(2, 0);
		else
			ft_error(2, 0);
	else
		ft_error(2, 0);
}

void player_identification(t_player **player, char *line)
{
	if (!strcmp((*player)->player1, "$$$ exec p1 : [./filler]"))
		(*player)->player_id = 1;
	else
		(*player)->player_id = 2;
}

void valid_init_player(char **s, t_filler **filler)
{
	static int player = 1;

	if (!ft_strcmp(s[0], "$$$"))
		if (!ft_strcmp(s[1], "exec"))
			if (!ft_strcmp(s[2], "p1") || !ft_strcmp(s[2], "p2"))
				if (!ft_strcmp(s[3], ":"))
					if (isprint_str(s[3]))
					{
						player == 1 ? (*filler)->player->player1 = (*filler)->line : 0;
						player == 2 ? (*filler)->player->player2 = (*filler)->line : 0;
						player++;
						player_identification(&((*filler)->player), (*filler)->line);
					}
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

void valid_init_token(char **str, t_map **token, char *line)
{
	if (!ft_strcmp(str[0], "Piece"))
		if (isdigit_str(str[1], 1))
			if (isdigit_str(str[2], 2))
			{
				init_token(token, ft_atoi(str[1]), ft_atoi(str[2]));
				(*token)->info = line;
			}
			else
				ft_error(3, 0);
		else
			ft_error(3, 0);
	else
		ft_error(3, 0);
}

void valid_and_init(char **line, t_filler **filler)
{
//	if (line)
//	{
		if (!ft_strcmp(line[0], "$$$"))
			valid_init_player(line, filler);
		else if (!ft_strcmp(line[0], "Plateau"))
			valid_init_plato(line, &((*filler)->plato), (*filler)->line);
		else if (isdigit_str(line[0], 0) && !line[1])
			return;
		else if (isdigit_str(line[0], 0) && line[1])
			fill_plato(line[1], &((*filler)->plato));
		else if (!ft_strcmp(line[0], "Piece"))
			valid_init_token(line, &((*filler)->token), (*filler)->line);
		else if (isprint_str(line[0]) && !line[1])
			fill_token(line[0], &((*filler)->token));
//	}
//	ft_error(4, 0);
}