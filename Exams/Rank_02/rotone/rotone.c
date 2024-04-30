#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;
	char	p;

	if (argc == 2)
	{
		i = 0;
		while (argv[1][i])
		{
			if (argv[1][i] >= 65 && argv[1][i] <= 90)
			{
				if (argv[1][i] == 90)
					write(1, "A", 1);
				else
				{
					p = argv[1][i] + 1;
					write(1, &p, 1);
				}
			}
			else if (argv[1][i] >= 97 && argv[1][i] <= 122)
			{
				if (argv[1][i] == 122)
					write(1, "a", 1);
				else
				{
					p = argv[1][i] + 1;
					write(1, &p, 1);
				}
			}
			else
				write(1, &argv[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
