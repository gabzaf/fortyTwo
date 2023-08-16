/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 12:25:34 by gamado-x          #+#    #+#             */
/*   Updated: 2023/03/27 13:24:40 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	ft_putchar(char output)
{
	write(1, &output, 1);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;
	int	x;

	i = 0;
	while (str[i])
	{
		if (str[i] < 32 || str[i] >= 127)
		{
			ft_putchar('\\');
			if (str[i] < 0)
				x = 256 + str[i];
			else
				x = str[i];
			ft_putchar("0123456789abcdef"[x / 16]);
			ft_putchar("0123456789abcdef"[x % 16]);
		}
		else
			ft_putchar(str[i]);
		i++;
	}
}

int	main(void)
{
	char	str[] = {"Ola, mun\ndo ??"};

	ft_putstr_non_printable(str);
	write(1, "\n", 1);
	return (0);
}
