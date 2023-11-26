unsigned int	ft_strlen(char *arr)
{
	unsigned int	length;

	length = 0;
	while (arr[length])
		length++;
	return (length);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	dest_size;
	unsigned int	index;

	dest_size = ft_strlen(dest);
	if (size <= dest_size)
		return (size + ft_strlen(src));
	index = 0;
	while (src[index] && dest_size + index + 1 < size)
	{
		dest[dest_size + index] = src[index];
		index++;
	}
	dest[dest_size + index] = '\0';
	return (dest_size + ft_strlen(src));
}
