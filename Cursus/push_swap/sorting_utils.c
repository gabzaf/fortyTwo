/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 20:02:13 by gamado-x          #+#    #+#             */
/*   Updated: 2024/05/28 13:26:01 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_lib.h"

bool	ft_lstsorted(t_stack *stack)
{
	t_stack	*temp;

	temp = stack;
	while (temp->next)
	{
		if (temp->value > temp->next->value)
			return (false);
		temp = temp->next;
	}
	return (true);
}

int	ft_smallest(t_stack *stack)
{
	t_stack			*tmp;
	int				smallest;

	tmp = stack;
	smallest = tmp->value;
	while (tmp)
	{
		if (tmp->value < smallest)
			smallest = tmp->value;
		tmp = tmp->next;
	}
	return (smallest);
}

int	ft_biggest(t_stack *stack)
{
	t_stack			*tmp;
	int				biggest;

	tmp = stack;
	biggest = tmp->value;
	while (tmp)
	{
		if (tmp->value > biggest)
			biggest = tmp->value;
		tmp = tmp->next;
	}
	return (biggest);
}

t_stack	*ft_lstlast(t_stack *stack)
{
	t_stack	*last;

	if (!stack)
		return (NULL);
	last = stack;
	while (last->next)
		last = last->next;
	return (last);
}

void	tiny_sort(t_stack **a, t_stack **b, t_sort_state *st)
{
	if (st->a_len == 2)
	{
		if ((*a)->value > (*a)->next->value)
			swap(a, b, SA, st);
	}
	while (ft_lstsorted(*a) == false)
	{
		if ((*a)->value == ft_smallest(*a)
			&& (*a)->next->value == ft_biggest(*a))
			reverse(a, b, RRA, st);
		else if ((*a)->value == ft_biggest(*a)
			&& ft_lstlast(*a)->value == ft_smallest(*a))
			swap(a, b, SA, st);
		else if (ft_lstlast(*a)->value == ft_smallest(*a)
			&& (*a)->next->value == ft_biggest(*a))
			reverse(a, b, RRA, st);
		else if ((*a)->value == ft_biggest(*a)
			&& (*a)->next->value == ft_smallest(*a))
			rotate(a, b, RA, st);
		else if (ft_lstlast(*a)->value == ft_biggest(*a)
			&& (*a)->next->value == ft_smallest(*a))
			swap(a, b, SA, st);
		else
			break ;
	}
}
