/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_gamestate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuliia <yuliia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 19:52:56 by yuliia            #+#    #+#             */
/*   Updated: 2022/10/31 19:55:58 by yuliia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_gamestate.h"
#include "form_data_structure.h"
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
	int				fd;
	t_game_state	game_state;

	game_state.map_size = initiate_map_size(file_name);
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		error_message_exit(ERR_OPEN);
	form_data_structure(fd, &game_state.map_size, &game_state.data);
	form_grid(fd, &game_state);
	camera_resolution(&game_state);
	if (close(fd) < 0)
		error_message_exit(ERR_CLOSE);
	return (game_state);
}

void	pack_parsing(t_game_state *gstate, t_parsing_result *parsing)
{
	parsing->map = gstate->map;
	parsing->len_rows = gstate->map_size.len_rows;
	parsing->len_cols = gstate->map_size.len_cols;
	parsing->rgb_floor = gstate->data.rgb_floor;
	parsing->rgb_ceiling = gstate->data.rgb_ceiling;
	parsing->fd_no = gstate->data.fd_no;
	parsing->fd_so = gstate->data.fd_so;
	parsing->fd_ea = gstate->data.fd_ea;
	parsing->fd_we = gstate->data.fd_we;
	
	//player
	parsing->player = gstate->player;
	//OR
	parsing->player_x = gstate->player.x;
	parsing->player_y = gstate->player.y;
	parsing->x_view_direction = gstate->player.x_view_direction;
	parsing->y_view_direction = gstate->player.y_view_direction;
	parsing->x_camera = gstate->player.x_camera;
	parsing->y_camera = gstate->player.y_camera;
	parsing->pa = gstate->player.pa; //pa is not initialised
}

t_parsing_result	parsing(const char **argv, int argc)
{
	t_game_state		game_state;
	t_parsing_result	parsing;

	if (argc != 2)
		error_message_exit(ERR_INCOMPLETE_INFORMATION);
	game_state = form_gamestate(argv[1]);
	pack_parsing(&game_state, &parsing);
	return (parsing);
}
