#include <unistd.h>

void	ft_putstr(char *str);
int		handle_map(char *file_path);
int		validate_map(char *str);

int	main(int size, char **args)
{
	int		index;
	char	buffer[4096];

	if (size == 1)
	{
		write(0, "Lütfen dosya adını giriniz.\nDosya: ", 39);
		buffer[read(0, buffer, sizeof(buffer)) - 1] = '\0';
		if (!handle_map(buffer))
			write(2, "map error\n", 11);
	}
	else
	{
		index = 1;
		while (index < size)
		{
			if (!validate_map(args[index]) || !handle_map(args[index]))
				write(2, "map error\n", 11);
			if (index != size - 1)
				ft_putstr("\n");
			index++;
		}
	}
	return (0);
}
