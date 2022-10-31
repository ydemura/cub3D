//
//  read_map.h
//  cubic_xcode_part
//
//  Created by Julia Demura on 25/10/2022.
//  Copyright © 2022 Yuliia Demura. All rights reserved.
//

#ifndef read_map_h
#define read_map_h

#include "form_gamestate.h"

typedef struct         s_tile
{
	t_kind kind;
	int row;
	int col;
}                    t_tile;


int        read_map(int fd, t_game_state *gstate);

#endif /* read_map_h */
