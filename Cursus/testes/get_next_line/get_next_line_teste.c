/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_teste.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 17:21:15 by gamado-x          #+#    #+#             */
/*   Updated: 2023/07/01 20:49:06 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_teste.h"

void	dealloc(t_list **list, t_list *clean_node, char *buffer)
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

void	prepare_list(t_list **list)
{
	t_list	*last_node;
	t_list	*clean_node;
	int	i;
	int	k;
	char	*buffer;

	buffer = malloc(BUFFER_SIZE + 1);
	clean_node = malloc(sizeof(t_list));
	if (buffer == NULL || clean_node == NULL)
		return ;
	last_node = find_last_node(*list);
	i = 0;
	k = 0;
	while (last_node->string_buffer[i] && last_node->string_buffer[i] != '\n')
		i++;
	while (last_node->string_buffer[i] && last_node->string_buffer[++i])
		buffer[k++] = last_node->string_buffer[i];
	buffer[k] = '\0';
	clean_node->string_buffer = buffer;
	clean_node->next = NULL;
	dealloc(list, clean_node, buffer);
}

void	cpy_str(t_list *list, char *str)
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

int	newline_len(t_list *list)
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
				len++;
				return (len);
			}
			i++;
			len++;
		}
		list = list->next;
	}
	return (len);
}

char	*get_line(t_list *list)
{
	int	str_len;
	char	*next_str;

	if (list == NULL)
		return (NULL);
	str_len = newline_len(list);
	next_str = malloc(str_len + 1);
	if (next_str == NULL)
		return (NULL);
	cpy_str(list, next_str);
	return (next_str);
}

t_list	*find_last_node(t_list *list)
{
	if (list == NULL)
		return (NULL);
	while (list->next)
		list = list->next;
	return (list);
}

void	add(t_list **list, char *buffer)
{
	t_list	*new_node;
	t_list	*last_node;

	last_node = find_last_node(*list);
	new_node = malloc(sizeof(t_list));
	if (new_node == NULL)
		return ;
	if (last_node == NULL)
		*list = new_node;
	else
		last_node->next = new_node;
	new_node->string_buffer = buffer;
	new_node->next = NULL;
}

int	ft_search_newline(t_list *list)
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

void	ft_create_list(t_list **list, int fd)
{
	char	*buffer;
	int	bytes_read;
	
	if (!ft_search_newline(*list))
	{
		buffer = malloc(BUFFER_SIZE + 1);
		if (buffer == NULL)
			return ;
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (!bytes_read)
		{
			free(buffer);
			return ;
		}
		buffer[bytes_read] = '\0';
		add(list, buffer);
	}
}

char	*get_next_line(int fd)
{
	static t_list	*list = NULL;
	char	*str;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &str, 0) < 0)
		return (NULL);
	ft_create_list(&list, fd);
	if (list == NULL)
		return (NULL);
	str = get_line(list);
	prepare_list(&list);
	return (str);
}

int	main(void)
{
	int	fd;
	
	fd = open("/nfs/homes/gamado-x/Documents/Cursus/getNextLineSemGit/example.txt", O_RDONLY);
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	return (0);
}
