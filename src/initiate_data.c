//
//  initiate_struct.c
//  tests
//
//  Created by Yuliia Demura on 19/04/2021.
//  Copyright © 2021 Yuliia Demura. All rights reserved.
//

#include "initiate_data.h"
#include "form_gamestate.h"
#include <stdlib.h>

t_flags initiate_flags(void)
{
	t_flags flags;

	flags.flag_n = 0;
	flags.flag_e = 0;
	flags.flag_s = 0;
	flags.flag_w = 0;
	flags.flag_f = 0;
	flags.flag_c = 0;
	flags.all_flags_collected = 0;
	return (flags);
}

void initiate_data_srtuct(t_data *data)
{
    data->err = NO_ERROR;
	data->fd_no = -1;
	data->fd_so = -1;
	data->fd_ea = -1;
	data->fd_we = -1;
	data->rgb_floor = 0; // should this be int?
	data->rgb_ceiling = 0;
	data->flags = initiate_flags();
}
