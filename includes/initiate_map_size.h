//
//  initiate_map_size.h
//  cubic_xcode_part
//
//  Created by Julia Demura on 25/10/2022.
//  Copyright © 2022 Yuliia Demura. All rights reserved.
//

#ifndef initiate_map_size_h
#define initiate_map_size_h

#include "error_handling.h"

typedef	struct 	s_map_size
{
	int len_rows;
	int len_cols;
	int map_error;
	int player_flag;
	int	strings_before_map;
	t_error_handling err;
}				t_map_size;

//open file, check how many rows and cols I need to malloc further, check if there is only 1 player flag N within map
// exits in case of malloc/read/open fails.
//exits in case there is no player or > 1 player

t_map_size initiate_map_size(const char *file_name);

#endif /* initiate_map_size_h */
