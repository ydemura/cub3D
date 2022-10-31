//
//  read_map.c
//  cubik_VScode
//
//  Created by Yuliia Demura on 17/03/2021.
//

#include "read_map.h"
#include "map_utils.h"
#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

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
		return (TRU);
	else if (is_maze_space(c) || is_maze_number(c))
		return (TRU);
	else if (c == '\n')
		return (TRU);
	else
		error_message_exit(ERR_MAP);
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

int find_kind_structure(char c, t_tile *tile)
{
    if (c == '0')
        tile->kind = FLOOR;
    else if (c == '1')
        tile->kind = WALL;
    else if (c == ' ')
        tile->kind = EMPTY;
    else
        return (1);
    return (0);
}

void    check_char(char c, t_player *player_info, t_game_state *gstate, t_tile *tile)
{
    if (c == 'N')
    {
        player_info->x_view_direction = tile->col;
        player_info->y_view_direction = tile->row - 1; //one row up
    }
    else if (c == 'S')
    {
        player_info->x_view_direction = tile->col;
        player_info->y_view_direction = tile->row + 1; //1 row down
    }
    else if (c == 'E')
    {
        player_info->x_view_direction = tile->col + 1;
        player_info->y_view_direction = tile->row;
    }
    else if (c == 'W')
    {
        player_info->x_view_direction = tile->col - 1;
        player_info->y_view_direction = tile->row;
    }
}

void fill_player_info(char c, t_tile *tile, t_game_state *gstate)
{
    t_player player_info;

    check_char(c, &player_info, gstate, tile);
    player_info.x = tile->col;
    player_info.y = tile->row;
    gstate->player = player_info;
    gstate->player.x_camera = 0;
    gstate->player.y_camera = 0.66;
}

int    classify_tiles(t_game_state *gstate, char c, t_tile *tile)
{
    if (c == '\n')
    {
        tile->row++;
        tile->col = 0;
    }
    else if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
    {
        fill_player_info(c, tile, gstate);
        c = '0';
    }
    if (c == ' ' || c == '0' || c == '1' || c == '2')
    {
        find_kind_structure(c, tile);
        set_tile(gstate, *tile);
        tile->col++; //or if col == map_col make col 0 again
    }
    return (0);
}

//this need to be changed in 2d array

int        read_map(int fd, t_game_state *gstate) //t_game_state *gstate, int fd
{
    t_tile tile;
    int map_flag;
    char c;

    tile.col = 0;
    tile.row = 0;
    tile.kind = EMPTY;
    map_flag = 0;
    gstate->tiles = malloc(gstate->map_size.len_rows * gstate->map_size.len_cols * sizeof(t_tile));
    set_tile(gstate, tile);
    while (read(fd, &c, 1) > 0)
    {
        if (find_char_in_map_set(c) == 0)
        {
            if (c != '\n' && map_flag == 0)
                map_flag = 1;
            if (map_flag == 1)
                classify_tiles(gstate, c, &tile);
        }
        else
            return (find_if_error_is_identifier(c, &gstate->data));
    }
    return (0);
}
