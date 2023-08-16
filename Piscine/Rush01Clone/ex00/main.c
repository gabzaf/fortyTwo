/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marloaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 10:55:30 by marloaur          #+#    #+#             */
/*   Updated: 2023/03/19 11:28:34 by marloaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	**args(int argc, char **argv, int *size);
void	gen(int **locked, int size);
void	ft_putstr(char *str);

int	main(int argc, char **argv)
{
	int	**bord;
	int	size;

		bord = args(argc, argv, &size);
		if (bord != NULL)
		{
			gen(bord, size);
		}
		else
			ft_putstr("Error\n");
}
