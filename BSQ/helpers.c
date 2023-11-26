#include <unistd.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int		length;

	length = 0;
	while (str[length])
		length++;
	return (length);
}

char	*ft_strcpy(char *dest, char *src)
{
	int		index;

	index = 0;
	while (src[index])
	{
		dest[index] = src[index];
		index++;
	}
	dest[index] = '\0';
	return (dest);
}

char	*ft_realloc(char *str, int *size, int newsize)
{
	char	*new_str;

	new_str = (char *) malloc(sizeof(char) * newsize);
	*size = newsize;
	ft_strcpy(new_str, str);
	free(str);
	return (new_str);
}

int	ft_simple_atoi(char *str)
{
	int		num;

	num = 0;
	while (*str && *str >= '0' && *str <= '9')
	{
		if (!(*str >= '0' && *str <= '9'))
			return (-1);
		num *= 10;
		num += (*str - '0');
		str++;
	}
	return (num);
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}
