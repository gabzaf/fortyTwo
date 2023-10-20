/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <gamado-x@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 10:12:32 by gamado-x          #+#    #+#             */
/*   Updated: 2023/10/20 11:10:57 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	printBinary(unsigned char num)
{
	int	bits[8];
	int	i;

	i = 7;
	while (i >= 0)
	{
		printf("%d", (num >> i) & 1);
		i--;
	}
	printf("\n");
}

unsigned char reverseBits(unsigned char byte)
{
	unsigned char reversedByte;
	int	i;

	reversedByte = 0;
	i = 0;
	while (i < 8)
	{
		reversedByte =(reversedByte << 1) | ((byte >> i) & 1);
		i++;
	}
	return (reversedByte);
}

int	main(void)
{
	unsigned char	originalByte;
	unsigned char	reversedByte;

	originalByte = 0b10000110;
	reversedByte = reverseBits(originalByte);
	printf("Original byte in binary: ");
	printBinary(originalByte);
	printf("Original byte: 0x%02X\n", originalByte);
	printf("Reversed byte in binary: ");
	printBinary(reversedByte);
	printf("Reversed byte: 0x%02X\n", reversedByte);	
	return (0);
}
