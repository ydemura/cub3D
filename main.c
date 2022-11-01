#include <stdio.h>
#include "cub3d.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, unsigned int colour)
{
	char	*dst;
	int		offset;

	offset = y * img->line_size + x * (img->bits_per_pixel / 8);
	dst = img->address + offset;
	*(unsigned int *)dst = colour;
}




void	create_win(t_vars *vars, int x, int y)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, x * 50, y * 50, "CUB3D");
	vars->background.img_ptr = mlx_new_image(vars->mlx, x * 50, y * 50);
	vars->background.address = mlx_get_data_addr(vars->background.img_ptr,
			&vars->background.bits_per_pixel,
			&vars->background.line_size, &vars->background.endian);
}


// -7 up +7 down, 
void create_player(t_vars *vars, int player_x, int player_y)
{

	int x = player_x;
	int y = player_y;
	printf("player x %d y %d\n",player_x,player_y);
	
	while (player_x > x - 3)
	{
		y = player_y;
		while (y - 3 < player_y)
		{
			my_mlx_pixel_put(&vars->background, x, y, 0XE6ADD8);
			y++;
		}
		x++;
	}
	
	// float a = (float)90 /180;
	draw_line(vars, vars->player.pa , 8, 0XE6ADD8);


}





//walls color 0X4C1130
//space  0XFFFFFF
void create_elemntry(t_vars *vars, int wall_x, int wall_y, int color)
{
	int x = wall_x * 50;
	int y = wall_y * 50;
	

	while (x < (wall_x * 50) + 49)
	{
		y = wall_y * 50;
		while (y < (wall_y * 50) + 49 )
		{
			my_mlx_pixel_put(&vars->background, x, y, color);
			y++;
		}
		x++;
	}
}

float degToRad(int a) { return a*M_PI/180.0;}
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
					vars->player.y = (vars->image_len * x) + 15;
					vars->player.x = (vars->image_len * a) + 15;
				
					vars->player.pa = 90;
					vars->player.d_x = (cos(vars->player.pa));
					vars->player.d_y = (sin(vars->player.pa));
					printf("x %d y %d ,angel value = %f, y value = %f\n",vars->player.x, vars->player.y ,vars->player.d_x, vars->player.d_y);

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



void	start_draw(char **data, t_map *maps_info)
{
	t_vars	vars;

	vars.game_speed = 10;
	vars.map_info.maps = data;
	vars.map_info.len = maps_info->len;
	vars.map_info.line = maps_info->line;
	vars.image_len = 50;
	vars.player.x = -1;
	vars.player.y = -1;
	create_win(&vars, maps_info->len , maps_info->line);
	maps_load(&vars, 0);
	mlx_hook(vars.win, 2, 0, click_button, &vars);
	mlx_hook(vars.win, 17, 0, close_clik, &vars);
	mlx_loop(vars.mlx);
}

int main()
{
    char  **map;
	t_map maps_info;

	maps_info.len = 15;
	maps_info.line = 5;
	map = malloc(sizeof(char**) * 6);
	map[0] = malloc(sizeof(char *) * 13);
	map[1] = malloc(sizeof(char *) * 13);
	map[2] = malloc(sizeof(char *) * 13);
	map[3] = malloc(sizeof(char *) * 13);
	map[0] = malloc(sizeof(char *) * 13);
    map[0] = "111111111111111";
	map[1] = "100000000001001";
	map[2] = "10000P000001001";
    map[3] = "100000000001001";
	map[4] = "111111111111111";
	map[5] = NULL;
	start_draw(map, &maps_info);
	
	
}	

