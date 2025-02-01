/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olachhab <olachhab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 11:48:25 by olachhab          #+#    #+#             */
/*   Updated: 2025/02/01 10:50:01 by olachhab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_map_size(t_big *data)
{
	char	*line;
	int		fd;
	int		i;

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
		if (i == 0)
			data->map_width = (int)ft_strlen(line) - 1;
		free(line);
		i++;
	}
	data->map_height = i;
	close(fd);
	if (data->map_width == data->map_height)
	{
		print_error("map not rectangular");
		exit(0);
	}
}
