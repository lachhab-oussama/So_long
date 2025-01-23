#include "so_long.h"

void trace_img_player(t_big *data)
{
	int img_width;
	int img_height;
	data->trace_img_player = "trace_player.xpm";
	data->img_trace_player = mlx_xpm_file_to_image(data->mlx, data->trace_img_player, &img_width, &img_height);
	if (!data->img_wall)
	{
		perror("Failed to load trace player image");
		exit(1);
	}
}

void wall_img(t_big *data)
{
	int img_width;
	int img_height;

	data->wall_path = "wall.xpm";
	data->img_wall = mlx_xpm_file_to_image(data->mlx, data->wall_path, &img_width, &img_height);
	if (!data->img_wall)
	{
		perror("Failed to load wall image");
		exit(1);
	}
}

void player_img(t_big *data)
{
	int img_width;
	int img_height;

	data->player_path = "player.xpm";
	data->img_player = mlx_xpm_file_to_image(data->mlx, data->player_path, &img_width, &img_height);
	if (!data->img_player)
	{
		perror("Failed to load player image");
		exit(1);
	}
}
void exit_img(t_big *data)
{
	int img_width;
	int img_height;

	data->exit_path = "exit.xpm";
	data->img_exit = mlx_xpm_file_to_image(data->mlx, data->exit_path, &img_width, &img_height);
	if (!data->img_exit)
	{
		perror("Failed to load exit image");
		exit(1);
	}
}

void collect_img(t_big *data)
{
	int img_width;
	int img_height;

	data->collect_path = "collect.xpm";
	data->img_collect = mlx_xpm_file_to_image(data->mlx, data->collect_path, &img_width, &img_height);
	if (!data->img_collect)
	{
		perror("Failed to load collect image");
		exit(1);
	}
}
