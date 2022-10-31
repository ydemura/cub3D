//
//  check_map_borders.c
//  cubic
//
//  Created by Yuliia Demura on 26/10/2022.
//  Copyright © 2021 Yuliia Demura. All rights reserved.
//

#include "check_map_borders.h"
#include "initiate_data.h"
#include <stdio.h>

int	is_neibor_wall_floor(t_grid *grid, int ri, int ci)
{
	if (ri >= grid->rn || ri < 0 || ci >= grid->cn || ci < 0)
		return (0);
	else if (grid->arr[ri][ci] == WALL || grid->arr[ri][ci] == FLOOR)
		return (1);
	else
		return (0);
}

int is_all_neibors_wall_floor(t_grid *grid, int ri, int ci)
{
	int	find_walls;

	find_walls = 0;
	find_walls += is_neibor_wall_floor(grid, ri - 1, ci - 1);
	find_walls += is_neibor_wall_floor(grid, ri - 1, ci);
	find_walls += is_neibor_wall_floor(grid, ri - 1, ci + 1);
	find_walls += is_neibor_wall_floor(grid, ri, ci - 1);
	find_walls += is_neibor_wall_floor(grid, ri, ci + 1);
	find_walls += is_neibor_wall_floor(grid, ri + 1, ci - 1);
	find_walls += is_neibor_wall_floor(grid, ri + 1, ci);
	find_walls += is_neibor_wall_floor(grid, ri + 1, ci + 1);
	if (find_walls != 8)
		error_message_exit(ERR_MAP);
	return (TRU);
}

int	check_map_for_boarders(t_grid *grid)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < grid->rn)
	{
		j = 0;
		while (j < grid->cn)
		{
			if (grid->arr[i][j] == FLOOR)
				is_all_neibors_wall_floor(grid, i, j);
			j++;
		}
		i++;
	}
	return 0;
}
