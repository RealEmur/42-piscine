int	ft_is_prime(int nb)
{
	int		divider;

	if (nb == 2)
		return (1);
	else if (nb % 2 == 0 || nb <= 1)
		return (0);
	divider = 3;
	while (divider <= nb / divider)
	{
		if (!(nb % divider))
			return (0);
		divider += 2;
	}
	return (1);
}
