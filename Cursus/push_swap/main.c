/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:44:24 by gamado-x          #+#    #+#             */
/*   Updated: 2024/05/28 13:19:15 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_lib.h"

int	main(int argc, char **argv)
{
	t_stack			*a;
	t_stack			*b;
	t_sort_state	st;

	if (argc == 1)
		return (0);
	st = (t_sort_state){0};
	if (argc == 2)
		return (validation(argv));
	a = NULL;
	b = NULL;
	initialize_stack(&a, argc, argv, &st);
	if (!st.error)
	{
		if (st.a_len > 3)
			sorting(&a, &b, &st);
		tiny_sort(&a, &b, &st);
	}
	ft_clean(&a, &b, &st);
	return (st.error);
}
