/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydemura <ydemura@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 19:53:01 by yuliia            #+#    #+#             */
/*   Updated: 2022/12/12 10:57:21 by ydemura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/textures.h"
#include "../includes/colours.h"
#include "../includes/map_utils.h"
#include "../includes/error_handling.h"
#include "../libft/libft.h"
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

const char	*collect_path(const char *str, const char *extention)
{
	int	i;
	int	len;

	i = 0;
	len = (int)ft_strlen(str);
	if (len < 4)
		error_message_exit(ERR_EXTENTION);
	else if (len == 4)
		str_cmpr_till_n(str, extention, 4);
	if (str_cmpr_till_n(str + (len - 4), extention, 4))
		return (str);
	else
		error_message_exit(ERR_EXTENTION);
	return (str);
}

void	pick_identifier(char *str, t_data *data, int i)
{
	if (str_cmpr_till_n(str, "NO", 2))
	{
		data->no = ft_strdup(collect_path(str + i, ".png"));
		data->flags.flag_no++;
	}
	else if (str_cmpr_till_n(str, "WE", 2))
	{
		data->we = ft_strdup(collect_path(str + i, ".png"));
		data->flags.flag_we++;
	}
	else if (str_cmpr_till_n(str, "EA", 2))
	{
		data->ea = ft_strdup(collect_path(str + i, ".png"));
		data->flags.flag_ea++;
	}
	else if (str_cmpr_till_n(str, "SO", 2))
	{
		data->so = ft_strdup(collect_path(str + i, ".png"));
		data->flags.flag_so++;
	}
	else
		error_message_exit(ERR_ELEMENT_IDENTIFIER);
}

void	double_check(char *str, t_data *data)
{
	if (str_cmpr_till_n(str, "NO", 2) && data->no != NULL)
		error_message_exit(ERR_DUPLICATE_ELEMENT);
	else if (str_cmpr_till_n(str, "WE", 2) && data->we != NULL)
		error_message_exit(ERR_DUPLICATE_ELEMENT);
	else if (str_cmpr_till_n(str, "EA", 2) && data->ea != NULL)
		error_message_exit(ERR_DUPLICATE_ELEMENT);
	else if (str_cmpr_till_n(str, "SO", 2) && data->so != NULL)
		error_message_exit(ERR_DUPLICATE_ELEMENT);
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
	double_check(str, data);
	if (is_maze_space(str[i]) == FLS)
		error_message_exit(ERR_ELEMENT);
	while (is_maze_space(str[i]) == TRU)
		i++;
	pick_identifier(str, data, i);
	return (0);
}
