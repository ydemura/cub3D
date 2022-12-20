/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_borders.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydemura <ydemura@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 19:45:41 by yuliia            #+#    #+#             */
/*   Updated: 2022/12/08 15:08:45 by ydemura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_MAP_BORDERS_H
# define CHECK_MAP_BORDERS_H

typedef struct s_grid
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

#endif /* check_map_borders_h */
