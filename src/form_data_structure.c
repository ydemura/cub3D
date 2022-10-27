//
//  form_data_structure.c
//  tests
//
//  Created by Yuliia Demura on 05/04/2021.
//  Copyright © 2021 Yuliia Demura. All rights reserved.
//

#include "form_data_structure.h"
#include "colours.h"
#include "textures.h"
#include "gnl.h"
#include "map_tiles_utils.h"
#include <stdlib.h>

int 	is_string_maze(char *str)
{
	int i;

	i = 0;
    if (str == NULL || str[0] == '\0')
        return (FLS);
	while (str[i] != '\0')
	{
		if (is_maze_number(str[i]) == TRU || is_maze_space(str[i]) == TRU)
			i++;
		else if (is_maze_player(str[i], str[i + 1]) == TRU)
			i++;
		else
			return (FLS); //not map
	}
	return (TRU); //is map
}

void 	is_all_flags_collected(t_data *data)
{
    if (data->flags.flag_w == 1 && data->flags.flag_s == 1 &&
        data->flags.flag_e == 1 && data->flags.flag_n == 1 &&
		data->flags.flag_f == 1 && data->flags.flag_c == 1)
	{
        data->flags.all_flags_collected = 1;
	}
	else if (data->flags.flag_w > 1 || data->flags.flag_s > 1 ||
             data->flags.flag_e > 1 || data->flags.flag_n > 1 ||
			 data->flags.flag_f > 1 || data->flags.flag_c > 1)
	{
		error_message_exit(ERR_DUPLICATE_ELEMENT);
	}
    else
        data->flags.all_flags_collected = 0;
}

int   get_texture_color_resolution(char *str, t_data *data)
{
	while (*str != '\0' && is_maze_space(*str) == TRU)
		str++;
	if (*str == 'N' || *str == 'W' || *str == 'E' || *str == 'S')
		collect_textures(str, data);

	else if (*str == 'C' || *str == 'F')
	{
		if (color_check_collection(data, str) == 1)
			return (data->err);
	}
	else
		error_message_exit(ERR_ELEMENT_IDENTIFIER);
	return (0);
}

int    pars_received_string(t_data *data, char *buff)
{
    if (data->flags.all_flags_collected == 0 && is_string_maze(buff) == 1)
		error_message_exit(ERR_INCOMPLETE_INFORMATION);
    if (get_texture_color_resolution(buff, data) != 0)
        return (data->err);
    is_all_flags_collected(data);
    return (0);
}

int        form_data_structure(int fd, t_data *data)
{
	char 	*buff;
	int		res;

	initiate_data_srtuct(data);
	res = 1;
    while (res > 0 && data->flags.all_flags_collected != 1)
	{
        if (data->err != NO_ERROR)
			return (data->err);
		res = exam_get_next_line(fd, &buff); // ADD original GNL?
		if (buff != NULL)
		{
            pars_received_string(data, buff);
            free(buff);
		}
	}
    if (res == 0 && data->flags.all_flags_collected != 1)
        data->err = ERR_INCOMPLETE_INFORMATION;
    if (data->flags.all_flags_collected == 1 && data->err == NO_ERROR)
        return (0);
    else
        return (data->err);
}
