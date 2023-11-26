unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	srcsize;

	srcsize = 0;
	while (src[srcsize])
		srcsize++;
	i = 0;
	while (src[i] && i + 1 < size)
	{
		*(dest + i) = src[i];
		i++;
	}
	if (size != 0)
		*(dest + i) = '\0';
	return (srcsize);
}
