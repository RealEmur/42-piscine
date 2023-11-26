#include <unistd.h>

char	gethexvalue(int num)
{
	if (num <= 9)
		return ('0' + num);
	else if (num == 10)
		return ('a');
	else if (num == 11)
		return ('b');
	else if (num == 12)
		return ('c');
	else if (num == 13)
		return ('d');
	else if (num == 14)
		return ('e');
	else if (num == 15)
		return ('f');
	else
		return ('\0');
}

void	format_and_print(char *addr)
{
	int		i;

	i = 0;
	while (addr[i] && i < 16)
	{
		if (addr[i] >= 32 && addr[i] <= 126)
			write(1, addr + i, 1);
		else
			write(1, ".", 1);
		i++;
	}
	while (i < 16)
	{
		write(1, " ", 1);
		i++;
	}
}

void	print_hexidecimals(unsigned char *addr)
{
	int		i;
	char	hex[3];
	int		keepwriting;

	i = 0;
	keepwriting = 1;
	while (i <= 15)
	{
		hex[0] = ' ';
		hex[1] = ' ';
		if (addr[i] && keepwriting)
		{
			hex[1] = gethexvalue(addr[i] % 16);
			hex[0] = gethexvalue(addr[i] / 16);
		}
		else
			keepwriting = 0;
		write(1, hex, 2);
		if (i % 2)
			write(1, " ", 1);
		i++;
	}
}

void	print_address(void *addr)
{
	char				addr_str[18];
	unsigned long long	ptr_value;
	int					i;

	addr_str[16] = ':';
	ptr_value = (unsigned long long) addr;
	i = 16;
	while (i >= 0)
	{
		addr_str[i - 1] = gethexvalue(ptr_value % 16);
		ptr_value /= 16;
		i--;
	}
	write(1, addr_str, 17);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	while (size > 0)
	{
		print_address(addr);
		write(1, " ", 1);
		print_hexidecimals((unsigned char *) addr);
		format_and_print((char *) addr);
		write(1, "\n", 1);
		if (size > 16)
		{
			size -= 16;
			addr += 16;
		}
		else
			size = 0;
	}
	return (addr);
}
