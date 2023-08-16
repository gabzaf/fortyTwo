/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste_read_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 19:39:59 by gamado-x          #+#    #+#             */
/*   Updated: 2023/06/26 19:59:07 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

void	*get_next_line(int fd)
{
}

int	main()
{
	int	fd;
	char	path[] = "/nfs/homes/gamado-x/Documents/Cursus/teste/get_next_line/example.txt";
	fd = open(path, O_RDONLY);
	get_next_line(fd);
	return (0);
}
