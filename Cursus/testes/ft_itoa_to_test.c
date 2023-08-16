/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 18:52:52 by gamado-x          #+#    #+#             */
/*   Updated: 2023/05/21 13:22:36 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_addchar(unsigned int n, unsigned int *i, unsigned char *s)
{
	s[*i] = n;
	(*i)++;
}

static void	ft_putnstr(unsigned int n, unsigned int *i, unsigned char *s)
{
	if (n == -2147483647)
	{
		ft_addchar(45, i, s);
		ft_addchar(2 + 48, i, s);
		n = 147483647;
	}
	if (n < 0)
	{
		ft_addchar(45, i, s);
		n *= -1;
	}
	if (n >= 10)
	{
		ft_putnstr(n / 10, i, s);
		ft_putnstr(n % 10, i, s);
	}
	else
		ft_addchar(n + '0', i, s);
}

static char	*create_string(unsigned int order)
{
	unsigned char	*string;

	string = malloc(order * sizeof(char));
	if (!string)
		return (NULL);
	return (string);
}

static int	order_of_magnitude(unsigned int n, unsigned int i)
{
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	unsigned int		order;
	unsigned char	*string;
	unsigned int		i;

	i = 0;
	order = order_of_magnitude(n, 0);
	if (n < 0)
		order++;
	string = create_string(order);
	ft_putnstr(n, &i, string);
	string[i] = '\0';
	return (string);
}
