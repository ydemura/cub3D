#include "cub3d.h"

t_vars	*maps_load(t_vars *vars, int where)
{
	int	a;
	int	x;

	x = 0;
	while (vars->map_info.maps[x])
	{
		a = 0;
		while (vars->map_info.maps[x][a])
		{
			if (vars->map_info.maps[x][a] == '0')
				create_elemntry(vars, a, x, 0XFFFFFF);
			else if (vars->map_info.maps[x][a] == '1')
			{
				create_elemntry(vars, a, x, 0X4C1130);
			}
			else if (vars->map_info.maps[x][a] == 'P' )
			{
				create_elemntry(vars, a, x, 0XFFFFFF);
				if (where == 0)
				{				
					vars->player.y = 200;
					vars->player.x =200 ;
				
					vars->player.pa = 45;
					vars->player.d_x = lround((cos(vars->player.pa)));
					vars->player.d_y = lround((sin(vars->player.pa)));
					printf("dx %f dy %f\n",vars->player.d_x, vars->player.d_y);
					// printf("x %d y %d ,angel value = %f, y value = %f\n",vars->player.x, vars->player.y ,vars->player.d_x, vars->player.d_y);

				}

			}
			a++;
		}
		x++;
	}
					create_player(vars, vars->player.x, vars->player.y);

		mlx_put_image_to_window(vars->mlx, vars->win,
		vars->background.img_ptr, 0, 0);
	return (vars);
}

