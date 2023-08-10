/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 13:23:35 by gamado-x          #+#    #+#             */
/*   Updated: 2023/05/21 15:43:15 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_create_string(unsigned int magnitudeorder)
{
	char	*string;

	string = (char *)malloc((magnitudeorder + 1) * sizeof(char));
	if (!string)
		return (NULL);
	string[magnitudeorder] = 0;
	return (string);
}

static int	ft_order_of_magnitude(int n)
{
	int	om;

	om = 0;
	if (n <= 0)
		om++;
	while (n != 0)
	{
		n = n / 10;
		om++;
	}
	return (om);
}

char	*ft_itoa(int n)
{
	unsigned int	magnitudeorder;
	long			temp;
	char			*ptr;

	magnitudeorder = ft_order_of_magnitude(n);
	ptr = ft_create_string(magnitudeorder);
	temp = n;
	if (!ptr)
		return (NULL);
	if (temp < 0)
	{
		ptr[0] = '-';
		temp *= -1;
	}
	if (temp == 0)
		ptr[0] = '0';
	magnitudeorder--;
	while (temp != 0)
	{
		ptr[magnitudeorder] = (temp % 10) + '0';
		temp = temp / 10;
		magnitudeorder--;
	}
	return (ptr);
}
