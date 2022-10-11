//
//  main.c
//  cubik_xcode_part
//
//  Created by Yuliia Demura on 17/03/2021.
//

#include "header_all.h"

#define FIXTURES_PATH_HOME "/Users/julia/Desktop/cubik/tests/tests/maps_variations/"
#define FIXTURES_PATH_CODAM "/Users/ydemura/Desktop/cubik/cubik_xcode_part/cubik_xcode_part/maps_variations/"

//    char *file_name = FIXTURES_PATH_CODAM"map_basic.cub";
//    char *file_name = FIXTURES_PATH_CODAM"map_r_mistake.cub";
//    char *file_name = FIXTURES_PATH_CODAM"map_basic.cub";
//    char *file_name = FIXTURES_PATH_CODAM"test_map_copy.cub";
    
//    char *file_name = FIXTURES_PATH_HOME"map_r_mistake.cub";
//    char *file_name = FIXTURES_PATH_HOME"test_map_copy.cub";

int main(int argc, const char *argv[])
{
    int i;
    
    i = 0;
    char *file_name = FIXTURES_PATH_CODAM"small_map_for_reading.cub";
    t_game_state game_state;

    form_gamestate(&game_state, file_name);
    
//    start_algoritm(&game_state); - mlx, breaking xcode, later
    find_distance(&game_state);
    
    
    
    if (game_state.head.errors_parsing == NO_ERROR)
        return (0);
    else
        return (1);
}
