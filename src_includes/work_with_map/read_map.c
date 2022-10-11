//
//  read_map.c
//  cubik_VScode
//
//  Created by Yuliia Demura on 17/03/2021.
//

#include "header_all.h"

int find_kind_structure(char c, t_tile *tile)
{
    if (c == '0')
        tile->kind = KIND_FLOOR;
    else if (c == '1')
        tile->kind = KIND_WALL;
    else if (c == '2')
        tile->kind = KIND_OBJECT;
    else if (c == ' ')
        tile->kind = KIND_EMPTY;
    else
        return (1);
    return (0);
}

void    check_char(char c, t_player_info *p_info, t_game_state *gstate, t_tile *tile)
{
    if (c == 'N')
    {
        p_info->x_player_view_direction = tile->col;
        p_info->y_player_view_direction = tile->row - 1; //one row up
    }
    else if (c == 'S')
    {
        p_info->x_player_view_direction = tile->col;
        p_info->y_player_view_direction = tile->row + 1; //1 row down
    }
    else if (c == 'E')
    {
        p_info->x_player_view_direction = tile->col + 1;
        p_info->y_player_view_direction = tile->row;
    }
    else if (c == 'W')
    {
        p_info->x_player_view_direction = tile->col - 1;
        p_info->y_player_view_direction = tile->row;
    }
}

void fill_player_info(char c, t_tile *tile, t_game_state *gstate)
{
    t_player_info p_info;

    check_char(c, &p_info, gstate, tile);
    p_info.x_player = tile->col;
    p_info.y_player = tile->row;
    gstate->p_info = p_info;
    gstate->p_info.x_camera = 0;
    gstate->p_info.y_camera = 0.66;
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

int        read_map(t_game_state *gstate, int fd)
{
    t_tile tile;
    int map_flag;
    char c;

    tile.col = 0;
    tile.row = 0;
    tile.kind = KIND_EMPTY;
    map_flag = 0;
    gstate->tiles = malloc(gstate->map_size.len_rows * gstate->map_size.len_cols * sizeof(t_tile));
    set_tile(gstate, tile);
    while (read(fd, &c, 1) > 0)
    {
        if (check_set_of_char(c) == 0)
        {
            if (c != '\n' && map_flag == 0)
                map_flag = 1;
            if (map_flag == 1)
                classify_tiles(gstate, c, &tile);
        }
        else
            return (find_if_error_is_identifier(c, &gstate->head));
    }
    return (0);
}
