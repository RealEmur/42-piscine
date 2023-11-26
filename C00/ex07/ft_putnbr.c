#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	int		timesten;

	timesten = 1;
	if (nb < 0)
	{
		if (nb == -2147483648)
		{
			write(1, "-2147483648", 11);
			return ;
		}
		ft_putchar('-');
		nb *= -1;
	}
	while (nb / timesten >= 10)
		timesten *= 10;
	while (timesten >= 1)
	{
		ft_putchar('0' + (nb / timesten));
		nb = nb % timesten;
		timesten /= 10;
	}
}
