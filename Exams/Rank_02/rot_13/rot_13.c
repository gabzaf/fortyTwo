#include <unistd.h>

int	main (int ac, char ** av)
{
	int	i;
	char	c;

	if (ac == 2)
	{
		i = 0;
		while (av[1][i])
		{
			if (av[1][i] >= 'A' && av[1][i] <= 'Z')
			{
				if (av[1][i] <= 'M')
					c = av[1][i] + 13;
				else
					c = av[1][i] - 13;
				write (1, &c, 1);
			}
			else if (av[1][i] >= 'a' && av[1][i] <= 'z')
			{
				if (av[1][i] <= 'm')
					c = av[1][i] + 13;
				else
					c = av[1][i] - 13;
				write (1, &c, 1);
			}
			else
				write (1, &av[1][i], 1);
			i++;
		}
	}
	write (1, "\n", 1);
	return (0);
}
