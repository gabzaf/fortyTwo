/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 17:34:44 by gamado-x          #+#    #+#             */
/*   Updated: 2023/07/25 08:27:31 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_list
{
	char			*string_buffer;
	struct s_list	*next;
}		t_list;

char	*get_next_line(int fd);
int		ft_search_line(t_list *list);
t_list	*ft_search_last_node(t_list *list);
char	*ft_get_line(t_list *list);
void	ft_cpystr(t_list *list, char *str);
int		ft_line_len(t_list *list);
void	ft_prepare_list(t_list **list);
void	ft_dealloc(t_list **list, t_list *clean_node, char *buffer);
void	ft_create_list(int fd, t_list **list);

#endif
