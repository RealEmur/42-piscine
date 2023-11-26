int	ft_str_is_alpha(char *str)
{
	while (*str)
	{
		if (!(*str <= 'Z' && *str >= 'A') && !(*str >= 'a' && *str <= 'z'))
			return (0);
		str++;
	}
	return (1);
}
