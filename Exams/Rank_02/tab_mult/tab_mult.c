#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nbr)
{
	if (nbr == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		nbr = nbr % 1000000000 * -1;
	}
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr = nbr * -1;
	}
	if (nbr / 10 > 0)
		ft_putnbr(nbr / 10);
	ft_putchar(nbr % 10 + '0');
}

int	ft_atoi(char *str)
{
	int	r;
	int	minus;

	r = 0;
	minus = 1;
	while (*str == ' ')
		str++;
	if (*str == '-')
	{
		minus = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		r = r * 10 + *str - '0';
		str++;
	}
	return (minus * r);
}

int	main(int argc, char **argv)
{
	int	i;
	int	nbr;

	i = 1;
	if (argc == 2)
	{
		nbr = ft_atoi(argv[1]);
		while (i < 10)
		{
			ft_putnbr(i);
			write(1, " x ", 3);
			ft_putnbr(nbr);
			write(1, " = ", 3);
			ft_putnbr(i * nbr);	
			write(1, "\n", 1);	
			i++;
		}
	}
	else
		write(1, "\n", 1);
	return (0);
}
