#include <unistd.h>

int	islastnum(int nums[], int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		if (nums[i] != 10 - size + i)
			return (0);
		i = i + 1;
	}
	return (1);
}

void	writeifsorted(int nums[], int size, int usecommas)
{
	char	character;
	int		i;

	i = 1;
	while (i < size)
	{
		if (nums[i] <= nums[i - 1])
			return ;
		i++;
	}
	if (usecommas)
		write(2, ", ", 2);
	i = 0;
	while (i < size)
	{
		character = nums[i] + '0';
		write(1, &character, 1);
		i++;
	}
}

void	ft_print_combn(int n)
{
	int		digits[10];
	int		i;

	i = 0;
	while (i < n)
	{
		digits[i] = i;
		i++;
	}
	writeifsorted(digits, n, 0);
	while (!islastnum(digits, n))
	{
		i = n - 1;
		digits[i]++;
		while (digits[i] == 10)
		{
			digits[i] = 0;
			i--;
			digits[i]++;
		}
		writeifsorted(digits, n, 1);
	}
}
