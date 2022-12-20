/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form_data_structure.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydemura <ydemura@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 19:52:11 by yuliia            #+#    #+#             */
/*   Updated: 2022/12/02 14:56:19 by ydemura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/form_data_structure.h"
#include "../includes/colours.h"
#include "../includes/textures.h"
#include "../includes/gnl.h"
#include "../includes/map_utils.h"
#include <stdlib.h>

int	is_string_maze(char *str)
{
	int	i;

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
			return (FLS);
	}
	return (TRU);
}

void	is_all_flags_collected(t_data *data)
{
	if (data->flags.flag_we == 1 && data->flags.flag_so == 1
		&& data->flags.flag_ea == 1 && data->flags.flag_no == 1
		&& data->flags.flag_f == 1 && data->flags.flag_c == 1)
	{
		data->flags.all_flags_collected = 1;
	}
	else if (data->flags.flag_we > 1 || data->flags.flag_so > 1
		|| data->flags.flag_ea > 1 || data->flags.flag_no > 1
		|| data->flags.flag_f > 1 || data->flags.flag_c > 1)
	{
		error_message_exit(ERR_DUPLICATE_ELEMENT);
	}
	else
		data->flags.all_flags_collected = 0;
}

int	get_texture_color(char *str, t_data *data)
{
	while (*str != '\0' && is_maze_space(*str) == TRU)
		str++;
	if (*str == 'N' || *str == 'W' || *str == 'E' || *str == 'S')
		textures_collect(str, data);
	else if (*str == 'C' || *str == 'F')
		color_collect(data, str);
	else
		error_message_exit(ERR_ELEMENT_IDENTIFIER);
	return (0);
}

int	pars_received_string(t_data *data, char *buff)
{
	if (data->flags.all_flags_collected == 0 && is_string_maze(buff) == 1)
		error_message_exit(ERR_INCOMPLETE_INFORMATION);
	if (get_texture_color(buff, data) != 0)
		error_message_exit(ERR_INCOMPLETE_INFORMATION);
	is_all_flags_collected(data);
	return (0);
}

int	form_data_structure(int fd, t_map_size *mp_size, t_data *data)
{
	char	*buff;
	int		res;

	initiate_data_srtuct(data);
	res = 1;
	while (res > 0 && mp_size->strings_before_map > 0)
	{
		if (data->err != NO_ERROR)
			error_message_exit(ERR_MAP);
		res = exam_get_next_line(fd, &buff);
		if (buff != NULL && buff[0] != '\0')
		{
			pars_received_string(data, buff);
		}
		free(buff);
		buff = NULL;
		mp_size->strings_before_map--;
	}
	if (data->flags.all_flags_collected != 1)
		error_message_exit(ERR_INCOMPLETE_INFORMATION);
	return (0);
}
