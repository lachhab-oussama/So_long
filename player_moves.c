/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olachhab <olachhab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 11:48:52 by olachhab          #+#    #+#             */
/*   Updated: 2025/02/01 09:49:47 by olachhab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_move_up(t_big *data)
{
	int	new_y;

	new_y = data->player_y - 32;
	if (data->map[new_y / 32][data->player_x / 32] != '1')
	{
		if (data->map[new_y / 32][data->player_x / 32] == 'C')
		{
			data->collectibles_number -= 1;
		}
		data->map[data->player_y / 32][data->player_x / 32] = '0';
		data->player_y = new_y;
		data->map[data->player_y / 32][data->player_x / 32] = 'P';
		render_free_space(*data);
		if (data->player_x != data->exit_x || data->player_y != data->exit_y)
		{
			mlx_put_image_to_window(data->mlx, data->win, data->img_exit,
				data->exit_x, data->exit_y);
		}
		find_player_position(data);
		data->count_moves += 1;
		printf("Player moves: %d\n", data->count_moves);
	}
}

void	player_move_down(t_big *data)
{
	int	new_y;

	new_y = data->player_y + 32;
	if (data->map[new_y / 32][data->player_x / 32] != '1')
	{
		if (data->map[new_y / 32][data->player_x / 32] == 'C')
		{
			data->collectibles_number -= 1;
		}
		data->map[data->player_y / 32][data->player_x / 32] = '0';
		data->player_y = new_y;
		data->map[data->player_y / 32][data->player_x / 32] = 'P';
		render_free_space(*data);
		if (data->player_x != data->exit_x || data->player_y != data->exit_y)
		{
			mlx_put_image_to_window(data->mlx, data->win, data->img_exit,
				data->exit_x, data->exit_y);
		}
		find_player_position(data);
		data->count_moves += 1;
		printf("Player moves: %d\n", data->count_moves);
	}
}

void	player_move_left(t_big *data)
{
	int	new_x;

	new_x = data->player_x - 32;
	if (data->map[data->player_y / 32][new_x / 32] != '1')
	{
		if (data->map[data->player_y / 32][new_x / 32] == 'C')
		{
			data->collectibles_number -= 1;
		}
		data->map[data->player_y / 32][data->player_x / 32] = '0';
		data->player_x = new_x;
		data->map[data->player_y / 32][data->player_x / 32] = 'P';
		render_free_space(*data);
		if (data->player_x != data->exit_x || data->player_y != data->exit_y)
		{
			mlx_put_image_to_window(data->mlx, data->win, data->img_exit,
				data->exit_x, data->exit_y);
		}
		find_player_position(data);
		data->count_moves += 1;
		printf("Player moves: %d\n", data->count_moves);
	}
}

void	player_move_right(t_big *data)
{
	int	new_x;

	new_x = data->player_x + 32;
	if (data->map[data->player_y / 32][new_x / 32] != '1')
	{
		if (data->map[data->player_y / 32][new_x / 32] == 'C')
		{
			data->collectibles_number -= 1;
		}
		data->map[data->player_y / 32][data->player_x / 32] = '0';
		data->player_x = new_x;
		data->map[data->player_y / 32][data->player_x / 32] = 'P';
		render_free_space(*data);
		if (data->player_x != data->exit_x || data->player_y != data->exit_y)
		{
			mlx_put_image_to_window(data->mlx, data->win, data->img_exit,
				data->exit_x, data->exit_y);
		}
		find_player_position(data);
		data->count_moves += 1;
		printf("Player moves: %d\n", data->count_moves);
	}
}

void	render_free_space(t_big data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data.map[i])
	{
		j = 0;
		while (data.map[i][j])
		{
			if (data.map[i][j] == '0')
			{
				data.prev_player_x = j * 32;
				data.prev_player_y = i * 32;
				mlx_put_image_to_window(data.mlx, data.win,
					data.img_trace_player, data.prev_player_x,
					data.prev_player_y);
			}
			j++;
		}
		i++;
	}
}
