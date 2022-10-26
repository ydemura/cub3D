//
//  main.c
//  cubik_xcode_part
//
//  Created by Yuliia Demura on 17/03/2021.
//

#include "form_gamestate.h"

int main(int argc, const char *argv[])
{
	t_game_state	game_state;

    form_gamestate(&game_state, argv[1]);
    
    
    if (game_state.head.errors_parsing == NO_ERROR)
        return (0);
    else
        return (1);
}
