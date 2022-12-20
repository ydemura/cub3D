/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiate_data.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydemura <ydemura@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 19:49:35 by yuliia            #+#    #+#             */
/*   Updated: 2022/12/08 15:12:08 by ydemura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INITIATE_DATA_H
# define INITIATE_DATA_H

# include "error_handling.h"

typedef enum e_kind
{
	FLOOR = '0',
	WALL = '1',
	EMPTY = ' ',
	END_MAP = '\0',
}	t_kind;

typedef struct s_flags
{
	int	flag_no;
	int	flag_so;
	int	flag_ea;
	int	flag_we;
	int	flag_f;
	int	flag_c;
	int	all_flags_collected;
}	t_flags;

typedef struct s_data
{
	t_error_handling	err;
	t_flags				flags;
	char				*no;
	char				*so;
	char				*ea;
	char				*we;
	unsigned int		rgb_floor;
	unsigned int		rgb_ceiling;
}	t_data;

void	initiate_data_srtuct(t_data *data);

#endif /* initiate_struct_h */
