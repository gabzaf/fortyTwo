/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 12:46:27 by gamado-x          #+#    #+#             */
/*   Updated: 2024/05/24 17:54:00 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_lib.h"

void	push(t_stack **src, t_stack **dst, char c)
{
	t_stack	*temp;

	temp = *src;
	*src = (*src)->next;
	if (*dst == NULL)
	{
		*dst = temp;
		(*dst)->next = NULL;
	}
	else
	{
		temp->next = *dst;
		*dst = temp;
	}
	write(1, "p", 1);
	write(1, &c, 1);
	write(1, "\n", 1);
}
