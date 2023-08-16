/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memoryLeak.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 08:10:28 by gamado-x          #+#    #+#             */
/*   Updated: 2023/07/27 09:52:03 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int	ARR_SIZE = 1000;

int main	(void)
{
	int	*intArray = malloc(sizeof(int) * ARR_SIZE);
	int	i;
	int	randNum;

	i = 0;
	while (i < ARR_SIZE)
	{
		intArray[i] = i;
		i++;
	}
	srand(time(NULL));
	randNum = rand() % ARR_SIZE;
	printf("intArray[%d]: %d\n", randNum, intArray[randNum]);
	free(intArray);
	return (0);
}
