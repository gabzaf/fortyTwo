/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 09:36:49 by gamado-x          #+#    #+#             */
/*   Updated: 2024/04/25 19:18:45 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_lib.h"

void	ft_putchar_ft_printf(const char c, int *count)
{
	write (1, &c, 1);
	(*count)++;
}

void	ft_putstr_ft_printf(const char *s, int *count)
{
	int	i;

	i = 0;
	if (!s)
	{
		ft_putstr_ft_printf("(null)", count);
		return ;
	}
	while (s[i])
	{
		ft_putchar_ft_printf(s[i], count);
		i++;
	}
}

void	ft_putnbr_ft_printf(int nbr, int *count)
{
	long	number;

	number = (long)nbr;
	if (number < 0)
	{
		number *= -1;
		ft_putchar_ft_printf('-', count);
	}
	if (number < 10)
		ft_putchar_ft_printf((number + '0'), count);
	if (number >= 10)
	{
		ft_putnbr_ft_printf(number / 10, count);
		ft_putnbr_ft_printf(number % 10, count);
	}
}

void	ft_baseputnbr_ft_printf(unsigned int nbr, char *base, int *count)
{
	long	number;
	int		length;

	length = ft_strlen(base);
	if (length < 2)
		return ;
	number = nbr;
	if (number < 0)
	{
		number *= -1;
		ft_putchar_ft_printf('-', count);
	}
	if (number < length)
		ft_putchar_ft_printf(base[number], count);
	if (number >= length)
	{
		ft_baseputnbr_ft_printf(number / length, base, count);
		ft_baseputnbr_ft_printf(number % length, base, count);
	}
}
