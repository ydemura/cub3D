/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_borders.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuliia <yuliia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 19:45:41 by yuliia            #+#    #+#             */
/*   Updated: 2022/10/31 19:46:31 by yuliia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_MAP_BORDERS_H
# define CHECK_MAP_BORDERS_H

typedef struct
{
	int		ri;
	int		ci;
	int		rn;
	int		cn;
	char	**arr;
	char	c;
	int		next_line_flag;
}			t_grid;

int	check_map_for_boarders(t_grid *grid);

# endif /* check_map_borders_h */
