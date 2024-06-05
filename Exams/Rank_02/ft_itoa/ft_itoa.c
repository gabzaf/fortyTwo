#include <stdlib.h>

char	*ft_itoa(int nbr)
{
	if (nbr == -2147483648)
		return ("-2147483648");
	int	n = nbr;
	int 	len = 0;
	if (nbr <= 0)
	len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	char	*r = malloc(sizeof(char) * (len + 1));
	if (r == NULL)
		return (NULL);
	r[len] = '\0';
	if (nbr == 0)
	{
		r[0] = '0';
		return (r);
	}
	if (nbr < 0)
	{
		r[0] = '-';
		nbr = -nbr;
	}
	while (nbr)
	{
		r[--len] = nbr % 10 + '0';
		nbr = nbr / 10;
	}
	return (r);
}
