/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 13:02:58 by gamado-x          #+#    #+#             */
/*   Updated: 2024/06/03 14:25:16 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdlib.h>
//#include <stdio.h>
#include "list.h"

int	ft_list_size(t_list *begin_list)
{
	int	i;
	
	if (begin_list == 0)
		return (0);
	else
		i = 0;
		while (begin_list)
		{
			i++;
			begin_list = begin_list->next;
		}
		return (i);
}

/*int	main(int ac, char **av)
{
	t_list	*a = NULL;
	int	i = 1;
	char	*c_data = malloc(sizeof(char));

	while (i <= ac)
	{
		t_list *node = malloc(sizeof(t_list));
		*c_data = av[1][i];
		node->data = c_data;
		node->next = a;
		a = node;
		i++;
	}
	printf("%d", ft_list_size(a));
	return (0);
}*/
