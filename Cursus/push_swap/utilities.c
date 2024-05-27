/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 19:00:59 by gamado-x          #+#    #+#             */
/*   Updated: 2024/05/25 19:42:50 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_lib.h"

void	ft_isdigit(char *str, t_sort_state *st)
{
	int	i;

	if (st->error == true)
		return ;
	i = 0;
	if ((str[i] == '-' || str[i] == '+')
		&& (str[i + 1] != '\0' && str[i + 1] != ' '))
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			st->error = true;
		i++;
	}
}

void	ft_free_split(char **split)
{
	int	i;

	i = -1;
	while (split[++i])
		free(split[i]);
	free(split);
}

void	ft_clean(t_stack **stack_a, t_stack **stack_b, t_sort_state *st)
{
	t_stack	*tmp;

	while (*stack_a)
	{
		tmp = *stack_a;
		*stack_a = (*stack_a)->next;
		free(tmp);
	}
	while (*stack_b)
	{
		tmp = *stack_b;
		*stack_b = (*stack_b)->next;
		free(tmp);
	}
	if (st->error == true)
		write(2, "Error\n", 6);
}
