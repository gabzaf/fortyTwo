/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 12:51:20 by gamado-x          #+#    #+#             */
/*   Updated: 2024/05/24 17:45:59 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_lib.h"

void	swap(t_stack **stack)
{
	t_stack	*temp;
	
	temp = (*stack)->next;
	(*stack)->next = (*stack)->next->next;
	temp->next = (*stack);
	(*stack) = temp;
}
