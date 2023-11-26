int	isalphanumericals(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	else if (c >= 'A' && c <= 'Z')
		return (1);
	else if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

char	*ft_strcapitalize(char *str)
{
	int		i;
	int		uppercase;

	uppercase = 1;
	i = 0;
	while (str[i])
	{
		if (isalphanumericals(str[i]))
		{
			if (uppercase && (str[i] >= 'a' && str[i] <= 'z'))
				str[i] = 'A' + str[i] - 'a';
			else if (!uppercase && (str[i] >= 'A' && str[i] <= 'Z'))
				str[i] = 'a' + str[i] - 'A';
			uppercase = 0;
		}
		else
			uppercase = 1;
		i++;
	}
	return (str);
}
