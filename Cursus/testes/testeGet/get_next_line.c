/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 09:37:08 by gamado-x          #+#    #+#             */
/*   Updated: 2023/08/07 10:19:01 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	//FOPENMAX is the max nbr of files that can be opened simultaneously.
	static char	filesArray[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*line;
	//safe check 
	if (fd < 0 || FOPEN_MAX < fd)
		return (NULL);
	line = NULL;
	//1st checks if the buffer has any chars left from the previous read op
	//2nd reads data from fd and checks if the read 
	while (filesArray[fd][0] || read(fd, filesArray[fd], BUFFER_SIZE) > 0)
	{
		line = ft_strjoin(line, filesArray[fd]);
		if (ft_strlen(filesArray[fd]) == 0)
			return (line);
		//caso o bf passe do barraN
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
