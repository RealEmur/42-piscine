int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (s1[i] && s1[i] == s2[i] && i < n)
		i++;
	if (i == n || (!s1[i] && !s2[i]))
		return (0);
	else
		return (s1[i] - s2[i]);
}
