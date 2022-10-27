//
//  textures.c
//  cubic
//
//  Created by Yuliia Demura on 19/04/2021.
//  Copyright © 2021 Yuliia Demura. All rights reserved.
//

#include "textures.h"
#include "colours.h"
#include "map_tiles_utils.h"
#include "error_handling.h"
#include "libft.h"
#include <fcntl.h>

int	str_cmpr_till_n(const char *str, const char *example, int n)
{
	if (!str)
		return (FLS);
	while (*str != '\0' && n > 0 && *example != '\0')
	{
		if (*example == *str)
		{
			example++;
			str++;
		}
		else
			return (FLS);
		n--;
	}
	return (TRU);
}

int		collect_path_open_fd(char *str)
{
	int fd;

	while (is_maze_space(*str))
		str++;
	str += 2;
	fd = open(str, O_RDONLY);
	if (fd < 0)
	{
		fd = 1; // for test purpose as I dont have textures!
		//error_message_exit(ERR_OPEN); -- UNCOMMENT later
	}
	// what if texture files are same and if I open opened file what will be/?
	
    return (fd);
}

 void	pick_identifier(char *str, t_data *data)
{
	if (str_cmpr_till_n(str, "NO", 2))
    {
		data->fd_no = collect_path_open_fd(str + 2);
		data->flags.flag_n++;
    }
	else if (str_cmpr_till_n(str, "WE", 2))
    {
		data->fd_we = collect_path_open_fd(str + 2);
		data->flags.flag_w++;
    }
	else if (str_cmpr_till_n(str, "EA", 2))
    {
		data->fd_ea = collect_path_open_fd(str + 2);
		data->flags.flag_e++;
    }
	else if (str_cmpr_till_n(str, "SO", 2))
	{
		data->fd_so = collect_path_open_fd(str + 2);
		data->flags.flag_s++;
	}
}

int    collect_textures(char *str, t_data *data)
{
    int i;
    
    i = 0;
	if (str_cmpr_till_n(str, "NO", 2) || str_cmpr_till_n(str, "WE", 2)
			|| str_cmpr_till_n(str, "EA", 2) || str_cmpr_till_n(str, "SO", 2))
		i += 2;
	else
		error_message_exit(ERR_ELEMENT);
	if (is_maze_space(str[i]) == FLS)
		error_message_exit(ERR_ELEMENT);
	while (is_maze_space(str[i]) == TRU)
		i++;
	if (str_cmpr_till_n(str + i, "./", 2))
		pick_identifier(str, data);
	else
		error_message_exit(ERR_ELEMENT_IDENTIFIER);
	return (0);
}
