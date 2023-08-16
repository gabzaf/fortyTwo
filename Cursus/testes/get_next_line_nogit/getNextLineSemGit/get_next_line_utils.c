/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 17:34:23 by gamado-x          #+#    #+#             */
/*   Updated: 2023/07/25 08:18:37 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_dealloc(t_list **list, t_list *clean_node, char *buffer)
{
	t_list	*tmp;

	if (*list == NULL)
		return ;
	while (*list)
	{
		tmp = (*list)->next;
		free((*list)->string_buffer);
		free(*list);
		*list = tmp;
	}
	*list = NULL;
	if (clean_node->string_buffer[0])
		*list = clean_node;
	else
	{
		free(buffer);
		free(clean_node);
	}
}

void	ft_cpystr(t_list *list, char *str)
{
	int	i;
	int	k;

	if (list == NULL)
		return ;
	k = 0;
	while (list)
	{
		i = 0;
		while (list->string_buffer[i])
		{
			if (list->string_buffer[i] == '\n')
			{
				str[k++] = '\n';
				str[k] = '\0';
				return ;
			}
			str[k++] = list->string_buffer[i++];
		}
		list = list->next;
	}
	str[k] = '\0';
}

int	ft_line_len(t_list *list)
{
	int	i;
	int	len;

	if (list == NULL)
		return (0);
	len = 0;
	while (list)
	{
		i = 0;
		while (list->string_buffer[i])
		{
			if (list->string_buffer[i] == '\n')
			{
				++len;
				return (len);
			}
			++i;
			++len;
		}
		list = list->next;
	}
	return (len);
}

t_list	*ft_search_last_node(t_list *list)
{
	if (list == NULL)
		return (NULL);
	while (list->next)
		list = list->next;
	return (list);
}

int	ft_search_line(t_list *list)
{
	int	i;

	if (list == NULL)
		return (0);
	while (list)
	{
		i = 0;
		while (list->string_buffer[i] && i < BUFFER_SIZE)
		{
			if (list->string_buffer[i] == '\n')
				return (1);
			++i;
		}
		list = list->next;
	}
	return (0);
}
