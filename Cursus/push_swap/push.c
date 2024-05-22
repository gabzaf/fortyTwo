/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 12:46:27 by gamado-x          #+#    #+#             */
/*   Updated: 2024/05/20 13:26:14 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_lib.h"

void	ft_push(t_list **a, t_list **b)
{
	t_list	*head_b;

	if (*b == NULL)
		return ;
	head_b = *b;
	*b = head_b->next;
	head_b->next = *a;
	*a = head_b;
}

void	push_a(t_list **a, t_list **b)
{
	ft_push(a, b);
	ft_printf("pa\n");
}

void	push_b(t_list **a, t_list **b)
{
	ft_push(b, a);
	ft_printf("pb\n");
}
