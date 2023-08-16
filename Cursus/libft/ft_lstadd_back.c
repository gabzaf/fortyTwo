/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 16:29:35 by gamado-x          #+#    #+#             */
/*   Updated: 2023/05/18 16:52:17 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}			t_list;*/

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if ((*lst) == NULL)
	{
		(*lst) = new;
		return ;
	}
	last = (*lst);
	while (last->next != NULL)
		last = last->next;
	last->next = new;
}

/*int	main(void)
{
	t_list	*frstnode = malloc(sizeof(t_list));
	t_list	*scndnode = malloc(sizeof(t_list));
	t_list	*thrdnode = malloc(sizeof(t_list));
	t_list	*newnode = malloc(sizeof(t_list));

	frstnode->content = "Node1";
	frstnode->next = scndnode;
	scndnode->content = "Node2";
	scndnode->next = thrdnode;
	thrdnode->content = "Node3";
	thrdnode->next = NULL;
	newnode->content = "NewNode";
	newnode->next = NULL;
	ft_lstadd_back(&frstnode, newnode);
	t_list	*current = frstnode;
	while (current != NULL)
	{
		printf("%s\n", (char *)current->content);
		current = current->next;
	}
	current = frstnode;
	while (current != NULL)
	{
		t_list	*temp = current;
		current = current->next;
		free(temp);
	}
	return (0);
}*/
