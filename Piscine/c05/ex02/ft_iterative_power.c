/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 12:27:43 by gamado-x          #+#    #+#             */
/*   Updated: 2023/03/29 11:16:05 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_iterative_power(int nb, int power)
{
	int	powered_number;

	powered_number = nb;
	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	else if (power == 1)
		return (nb);
	while (power > 1)
	{
		powered_number *= nb;
		power--;
	}
	return (powered_number);
}

/*int	main(void)
{
	printf("%d", ft_iterative_power(10, 3));
	return (0);
}*/
