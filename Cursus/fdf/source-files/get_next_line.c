/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 09:37:08 by gamado-x          #+#    #+#             */
/*   Updated: 2023/11/09 12:58:10 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	files_array[FOPEN_MAX][BUFFER_SIZE + 1];
	char	*line;

	if (fd < 0 || FOPEN_MAX < fd)
		return (NULL);
	line = NULL; 
	while (files_array[fd][0] || read(fd, files_array[fd], BUFFER_SIZE) > 0)
	{
		line = ft_strjoin(line, files_array[fd]);
		if (ft_strlen(files_array[fd]) == 0)
			return (line);
		if (ft_clean(files_array[fd]) == 1)
			break ;
		if (read(fd, files_array[fd], BUFFER_SIZE) < 0)
		{
			free(line);
			return (NULL);
		}
	}
	return (line);
}
