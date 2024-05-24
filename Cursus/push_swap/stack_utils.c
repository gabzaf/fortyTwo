/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 14:16:26 by gamado-x          #+#    #+#             */
/*   Updated: 2024/05/24 18:57:47 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_lib.h"

int	asc_order_check(t_stack **stack)
{
	while (stack->next)
	{
		if (stack->value < stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}
