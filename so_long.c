/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olachhab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:11:54 by olachhab          #+#    #+#             */
/*   Updated: 2025/01/23 13:58:13 by olachhab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int close_window(void *param)
{
	t_big *data;

	data = (t_big *)param;
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
	return (0);
}

static void cleanup(t_big *data)
{
	if (data->map)
	{
		int i = 0;
		while (data->map[i])
			free(data->map[i++]);
		free(data->map);
	}
	if (data->img_wall)
		mlx_destroy_image(data->mlx, data->img_wall);
	if (data->img_player)
		mlx_destroy_image(data->mlx, data->img_player);
	if (data->img_exit)
		mlx_destroy_image(data->mlx, data->img_exit);
	if (data->img_collect)
		mlx_destroy_image(data->mlx, data->img_collect);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
}

static void init_data(t_big *data)
{
	data->mlx = NULL;
	data->win = NULL;
	data->img_wall = NULL;
	data->img_player = NULL;
	data->img_exit = NULL;
	data->img_collect = NULL;
	data->map = NULL;
	data->trace_img_player = NULL;
	data->img_trace_player = NULL;
	data->map_x = 0;
	data->map_y = 0;
	data->player_x = 0;
	data->player_y = 0;
	data->collect_x = 0;
	data->collect_y = 0;
	data->win_width = 0;
	data->win_height = 0;
	data->prev_player_x = 0;
	data->prev_player_y = 0;
	data->count_moves = 0;
	data->map_width = 0;
	data->map_height = 0;
	data->collectibles_number = 0;
	data->player_number = 0;
	data->exit_number = 0;
}
static int initialize_images(t_big *data)
{
	wall_img(data);
	player_img(data);
	exit_img(data);
	collect_img(data);
	trace_img_player(data);
	if (!data->img_wall)
	{
		cleanup(data);
		return (0);
	}
	return (1);
}

int main(void)
{
	t_big data;

	init_data(&data);
	get_map_size(&data);
	chek_elements_of_map(&data);
	data.mlx = mlx_init();
	if (!data.mlx)
		return (1);
	data.win = mlx_new_window(data.mlx, data.map_width * width_pixel, data.map_height * height_pixel, "So_long");

	if (!initialize_images(&data))
		return (1);

	prepare_maps(&data);

	mlx_hook(data.win, 2, 1L << 0, key_hook, &data);
	mlx_hook(data.win, 17, 0, close_window, &data);

	mlx_loop(data.mlx);
	return (0);
}
