//
//  form_gamestate.c
//  cubic_xcode_part
//
//  Created by Julia Demura on 21/10/2022.
//  Copyright © 2022 Yuliia Demura. All rights reserved.
//

#include "form_gamestate.h"
#include "form_header_structure.h"
#include "read_map.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int     form_gamestate(t_game_state *game_state, const char *file_name)
{
	t_header_info head;
	int fd;

	game_state->map_size = initiate_map_size(file_name); //count_map_size (open-count-close)
	if (game_state->map_size.errors_parsing != NO_ERROR)
		return (error_handling(game_state->map_size.errors_parsing));
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (error_handling(game_state->head.errors_parsing = ERR_OPEN));
	if (form_header_structure(fd, &head) > 0)
		return (error_handling(game_state->head.errors_parsing));
	game_state->head = head;
	if (read_map(fd, game_state) > 0)
		return (error_handling(game_state->head.errors_parsing));
	if (close(fd) < 0)
		return (error_handling(game_state->head.errors_parsing = ERR_CLOSE));
	printf("finished form gameatste\n"); //small check with printf here
	return (0);
}
