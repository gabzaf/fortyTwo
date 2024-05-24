/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 12:47:52 by gamado-x          #+#    #+#             */
/*   Updated: 2024/05/24 18:31:12 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_lib.h"

void	reverse(t_stack **stack)
{
	t_stack	*tail;
	t_stack	*before_tail;

	tail = get_tail(*stack);
	before_tail = get_last_before_tail(*stack);
	before_tail->next = NULL;
	tail->next = *stack;
	*stack = tail;
}
