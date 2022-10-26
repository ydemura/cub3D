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
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int     form_gamestate(t_game_state *game_state, const char *file_name)
{
	t_data	data;
	int fd;

	game_state->map_size = initiate_map_size(file_name); ///checking how many player symbols I have, find row and cols for array malloc

	//	if (game_state->map_size.err != NO_ERROR)
//		error_message_exit(game_state->map_size.err);


	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (error_handling(game_state->data.err = ERR_OPEN));
	if (form_data_structure(fd, &data) > 0)
		return (error_handling(game_state->data.err));
	game_state->data = data;
	if (read_map(fd, game_state) > 0)
		return (error_handling(game_state->data.err));
	if (close(fd) < 0)
		return (error_handling(game_state->data.err = ERR_CLOSE));
	printf("finished form gameatste\n"); //small check with printf here
	return (0);
}
