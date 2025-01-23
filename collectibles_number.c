#include "so_long.h"

void chek_elements_of_map(t_big *data)
{
	char *line;
	int fd;
	int i;

	fd = open("./maps/test.ber", O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening map file");
		return;
	}
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		while (line[i])
		{
			if (line[i] == 'C')
			{
				data->collectibles_number += 1;
			}
			if (line[i] == 'P')
			{
				data->player_number += 1;
			}
			if (line[i] == 'E')
			{
				data->exit_number += 1;
			}
			i++;
		}
		free(line);
		i = 0;
	}
	close(fd);
	printf("Number of Collects: %d\n", data->collectibles_number);
	printf("Number of Players: %d\n", data->player_number);
	printf("Number of Exits: %d\n", data->exit_number);
	validation_of_map(data);
}

void validation_of_map(t_big *data)
{
	if (data->player_number != 1 || data->exit_number != 1)
	{
		printf("Error : map non valid check player or exit number");
		exit(1);
	}
}
