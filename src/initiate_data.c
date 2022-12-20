/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiate_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydemura <ydemura@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 19:52:25 by yuliia            #+#    #+#             */
/*   Updated: 2022/12/09 14:30:05 by ydemura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/initiate_data.h"
#include "../includes/parsing_gamestate.h"
#include <stdlib.h>

t_flags	initiate_flags(void)
{
	t_flags	flags;

	flags.flag_no = 0;
	flags.flag_ea = 0;
	flags.flag_so = 0;
	flags.flag_we = 0;
	flags.flag_f = 0;
	flags.flag_c = 0;
	flags.all_flags_collected = 0;
	return (flags);
}

void	initiate_data_srtuct(t_data *data)
{
	data->err = NO_ERROR;
	data->no = NULL;
	data->so = NULL;
	data->ea = NULL;
	data->we = NULL;
	data->rgb_floor = -1;
	data->rgb_ceiling = -1;
	data->flags = initiate_flags();
}
