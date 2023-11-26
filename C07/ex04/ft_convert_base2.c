int	ft_strlen(char *str)
{
	int		lenght;

	lenght = 0;
	while (str[lenght])
		lenght++;
	return (lenght);
}

int	is_valid_base(char *base)
{
	int		index;

	if (ft_strlen(base) <= 1)
		return (0);
	while (*base)
	{
		if (!(*base >= 32 && *base < 127) || (*base == '-' || *base == '+'))
			return (0);
		index = 1;
		while (base[index])
		{
			if (*base == base[index])
				return (0);
			index++;
		}
		base++;
	}
	return (1);
}

int	ft_find_index(char *str, char target)
{
	int		index;

	index = 0;
	while (str[index])
	{
		if (str[index] == target)
			return (index);
		index++;
	}
	return (-1);
}

char	*trim_nbr_str(char *str, int *sign)
{
	while (*str == ' ')
		str++;
	*sign = 1;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			*sign = !(*sign);
		str++;
	}
	return (str);
}

int	ft_atoi_base(char *str, char *base)
{
	int		num;
	int		digit;
	int		sign;
	int		base_num;

	if (!is_valid_base(base))
		return (0);
	str = trim_nbr_str(str, &sign);
	base_num = ft_strlen(base);
	num = 0;
	while (*str)
	{
		digit = ft_find_index(base, *str);
		if (digit == -1)
			break ;
		num *= base_num;
		num += digit;
		str++;
	}
	if (!sign)
		return (num * -1);
	return (num);
}
