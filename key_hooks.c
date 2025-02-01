/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olachhab <olachhab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 11:48:41 by olachhab          #+#    #+#             */
/*   Updated: 2025/02/01 10:38:43 by olachhab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_big *data)
{
	if (keycode == 65307)
	{
		cleanup(data);
		exit(1);
	}
	else if (keycode == 119)
		player_move_up(data);
	else if (keycode == 115)
		player_move_down(data);
	else if (keycode == 97)
		player_move_left(data);
	else if (keycode == 100)
		player_move_right(data);
	if (data->collectibles_number == 0 && data->player_x == data->exit_x
		&& data->player_y == data->exit_y)
	{
		printf("Rba7ti m3ana bakia Tide\n");
		cleanup(data);
		exit(0);
	}
	return (0);
}
