#include <unistd.h>

void	write_word(char *start, char *end)
{
	while (start < end)
	{
		write(1, start, 1);
		start++;
	}
}

void	rostring(char *str)
{
	int	i = 0;
	char	*temp;
	char	*frst_w_start;
	char	*frst_w_end;

	temp = str;
	while (temp[i] == ' ' || temp[i] == '\t')
	       i++;
	frst_w_start = &temp[i];
	while (temp[i] && temp[i] != ' ' && temp[i] != '\t')
		i++;
	frst_w_end = &temp[i];
	while (temp[i] == ' ' || temp[i] == '\t')
		i++;	
	if (temp[i])
	{
		while (temp[i])
		{
			if (temp[i] == ' ' || temp[i] == '\t')
			{
				while (temp[i] == ' ' || temp[i] == '\t')
					i++;
				if (temp[i])
					write (1, " ", 1);
			}
			else
			{
				write(1, &temp[i], 1);
				i++;
			}
		}
		write(1, " ", 1);
	}
	write_word(frst_w_start, frst_w_end);			
}

int	main(int ac, char **av)
{
	if (ac > 1)
		rostring(av[1]);
	write (1, "\n", 1);
	return (0);
}
