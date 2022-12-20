/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiate_map_size.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydemura <ydemura@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 19:50:04 by yuliia            #+#    #+#             */
/*   Updated: 2022/12/08 15:12:36 by ydemura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INITIATE_MAP_SIZE_H
# define INITIATE_MAP_SIZE_H

# include "error_handling.h"

typedef struct s_map_size
{
	int	len_rows;
	int	len_cols;
	int	map_error;
	int	player_flag;
	int	strings_before_map;
}				t_map_size;

//open file, check how many rows and cols I need to malloc further,
//check if there is only 1 player flag N within map
// exits in case of malloc/read/open fails.
//exits in case there is no player or > 1 player

t_map_size	initiate_map_size(const char *file_name);

#endif /* initiate_map_size_h */
