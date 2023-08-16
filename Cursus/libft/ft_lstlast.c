/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 16:28:35 by gamado-x          #+#    #+#             */
/*   Updated: 2023/05/20 17:53:54 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;*/

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst != NULL)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

/*int	main(void)
{
	t_list	*frstnode = malloc(sizeof(t_list));
	t_list	*scndnode = malloc(sizeof(t_list));
	t_list	*thrdnode = malloc(sizeof(t_list));
	frstnode->content = "Node1";
	frstnode->next = scndnode;
	scndnode->content = "Node2";
	scndnode->next = thrdnode;
	thrdnode->content = "Node3";
	thrdnode->next = NULL;
	t_list *last = ft_lstlast(frstnode);
	printf("%s\n", (char *)last->content);
	NAO ESQUECER O FREE
	return (0);
}*/
