/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 08:45:47 by gamado-x          #+#    #+#             */
/*   Updated: 2023/03/21 10:03:32 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	int	*src;
	int	i;
	int	a, b, c, d;

	i = 0;
	src = calloc(8, sizeof(int*));
	if (src == NULL)
	{
		printf("Memory not allocated. Error.");
		exit(0);
	}
	a = 0;
	src[0] = a;
	b = 1;
	src[1] = b;
	c = 2;
	src[2] = c;
	d = 3;
	src[3] = d;
	src[4] = 4;
	src[5] = 5;
	src[6] = 6;
	src[7] = 7;
	while (i <= 7)
	{
		if (i == 0)
			printf("var_A_value: %d var_A_address: %p ", a, &a);
		else if (i == 1)
			printf("var_B_value: %d var_B_address: %p ", b, &b);
		else if (i == 2)
			printf("var_C_value: %d var_C_address: %p ", c, &c);
		else if (i == 3)
			printf("var_D_value: %d var_D_address: %p ", d, &d);
		printf("array_value: %d array_element_address: %p\n", src[i], &src[i]);
		i++;
	}
	free(src);
	return (0);
}
