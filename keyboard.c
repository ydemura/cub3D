#include "cub3d.h"


void	move(t_vars *vars, int keycode)
{
	clean_maps(vars);
	if (keycode == LEFT || keycode == A)
	{
		printf("\n LEFT\n--------------------\n");
		vars->player.pa -= 0.1 * M_PI; 
		printf("angle = %f\n", vars->player.pa / (M_PI));
		if (vars->player.pa < 0)
			vars->player.pa += 2 * M_PI;
		printf("angle after  = %f\n", vars->player.pa / (M_PI));
			vars->player.d_x = cos(vars->player.pa) * 5;
			vars->player.d_y = sin(vars->player.pa) * 5;
		printf("_d %f %f\n",vars->player.d_x, vars->player.d_y);
		printf("left x %d  y %d\n",vars->player.x, vars->player.y);
	}

	if (keycode == RIGHT || keycode == D)
	{
		printf("\n RIGHT\n--------------------\n");
		printf("angle before %f\n",vars->player.pa  / (M_PI));
		vars->player.pa+=0.1 * M_PI; 
		if (vars->player.pa > 2 * M_PI )
			vars->player.pa -= 2 * M_PI;
		vars->player.d_x =  cos(vars->player.pa) * 5;
		vars->player.d_y = sin(vars->player.pa) * 5;
		printf("angle = %f\n", vars->player.pa / (M_PI));
		printf("_d %f %f\n",vars->player.d_x, vars->player.d_y);
		printf("right %d %d\n",vars->player.x, vars->player.y);
		
	}
	if (keycode == DOWN || keycode == S)
	{
		printf("\n DOWN\n--------------------\n");
		printf("angle befor = %f\n", vars->player.pa / (M_PI));
		vars->player.x -= (int)vars->player.d_x;
		vars->player.y -= (int)vars->player.d_y;
		printf("angel %f\n",vars->player.pa  / (M_PI));
		printf("down_d %f %f\n",vars->player.d_x, vars->player.d_y);
		printf("down %d %d\n",vars->player.x, vars->player.y);

	} 
	if (keycode == UP || keycode == W)
	{
		printf("\n UP\n--------------------\n");

		printf(" before angle = %f\n", vars->player.pa / (M_PI));
		vars->player.x += (int)vars->player.d_x;
		vars->player.y += (int)vars->player.d_y;
		printf("angle = %f\n", vars->player.pa / (M_PI));

		printf("up_d %f %f\n",vars->player.d_x, vars->player.d_y);
		printf("up %d %d\n",vars->player.x, vars->player.y);

	}

	maps_load(vars, 1);
	

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
	move(vars, keycode);
	return (0);
}

int	close_clik(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit (0);
}