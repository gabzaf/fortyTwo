
#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
	/*printf("%d\n", *a);
	printf("%d\n", *b);*/
}

/*int	main()
{
	int	a;
	int	b;

	a = 1;
	b = 9;
	ft_swap(&a, &b);
	return (0);
}*/
