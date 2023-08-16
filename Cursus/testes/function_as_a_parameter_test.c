/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_as_a_parameter_test.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 12:15:11 by gamado-x          #+#    #+#             */
/*   Updated: 2023/05/09 12:25:05 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	double_num(int num)
{
	return (num * 2);
}

int	square_num(int num)
{
	return (num * num);
}

int	divide_by_two(int num)
{
	return (num / 2);
}

int	apply_calculation(int num, int (*f)(int))
{
	return (*f)(num);
}

int	main(void)
{
	int	num;

	num = 6;
	printf("Double result: %d\n", apply_calculation(num, double_num));
	printf("Square result: %d\n", apply_calculation(num, square_num));
	printf("Divide by two: %d\n", apply_calculation(num, divide_by_two));
	return (0);
}
