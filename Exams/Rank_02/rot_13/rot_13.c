/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_13.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:45:43 by gamado-x          #+#    #+#             */
/*   Updated: 2024/04/26 17:08:14 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	replacer(char c)
{
	if (c >= 65 && c <= 90)
	{
		if (c < 78)
			ft_putchar(c + 13);
		else
			ft_putchar(c - 13);
	}
	else if (c >= 97 && c <= 122)
	{
		if (c < 110)
			ft_putchar(c + 13);
		else
			ft_putchar(c - 13);
	}
	else
		ft_putchar(c);
}

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc == 2)
	{
		while (argv[1][i])
		{
			replacer(argv[1][i]);
			i++;
		}
	}
	ft_putchar('\n');
}
