/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 12:48:09 by gamado-x          #+#    #+#             */
/*   Updated: 2024/05/24 18:10:43 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_lib.h"

void	rotate(t_stack **stack)
{
	t_stack	*temp;
	t_stack *tail;
	
	temp = *stack;
	(*stack) = (*stack)->next;
	temp->next = NULL;
	tail = get_tail(*stack);
	tail->next = temp;
}
