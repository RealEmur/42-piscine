#include <stdlib.h>

int		ft_atoi_base(char *str, char *base);
char	*trim_nbr_str(char *str, int *sign);
int		ft_find_index(char *str, char target);
int		is_valid_base(char *base);
int		ft_strlen(char *str);

int	get_digit_count(int nbr, int base_num)
{
	int		digits;
	long	num;

	num = nbr;
	digits = 1;
	if (num < 0)
	{
		digits++;
		num *= -1;
	}
	while (num / base_num > 0)
	{
		num /= base_num;
		digits++;
	}
	return (digits);
}

void	ft_putnbr_base(int nbr, char *base, char *str)
{
	int		base_num;
	int		digit_index;
	long	num;

	if (!is_valid_base(base))
		return ;
	num = (long) nbr;
	if (num < 0)
	{
		str[0] = '-';
		num *= -1;
	}
	base_num = ft_strlen(base);
	digit_index = get_digit_count(nbr, ft_strlen(base)) - 1;
	while (num >= 0)
	{
		str[digit_index] = base[num % base_num];
		num /= base_num;
		digit_index--;
		if (num == 0)
			break ;
	}
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		num;
	char	*str;
	int		str_size;

	if (!is_valid_base(base_from) || !is_valid_base(base_to))
		return (0);
	num = ft_atoi_base(nbr, base_from);
	str_size = get_digit_count(num, ft_strlen(base_to));
	str = (char *) malloc(sizeof(char) * (str_size + 1));
	str[str_size] = '\0';
	ft_putnbr_base(num, base_to, str);
	return (str);
}
