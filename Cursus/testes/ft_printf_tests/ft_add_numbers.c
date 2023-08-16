/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_numbers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 15:34:30 by gamado-x          #+#    #+#             */
/*   Updated: 2023/08/07 16:14:45 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>

int	AddNumbers(int n, ...)
{
	int	sum = 0;
	va_list	ptr;

	va_start(ptr, n);
	for (int i = 0; i < n; i++)
		sum += va_arg(ptr, int);
	va_end(ptr);
	return sum;	
}

int	main()
{
	printf("\n\n Variadic functions: \n");
	printf("\n 1 + 2 = %d", AddNumbers(2, 1, 2));
	printf("\n 3 + 4 + 5 = %d", AddNumbers(3, 3, 4, 5));
	printf("\n 6 + 7 + 8 + 9 = %d", AddNumbers(4, 6, 7, 8, 9));
	printf("\n");
	return (0);
}
