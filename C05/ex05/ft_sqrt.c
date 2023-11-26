int	ft_sqrt(int nb)
{
	int		num;

	if (nb < 0)
		return (0);
	num = 1;
	while (num <= nb / num)
	{
		if (num * num == nb)
			return (num);
		num++;
	}
	return (0);
}
