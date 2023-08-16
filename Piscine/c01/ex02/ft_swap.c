/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 12:38:48 by gamado-x          #+#    #+#             */
/*   Updated: 2023/03/19 13:12:00 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>
#include <stdlib.h>*/

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/*int	main(void)
{
	int	*a;
	int	*b;

	a = (int *)calloc(1, sizeof(int));
	b = (int *)calloc(1, sizeof(int));
	*a = 42;
	*b = 24;
	printf("%d %d\n", *a, *b);
	ft_swap(a, b);
	printf("%d %d\n", *a, *b);
	return (0);
}*/
