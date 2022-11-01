#include "cub3d.h"

int check_up(t_vars *vars)
{
    return(50 < vars->player.y);
}

int check_down(t_vars *vars)
{
    int down = vars->map_info.line - 1;
    return ((down * 50) > vars->player.y + vars->game_speed);
}

int check_left(t_vars *vars)
{
    return (vars->player.x > 50);
}

//result = check_position(vars, 0, -1);
int check_right(t_vars *vars)
{
    int x = vars->player.x /50;
    int y = vars->player.y /50;
    int len = vars->map_info.len - 1;
    
    if (vars->map_info.maps[y][x -1] == '1')
    {
        printf("duvar konumu [%d][%d]\n", y , x - 1);
        printf("duvar %d player %d\n",(x-1) * 50, vars->player.x);
        return ((x - 1) * 50 > vars->player.x);
    }
    return (vars->player.x + vars->game_speed < len * 50);
}