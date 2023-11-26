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

void	printhexformat(unsigned char value)
{
	char	str[4];

	str[0] = '\\';
	str[1] = gethexvalue(value / 16);
	str[2] = gethexvalue(value % 16);
	write(1, str, 3);
}

void	ft_putstr_non_printable(char *str)
{
	unsigned int	i;

	i = 0;
	while (*(str + i))
	{
		if (!(*(str + i) >= 32 && *(str + i) != 127))
			printhexformat((unsigned char) *(str + i));
		else
			write(1, str + i, 1);
		i++;
	}
}
