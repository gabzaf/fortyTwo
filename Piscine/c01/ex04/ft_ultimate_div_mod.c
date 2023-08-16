/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 13:25:18 by gamado-x          #+#    #+#             */
/*   Updated: 2023/03/19 13:31:42 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>
#include <stdlib.h>*/

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	div;
	int	mod;

	div = *a / *b;
	mod = *a % *b;
	*a = div;
	*b = mod;
}

/*int	main(void)
{
	int	*a;
	int	*b;

	a = (int *)calloc(1, sizeof(int));
	b = (int *)calloc(1, sizeof(int));
	*a = 42;
	*b = 10;
	printf("%d %d", *a, *b);
	ft_ultimate_div_mod(a, b);
	printf("%d %d", *a, *b);
	free(a);
	free(b);
	return (0);
}*/
