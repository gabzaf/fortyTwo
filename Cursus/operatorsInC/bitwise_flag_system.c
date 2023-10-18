/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitwise_flag_system.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <gamado-x@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 07:42:10 by gamado-x          #+#    #+#             */
/*   Updated: 2023/10/18 09:26:11 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	main(void)
{
	//00000000 00000000 00000000 00000000
	unsigned int	flag_one; //4 bytes => 32 bits
	unsigned int	flag_two;
	//what if i want to select a feature that is located on 1st, 2nd and 8th digit, right to left
	//00000000 00000000 00000000 10000011
	unsigned int	flag_three;
	//int	x; 4 bytes of memory
	//int	y; 4 bytes of memory

	flag_one = 1; //binary 01
	flag_two = 2; //binary 10
	//flag_three = 128; //but I dont want to do calculations
	flag_three = 1 | 0b10 | 0b10000000;
	//It is better to do bitwise OR 
	//x = 1;
	//y = 0;
	//the if statement below make logical AND with two numbers below:
	//00000000 00000000 00000000 00000001
	//00000000 00000000 00000000 00000001
	/*if ((flag_one & 1) != 0)
		printf("1st feature is enabled\n");*/
	//00000000 00000000 00000000 00000010
	//00000000 00000000 00000000 00000001
	/*if ((flag_two & 1) != 0)
		printf("2nd feature is enabled\n");*/
	if ((flag_three & 0b1) != 0)
		printf("1st feature is enabled\n");
	if ((flag_three & 0b10) != 0)
		printf("2nd feature is enabled\n");
	if ((flag_three & 0b10000000) != 0)
		printf("8th feature is enabled\n");
	/*if (x == 1)
		printf("1st feature is enabled\n");
	if (y == 1)
		printf("2nd feature is enabled\n");*/

	return (0);
}
