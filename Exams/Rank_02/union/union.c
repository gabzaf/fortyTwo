#include <unistd.h>

int	has_char(char *str, char c)
{
	int	i = 0;

	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	union_str(char *str1, char *str2)
{
	char	seen[256] = {0};
	int	i = 0;
	int	j = 0;

	while (str1[i])
	{
		j = 0;
		if (!has_char(seen, str1[i]))
		{
			seen[j] = str1[i];
			write (1, &str1[i], 1);
			j++;
		}
		i++;
	}
	i = 0;
	while (str2[i])
	{
		if (!has_char(seen, str2[i]))
		{
			seen[j] = str2[i];
			write (1, &str2[i], 1);
			j++;
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 3)
		union_str(av[1], av[2]);
	write (1, "\n", 1);
	return (0);
}
