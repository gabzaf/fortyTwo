/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 12:50:09 by gamado-x          #+#    #+#             */
/*   Updated: 2024/05/24 20:11:11 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_lib.h"

t_stack	*get_smallest(t_stack *stack)
{
	int		smallest;
	t_stack	*smallest_node;

	if (!stack)
		return (NULL);
	smallest = INT_MAX;
	while (stack)
	{
		if (stack->value < smallest)
		{
			smallest = stack->value;
			smallest_node = stack;
		}
		stack = stack->next;
	}
	return (smallest_node);
}

t_stack	*get_last_before_tail(t_stack *stack)
{
	while (stack && stack->next && stack->next->next)
		stack = stack->next;
	return (stack);
}

t_stack	*get_tail(t_stack *stack)
{
	while (stack && stack->next)
		stack = stack->next;
	return (stack);
}

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

t_stack	*get_biggest(t_stack *stack)
{
	int	biggest;
	t_stack	*biggest_node;

	if(!stack)
		return (NULL);
	biggest = INT_MIN;
	while (stack)
	{
		if (stack->value < biggest)
		{
			biggest = stack->value;
			biggest_node = stack;
		}
		stack = stack->next;
	}
	return (biggest_node);
}
int	stack_len(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack != NULL)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}
