#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct Map{
	char	**rows;
	char	chr_empty;
	char	chr_blocked;
	char	chr_square;
	int		rows_size;
	int		file_index;
}	t_Map;

int		ft_strlen(char *str);
int		ft_simple_atoi(char *str);
char	*ft_realloc(char *str, int *size, int newsize);
void	ft_putstr(char *str);
void	find_and_print_biggest_square(t_Map *map);

void	print_map(t_Map *map)
{
	int		index;

	index = 0;
	while (index < map->rows_size)
	{
		ft_putstr(map->rows[index]);
		write(1, "\n", 1);
		index++;
	}
}

char	*get_next_row(t_Map *map)
{
	int		str_size;
	char	*row_data;
	char	ch;

	str_size = 1;
	row_data = (char *) malloc(sizeof(char) * str_size);
	if (!row_data)
		return (0);
	row_data[str_size - 1] = '\0';
	while (read(map->file_index, &ch, 1) > 0 && ch != '\n')
	{
		row_data = ft_realloc(row_data, &str_size, str_size + 1);
		row_data[str_size - 2] = ch;
		row_data[str_size - 1] = '\0';
	}
	return (row_data);
}

int	get_map_array(t_Map *map)
{
	int		index;

	index = 0;
	while (index < map->rows_size)
	{
		map->rows[index] = get_next_row(map);
		if (!map->rows[index])
			return (0);
		index++;
	}
	return (1);
}

int	get_map_info(t_Map *map)
{
	int		str_size;
	char	*header_data;
	char	ch;

	str_size = 1;
	header_data = (char *) malloc(sizeof(char) * str_size);
	if (!header_data)
		return (0);
	header_data[str_size - 1] = '\0';
	while (read(map->file_index, &ch, 1) > 0 && ch != '\n')
	{
		header_data = ft_realloc(header_data, &str_size, str_size + 1);
		header_data[str_size - 2] = ch;
		header_data[str_size - 1] = '\0';
	}
	map->chr_square = header_data[str_size - 2];
	map->chr_blocked = header_data[str_size - 3];
	map->chr_empty = header_data[str_size - 4];
	header_data[str_size - 4] = '\0';
	map->rows_size = ft_simple_atoi(header_data);
	free(header_data);
	return (1);
}

int	handle_map(char *file_path)
{
	t_Map	map;
	int		index;

	map.file_index = open(file_path, 0);
	if (map.file_index == -1)
		return (0);
	if (!get_map_info(&map))
		return (0);
	map.rows = (char **) malloc(sizeof(char *) * map.rows_size);
	if (!map.rows || !get_map_array(&map))
	{
		close(map.file_index);
		return (0);
	}
	close(map.file_index);
	find_and_print_biggest_square(&map);
	print_map(&map);
	index = 0;
	while (index < map.rows_size)
	{
		free(map.rows[index]);
		index++;
	}
	free(map.rows);
	return (1);
}
