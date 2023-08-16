/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 17:49:55 by gamado-x          #+#    #+#             */
/*   Updated: 2023/03/29 18:28:27 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
//#include <stdio.h>

int	*ft_range(int min, int max)
{
	int	*arr;
	int	size;

	size = 0;
	if (min >= max)
		return (0);
	size = max - min;
	arr = malloc((size) * sizeof(int));
	size = 0;
	while (min <= max)
	{
		arr[size] = min;
		min++;
		size++;
	}
	return (arr);
}

/*int	main(void)
{
	int	*array;
	int	i;
	int	min;
	int	max;
	int	size;

	i = 0;
	min = 0;
	max = 9;
	array = ft_range(min, max);
	size = max - min;
	while (i < size)
	{
		printf("%d\n", array[i]);
		i++;
	}
	return (0);
}*/
