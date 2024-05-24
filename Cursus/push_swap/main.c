/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:44:24 by gamado-x          #+#    #+#             */
/*   Updated: 2024/05/24 20:46:21 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_lib.h"

static void	free_stack(t_stack **node)
{
	t_stack	*temp;

	while (*node)
	{
		temp = *node;
		*node = (*node)->next;
		free(temp);
	}
	*node = NULL;
}

t_stack	*node_gen(int value)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->value = value;
	node->index_set = -1;
	node->next = NULL;
	return (node);
}

static void	list_insertion(int value, t_stack **head_node)
{
	t_stack	*last_node;
	t_stack	*new_node;

	new_node = node_gen(value);
	if (!new_node)
	{
		free_stack(head_node);
		return ;
	}
	if (*head_node == NULL)
	{
		*head_node = new_node;
		return ;
	}
	last_node = *head_node;
	while (last_node->next != NULL)
	{
		last_node = last_node->next;
	}
	last_node->next = new_node;
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		i;

	a = NULL;
	b = NULL;
	if (argc >= 2)
	{
		if (check_input(argc, argv) || check_dplctd_nbr(argc, argv))
		{
			write(2, "Error\n", 6);
			exit (0);
		}
		i = 1;
		while (i <argc)
		{
			list_insertion(ft_atoi(argv[i]), &a);
			i++;
		}
		if (!asc_sort_check(a))
			push_swap(&a, &b);
		free_stack(&a);
		free(a);
	}
	return (0);
}
