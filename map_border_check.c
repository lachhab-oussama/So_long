/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_border_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olachhab <olachhab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 09:44:12 by olachhab          #+#    #+#             */
/*   Updated: 2025/02/01 10:53:02 by olachhab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_border_check(t_big *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < data->map_width)
	{
		if (data->tab[0][j] != '1' || data->tab[data->map_height - 1][j] != '1')
		{
			print_error("borders not valid\n");
			exit(0);
		}
		j++;
	}
	while (i < data->map_height)
	{
		if (data->tab[i][0] != '1' || data->tab[i][data->map_width - 1] != '1')
		{
			print_error("borders not valid\n");
			exit(0);
		}
		i++;
	}
}
