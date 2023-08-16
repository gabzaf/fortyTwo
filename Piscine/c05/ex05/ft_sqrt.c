/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 19:09:25 by gamado-x          #+#    #+#             */
/*   Updated: 2023/03/30 11:29:17 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_sqrt_recursive(int nb, int i)
{
	if (i > 46340)
		return (0);
	if (i * i < nb)
		return (ft_sqrt_recursive(nb, i + 1));
	if (i * i == nb)
		return (i);
	return (0);
}

int	ft_sqrt(int nb)
{
	if (nb < 0)
		return (0);
	return (ft_sqrt_recursive(nb, 0));
}

/*int	main(void)
{
	printf("%d", ft_sqrt(2147395600));
	return (0);
}*/
