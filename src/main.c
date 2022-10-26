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

	if (argc != 2)
		error_message_exit(ERR_INCOMPLETE_INFORMATION);
//		return (error_handling(ERR_INCOMPLETE_INFORMATION));
    form_gamestate(&game_state, argv[1]);

    if (game_state.data.err == NO_ERROR)
        return (0);
    else
        return (1);
}
