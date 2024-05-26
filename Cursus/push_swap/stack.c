/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 18:12:58 by gamado-x          #+#    #+#             */
/*   Updated: 2024/05/25 19:34:30 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_lib.h"

static void	check_dplcts(t_stack *a, t_push *st, int value)
{
	t_stack	*temp;

	temp = a;
	while (temp->next)
	{
		if (temp->value == value)
			st->error = true;
		temp = temp->next;
	}
}

static t_stack	*ft_lstnew(int value)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (new)
	{
		new->value = value;
		new->next = NULL;
		new->prev = NULL;
	}
	return (new);
}

static void	ft_lstadd_back(t_stack **a, int value, t_push *st)
{
	t_stack	*last;
	t_stack *new;

        if (!a)
                st->error = true;
        if (st->error == true)
                return ;
        new = ft_lstnew(value);
        if (!new)
        {
                st->error = true;
                return ;
        }
        st->size_of_a++;
        if (!*a)
        {
                *a = new;
                return ;
        }
        last = ft_lstlast(*a);
        new->prev = last;
        last->next = new;
}

static int	ft_atoi(char *str, t_push *st)
{
	int	i;
	int	sign;
	long		nbr;

	i = 0;
	sign = 1;
	nbr = 0;
	if (st->error == true)
		return (0);
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			sign = -1;
	}
	while (str[i] && st->error == false)
	{
		nbr = nbr * 10 + (str[i++] - '0');
		if (nbr < 0)
			st->error = true;
	}
	return (nbr * sign);
}

void	initialize_stack(int argc, char **argv, t_stack **a, t_push *st)
{
	int	i;
	int	value;

	i = 0;
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		if (!*argv)
			st->error = true;
		i = -1;
	}
	while (argv[++i] && st->error == false)
	{
		ft_isdigit(argv[i], st);
		value = ft_atoi(argv[i], st);
		if (st->error == true)
			break;
		ft_lstadd_back(a, value, st);
		check_dplcts(*a, st, value);
	}
	if (argc == 2)
		ft_free_split(argv);
}
