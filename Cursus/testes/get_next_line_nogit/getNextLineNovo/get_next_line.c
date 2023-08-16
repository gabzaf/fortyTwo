/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 16:22:00 by gamado-x          #+#    #+#             */
/*   Updated: 2023/07/26 18:03:47 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_search_line(t_list *list)
{
	int	i;

	if (!list)
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
	}
}

char	*get_next_line(int fd)
{
	static t_list	*list = NULL;
	char			*line;

	if (fd < 0)
		return (NULL);
	ft_create_list(fd, &list);
	line = NULL;
	while (list->string_buffer[0] || read(fd, list->string_buffer, BUFFER_SIZE) > 0)
	{
		line = ft_strjoin(line, list->string_buffer);
		if (ft_strlen(list->string_buffer) == 0)
			return (line);
		if (ft_clean(list->string_buffer) == 1)
			break ;
		if (read(fd, list->string_buffer, 0) < 0)
		{
			free(line);
			return (NULL);
		}
	}
	return (line);
}
