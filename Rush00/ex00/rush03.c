void	ft_putchar(char c);

char	getchar(int x, int y, int xmax, int ymax)
{
	if (y == 0 && (x == 0 || x == xmax))
		return ('A');
	else if (y == ymax && (x == 0 || x == xmax))
		return ('C');
	else if ((x == 0 || x == xmax) || (y == 0 || y == ymax))
		return ('B');
	else
		return (' ');
}

int	rush(int x, int y)
{
	int		i;
	int		j;

	if (x <= 0 || y <= 0)
		return (0);
	i = 0;
	while (i < y)
	{
		j = 0;
		while (j < x)
		{
			ft_putchar(getchar(i, j, y - 1, x - 1));
			j++;
		}
		ft_putchar('\n');
		i++;
	}
	return (1);
}
