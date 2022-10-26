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
	t_error_handling errors_parsing;
}				t_map_size;

t_map_size initiate_map_size(const char *file_name);

#endif /* initiate_map_size_h */
