//
//  initiate_struct.h
//  cubic_xcode_part
//
//  Created by Julia Demura on 21/10/2022.
//  Copyright © 2022 Yuliia Demura. All rights reserved.
//

#ifndef initiate_struct_h
#define initiate_struct_h

#include "error_handling.h"

typedef enum    e_kind
{
	KIND_FLOOR = '0',
	KIND_WALL = '1',
	KIND_EMPTY = ' ',
	KIND_END_MAP = 255,
}                 t_kind;

typedef struct  s_flags
{
	int flag_n;
	int flag_s;
	int flag_e;
	int flag_w;
	int flag_f;
	int flag_c;
	int flag_r;
	int all_flags_collected;
}           t_flags;

typedef struct  s_data
{
	t_error_handling err;
	t_flags flags;
	int fd_no; //need to be closed later, pass it to algoritn opened!
	int fd_so;
	int fd_ea;
	int fd_we;
	int rgb_floor;
	int rgb_ceiling;
	int x_render_size;
	int y_render_size;
}               t_data;

void initiate_data_srtuct(t_data *data);

#endif /* initiate_struct_h */
