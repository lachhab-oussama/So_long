/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imgs_to_maps.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olachhab <olachhab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 11:48:33 by olachhab          #+#    #+#             */
/*   Updated: 2025/02/01 10:51:09 by olachhab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	trace_img_player(t_big *data)
{
	int	img_width;
	int	img_height;

	data->trace_img_player = "./img/trace_player.xpm";
	data->img_trace_player = mlx_xpm_file_to_image(data->mlx,
			data->trace_img_player, &img_width, &img_height);
	if (!data->img_wall)
	{
		print_error("Failed to load trace player image");
		exit(1);
	}
}

void	wall_img(t_big *data)
{
	int	img_width;
	int	img_height;

	data->wall_path = "./img/wall.xpm";
	data->img_wall = mlx_xpm_file_to_image(data->mlx, data->wall_path,
			&img_width, &img_height);
	if (!data->img_wall)
	{
		print_error("Failed to load wall image");
		exit(1);
	}
}

void	player_img(t_big *data)
{
	int	img_width;
	int	img_height;

	data->player_path = "./img/player.xpm";
	data->img_player = mlx_xpm_file_to_image(data->mlx, data->player_path,
			&img_width, &img_height);
	if (!data->img_player)
	{
		print_error("Failed to load player image");
		exit(1);
	}
}

void	exit_img(t_big *data)
{
	int	img_width;
	int	img_height;

	data->exit_path = "./img/closed_door.xpm";
	data->img_exit = mlx_xpm_file_to_image(data->mlx, data->exit_path,
			&img_width, &img_height);
	if (!data->img_exit)
	{
		print_error("Failed to load exit image");
		exit(1);
	}
}

void	collect_img(t_big *data)
{
	int	img_width;
	int	img_height;

	data->collect_path = "./img/collect.xpm";
	data->img_collect = mlx_xpm_file_to_image(data->mlx, data->collect_path,
			&img_width, &img_height);
	if (!data->img_collect)
	{
		print_error("Failed to load collect image");
		exit(1);
	}
}
