/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olachhab <olachhab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 11:48:09 by olachhab          #+#    #+#             */
/*   Updated: 2025/02/01 09:47:38 by olachhab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_exit(t_big *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'E')
			{
				data->exit_x = j * 32;
				data->exit_y = i * 32;
				mlx_put_image_to_window(data->mlx, data->win, data->img_exit,
					data->exit_x, data->exit_y);
			}
			j++;
		}
		i++;
	}
}

void	find_player_position(t_big *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'P')
			{
				data->player_x = j * 32;
				data->player_y = i * 32;
				mlx_put_image_to_window(data->mlx, data->win, data->img_player,
					data->player_x, data->player_y);
			}
			j++;
		}
		i++;
	}
}

void	find_collect(t_big *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'C')
			{
				data->collect_x = j * 32;
				data->collect_y = i * 32;
				mlx_put_image_to_window(data->mlx, data->win, data->img_collect,
					data->collect_x, data->collect_y);
			}
			j++;
		}
		i++;
	}
}

void	prepare_maps(t_big *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			fil_to_win(*data, j, i);
			j++;
		}
		i++;
	}
	find_player_position(data);
	find_collect(data);
	find_exit(data);
}

void	fil_to_win(t_big data, int x, int y)
{
	data.map_x = x * 32;
	data.map_y = y * 32;
	if (data.map[y][x] == '1')
		mlx_put_image_to_window(data.mlx, data.win, data.img_wall, data.map_x,
			data.map_y);
	else
		mlx_put_image_to_window(data.mlx, data.win, data.img_trace_player,
			data.map_x, data.map_y);
}
