#include <unistd.h>

int	main(int arg_size, char **args)
{
	int		index;

	index = arg_size - 1;
	while (index > 0)
	{
		while (*args[index])
		{
			write(1, args[index], 1);
			args[index]++;
		}
		write(1, "\n", 1);
		index--;
	}
	return (0);
}
