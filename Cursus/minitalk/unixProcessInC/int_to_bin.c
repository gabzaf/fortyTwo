/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_to_bin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <gamado-x@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 10:20:03 by gamado-x          #+#    #+#             */
/*   Updated: 2023/10/17 10:25:18 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	intToBin(nbr)
{
	if (nbr == 0)
		return (0);
	if (nbr == 1)
		return (1);
	return (nbr % 2) + 10 * intToBin(nbr / 2);
}

int	main(void)
{
	int	nbr;

	nbr = 100;
	printf("%d\n", intToBin(nbr));
	return (0);
}
