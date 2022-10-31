//
//  map_utils.c
//  cubic_xcode_part
//
//  Created by Julia Demura on 25/10/2022.
//  Copyright © 2022 Yuliia Demura. All rights reserved.
//

#include "map_utils.h"

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

//N,S,E or W for the player’s start position and spawning orientation.
int	is_maze_player(char c, char next)
{
	if ((c == 'N' || c == 'S' || c == 'E' || c == 'W')
			&& (is_maze_number(next) || is_maze_space(next)))
		return (TRU);
	else
		return (FLS);
}
