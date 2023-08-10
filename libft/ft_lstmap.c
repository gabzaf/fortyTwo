/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 16:34:34 by gamado-x          #+#    #+#             */
/*   Updated: 2023/05/20 18:05:02 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

static void	iterate_list(void *lst)
{
	t_list *list = (t_list *)lst;
	while (list != NULL)
	{
		printf("%s\n", (char *)list->content);
		list = list->next;
	}
}

static void	delete_node(void *lst)
{
	t_list *nodecontent = (t_list *)lst;
	nodecontent = nodecontent->next;
}*/

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*frst;
	t_list	*newlist;

	if (!f || !del)
		return (NULL);
	frst = NULL;
	while (lst)
	{
		newlist = ft_lstnew((*f)(lst->content));
		if (!(newlist))
		{
			while (frst)
			{
				newlist = frst->next;
				(*del)(frst->content);
				free(frst);
				frst = newlist;
			}
			lst = NULL;
			return (NULL);
		}
		ft_lstadd_back(&frst, newlist);
		lst = lst->next;
	}
	return (frst);
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
	ft_lstclear(scndnode, iterate_list, delete_node);
	t_list	*current = frstnode;
	while (current != NULL)
	{
		printf("%s\n", (char *)current->content);
		current = current->next;
	}
	return (0);
}*/
