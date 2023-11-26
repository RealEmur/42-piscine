#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		ft_putchar(*str);
		str++;
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	if (!(*s1 || *s2))
		return (0);
	else
		return (*s1 - *s2);
}

int	main(int arg_size, char **args)
{
	int		index;
	int		j;
	char	*temp;

	index = 1;
	while (index < arg_size)
	{
		j = index + 1;
		while (j < arg_size)
		{
			if (ft_strcmp(args[index], args[j]) > 0)
			{
				temp = args[index];
				args[index] = args[j];
				args[j] = temp;
			}
			j++;
		}
		ft_putstr(args[index]);
		ft_putchar('\n');
		index++;
	}
	return (0);
}
