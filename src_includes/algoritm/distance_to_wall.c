//
//  distance_to_wall.c
//  cubic_xcode_part
//
//  Created by Yuliia Demura on 5/10/21.
//  Copyright © 2021 Yuliia Demura. All rights reserved.
//

#include "header_all.h"

void    find_distance(t_game_state *gstate)
{
    
    int mapWidth;
    int mapHeight;
    int screenWidth;
    int screenHeight;
    
    //double - floats that are bigger
    
    double posX; //x and y start position
    double posY;
    
    double dirX; //x and y player's view direction vector
    double dirY;
    
    double planeX; //the 2d raycaster version of camera plane
    double planeY;
    
    double time_frame; //2 screenshots I am gonna show
    double old_time_frame;
    
    double x;
    double w;
    
    double cameraX; //x-coordinate in camera space
    double rayDirX; // direction of the ray
    double rayDirY;
    
    mapWidth = gstate->map_size.len_cols;
    mapHeight = gstate->map_size.len_rows;
    
    screenWidth = gstate->head.x_render_size;
    screenHeight = gstate->head.y_render_size;

    posX = gstate->p_info.x_player;
    posY = gstate->p_info.y_player;
    
    dirX = gstate->p_info.x_player_view_direction;
    dirY = gstate->p_info.y_player_view_direction;
    
    planeX = gstate->p_info.x_camera;
    planeY = gstate->p_info.y_camera;

    time_frame = 0;
    old_time_frame = 0;
    
    x = 0;
    w = gstate->head.x_render_size;
    
    int mapX; //coordinates of the square where the ray is now
    int mapY;
    
    double sideDistX; // lenght of the ray from current position to x/y side
    double sideDistY; // initially, at first
    
    double deltaDistX; //length of the ray from one x/y side to next x/y side
    double deltaDistY; //and for y same
    
    double perpWallDist; //explained later
    
    int stepX; //is it x or y step direction (+1 or -1)
    int stepY;
    
    int hit; //flag if the wall was hit
    int side; //NS or EW
    

    mapX = (int)posX;
    mapY = (int)posY;
    //or
//    mapX = gstate->p_info.x_player;
//    mapY = gstate->p_info.y_player;
    
    hit = 0;
    
    while (x < w)
    {
        //calculate ray position and direection
        cameraX = 2 * x / w - 1;
        rayDirX = dirX + planeX * cameraX;
        rayDirY = dirY + planeY * cameraX; //why camera X?
        x++;
        
        //as drawing triange with deltaDistanceX and deltaDistance Y we use Pyphagoras for calculations
        //  a² + b² = c²
        //  c = sqr(a2 + b2) a2 = 1, b2 = rayDiry2/rayDirx2 (for x) and x/y for y
        
        //deltaDistX = sqrt(1 + (rayDirY * rayDirY)/(rayDirX * rayDirX));
        //or if simplified:
        deltaDistX = fabs(1 / rayDirX); //wtf is std::abs
        deltaDistY = fabs(1 / rayDirY);
    }
    
    
    
    
}
