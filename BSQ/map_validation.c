#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct MapValidation
{
	char	chr_empty;
	char	chr_blocked;
	char	chr_square;
	int		rows_size;
	int		column_size;
}	t_MapValidation;

int		ft_strlen(char *str);
int		ft_simple_atoi(char *str);
char	*ft_realloc(char *str, int *size, int newsize);

int	check_duplicates(char *str)
{
	int	i;

	while (*str)
	{
		i = 1;
		while (str[i])
		{
			if (str[i] == *str)
				return (1);
			i++;
		}
		str++;
	}
	return (0);
}

int	is_valid_line(char *str, t_MapValidation *map)
{
	int	count;

	count = 0;
	while (str[count])
	{
		if (str[count] != map->chr_blocked && str[count] != map->chr_empty \
		&& str[count] != map->chr_square)
			return (0);
		count++;
	}
	if (map->column_size == -1)
		map->column_size = count;
	else if (count != map->column_size || count < 1)
		return (0);
	return (1);
}

int	is_valid_header(char *str, t_MapValidation *map)
{
	int	length;

	length = ft_strlen(str);
	if (length < 4 || check_duplicates(str + length - 3))
		return (0);
	map->chr_square = str[length - 1];
	map->chr_blocked = str[length - 2];
	map->chr_empty = str[length - 3];
	str[length - 3] = '\0';
	map->rows_size = ft_simple_atoi(str);
	if (map->rows_size == -1)
		return (0);
	if (!(map->chr_square >= 32 && map->chr_square <= 126) || \
		!(map->chr_blocked >= 32 && map->chr_blocked <= 126) || \
		!(map->chr_empty >= 32 && map->chr_empty <= 126))
		return (0);
	return (1);
}

char	*get_line(int file_index)
{
	int		str_size;
	char	*row_data;
	char	ch;

	str_size = 1;
	row_data = (char *)malloc(sizeof(char) * str_size);
	row_data[str_size - 1] = '\0';
	while (read(file_index, &ch, 1) > 0 && ch != '\n')
	{
		row_data = ft_realloc(row_data, &str_size, str_size + 1);
		row_data[str_size - 2] = ch;
		row_data[str_size - 1] = '\0';
	}
	return (row_data);
}

int	validate_map(char *str)
{
	t_MapValidation	map;
	int				file;
	int				line_count;
	char			*line;

	file = open(str, 0);
	if (!file)
		return (0);
	line_count = -1;
	line = get_line(file);
	map.column_size = -1;
	while (*line)
	{
		if ((line_count == -1 && !is_valid_header(line, &map)) || \
			(line_count != -1 && !is_valid_line(line, &map)))
			return (0);
		line_count++;
		line = get_line(file);
		if (!line)
			return (0);
	}
	free(line);
	close(file);
	return (line_count == map.rows_size);
}
