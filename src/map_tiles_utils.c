//
//  map_tiles_utils.c
//  cubic_xcode_part
//
//  Created by Julia Demura on 25/10/2022.
//  Copyright © 2022 Yuliia Demura. All rights reserved.
//

#include "map_tiles_utils.h"

int	is_maze_number(char c)
{
	if (c == '0' || c == '1')
		return (TRU);
	else
		return (FLS);
}

int	is_map_char(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (TRU);
	else
		return (FLS);
}

int	is_maze_space(char c)
{
	if (c == 32 || (c >= 8 && c <= 14))
		return (TRU);
	else
		return (FLS);
}

int	is_maze_player(char c, char next)
{
	if (c == 'N' && next != 'O')
		return (TRU);
	else
		return (FLS);
}

static int     index_of_tile(t_map_size map, int row, int col)
{
	return (row * map.len_cols + col);
}

t_tile    get_tile(const t_game_state *gstate, int row, int col)
{
	int i;

	i = index_of_tile(gstate->map_size, row, col);
	return (gstate->tiles[i]);
}

void    set_tile(t_game_state *gstate, t_tile tile)
{
	int i;

	i = index_of_tile(gstate->map_size, tile.row, tile.col);
	gstate->tiles[i] = tile;
}

int find_if_error_is_identifier(char c, t_data *head)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E' || c == 'F'|| c == 'C' || c == 'R')
	{
		if (head->flags.all_flags_collected == 1)
			head->err = ERR_DUPLICATE_ELEMENT;
		else
			head->err = ERR_INCOMPLETE_INFORMATION;
	}
	return (0);
}

int find_char_in_map_set(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (0);
	else if (c == ' ' || c == '0' || c == '1')
		return (0);
	else if (c == '\n')
		return (0);
	else
		return (1);
}
