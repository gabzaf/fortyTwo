/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 16:27:35 by gamado-x          #+#    #+#             */
/*   Updated: 2023/07/26 17:25:59 by gamado-x         ###   ########.fr       */
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
        char                    *string_buffer;
        struct s_list   *next;
}               t_list;

char    *get_next_line(int fd);
size_t  ft_strlen(const char *str );
char    *ft_strjoin(char *s1, char *s2);
int             ft_clean(char *str);

#endif

