/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitwise_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <gamado-x@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 15:29:57 by gamado-x          #+#    #+#             */
/*   Updated: 2023/10/17 15:50:57 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	main(void)
{
	int	a;
	int	b;

	a = 100000;
	/*printf("Left shifted by 1: %d\n", a << 1);
	printf("Left shifted by 2: %d\n", a << 2);
	printf("Left shifted by 3: %d\n", a << 3);
	printf("Left shifted by 4: %d\n", a << 4);*/
	
	b = 0;
	while (b < 32)
	{
		printf("Left shifted by %02d: %08x | %d\n", b, a << b, a << b);
		b++;
	}
	return (0);
}
