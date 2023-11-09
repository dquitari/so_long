#include "so_long.h"

int	ft_substr_end(char *str, char *sub)
{
	int	i;
	int	j;

	if (!str || !sub)
		return (-1);
	i = ft_strlen(str) - 1;
	j = ft_strlen(sub) - 1;
	if (j > i)
		return (-1);
	while (j >= 0)
	{
		//ft_printf("str[i] = %c, sub[j] = %c\n", str[i], sub[j]);
		if (str[i] != sub[j])
			return (-1);
		j--;
		i--;
	}
	return (1);
}

int	file_check(char *filename)
{
	int	fd;

	if (ft_substr_end(filename, ".ber") == -1)
		return (-1);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	close(fd);
	return (0);
}

t_xy get_map_size(t_game game, char *filename)
{
	int	fd;
	t_xy size;

	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	ft_printf("%s\n", line);
	size.x = ft_strlen(line);
}

/*t_xy	size_error(t_xy size)
{
	size.x = -1;
	size.y = -1;
	return (size);
}

t_xy	get_map_size(char *filename)
{
	t_xy	size;
	int	fd;
	int	line_len;
	char	*line;

	size = xy_initializer();
	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	ft_printf("%s\n", line);
	size.x = ft_strlen(line);
	ft_printf("x = %d, y = %d\n", size.x, size.y);
	while (line)
	{
		size.y++;
		free(line);
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		ft_printf("%s\n", line);
		line_len = ft_strlen(line);
		if (line_len != size.x)
		{
			free(line);
			close(fd);
			return (size_error(size));
		}
		ft_printf("x = %d, y = %d\n", size.x, size.y);
	}
	size.x--;
	ft_printf("x = %d, y = %d\n", size.x, size.y);
	free(line);
	close(fd);
	return (size);
}*/


void	get_map(char *filename, t_game *game)
{
	int	fd;
	int	i;

	fd = open(filename, O_RDONLY);
	i = 0;
	while (i < game->size.y)
	{
		game->map[i] = get_next_line(fd);
		i++;
	}
	game->map[i] = NULL;
	close(fd);
}
