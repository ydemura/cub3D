/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiate_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuliia <yuliia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 19:52:25 by yuliia            #+#    #+#             */
/*   Updated: 2022/10/31 19:52:27 by yuliia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "initiate_data.h"
#include "parsing_gamestate.h"
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
	data->fd_no = -1;
	data->fd_so = -1;
	data->fd_ea = -1;
	data->fd_we = -1;
	data->rgb_floor = 0;
	data->rgb_ceiling = 0;
	data->flags = initiate_flags();
}
