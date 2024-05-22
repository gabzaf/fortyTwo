/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 13:57:35 by gamado-x          #+#    #+#             */
/*   Updated: 2024/04/25 19:17:23 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_lib.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	result;
	int	isneg;

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
