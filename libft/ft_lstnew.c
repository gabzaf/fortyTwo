/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <gamado-x@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 20:26:44 by gamado-x          #+#    #+#             */
/*   Updated: 2023/05/11 20:49:01 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

typedef struct	s_list
{
	void		*content;
	struct s_list	*next;
}			t_list;

t_list	*ft_lstnew(void *content)
{
	t_list *new_node = (t_list*)malloc(sizeof(t_list));
	if (new_node == NULL)
		return (NULL);
	new_node -> content = content;
	new_node -> next = NULL;
	return (new_node);	
}

int	main(void)
{
	int	num = 42;
	int	*ptr = &num;	
	t_list	*node1 = ft_lstnew(ptr);
	printf("%d, %p", *(int*)node1->content, node1->next);
	return (0);
}


