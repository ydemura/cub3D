/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydemura <ydemura@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 19:52:18 by yuliia            #+#    #+#             */
/*   Updated: 2022/12/09 14:12:31 by ydemura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/form_grid.h"
#include "../includes/check_map_borders.h"
#include "../includes/map_utils.h"
#include "../includes/gnl.h"
#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <math.h>
#include "../cub3d.h"

char	**malloc_arr(int row, int col)
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

void	set_plr(char c, t_grid *grid, t_game_state *gstate)
{
	gstate->map[grid->ri][grid->ci] = FLOOR;
	gstate->player.x = grid->ci + 0.5;
	gstate->player.y = grid->ri + 0.5;
	gstate->player.hit_x = 0;
	gstate->player.game_speed = 0.2;
	gstate->player.hit_x = 0;
	if (c == 'N')
		gstate->player.pa = 1.5 * M_PI;
	else if (c == 'S')
		gstate->player.pa = M_PI * 0.5;
	else if (c == 'E')
		gstate->player.pa = M_PI * 2;
	else if (c == 'W')
		gstate->player.pa = M_PI ;
	gstate->player.x_view_direction = cos(gstate->player.pa) * 5;
	gstate->player.y_view_direction = sin(gstate->player.pa) * 5;
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
	else if (is_maze_space(grid->c))
		gstate->map[grid->ri][grid->ci] = EMPTY;
	else if (grid->c == 'N' || grid->c == 'S'
		|| grid->c == 'E' || grid->c == 'W')
		set_plr(grid->c, grid, gstate);
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

	gstate->map = malloc_arr(gstate->map_size.len_rows,
			gstate->map_size.len_cols);
	init_grid(gstate, &grid);
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
	if (grid.next_line_flag != grid.rn - 1)
		error_message_exit(ERR_MAP);
	check_map_for_boarders(&grid);
	return (0);
}
