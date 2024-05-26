/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:44:24 by gamado-x          #+#    #+#             */
/*   Updated: 2024/05/26 15:10:03 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_lib.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_push	st;

	if (argc < 2)
		return (0);	
	a = NULL;
	b = NULL;
	st = (t_push){0};
	initialize_stack(argc, argv, &a, &st);
	if (!st.error)
	{
		if (st.size_of_a > 3)
			sorting(&a, &b, &st);
		sort_three_items(&a, &b, &st);
	}
	ft_clean(&a, &b, &st);
	return (st.error);
}
