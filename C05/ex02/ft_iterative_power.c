int	ft_iterative_power(int nb, int power)
{
	int		base;

	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	base = nb;
	while (power > 1)
	{
		nb *= base;
		power--;
	}
	return (nb);
}
