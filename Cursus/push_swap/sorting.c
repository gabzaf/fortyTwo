/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 12:48:37 by gamado-x          #+#    #+#             */
/*   Updated: 2024/05/24 20:54:18 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_lib.h"

static int	rotate_or_reverse(t_stack *stack)
{
	int	smallest;
	int	index;
	int	smallest_index;
	int	avg;

	smallest = INT_MAX;
	index = 0;
	smallest_index = 0;
	avg = stack_len(stack) / 2;
	while (stack)
	{
		if (stack->value < smallest)
		{
			smallest = stack->value;
			smallest_index = index;
		}
		stack = stack->next;
		index++;
	}
	if (smallest_index < avg)
		return (1);
	else
		return (0);
}

void	five_four_items_sort(t_stack **a, t_stack **b)
{
	int	smallest;
	int	movement_direction;
	
	while (stack_len(*a) > 3)
	{
		smallest = get_smallest(*a)->value;
		movement_direction = rotate_or_reverse(*a);
		while ((*a)->value != smallest)
		{
			if (movement_direction == 1)
				change(rotate, a, 'a');
			else
				change(reverse, a, 'a');
		}
		push(a, b, 'b');
	}
	three_items_sort(a);
	while (stack_len(*b) >= 1)
		push(b, a, 'a');
}

void	three_items_sort(t_stack **stack)
{
	t_stack *biggest_node;

	biggest_node = get_biggest(*stack);
	if (*stack == biggest_node)
		change(rotate, stack, 'a');
	else if ((*stack)->next == biggest_node)
		change(rotate, stack, 'a');
	if ((*stack)->value > (*stack)->next->value)
		change(swap, stack, 'a');
}

void	change(void (*op)(t_stack**), t_stack **head_node, char c)
{
	if (!head_node)
		return ;
	op(head_node);
	if (op == swap)
		write(1, "s", 1);
	else if (op == rotate)
		write(1, "r", 1);
	else if (op == reverse)
		write(1, "rr", 2);
	write(1, &c, 1);
	write(1, "\n", 1);
}

void	push_swap(t_stack **a, t_stack **b)
{
	int	len;

	len = stack_len(*a);
	if (len == 2)
		change(swap, a, 's');
	else if (len == 3)
		three_items_sort(a);
	else if (len <= 5)
		five_four_items_sort(a, b);
	else if (len > 5)
	{
		set_index(a, len);
		big_sort_radix(a, b);
	}
}
