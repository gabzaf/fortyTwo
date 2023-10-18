/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switch_stat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <gamado-x@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:43:17 by gamado-x          #+#    #+#             */
/*   Updated: 2023/10/17 14:48:19 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	main(void)
{
	int	fruit;

	fruit = -1;
	printf("Whats ur fav fruit?\n");
	scanf("%d", &fruit);
	switch (fruit)
	{
		case 0:
			printf("U selected apples\n");
			break;
		case 1:
			printf("U selected lemons\n");
			break;
		case 2:
			printf("U selected oranges\n");
			break;
		default:
			printf("No such fruit\n");
			break;
	}
	return (0);
}
