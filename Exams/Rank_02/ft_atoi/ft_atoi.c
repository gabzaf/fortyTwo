int	ft_atoi(const char *str)
{
	int	r;
	int	minus;

	r = 0;
	minus = 1;
	while (*str == ' ')
		str++;
	if (*str == '-')
		minus = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		r = r * 10 + *str - '0';
		str++;
	}
	return (minus * r);
}
