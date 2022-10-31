//
//  map_utils.h
//  cubic_xcode_part
//
//  Created by Julia Demura on 25/10/2022.
//  Copyright © 2022 Yuliia Demura. All rights reserved.
//

#ifndef map_utils_h
#define map_utils_h

#include "parsing_gamestate.h"

int	is_maze_number(char c);
int	is_map_char(char c);
int	is_maze_space(char c);
int	is_maze_player(char c, char next);

#endif /* map_utils_h */
