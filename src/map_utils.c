/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_utils.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: yuliia <yuliia@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/31 19:52:50 by yuliia        #+#    #+#                 */
/*   Updated: 2022/11/20 16:21:08 by adoner        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/map_utils.h"

int	is_maze_number(char c)
{
	if (c == '0' || c == '1')
		return (TRU);
	else
		return (FLS);
}

int	is_map_char(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (TRU);
	else
		return (FLS);
}

int	is_maze_space(char c)
{
	if (c == 32 || (c >= 8 && c <= 14))
		return (TRU);
	else
		return (FLS);
}

//N,S,E or W for the player’s start position and spawning orientation.
int	is_maze_player(char c, char next)
{
	if ((c == 'N' || c == 'S' || c == 'E' || c == 'W')
		&& (is_maze_number(next) || is_maze_space(next)))
		return (TRU);
	else
		return (FLS);
}
