#include <unistd.h>

int	ft_strlen(char *str)
{
	int		lenght;

	lenght = 0;
	while (str[lenght])
		lenght++;
	return (lenght);
}

int	is_valid_base(char *base)
{
	int		index;

	if (ft_strlen(base) <= 1)
		return (0);
	while (*base)
	{
		if (!(*base >= 32 && *base < 127) || (*base == '-' || *base == '+'))
			return (0);
		index = 1;
		while (base[index])
		{
			if (*base == base[index])
				return (0);
			index++;
		}
		base++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	char	nums[32];
	int		base_num;
	int		digit_index;
	long	num;

	if (!is_valid_base(base))
		return ;
	num = (long) nbr;
	if (num < 0)
	{
		num *= -1;
		write(1, "-", 1);
	}
	base_num = ft_strlen(base);
	digit_index = 31;
	while (num >= 0)
	{
		nums[digit_index] = base[num % base_num];
		num /= base_num;
		digit_index--;
		if (num == 0)
			break ;
	}
	write(1, nums + digit_index + 1, (32 - digit_index - 1));
}
