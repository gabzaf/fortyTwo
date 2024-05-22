/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 12:51:20 by gamado-x          #+#    #+#             */
/*   Updated: 2024/05/20 12:51:24 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_lib.h"

void	ft_swap(t_list **stack)
{
	int		temp_v;
	t_list	*temp_list;

	if (stack == NULL || (*stack)->next == NULL)
		return ;
	temp_v = (*stack)->value;
	temp_list = *stack;
	(*stack)->value = temp_list->next->value;
	(*stack)->next->value = temp_v;
}

void	swap_b(t_list **b)
{
	ft_swap(b);
	ft_printf("sb\n");
}

void	swap_a(t_list **a)
{
	ft_swap(a);
	ft_printf("sa\n");
}
