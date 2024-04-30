//#include <stdio.h>

int	max(int* tab, unsigned int len)
{
	int	max;

	max = 0;
	if (len == 0)
		return (0);
	while (*tab)
	{
		if (*tab > max)
			max = *tab;
		tab++;
	}
	return (max);
}

/*int	main()
{
	int	array[] = {1, 2, 5, 9, 67, 65, 3};
	printf("%d\n", max(array, 7));
	return (0);
}*/
