#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int		index;
	int		*arr;

	if (min >= max)
		return (0);
	arr = (int *) malloc(sizeof(int) * (max - min));
	if (!arr)
		return (0);
	index = 0;
	while (index < max - min)
	{
		arr[index] = min + index;
		index++;
	}
	return (arr);
}

int	ft_ultimate_range(int **range, int min, int max)
{
	if (min >= max)
	{
		*range = 0;
		return (0);
	}
	*range = ft_range(min, max);
	if (*range == 0)
		return (0);
	return (max - min);
}
