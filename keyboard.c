/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   keyboard.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ydemura <ydemura@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/08 15:25:19 by ydemura       #+#    #+#                 */
/*   Updated: 2022/12/08 21:45:56 by adoner        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "key_moves.h"

int	check_move(int x, int y, t_parsing_result *data)
{
	if (data->len_cols > x && data->len_rows > y && x > 0 && y > 0)
	{
		if (data->map[y][x] == '1')
			return (FALSE);
		return (TRUE);
	}
	return (FALSE);
}

void	key_w(t_parsing_result *data)
{
	double	move_x;
	double	move_y;

	move_x = data->player.x + data->player.game_speed * cos(data->player.pa);
	move_y = data->player.y + data->player.game_speed * sin(data->player.pa);
	if (check_move(move_x, move_y, data))
	{
		data->player.x = move_x;
		data->player.y = move_y;
	}
}

void	move(t_parsing_result *data)
{
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
		key_left(data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_A))
		key_a(data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_D))
		key_d(data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
		key_right(data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_S))
		key_s(data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_W))
		key_w(data);
	draw_3d(data);
}

void	click_button(mlx_key_data_t keydata, void *info)
{
	int					result;
	t_parsing_result	*data;

	data = (t_parsing_result *) info;
	result = -1;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		mlx_close_window(data->mlx);
		exit(0);
	}
	move(data);
}

int	close_clik(t_parsing_result *data)
{
	mlx_close_window(data->mlx);
	exit (0);
}
