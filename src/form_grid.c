/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuliia <yuliia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 19:52:18 by yuliia            #+#    #+#             */
/*   Updated: 2022/10/31 19:52:20 by yuliia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "form_grid.h"
#include "check_map_borders.h"
#include "map_utils.h"
#include "gnl.h"
#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

char 	**malloc_int_arr(int row, int col)
{
	char	**arr;
	int		i;

	arr = malloc(sizeof(char *) * (row + 1));
	if (arr == NULL)
		error_message_exit(ERR_MALLOC);
	i = 0;
	while (i < row)
	{
		arr[i] = malloc(sizeof(char) * (col + 1));
		arr[i][col] = '\0';
		if (arr[i] == NULL)
			error_message_exit(ERR_MALLOC);
		i++;
	}
	arr[i] = NULL;
	return (arr);
}

void	set_player(char c, t_grid *grid, t_game_state *gstate)
{
	gstate->map[grid->ri][grid->ci] = FLOOR;
	gstate->player.x = grid->ci;
	gstate->player.y = grid->ri;
	if (c == 'N')
	{
		gstate->player.x_view_direction = grid->ci;
		gstate->player.y_view_direction = grid->ri - 1;
	}
	else if (c == 'S')
	{
		gstate->player.x_view_direction = grid->ci;
		gstate->player.y_view_direction = grid->ri + 1;
	}
	else if (c == 'E')
	{
		gstate->player.x_view_direction = grid->ci + 1;
		gstate->player.y_view_direction = grid->ri;
	}
	else if (c == 'W')
	{
		gstate->player.x_view_direction = grid->ci - 1;
		gstate->player.y_view_direction = grid->ri;
	}
}

void	fill_grid(int fd, t_grid *grid, t_game_state *gstate)
{
	if (read(fd, &grid->c, 1) < 0)
		error_message_exit(ERR_READ);
	if (grid->c == '\0')
		return ;
	else if (grid->c == '\n')
		grid->next_line_flag++;
	else if (grid->c == '0')
		gstate->map[grid->ri][grid->ci] = FLOOR;
	else if (grid->c == '1')
		gstate->map[grid->ri][grid->ci] = WALL;
	else if (is_maze_space(grid->c)) ///still not sure if this can be only ' ' or any space
		gstate->map[grid->ri][grid->ci] = EMPTY;
	else if (grid->c == 'N' || grid->c == 'S'
		|| grid->c == 'E' || grid->c == 'W')
		set_player(grid->c, grid, gstate);
	else
		error_message_exit(ERR_MAP);
}

void	init_grid(t_game_state *gstate, t_grid *grid)
{
	grid->ri = 0;
	grid->ci = 0;
	grid->arr = gstate->map;
	grid->rn = gstate->map_size.len_rows;
	grid->cn = gstate->map_size.len_cols;
	grid->next_line_flag = 0;
}

int	form_grid(int fd, t_game_state *gstate)
{
	t_grid	grid;

	gstate->map = malloc_int_arr(gstate->map_size.len_rows,
			gstate->map_size.len_cols);
	while (grid.ri < grid.rn && grid.c != '\0')
	{
		grid.ci = 0;
		while (grid.ci < grid.cn + 1)
		{
			fill_grid(fd, &grid, gstate);
			if (grid.c == '\n')
				break ;
			grid.ci++;
		}
		grid.ri++;
	}
	if (grid.next_line_flag != grid.rn)
		error_message_exit(ERR_MAP);
	check_map_for_boarders(&grid);
	return (0);
}
