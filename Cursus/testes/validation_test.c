#include <stdio.h>

int	ft_strlen(char **av)
{
	int	i;

	i = 0;
	while (av[1][i] != '\0')
		i++;
	return (i);
}

void	validation(char **av)
{
	int	i;

	i = 0;
	while (i < ft_strlen(av))
	{
		printf("%c\n", av[1][i]);
		i++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
		validation(av);
	return (0);
}
