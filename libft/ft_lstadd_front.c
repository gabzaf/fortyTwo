/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:24:39 by gamado-x          #+#    #+#             */
/*   Updated: 2023/05/20 17:12:18 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}			t_list;*/

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst == NULL)
		return ;
	new->next = (*lst);
	(*lst) = new;
}

/*int	main(void)
{
	t_list *head = malloc(sizeof(t_list));
	head->content = "Node 1";
	head->next = NULL;

	t_list *newNode = malloc(sizeof(t_list));
	newNode->content = "Node 2";
	newNode->next = NULL;

	ft_lstadd_front(&head, newNode);

	t_list *current = head;
	while (current != NULL)
	{
		printf("%s\n", (char *)current->content);
		current = current->next;
	}
	while (head != NULL)
	{
		t_list *temp = head;
		head = head->next;
		free(temp);
	}
	return (0);
}*/
