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
	t_list	*a;
	t_list	*b;
	int		*array;

	b = NULL;
	if (argc >= 2)
	{
		if (check_input(argc, argv) || check_dplctd_nbr(argc, argv))
		{
			write(1, "Error\n", 6);
			return (0);
		}
		array = (int *)malloc(sizeof(int) * (argc - 1));
		if (!array)
			exit(0);
		array_insertion(argc, argv, array);
		a = (t_list *)malloc(sizeof(t_list));
		if (!a)
			exit(1);
		a = NULL;
		list_insertion(argc, argv, &a);
		push_swap(array, a, b);
		free_stack(a, b);
		free(array);
	}
	return (0);
}
