void	ft_ultimate_div_mod(int *a, int *b)
{
	int		copya;

	copya = *a;
	*a = copya / *b;
	*b = copya % *b;
}
