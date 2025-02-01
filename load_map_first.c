/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map_first.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olachhab <olachhab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 11:48:12 by olachhab          #+#    #+#             */
/*   Updated: 2025/02/01 10:52:36 by olachhab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_map_lines(char *map_path)
{
	int		fd;
	int		line_count;
	char	*line;

	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		return (-1);
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

int	allocate_map(t_big *data, char *map_path)
{
	int	line_count;

	line_count = count_map_lines(map_path);
	if (line_count <= 0)
	{
		print_error("Error reading map or empty map");
		return (0);
	}
	data->map = (char **)malloc(sizeof(char *) * (line_count + 1));
	if (!data->map)
	{
		print_error("Memory allocation failed");
		return (0);
	}
	data->map[line_count] = NULL;
	return (1);
}

void	load_map(t_big *data)
{
	int		fd;
	int		i;
	char	*line;

	if (!allocate_map(data, data->map_path))
		return ;
	fd = open(data->map_path, O_RDONLY);
	if (fd < 0)
	{
		print_error("Error opening map file");
		return ;
	}
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		data->map[i] = line;
		i++;
	}
	data->map[i] = NULL;
	close(fd);
}

void	check_all_lines(t_big *data)
{
	int	i;
	int	len;

	i = data->map_height - 1;
	len = ft_strlen(data->map[i]);
	i--;
	if (len == 0)
	{
		print_error("mon map exist or empty");
		exit(1);
	}
	while (i >= 0)
	{
		if (len != ft_strlen(data->map[i]) - 1)
		{
			print_error("map not correct load a valid map :(");
			exit(1);
		}
		i--;
	}
}
