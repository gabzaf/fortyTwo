/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 10:30:22 by gamado-x          #+#    #+#             */
/*   Updated: 2023/09/17 12:28:59 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_verify_format(va_list args, char *str, int i, int *count)
{
	char	*dec;
	char	*low_hex;
	char	*hig_hex;

	dec = "0123456789";
	low_hex = "0123456789abcdef";
	hig_hex = "0123456789ABCDEF";
	if (str[i] == 'c')
		ft_putchar_ft_printf(va_arg(args, int), count);
	else if (str[i] == 's')
		ft_putstr_ft_printf(va_arg(args, char *), count);
	else if (str[i] == 'p')
		ft_pointer_printer(va_arg(args, unsigned long), low_hex, count);
	else if (str[i] == 'd' || str [i] == 'i')
		ft_putnbr_ft_printf(va_arg(args, int), count);
	else if (str[i] == 'u')
		ft_baseputnbr_ft_printf(va_arg(args, unsigned int), dec, count);
	else if (str[i] == 'x')
		ft_baseputnbr_ft_printf(va_arg(args, unsigned int), low_hex, count);
	else if (str[i] == 'X')
		ft_baseputnbr_ft_printf(va_arg(args, unsigned int), hig_hex, count);
	else if (str[i] == '%')
		ft_putchar_ft_printf('%', count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	char	*str;
	int		i;
	int		count;

	str = (char *)format;
	i = 0;
	count = 0;
	va_start(args, format);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			ft_verify_format(args, str, i, &count);
		}
		else
			ft_putchar_ft_printf(str[i], &count);
		i++;
	}
	va_end(args);
	return (count);
}

/*int	main (void)
{
	int	c;

	c = ft_printf("%s %c", "ola", 'o');
	printf("\n%d", c);
	return (0);
}*/
