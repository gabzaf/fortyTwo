/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 16:31:54 by gamado-x          #+#    #+#             */
/*   Updated: 2023/05/20 18:12:35 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*typedef struct s_list
{
	void		*content;
	struct s_list	*next;
}			t_list;

static void	delete_node(void *lst)
{
	t_list *nodecontent = (t_list *)lst;
	nodecontent = nodecontent->next;
}*/

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	if (!del || !lst || !*lst)
	{
		return ;
	}
	while (lst && *lst)
	{
		temp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = temp;
	}
}

/*int	main(void)
{
	t_list	*frstnode = malloc(sizeof(t_list));
	t_list	*scndnode = malloc(sizeof(t_list));
	t_list	*thrdnode = malloc(sizeof(t_list));
	t_list	*frthnode = malloc(sizeof(t_list));

	frstnode->content = "Node1";
	frstnode->next = scndnode;
	scndnode->content = "Node2";
	scndnode->next = thrdnode;
	thrdnode->content = "Node3";
	thrdnode->next = frthnode;
	frthnode->content = "Node4";
	frthnode->next = NULL;
	ft_lstclear(&scndnode, delete_node);
	t_list	*current = frstnode;
	while (current->next != NULL)
	{
		printf("%s\n", (char *)current->content);
		current = current->next;
	}
	return (0);
}*/
