/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 12:48:09 by gamado-x          #+#    #+#             */
/*   Updated: 2024/05/20 12:48:13 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_lib.h"

void	rotate_stack(t_list **stack)
{
	t_list	*head;
	t_list	*tail;

	if (stack == NULL || (*stack)->next == NULL)
		return ;
	head = *stack;
	tail = *stack;
	while (tail->next != NULL)
		tail = tail->next;
	*stack = head->next;
	tail->next = head;
	head->next = NULL;
}

void	rotate_b(t_list **b)
{
	rotate_stack(b);
	ft_printf("rb\n");
}

void	rotate_a(t_list **a)
{
	rotate_stack(a);
	ft_printf("ra\n");
}
