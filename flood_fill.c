/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olachhab <olachhab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 09:53:16 by olachhab          #+#    #+#             */
/*   Updated: 2025/02/01 10:49:33 by olachhab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	get_player_position(t_big *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->tab[i])
	{
		j = 0;
		while (data->tab[i][j])
		{
			if (data->tab[i][j] == 'P')
			{
				data->x = j;
				data->y = i;
			}
			j++;
		}
		i++;
	}
}

static int	get_count_map_lines(int fd)
{
	int		line_count;
	char	*line;

	line_count = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		free(line);
		line_count++;
	}
	close(fd);
	return (line_count);
}

static int	get_allocate_map(t_big *data, int fd)
{
	int	line_count;

	line_count = get_count_map_lines(fd);
	if (line_count <= 0)
	{
		print_error("Error reading map or empty map");
		return (0);
	}
	data->tab = (char **)malloc(sizeof(char *) * (line_count + 1));
	if (!data->tab)
	{
		print_error("Memory allocation failed");
		return (0);
	}
	data->tab[line_count] = NULL;
	return (1);
}

void	get_map_in_tab(t_big *data)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	fd = open(data->map_path, O_RDONLY);
	if (!get_allocate_map(data, fd))
		return ;
	fd = open(data->map_path, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		data->tab[i] = line;
		i++;
	}
	data->tab[i] = NULL;
	close(fd);
	get_player_position(data);
}

static void	fill(char **tab, int map_height, int map_width, int begin_y,
		int begin_x)
{
	if (begin_y < 0 || begin_x < 0 || begin_y >= map_height
		|| begin_x >= map_width)
	{
		return ;
	}
	if (tab[begin_y][begin_x] == '1' || tab[begin_y][begin_x] == 'F')
		return ;
	tab[begin_y][begin_x] = 'F';
	fill(tab, map_height, map_width, begin_y + 1, begin_x);
	fill(tab, map_height, map_width, begin_y - 1, begin_x);
	fill(tab, map_height, map_width, begin_y, begin_x + 1);
	fill(tab, map_height, map_width, begin_y, begin_x - 1);
}

void	flood_fill(t_big *data)
{
	int	i;
	int	j;

	get_map_in_tab(data);
	map_border_check(data);
	fill(data->tab, data->map_height, data->map_width, data->y, data->x);
	i = 0;
	while (data->tab[i])
	{
		j = 0;
		while (data->tab[i][j])
		{
			if (data->tab[i][j] == 'C' || data->tab[i][j] == 'E')
			{
				print_error("Your map not accessible for all elements\n");
				cleanup(data);
				exit(0);
			}
			j++;
		}
		i++;
	}
}
