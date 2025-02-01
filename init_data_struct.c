/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olachhab <olachhab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 11:48:38 by olachhab          #+#    #+#             */
/*   Updated: 2025/02/01 09:52:52 by olachhab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_data(t_big *data)
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

int	initialize_images(t_big *data)
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
