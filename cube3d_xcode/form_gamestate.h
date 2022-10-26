//
//  form_gamestate.h
//  cubic_xcode_part
//
//  Created by Julia Demura on 21/10/2022.
//  Copyright © 2022 Yuliia Demura. All rights reserved.
//

#ifndef form_gamestate_h
#define form_gamestate_h

#include "error_handling.h"
#include "initiate_struct.h"
#include "initiate_map_size.h"

typedef struct  s_player_info
{
	int x_player;
	int y_player;
	int x_player_view_direction;
	int y_player_view_direction;
	double x_camera;
	double y_camera;
}               t_player_info;

typedef struct         s_tile
{
	t_kind kind;
	int row;
	int col;
}                    t_tile;

typedef struct  s_game_state
{
	t_map_size   map_size;
	t_tile      *tiles;
	t_header_info head;
	t_player_info p_info;
	
}               t_game_state;

int     form_gamestate(t_game_state *game_state, const char *file_name);

#endif /* form_gamestate_h */
