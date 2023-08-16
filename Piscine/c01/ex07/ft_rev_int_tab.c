/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 14:13:43 by gamado-x          #+#    #+#             */
/*   Updated: 2023/03/19 14:42:25 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	increment_tab;
	int	decrement_tab;
	int	swap;

	increment_tab = 0;
	decrement_tab = size - 1;
	while (increment_tab < size)
	{
		swap = tab[increment_tab];
		tab[increment_tab] = tab[decrement_tab];
		increment_tab++;
		decrement_tab--;
	}
}

int	main(void)
{
	int	*tab;
	int	size;
	int	counter;

	tab = (int *)calloc(10, sizeof(int));
	size = 10;
	counter = 0;
	while (counter < 9)
	{
		tab[counter] = counter;
		counter++;
	}
	counter = 0;
	while (counter < 9)
	{
		printf("%d", tab[counter]);
		counter++;
	}
	printf("\n");
	ft_rev_int_tab(tab, size);
	counter = 0;
	while (counter < 9)
	{
		printf("%d ", tab[counter]);
		counter++;
	}
	printf("\n");
	free(tab);
	return (0);
}
