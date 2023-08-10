/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 16:27:42 by gamado-x          #+#    #+#             */
/*   Updated: 2023/05/20 17:57:23 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}			t_list;*/

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

/*int	main(void)
{
	t_list *frstnode = malloc(sizeof(t_list));
	t_list *scndnode = malloc(sizeof(t_list));
	t_list *thrdnode = malloc(sizeof(t_list));
	frstnode->content = "Node 1";
	frstnode->next = scndnode;
	scndnode->content = "Node 2";
	scndnode->next = thrdnode;
	thrdnode->content = "Node 3";
	thrdnode->next = NULL;
	printf("%d\n", ft_lstsize(frstnode));

}*/
