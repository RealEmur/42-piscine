void	ft_swap(int *a, int *b)
{
	int		c;

	c = *b;
	*b = *a;
	*a = c;
}

void	ft_rev_int_tab(int *tab, int size)
{
	int		i;

	i = 0;
	while (i < size - i)
	{
		ft_swap(&tab[i], &tab[size - 1 - i]);
		i++;
	}
}
