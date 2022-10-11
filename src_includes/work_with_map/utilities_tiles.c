//utilities.c

//to store all additional f-s
//01.04.2021

#include "header_all.h"

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
