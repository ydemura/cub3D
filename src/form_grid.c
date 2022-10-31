//form_grid.c

//cube3d
//27.10.2022

#include "form_grid.h"
#include "check_map_borders.h"
#include "map_utils.h"
#include "gnl.h"
#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

int 	**malloc_int_arr(int row, int col)
{
	int **arr;
	int i;

	arr = malloc(sizeof(int *) * (row + 1));
	if (arr == NULL)
		error_message_exit(ERR_MALLOC);
	i = 0;
	while (i < row)
	{
		arr[i] = malloc(sizeof(int) * col);
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
	char c;

	if (read(fd, &c, 1) < 0)
		error_message_exit(ERR_READ);
	if (c == '\n' || c == '\0')
		return ;
	else if (c == '0')
		gstate->map[grid->ri][grid->ci] = FLOOR;
	else if (c == '1')
		gstate->map[grid->ri][grid->ci] = WALL;
	
	
	else if (is_maze_space(c)) //still not sure if this can be only ' ' or any space
		gstate->map[grid->ri][grid->ci] = EMPTY;
	
	
	else if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		set_player(c, grid, gstate);
	else
		error_message_exit(ERR_MAP);
}

int	form_grid(int fd, t_game_state *gstate)
{
	t_grid grid;

	gstate->map = malloc_int_arr(gstate->map_size.len_rows, gstate->map_size.len_cols);
	grid.ri = 0;
	grid.ci = 0;
	grid.arr = gstate->map;
	grid.rn = gstate->map_size.len_rows;
	grid.cn = gstate->map_size.len_cols;
	grid.max_ri = gstate->map_size.len_rows - 1;
	grid.max_ci = gstate->map_size.len_cols - 1;
	while (grid.ri < grid.rn)
	{
		grid.ci = 0;
		while (grid.ci <= grid.cn)
		{
			fill_grid(fd, &grid, gstate);
			grid.ci++;
		}
		grid.ri++;
	}
	check_map_for_boarders(&grid);
	return (0);
}
