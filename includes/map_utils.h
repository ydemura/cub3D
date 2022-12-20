/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydemura <ydemura@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 19:50:24 by yuliia            #+#    #+#             */
/*   Updated: 2022/12/08 15:12:42 by ydemura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_UTILS_H
# define MAP_UTILS_H

# include "parsing_gamestate.h"

int	is_maze_number(char c);
int	is_map_char(char c);
int	is_maze_space(char c);
int	is_maze_player(char c, char next);

#endif /* map_utils_h */
