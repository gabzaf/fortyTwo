/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 17:32:34 by gamado-x          #+#    #+#             */
/*   Updated: 2023/07/27 07:58:43 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_prepare_list(t_list **list)
{
	t_list	*last_node;
	t_list	*clean_node;
	int		i;
	int		k;
	char	*buffer;

	buffer = malloc(BUFFER_SIZE + 1);
	clean_node = malloc(sizeof(t_list));
	if (buffer == NULL || clean_node == NULL)
		return ;
	last_node = ft_search_last_node(*list);
	i = 0;
	k = 0;
	while (last_node->string_buffer[i] && last_node->string_buffer[i] != '\n')
		++i;
	while (last_node->string_buffer[i] && last_node->string_buffer[++i])
		buffer[k++] = last_node->string_buffer[i];
	buffer[k] = '\0';
	clean_node->string_buffer = buffer;
	clean_node->next = NULL;
	ft_dealloc(list, clean_node, buffer);
}

char	*ft_get_line(t_list *list)
{
	char	*string;
	int		str_length;

	if (list == NULL)
		return (NULL);
	str_length = ft_line_len(list);
	string = malloc(str_length + 1);
	if (string == NULL)
		return (NULL);
	ft_cpystr(list, string);
	return (string);
}

void	ft_add(t_list **list, char *buffer)
{
	t_list	*new_node;
	t_list	*last_node;

	new_node = malloc(sizeof(t_list));
	last_node = ft_search_last_node(*list);
	if (new_node == NULL)
	{
		free(new_node);
		return ;
	}
	if (last_node == NULL)
		*list = new_node;
	else
		last_node->next = new_node;
	new_node->string_buffer = buffer;
	new_node->next = NULL;
}

void	ft_create_list(int fd, t_list **list)
{
	char	*buffer;
	int		bytes_read;

	while (!ft_search_line(*list))
	{
		buffer = malloc(BUFFER_SIZE + 1);
		if (!buffer)
			return ;
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (!bytes_read)
		{
			free(buffer);
			return ;
		}
		buffer[bytes_read] = '\0';
		ft_add(list, buffer);
	}
}

char	*get_next_line(int fd)
{
	static t_list	*list = NULL;
	char			*str;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &str, 0) != 0)
		return (NULL);
	ft_create_list(fd, &list);
	if (list == NULL)
		return (NULL);
	str = ft_get_line(list);
	ft_prepare_list(&list);
	return (str);
}
