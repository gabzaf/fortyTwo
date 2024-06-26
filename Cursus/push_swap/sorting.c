/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 19:55:58 by gamado-x          #+#    #+#             */
/*   Updated: 2024/05/26 14:54:41 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_lib.h"

static void	set_b_index(t_stack **a, t_stack **b)
{
	t_stack	*temp_a;
	t_stack	*temp_b;

	temp_a = *a;
	while (temp_a != NULL)
	{
		temp_b = *b;
		temp_a->index = INT_MIN;
		while (temp_b != NULL)
		{
			if (temp_b->value < temp_a->value && temp_b->value > temp_a->index)
			{
				temp_a->index = temp_b->value;
			}
			temp_b = temp_b->next;
		}
		if (temp_a->index == INT_MIN)
			temp_a->index = ft_biggest(*b);
		temp_a = temp_a->next;
	}
}

static void	set_a_index(t_stack **a, t_stack **b)
{
	t_stack	*temp_a;
	t_stack	*temp_b;

	temp_b = *b;
	while (temp_b != NULL)
	{
		temp_a = *a;
		temp_b->index = INT_MAX;
		while (temp_a != NULL)
		{
			if (temp_a->value > temp_b->value && temp_a->value < temp_b->index)
				temp_b->index = temp_a->value;
			temp_a = temp_a->next;
		}
		if (temp_b->index == INT_MAX)
			temp_b->index = ft_smallest(*a);
		temp_b = temp_b->next;
	}
}

static void	move(t_stack **a, t_stack **b, t_sort_state *st)
{
	if (*a == NULL)
	{
		st->error = true;
		return ;
	}
	while (st->rotate[RRR]--)
		reverse(a, b, RRR, st);
	while (st->rotate[RR]--)
		rotate(a, b, RR, st);
	while (st->rotate[RA]--)
		rotate(a, b, RA, st);
	while (st->rotate[RB]--)
		rotate(a, b, RB, st);
	while (st->rotate[RRA]--)
		reverse(a, b, RRA, st);
	while (st->rotate[RRB]--)
		reverse(a, b, RRB, st);
}

void	sorting(t_stack **a, t_stack **b, t_sort_state *st)
{
	if (ft_lstsorted(*a))
		return ;
	push(a, b, PB, st);
	push(a, b, PB, st);
	while (st->a_len > 3)
	{
		set_b_index(a, b);
		get_moves(a, b, st, 'A');
		move(a, b, st);
		push(a, b, PB, st);
	}
	tiny_sort(a, b, st);
	while (st->b_len)
	{
		set_a_index(a, b);
		get_moves(a, b, st, 'B');
		move(a, b, st);
		push(a, b, PA, st);
	}
	while (ft_lstsorted(*a) == false)
		reverse(a, b, RRA, st);
}
