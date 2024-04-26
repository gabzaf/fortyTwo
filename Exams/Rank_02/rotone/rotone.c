/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotone.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 13:22:35 by gamado-x          #+#    #+#             */
/*   Updated: 2024/04/26 14:10:52 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_check_letters(char c)
{
	if (c >= 65 && c <= 90)
	{
		if (c == 90)
			ft_putchar('A');
		else
			ft_putchar(c + 1);
	}
	else if (c >= 97 && c <= 122)
	{
		if (c == 122)
			ft_putchar('a');
		else
			ft_putchar(c + 1);
	}
	else
		ft_putchar(c);
}

int	main(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	if (argc == 2)
	{
		while (argv[i])
		{
			while (argv[i][j])
			{
				ft_check_letters(argv[i][j]);
				j++;
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
