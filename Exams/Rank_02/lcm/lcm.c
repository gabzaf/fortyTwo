
//#include <stdio.h>

unsigned int	lcm(unsigned int a, unsigned int b)
{
	unsigned int	n;

	n = 0;
	if (a == 0 || b == 0)
		return (n);
	if (a > b)
		n = a;
	else
		n = b;
	while (1)
	{
		if (n % a == 0 && n % b == 0)
			return (n);
		++n;
	}
}

/*int	main()
{
	printf("%d\n", lcm(12, 30));
	return (0);
}*/
