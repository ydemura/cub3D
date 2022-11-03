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





void	start_draw(char **data, t_map *maps_info)
{
	t_vars	vars;

	vars.game_speed = 10;
	vars.map_info.maps = data;
	vars.map_info.len = maps_info->len;
	vars.map_info.line = maps_info->line;
	vars.image_len = 50;
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

	// maps1
	// maps_info.len = 15;
	// maps_info.line = 5;
	// map = malloc(sizeof(char**) * maps_info.line + 1);
	// map[0] = malloc(sizeof(char *) * maps_info.len + 1);
	// map[1] = malloc(sizeof(char *) * maps_info.len + 1);
	// map[2] = malloc(sizeof(char *) * maps_info.len + 1);
	// map[3] = malloc(sizeof(char *) * maps_info.len + 1);
	// map[4] = malloc(sizeof(char *) * maps_info.len + 1);
	// map[5] = malloc(sizeof(char *) * maps_info.len + 1);
    // map[0] = "111111111111111";
	// map[1] = "100000000001001";
	// map[2] = "10000P000001001";
    // map[3] = "100000000001001";
	// map[4] = "111111111111111";
	// map[5] = NULL;


	//maps 2
	maps_info.len = 15;
	maps_info.line = 8;
	map = malloc(sizeof(char**) * maps_info.line + 1);
	map[0] = malloc(sizeof(char *) * maps_info.len + 1);
	map[1] = malloc(sizeof(char *) * maps_info.len + 1);
	map[2] = malloc(sizeof(char *) * maps_info.len + 1);
	map[3] = malloc(sizeof(char *) * maps_info.len + 1);
	map[4] = malloc(sizeof(char *) * maps_info.len + 1);
	map[5] = malloc(sizeof(char *) * maps_info.len + 1);
	map[6] = malloc(sizeof(char *) * maps_info.len + 1);
	map[7] = malloc(sizeof(char *) * maps_info.len + 1);
	map[8] = malloc(sizeof(char *) * maps_info.len + 1);
    map[0] = "111111111111111";
	map[1] = "100001000001001";
	map[2] = "10010P010000101";
    map[3] = "101001000000001";
    map[4] = "101000000001001";
    map[5] = "101000001001001";
    map[6] = "101001000000001";
	map[7] = "111111111111111";
	map[8] = NULL;


	//maps3
	// maps_info.len = 5;
	// maps_info.line = 10;
	// map = malloc(sizeof(char**) * maps_info.line + 1);
	// map[0] = malloc(sizeof(char *) * maps_info.len + 1);
	// map[1] = malloc(sizeof(char *) * maps_info.len + 1);
	// map[2] = malloc(sizeof(char *) * maps_info.len + 1);
	// map[3] = malloc(sizeof(char *) * maps_info.len + 1);
	// map[4] = malloc(sizeof(char *) * maps_info.len + 1);
	// map[5] = malloc(sizeof(char *) * maps_info.len + 1);
	// map[6] = malloc(sizeof(char *) * maps_info.len + 1);
	// map[7] = malloc(sizeof(char *) * maps_info.len + 1);
	// map[8] = malloc(sizeof(char *) * maps_info.len + 1);
	// map[9] = malloc(sizeof(char *) * maps_info.len + 1);
    // map[0] = "11111";
	// map[1] = "10001";
	// map[2] = "10001";
	// map[3] = "10001";
	// map[4] = "10001";
	// map[5] = "10001";
	// map[6] = "10001";
	// map[7] = "10001";
	// map[8] = "100P1";
	// map[9] = "11111";
	// map[10] = NULL;
	start_draw(map, &maps_info);
	
	
}	
