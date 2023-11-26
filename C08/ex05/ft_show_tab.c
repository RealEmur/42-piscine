#include <unistd.h>
#include "ft_stock_str.h"

void	ft_putchr(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		ft_putchr(*str);
		str++;
	}
}

void	ft_putnbr(int nb)
{
	long	nbr;
	int		divider;

	nbr = nb;
	divider = 1;
	if (nbr < 0)
		nbr *= -1;
	while (nbr / divider >= 10)
		divider *= 10;
	while (divider >= 1)
	{
		ft_putchr((nbr / divider) + '0');
		nbr = nbr % divider;
		divider /= 10;
	}
}

void	ft_show_tab(struct s_stock_str *par)
{
	int		index;

	index = 0;
	while (par[index].str != 0)
	{
		ft_putstr(par[index].str);
		ft_putchr('\n');
		ft_putnbr(par[index].size);
		ft_putchr('\n');
		ft_putstr(par[index].copy);
		ft_putchr('\n');
		index++;
	}
}
