/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitwise_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <gamado-x@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 09:55:38 by gamado-x          #+#    #+#             */
/*   Updated: 2023/10/18 10:33:31 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ascii_printer(int c)
{
	int	bit;
	int	digit;

	bit = 0;
	digit = 1;
	while (bit < 8)
	{
		if ((c & (digit << bit)) != 0)
			printf("O char eh %c, tem valor %d e digit eh %d.\n", c, c, digit << bit);	
		bit++;
	}
}

int	main(void)
{
	char	a;

	a = 'a';
	ascii_printer(a);
	return (0);
}
