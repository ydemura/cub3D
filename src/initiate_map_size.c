/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiate_map_size.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuliia <yuliia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 19:52:32 by yuliia            #+#    #+#             */
/*   Updated: 2022/10/31 19:52:33 by yuliia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "initiate_map_size.h"
#include "libft.h"
#include "gnl.h"
#include "form_data_structure.h"
#include "map_utils.h"
#include <fcntl.h>
#include <unistd.h>

int	initiate_map_struct_open_file(const char *file_name, t_map_size *map_size)
{
	int	fd;

	map_size->len_cols = 0;
	map_size->len_rows = 0;
	map_size->map_error = 0;
	map_size->player_flag = 0;
	map_size->strings_before_map = 0;
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		error_message_exit(ERR_OPEN);
	return (fd);
}

void	check_player_flag(char *str, t_map_size *map_size)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == 'N' && str[i + 1] != 'O')
		{
			map_size->player_flag++;
			if (map_size->player_flag > 1)
				error_message_exit(ERR_MAP);
		}
		i++;
	}
}

int	is_string_maze_part_of_map(char *str, t_map_size *map_size)
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
		{
			map_size->player_flag++;
			i++;
		}
		else
			return (FLS);
	}
	return (TRU);
}

int	get_longest_col_increase_row(char *str, t_map_size *map_size)
{
	if (map_size->len_cols < ft_strlen(str))
		map_size->len_cols = ft_strlen(str);
	map_size->len_rows++;
	return (0);
}

t_map_size	initiate_map_size(const char *file_name)
{
	int			fd;
	int			res;
	char		*str;
	t_map_size	map_size;

	res = 1;
	fd = initiate_map_struct_open_file(file_name, &map_size);
	while (res > 0)
	{
		res = exam_get_next_line(fd, &str);
		if (res == 0)
			break ;
		if (is_string_maze_part_of_map(str, &map_size) == TRU)
			get_longest_col_increase_row(str, &map_size);
		else if (map_size.len_rows == 0)
			map_size.strings_before_map++;
		else if (map_size.len_rows > 0
			&& is_string_maze_part_of_map(str, &map_size) == FLS)
			error_message_exit(ERR_MAP);
	}
	if (close(fd) < 0)
		error_message_exit(ERR_CLOSE);
	if (map_size.player_flag != 1)
		error_message_exit(ERR_MAP);
	return (map_size);
}
