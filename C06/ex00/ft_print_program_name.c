#include <unistd.h>

int	main(int arg_size, char **args)
{
	if (arg_size != 0)
	{
		while (*args[0])
		{
			write(1, *args, 1);
			args[0]++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
