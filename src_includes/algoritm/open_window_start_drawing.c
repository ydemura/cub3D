//
//  open_window_start_drawing.c
//  cubic_xcode_part
//
//  Created by Yuliia Demura on 5/6/21.
//  Copyright © 2021 Yuliia Demura. All rights reserved.
//

#include "header_all.h"

//  posX and posY represent the position vector of the player
//  dirX and dirY represent the direction of the player
//  planeX and planeY the camera plane of the player.
    
//  Make sure the camera plane is perpendicular to the direction, but you can change the length of it.

//  The ratio between the length of the direction and the camera plane determinates the FOV
//  the FOV is 2 * atan(0.66/1.0)=66°

//  time and oldTime will be used to store the time of the current and the previous frame
//  the time difference between these two can be used to determinate how much you should move when a certain key is pressed (to move a constant speed no matter how long the calculation of the frames takes), and for the FPS counter.

typedef struct  s_mlx
{
    void    *mlx_ptr; // void * which holds the location of our current MLX instance, initialize MiniLibX
    void    *mlx_win;
    
    void    *img_ptr;
    
}               t_mlx;



//int window_initiate_open(t_mlx *mlx, int size_x, int size_y)
//{
//    mlx->mlx_ptr = mlx_init();
//
//    mlx->mlx_win = mlx_new_window(mlx->mlx_ptr, size_x, size_y, "TITLE_TEST");
//    mlx_loop(mlx->mlx_ptr);
//
//    mlx->img_ptr = mlx_new_image(mlx->mlx_ptr, size_x, size_y);
//
//
//    return (0);
//}



void    start_algoritm(t_game_state *gstate)
{
//    t_mlx mlx;
    
    int mapWidth;
    int mapHeight;
    int screenWidth;
    int screenHeight;
    
    mapWidth = gstate->map_size.len_cols;
    mapHeight = gstate->map_size.len_rows;
    
    screenWidth = gstate->head.x_render_size;
    screenHeight = gstate->head.y_render_size;
    
    
    int posX; //x and y start position
    int posY;
    posX = gstate->p_info.x_player;
    posY = gstate->p_info.y_player;
    
    int dirX; //x and y player's view direction vector
    int dirY;
    dirX = gstate->p_info.x_player_view_direction;
    dirY = gstate->p_info.y_player_view_direction;
    
    
    int planeX;
    float planeY;
    planeX = gstate->p_info.x_camera;
    planeY = gstate->p_info.y_camera;

    int time_frame;
    int old_time_frame;
    
    time_frame = 0;
    old_time_frame = 0;

    //create window with resolution collected - mlx library, also initiate image
//    window_initiate_open(&mlx, gstate->head.x_render_size, gstate->head.y_render_size);
    
    
    int x;
    int w;
    
    x = 0;
    w = gstate->head.x_render_size;
    
    while (x < w)
    {
        
        
        x++;
    }
    
    
}

