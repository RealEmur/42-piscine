char	*ft_strstr(char *str, char *to_find)
{
	int		i;

	if (!*to_find)
		return (str);
	while (*str)
	{
		i = 0;
		while (str[i] == to_find[i])
		{
			if (to_find[i + 1] == '\0')
				return (str);
			i++;
		}
		str++;
	}
	return (0);
}
