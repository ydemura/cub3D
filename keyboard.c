#include "cub3d.h"

void draw_line(t_vars *data, double angle, int line_lenght, long color)
{
    int x1;
    int y1;

    for(int i = 0; i < line_lenght; i += 1)
    {
        x1 = (int)(i * sin(angle)) + data->player.x + 1;
        y1 = (int)(i * cos(angle)) + data->player.y + 1;
		// printf("x %d y %d ,angel value = %f, y value = %f\n",data->player.x, data->player.y ,data->player.d_x, data->player.d_y);	
        if (x1 < 15 * 50 && x1 > 0  && y1 < 5 * 50 && y1 > 0)
            my_mlx_pixel_put(&data->background, x1, y1, color);
    }
    // printf("x value = %d, y value = %d\n", x1, y1);
}
void change_color_pixel(t_vars *vars, int color, int x, int y)
{
	int a = 0;
	int b;
	while (a < 5)
	{
		b = 0;
		while (b < 5)
		{
			my_mlx_pixel_put(&vars->background, a, b, color);
			b++;
		}
		a++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->background.img_ptr, x, y);
	
}
int FixAng(int a){ if(a>359){ a-=360;} if(a<0){ a+=360;} return a;}
void clean_maps(t_vars *vars)
{
	
    if (vars->background.img_ptr)
	{
	mlx_destroy_image(vars->mlx, vars->background.img_ptr);
	}
			vars->background.img_ptr = mlx_new_image(vars->mlx, 15 * 50, 5 * 50);
	vars->background.address = mlx_get_data_addr(vars->background.img_ptr,
			&vars->background.bits_per_pixel,
			&vars->background.line_size, &vars->background.endian);
}
void	change_position(t_vars *vars, int keycode)
{
	clean_maps(vars);
	if (keycode == LEFT || keycode == A)
	{
		vars->player.pa+=45; 
		vars->player.d_x = cos(vars->player.pa) * 5;
		vars->player.d_y = sin(vars->player.pa) * 5;
	// 	vars->player.pa=FixAng(vars->player.pa);
	// 	vars->player.d_x=cos(degToRad(vars->player.pa));
	// 	vars->player.d_y=-sin(degToRad(vars->player.pa));
	// 	// vars->player.x -= vars->game_speed;
	}
	if (keycode == RIGHT || keycode == D)
	{
	
		
		vars->player.pa -= 45; 
		vars->player.d_x = cos(vars->player.pa) * 5;
		vars->player.d_y = sin(vars->player.pa) * 5;
	}
	if (keycode == DOWN || keycode == S)
	{
		vars->player.x -= vars->player.d_x;
		vars->player.y -= vars->player.d_y;
		printf("down %d %d\n",vars->player.x, vars->player.y);

	} 
	if (keycode == UP || keycode == W)
	{
		
		vars->player.x += vars->player.d_x;
		vars->player.y += vars->player.d_y;
		printf("up %d %d\n",vars->player.x, vars->player.y);

	}
	maps_load(vars, 1);
	

}

void	check_position(t_vars *vars)
{
	int x = vars->player.x;
	int y = vars->player.y;
	printf("konum x = %d y %d\n", x , y);
}


int	click_button(int keycode, t_vars *vars)
{
	int result;

	result = -1;
	
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
        exit(0);
	}
	if (keycode == RIGHT || keycode == D)
		{
			if (check_right(vars))
				result = 0;
		}
	else if (keycode == LEFT || keycode == A)
	{
		if (check_left(vars))
			result = 0;
	}

	else if (keycode == DOWN || keycode == S){
		if (check_down(vars))
			result = 0;
		}
	else if (keycode == UP || keycode == W)
	{
		//printf("burda\n");
		if (check_up(vars) && result != 0){
			//printf("girdi\n\n");
			result = 0;
		}
	}
	else
		return (0);
	result = 0;
	if (result == 0)
		change_position(vars, keycode);
	return (0);
}

int	close_clik(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit (0);
}