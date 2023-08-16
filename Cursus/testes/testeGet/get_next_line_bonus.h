/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 09:40:08 by gamado-x          #+#    #+#             */
/*   Updated: 2023/07/26 09:40:17 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include	<stdio.h>
# include	<stdlib.h>
# include	<string.h>
# include	<unistd.h>

size_t	ft_strlen(const char *str );
char	*ft_strjoin(char *s1, char *s2);
int		ft_clean(char *str);
char	*get_next_line(int fd);

#endif
