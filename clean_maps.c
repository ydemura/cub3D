#include "cub3d.h"


void clean_maps(t_vars *vars)
{
	
    if (vars->background.img_ptr)
	{
	mlx_destroy_image(vars->mlx, vars->background.img_ptr);
	}
			vars->background.img_ptr = mlx_new_image(vars->mlx, vars->map_info.len * 50, vars->map_info.line * 50);
	vars->background.address = mlx_get_data_addr(vars->background.img_ptr,
			&vars->background.bits_per_pixel,
			&vars->background.line_size, &vars->background.endian);
}