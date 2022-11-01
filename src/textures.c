/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuliia <yuliia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 19:53:01 by yuliia            #+#    #+#             */
/*   Updated: 2022/10/31 19:53:03 by yuliia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "textures.h"
#include "colours.h"
#include "map_utils.h"
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

int	collect_path_open_fd(char *str)
{
	int	fd;

	while (is_maze_space(*str))
		str++;
	str += 1;
	fd = open(str, O_RDONLY);
	//fd = 1; // for test purpose as I dont have textures!
	if (fd < 0)
		error_message_exit(ERR_OPEN);
	// what if texture files are same and if I open opened file what will be/?
    return (fd);
}

void	pick_identifier(char *str, t_data *data)
{
	if (str_cmpr_till_n(str, "NO", 2))
	{
		data->fd_no = collect_path_open_fd(str + 2);
		data->flags.flag_no++;
	}
	else if (str_cmpr_till_n(str, "WE", 2))
	{
		data->fd_we = collect_path_open_fd(str + 2);
		data->flags.flag_we++;
	}
	else if (str_cmpr_till_n(str, "EA", 2))
	{
		data->fd_ea = collect_path_open_fd(str + 2);
		data->flags.flag_ea++;
	}
	else if (str_cmpr_till_n(str, "SO", 2))
	{
		data->fd_so = collect_path_open_fd(str + 2);
		data->flags.flag_so++;
	}
}

int	textures_collect(char *str, t_data *data)
{
	int	i;

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
