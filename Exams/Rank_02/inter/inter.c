/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 13:09:43 by gamado-x          #+#    #+#             */
/*   Updated: 2024/04/28 14:09:41 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	ft_compare(char c, char **argv, int index)
{
	int	i;

	i = 0;
	while (argv[1][i])
	{
		if (index == i)
		{
			i++;
			continue;
		}
		if (c == argv[1][i])
			exit (1);
		i++;
	}
	write(1, &c, 1);
}

int	main(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	if (argc == 3)
	{
		while (argv[1][i])
		{
			j = 0;
			while (argv[2][j])
			{
				if (argv[1][i] == argv[2][j])
				{
					ft_compare(argv[1][i], argv, i);
				}
				j++;
			}
			i++;
		}	
	}
	write(1, "\n", 1);
	return (0);
}
