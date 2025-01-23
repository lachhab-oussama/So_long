#include "so_long.h"

void player_move_up(t_big *data)
{
	int new_y = data->player_y - 32;
	if (data->map[new_y / 32][data->player_x / 32] != '1')
	{
		if (data->map[new_y / 32][data->player_x / 32] == 'C')
		{
			data->collectibles_number -= 1;
			printf("Number of Collects: %d\n", data->collectibles_number);
		}
		data->map[data->player_y / 32][data->player_x / 32] = '0';
		data->player_y = new_y;
		data->map[data->player_y / 32][data->player_x / 32] = 'P';
		render_free_space(*data);
		render_map(data);
		if (data->map[new_y / 32][data->player_x / 32] == 'E' && data->collectibles_number != 0)
		{
			fil_exit(*data);
		}
		data->count_moves += 1;
		printf("Player moves: %d\n", data->count_moves);
	}
}

void player_move_down(t_big *data)
{
	int new_y = data->player_y + 32;
	if ((data->map[new_y / 32][data->player_x / 32]) != '1')
	{
		if (data->map[new_y / 32][data->player_x / 32] == 'C')
		{
			data->collectibles_number -= 1;
			printf("Number of Collects: %d\n", data->collectibles_number);
		}
		data->map[data->player_y / 32][data->player_x / 32] = '0';
		data->player_y = new_y;
		data->map[data->player_y / 32][data->player_x / 32] = 'P';
		render_free_space(*data);
		render_map(data);
		data->count_moves += 1;
		printf("Player moves: %d\n", data->count_moves);
	}
	if (data->map[new_y / 32][data->player_x / 32] == 'E' && data->collectibles_number != 0)
	{
		fil_exit(*data);
	}
}

void player_move_left(t_big *data)
{
	int new_x = data->player_x - 32;
	if (data->map[data->player_y / 32][new_x / 32] != '1')
	{
		if (data->map[data->player_y / 32][new_x / 32] == 'C')
		{
			data->collectibles_number -= 1;
			printf("Number of Collects: %d\n", data->collectibles_number);
		}
		data->map[data->player_y / 32][data->player_x / 32] = '0';
		data->player_x = new_x;
		data->map[data->player_y / 32][data->player_x / 32] = 'P';
		render_free_space(*data);
		render_map(data);
		if (data->map[data->player_y / 32][new_x / 32] == 'E' && data->collectibles_number != 0)
		{
			fil_exit(*data);
		}
		data->count_moves += 1;
		printf("Player moves: %d\n", data->count_moves);
	}
}

void player_move_right(t_big *data)
{
	int new_x = data->player_x + 32;
	if (data->map[data->player_y / 32][new_x / 32] != '1')
	{
		if (data->map[data->player_y / 32][new_x / 32] == 'C')
		{
			data->collectibles_number -= 1;
			printf("Number of Collects: %d\n", data->collectibles_number);
		}
		data->map[data->player_y / 32][data->player_x / 32] = '0';
		data->player_x = new_x;
		data->map[data->player_y / 32][data->player_x / 32] = 'P';
		render_free_space(*data);
		render_map(data);
		if (data->map[data->player_y / 32][new_x / 32] == 'E' && data->collectibles_number != 0)
		{
			fil_exit(*data);
		}
		data->count_moves += 1;
		printf("Player moves: %d\n", data->count_moves);
	}
}

void render_map(t_big *data)
{
	int i = 0;
	int j = 0;

	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			find_player_position(data);
			j++;
		}
		i++;
	}
}

void render_free_space(t_big data)
{
	int i = 0;
	int j = 0;

	while (data.map[i])
	{
		j = 0;
		while (data.map[i][j])
		{
			if (data.map[i][j] == '0')
			{
				data.prev_player_x = j * 32;
				data.prev_player_y = i * 32;
				mlx_put_image_to_window(data.mlx, data.win, data.img_trace_player,
										data.prev_player_x, data.prev_player_y);
			}
			j++;
		}
		i++;
	}
}

// void update_move_counter(t_big *data)
// {
// 	char move_text[50];
// 	// sprintf(move_text, "Moves: %d", data->count_moves);
// 	mlx_string_put(data->mlx, data->win, 10, 20, 0x000000, "Moves:");
// 	mlx_string_put(data->mlx, data->win, 10, 20, 0x000000, move_text);
// }
