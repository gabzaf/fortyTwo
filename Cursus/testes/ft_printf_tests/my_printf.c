/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 17:21:00 by gamado-x          #+#    #+#             */
/*   Updated: 2023/08/09 12:12:27 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>

void	my_printf(const char *a, ...)
{
	va_list	va;

	va_start(va, a);
	vprintf(a, va);
	va_end(va);
}

int	main(void)
{
	int	x;
	float	y;

	x = 10;
	y = 3.2;
	my_printf("%d %f", x, y);
}
