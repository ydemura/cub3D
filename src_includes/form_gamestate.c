//
//  form_gamestate.c
//  cubic_xcode_part
//
//  Created by Yuliia Demura on 5/3/21.
//  Copyright © 2021 Yuliia Demura. All rights reserved.
//

#include "header_all.h"



int     form_gamestate(t_game_state *game_state, char *file_name)
{
    t_map_size map_size;
    t_error_handling error_handling_with_enum;
    t_header_info head;

    if (count_map_size(file_name, &map_size) > 0)                               //count_map_size (open-count-close)
        return (error_handling(map_size.errors_parsing));
    game_state->map_size = map_size;
    

    int fd = open(file_name, O_RDONLY);                                         //open file
    if (fd == -1)
        return (error_handling(game_state->head.errors_parsing = ERR_OPEN));
    
    
    error_handling_with_enum = check_header(fd, &head);                         //check header
    game_state->head = head;
    if (error_handling_with_enum > 0)
        return (error_handling(game_state->head.errors_parsing));
    
    
    read_map(game_state, fd);                                                   //read_map
    if (error_handling_with_enum > 0)
        return (error_handling(game_state->head.errors_parsing));
    
    
    if (close(fd) < 0)                                                          //close file
        return (error_handling(game_state->head.errors_parsing = ERR_CLOSE));
    printf("finished form gameatste\n");
    return (0);
}
