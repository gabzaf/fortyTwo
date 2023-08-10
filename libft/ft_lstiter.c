/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 16:33:40 by gamado-x          #+#    #+#             */
/*   Updated: 2023/05/21 16:16:49 by gamado-x         ###   ########.fr       */
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
	
}*/

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*temp;
	t_list	*temp2;

	if (lst == NULL)
		return ;
	temp = lst;
	while (temp)
	{
		temp2 = temp->next;
		f(temp->content);
		temp = temp2;
	}
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
	ft_lstiter(scndnode, iterate_list);
	//t_list	*current = frstnode;
	while (current != NULL)
	{
		printf("%s\n", (char *)current->content);
		current = current->next;
	}
	return (0);
}*/	
