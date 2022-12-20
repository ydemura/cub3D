/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydemura <ydemura@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:21:31 by ydemura           #+#    #+#             */
/*   Updated: 2022/12/12 11:13:35 by ydemura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_all(t_parsing_result *data)
{
	int	i;

	i = 0;
	while (data->map[i] != NULL)
	{
		free(data->map[i]);
		i++;
	}
	free(data->map);
	free(data->no);
	free(data->so);
	free(data->ea);
	free(data->we);
	mlx_delete_texture(data->texture[0]);
	mlx_delete_texture(data->texture[1]);
	mlx_delete_texture(data->texture[2]);
	mlx_delete_texture(data->texture[3]);
	mlx_delete_image(data->mlx, data->img);
}

void	create_win(t_parsing_result *data)
{
	data->mlx = mlx_init((const uint32_t)SCREENWIDTH,
			(const uint32_t)SCREENHEIGHT, "Cub3d", false);
	if (!data->mlx)
		exit(EXIT_FAILURE);
	data->img = mlx_new_image(data->mlx, SCREENWIDTH, SCREENHEIGHT);
}

void	start_draw(t_parsing_result *data)
{
	create_win(data);
	draw_3d(data);
	mlx_key_hook(data->mlx, &click_button, data);
	mlx_loop(data->mlx);
	free_all(data);
	mlx_terminate(data->mlx);
}

//	atexit(leaks);
// void	leaks(void)
// {
// 	system("leaks -q cub3d");
// }

void	fill_text(t_parsing_result *data)
{
	data->texture[0] = mlx_load_png(data->ea);
	data->texture[1] = mlx_load_png(data->so);
	data->texture[2] = mlx_load_png(data->we);
	data->texture[3] = mlx_load_png(data->no);
	if (!data->texture[0] || !data->texture[1]
		|| !data->texture[2] || !data->texture[3])
	{
		printf("0 failed to load texture\n");
		exit(1);
	}
}

int	main(int argc, const char **argv)
{
	t_parsing_result	data;

	data = parsing(argv, argc);
	fill_text(&data);
	start_draw(&data);
}	
