//
//  form_gamestate.c
//  cubic_xcode_part
//
//  Created by Julia Demura on 21/10/2022.
//  Copyright © 2022 Yuliia Demura. All rights reserved.
//

#include "form_gamestate.h"
#include "form_data_structure.h"
#include "read_map.h"
#include "form_grid.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

void	camera_resolution(t_game_state *gstate)
{
	gstate->player.x_camera = 0;
	gstate->player.y_camera = 0.66;
}

t_game_state	form_gamestate(const char *file_name)
{
	int fd;
	t_game_state game_state;

	game_state.map_size = initiate_map_size(file_name);
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		error_message_exit(ERR_OPEN);
	form_data_structure(fd, &game_state.map_size, &game_state.data);
	form_grid(fd, &game_state);
	camera_resolution(&game_state);
	if (close(fd) < 0)
		error_message_exit(ERR_CLOSE);
	
	
	printf("finished form gameatste\n"); //small check with printf here
	return (game_state);
}
