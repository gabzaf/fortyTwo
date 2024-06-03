/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 18:12:58 by gamado-x          #+#    #+#             */
/*   Updated: 2024/05/31 10:18:25 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_lib.h"

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

static void	ft_lstadd_back(t_stack **stack, int value, t_sort_state *st)
{
	t_stack	*tail;
	t_stack	*new;

	if (!stack)
		st->error = true;
	if (st->error == true)
		return ;
	new = ft_lstnew(value);
	if (!new)
	{
		st->error = true;
		return ;
	}
	st->a_len++;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	tail = ft_lstlast(*stack);
	new->prev = tail;
	tail->next = new;
}

static int	ft_atoi(char *str, t_sort_state *st)
{
	int		sign;
	int		i;
	long	nbr;

	sign = 1;
	i = 0;
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
	if ((nbr * sign) > 2147483647 || (nbr * sign) < -2147483648)
		st->error = true;
	return ((int)(nbr * sign));
}

static void	check_dplct(t_stack *stack_a, t_sort_state *st, int value)
{
	t_stack	*tmp;

	tmp = stack_a;
	while (tmp->next)
	{
		if (tmp->value == value)
			st->error = true;
		tmp = tmp->next;
	}
}

void	initialize_stack(t_stack **a, int argc, char **argv, t_sort_state *st)
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
			break ;
		ft_lstadd_back(a, value, st);
		check_dplct(*a, st, value);
	}
	if (argc == 2)
		ft_free_split(argv);
}
