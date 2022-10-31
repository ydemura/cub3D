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
#include "initiate_data.h"
#include "initiate_map_size.h"

typedef struct  s_player
{
	int x;
	int y;
	int x_view_direction;
	int y_view_direction;
	double x_camera;
	double y_camera;
}               t_player;

typedef struct  s_game_state
{
	t_map_size	map_size;
	t_data		data;
	t_player	player;
	char		**map;
	
}               t_game_state;

typedef struct  s_parsing_result
{
	
	//map
	char	**map;
	
	//map sizes
	int len_rows; // - total rows number
	int len_cols; // - longest column size
	
	//floor and seiling collors
	unsigned int rgb_floor;
	unsigned int rgb_ceiling;
	
	//texture opened file descriptors
	int fd_no;
	int fd_so;
	int fd_ea;
	int fd_we;
	
	//player section, also can be in player structure
	int player_x;
	int player_y;
	int x_view_direction;
	int y_view_direction;
	double x_camera;
	double y_camera;
	int pa; // not initialized
}               t_parsing_result;

t_game_state	form_gamestate(const char *file_name);

#endif /* form_gamestate_h */
