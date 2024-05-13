/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:44:24 by gamado-x          #+#    #+#             */
/*   Updated: 2024/04/25 19:58:39 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_lib.h"

int	main(int argc, char **argv)
{
	//t_list	*a;
	//t_list	*b;
	int	i;

	i = 0;
	//a = NULL;
	//b = NULL;
	if (argc >= 2)
	{
		if (check_input(argc, argv) || check_dplctd_nbr(argc, argv))
		{
			write(1, "Error\n", 6);
			return (0);
		}
	}
	while (i < argc)
	{
		ft_printf("%s\n", argv[i]);
		i++;
	}
	return (0);
}
