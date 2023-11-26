#include <unistd.h>

int	main(int arg_size, char **args)
{
	int		index;

	index = 1;
	while (index < arg_size)
	{
		while (*args[index])
		{
			write(1, args[index], 1);
			args[index]++;
		}
		write(1, "\n", 1);
		index++;
	}
	return (0);
}
