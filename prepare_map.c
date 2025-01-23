#include "so_long.h"

void find_exit(t_big *data)
{
	int i;
	int j;

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
				fil_exit(*data);
			}
			j++;
		}
		i++;
	}
}

void find_player_position(t_big *data)
{
	int i;
	int j;

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
				fil_player(*data);
			}
			j++;
		}
		i++;
	}
}

void find_collect(t_big *data)
{
	int i;
	int j;

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
				fil_collect(*data);
			}
			j++;
		}
		i++;
	}
}

static int count_map_lines(char *map_path)
{
	int fd;
	int line_count;
	char *line;

	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		return (-1);

	line_count = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		free(line);
		line_count++;
	}
	close(fd);
	return (line_count);
}

static int allocate_map(t_big *data, char *map_path)
{
	int line_count;

	line_count = count_map_lines(map_path);
	if (line_count <= 0)
	{
		perror("Error reading map or empty map");
		return (0);
	}

	data->map = (char **)malloc(sizeof(char *) * (line_count + 1));
	if (!data->map)
	{
		perror("Memory allocation failed");
		return (0);
	}
	data->map[line_count] = NULL;
	return (1);
}

void prepare_maps(t_big *data)
{
	int fd;
	int i;
	int j;
	char *line;

	if (!allocate_map(data, "./maps/test.ber"))
		return;

	fd = open("./maps/test.ber", O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening map file");
		return;
	}
	i = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		data->map[i] = line;
		i++;
	}
	data->map[i] = NULL;
	close(fd);
	fill_background(data, BACKGROUND_COLOR);
	i = 0;
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

void fil_to_win(t_big data, int x, int y)
{
	data.map_x = x * 32;
	data.map_y = y * 32;
	if (data.map[y][x] == '1')
		fil_wall(data);
}

void fil_wall(t_big data)
{
	mlx_put_image_to_window(data.mlx, data.win, data.img_wall,
							data.map_x, data.map_y);
}

void fil_player(t_big data)
{
	mlx_put_image_to_window(data.mlx, data.win, data.img_player,
							data.player_x, data.player_y);
}

void fil_exit(t_big data)
{
	mlx_put_image_to_window(data.mlx, data.win, data.img_exit,
							data.exit_x, data.exit_y);
}

void fil_collect(t_big data)
{
	mlx_put_image_to_window(data.mlx, data.win, data.img_collect,
							data.collect_x, data.collect_y);
}

void fill_background(t_big *data, int color)
{
	for (int y = 0; y < (data->map_height * 32); y++)
	{
		for (int x = 0; x < (data->map_width * 32); x++)
		{
			mlx_pixel_put(data->mlx, data->win, x, y, color);
		}
	}
}
