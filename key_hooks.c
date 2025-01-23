#include "so_long.h"

int key_hook(int keycode, t_big *data)
{
	if (keycode == 65307)
	{
		mlx_destroy_window(data->mlx, data->win);
		exit(1);
	}
	else if (keycode == 119)
	{
		player_move_up(data);
	}
	else if (keycode == 115)
	{
		player_move_down(data);
	}
	else if (keycode == 97)
	{
		player_move_left(data);
	}
	else if (keycode == 100)
	{
		player_move_right(data);
	}
	if (data->collectibles_number == 0 && data->exit_number == 0)
	{
		printf("You win\n");
	}
	return (0);
}
