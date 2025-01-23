#include "so_long.h"

void get_map_size(t_big *data)
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
		if (i == 0)
			data->map_width = (int)ft_strlen(line) - 1;
		free(line);
		i++;
	}
	data->map_height = i;
	close(fd);
}
