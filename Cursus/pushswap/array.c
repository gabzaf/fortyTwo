
#include "ps_lib.h"

void	bubble_sort(int **array, int argc)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	temp = 0;
	while (i < (argc - 1))
	{
		j = i + 1;
		while (j < (argc - 1))
		{
			if ((*array)[i] > (*array)[j])
			{
				temp = (*array)[i];
				(*array)[i] = (*array)[j];
				(*array)[j] = temp;
				j = i;
			}
			j++;
		}
		i++;
	}
}

int	*array_insertion(int argc, char **argv)
{
	int	i;
	int	j;
	int	paramc;
	int	*array;

	i = 0;
	j = 1;
	paramc = argc;
	array = malloc(sizeof(int) * (argc - 1));
	if (!array)
		return (NULL);
	while (argc > 1)
	{
		array[i] = ft_atoi(argv[j]);
		i++;
		j++;
		argc--;
	}
	bubble_sort(&array, paramc);
	return (array);
}
