/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colours.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydemura <ydemura@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 19:51:50 by yuliia            #+#    #+#             */
/*   Updated: 2022/12/09 15:32:55 by ydemura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/colours.h"
#include "../includes/map_utils.h"
#include "../includes/error_handling.h"
#include "../libft/libft.h"
#include <stdio.h>

//http://www.shodor.org/~efarrow/trunk/html/rgbint.html - calculator for color
unsigned int	color_maker(int red, int green, int blue)
{
	unsigned int	alpha;
	unsigned int	res;

	alpha = 255;
	res = 0;
	if ((red >= 0 && red <= 255) && (green >= 0 && green <= 255)
		&& (blue >= 0 && blue <= 255))
		res = ((unsigned int)(red << 24 | green << 16 | blue << 8 | alpha));
	else
		error_message_exit(ERR_COLOUR);
	return (res);
}

int	number_collection(char *str, t_data *data, char c, int *n_array)
{
	while (ft_isdigit(*str) == 0)
		str++;
	n_array[0] = ft_atoi(str);
	while (ft_isdigit(*str) == 1)
		str++;
	while (ft_isdigit(*str) == 0)
		str++;
	n_array[1] = ft_atoi(str);
	while (ft_isdigit(*str) == 1)
		str++;
	while (ft_isdigit(*str) == 0)
		str++;
	n_array[2] = ft_atoi(str);
	while (ft_isdigit(*str) == 1)
		str++;
	if (c == 'C')
		data->rgb_ceiling = color_maker(n_array[0], n_array[1],
				n_array[2]);
	if (c == 'F')
		data->rgb_floor = color_maker(n_array[0], n_array[1], n_array[2]);
	return (1);
}

int	digit_pattern(const char *str)
{
	int	i;

	i = 0;
	while (is_maze_space(str[i]))
		i++;
	if (ft_isdigit(str[i]) == 0)
		error_message_exit(ERR_COLOUR);
	while (ft_isdigit(str[i]) == 1)
		i++;
	while (is_maze_space(str[i]))
		i++;
	return (i);
}

void	is_valid_color_input(const char *str)
{
	size_t	i;

	i = 0;
	while (is_maze_space(str[i]))
		i++;
	if (str[i] == 'C' || str[i] == 'F')
		i++;
	i += digit_pattern(str + i);
	if (str[i] == ',')
		i++;
	i += digit_pattern(str + i);
	if (str[i] == ',')
		i++;
	i += digit_pattern(str + i);
	if (str[i] != '\0')
		error_message_exit(ERR_COLOUR);
	if (ft_strlen(str) != i)
		error_message_exit(ERR_COLOUR);
}

int	color_collect(t_data *data, char *str)
{
	int	n_array[3];
	int	*ptr_array;
	int	i;

	i = 0;
	ptr_array = n_array;
	while (str[i] != '\0')
	{
		if (str[i] == 'C' || str[i] == 'F' || is_maze_space(str[i])
			|| str[i] == ',' || ft_isdigit(str[i]))
			i++;
		else
			error_message_exit(ERR_COLOUR);
	}
	is_valid_color_input(str);
	if (*str == 'C')
		data->flags.flag_c += number_collection(str + 1, data, 'C', ptr_array);
	else if (*str == 'F')
		data->flags.flag_f += number_collection(str + 1, data, 'F', ptr_array);
	return (0);
}
