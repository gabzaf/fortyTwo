#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;
	char	c;

	if (argc == 2)
	{
		i = 0;
		while (argv[1][i])
		{
			if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
			{
				if (argv[1][i] == 'Z')
					c = 'A';
				else
					c = argv[1][i] + 1;
				write(1, &c, 1);
			}
			else if (argv[1][i] >= 'a' && argv[1][i] <= 'z')
			{
				if (argv[1][i] == 'z')
					c = 'a';
				else
					c = argv[1][i] + 1;
				write(1, &c, 1);
			}
			else
				write(1, &argv[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
