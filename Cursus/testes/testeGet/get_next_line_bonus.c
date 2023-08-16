/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 09:38:53 by gamado-x          #+#    #+#             */
/*   Updated: 2023/08/07 10:22:37 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	filesArray[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*line;

	if (fd < 0 || FOPEN_MAX < fd)
		return (NULL);
	line = NULL;
	while (filesArray[fd][0] || read(fd, filesArray[fd], BUFFER_SIZE) > 0)
	{
		line = ft_strjoin(line, filesArray[fd]);
		if (ft_strlen(filesArray[fd]) == 0)
			return (line);
		if (ft_clean(filesArray[fd]) == 1)
			break ;
		if (read(fd, filesArray[fd], 0) < 0)
		{
			free(line);
			return (NULL);
		}
	}
	return (line);
}
