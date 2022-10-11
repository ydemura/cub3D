//
//  read_map.c
//  cubik_VScode
//
//  Created by Yuliia Demura on 17/03/2021.
//

#include "header_all.h"

int find_if_error_is_identifier(char c, t_header_info *head)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E' || c == 'F'|| c == 'C' || c == 'R')
    {
        if (head->all_flags_collected == 1)
			head->errors_parsing = ERR_DUPLICATE_ELEMENT;
        else
			head->errors_parsing = ERR_INCOMPLETE_INFORMATION;
    }
	return (0);
}

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

int find_kind_player(char c, t_tile *tile)
{
    if (c == 'N')
        tile->kind = KIND_PLAYER_N;
    else if (c == 'S')
        tile->kind = KIND_PLAYER_S;
    else if (c == 'E')
        tile->kind = KIND_PLAYER_E;
    else if (c == 'W')
        tile->kind = KIND_PLAYER_W;
    else
        return (1);
    return (0);
}

int    classify_tiles(t_game_state *gstate, char c)
{
    t_tile tile;

    tile.col = 0;
    tile.row = 0;
    tile.kind = KIND_EMPTY;
    if (c == '\n')
        tile.row++;
    else
    {
        if (find_kind_structure(c, &tile) == 1 && find_kind_player(c, &tile) == 1)
            return (1);
        set_tile(gstate, tile);
        tile.col++;
    }
    return (0);
}

int        read_map(t_game_state *gstate, int fd)
{
    t_tile tile;

    tile.col = 0;
    tile.row = 0;
    tile.kind = KIND_EMPTY;
    
    gstate->tiles = malloc(gstate->map_size.len_rows * gstate->map_size.len_cols * sizeof(t_tile));
    set_tile(gstate, tile);
    int is_error = 0;
    char c;
    
    while (read(fd, &c, 1) > 0 && !is_error)
    {
        if (classify_tiles(gstate, c) == 1)
        {
            find_if_error_is_identifier(c, &gstate->head);
            break;

        }
    }
    return (0);
}
