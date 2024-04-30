#include <unistd.h>

void	ft_putnbr(int n)
{
	if (n >= 10)
		ft_putnbr(n / 10);
	char	to_print = n % 10 + '0';
	write(1, &to_print, 1);
}

int	is_prime(int n)
{
	int	i;

	i = 2;
	if (n <= 1)
		return (0);
	while (i * i <= n)
	{
		if (n % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_atoi(char *argv)
{
	int	r;

	r = 0;
	while (*argv)
		r = r * 10 + *argv++ - 48;
	return (r);
}

int	main(int argc, char **argv)
{
	int	nbr;
	int	s;

	if (argc == 2)
	{
		nbr = ft_atoi(argv[1]);
		s = 0;
		while (nbr > 0)
		{
			if (is_prime(nbr))
				s += nbr;
			nbr--;
		}
		ft_putnbr(s);
	}
	if (argc != 2 || argv[1][0] == '-')
		write(1, "0", 1);
	write(1, "\n", 1);
	return (0);
}
