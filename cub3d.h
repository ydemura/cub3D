/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: adoner <adoner@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/03 16:00:13 by adoner        #+#    #+#                 */
/*   Updated: 2022/10/31 17:34:46 by adoner        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_HPP
# define CUB3D_HPP
# include "minilibx_opengl/mlx.h"
# include "get_next_line/get_next_line.h"
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
#include <math.h>
# include "libft/libft.h"

# define ESC 53
# define UP 126
# define RIGHT 124
# define DOWN 125
# define LEFT 123
# define W 13
# define D 2
# define S 1
# define A 0
# define TRUE 1
# define FALSE 0
# define PI 3.14159265359
typedef struct s_img
{
	void	*img_ptr;
	char	*address;
	int		bits_per_pixel;
	int		line_size;
	int		len_height;
	int		img_width;
	int		endian;
}			t_img;

typedef struct s_map
{
	int		player;
	int		collection;
	int		exit;
	int		line;
	int		len;
	char	**maps;
}			t_map;
typedef struct s_player
{
	int x;
	int y;
	double d_x;
	double d_y;
	double pa;
}				t_player;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	int		image_len;
	t_img	background;
	t_player	player;
	int		game_speed;
	int		total_eat;
	int		counter;
	int		ate;
	t_map	map_info;
}			t_vars;


int check_up(t_vars *vars);
int	click_button(int keycode, t_vars *vars);
int check_right(t_vars *vars);
void create_angel(t_vars *vars, int wall_x, int wall_y);
int check_left(t_vars *vars);
int check_down(t_vars *vars);
t_vars	*maps_load(t_vars *vars, int where);
int	close_clik(t_vars *vars);
void	my_mlx_pixel_put(t_img *img, int x, int y, unsigned int colour);
void create_player(t_vars *vars, int player_x, int player_y);
void draw_line(t_vars *data, double angle, int line_lenght, long color);
void	check_position(t_vars *vars);
float degToRad(int a);

# endif