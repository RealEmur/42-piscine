typedef struct Map
{
	char	**rows;
	char	chr_empty;
	char	chr_blocked;
	char	chr_square;
	int		rows_size;
	int		file_index;
}	t_Map;

int	calc_square(t_Map *map, int x, int y)
{
	int	size;
	int	index_x;
	int	index_y;

	size = 0;
	while (y + size < map->rows_size && map->rows[0][x + size] != '\0')
	{
		index_y = y;
		while (index_y <= y + size)
		{
			index_x = x;
			while (index_x <= x + size)
			{
				if (map->rows[index_y][index_x] == map->chr_blocked)
				{
					return (size);
				}
				index_x++;
			}
			index_y++;
		}
		size++;
	}
	return (size);
}

void	print_square(t_Map *map, int x, int y, int size)
{
	int	base_y;
	int	base_x;

	base_x = x;
	base_y = y;
	while (y < base_y + size)
	{
		x = base_x;
		while (x < base_x + size)
		{
			map->rows[y][x] = map->chr_square;
			x++;
		}
		y++;
	}
}

void	find_and_print_biggest_square(t_Map *map)
{
	int	max;
	int	max_coords[2];
	int	x;
	int	y;

	max = 0;
	y = 0;
	while (y < map->rows_size)
	{
		x = 0;
		while (map->rows[y][x])
		{
			if (map->rows[y][x] == map->chr_empty && \
			calc_square(map, x, y) > max)
			{
				max = calc_square(map, x, y);
				max_coords[0] = x;
				max_coords[1] = y;
			}
			x++;
		}
		y++;
	}
	print_square(map, max_coords[0], max_coords[1], max);
}
