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

void    ft_clean(t_stack **a, t_stack **b, t_push *st)
{
        t_stack *temp;

        while (*a)
        {
                temp = *a;
                *a = (*a)->next;
                free(temp);
        }
        while (*b)
        {
                temp = *b;
                *b = (*b)->next;
                free(temp);
        }
        if (st->error == true)
                write(2, "Error\n", 6);
}

void	ft_free_split(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
}

void	ft_isdigit(char *str, t_push *st)
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
