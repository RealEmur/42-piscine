#include <stdlib.h>

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
