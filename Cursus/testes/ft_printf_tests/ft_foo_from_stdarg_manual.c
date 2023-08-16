/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foo_from_stdarg_manual.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 15:58:33 by gamado-x          #+#    #+#             */
/*   Updated: 2023/08/10 19:50:03 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>

void	foo(char *format, ...)
{
	va_list	ap;
	int	d;
	char	c;
	char	*s;

	va_start(ap, format);
	while (*format)
	{
		switch (*format++)
		{
			case 's':
				s = va_arg(ap, char *);
				printf("string %s\n", s);
				break;
			case 'd':
				d = va_arg(ap, int);
				printf("int %d\n", d);
				break;
			case 'c':
				c = (char) va_arg(ap, int);
				printf("char %c");
		}
	}
}
