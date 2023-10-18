/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cond_operator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <gamado-x@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:23:24 by gamado-x          #+#    #+#             */
/*   Updated: 2023/10/17 14:26:53 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	main(void)
{
	int	x;
	int	y;
	int	max;

	scanf("%d", &x);
	scanf("%d", &y);
	/*if (x > y)
		max = x;
	else
		max = y;*/
	max = x > y ? x : y;
	printf("Maximum is %d\n", max);
	return (0);
}
