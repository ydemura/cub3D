//
//  map_tiles_utils.h
//  cubic_xcode_part
//
//  Created by Julia Demura on 25/10/2022.
//  Copyright © 2022 Yuliia Demura. All rights reserved.
//

#ifndef map_tiles_utils_h
#define map_tiles_utils_h

#include "form_gamestate.h"

t_tile	get_tile(const t_game_state *gstate, int row, int col);
void	set_tile(t_game_state *gstate, t_tile tile);
int		find_if_error_is_identifier(char c, t_header_info *head);
int		find_char_in_map_set(char c);

#endif /* map_tiles_utils_h */
