

#include "ps_lib.h"

int	ft_o_strlen(char **av)
{
	int	i;

	i = 0;
	while (av[1][i] != '\0')
		i++;
	return (i);
}

long long int	ft_o_atoi(const char *str)
{
	long long int	result;
	int	isneg;

	isneg = 1;
	result = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			isneg = -1;
		str++;
	}
	while (*str > 47 && *str < 58)
		result = (result * 10) + (*(str++) - '0');
	return (result * isneg);
}

int	validation(char **argv)
{
	int	i;
	int	len;

	i = 0;
	if ((ft_o_atoi(argv[1]) > 2147483647) || (ft_o_atoi(argv[1]) < -2147483648))
	{
		write (2, "Error\n", 6);
		return (1);
	}
	len = ft_o_strlen(argv);
	if ((argv[1][0] == '-' || argv[1][0] == '+') && len > 1)
		i = 1;
	while (i < len)
	{
		if (!(argv[1][i] > 47 && argv[1][i] < 58))
		{
			write(2, "Error\n", 6);
			return (1);
		}
		i++;
	}

	return (0);
}
