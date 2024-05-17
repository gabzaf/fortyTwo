

#include "ps_lib.h"

long	ft_atol(const char *nptr)
{
	long	i;
	long	result;
	long	isneg;

	i = 0;
	isneg = 1;
	result = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			isneg = -1;
		i++;
	}
	while (nptr[i] > 47 && nptr[i] < 58)
	{
		result = (result * 10) + (nptr[i] - '0');
		i++;
	}
	return (result * isneg);
}
