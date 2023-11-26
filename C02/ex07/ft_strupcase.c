char	*ft_strupcase(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] <= 'z' && str[i] >= 'a')
			str[i] = 'A' + (str[i] - 'a');
		i++;
	}
	return (str);
}
