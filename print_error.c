/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olachhab <olachhab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 10:25:59 by olachhab          #+#    #+#             */
/*   Updated: 2025/02/01 10:58:40 by olachhab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void print_error(char *str)
{
    printf("%s", str);
}

int	argumet_num(int ac)
{
	if (ac != 2)
	{
		print_error("You forget to put maps\n");
		return (0);
	}
	return (1);
}

int	close_window(void *param)
{
	t_big	*data;

	data = (t_big *)param;
	cleanup(data);
	exit(0);
	return (0);
}