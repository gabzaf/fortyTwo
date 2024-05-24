/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils_two.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 18:34:36 by gamado-x          #+#    #+#             */
/*   Updated: 2024/05/24 19:46:39 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_lib"

static int	get_biggest_position(t_stack *stack)
{
	int	biggest_bits;
	int	biggest;

	biggest_bits = 0;
	biggest = get_biggest(stack)->index;
	while (biggest > 0)
	{
		biggest_bits++;
		biggest = biggest >> 1;
	}
	return (biggest_bits);
}

void	stack_b_sort_radix(t_stack **a, t_stack **b, int bit_position)
{
	int	len;
	int	i;

	len = stack_len(*b);
	i = 0;
	if (asc_sort_check(*a) && desc_sort_check(*b))
	{
		while (i++ < len)
			push(b, a, 'a');
	}
	i = 0;
	while (*b != NULL && i < len)
	{
		if ((((*b)->index >> bit_position) & 1) == 0)
			change(rotate, b, 'b');
		else
			push(b, a, 'a');
		i++;
	}
}

void	big_sort_radix(t_stack **a, t_stack **b)
{
	int	bit_position;
	int	biggest_bit;
	int	len;
	int	i;

	bit_position = 0;
	biggest_position = get_biggest_position(*a);
	while (bit_position < biggest_position)
	{
		i = 0;
		len = stack_len(*a);
		while (!asc_order_check(*a) && i < len)
		{
			if ((((*a)->index >> bit_position) & 1) == 1)
				change(rotate, a, 'a');
			else
				push(a, b,'b');
			i++;
		}
		stack_b_sort_radix(a, b, bit_position + 1);
		bit_position++;
	}
}

void	set_index(int len, t_stack **stack)
{
	t_stack	*smallest_node;
	t_stack	*temp;
	int		index;
	int		smallest;

	index = 0;
	temp = *stack;
	while (temp != NULL)
	{
		smallest = INT_MAX;
		temp = *stack;
		while (temp != NULL)
		{
			if (temp->value < smallest && temp->index_set == -1)
			{
				smallest_node = temp;
				smallest = temp->value;
			}
			temp = temp->next;
		}
		smallest_node->index = index;
		smallest_node->index_set = 1;
		index++;
	}
}
