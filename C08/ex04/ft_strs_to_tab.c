#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int		length;

	length = 0;
	while (str[length])
		length++;
	return (length);
}

char	*ft_strdup(char *src)
{
	char	*str;
	int		index;

	str = (char *) malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (!str)
		return (0);
	index = 0;
	while (src[index])
	{
		str[index] = src[index];
		index++;
	}
	str[index] = '\0';
	return (str);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			index;
	t_stock_str	*arr;

	arr = (t_stock_str *) malloc(sizeof(t_stock_str) * (ac + 1));
	if (!arr)
		return (0);
	index = 0;
	while (index < ac)
	{
		arr[index].size = ft_strlen(av[index]);
		arr[index].str = av[index];
		arr[index].copy = ft_strdup(av[index]);
		index++;
	}
	arr[index].str = 0;
	return (arr);
}
