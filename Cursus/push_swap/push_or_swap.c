/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_or_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 12:46:27 by gamado-x          #+#    #+#             */
/*   Updated: 2024/05/26 16:03:02 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_lib.h"

static void	swap_instructions(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*swap;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	temp = *stack;
	swap = (*stack)->next;
	if (swap->next)
		swap->next->prev = *stack;
	swap->prev = temp->prev;
	temp->prev = swap;
	(*stack)->next = swap->next;
	swap->next = temp;
	*stack = swap;
}

static void	push_instructions(t_stack **src, t_stack **dst)
{
	t_stack	*head_s;
	t_stack	*head_d;

	if (*src == NULL)
		return ;
	head_s = *src;
	head_d = *dst;
	*src = head_s->next;
	if (*src)
		(*src)->prev = NULL;
	if (head_d == NULL)
	{
		head_s->next = NULL;
		*dst = head_s;
		(*dst)->prev = NULL;
		return ;
	}
	head_s->next = head_d;
	head_d->prev = head_s;
	*dst = head_s;
}

void	push(t_stack **a, t_stack **b, int instruction, t_sort_state *st)
{
	if (instruction == PB)
	{
		push_instructions(a, b);
		st->a_len--;
		st->b_len++;
	}
	if (instruction == PA)
	{
		push_instructions(b, a);
		st->a_len++;
		st->b_len--;
	}
	if (st->checker)
		return ;
	if (instruction == PB)
		write(1, "pb\n", 3);
	if (instruction == PA)
		write(1, "pa\n", 3);
}

void	swap(t_stack **a, t_stack **b, int instruction, t_sort_state *st)
{
	if (a == NULL && b == NULL)
		return ;
	if (instruction == SA || instruction == SS)
		swap_instructions(a);
	if (instruction == SB || instruction == SS)
		swap_instructions(b);
	if (st->checker)
		return ;
	if (instruction == SA)
		write(1, "sa\n", 3);
	if (instruction == SB)
		write(1, "sb\n", 3);
	if (instruction == SS)
		write(1, "ss\n", 3);
}
