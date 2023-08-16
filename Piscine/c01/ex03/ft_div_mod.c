/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 13:12:46 by gamado-x          #+#    #+#             */
/*   Updated: 2023/03/19 13:23:36 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>
#include <stdlib.h>*/

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}

/*int	main(void)
{
	int	a;
	int	b;
	int	*div;
	int	*mod;

	a = 42;
	b = 10;
	div = (int *)calloc(1, sizeof(int));
	mod = (int *)calloc(1, sizeof(int));
	ft_div_mod(a, b, div, mod);
	printf("%d, %d, %d, %d", a, b, *div, *mod);
	return (0);
}*/
