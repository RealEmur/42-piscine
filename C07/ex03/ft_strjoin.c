#include <stdlib.h>

int	ft_strlen(char *str)
{
	int		length;

	length = 0;
	while (str[length])
		length++;
	return (length);
}

int	calc_length(char **strs, int size, char *sep)
{
	int		length;
	int		i;
	int		count;

	i = 0;
	length = 0;
	count = 0;
	while (i < size)
	{
		length += ft_strlen(strs[i]);
		count++;
		i++;
	}
	length += (ft_strlen(sep) * (count - 1));
	length++;
	return (length);
}

char	*ft_strcat(char *dest, char *src)
{
	int		i;

	i = 0;
	while (dest[i])
		i++;
	while (*src)
	{
		dest[i] = *src;
		src++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*str;
	int		str_index;
	int		strs_index;

	if (size == 0)
		str = (char *) malloc(sizeof(char));
	else
		str = (char *) malloc(sizeof(char) * \
		(calc_length(strs, size, sep)));
	str_index = 0;
	str[str_index] = '\0';
	strs_index = 0;
	while (strs_index < size)
	{
		if (strs_index != 0)
		{
			ft_strcat(str + str_index, sep);
			str_index += ft_strlen(sep);
		}
		ft_strcat(str + str_index, strs[strs_index]);
		str_index += ft_strlen(strs[strs_index]);
		strs_index++;
	}
	return (str);
}
