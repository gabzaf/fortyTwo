#include <stdlib.h>

int	ft_range(int start, int end)
{
	int	i;
	int	len;
	int	*array;

	len = abs(end - start) + 1;
	array = (int *)malloc(sizeof(int) * len);
	i = 0;
	while (i < len)
	{
		if (start < end)
		{
			array[i] = start;
			start++;
			i++;
		}
		else
		{
			array[i] = start;
			start--;
			i++;
		}
	}
	return (array);
}
