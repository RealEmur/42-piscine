#include <unistd.h>

void	printnum(int num)
{
	char	nums[3];
	int		firstdigit;

	firstdigit = num / 10;
	if (firstdigit > 0)
		nums[0] = firstdigit + '0';
	else
		nums[0] = '0';
	nums[1] = (num % 10) + '0';
	write(1, nums, 2);
}

void	ft_print_comb2(void)
{
	int		isfirstnums;
	int		num;
	int		secondnum;

	isfirstnums = 1;
	num = 0;
	while (num < 100)
	{
		secondnum = num + 1;
		while (secondnum < 100)
		{
			if (!isfirstnums)
				write(1, ", ", 2);
			else
				isfirstnums = 0;
			printnum(num);
			write(1, " ", 1);
			printnum(secondnum);
			secondnum++;
		}
		num++;
	}
}
