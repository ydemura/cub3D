#include "cub3d.h"


int draw_ray(t_vars *data, double angle, long color)
{
    int x1;
    int y1;
	int  i = 0;
	int len;
	int oldx;
	int oldy;
	oldx = (int)(i * cos(angle)) + data->player.x;
    oldy = (int)(i * sin(angle)) + data->player.y;
	printf("angel %f\n",angle);
    while(1)
    {
        x1 = (i * cos(angle)) + data->player.d_x + data->player.x;
        y1 = (i * sin(angle)) + data->player.d_y + data->player.y;
		// printf("x %d y %d ,angel value = %f, y value = %f\n",data->player.x, data->player.y ,data->player.d_x, data->player.d_y);	
        // printf("x1 %d y1 %d\n",x1,y1);
		if (x1 < data->map_info.len * 50 && x1 > 0  && y1 < data->map_info.line * 50 && y1 > 0)
		{
			if (check_walls(x1, y1, data))
			{
            	my_mlx_pixel_put(&data->background, x1 , y1, color);
				// printf("ray x %d y %d\n",x1,y1);
			}
			else
				break;
		}
		else
		{
			break;
		}
		i++;
    }

	// printf("new x %d - old x %d = %d. and new y %d - old y %d = %d\n",x1,oldx, x1-oldx, y1,oldy, y1-oldy);
	len = find_ray_len(x1-oldx, y1-oldy);
	return (len);
}

void draw_angle(t_vars *data, double angle, int line_lenght, long color)
{
    int x1;
    int y1;

    for(int i = 0; i < line_lenght; i += 1)
    {
        x1 = (int)(i * cos(angle)) + data->player.x + 1;
        y1 = (int)(i * sin(angle)) + data->player.y + 1;
		// printf("x %d y %d ,angel value = %f, y value = %f\n",data->player.x, data->player.y ,data->player.d_x, data->player.d_y);	
        if (x1 < data->map_info.len * 50 && x1 > 0  && y1 < data->map_info.line * 50 && y1 > 0)
            my_mlx_pixel_put(&data->background, x1, y1, color);
    }
    // printf("x value = %d, y value = %d\n", x1, y1);
}