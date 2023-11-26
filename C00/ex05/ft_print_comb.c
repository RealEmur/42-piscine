#include <unistd.h>

void	ft_print_comb(void)
{
	char	nums[4];
	int		firstnum;

	firstnum = 1;
	nums[0] = '0';
	while (nums[0] <= '9')
	{
		nums[1] = nums[0] + 1;
		while (nums[1] <= '9')
		{
			nums[2] = nums[1] + 1;
			while (nums[2] <= '9')
			{
				if (!firstnum)
					write(1, ", ", 2);
				else
					firstnum = 0;
				write(1, nums, 3);
				nums[2]++;
			}
			nums[1]++;
		}
		nums[0]++;
	}
}
