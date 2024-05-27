/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_rev.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 12:47:52 by gamado-x          #+#    #+#             */
/*   Updated: 2024/05/26 15:59:55 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_lib.h"

static void	rotate_instructions(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*tail;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	first = *stack;
	second = (*stack)->next;
	tail = ft_lstlast(*stack);
	*stack = second;
	second->prev = NULL;
	tail->next = first;
	first->prev = tail;
	first->next = NULL;
}

static void	reverse_instructions(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*tail;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	tail = *stack;
	while (tail->next)
	{
		temp = tail;
		tail = tail->next;
	}
	tail->next = *stack;
	temp->next = NULL;
	(*stack)->prev = tail;
	*stack = tail;
	(*stack)->prev = NULL;
}

void	reverse(t_stack **a, t_stack **b, int instruction, t_sort_state *st)
{
	if (a == NULL && b == NULL)
		return ;
	if (instruction == RRA || instruction == RRR)
		reverse_instructions(a);
	if (instruction == RRB || instruction == RRR)
		reverse_instructions(b);
	if (st->checker)
		return ;
	if (instruction == RRA)
		write(1, "rra\n", 4);
	if (instruction == RRB)
		write(1, "rrb\n", 4);
	if (instruction == RRR)
		write(1, "rrr\n", 4);
}

void	rotate(t_stack **a, t_stack **b, int instruction, t_sort_state *st)
{
	if (a == NULL && b == NULL)
		return ;
	if (instruction == RA || instruction == RR)
		rotate_instructions(a);
	if (instruction == RB || instruction == RR)
		rotate_instructions(b);
	if (st->checker)
		return ;
	if (instruction == RA)
		write(1, "ra\n", 3);
	if (instruction == RB)
		write(1, "rb\n", 3);
	if (instruction == RR)
		write(1, "rr\n", 3);
}
