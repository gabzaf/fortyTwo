/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 12:47:52 by gamado-x          #+#    #+#             */
/*   Updated: 2024/05/20 12:47:55 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_lib.h"

void	ft_reverse(t_list **stack)
{
	t_list	*tail;
	t_list	*prev;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	tail = *stack;
	prev = NULL;
	while (tail->next != NULL)
	{
		prev = tail;
		tail = tail->next;
	}
	tail->next = *stack;
	prev->next = NULL;
	*stack = tail;
}

void	reverse_b(t_list **b)
{
	ft_reverse(b);
	ft_printf("rrb\n");
}

void	reverse_a(t_list **a)
{
	ft_reverse(a);
	ft_printf("rra\n");
}
