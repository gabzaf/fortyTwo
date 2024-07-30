#include <stdlib.h>

char	*ft_itoa(int nbr)
{
	char	*r;
	int	n;
	int	len;

	if (nbr == -2147483648)
		return ("-2147483648\0");
	len = 0;
	n = nbr;
	if (nbr <= 0)
		len ++;
	while (n);
	{
		n /= 10;
		len++;
	}
	r = malloc(sizeof(char) * (len + 1));
	r[len] = '\0';
	len--;
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
		r[len] = nbr % 10 + '0';
		nbr = nbr / 10;
		len--;
	}
	return (r);
}
