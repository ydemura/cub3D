/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: adoner <adoner@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/03 16:00:13 by adoner        #+#    #+#                 */
/*   Updated: 2022/12/09 12:57:54 by adoner        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "minilibx_opengl/include/MLX42/MLX42.h"
# include "get_next_line/get_next_line.h"
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include "libft/libft.h"
# include "includes/parsing_gamestate.h"

# define SCREENWIDTH 1000
# define SCREENHEIGHT 1000

# define TRUE 1
# define FALSE 0

typedef struct s_calculation
{
	int			map_x;
	int			map_y;
	int			step_x;
	int			step_y;
	double		ray_x;
	double		ray_y;
	double		delta_x;
	double		delta_y;
	double		side_x;
	double		side_y;
	int			hit;
}				t_calculation;

typedef struct s_draw_info
{
	int				top;
	int				bottom;
	unsigned int	color;
	double			step;
	mlx_texture_t	*tex;
	double			text_start;
}					t_draw_info;

void	click_button(mlx_key_data_t keydata, void *info);
int		close_clik(t_parsing_result *data);
void	walls(t_parsing_result *data, int i);
void	start_draw(t_parsing_result *data);
double	len_find(t_parsing_result *data, double angle);
void	move(t_parsing_result *data);
void	draw_3d(t_parsing_result *data);

#endif