/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 20:02:13 by gamado-x          #+#    #+#             */
/*   Updated: 2024/05/26 15:02:28 by gamado-x         ###   ########.fr       */
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

int     get_smallest(t_stack *stack)
{
        t_stack                 *temp;
        int                             smallest;

        temp = stack;
        smallest = temp->value;
        while (temp)
        {
                if (temp->value < smallest)
                        smallest = temp->value;
                temp = temp->next;
        }
        return (smallest);
}

int     get_biggest(t_stack *stack)
{
        t_stack                 *temp;
        int                             biggest;

        temp = stack;
        biggest = temp->value;
        while (temp)
        {
                if (temp->value > biggest)
                        biggest = temp->value;
                temp = temp->next;
        }
        return (biggest);
}

void    sort_three_items(t_stack **a, t_stack **b, t_push *st)
{
        if (st->size_of_a == 2)
                swap(a, b, SA, st);
        while (ft_lstsorted(*a) == false)
        {
                if ((*a)->value == get_smallest(*a)
                        && (*a)->next->value == get_biggest(*a))
                        reverse(a, b, RRA, st);
                else if ((*a)->value == get_biggest(*a)
                        && ft_lstlast(*a)->value == get_smallest(*a))
                        swap(a, b, SA, st);
                else if (ft_lstlast(*a)->value == get_smallest(*a)
                        && (*a)->next->value == get_biggest(*a))
                        reverse(a, b, RRA, st);
                else if ((*a)->value == get_biggest(*a)
                        && (*a)->next->value == get_smallest(*a))
                        rotate(a, b, RA, st);
                else if (ft_lstlast(*a)->value == get_biggest(*a)
                        && (*a)->next->value == get_smallest(*a))
                        swap(a, b, SA, st);
                else
                        break ;
        }
}

t_stack *ft_lstlast(t_stack *stack)
{
        t_stack *last;

        if (!stack)
                return (NULL);
        last = stack;
        while (last->next)
                last = last->next;
        return (last);
}


