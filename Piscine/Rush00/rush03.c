/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 15:30:42 by gamado-x          #+#    #+#             */
/*   Updated: 2023/03/16 09:57:02 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char a);

void	lines(int x, char left, char mid, char right)
{
	if (x-- >= 1)
	{
		ft_putchar(left);
		while (x-- >= 2)
			ft_putchar(mid);
		if (x == 0)
			ft_putchar(right);
		ft_putchar('\n');
	}
}

void	columns(int x, int y, char height)
{
	int	i;

	while (y-- > 2)
	{
		ft_putchar(height);
		i = 2;
		while (x > i)
		{
			ft_putchar(' ');
			i++;
		}
		ft_putchar(height);
		ft_putchar('\n');
	}
}

void	rush(int x, int y)
{
	if (y >= 1)
	{
		lines(x, 'A', 'B', 'C');
	}
	columns(x, y, 'B');
	if (y >= 2)
	{
		lines(x, 'A', 'B', 'C');
	}
}
