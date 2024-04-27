/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer_printer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 11:23:30 by gamado-x          #+#    #+#             */
/*   Updated: 2024/04/25 19:17:52 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_lib.h"

void	ft_pointer_printer(unsigned long ptr, char *base, int *count)
{
	if (ptr == 0)
		ft_putstr_ft_printf("(nil)", count);
	else
	{
		ft_putstr_ft_printf("0x", count);
		ft_pointer_putnbr(ptr, base, count);
	}
}

void	ft_pointer_putnbr(unsigned long ptr, char *base, int *count)
{
	if (ptr < 16)
		ft_putchar_ft_printf(base[ptr], count);
	if (ptr >= 16)
	{
		ft_pointer_putnbr((ptr / 16), base, count);
		ft_pointer_putnbr((ptr % 16), base, count);
	}
}
